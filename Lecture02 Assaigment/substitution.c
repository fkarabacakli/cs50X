#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int k = 1;

int main(int argc, string argv[]) 
{
    bool kontrol0=true;
    bool kontrol1=true;
    
    if(argc==2)
    {
        if(strlen(argv[k])==26)
        {
            for(int i=0 ; i<26 ; i++)
            {
                if(isalpha(argv[k][i]))
                {

                }
                else
                {
                    kontrol1=false;
                }
            }

            for(int i=0; i<26 ; i++)
            {
                for(int j=i+1 ; j<26 ; j++)
                {
                    if(argv[k][i]==argv[k][j])
                    {
                        kontrol1=false;
                    }
                    else if (argv[k][i]+32==argv[k][j])
                    {
                        kontrol1=false;
                    }
                    else if(argv[k][i]==argv[k][j]+32)
                    {
                        kontrol1=false;
                    }
                }
            }
        
        }
        else
        {
            kontrol1=false;
        }
    }
    else
    {
        kontrol0=false;
    }
    
    if(kontrol0==0)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    else if(kontrol1==0)
    {
        printf("Key must contain 26 characters.\n");
        return 2;
    }

    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);

    printf("cybertext: ");
   
    for(int i=0 ; i<length ; i++)    
    {
        if(isalpha(plaintext[i]))
        { 
        
            if(isupper(plaintext[i]))
            {
                int sıra = plaintext[i]-65;
                printf("%c",toupper(argv[k][sıra]));
            }
            else if(islower(plaintext[i]))
            {
                int sıra = plaintext[i]-97;
                printf("%c",tolower(argv[k][sıra]));
            }
        }
        else
        {
            printf("%c",plaintext[i]);
        }
        
    }
    printf("\n");
}