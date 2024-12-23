#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int length;
    do
    {
        length = get_int("What is the length; ");
    }
    while(length<1);

    int start;
    do 
    {
        start = get_int("What is the start number; ");
    }
    while(start<1);

    
    long int array[length];
    array[0]=start;
   
    for (int i=0; i<length ;i++)
    {
        array[i+1]=array[i]*2;
        printf("%li\n", array[i]);
    }
    
}  