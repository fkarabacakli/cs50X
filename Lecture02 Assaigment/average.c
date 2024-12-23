#include <stdio.h>
#include <cs50.h>

float avarege (int length, int array[]);
int total (int length, int array[]);

int main(void)
{

    int n = get_int("How Many Week did you study: ");

    int time[n];
    for(int i=0 ; i<n ; i++)
    {
        time[i] = get_int("How many hours did you work on week %i\n", i);
    }
    
    int cevap;
    do 
    {    
    cevap= get_int("Toplam için '1' yazın\nOrtalama için '2' yazın\n");
    }    
    while( cevap<1 || cevap>2 );
    
    if (cevap == 1)
    {
        printf("Total is %i\n" , total(n , time));
    }
    else if (cevap==2)
    {
        printf("Avarege is %f\n" , avarege(n , time));
    }
}

float avarege (int length, int array[])
{
    int sem=0  ;
    for(int i=0 ; i<length ; i++)
    {
        sem += array[i];
    }
    return sem / (float) length;
}  

int total (int length, int array[])
{
    int sem=0  ;
    for(int i=0 ; i<length ; i++)
    {
        sem += array[i];
    }
    return sem;
}  
