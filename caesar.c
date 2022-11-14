#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void cipher_text(string plaintext, int key);

int main(int argc, string argv[])
{
    // check how many arguments are given
    if (argc == 2)
    {
        //check if argv[1] is a number
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
                // if false end program
            }
        }

        //convert argv[1] to a int
        int key = atoi(argv[1]);

        printf("Success\n" "%d\n", key);

        string plaintext = get_string("Plaintext: "); // get text

        printf("ciphertext: ");

        cipher_text(plaintext, key); //run function
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
        // if number of arguments not met end function and tell user that it doesnt work
    }

    printf("\n");
}

void cipher_text(string plaintext, int key)
{
    for (int i = 0; i < strlen(plaintext); i++) // iterate through each element of the text
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');//cipher
        }

        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A'); //cipher
        }

        else if (isalpha(plaintext[i]) == false)
        {
            printf("%c", plaintext[i]);
        }

    }
}
