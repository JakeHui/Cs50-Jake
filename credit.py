import cs50
import cs50 as cs
import sys

def cardlength (card):
    cardlength1 = len(str(card))
    return cardlength1

def checksum(card):
    odd = 0
    even = 0
    if len(str(card)) % 2 == 0:
        for i in range(len(str(card))):
            num = int(str(card)[i])
            if i % 2 == 0:
                multiple = num * 2
                if multiple >= 10:
                    even += multiple // 10
                    even += multiple % 10
                else:
                    even += multiple
            else:
                odd += num
    else:
        for i in range(len(str(card))):
            num = int(str(card)[i])
            if i % 2 != 0:
                multiple = num * 2
                if multiple >= 10:
                    even += multiple // 10
                    even += multiple % 10
                else:
                    even += multiple
            else:
                odd += num
    sum = (even + odd) % 10
    return sum



flag = True
cardlength2 = 0
while flag:
    card = cs.get_int("Enter Credit Card Number: ")
    if (len(str(card)) == 13 or len(str(card)) == 15 or len(str(card)) == 16):
        flag = False #prompt user for card number
    else:
        print("INVALID")
        sys.exit(0)

if (checksum(card) == 0) : #if the card number is valid
    digi_1 = int(str(card)[0])
    digi_2 = int(str(card)[1])
    digi_3 = int(str(card)[2])
    if digi_1 == 3 and (digi_2 == 4 or digi_2 == 7):
        print("AMEX")
    elif digi_1 == 4:
        print("VISA")
    elif digi_1 == 5 and (1 <= digi_2 <= 5):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
    sys.exit(0)

