#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {

        height = get_int("Positive Number: ");

    }
    while (height < 1 || height > 8);  //validate an inclusive range 1-8


    int innerHeight = height;

    //loop to build the pyramid
    for (int i = 0; i < height; i++)
    {
        //right leaning pyramid
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

        //left leaning pyramid
        //printing the #
        for (int j = 0; j <  i + 1  ; j++)
        {
            if (j == 0)
            {
                printf("  "); //space in between the right and left-leaning pyramids
            }
            printf("#");
        }
        printf("\n");
        innerHeight--;
    }
}
