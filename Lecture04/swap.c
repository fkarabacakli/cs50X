#include <stdio.h>
#include <cs50.h>

void swap(int *a, int *b);

int main(void)
{
    int first = get_int("First Number=");
    int second = get_int("Second Number=");

    printf("First is %i. Second is %i.\n", first, second);
    swap(&first, &second);
    printf("First is %i. Second is %i.\n", first, second);
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}