#include "helpers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++) // loop for height
    {
        for (int w = 0; w < width; w++) // loop for width
        {
            float avgRGB = round((float)(image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3); // calculate avg
            image[h][w].rgbtRed = round(avgRGB); // apply
            image[h][w].rgbtGreen = round(avgRGB); // apply
            image[h][w].rgbtBlue = round(avgRGB); // apply
        }
    }
    return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int OGRed, OGGreen, OGBlue = 0; // variables to store OG colors
    float sepiaRed, sepiaGreen, sepiaBlue = 0; // Float for Sepia Values
    for (int h = 0; h < height; h++) // loop for height
    {
        for (int w = 0; w < width; w++) // loop for width
        {
            OGRed = image[h][w].rgbtRed; // assign OG Red
            OGGreen = image[h][w].rgbtGreen; // assign OG Green
            OGBlue = image[h][w].rgbtBlue; // assign OG Blue

            sepiaRed = round((float)(.393 * OGRed) + (.769 * OGGreen) + (.189 * OGBlue)); // find sepiaRed Caclulation and assign to variable

            if (sepiaRed > 255) // ask if SepiaRed > 255
            {
                image[h][w].rgbtRed = 255; // if true assign Red pixels to 255
            }
            else
            {
                image[h][w].rgbtRed = round(sepiaRed); // if false assign to SepiaRed
            }

            sepiaGreen = round((float)(.349 * OGRed) + (.686 * OGGreen) + (.168 *
                               OGBlue)); // find sepiaGreen Caclulation and assign to variable

            if (sepiaGreen > 255) // ask if SepiaRed > 255
            {
                image[h][w].rgbtGreen = 255; // if true assign Green pixels to 255
            }
            else
            {
                image[h][w].rgbtGreen = round(sepiaGreen); // if false assign to SepiaGreen
            }

            sepiaBlue = round((float)(.272 * OGRed) + (.534 * OGGreen) + (.131 * OGBlue)); // find sepiaBlue Caclulation and assign to variable

            if (sepiaBlue > 255) // ask if SepiaRed > 255
            {
                image[h][w].rgbtBlue = 255; // if true assign Blue pixels to 255
            }
            else
            {
                image[h][w].rgbtBlue = round(sepiaBlue); // if false assign to SepiaBlue
            }
        }
    }
    return;
}
// Reflect image horizontally
void swap(RGBTRIPLE *, RGBTRIPLE *); // call swap function
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int H = 0, W = 0, swapW = width; H < height; H++) // loop for height, add a swap value for swap function
    {
        while (W < width && swapW > W) // loop if swap is not finished on row 'H'
        {
            swap(&image[H][W], &image[H][swapW - 1]); // if not, swap
            W++; // increment to move to next swap
            swapW--; //decrement to move to next swap
        }
        W = 0; // when finished return W to 0 to prepare for next row or 'H'
        swapW = width; // when finished return swapW to value of width to prepare for next row or 'H'
    }
    return;
}

