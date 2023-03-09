import cs50
import os
import cs50 as cs
import sys
import random
import time
from PyDictionary import PyDictionary
from word2word import Word2word
import datetime

dictionary=PyDictionary()

hardlist = ["ambidextrous", "benevolent", "catastrophic", "deleterious", "effervescent", "fastidious", "gregarious", "heterogeneous", "inquisitive", "judicious", "kaleidoscopic", "luminescent", "magnanimous", "nefarious", "omnipotent", "perfunctory", "quixotic", "resilient", "sagacious", "tenacious", "ubiquitous", "voracious", "wanton", "xenophobic", "yielding", "zealous"]
medlist = ["abacus", "banana", "cherry", "dandelion", "elephant", "giraffe", "hippopotamus", "jellyfish", "kiwi", "lemon", "marmalade", "nebula", "octopus", "penguin", "quicksilver", "rhubarb", "strawberry", "tangerine", "umbrella", "violin", "watermelon", "xylophone", "yellow", "zebra"]
ezlist = ["book", "cat", "dog", "egg", "fish", "goat", "hat", "ice", "jacket", "kite", "lamp", "moon", "nest", "orange", "pen", "queen", "rain", "socks", "tree", "umbrella", "vase", "water", "xylophone", "yarn", "zebra"]

def printmenu(): # print menu
    print("               Word Game               ")
    print("             Instructions:            ")
    print("    In this game you will guess words ")
    print(" Try to guess the word 1 letter at a time")
    print("       Pick your difficulty        ")
    print("     1 Easy                        ")
    print("     2 Medium                      ")
    print("     3 Hard                        ")
    print("     4 Scoreboard                  ")
    print("     Press any other number to exit")
    print("-----------------------------------")
    getwordanddiff()

def getwordanddiff():
    global length
    global turns
    global multiplier
    global word
    rightdiff = True
    diff = 0
    while (rightdiff): #if difficulty is not a number entered
        diff = cs.get_int ("Enter Difficulty: ")
        if (diff == 1, 2, 3):
            rightdiff = False
        else:
            print("Invalid Difficulty")
            rightdiff = True

    if diff == 1: #ez diff
        word = random.choice(ezlist)
        multiplier = 1
        turns = 20
    elif diff == 2: #medium diff
        word = random.choice(medlist)
        multiplier = 2.5
        turns = 15
    elif diff == 3: #hard diff
        word = random.choice(hardlist)
        multiplier = 4
        turns = 10
    elif diff == 4: #scoreboard
        os.system('clear')
        scoreboard()
    else:
        sys.exit(0) #exit program if else
    length = len(word)

def langword(word):#translate to different languages :)
    #pip install word2word
    try:
        print("Spanish", Word2word("en", "es")(word))
        print("French", Word2word("en", "fr")(word))
        print("Finnish", Word2word("en", "fi")(word))
        print("Japanese", Word2word("en", "ja")(word))
        print("Korean", Word2word("en", "ko")(word))
        print("Chinese", Word2word("en", "zh_tw")(word))
    except:
        print(" ")

def scoreboard():
    scores = open("scores.txt", 'a') #open file
    scores.close
    scores = open("scores.txt", 'r')
    lines = scores.readlines() #put scores into lines array
    lines.sort(key=lambda line: int(line.split()[0]), reverse = True)#sort array by score
    for i in range (len(lines)): #print all scores
        print (lines[i])
    input("Enter to Continue")
    os.system('clear')
    printmenu()


def input_scoreboard():
    date = datetime.datetime.now()
    name = input ("Name: ") #get user name
    scoreline = str(score)+"\t"+name+"\t"+date.strftime('%m/%d/%y'+'\n')#format score
    scores = open("scores.txt", 'a')
    scores.write(scoreline)#input score
    scores.close
    scores = open("scores.txt", 'r')
    print (scoreline) #print score for user
    input ("Enter to Continue")
    os.system('clear')

    # scoreline = str(score)+ name + date

#Main Function
loss = False
again = True
guess = ' ' #empty list for guess
used_letters = [' '] #empty list for used letters
while (again == True):#loop if they want to go again
    os.system('clear')
    printmenu()

    # counter = len(word)
    ukword = ['_']*length

    win = False
    while win == False: #loop for guessing letters and seeing if they won
        flag = True #get user input
        print(ukword)
        while flag:
            guess = cs.get_string("Enter a Letter: ")
            if guess.isalpha() and len(guess) == 1: #has to be one letter
                flag = False
            else:
                print("Print only 1 letter please")
        flag1 = False
        for b in range(length): #for every letter check if it is the same, if it is then change the answer array
            if guess == word[b]:
                ukword[b] = guess
                flag1 = True
        os.system('clear')
        if flag1:
            if guess in used_letters: # if letter is repeated tell them to try again
                print("Letter already used, try again")
            else:
                print(("Correct!\nTurns = "), turns)
        else:
            turns = turns - 1 #subtract turns if wrong
            print (("Wrong!\nTurns = "), turns)
        used_letters.append(guess)

        loss = False
        if turns == 0:
            print("You Lose!")
            print("Word was:", word)
            langword(word) #translation
            input("Enter to continue")
            os.system('clear')
            win = True #only to exit loop
            loss = True

        counter = 0
        for i in range(length): #check if no more underscores
            if ukword [i] == "_":
                counter = counter + 1
        if counter == 0:
            win = True


    if loss:
        your_mom = 1
    else:
        print("You Win!")
        score = 100*multiplier*turns #caluclation for score
        langword(word)
        input("Return to Continue")
        response = cs.get_int("Would you like to input your score into the scoreboard?\n2 to continue\n1 to input score\n")
        if response == 1: #scoreboard
            os.system('clear')
            print ("Your Score was: ", score)
            input_scoreboard() #if win put score in scoreboard
        else:
            os.system('clear')
