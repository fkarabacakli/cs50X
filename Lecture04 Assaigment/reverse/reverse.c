#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc !=3)
    {
        printf("Uncorrect usage!!\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *infile = fopen(argv[1], "r");
    if(infile==NULL)
    {
        printf("No such a file!!\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER buffer;
    fread(&buffer,sizeof(buffer),1,infile);

    // Use check_format to ensure WAV format
    // TODO #4
    if(check_format(buffer)==0)
    {
        fclose(infile);
        printf("Invalid type file!!\n");
    }
    

    // Open output file for writing
    // TODO #5
    FILE *outfile = fopen(argv[2], "w");

    // Write header to file
    // TODO #6
    fwrite(&buffer,sizeof(buffer),1,outfile);


    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(buffer);

    // Write reversed audio to file
    // TODO #8
    fseek(infile,block_size,SEEK_END);
    WAVHEADER copy;
    while(ftell(infile)-block_size > sizeof(buffer))
    {
        fseek(infile, -2 * block_size, SEEK_CUR);
        fread(&copy,block_size,1,infile);
        fwrite(&copy,block_size,1,outfile);
    }
    fclose(infile);
    fclose(outfile);

}

int check_format(WAVHEADER header)
{
    // TODO #4
    char check[4]= {'W','A','V','E'};
    for (int i=0 ; i<4 ; i++)
    {
        if(header.format[i]!=check[i])
        {
            return 0;
        }
    }
    return 1;

}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size;
    WORD bytespersample = header.bitsPerSample/8;
    size= bytespersample * header.numChannels;
    return size;
}