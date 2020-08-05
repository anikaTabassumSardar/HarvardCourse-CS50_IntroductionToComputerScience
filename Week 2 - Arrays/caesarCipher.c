#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool isLetter(char c);
bool isWord(char c);
bool isSentence(char c);

int main(void)
{
    //propmts the user for a text to evaluate
    string text = get_string("Text: ");

    /**
     * Counts the number of letters, words and sentences in the text.
     * totalNumOfWords: initialized to one to account for the last word.
     * */
    int totalNumOfLetters = 0, totalNumOfWords = 1, totalNumOfSentences = 0;

    for(int i=0, n = strlen(text); i < n; i++){

        if(isLetter(text[i]))
        {
            totalNumOfLetters++;
        }

        if(isWord(text[i]))
        {
            totalNumOfWords++;
        }

        if(isSentence(text[i]))
        {
            totalNumOfSentences++;
        }
    }

    float avgNumOfLettersPer100Words = (totalNumOfLetters/(float)totalNumOfWords) * 100;
    float avgNumOfSentencesPer100Words = (totalNumOfSentences/(float)totalNumOfWords) * 100;

    /**
     * Coleman-Liau formula to determine the reading level/grade
     * Formula: index = 0.0588 * L - 0.296 * S - 15.8
     * Here, L is the average number of letters per 100 words in the text,
     * and S is the average number of sentences per 100 words in the text.
     * */
    float grade = 0.0588 * avgNumOfLettersPer100Words - 0.296 * avgNumOfSentencesPer100Words - 15.8;

    int roundedGrade = round(grade); //rounding to the nearest 10

    //identify grade
    if(roundedGrade < 1 )
    {
        printf("Before Grade 1\n");
    }
    else if(roundedGrade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", roundedGrade);
    }
}

/**
 * Returns true if it includes characters from A-Z or a-z
 * */
bool isLetter(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    return false;
}

/**
 * Returns true if the character is a space.
 * */
bool isWord(char c)
{
    if(isspace(c))
    {
        return true;
    }
    return false;
}

/**
 * Returns true if it is a sentence marker and is not a word or a letter
 * */
bool isSentence(char c)
{
    if(!isWord(c)
    && !isLetter(c)
    && (c == '.'
    || c == '?'
    || c == '!'))
    {
        return true;
    }
    return false;
}
