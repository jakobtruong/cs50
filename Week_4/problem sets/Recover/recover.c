#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    BYTE buffer[512];
    int count = 0;
    FILE *image_pointer = NULL;
    char filename[8]; // string of 7 characters and null value.

    if (argc != 2)
    {
        printf("Error: Program requires exactly one command-line argument!\n");
        return 1;
    }

    // opens up file
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Error: Error: Cannot open file!");
        return 1;
    }

    // checks if able to read next 512 bytes
    while (fread(&buffer, 512, 1, file)) // == 1 if read and ==0 if not read successfully
    {
        // checks signatures of bytes to determine if it is a jpg
        if (buffer[0] == 0xff & buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0)
        {
            if (count != 0)
            {
                fclose(image_pointer);
            }

            sprintf(argv[1], "%03i.jpg", count);
            image_pointer = fopen(argv[1], "w");
            count++;
        }

        if (count != 0)
        {
            fwrite(&buffer, 512, 1, image_pointer);
        }
    }
    // closes file when nothing is left to read
    fclose(file);
    // closes image_pointer on laster iteration.
    fclose(image_pointer);
}
