//malloc

#include <stdio.h>
#include <stdlib.h>

int main()
{

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;

    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
        printf("\n");
    }
    free(ptr);

    int * ptr2;
    ptr2 = (int*)calloc(n, sizeof(int));
    for (i = 0; i < n; ++i)
    {
        ptr2[i] = i + 1;
    }

    // Print the elements of the array
    printf("The elements of the second array are: ");
    for (i = 0; i < n; ++i)
    {
        printf("%d, ", ptr2[i]);
    }
    printf("\n");


    ptr2 = realloc(ptr2, (n+90) *sizeof(int));
    return 0;
}

//then use calloc()

//ptr = (int*)calloc(n, sizeof(int));

// free

 // Dynamically re-allocate memory using realloc()
 //ptr = realloc(ptr, n * sizeof(int));
