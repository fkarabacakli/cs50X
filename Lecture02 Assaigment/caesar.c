#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) 
{   
    const int k =1 ;
    int length_number = strlen(argv[k]);
    bool check = true;
    int jump = atoi(argv[k]);
    
    if(argc==2)
    {
       for(int i=0 ; i<length_number ; i++)
       {
            if(isdigit(argv[k][i]))
            {
            }
            else
            {
                check=false;
            }
        }
        
    }
    else
    {
        check=false;
    }   

    if(check==true)
    {
        string plaintext = get_string("Plaintext: ");
        int length = strlen(plaintext);
        char harf[length];
        for(int i=0 ; i<length ; i++)
        {
            if(isalpha(plaintext[i]))
            {
                if(isupper(plaintext[i]))
                {
                    harf[i]=(((plaintext[i]-65)+jump)%26)+65;
                }
                else
                {
                    harf[i]=(((plaintext[i]-97)+jump)%26)+97;
                }
            }
            else
            {
                harf[i] = plaintext[i];
            }

        }

        printf("ciphertext: "); 
        for (int i=0 ; i<length ; i++)
        {
            printf("%c" , harf[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key \n");
    }



}

