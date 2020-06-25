#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#define FILE_SIZE 512

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
    unsigned char buffer[512];
    bool jpeg = false;
    int counter = 0;

    FILE *image = NULL;
    char p[7];

    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg == false)
            {
                //close
                sprintf(p, "%03i.jpg", counter);
                image = fopen(p, "w");
                if (image == NULL)
                {
                    return 1;
                }
                fwrite(&buffer, 512, 1, image);
                counter++;
                jpeg = true;
            }
            else if (jpeg == true)
            {
                fclose(image);
                sprintf(p, "%03i.jpg", counter);
                image = fopen(p, "w");
                if (image == NULL)
                {
                    return 1;
                }
                fwrite(&buffer, 512, 1, image);
                counter++;
            }
        }
        else
        {
            if (jpeg == true)
            {
                fwrite(&buffer, 512, 1, image);
            }
        }
    fclose(file);
    if (image != NULL)
    {
        fclose(image);
    }
    //fread
    //fread(data, size, number, inptr);
        //if start of JPEG
            //if first JPEG
            //else
        //else
            //if already found JPEG
        //Close any remaining files
    }
}
