#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main (int argc, char *argv[])
{
    //proper usage
    if (argc != 3)
    {
        printf("Usage: whodunit infile outfile \n");
        return 1;
    }

    //name of the files
    char* infile = argv[1];
    char* outfile = argv[2];

    //open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    //open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not open %s.\n", outfile);
        return 3;
    }

    //read input BITMAPINFOHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    //make sure that infile is a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
    bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 4;
    }

    //write output BITMAPINFOHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    //pading for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //iterate over scanlines in the file
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE triple;

            //read RGBTRIPLE from the file
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //shift zero bits to their maximum value
            triple.rgbtGreen -= 0x1;
            triple.rgbtBlue -= 0x1;

            //write to the file
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
        //skip over padding
        fseek(inptr, padding, SEEK_CUR);

        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }
    fclose(inptr);
    fclose(outptr);
    return 0;

}