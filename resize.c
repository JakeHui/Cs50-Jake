#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize, scale factor, infile, outfile\n");
        return 1;
    }

    //Get the scale factor
    float factor = atof(argv[1]);

    // Remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf; //Creates a buffer
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr); //Address of bf, read size of BITMAPFILEHEADER, read 1, input file

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi; //Creates a buffer
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr); //Address of bi, read size of BITMAPINFOHEADER, read 1, input file

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //Store dimensions of the original image
    int originalHeight = bi.biHeight; //Height of the original image
    int originalWidth = bi.biWidth; //Width of the original image
    int originalPadding = (4 - (originalWidth * sizeof(RGBTRIPLE)) % 4) % 4; //Padding of the original image

    //New dimensions and padding for the new image
    int newHeight = floor(originalHeight * factor); //Height multiply by the scale factor to get new height

    bi.biHeight = newHeight;
    int newWidth = floor(originalWidth * factor); //Width multiply by the scale factor to get new width
    bi.biWidth = newWidth;
    int padding = (4 - (newWidth * sizeof(RGBTRIPLE)) % 4) % 4; //Padding for the new image

    //Changing the bi.biSizeImage and bf.bfSize
    bi.biSizeImage = abs(bi.biHeight) * ((sizeof(RGBTRIPLE) * bi.biWidth) + padding);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE arr[sizeof(RGBTRIPLE) * newWidth];

    // Iterate over infile's scanlines
    for (int i = 0, biHeight = abs(originalHeight); i < biHeight; i++)
    {
        int counter = 0;
        // Iterate over pixels in scanline
        for (int j = 0; j < originalWidth; j++)
        {
            // Temporary storage
            RGBTRIPLE triple;

            // Read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int a = 0; a < factor; a++)
            {
                // Write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                arr[counter] = triple;
                counter++;
            }
        }

        //write padding
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }

        // Skip over padding, if any
        fseek(inptr, originalPadding, SEEK_CUR);

        for (int b = 0; b < factor - 1; b++)
        {
            fwrite(arr, sizeof(RGBTRIPLE), newWidth, outptr);
            // Then add it back (to demonstrate how)
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);
    return 0;
}
