#include <cs50.h>
#include <stdio.h>
//ask for height
int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h<1||h>8);
//print hastags
    for (int i = 1; i <= h; i++)
    {
        for (int n = h; n > i; n--)
        {
            printf(" ");
        }
        //hey
        for (int n = 0; n < i; n++)
        {
            printf("#");
        }
        printf("  ");
        //hi
        for (int n=0; n<i; n++)
        {
            printf("#");
        }
        printf("\n");
    }

}
