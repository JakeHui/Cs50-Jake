// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main()
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int capitalletter = 0;
    int lowercaseletter = 0;
    int number = 0;
    int symbol = 0;

    for (int length = strlen(password) ; length >= 0; length--) //repeats for each letter on the string
    {
        char letter = password[length];

        if (isupper(letter))
        {
            capitalletter++;
        } else if (islower(letter))
        {
            lowercaseletter++;
        } else if (isdigit(letter))
        {
            number++;
        } else if (ispunct(letter))
        {
            symbol++;
        }
    }

    if ((capitalletter > 0)&&(lowercaseletter > 0)&&(number > 0)&&(symbol > 0))
    {
        return true;
    } else
    {
        return false;
    }
}
