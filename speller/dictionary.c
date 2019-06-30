// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define hashTableSize 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// node *node1 = malloc(sizeof(node);
// node *node2 = malloc(sizeof(node);

// strcpy(node1->word, "Hello");
// strcpy(node2->word, "World");

// these are two independents nodes
// point to next variable
// node1->next = node2;
// link list of size 2


// Represents a hash table
node *hashtable[hashTableSize];

int dictionaryWords;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < hashTableSize; i++)
    {
        hashtable[i] = NULL;
        // hashtable[i] = malloc(sizeof(node));
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        node *newNode = malloc(sizeof(node));

        if (newNode == NULL)
        {
            unload();
            return false;
        }

        strcpy(newNode->word, word);
        int hashed = hash(word);
        if (hashtable[hashed] == NULL)
        {
            hashtable[hashed] = newNode;;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = hashtable[hashed];
            hashtable[hashed] = newNode;
        }

        dictionaryWords++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
