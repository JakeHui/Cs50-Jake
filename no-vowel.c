// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string vowelswitch(string input);    //function to switch vowels to numbers

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please give 1 argument\n"); //end program if no word is given
        return 1;
    }

    string input = argv[1];
    string new = vowelswitch(input);

    printf("%s\n", input); //print final word
}

string vowelswitch(string input) //function for switching vowels to numbers
{
    int length = strlen(input);    // length of input

    for (int elem = 0; elem < length; elem++) //repeats for each letter
    {
        if (input[elem] == 'a') //replace a with 6
        {
            input[elem] = '6';
        }
        if (input[elem] == 'e') //replace e with 3
        {
            input[elem] = '3';
        }
        if (input[elem] == 'i') //replace i with 1
        {
            input[elem] = '1';
        }
        if (input[elem] == 'o')// replace o with 0
        {
            input[elem] = '0';
        }
    }
    return input;
}
