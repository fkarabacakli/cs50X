#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if(argc !=2)
    {
        printf("Uncorrect command.\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    
    if(infile==NULL)
    {
        printf("Could not opened.\n");
        return 1;
    }

    
    
    int count=0;
    BYTE buffer[512];
    
    char filename[8];
    FILE* outfile =NULL;
    
    while(fread(buffer,sizeof(BYTE),512,infile)==512)
    {
        
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            
            if(outfile ==NULL)
            {
                sprintf(filename,"%03i.jpg",count);
                outfile = fopen(filename,"w");
                fwrite(&buffer,sizeof(BYTE),512,outfile);
                count += +1 ;
            }
            else if(outfile != NULL)
            {
                fclose(outfile);
                sprintf(filename,"%03i.jpg",count);
                outfile = fopen(filename ,"w");
                fwrite(&buffer,sizeof(BYTE),512,outfile);
                count += +1;
            }
            
        }
        else if( outfile !=NULL)
        {
            fwrite(buffer,sizeof(BYTE),512,outfile);
        }
    }
    fclose(outfile);
    fclose(infile);


}