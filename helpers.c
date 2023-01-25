#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avgvalue = 0;
    for (int a = 0; a < height; a++) //go through the entire column
    {
        for (int b = 0; b < width; b++) //then go through every row
        {
            avgvalue = (image[a][b].rgbtRed + image[a][b].rgbtGreen + image[a][b].rgbtBlue)/3; //average all rgb values
            image[a][b].rgbtRed = avgvalue; //make all the rgb values for the pixel equal
            image[a][b].rgbtGreen = avgvalue;
            image[a][b].rgbtBlue = avgvalue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int a = 0; a < height; a++) //go through the entire column
    {
        for (int b = 0; b < width; b++) //then go through every row
        {
            image[a][b].rgbtRed = .393 * image[a][b].rgbtRed + .769 * image[a][b].rgbtGreen + .189 * image[a][b].rgbtBlue;
            image[a][b].rgbtGreen = .349 * image[a][b].rgbtRed + .686 * image[a][b].rgbtGreen + .168 * image[a][b].rgbtBlue;
            image[a][b].rgbtBlue = .272 * image[a][b].rgbtRed + .534 * image[a][b].rgbtGreen + .131 * image[a][b].rgbtBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    float tempreflectRed;
    float tempreflectBlue;
    float tempreflectGreen;
    int oppositevalue;
    for (int a = 0; a < height ; a++) //go through the entire column
    {
        for (int b = 0; b < (width/2) ; b++) //then go through half of the row
        {
             tempreflectBlue = image[a][b].rgbtBlue;
             tempreflectGreen = image[a][b].rgbtGreen; //store original values in a temp value
             tempreflectRed = image[a][b].rgbtRed;
             oppositevalue = width - b; // take the opposite value
             image[a][b].rgbtRed = image[a][oppositevalue].rgbtRed;
             image[a][b].rgbtGreen = image[a][oppositevalue].rgbtGreen; //replace
             image[a][b].rgbtBlue = image[a][oppositevalue].rgbtBlue;

             image[a][oppositevalue].rgbtRed = tempreflectRed;
             image[a][oppositevalue].rgbtGreen = tempreflectGreen; // replace
             image[a][oppositevalue].rgbtBlue = tempreflectBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumBlue = 0;
            float sumGreen = 0;
            float sumRed = 0;
            float counter = 0;

            for (int r = -1; r < 2; r++) // search area
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1) // if outside of seen values such as negative values dont count it
                    {
                        continue;
                    }

                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[i + r][j + c].rgbtBlue;
                    sumGreen += image[i + r][j + c].rgbtGreen; // average values
                    sumRed += image[i + r][j + c].rgbtRed;
                    counter++; // add a number to counter for rounding
                }
            }

            temp[i][j].rgbtBlue = round(sumBlue / counter); // average values
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    for (int i = 0; i < height; i++) // replace all values for averages
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }

    }

    return;
}
