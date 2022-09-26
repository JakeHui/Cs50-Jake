// You are eating out at a restaurant with a friend and want to split the bill evenly.
//You may want to anticipate the amount you’ll owe before the bill arrives with tax added.
//In this problem, you’ll complete a function to calculate the amount each of you owes based on
//the bill amount, the tax, and the tip.
// Ask the user for the bill amount, the tax rate, and the tip rate!
// Print the result as a bill.
#include <cs50.h>
#include <stdio.h>
#include <math.h>

double solve (double tax, double tip, double bill);

int main(void)
{
    double nofpeople;
    double tax;
    double tip;
    double bill;
    double personpay;
    double total;

// finding the number of people
    do
    {
        nofpeople = get_double("Number of people: ");
    }
    while (nofpeople < 1);

// finding the tax amount
    do
    {
        tax = get_double("Tax Precentage: ");
    }
    while (tax < 0);

// finding the tip precentage
    do
    {
        tip = get_double("Tip precentage of bill: ");
    }
    while (tip < 0);

// finding the amount of the bill
    do
    {
        bill = get_double("How much was the bill: ");
    }
    while (bill < 0);

    total = solve(bill, tip, tax);
    personpay = (total/nofpeople);

    // printing
    printf("Each person pays: %f", personpay);
    printf("\n");

    return 0;
}

double solve (double tax, double tip, double bill) {
    double total = 0;
    total = (bill)+(tip*bill/100)+(tax*bill/100);
    // calculating total cost
    //dividing by 100 makes it a precentage
    return total;
}

