#include <stdio.h>

int main(void)
{
  
int say = 0;
int start;
int end;
printf("Kaç hayvan var?");
scanf("%d", &start);
printf("Kaç hayvana ulaşsın?");
scanf("%d", &end);

    while(start<end) 
    {
        start= start+(start/3)-(start/4);
        say++ ;
    }
           
           
printf("%i", &say);
        
}

