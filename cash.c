#include <cs50.h>
#include <stdio.h>
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    printf("Quarters: %i\n", quarters);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    printf("Dimes: %i\n", dimes);

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    printf("Nickels: %i\n", nickels);


    // Calculate the number of pennies to give the customer
    int pennies = cents;
    printf("Pennies: %i\n", pennies);

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Enter amount owed: ");
    }
    while (cents < 1);
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    if (cents >= 25)
    {
        do
        {
            cents = cents - 25;
            quarters++;
        }
        while (cents >= 25);
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    if (cents >= 10)
    {
        do
        {
            cents = cents - 10;
            dimes++;
        }
        while (cents >= 10);
    }
    return dimes;
}


int calculate_nickels(int cents)
{
    int nickels = 0;
    if (cents >= 5)
    {
        do
        {
            cents = cents - 5;
            nickels++;
        }
        while (cents >= 5);
    }
    return nickels;
}
