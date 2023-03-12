#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through each row

for (int i = 0; i < height; i++)
{
    //iterate through each pixel in width
    for (int j = 0; j < width; j++)
    {
        //for each pixel calculate average RGB pixel value
        //add rgbtRed, rgbtgreen, rgbtblue together and divide by 3.0
        float red = image[i][j].rgbtRed;
        float green = image[i][j].rgbtGreen;
        float blue = image[i][j].rgbtBlue;

        int avgc = round((red + green + blue)/3.0);   //assign new avg value (rounded to an int) to that pixel's RGB values

        image[i][j].rgbtRed = avgc;
        image[i][j].rgbtGreen = avgc;
        image[i][j].rgbtBlue = avgc;
    }
}
return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen  = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)    //iterate through each row
    {
        for (int j = 0; j < width/2; j++)   //iterate through each column
        {
            int* copyRed = malloc(3);
            int* copyGreen = malloc(3);
            int* copyBlue = malloc(3);

            *copyRed = image[i][width - (j + 1)].rgbtRed;
            *copyGreen = image[i][width - (j + 1)].rgbtGreen;
            *copyBlue = image[i][width - (j + 1)].rgbtBlue;

            image[i][width - (j + 1)].rgbtRed = image[i][j].rgbtRed;
            image[i][width - (j + 1)].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - (j + 1)].rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = *copyRed;
            image[i][j].rgbtGreen = *copyGreen;
            image[i][j].rgbtBlue = *copyBlue;

            free(copyRed);
            free(copyGreen);
            free(copyBlue);
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate through each row

    for (int i = 0; i < height; i++)
    {
         //iterate through each column
         for (int j = 0; j < width; j++)
         {
            //calculate avg red, green blue values of pixels within 1 row/column of target
            float sumred;
            float sumgreen;
            float sumblue;


            {
                for (int k = -1; k < 2; k++)
                {
                    for (int l = -1; l < 2; l++)
                    {
                        if ((i < height) || (!i == 0) || (j < width) || (!j == 0))
                        {
                            continue;
                        }

                        sumred+ = image[k][l].rgbtRed;
                        sumgreen+ = image[k][l].rgbtGreen;
                        sumblue+ = image[k][l].rgbtBlue;
                    }
                }
            }
            //assign avg r g b to target
            int avgred = round(sumred/3.0);
            int avggreen = round(sumgreen/3.0);
            int avgblue = round(sumblue/3.0);

            image[i][j].rgbtRed = avgred;
            image[i][j].rgbtGreen = avggreen;
            image[i][j].rgbtblue = avgblue;
         }






    return;
}
