#include <stdio.h>
#include <cs50.h>

/* function declaration */
int max(int num1, int num2);

int main () {

   /* local variable definition */
   int num1 = get_int ("Number 1: ");
   int num2 = get_int ("Number 2: ");
   int ret;

   /* calling a function to get max value */
   ret = max(num1,num2);

   if (ret == 0 && num1 == 0 && num2 == 0)
   printf( "Values are the same \n");
   else
   printf( "Max value is : %d\n", ret );

   return 0;
}

/* function returning the max between two numbers */
int max(int num1, int num2) {

   /* local variable declaration */
   int result;

   if (num1 > num2)
      result = num1;
   if (num2 > num1)
      result = num2;
    else
        result = 0;

   return result;
}
