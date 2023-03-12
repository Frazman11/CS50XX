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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //make copy of the array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // iterate through each row

    for (int i = 0; i < height; i++)
    {
         //iterate through each column
         for (int j = 0; j < width; j++)
         {
            //calculate sum red, green blue values of pixels within 1 row/column of target
            float sumred, sumgreen, sumblue;
            sumred = sumgreen = sumblue = 0;
            float counter = 0;


            {
                for (int k = -1; k < 2; k++)    //iterate using nested loop over k(rows) and l(height) within 1 of target
                {
                    for (int l = -1; l < 2; l++)
                    {
                        int currentk = i + k;
                        int currentl = j + l;

                        if(currentk < 0 || currentk > (height - 1) || currentl < 0 || currentl > (width - 1))
                        {
                            continue;   //if invalid cell (beyond edges) then skip, if valid (all others) continue in loop
                        }

                        sumred +=  image[currentk][currentl].rgbtRed;
                        sumgreen += image[currentk][currentl].rgbtGreen;
                        sumblue += image[currentk][currentl].rgbtBlue;

                        counter++;
                    }
                    //assign avg r g b  of target to temp
                    temp[i][j].rgbtRed = round(sumred/counter);
                    temp[i][j].rgbtGreen = round(sumgreen/counter);
                    temp[i][j].rgbtBlue = round(sumblue/counter);
                }
            }
         }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
return;
}
