#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h<1||h>8);

    for (int i=1; i<=h; i++)
    {
        for(int n=h; n>i; n--)
        {
            printf(" ");
        }
        for(int n=0; n<i; n++)
        {
            printf("#");
        }
        printf("  ");
        for(int n=0; n<i; n++)
        {
            printf("#");
        }
        printf("\n");
    }

}
