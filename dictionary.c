#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];
int fp_size = 0;
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char bord[LENGTH+1];
    int n = strlen(word);
    for (int i = 0; i < n+1; i++)
    {
        bord[i] = tolower(word[i]);
    }

    int bucket = hash(bord);
    node *cursor = table[bucket];
    while (cursor != NULL)
    {
        if(strcasecmp(cursor->word, bord) == 0)
        {
            return true;
        }
        else
        {
            cursor=cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hash = 0;
    int first = 0;
    int second = 0;
    if(word[0] > 64)
    {
        first = word[0]-32;
    }
    else
    {
        first = word[0];
    }
    if(word[1] > 64)
    {
        second = word[1]-32;
    }
    else
    {
        second = word[1];
    }
    int bucket = ((first - 65)*26) + (second - 65);
    printf("%i", bucket);
    return bucket;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char buff[LENGTH + 1];
    // TODO
    //fopen
    FILE * fp;
    fp = fopen("dictionary", "w");
    //check if return value is NULL
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return 1;
    }
    //read strings
    //fscanf(file, "%s", word)
        //EOF means end of file
    while (fscanf(fp, "%s", buff) != EOF)
    {
        //create node
        node *tmp = malloc(sizeof(node));

        strncpy(tmp->word, buff, sizeof(buff));
        int index = hash(buff);

        if (table[index] == NULL)
        {
            table[index] = tmp;
        }
        else
        {
            tmp->next = table[index];
            table[index] = tmp;
        }
        fp_size++;
    }

    fclose(fp);
    return true;

        //check if return is NULL
       // if (n == NULL)
  //      {
//            return false;
 //       }
        //copy word into node
 //       strcpy(n->word, word);
 //      n->next = NULL;
 //       int bucket = hash(word);
 //       n->next = table[bucket];
 //       table[bucket] = n;
        //use hash function to return an index
        //insert word into linked list
            //set pointers in correct order
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return fp_size;
}

void end(node *head)
{
    if (head->next != NULL)
    {
        end(head->next);
    }
    free(head);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    //free memory using valgrind
    for (int i = 0; i < N; i ++)
    {
        if (table[i] != NULL)
        {
            end(table[i]);
        }
    }
    return true;
}
