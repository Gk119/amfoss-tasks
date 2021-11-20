#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            unsigned char blue = image[i][j].rgbtBlue;
            unsigned char green = image[i][j].rgbtGreen;
            unsigned char red = image[i][j].rgbtRed;
            unsigned char avg = (blue + green + red) / 3;

            RGBTRIPLE gs;
            gs.rgbtBlue = avg;
            gs.rgbtGreen = avg;
            gs.rgbtRed = avg;

            image[i][j] = gs;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            unsigned char originalBlue = image[i][j].rgbtBlue;
            unsigned char originalGreen = image[i][j].rgbtGreen;
            unsigned char originalRed = image[i][j].rgbtRed;

            int sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            int sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            int sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            sepiaRed = sepiaRed < 255 ? sepiaRed : 255;
            sepiaGreen = sepiaGreen < 255 ? sepiaGreen : 255;
            sepiaBlue = sepiaBlue < 255 ? sepiaBlue : 255;

            RGBTRIPLE sepia;
            sepia.rgbtBlue = (unsigned char)sepiaBlue;
            sepia.rgbtGreen = (unsigned char)sepiaGreen;
            sepia.rgbtRed = (unsigned char)sepiaRed;

            image[i][j] = sepia;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j -1];
            image[i][width - j -1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int pcount = 1;
            int rsum, gsum, bsum;
            rsum = image[i][j].rgbtRed;
            gsum = image[i][j].rgbtGreen;
            bsum = image[i][j].rgbtBlue;

            if(i - 1 >= 0 && j - 1 >= 0)    //tl
            {
                pcount++;
                rsum += image[i - 1][j - 1].rgbtRed;
                gsum += image[i - 1][j - 1].rgbtGreen;
                bsum += image[i - 1][j - 1].rgbtBlue;
            }
            if(i - 1 >= 0 && j + 1 < width)    //tr
            {
                pcount++;
                rsum += image[i - 1][j + 1].rgbtRed;
                gsum += image[i - 1][j + 1].rgbtGreen;
                bsum += image[i - 1][j + 1].rgbtBlue;
            }
            if(i + 1 < height && j - 1 >= 0)    //bl
            {
                pcount++;
                rsum += image[i + 1][j - 1].rgbtRed;
                gsum += image[i + 1][j - 1].rgbtGreen;
                bsum += image[i + 1][j - 1].rgbtBlue;
            }
            if(i + 1 < height && j + 1 < width)    //br
            {
                pcount++;
                rsum += image[i + 1][j + 1].rgbtRed;
                gsum += image[i + 1][j + 1].rgbtGreen;
                bsum += image[i + 1][j + 1].rgbtBlue;
            }
            if(j - 1 >= 0)  //l
            {
                pcount++;
                rsum += image[i][j - 1].rgbtRed;
                gsum += image[i][j - 1].rgbtGreen;
                bsum += image[i][j - 1].rgbtBlue;
            }
            if(j + 1 < width)  //r
            {
                pcount++;
                rsum += image[i][j + 1].rgbtRed;
                gsum += image[i][j + 1].rgbtGreen;
                bsum += image[i][j + 1].rgbtBlue;
            }
            if(i - 1 >= 0)  //t
            {
                pcount++;
                rsum += image[i - 1][j].rgbtRed;
                gsum += image[i - 1][j].rgbtGreen;
                bsum += image[i - 1][j].rgbtBlue;
            }
            if(i + 1 < width)  //b
            {
                pcount++;
                rsum += image[i + 1][j].rgbtRed;
                gsum += image[i + 1][j].rgbtGreen;
                bsum += image[i + 1][j].rgbtBlue;
            }

            image[i][j].rgbtRed = (unsigned char)(rsum / pcount);
            image[i][j].rgbtGreen = (unsigned char)(gsum / pcount);
            image[i][j].rgbtBlue = (unsigned char)(bsum / pcount);
        }
    }
    return;
}
