// You are eating out at a restaurant with a friend and want to split the bill evenly.
//You may want to anticipate the amount you’ll owe before the bill arrives with tax added.
//In this problem, you’ll complete a function to calculate the amount each of you owes based on
//the bill amount, the tax, and the tip.
// Ask the user for the bill amount, the tax rate, and the tip rate!
// Print the result as a bill.
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int nofpeople;
    int tax;
    int tip;
    int bill;
    int totalpay;
    int personpay;

// finding the number of people
    do
    {
        nofpeople = get_int("Number of people: ");
    }
    while (nofpeople < 1);

// finding the tax amount
    do
    {
        tax = get_int("Tax Precentage: ");
    }
    while (tax < 0);

// finding the tip precentage
    do
    {
        tip = get_int("Tip precentage of bill: ");
    }
    while (tip < 0);

// finding the amount of the bill
    do
    {
        bill = get_int("How much was the bill: ");
    }
    while (bill < 0);

    // calculate how much each person pays
    totalpay = (bill)+(tip*bill/100)+(tax*bill/100);
    //dividing by 100 makes it a precentage
    personpay = (totalpay/nofpeople);
    printf("Each person pays: %i", personpay);
    printf("\n");
}
