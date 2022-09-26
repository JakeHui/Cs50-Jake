// You are eating out at a restaurant with a friend and want to split the bill evenly.
//You may want to anticipate the amount you’ll owe before the bill arrives with tax added.
//In this problem, you’ll complete a function to calculate the amount each of you owes based on
//the bill amount, the tax, and the tip.
// Ask the user for the bill amount, the tax rate, and the tip rate!
// Print the result as a bill.

// ask for bill
// ask for tax
// ask for tip
// ask for no of people
// add values together in a function
// print values

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
    printf("\n\n\n");
    printf("Bill: %f \n", bill);
    printf("Tip: %f \n", tip);
    printf("Tax: %f \n", tax);
    printf("Total: %f \n", total);
    printf("Each person pays: %f \n", personpay);
    printf("\n\n\n");

    return 0;
}

double solve (double tax, double tip, double bill) {
    double total = 0;
    total = (bill)+(tip*bill/100)+(tax*bill/100);
    // calculating total cost
    //dividing by 100 makes it a precentage
    return total;
}

