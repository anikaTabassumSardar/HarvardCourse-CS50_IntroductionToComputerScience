#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //retrieves user's name
    string userName = get_string("What is your name?\n");

    //prints user's name
    printf("Hello, %s\n", userName);
}
