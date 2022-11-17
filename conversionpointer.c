#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
char bin(long num, int base);

int main(void){
    long bi = 0; // make variable bi
    do{
        bi = get_long ("Enter Number: ");
    } while (bi <= 0); // repeat until >=0

    int base = 0; // make variable base
    do{
        base = get_int ("Enter Base: ");
    } while (base <= 0); // repeat until >=0

    charans = bin(bi, base);

    for(int i = 31; i>=0; i--){ // print out the values
        printf("%c",ans[i]);
    }
    printf("\n");
}

char bin(long num, int base){
    char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; // array for hex
    chararray = malloc(sizeof(int) * 32);
    int n = 0; // count variable
    while(num>0){ // when the number is no longer divisible, stop
        int rem = num%base;
        array[n] = hex[rem];
        num = num/base; // divide the number by the base
        n++; // move to next value
    }
    return array; //return array

}
