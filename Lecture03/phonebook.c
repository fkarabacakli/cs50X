#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    const int n=2;
    person people[n];

    people[0].name = "Halil";
    people[0].number = "+90-535-252-3900";
    people[1].name = "Furkan";
    people[1].number = "+90-539-387-7602";
   
    string name = get_string("What is the name =>");
    
    for(int i=0 ; i<n ;i++)
    {
        if(strcmp(people[i].name,name)==0)
        {
            printf("Found. Number is %s\n", people[i].number);
            return 0 ;
        }
    }
    printf("Not Found\n");
    return 1;
}


