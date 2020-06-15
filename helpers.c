#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float a = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3;
            float avg = nearbyint(a);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
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
            float sepiaRed = (.393 * image[i][j].rgbtRed) + (0.189 * image[i][j].rgbtBlue) + (0.769 * image[i][j].rgbtGreen);
            float sepiaGreen = (.349 * image[i][j].rgbtRed) + (0.168 * image[i][j].rgbtBlue) + (0.686 * image[i][j].rgbtGreen);
            float sepiaBlue = (.272 * image[i][j].rgbtRed) + (0.131 * image[i][j].rgbtBlue) + (0.534 * image[i][j].rgbtGreen);
            float r = round(sepiaRed);
            float g = round(sepiaGreen);
            float b = round(sepiaBlue);
            if (r > 255)
            {
                r = 255;
            }
            if (g > 255)
            {
                g = 255;
            }
            if (b > 255)
            {
                b = 255;
            }
            image[i][j].rgbtRed = r;
            image[i][j].rgbtBlue = b;
            image[i][j].rgbtGreen = g;
        }
    }
    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width/2); j++)
        {
            //image[i][j];
            //image[i][width - j];
            swap(&image[i][j], &image[i][width - j]);
        }
    }
    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE store[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Top Left
            if (i == 0 && j == 0)
            {
                store[i][j].rgbtRed = round((image[0][0].rgbtRed + image[1][0].rgbtRed + image[0][1].rgbtRed + image[1][1].rgbtRed)/4);
                store[i][j].rgbtGreen = round((image[0][0].rgbtGreen + image[1][0].rgbtGreen + image[0][1].rgbtGreen + image[1][1].rgbtGreen)/4);
                store[i][j].rgbtBlue = round((image[0][0].rgbtBlue + image[1][0].rgbtBlue + image[0][1].rgbtBlue + image[1][1].rgbtBlue)/4);
            }
            //Top Row
            else if(i == 0 && j!=0 && j != width-1)
            {
                store[i][j].rgbtRed = round((image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/6);
                store[i][j].rgbtBlue = round((image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/6);
                store[i][j].rgbtGreen = round((image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/6);
            }
            //Top Right
            else if(i == 0 && j == width-1)
            {
                store[i][j].rgbtRed = round((image[0][width-1].rgbtRed + image[1][width-2].rgbtRed + image[0][width-2].rgbtRed + image[1][width-1].rgbtRed)/4);
                store[i][j].rgbtBlue = round((image[0][width-1].rgbtBlue + image[1][width-2].rgbtBlue + image[0][width-2].rgbtBlue + image[1][width-1].rgbtBlue)/4);
                store[i][j].rgbtGreen = round((image[0][width-1].rgbtGreen + image[1][width-2].rgbtGreen + image[0][width-2].rgbtGreen + image[1][width-1].rgbtGreen)/4);
            }
            //Bottom Left
            else if(i == height-1 && j == 0)
            {
                store[i][j].rgbtRed = round((image[height-1][0].rgbtRed + image[height-2][0].rgbtRed + image[height-2][1].rgbtRed + image[height-1][1].rgbtRed)/4);
                store[i][j].rgbtBlue = round((image[height-1][0].rgbtBlue + image[height-2][0].rgbtBlue + image[height-2][1].rgbtBlue + image[height-1][1].rgbtBlue)/4);
                store[i][j].rgbtGreen = round((image[height-1][0].rgbtGreen + image[height-2][0].rgbtGreen + image[height-2][1].rgbtGreen + image[height-1][1].rgbtGreen)/4);
            }
            //Bottom Right
            else if(i == height-1 && j == width-1)
            {
                store[i][j].rgbtRed = round((image[height-1][width-1].rgbtRed + image[height-2][width-1].rgbtRed + image[height-2][width-2].rgbtRed + image[height-1][width-2].rgbtRed)/4);
                store[i][j].rgbtBlue = round((image[height-1][width-1].rgbtBlue + image[height-2][width-1].rgbtBlue + image[height-2][width-2].rgbtBlue + image[height-1][width-2].rgbtBlue)/4);
                store[i][j].rgbtGreen = round((image[height-1][width-1].rgbtGreen + image[height-2][width-1].rgbtGreen + image[height-2][width-2].rgbtGreen + image[height-1][width-2].rgbtGreen)/4);
            }
            //Bottom Row
            else if(i == height - 1 && j !=0 && j != width - 1)
            {
                store[i][j].rgbtRed = round((image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed)/6);
                store[i][j].rgbtBlue = round((image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue)/6);
                store[i][j].rgbtGreen = round((image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen)/6);
            }
            //Leftmost Column
            else if(i != 0 && i != height - 1 && j == 0)
            {
                store[i][j].rgbtRed = round((image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed)/6);
                store[i][j].rgbtBlue = round((image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue)/6);
                store[i][j].rgbtGreen = round((image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen)/6);
            }
            //Rightmost Column
            else if(i != 0 && i != height - 1 && j == width - 1)
            {
                store[i][j].rgbtRed = round((image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed)/6);
                store[i][j].rgbtBlue = round((image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue)/6);
                store[i][j].rgbtGreen = round((image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen)/6);
            }
            //Otherwise
            else
            {
                float red = (image[i+1][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed)/9;
                float green = (image[i+1][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen)/9;
                float blue = (image[i+1][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue)/9;
                store[i][j].rgbtRed = round(red);
                store[i][j].rgbtBlue = round(blue);
                store[i][j].rgbtGreen = round(green);
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = store[i][j].rgbtRed;
            image[i][j].rgbtBlue = store[i][j].rgbtBlue;
            image[i][j].rgbtGreen = store[i][j].rgbtGreen;
        }
    }
    return;
}
