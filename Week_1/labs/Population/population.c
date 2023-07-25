#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;

    do
    {
        startSize = get_int("Start size: \n");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;

    do
    {
        endSize = get_int("End size: \n");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int currentSize = startSize;

    while (currentSize < endSize)
    {
        int llamaBirths = currentSize / 3;
        int llamaDeaths = currentSize / 4;
        currentSize = currentSize + llamaBirths - llamaDeaths;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
