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

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
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
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char * word = 0;
    // TODO
    //fopen
    FILE * fp;
    fp = fopen("dictionary", "w");
    //check if return value is NULL
    if (fp == NULL)
    {
        return 1;
    }
    //read strings
    //fscanf(file, "%s", word)
        //EOF means end of file
    while (fscanf(fp, "%s", word) != EOF)
    {
        //create node
        node *n = malloc(sizeof(node));
        //check if return is NULL
        if (n == NULL)
        {
            return false;
        }
        //copy word into node
        strcpy(n->word, word);
        n->next = NULL;
        int bucket = hash(word);
        n->next = table[bucket];
        table[bucket] = n;
        //use hash function to return an index
        //insert word into linked list
            //set pointers in correct order
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false


void freeSLList(node *n)
{
    if(n == NULL)// base case
    {
        // stop
        free(n);
    }
    else
    {
        freeSLList(n->next);
        free(n);
    }
}
bool unload(void)
{
    //free the malloc for each linked list in table
    for (int i = 0; i < N; i++)
    {
        freeSLList(table[i]);
    }

    return true;
}