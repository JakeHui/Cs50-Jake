import cs50
from cs50 import get_int

flag = True
while flag:
    steps = get_int("amount of steps: \n")  #user input for amount of steps
    if steps > 0 and steps < 9:
        flag = False

for line in range(0,steps):
        print(" "*(steps - line - 1), end = "")
        print("#"*(line + 1), end = "  ")
        print("#"*(line + 1))
