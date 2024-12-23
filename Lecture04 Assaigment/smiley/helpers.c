#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0 ; i< width; i++)
    {
        for(int j=0 ;  j<height; j++)
        {
            if(image[i][j].rgbtBlue==0 && image[i][j].rgbtGreen==0 && image[i][j].rgbtRed==0)
            {
                image[i][j].rgbtBlue=123;
                image[i][j].rgbtGreen=43;
                image[i][j].rgbtRed=240;
            }
        }
    }

}
