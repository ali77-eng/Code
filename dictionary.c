#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define MAX_BUCKETS 60000

// create a struct
struct node{
    char word[LENGTH+1];
    struct node *next;
};

typedef struct node *node_ptr;

// global variables
node_ptr hashtable[MAX_BUCKETS];
int dictionary_word_counter = 0;



/******
START Custom functions
******/


size_t precision = 2; //change the precision with this
size_t generate_hash(const char* str)
{
   return ((*(size_t*)str)>> precision) % MAX_BUCKETS;
}




void insert(node_ptr node, int index){

    // check if the array location is null
    if ( !(hashtable[index]) ){ // means if array location is null
        // insert the node and that's that
        hashtable[index] = node;
    }
    else{
        // there is a node already at that location
        // assign our node as the head of the new linked list

        // we need to store the ptr to the old node in a temp variable
        node_ptr temp = hashtable[index];

        // now we can assign the new node to the head of the list
        hashtable[index] = node;

        // and attach the  old head node to the new head's next property
        node->next = temp;

        //printf("linked list created at index: %d\n", index);
    }

}


void free_linked_list(node_ptr head_ptr){

    while(head_ptr != NULL){

        // create temp variable to save the memory location of the head pointer
        node_ptr temp = head_ptr;

        // set the head node equal to it's next property making it the next node
        head_ptr = head_ptr->next;

        // free the temp variable which deletes the original head node
        free(temp);
    }

}

/******
END Custom functions
******/





/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{

    int len = strlen(word);

    char * lower_case_word = malloc( sizeof(char) * (len+1) );

    lower_case_word[len+1] = '\0';



    // change all letters to lowercase
    for(int i = 0; i < len; i++){
        lower_case_word[i] = tolower(word[i]);
    }

    // generate the int hash
    int index = generate_hash(lower_case_word);

    // traverse the linked list at the array index
    node_ptr trav = hashtable[index];

    // loop through while node->next is not null
    while (trav != NULL){
        if ( strcmp(trav->word, lower_case_word) == 0){
            return true;
        }

        trav = trav->next;

    }

    // if we get to this point the word was not found
    //printf("searched the entire bucket and the word was not found!\n");

    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary) // passing in the file name of the dictionary
{
    // create a FILE pointer and fopen() to start the stream
    FILE * dictionary_stream = fopen(dictionary, "r");

    // get each line
    // create a node
    // save to node->text
    // insert into hashtable


    char temp[LENGTH+1] = {'\0'};

    // the condition in this while loop is also storing
    // the string as well so...a slick way of doing
    // two jobs in one place!
    while (fscanf(dictionary_stream, "%s", temp) == 1){

        // make space for a node
        node_ptr d_node_ptr = malloc(sizeof(struct node));

        // set node's next property to null
        d_node_ptr->next = NULL;

        // save the current word in the node's char property

        strcpy(d_node_ptr->word, temp);

        // generate a hash
        int ht_index = generate_hash(d_node_ptr->word);

        // insert node into hashtable
        insert(d_node_ptr, ht_index);

        //
        dictionary_word_counter++;

        //printf("item inserted %s at index: %d\n", hashtable[ht_index]->word, ht_index);
    }

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictionary_word_counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i < MAX_BUCKETS; i++){
        free_linked_list(hashtable[i]);
    }

    return true;
}
