#include <stdio.h>
#include <cs50.h>

int fact(int n);

int main(void)
{
    int j = get_int("What is the number? ");

    printf("%i faktoriyel is equal => %i\n",j,fact(j));
}

int fact(int n)
{
    if( n==1 )
    {
        return 1;
    }
    else
    {
        return n * fact(n-1);
    }
}