#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

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

    while (true)
    {
        tabulate();

        bool won = print_winner();
        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

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

        eliminate(min);

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    
    for(int i=0; i<candidate_count; i++)
    {
        if(strcasecmp(name,candidates[i].name)==0)
        {
            preferences[voter][rank]=i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for(int i=0 ; i<voter_count; i++)
    {
        for(int j=0 ; j<candidate_count ; j++)
        {
            if(candidates[preferences[i][j]].eliminated==false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        
        }
    }
    return;
}

bool print_winner(void)
{
    for(int i=0; i<candidate_count;i++)
    {
        if(candidates[i].votes > voter_count/2)
        {
            printf("Winner is %s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int min = voter_count;
    
    for (int i=0; i<candidate_count; i++)
    {
        if(candidates[i].votes < min && candidates[i].eliminated ==false)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

bool is_tie(int min)
{
    int eliminate = 0;
    int counter = 0;
    
    for(int i=0; i< candidate_count;i++)
    {
        if(candidates[i].eliminated==false)
        {
            eliminate++;
        }
        
        if(candidates[i].votes == min)
        {
            counter++;
        }
    }
    if( eliminate == counter)
    {
        return true;
    }
    return false;
}

void eliminate(int min)
{
    for(int i=0; i< candidate_count; i++)
    {
        if(candidates[i].votes == min)
        {
            candidates[i].eliminated= true;
        }
    }
    return;
}