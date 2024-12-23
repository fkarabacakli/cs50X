#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("What is the message:");
    int length = strlen(message);
    
    for(int i=0 ; i<length ; i++)
    {
        unsigned char byte = message[i];
        int bat[8];
    
        for(int j=0 ; j<BITS_IN_BYTE ; j++)
        {
            bat[j]= byte %2 ;
            byte = byte/2;
        }
        for(int k=7; k>=0 ; k--)
        {
            print_bulb(bat[k]);
        }
        printf("\n");
    }        
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
