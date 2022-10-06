#include <stdio.h>
#include <cs50.h>
/*
prompt user for pyramid height
loop spaces that decrease by 1
use a function that prints number of hastags per layer
add the two spaces
use a function to print hashtags as it will be inverted without spaces
*/

int stepcode(int count);
int main()
{
    int count;
    int num;
    do
    {
        num = get_int("Enter how many steps: ");
        //prompts user for the number of steps
    }
    while (num < 1 || num > 8);
    printf("\n");
    for (count = 0; count < num ; count++) //loop1
    {
        for (int j = num-1; j > count; j--)
        {
            printf(" "); // adds spaces for bakwards pyramid
        }
        stepcode(count);// adds hashtags at the end of the spaces
        printf("  "); // add space in between
        stepcode(count);// without spaces before pyramid isnt inverted so copy paste
        printf("\n");//new line after each row
    }
}

int stepcode(int count)
{
    for (int step = -1; step < count; step++)
    {
        // loops for number of #s per step
        // adds hashtag at the end of the spaces
        printf("#");
    }
    return 0;
}
