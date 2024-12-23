// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int n =  strlen(word);
    char word_copy[LENGTH+1];

    for(int i=0 ; i<n ; i++)
    {
        word_copy[i]=word[i];
    }
    word_copy[n]='\n';
    
    int h = hash(word_copy);

    node *cursor= table[h];

    while(cursor !=NULL)
    {
        if(strcasecmp(cursor->word , word_copy)==0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if(file ==NULL)
    {
        return false;
    }
    char word[LENGTH +1];
    
    while (fscanf(file,"%s",word)!=EOF)
    {
        node *new_node = malloc(sizeof(node));

        strcpy(new_node->word,word);

        int h = hash(new_node->word);

        node *head = table[h];
        
        if (head == NULL)
        {
            table[h] = new_node;
            word_count++;
        }
        else
        {
            new_node->next = table[h];
            table[h] = new_node;
            word_count++;
        }
    }
    fclose(file);
    return true;
    
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *head=NULL;
    node *cursor= head;
    
    while(cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}
