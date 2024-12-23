#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main(int argc , string argv[])
{
    int length = strlen(argv[1]);

   if(argc !=2)
    {
        printf("no-vowels word\n");
        return 1;
    }
    else
    {
        for(int i=0 ; i< length  ; i++)
        {
            switch (argv[1][i])
            {
            case 'a':
                printf("6");
                break;
            case 'e':
                printf("3");
                break;
            case 'i':
                printf("1");
                break;
            case 'o':
                printf("0");
                break;
            default:
                printf("%c", argv[1][i]);
                break;
            }
    
        }

    }
    printf("\n");

}