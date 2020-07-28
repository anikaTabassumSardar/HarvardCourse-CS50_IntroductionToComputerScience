#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {

        height = get_int("Positive Number:");

    }
    while (height < 1 || height > 8);  //validate an inclusive range 1-8


    int innerHeight = height;

    //loop to build the pyramid
    for (int i = 0; i < height; i++)
    {
        //printing space
        for (int j = 0; j < innerHeight - 1 ; j++)
        {
            printf(" ");
        }

        //printing the #
        for (int j = 0; j <  i + 1  ; j++)
        {
            printf("#");
        }
        printf("\n");
        innerHeight--;
    }
}
