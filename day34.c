#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
    int* ptr;
    int n, i;

    printf("Enter number of elements:"); // get no of elements
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
    ptr = (int*)malloc(n * sizeof(int)); //llocate memory using malloc()

    if (ptr == NULL) 
    {
        printf("Memory not allocated.\n");
        exit(0); // Exit program if memory allocation failed
    }
    else {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
        printf("\n\n");
    }

    int* ptrr;
    int k;

    int j = get_int("Enter number of elements: ");
    printf("Entered number of elements: %d\n", j); // Printing j for user to confirm
    // Calloc to initialize the desired number of elements in the size of int
    ptrr = (int*)calloc(j, sizeof(int));

    // Check if the memory has been successfully allocated by memory because of multiple factors
    if (ptrr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0); // Exit program if memory allocation failed
    }
        else // If not null, then memory has been successfully allocated
    {
        printf("Memory successfully allocated using calloc.\n");
        for (k = 0; k < j; ++k) // To put values into the memory with array, pointer and for loop. k<j ensures stops before last element is reached
        {
            ptrr[k] = k + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (k = 0; k < j; ++k) {
            printf("%d, ", ptrr[k]);
        }

        printf("\n\n");
    }

    free(ptr); // Freeing memory

    int z = get_int("Pick a new size for ptrr: ");

    ptrr = realloc(ptrr, z * sizeof(int)); //re-allocate ptrr with realloc() to size of new input
    if (ptrr == NULL) // If failed to allocate, pointer would be null
    {
        printf("Memory not allocated.\n");
        exit(0); // Exit program if memory allocation failed
    }
    else // If not null, then memory has been successfully allocated
    {
        printf("Memory successfully re-allocated using realloc.\n");

        for (int m = 0; m < z; ++m) // To put values into the memory with array, pointer and for loop. k<j ensures stops before last element is reached
        {
            ptrr[m] = m + 1;
        }

        printf("The elements of the array are: ");   //Print
        for (int m = 0; m < z; ++m) 
            printf("%d, ", ptrr[m]);
        }
        printf("\n\n");
    }
    return 0; // Free the memory
  }
