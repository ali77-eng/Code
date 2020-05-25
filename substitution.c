#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//NOTE: argv[] starts at 0

int main(int argc, string argv[])
{
    //CASES THAT DON'T WORK
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argv[1][26] != '\0')
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //CHECKING ALPHABETICAL
    else if (argc == 2 && argv[1][26] == '\0')
    {
        for  (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (isalpha(argv[1][i]))
            {
                for (int j = i - 1; j > -1; j--)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Key must not contain repeated chars.\n");
                        return 1;
                    }
                }
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }
        //GET TEXT
        int cipher[27] = { 0 };
        for  (int l = 0; argv[1][l] != '\0'; l++)
        {
            if (argv[1][l] > 96)
            {
                cipher[l] = argv[1][l] - 32;
            }
            else
            {
                cipher[l] = argv[1][l];
            }
        }
        string s = get_string("plaintext: ");
        printf("\nciphertext: ");
        for (int k = 0; s[k] != '\0'; k++)
        {
            if (!(isalpha(s[k])))
            {
                printf("%c", s[k]);
            }
            else if(s[k] > 96)
            {
                printf("%c", cipher[s[k]-97] + 32);
            }
            else
            {
                printf("%c", cipher[s[k]-65]);
            }
        }

    }
printf("\n");
return 0;
}
