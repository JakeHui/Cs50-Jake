import cs50
from cs50 import get_float
import math as mm


flag = True
while flag:
    cents = get_float("Enter amount owed: ")
    if (cents >= 0):
        cents = cents*100
        flag = False


def calculate_quarters(cents):
    quarters = mm.floor(cents/25)
    return quarters


def calculate_dimes(cents):
    dimes = mm.floor(cents/10)
    return dimes


def calculate_nickels(cents):
    nickels = mm.floor(cents/5)
    return nickels


def calculate_pennies(cents):
    pennies = cents
    return pennies

#Calculate the number of quarters to give the customer
quarters = calculate_quarters(cents)
cents = cents - quarters * 25

#Calculate the number of dimes to give the customer
dimes = calculate_dimes(cents)
cents = cents - dimes * 10

#Calculate the number of nickels to give the customer
nickels = calculate_nickels(cents)
cents = cents - nickels * 5

#Calculate the number of pennies to give the customer
pennies = calculate_pennies(cents)
cents = cents - pennies * 1

#Sum coins
coins = quarters + dimes + nickels + pennies

#Print total number of coins to give the customer
print(coins)
