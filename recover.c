#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
Psuedocode:
Open memory card
repeat until end {
    Read first 512 bytes into buffer
    if start of new jpg
        if fist jpg

        else

        else
            if already found jpg
}
*/
int main(int argc, char *argv[])
{
    if (argc != 2) //check commandline argument
    {
        printf("Format: ./recover card.raw");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("File opening failed.");
        return 1;
    }

    int num = 0; //counter to make the names of the jpg files starting from 0
    uint8_t buffer[512]; //unsigned char because header of jpg is hex
    FILE *output = NULL;
    char filename[8] = {0};

    while (fread(buffer, sizeof(uint8_t), 512, f)) //reads card.raw in chunks of 512
    {

        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            // if at the start of a file
            if (output != NULL)
            {
                fclose(output);//start with closing the file
            }
            sprintf(filename, "%03i.jpg", num); //prints the number of the jpg to filename
            num++; // add to counter for file no.
            output = fopen(filename, "w"); //open file
        }

        if (output != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, output); //if output = null write data
        }
    }

    fclose(output);//at the end close all files
    fclose(f);
    return 0;
}
