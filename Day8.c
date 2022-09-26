// 1)Write a  Program to calculate the sum of first n natural numbers given by the user
//  (Example: n=5    sum=1+2+3+4+5)  Pseudocode first
// 2) Can you write the same with a different kind of loop?
// 3) if you want to make sure the n is positive and no greater than a 2 bytes number what would you do?
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    //declare integer n that represents inputted number
    do
    {
        n = get_int("Natrual Number: ");
        // prompt user for a natrual number
    }
    while (n < 2);
    //natrual number must be more than one

    int number = 0;
    //declare number as 0
    for (int i = 1; i <= n; i++)
    {
        number = number + i;
        // repeats 1 added with itself, then adding that
        // number with itself until that number equals the natrual number
    }

    if (number > 131071)
    {
        printf("Exceeds 2 byte integer limit \n");
        //if the number is larger than 2 byte integer limit or 2^16-1 then the number is too large and output too big
    }
    else
    {
        printf("The number is %i\n", number);
        //if its not too large output number
    }
}
