#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    bool lower = false;
    bool upper = false;
    bool digit = false;
    
    string password = get_string("What is the password? \n");
    int length = strlen(password);
    
    for(int i=0 ; i<length ; i++ )
    {
        if(islower(password[i]))
        {
            lower = true;
        }
        else if(isupper(password[i]))
        {
            upper = true;
        }
        else if (isdigit(password[i]))
        {
            digit = true;
        }
        else 
        {}
    }
    if (lower==true && upper==true && digit==true)
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol!\n");
    }
}