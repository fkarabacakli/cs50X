#include <stdio.h>

int main(void)
{
   int n ;
   do
   {
    printf("Bir sayı giriniz =>");
    scanf("%d", &n);
   }
   while (n<1);
    
   for(int i=0 ; i<n ; i++)
    {
        for (int j= ; j<n ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}   