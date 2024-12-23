#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

const int LIST_SIZE = 2;

typedef struct node
{
    char *pharase;
    struct node *next;

}node;

void unload(node *list);
void visualize(node *list);

int main(void)
{
    node *list = NULL;

    for(int i=0 ; i < LIST_SIZE ; i++)
    {
        string pharase = get_string("What is the string ==>");

        node *n = malloc(sizeof(node));
        if ( n == NULL)
        {
            return 1;
        }


        n->pharase = pharase;
        n->next = NULL;

        n->next = list;
        list = n;



    }
    visualize(list);
    unload(list);


}

void unload(node *list)
{

    while(list != NULL)
    {
        node *ptr = list->next;
        free (list);
        list = ptr;

    }
}

void visualize(node *list)
{
    node *temp = list;

    while(temp!=NULL)
    {
        printf("-----------------------\n");
        printf("Loacation %p\n",temp);
        printf("Pharase : /%s/\n",temp->pharase);
        printf("Next : /%p/\n\n", temp->next);
        printf("-----------------------\n");
        temp= temp->next;
    }

}