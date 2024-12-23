#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int total;
    for(int i=0 ; i<height; i++)
    {
        for(int j=0 ; j<width ; j++)
        {
            total = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            total = total /3;
            image[i][j].rgbtRed = total;
            image[i][j].rgbtGreen = total;
            image[i][j].rgbtBlue = total;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0 ; i<height ; i++)
    {
        if(width % 2 == 0)
        {
            for(int j=0 ; j< width/2 ; j++)
            {
                RGBTRIPLE temps[height][width];
                temps[i][j] = image[i][j];
                image[i][j] = image[i][width-(j+1)];
                image[i][width-(j+1)]=temps[i][j];
            }
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i=0; i<height; i++)
    {
        for(int j=0; j< width; j++)
        {
            int red=0;
            int green=0;
            int blue=0;
            double total=0;

            for(int s=i-1; s<i+2 ; s++ )
            {
                if(s<0)
                continue;
                
                for(int m=j-1; m<j+2; m++)
                {
                    if(m<0)
                    continue;

                    red += copy[s][m].rgbtRed;
                    green += copy[s][m].rgbtGreen;
                    blue += copy[s][m].rgbtBlue;
                    total += 1;
                }
            }

            image[i][j].rgbtRed   = red/total;
            image[i][j].rgbtGreen = green/total;
            image[i][j].rgbtBlue  = blue/total;
        
        
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int gx[3][3]={{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3]={{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};


    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int gxblue=0;
            int gyblue=0;
            int gxred=0;
            int gyred=0;
            int gxgreen=0;
            int gygreen=0;
            
            
            for(int r=-1 ; r<2 ;r++)
            {
                
                
                for(int c=-1 ; c<2; c++)
                {
                    if (i + r < 0 || i + r > height - 1)
                    {
                        continue;
                    }
                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }


                    gxblue  += image[i+r][j+c].rgbtBlue   * gx[r+1][c+1];
                    gyblue  += image[i+r][j+c].rgbtBlue   * gy[r+1][c+1];

                    gxred   += image[i+r][j+c].rgbtRed    * gx[r+1][c+1];
                    gyred   += image[i+r][j+c].rgbtRed    * gy[r+1][c+1];
                    
                    gygreen += image[i+r][j+c].rgbtGreen  * gx[r+1][c+1];
                    gygreen += image[i+r][j+c].rgbtGreen  * gy[r+1][c+1];

                }
            }

            int blue = round(sqrt(gxblue  * gxblue  + gyblue  * gyblue));
            int green= round(sqrt(gxgreen * gxgreen + gygreen * gygreen));
            int red  = round(sqrt(gxred   * gxred   + gyred   * gyred));

            
            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;

        }
    }

        
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }    
        

}
