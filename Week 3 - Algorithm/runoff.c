#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;
int topPrefCandidate = 0; //retrieves the first pref initially and then increments as people start getting eliminated

//Helper methods written by Neela
int findTheCandidate(string name);
void retrieveAndAddItsNextPrefCandidate(int indexOfEliminatedCandidate);

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

/**
 * Specification:
 * The function takes arguments voter, rank, and name.
 * If name is a match for the name of a valid candidate,
 * then you should update the global preferences array to indicate that
 * the voter voter has that candidate as their rank preference (where 0 is the first preference, 1 is the second preference, etc.).
 * If the preference is successfully recorded, the function should
 * return true; the function should return false otherwise (if, for instance, name is not the name of one of the candidates).
 * You may assume that no two candidates will have the same name.
**/
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //Check if it is a valid candidate name
    int index = findTheCandidate(name);

    if (index == -1)
    {
        return false;
    }

    //if valid, populate the preference array
    //aka the index of the preferences[i][j] stores the index of the candidate who is the jth ranked preference for the ith voter.
    preferences[voter][rank] = index;
    return true;
}

/**
 * The function should update the number of votes each candidate has at this stage in the runoff.
 * Recall that at each stage in the runoff, every voter effectively votes for their top-preferred
 * candidate who has not already been eliminated.
 * */
// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //loop through each voter
    for (int i = 0; i < voter_count; i++)
    {
        int firstPrefCandIndex = preferences[i][topPrefCandidate]; //first preferenced candidate's index

        if (!candidates[firstPrefCandIndex].eliminated)
        {
            candidates[firstPrefCandIndex].votes++; //if the candidate is not already eliminated, add his vote
        }
        else
        {
            retrieveAndAddItsNextPrefCandidate(firstPrefCandIndex);
        }
    }
}

/**
 *If any candidate has more than half of the vote, their name should be printed to stdout and the function should return true.
 * If nobody has won the election yet, the function should return false.
 * **/
// Print the winner of the election, if there is one
bool print_winner(void)
{
    float fiftyPercentOfVotesNeeded = voter_count / 2.0;

    //loop through each candidate and check their vote
    for (int i = 0; i < candidate_count; i ++)
    {
        if (candidates[i].votes > fiftyPercentOfVotesNeeded && !candidates[i].eliminated)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

/**
 * The function should return the minimum vote total for any candidate who is still in the election.
 * */
// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count + 1; //upperBound of voters since vote needs to be below this to be valid as well as to be min

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

/**
 * The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
 * The function should return true if every candidate remaining in the election has the same number of votes, and should return false otherwise.
 * */
// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

/**
 * The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
 * The function should eliminate the candidate (or candidates) who has min number of votes.
 * */
// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}

void retrieveAndAddItsNextPrefCandidate(int indexOfEliminatedCandidate)
{
    for (int i = 0; i < voter_count; i++)
    {
        if (preferences[i][0] == indexOfEliminatedCandidate)
        {
            //retrieve their next top candidate and increment vote
            int indexOfNextPref = preferences[i][topPrefCandidate + 1];
            candidates[indexOfNextPref].votes++;
        }
    }
}

//Checks if the candidate exists in the candidates array
//and if so, then returns its index or else returns -1 when not found
int findTheCandidate(string name)
{
    int index = -1;
    //if the candidates array is empty, exit early
    if (candidates[0].name == NULL)
    {
        return index;
    }

    //for each candidate, try to match the name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}