void swap(RGBTRIPLE *x, RGBTRIPLE *y)  // create swap function
{
    RGBTRIPLE tmp = *x; // create temporary value and assign to 'x'
    *x = *y; // assign 'x' to 'y'
    *y = tmp; // assign 'y' to 'tmp' to complete swap
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; // create temporary variable to store original img
    for (int h = 0; h < height; h++) // loop for height
    {
        for (int w = 0; w < width; w++) // loop for width
        {
            temp[h][w] = image[h][w]; // store original image to temp
        }
    }

    for (int h = 0; h < height; h++) // loop for height
    {
        for (int w = 0; w < width; w++) // loop for width
        {
            if (h == 0 && w == 0) // blur top left corner
            {
                float TLcornerRED = round((float)(temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed + temp[h + 1][w + 1].rgbtRed + temp[h +
                                                  1][w].rgbtRed) / 4); // find avg of surrounding pixels
                float TLcornerGREEN = round((float)(temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen + temp[h + 1][w + 1].rgbtGreen + temp[h +
                                                    1][w].rgbtGreen) / 4); // find avg of surrounding pixels
                float TLcornerBLUE = round((float)(temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue + temp[h + 1][w + 1].rgbtBlue + temp[h +
                                                   1][w].rgbtBlue) / 4); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(TLcornerRED); // assign avg to img
                image[h][w].rgbtGreen = round(TLcornerGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(TLcornerBLUE); // assign avg to img
            }
            else if (h == 0 && w == width - 1) // top right corner
            {
                float TRcornerRED = round((float)(temp[h][w].rgbtRed + temp[h][w - 1].rgbtRed + temp[h + 1][w - 1].rgbtRed + temp[h +
                                                  1][w].rgbtRed) / 4); // find avg of surrounding pixels
                float TRcornerGREEN = round((float)(temp[h][w].rgbtGreen + temp[h][w - 1].rgbtGreen + temp[h + 1][w - 1].rgbtGreen + temp[h +
                                                    1][w].rgbtGreen) / 4); // find avg of surrounding pixels
                float TRcornerBLUE = round((float)(temp[h][w].rgbtBlue + temp[h][w - 1].rgbtBlue + temp[h + 1][w - 1].rgbtBlue + temp[h +
                                                   1][w].rgbtBlue) / 4); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(TRcornerRED); // assign avg to img
                image[h][w].rgbtGreen = round(TRcornerGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(TRcornerBLUE); // assign avg to img
            }
            else if (h == height - 1 && w == 0) // bottom left corner
            {
                float BLcornerRED = round((float)(temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed + temp[h - 1][w + 1].rgbtRed + temp[h -
                                                  1][w].rgbtRed) / 4); // find avg of surrounding pixels
                float BLcornerGREEN = round((float)(temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen + temp[h - 1][w + 1].rgbtGreen + temp[h -
                                                    1][w].rgbtGreen) / 4); // find avg of surrounding pixels
                float BLcornerBLUE = round((float)(temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue + temp[h - 1][w + 1].rgbtBlue + temp[h -
                                                   1][w].rgbtBlue) / 4); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(BLcornerRED); // assign avg to img
                image[h][w].rgbtGreen = round(BLcornerGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(BLcornerBLUE); // assign avg to img
            }
            else if (h == height - 1 && w == width - 1) // bottom right corner
            {
                float BRcornerRED = round((float)(temp[h][w].rgbtRed + temp[h][w - 1].rgbtRed + temp[h - 1][w - 1].rgbtRed + temp[h -
                                                  1][w].rgbtRed) / 4); // find avg of surrounding pixels
                float BRcornerGREEN = round((float)(temp[h][w].rgbtGreen + temp[h][w - 1].rgbtGreen + temp[h - 1][w - 1].rgbtGreen + temp[h -
                                                    1][w].rgbtGreen) / 4); // find avg of surrounding pixels
                float BRcornerBLUE = round((float)(temp[h][w].rgbtBlue + temp[h][w - 1].rgbtBlue + temp[h - 1][w - 1].rgbtBlue + temp[h -
                                                   1][w].rgbtBlue) / 4); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(BRcornerRED); // assign avg to img
                image[h][w].rgbtGreen = round(BRcornerGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(BRcornerBLUE); // assign avg to img
            }
            else if (h > 0 && h < height - 1 && w == 0) // left side middles
            {
                float LSmiddleRED = round((float)(temp[h][w].rgbtRed + temp[h - 1][w].rgbtRed + temp[h - 1][w + 1].rgbtRed + temp[h][w + 1].rgbtRed
                                                  + temp[h + 1][w + 1].rgbtRed + temp[h + 1][w].rgbtRed) / 6); // find avg of surrounding pixels
                float LSmiddleGREEN = round((float)(temp[h][w].rgbtGreen + temp[h - 1][w].rgbtGreen + temp[h - 1][w + 1].rgbtGreen + temp[h][w +
                                                    1].rgbtGreen + temp[h + 1][w + 1].rgbtGreen + temp[h + 1][w].rgbtGreen) / 6); // find avg of surrounding pixels
                float LSmiddleBLUE = round((float)(temp[h][w].rgbtBlue + temp[h - 1][w].rgbtBlue + temp[h - 1][w + 1].rgbtBlue + temp[h][w +
                                                   1].rgbtBlue + temp[h + 1][w + 1].rgbtBlue + temp[h + 1][w].rgbtBlue) / 6); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(LSmiddleRED); // assign avg to img
                image[h][w].rgbtGreen = round(LSmiddleGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(LSmiddleBLUE); // assign avg to img
            }
            else if (h > 0 && h < height - 1 && w == width - 1) // right side middles
            {
                float RSmiddleRED = round((float)(temp[h][w].rgbtRed + temp[h - 1][w].rgbtRed + temp[h - 1][w - 1].rgbtRed + temp[h][w - 1].rgbtRed
                                                  + temp[h + 1][w - 1].rgbtRed + temp[h + 1][w].rgbtRed) / 6); // find avg of surrounding pixels
                float RSmiddleGREEN = round((float)(temp[h][w].rgbtGreen + temp[h - 1][w].rgbtGreen + temp[h - 1][w - 1].rgbtGreen + temp[h][w -
                                                    1].rgbtGreen + temp[h + 1][w - 1].rgbtGreen + temp[h + 1][w].rgbtGreen) / 6); // find avg of surrounding pixels
                float RSmiddleBLUE = round((float)(temp[h][w].rgbtBlue + temp[h - 1][w].rgbtBlue + temp[h - 1][w - 1].rgbtBlue + temp[h][w -
                                                   1].rgbtBlue + temp[h + 1][w - 1].rgbtBlue + temp[h + 1][w].rgbtBlue) / 6); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(RSmiddleRED); // assign avg to img
                image[h][w].rgbtGreen = round(RSmiddleGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(RSmiddleBLUE); // assign avg to img
            }
            else if (h == 0 && w > 0 && w < width - 1) // top middles
            {
                float TOPmiddleRED = round((float)(temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed + temp[h][w - 1].rgbtRed + temp[h + 1][w - 1].rgbtRed
                                                   + temp[h + 1][w].rgbtRed + temp[h + 1][w + 1].rgbtRed) / 6); // find avg of surrounding pixels
                float TOPmiddleGREEN = round((float)(temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen + temp[h][w - 1].rgbtGreen + temp[h + 1][w -
                                                     1].rgbtGreen + temp[h + 1][w].rgbtGreen + temp[h + 1][w + 1].rgbtGreen) / 6); // find avg of surrounding pixels
                float TOPmiddleBLUE = round((float)(temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue + temp[h][w - 1].rgbtBlue + temp[h + 1][w -
                                                    1].rgbtBlue + temp[h + 1][w].rgbtBlue + temp[h + 1][w + 1].rgbtBlue) / 6); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(TOPmiddleRED); // assign avg to img
                image[h][w].rgbtGreen = round(TOPmiddleGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(TOPmiddleBLUE); // assign avg to img
            }
            else if (h == height - 1 && w > 0 && w < width - 1) // bottom middles
            {
                float BTTMmiddleRED = round((float)(temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed + temp[h][w - 1].rgbtRed + temp[h - 1][w -
                                                    1].rgbtRed + temp[h - 1][w].rgbtRed + temp[h - 1][w + 1].rgbtRed) / 6); // find avg of surrounding pixels
                float BTTMmiddleGREEN = round((float)(temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen + temp[h][w - 1].rgbtGreen + temp[h - 1][w -
                                                      1].rgbtGreen + temp[h - 1][w].rgbtGreen + temp[h - 1][w + 1].rgbtGreen) / 6); // find avg of surrounding pixels
                float BTTMmiddleBLUE = round((float)(temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue + temp[h][w - 1].rgbtBlue + temp[h - 1][w -
                                                     1].rgbtBlue + temp[h - 1][w].rgbtBlue + temp[h - 1][w + 1].rgbtBlue) / 6); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(BTTMmiddleRED); // assign avg to img
                image[h][w].rgbtGreen = round(BTTMmiddleGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(BTTMmiddleBLUE); // assign avg to img
            }
            else // middles
            {
                float middlesRED = round((float)(temp[h][w].rgbtRed + temp[h][w + 1].rgbtRed + temp[h - 1][w + 1].rgbtRed + temp[h - 1][w].rgbtRed +
                                                 temp[h - 1][w - 1].rgbtRed + temp[h][w - 1].rgbtRed + temp[h + 1][w - 1].rgbtRed + temp[h + 1][w].rgbtRed + temp[h + 1][w +
                                                         1].rgbtRed) / 9); // find avg of surrounding pixels
                float middlesGREEN = round((float)(temp[h][w].rgbtGreen + temp[h][w + 1].rgbtGreen + temp[h - 1][w + 1].rgbtGreen + temp[h -
                                                   1][w].rgbtGreen + temp[h - 1][w - 1].rgbtGreen + temp[h][w - 1].rgbtGreen + temp[h + 1][w - 1].rgbtGreen + temp[h + 1][w].rgbtGreen
                                                   + temp[h + 1][w + 1].rgbtGreen) / 9); // find avg of surrounding pixels
                float middlesBLUE = round((float)(temp[h][w].rgbtBlue + temp[h][w + 1].rgbtBlue + temp[h - 1][w + 1].rgbtBlue + temp[h -
                                                  1][w].rgbtBlue + temp[h - 1][w - 1].rgbtBlue + temp[h][w - 1].rgbtBlue + temp[h + 1][w - 1].rgbtBlue + temp[h + 1][w].rgbtBlue +
                                                  temp[h + 1][w + 1].rgbtBlue) / 9); // find avg of surrounding pixels
                image[h][w].rgbtRed = round(middlesRED); // assign avg to img
                image[h][w].rgbtGreen = round(middlesGREEN); // assign avg to img
                image[h][w].rgbtBlue = round(middlesBLUE); // assign avg to img
            }
        }
    }
    return;
}


