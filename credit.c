// Jake Hui
//psuedo code
// prompt user for card number
//check if card number is valid
//check how many digits there are on the card
//determine the card type by the length and the first few numbers
//print answer

#include <cs50.h>
#include <stdio.h>
int cardlength1 = 0;
bool checksum(long card);
int card_company(int cardlength2, long card);
int cardlength (long card);
int main(void)
{
    int cardlength2 = 0;
    long card;

    do{
        card = get_long ("Enter Credit Card Number: ");
    } while (card < 0);
    // prompt user for card number
    long cardnum = card;
    checksum(card); // checks if card number is vaid
    if (checksum(card)) { // if the card number is valid
        cardlength(card);
if (cardlength1 == 13){ //check for visa
    if ((cardnum/1000000000000) == 4){
        printf("VISA");
    } else{
        printf("INVALID");
    }
}

if (cardlength1 == 15){ //check for american express
   if (cardnum/10000000000000 == 34)  {
        printf("AMEX");
    } else if ((cardnum / 10000000000000 == 37)) {
        printf("AMEX");
    } else{
    printf("INVALID");
    }
}

if (cardlength1 == 16){//check for visa and mastercard
    if ((cardnum / 100000000000000 >= 51) && (cardnum / 100000000000000 <= 55)) {
        printf("MASTERCARD");
    } else if (cardnum/1000000000000000 == 4) {
        printf("VISA");
    } else {
        printf("INVALID");
    }
    }

    } else {
        printf("INVALID");
    }
    printf("\n");
    }






int cardlength (long card) {
    do {
        card = card / 10;
        cardlength1++; //divides by ten to get rid of one digit do that multiple times to get the length
    } while (card > 0);
    return cardlength1;
}


bool checksum(long card){
    int sum1 = 0;
    int sum2 = 0;
    long card2 = card;
 while (card2 > 0)
 {
    int num = (card2 % 10);      //value of each digit
    sum1 = sum1 + (card2 % 10);
    card2 = card2 / 10;
    num = (card2 % 10) * 2;  //find the value of every other digit times 2
    if (num < 10)
    {
        sum2 = sum2 + num;
        } else
        {
            sum2 = sum2 + (num - 10) + 1; //if number has 2 digits, add the 2 digits to the sum
            }
            card2 = card2 / 10;
            }
if ((sum1 + sum2) % 10 == 0) {
    return true;
    } else {
        printf("INVALID");
        return false;
        }
}
