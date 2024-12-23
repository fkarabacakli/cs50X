#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    string k =get_string("What is the k=>");
    string l = get_string("What is the l=>");

    if(strcasecmp(k,l)==0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}