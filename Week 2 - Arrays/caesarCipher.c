#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int validateAndRetrieveInput(int argc, string argv[]);
bool checkIfCharBelongsToAlphabet(int ascii);
/**
 * Command line arguments: argc and argv are two variables that our main function will now get,
 * when our program is run from the command line.
 * argc is the argument count, or number of arguments,
 * and argv is an array of strings that are the arguments.
 * And the first argument, argv[0], is the name of our program (ex: ./caesar)
**/
int main(int argc, string argv[])
{
    //exit early if the key passes more than one CLI argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = validateAndRetrieveInput(argc, argv);

    //retrieve plain text
    string plainText = get_string("plaintext: ");

    int plainTextLen = strlen(plainText) + 1;
    //converting the chars of plaintext into ASCII code array then adding the key value to it
    char cipheredCharASCII[plainTextLen];

    //temporary storing the cipheredValue
    int temp = 0;
    int diff = 0; //to hold the value diff if the ASCII code overflows

    //A-Z belongs to ASCII range 65-90
    const int lowerBoundforAZ = 65;
    const int upperBoundforAZ = 90;

    //a-z belongs to ASCII 97-122
    const int lowerBoundfor_az = 97;
    const int upperBoundfor_az = 122;

    //implementing caesar's algorithm to save the char values in int
    for (int i = 0, n = plainTextLen; i <= n; i++)
    {
        if (i == n)
        {
            cipheredCharASCII[i] = '\0'; //adding null terminator to make it string
        }
        else if (!checkIfCharBelongsToAlphabet((int) plainText[i]))
        {
            //keep characters as is (ex - !, ?) if it is not part of the alphabt
            cipheredCharASCII[i] = (char) plainText[i];
        }
        else
        {
            //mask letters
            temp = (int) plainText[i] + key;

            //check for overflow
            if (!checkIfCharBelongsToAlphabet(temp) && temp > upperBoundforAZ && temp < lowerBoundfor_az) //should loop back to uppercase A-Z
            {
                do
                {
                    diff = (temp - upperBoundforAZ) - 1;
                    temp = lowerBoundforAZ + diff;
                }
                while (temp > upperBoundforAZ && temp < lowerBoundfor_az);
            }
            else if (!checkIfCharBelongsToAlphabet(temp) && temp > upperBoundfor_az) //should back back to lowercase a-z
            {
                do
                {
                    diff = (temp - upperBoundfor_az) - 1;
                    temp = lowerBoundfor_az + diff;
                }
                while (temp > upperBoundfor_az);
            }

            cipheredCharASCII[i] = (char) temp;
        }

    }

    //After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
    string cipheredText = cipheredCharASCII;
    printf("ciphertext: %s\n", cipheredText);

    return 0; //exit(0)
}

//Keeps prompting the user for input unless it is a valid int input
int validateAndRetrieveInput(int argc, string argv[])
{
    if (argc == 2 && atoi(argv[1]) != 0) //need a second layer of validation or else 1a will pass as valid value
    {
        char values[strlen(argv[1] + 1)];
        strcpy(values, argv[1]);

        for (int i = 0; values[i] != '\0'; i++)
        {
            if (!isdigit(values[i]))
            {
                printf("Usage: ./caesar key\n");
                exit(1);
            }
        }

        return atoi(argv[1]); //atoi func converts ascii to int
    }
    else
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
}

bool checkIfCharBelongsToAlphabet(int ascii)
{
    //A-Z belongs to ASCII range 65-90 and a-z belongs to ASCII 97-122
    if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
    {
        return true;
    }
    return false;
}
