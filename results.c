#include <stdio.h>
typedef struct Voters
{
    char name[49];
    long long voterid;
    int vote;
} Voter;
int get_int_len(long long value)
{
    int l = 1;
    while (value > 9)
    {
        l++;
        value /= 10;
    }
    return l;
}
int main()
{
    int a = 0;
    int b = 0;
    FILE *file = fopen("VotingData.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    Voter voter[100];
    int read = 0;
    int records = 0;
    do
    {
        read = fscanf(file, "%49[^,],%lld,%d",
                      voter[records].name,
                      &voter[records].voterid,
                      &voter[records].vote);

        if (read == 3)
            records++;
        if ((read != 3) && !feof(file))
        {
            printf("File formar error on index[%d]\n", records);
            continue;
        }
        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(file));
    fclose(file);
    printf("\n\n%d votes read\n\n", records);
    for (int i = 0; i < records; i++)
    {
        if (get_int_len(voter[i].voterid) != 12)
        {
            printf("Voter ID [%lld] is not valid (vote invalid)\n", voter[i].voterid);
            continue;
        }
        else
        {
            switch (voter[i].vote)
            {
            case 1:
                a++;
                break;
            case 2:
                b++;
                break;
            default:
                break;
            }
        }
    }
    printf("a:%d and b:%d\n", a, b);
    printf("%s ", ((a == b) ? "Tie" : ((a > b) ? "A wins" : "B wins")));
    if (a != b)
    {
        printf("with %.2f%% votes", (((a > b) ? a : b) / (float)records) * 100);
    }
    return 0;
}