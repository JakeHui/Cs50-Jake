#include <stdio.h>

/* function declaration */
int max(int num1, int num2);

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

int main (void) {

   /* local variable definition */
   int a = 200;
   int b = 200;
   int ret;

   /* calling a function to get max value */
   ret = max(a, b);

   if (ret == 0) 
   printf( "Values are the same \n");
   else
   printf( "Max value is : %d\n", ret );

   return 0;
}
