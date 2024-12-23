#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int computer_score (string cevap);
int points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main(void)
{

    string word1 = get_string("Player ı : ");
    string word2 = get_string("Player 2 : ");

    int total1 = computer_score(word1) ;
    int total2 = computer_score(word2) ;

    if ( total1>total2)
    {
        printf("Player 1 wins! \n");
    }
    else if ( total2>total1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int computer_score (string cevap)
{
    int sem=0 ;
    int length = strlen(cevap);

    for(int i=0 ; i<length ; i++)
    {


       if(isupper(cevap[i]))
        {
            sem += points[cevap[i]-65];
        }
       else if(islower(cevap[i]))
        {
            sem += points[cevap[i]-97];
        }

    }
   return sem;
}
