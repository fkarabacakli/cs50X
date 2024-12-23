#include <stdio.h>

int main(void)
{
    char name;
    
    printf("What is your name?");
    scanf("%s\n", &name);
   
    char uni[20];
    printf("what is your uni?");
    scanf("%s\n", &uni);
    
    printf("Hello,%s,%s\n", name,uni);
}