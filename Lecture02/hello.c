#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string aswer = get_string("What is your name? \n");
    printf("Hello, %s\n", aswer);

}