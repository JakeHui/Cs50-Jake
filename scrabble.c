// prompt user 1 and 2 for thier letters
// create array for points
/* score function:
covert all uppercase to lowercase using ascii no. - 32
insert word into a string while getting rid of punctuation
convert string into individual numbers utilizing the number of letters
use the numbers in the array of points
calculate and print points
*/
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Print the winner
    if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie\n");
    }
    else
    {
        printf("Player 1 Wins!\n");
    }

}

int compute_score(string word)
{
    int totalpoints = 0;
    for (int length = strlen(word) ; length >= 0; length--) //repeats for each letter on the string
    {
        char letter = word[length]; // finds the individual letter on the array
        char letter1 = toupper(letter); // makes letter uppercase
        if (isalpha(letter1))
        {
            totalpoints = totalpoints + POINTS[letter1 - 65]; // calculating total points
        }
    }
    // printf("Total Points for Player = %i\n", totalpoints);
    // only to confirm points cs50 no like
    return totalpoints;
}
