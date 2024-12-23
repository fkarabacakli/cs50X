#include <stdio.h>
#include <cs50.h>


typedef struct 
{
    string name;
    int vote;
}
candidate;

candidate get_candidate(string prompt);


int main(void)
{
   int n= get_int("How many president => ") ;
   
   candidate presidents[n];
   
   for (int i=0; i<n;i++)
   {
        presidents[i] = get_candidate("Enter a candidate");
   }
   


   
}

candidate get_candidate(string prompt)
{
    //ayperi♥semih
    printf("%s\n", prompt);
    candidate c;
    c.name = get_string("Enter a name =>");
    c.vote = get_int("Enter a number of votes =>");
    return c;
    
}