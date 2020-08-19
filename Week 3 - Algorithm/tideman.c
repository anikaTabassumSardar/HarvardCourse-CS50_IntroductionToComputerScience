#include <cs50.h>
#include <stdio.h>
#include <string.h>

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

// Creating a separate struct since I am not allowed to edit the existing struct
typedef struct
{
    int winner;
    int loser;
    int strength;
}
pairStrength;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

//Helper methods by Neela
int findTheCandidate(string name);
bool isCycle(int unlockedIndex1, int unlockedIndex2);

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

/**
 * Complete the vote function.
The function takes arguments rank, name, and ranks. If name is a match for the name of a valid candidate,
then you should update the ranks array to indicate that the voter has the candidate as their rank preference
(where 0 is the first preference, 1 is the second preference, etc.)
Recall that ranks[i] here represents the user’s ith preference.
The function should return true if the rank was successfully recorded, and false otherwise
(if, for instance, name is not the name of one of the candidates).
You may assume that no two candidates will have the same name.
 * */
// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    //Check if it is a valid candidate name
    int index = findTheCandidate(name);

    if (index == -1)
    {
        return false;
    }

    //if valid, update the rank
    ranks[rank] = index;
    return true;
}

/**
 * Complete the record_preferences function.
The function is called once for each voter, and takes as argument the ranks array,
(recall that ranks[i] is the voter’s ith preference, where ranks[0] is the first preference).
The function should update the global preferences array to add the current voter’s preferences.
Recall that preferences[i][j] should represent the number of voters who prefer candidate i over candidate j.
You may assume that every voter will rank each of the candidates.
 * */
// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    //the bool condition here is candidate_count-1 to avoid out of bounds exception for i+1
    for (int i = 0; i < candidate_count; i++)
    {
        int nextCandidate = i + 1;
        while (nextCandidate < candidate_count)
        {
            // avoid matching situations like [1][1]
            if (nextCandidate != i)
            {
                //handle pairs like [0][1] and [0][2]
                preferences[ranks[i]][ranks[nextCandidate]]++;
            }
            nextCandidate++;
        }
    };
}

/**
 * Complete the add_pairs function.
The function should add all pairs of candidates where one candidate is preferred to the pairs array.
A pair of candidates who are tied (one is not preferred over the other) should not be added to the array.
The function should update the global variable pair_count to be the number of pairs of candidates.
(The pairs should thus all be stored between pairs[0] and pairs[pair_count - 1], inclusive).
 * **/
// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int j;

    for (int i = 0; i < candidate_count; i++)
    {
        j = i + 1;
        while (j < candidate_count)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
            j++;
        }
    }
}

/**
 * Complete the sort_pairs function.
The function should sort the pairs array in decreasing order of strength of victory,
where strength of victory is defined to be the number of voters who prefer the preferred candidate.
If multiple pairs have the same strength of victory, you may assume that the order does not matter.
 * */
// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // fill array with winner preferences
    int strength[pair_count];

    for (int i = 0; i < pair_count; i++)
    {
        strength[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }

    //sorting function
    while (1)
    {
        int swapped = 0;

        for (int i = 0; i < pair_count - 1; i++)
        {
            for (int j = i + 1; j < pair_count; j++)
            {
                if (strength[i] < strength[j])
                {

                    //sorting pairs
                    pair tmp = pairs[i];
                    pairs[i] = pairs[j];
                    pairs[j] = tmp;

                    //sorting strength
                    int tmp2 = strength[j];
                    strength[j] = strength[i];
                    strength[i] = tmp2;
                    swapped = 1;
                }
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

/**
 * Complete the lock_pairs function.
The function should create the locked graph, adding all edges in decreasing order of victory strength so long as the edge would not create a cycle.
 * */
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int winner;
    int loser;

    for (int i = 0; i < pair_count; i++)
    {
        winner = pairs[i].winner;
        loser = pairs[i]. loser;

        //check if cycle
        if (!isCycle(winner, loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
}

/**
 *Complete the print_winner function.
The function should print out the name of the candidate who is the source of the graph. You may assume there will not be more than one source.
 * */
// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool source = true;

        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                source = false;
                break;
            }
        }

        if (source == true)
        {
            printf("%s\n", candidates[i]);
        }
    }
}

bool isCycle(int unlockedIndex1, int unlockedIndex2)
{
    bool flag = true;

    //creates a cycle
    if (locked[unlockedIndex2][unlockedIndex1] == true)
    {
        return true;
    }

    //check if index is present in the loser index for locked[], if not, then it is our winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][unlockedIndex1] == true)
        {
            return isCycle(i, unlockedIndex2);
        }
    }

    return false;
}

//Checks if the candidate exists in the candidates array
//and if so, then returns its index or else returns -1 when not found
int findTheCandidate(string name)
{
    int index = -1;
    //if the candidates array is empty, exit early
    if (candidates[0] == NULL)
    {
        return index;
    }

    //for each candidate, try to match the name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

