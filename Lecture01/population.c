#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int start ;
    int finish;
    int yil = 0;
    do
    {
       start = get_int ("What is the start number? ");
    }
    while( start < 9);

    do
    {
        finish = get_int ("what is the finish number? ");
    }
    while(finish<start);


    do
    {
       start += start/12;
        yil++;
    }
    while(start<finish);
    printf("%i\n", yil);
}