#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

bool ispdf(uint8_t values[4]);

int main(int argc, string argv[])
{
    if(argc != 2 )
    {
        printf("Uncorrect use!!!\n");
        return 1;
    }

    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    if(file == NULL)
    {
        printf("No such file found.\n");
        return 2;
    }

    uint8_t buffer[4];
    
    fread(buffer, 1, 4 , file);
    fclose(file);

    if(ispdf(buffer) != true)
    {
        printf("It is not pdf file.\n");
        return 3;
    }
    else
    {
        printf("It is pdf file.\n");
        return 0;
    }
    
    

}

bool ispdf(uint8_t values[4])
{
    uint8_t check[4]= {37,80,68,70};
    
    for(int i=0 ; i<4 ;i++)
    {
        if(values[i]!=check[i])
        {
            return false;
        }
    }
   return true;
}

