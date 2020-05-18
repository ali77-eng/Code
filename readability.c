#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    //count letters
    int letters = 0;
    string s = get_string("Text: ");
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }
    }
    //printf("%i letter(s)\n", letters);

    //count words
    int words = 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isspace(s[i]))
        {
            words++;
        }
    }
    //printf("%i word(s)\n", words);

    //count sentences
    int sentences = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 46 || s[i] == 63 || s[i] == 33)
        {
            sentences++;
        }
    }
    //printf("%i sentence(s)\n", sentences);

    //L
    int L = 0;
    L = (100*letters)/words;

    //S
    int S = 0;
    S = (100*sentences)/words;

    //Coleman-Liau Index
    float C = 0.0588*L - 0.296*S - 15.8;
    int index = round(C);
    if (C >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (1 < C && C < 16)
    {
        printf("Grade %i\n", index);
    }
    else if(C < 1)
    {
        printf("Before Grade 1\n");
    }

}