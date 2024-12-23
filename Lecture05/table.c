#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

typedef struct node
{
    string pharase;
    struct node *next;
}node;

const int verb = 3;

node table[26];

int hash(string pharase);

int main(void)
{
    for(int i=0 ; i<verb ; i++)
    {
        string pharase = get_string("What is the pharase ? ");
        printf("%s hashes to %i\n", pharase, hash(pharase));
    }
}

int hash(string pharase)
{
    int s = tolower(pharase[0]);
    s = s-97;
    return s;    
}
