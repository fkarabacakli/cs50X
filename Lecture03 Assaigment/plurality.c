#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
}

bool vote(string name)
{
    for(int i=0 ; i<candidate_count ; i++)
    {
        if(strcasecmp(name,candidates[i].name)==0)
        {
            candidates[i].votes = candidates[i].votes +1;
            return true; 
        }
    }
    return false;
}

void print_winner(void)
{
    int n= candidate_count;
    candidate convert;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-i-1 ; j++)
        {
            if(candidates[i].votes<candidates[i+1].votes)
            {
                convert= candidates[i];
                candidates[i]=candidates[i+1];
                candidates[i+1]=convert;
            }
        }
        
    }
    int equal=0;
    for(int i=1; i<n ; i++)
    {
        if(candidates[i].votes==candidates[0].votes)
        {
            equal = equal+1;
        }
    }

    if(equal==0)
    {
        printf("Winner is %s with %i votes\n", candidates[0].name,candidates[0].votes);
    }
    else
    {
        printf("Tie...\n");
        for(int i=0; i<=equal;i++)
        {
            printf("%s %i votes\n",candidates[i].name, candidates[i].votes);
        }
    }
    return;
}