//Jake Hui
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    int startsize;
    do
    {
        startsize = get_int("Start size:: ");
    }
    while (startsize < 9);

    int year = 0;
    int n = startsize;
    int calculator = 0;

    // TODO: Prompt for end size
    int endsize;
    do
    {
        endsize = get_int("End size:: ");
    }
    while (endsize < startsize);



    // if else returns 0 if end and start size is 0
    if (startsize == endsize)
    {
        printf("Years: 0");
    }
    else
    {
        do
        {
            //calculation for
            n = round(n + (n / 3) - (n / 4));
            year++;
            //adds one to year every year that it takes
        }
        while
        (n < endsize);
    }
    //repeats the cycle until the llamas are more than the ending size
    //it rounds up one and doesnt give exact because it may not equal the end size
    printf("Years: %i", year);
    printf("\n");
    //print answer
}
