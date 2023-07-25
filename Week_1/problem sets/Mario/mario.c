#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int pyramidHeight = get_positive_int();

    for (int currHeight = 0; currHeight < pyramidHeight; currHeight++)
    {
        // Prints spaces before pyramid
        for (int spaces = pyramidHeight - currHeight - 2; spaces >= 0; spaces--)
        {
            printf(" ");
        }
        // Prints left pyramid
        for (int row = 0; row <= currHeight; row++)
        {
            printf("#");
        }
        printf("  ");
        // Prints right pyramid
        for (int row2 = 0; row2 <= currHeight; row2++)
        {
            printf("#");
        }
        printf("\n");
    }
}

// Function that will only accept a positive integer equal to or between 1 and 7
int get_positive_int(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}
