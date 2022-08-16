#include <stdio.h>
#include <string.h>

typedef struct Voters
{
    char name[49];
    long long voterid;
    int vote;
} Voter;
int max_voters = 13;

int main()
{
    FILE *file = fopen("VotingData.csv", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    Voter voters[max_voters];
    // taking input
    int attendees = 0;
    char cont = 'Y';
    while (attendees < 3 && (cont == 'Y' || cont == 'y'))
    {
        printf("______________________________\n");
        printf("Enter your name : ");
        scanf("  %[^\n]s", voters[attendees].name);
        printf("Enter your 12 digit Voter ID : ");
        scanf("%lld", &voters[attendees].voterid);
        printf("Enter your Vote : ");
        scanf("%d", &voters[attendees].vote);
        printf("______________________________\n");
        attendees++;
        if (attendees < 3)
        {
            printf("\nDo you want to continue? [Y/N]\n");
            scanf(" %c", &cont);
        }
        else
        {
            printf("\nElection completed.\n");
        }
        
    }
    for (int i = 0; i < attendees; i++)
    {
        fprintf(file, "%s, %lld, %d\n", voters[i].name, voters[i].voterid, voters[i].vote);
    }
    fclose(file);
    if (attendees > 1)
    {
        printf("%d people voted.\n", attendees);
    }
    else
    {
        printf(((attendees == 0) ? ("No one voted.\n") : ("1 person voted.\n")));
    }
}
