#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool isUpperCaseLetter(char c);
bool isLowerCaseLetter(char c);
bool isValid(int argc, string argv[]);
bool isUniqueLetter(char *key);
char handleSubstituteEncryption(char c, string keySet, int subtractionVal);

/**
 * Command line arguments: argc and argv are two variables that our main function will now get,
 * when our program is run from the command line.
 * argc is the argument count, or number of arguments,
 * and argv is an array of strings that are the arguments.
 * And the first argument, argv[0], is the name of our program (ex: ./substitution)
**/
int main(int argc, string argv[])
{
    //validate input
    if (!isValid(argc, argv))
    {
        return 1;
    }

    int len = strlen(argv[1]);
    string key = argv[1];
    //retrieve plain text
    string plainText = get_string("plaintext: ");

    const int lowerBoundforAZ = 65;
    const int lowerBoundfor_az = 97;

    char cipherTextArray[strlen(plainText) + 1];

    for (int i = 0, n = strlen(plainText) ; i <= n; i++)
    {
        if (i == n)
        {
            cipherTextArray[i] = '\0'; //adding null terminator to make it string
        }
        //if not alphabetic character, leave as is
        else if (!isUpperCaseLetter(plainText[i]) && !isLowerCaseLetter(plainText[i]))
        {
            cipherTextArray[i] = plainText[i];
        }
        else if (isLowerCaseLetter(plainText[i]))
        {
            cipherTextArray[i] = tolower(handleSubstituteEncryption(plainText[i], key, lowerBoundfor_az));
        }
        else
        {
            cipherTextArray[i] = toupper(handleSubstituteEncryption(plainText[i], key, lowerBoundforAZ));
        }
    }

    //After outputting ciphertext, print a newline and exit by returning 0 from main.
    string cipheredText = cipherTextArray;
    printf("ciphertext: %s\n", cipheredText);

    return 0; //exit(0)
}

//validates user input
bool isValid(int argc, string argv[])
{
    //exit early if the key passes more than one command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    else if (strlen(argv[1]) != 26 || !isUniqueLetter(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    return true;
}

//checks if the char is uppercase
bool isUpperCaseLetter(char c)
{
    //A-Z belongs to ASCII range 65-90
    if ((int) c >= 65 && (int) c <= 90)
    {
        return true;
    }

    return false;
}

//checks if the char is lower case
bool isLowerCaseLetter(char c)
{
    if ((int) c >= 97 && (int) c <= 122)
    {
        return true;
    }

    return false;
}

//Checks if the character is an alphabetic char and if it is unique
bool isUniqueLetter(char *key)
{
    int len = strlen(key);
    bool seen[256];
    memset(seen, false, sizeof(seen));

    for (int i = 0; i < len; i++)
    {
        //tolower() to avoid duplicate of same letter with two different cases
        unsigned char c = tolower(key[i]);
        if ((!isLowerCaseLetter(c) && !isUpperCaseLetter(c)) || seen[c])
        {
            return false;
        }
        seen[c] = true;
    }
    return true;
}


/**
 * Takes in character of the plainText and substracts the minimum ascii char from it
 * of its case and they finds it in the index of the keySet and returns that character
 * */
char handleSubstituteEncryption(char c, string keySet, int subtractionVal)
{
    int index = (int) c - subtractionVal;
    return keySet[index];
}
