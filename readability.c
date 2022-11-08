#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int noofwords(string word);
int avgletters(string word);
int avgsentences(string word);
int main(void)
{
    string word = get_string ("Text: ");
    double W = noofwords(word);
    double amtletters = avgletters(word);
    double amtsentences = avgsentences(word);
    double L = amtletters*(100/W);
    double S = amtsentences *(100/W);
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
    printf("Before Grade 1\n");
    } else if (index > 16)
    {
    printf("Grade 16+\n");
    } else
    {
    printf("Grade %i\n", index);
    }
}

int noofwords(string word)
{
    int words = 0;
    int length = strlen(word); // length of input
    for (int character0 = 0; character0 < length; character0++) //repeats for each letter
    {
        if (word[character0] == ' ')
        {
            words++;
        }
    }
    words++;
    return words;
}

int avgletters(string word)
{
    int letters = 0;
    int length = strlen(word); // length of input
    for (int character = 0; character < length; character++) //repeats for each letter
    {
        char letter = word[character];
        if (isalpha(letter))
        {
            letters++;
        }
    }
    return letters;
}



int avgsentences(string word)
{
    int sentences = 0;
    int length1 = strlen(word); // length of input
    for (int character1 = 0; character1 < length1; character1++) //repeats for each letter
    {
        if (word[character1]  == '.')
        {
            sentences++;
        } else if (word[character1]  == '?')
        {
            sentences++;
        } else if (word[character1]  == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
