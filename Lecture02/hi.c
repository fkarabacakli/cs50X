#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = get_string("What is your name? \n");
    int n = strlen(name);
    printf("%i char \n", n);

}