#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkKey();
void substitute();
void alphaarrayvalue(char pos, string key);

int main(int argc, string argv[])
{
    if (argc == 2) // checks if has only allowed number of arguments
    {
        if (strlen(argv[1]) == 26) // check string length
        {
            for (int i = 0; i < strlen(argv[1]) ; i++) // checking each element of string
            {
                if (!isalpha(argv[1][i])) // if contain non-alphabet
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                    // end program if non alphabet
                }
                for (int j = i + 1 ; j < strlen(argv[1]) ; j++) // checking to the next element of arg[i]
                {
                    if (toupper(argv[1][j]) == toupper(argv[1][i])) // checking if repeated element
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }
            substitute(argv[1]);
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
            // if false end program
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
        // if false end program
    }
    return 0;
}

void substitute(string key)
{
    string p = get_string("plaintext: "); // get text

    printf("ciphertext: ");

    for (int i = 0; i < strlen(p); i++) // iterating through each letter in text
    {
        if (isalpha(p[i])) // checking p[i] if is alphabet
        {
            char x = p[i];
            if (islower(p[i]))
            {
                alphaarrayvalue(tolower(x), key); //  p[i] in lowercase
            }
            else
            {
                alphaarrayvalue(toupper(x), key); //  p[i] in uppercase
            }
        }
        else
        {
            printf("%c", p[i]); // print as it is
        }
    }
    printf("\n");
}
void alphaarrayvalue(char pos, string key)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // alphabet array

    for (int i = 0; i < strlen(alpha); i++) // iterating through each element in array
    {
        if (islower(pos)) // for lowercase
        {
            if (pos == tolower(alpha[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else // for uppercaese
        {
            if (pos == toupper(alpha[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}
