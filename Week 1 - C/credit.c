#include <stdio.h>
#include <cs50.h>
#include <math.h>

int countNumberofDigits(long number);
long retrieveDigits(long cardNumber, int numberOfDigitsToBeRetrieved);
void printCardType(long creditCardNumber);

int main(void)
{
    //promts the user for card number
    long creditCardNumber = get_long("Number: ");

    //Luhn’s Algorithm - concept
    //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    //Add the sum to the sum of the digits that weren’t multiplied by 2.

    int counter = 0; //keeps track of the number of digits in the credit card & multiplies or adds it according to the reruirement above

    int product = 0;
    int addedProductOfDigits = 0;
    int addedLeftOverDigits = 0;
    long temp = creditCardNumber;

    while (temp > 0)
    {
        int digit = temp % 10;
        ++counter;
        if (counter % 2 == 0)
        {

            product = digit * 2;

            //check if the digit product's digit is in range of 0-9
            if (product > 9)
            {
                //separate the digits and add the sum
                while (product > 0)
                {
                    int separatedDigit = product % 10;
                    addedProductOfDigits += separatedDigit;
                    product /= 10;
                }
            }
            else
            {
                addedProductOfDigits += product;
            }
        }
        else
        {
            //odd indexed digit's sum
            addedLeftOverDigits += digit;
        }

        //remove the digit accounted for and move on to the next digit
        temp /= 10;
    }

    //check if valid
    int totalSum = addedProductOfDigits + addedLeftOverDigits;
    int lastDigitOfTotalSum = totalSum % 10;

    //initial invalidity check
    if (lastDigitOfTotalSum != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        //if valid, check what card type it is
        printCardType(creditCardNumber);
    }
}

int countNumberofDigits(long number)
{
    int counter = 0;
    while (number != 0)
    {
        number /= 10;
        ++ counter;
    }
    return counter;
    //return floor (log10 (abs ((int)number))) + 1; //same can be achieved with this line
}

void printCardType(long creditCardNumber)
{
    int totalNumberOfDigits = countNumberofDigits(creditCardNumber);

    //American Express Card
    if (totalNumberOfDigits == 15)
    {
        if (retrieveDigits(creditCardNumber, 2) == 34 || retrieveDigits(creditCardNumber, 2) == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //MasterCard or Visa Card
    else if (totalNumberOfDigits == 16)
    {
        if (retrieveDigits(creditCardNumber, 2) >= 51 &&  retrieveDigits(creditCardNumber, 2) <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (retrieveDigits(creditCardNumber, 1) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //Visa Card
    else if (totalNumberOfDigits == 13 && retrieveDigits(creditCardNumber, 1) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

//retrieves the first one or first two or however many first place digits of a number
long retrieveDigits(long cardNumber, int numberOfDigitsToBeRetrieved)
{
    while (cardNumber >= pow(10, numberOfDigitsToBeRetrieved))
    {
        cardNumber /= 10;
    }

    return cardNumber;
}
