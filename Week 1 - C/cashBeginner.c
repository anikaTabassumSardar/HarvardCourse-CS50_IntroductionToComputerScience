#include <stdio.h>
#include <cs50.h>
#include <math.h>

//important to declare this method before the main method otherwise, C doesn't know where to look for the method if it is implemented BELOW the main method.
int numberOfMinCoins(int cents);

int main(void)
{
    float changeOwed;
    do
    {
        changeOwed = get_float("How much change is owed?\n");
    }
    while (changeOwed < 0);

    int cents = round(changeOwed * 100); //converting

    //calculate minimum number of coins required
    //quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
    int minNumOfCoins = numberOfMinCoins(cents);

    printf("%i\n ", minNumOfCoins);

}

int numberOfMinCoins(int cents)
{
    int numOfQuarters = 0;

    if (cents >= 25)
    {
        numOfQuarters += cents / 25;
        cents = cents - ((cents / 25) * 25);
    }
    if (cents >= 10)
    {
        numOfQuarters += cents / 10;
        cents = cents - ((cents / 10) * 10);
    }
    if (cents >= 5)
    {
        numOfQuarters += cents / 5;
        cents = cents - ((cents / 5) * 5);
    }
    if (cents >= 1)
    {
        numOfQuarters += cents / 1;
        cents = cents - (cents / 1);
    }

    return numOfQuarters;
}

//Alternate method to achieve the same result
// int main(void){
//     float changeOwed;
//     do{
//          changeOwed = get_float("How much change is owed?\n");
//     }
//     while(changeOwed < 0);

//     int cents = round(changeOwed * 100); //converting

//     //calculate minimum number of coins required
//     //quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
//     int minNumOfCoins = 0;
//     while(cents >= 25){
//         minNumOfCoins += 1;
//         cents = cents - 25;
//     }
//      while(cents >= 10){
//         minNumOfCoins += 1;
//         cents = cents - 10;
//     }

//     while(cents >= 5) {
//         minNumOfCoins += 1;
//         cents = cents - 5;
//     }

//     while(cents >= 1){
//         minNumOfCoins += 1;
//         cents = cents - 1;
//     }

//     printf("%i\n ", minNumOfCoins);

// }
