#include <cs50.h>
#include <stdio.h>
#include <math.h>
void convert(int type, int length, int num);
int arraylength(int yes, int no);

int main()
{
    int type;
    int length;
    int num;
    int exit = 0;
    do{
        do { // prompt user for conversion type
            printf("To exit press 0\n");
            type = get_int ("Type a base\n");
        } while (type < 0);

        do { // prompt user for number type
            num = get_int ("Enter Decimal Number: \n");
        } while (num < 0);
        if (num == 0){
            break;
        }

        length = arraylength(num, type);
        convert(type, length, num);
    } while (exit == 0);
    printf("END");
    printf("\n");
}

int arraylength(int yes, int no) {
    int length = 0;
    int num1 = yes;
    do {
        num1 = num1 / no;
        length++; //divides by ten to get rid of one digit do that multiple times to get the length
    } while (num1 > 0);
    return length;
}


void convert(int type, int length, int num)
{
    printf("Number: ");
    int array[length];
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};


    for (int k = 0; k < length; k++)
    {
        array[k] = num % type;
        num = num/type;
    }

    if (type == 16){
            for (int i = length-1; i >= 0; i--){
                printf("%c", hex[array[i]]);
            }

    } else {
        for (int i = length-1; i >= 0; i--){
            printf("%i", array[i]);
        }
    }
    printf("\n");
}

