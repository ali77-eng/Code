#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#define FILE_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //ask for argument
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    //Open memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    //buffer array
    BYTE buffer[FILE_SIZE];
    int counter = 0;

    FILE *image = NULL;
    char p[7];

    while (fread(buffer, sizeof *buffer, 512, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                //close
                fclose(image);
                sprintf(p, "%03i.jpg", counter);
                counter++;

                image = fopen(p, "new");
                fwrite(buffer, sizeof *buffer, 512, image);

            }
            if (counter == 0)
            {
                sprintf(p, "%03i.jpg", counter);
                counter++;
                image = fopen(p, "new");
                fwrite(buffer, sizeof *buffer, 512, image);
            }
        }
        if (counter != 0)
        {
            fwrite(buffer, sizeof *buffer, 512, image);
        }
    }

    fclose(image);
    fclose(file);
    return 0;
    //fread
    //fread(data, size, number, inptr);
        //if start of JPEG
            //if first JPEG
            //else
        //else
            //if already found JPEG
        //Close any remaining files

}
