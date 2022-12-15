/*
Jake Hui
Tideman
Psudeocode for functions
Vote:
Cycle through each candidate
Compare user input with candidate name string
If match update candidate's array number
If doesnt match any return invalid

Record_prefrences:
Using each voter's prefrences compare each candidate to another candidate
create a double loop to compare each candidate with the other candidate
using the loop cycle through a 2d array
compare the candidates in thier respective spots with how many people prefer this candidate over another

Add_pairs:
create a double loop checking each element in double array
Find the candidate who has the larger number and make them the winner
the opposite for the loser
determine the strength of the candidate by subtracting with how many times the other candidate is prefered over the current one

Sort_pairs:
Use sorting function to order the pairs in terms of strength
use a double loop to check for each candidate pair
(USE BUBBLE SORT)

Lock_pairs:
create function to check if pair will make loop
if end of pair results in begining of the cycle, ignore the pair
if the pair does not create a cycle. set the lock status to true

Print_winner:
use a double loop to compare opposite candidates
if all the opposite pairings are false, print the candidate's name as the winner

*/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>


// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i])== 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i  = 0; i < candidate_count; i++)
    {
        for (int j = i+1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + i; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            } else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void) //Using bubble sort
{
    for (int i = pair_count - 1; i >= 0 ; i--) //Starts at the end of the array, cycles through all pairs
    {
        for (int j = 0; j <= i - 1; j++) //Starts at the beginning of the array, cycles through all pairs
        {
            if ((preferences[pairs[j].winner][pairs[j].loser]) < (preferences[pairs[j + 1].winner][pairs[j + 1].loser])) //If one is smaller than the other
            {
                pair temp = pairs[j]; //Set pairtemp to pairs[j]
                pairs[j] = pairs[j + 1]; //Set pairs[j] to pairs[j + 1]
                pairs[j + 1] = temp; //Set pairs[j + 1] to pairs[j]
            }
        }
    }
    return; //Return nothing (void function)
}

// Test for cycle by checking arrow coming into each candidate
bool cycle(int end, int cycle_start)
{
    if (end == cycle_start)
    {
        return true;  // Return true if there is a cycle created
    }
    // Loop through candidates (Recursive case)
    for (int i = 0; i < candidate_count; i++) //Cycle through the candidates
    {
        if (locked[end][i]) //If the pair of candidate i and the end candidate
        {
            if (cycle(i, cycle_start)) //If the pair of candidate i and the end candidate form a cycle
            {
                return true; //Return true
            }
        }
    }
    return false; //Return false if the pair does not create a cycle
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i ++)
    {
        if (!cycle(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int false_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                false_count++;
                if (false_count == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
    return;
}
