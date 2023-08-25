// C program for electing the president of CSE branch for 2024 through online voting system
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
// define candidates
#define CANDIDATE1 "Ganesh"
#define CANDIDATE2 "Mahesh"
#define CANDIDATE3 "Rathan"
#define CANDIDATE4 "Abhishek"
#define NOTA "None"
#define SPOILEDVOTES "Error"
// initialise vote counts of candidates to zero
int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0, votesCount4 = 0, notavotes = 0, spoiledvotes = 0;
// create an array with boolean type and initially set to false
bool voted[300] = {false};
// This function is to choose the candidate of their choice
void castVote()
{

    int choice;
    printf("Please choose your Candidate !!\n");
    printf("\n 1. %s", CANDIDATE1);
    printf("\n 2. %s", CANDIDATE2);
    printf("\n 3. %s", CANDIDATE3);
    printf("\n 4. %s", CANDIDATE4);
    printf("\n 5. %s", NOTA);
    printf("\nInput your choice (1 - 5) : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        votesCount1++;
        break;
    case 2:
        votesCount2++;
        break;
    case 3:
        votesCount3++;
        break;
    case 4:
        votesCount4++;
        break;
    case 5:
        notavotes++;
        break;
    default:
        spoiledvotes++;
    }
    printf("Thanks for your valuable vote !!\n");
}
// This function provides the votes earned by candidates
void votesCount()
{
    printf(" Voting Statistics !!\n");
    printf("\n %s - %d ", CANDIDATE1, votesCount1);
    printf("\n %s - %d ", CANDIDATE2, votesCount2);
    printf("\n %s - %d ", CANDIDATE3, votesCount3);
    printf("\n %s - %d ", CANDIDATE4, votesCount4);
    printf("\n %s - %d ", NOTA, notavotes);
    printf("\n %s - %d\n", SPOILEDVOTES, spoiledvotes);
}
// This function provides the leading candidate
void getLeadingCandidate()
{
    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4 && votesCount1 > notavotes & votesCount1 > spoiledvotes)
        printf("[%s] has won the election with %d votes !!\n", CANDIDATE1, votesCount1);
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1 && votesCount2 > notavotes && votesCount2 > spoiledvotes)
        printf("[%s] has won the election with %d votes !!\n", CANDIDATE2, votesCount2);
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1 && votesCount3 > notavotes && votesCount3 > spoiledvotes)
        printf("[%s] has won the election with %d votes!!\n", CANDIDATE3, votesCount3);
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3 && votesCount4 > notavotes && votesCount4 > spoiledvotes)
        printf("[%s] has won the election with %d votes !!\n", CANDIDATE4, votesCount4);
    else if (notavotes > votesCount1 && notavotes > votesCount2 && notavotes > votesCount3 && notavotes > votesCount4 && notavotes > spoiledvotes)
        printf("None of te above option having higher votes !! Go for re-election !!\n");
    else if (spoiledvotes > votesCount1 && spoiledvotes > votesCount2 && spoiledvotes > votesCount3 && spoiledvotes > votesCount4 && spoiledvotes > notavotes)
        printf("Election spoiled due to invalid choices !! Go for re-election !!\n");
    else
        printf("There is a tie !! Go for re-election !!\n");
}

int main()
{
    int i = 1, usn;
    time_t startTime, currentTime;
    // duration of election = 2 hours in this election
    double duration = 60.0 * 120.0;
    startTime = time(NULL); // Get start time
    while (i <= 200)
    {
        currentTime = time(NULL); // Current time at ecah loop
        // checks diffference between current and start times
        // if it exceeds duration then voting time has ended otherwise voting continues till end of while or expiry of time
        if (difftime(currentTime, startTime) <= duration)
        {

            printf("\n\n WELCOME TO CSE BRANCH PRESIDENT ELECTION 2024 !!\n");
            printf("Enter last three digits of your usn:");
            scanf("%d", &usn);
            if (!voted[usn])
            {
                castVote();
                i++;
                voted[usn] = true;
            }
            else
            {
                printf("You have already voted!\n");
            }
        }
        else
        {
            printf("Election period has ended !!\n");
            break;
        }
    }

    int s;
    int k = 0;
    // To the use of CSE department for the result of election
    printf("\n\nFOR CSE DEPARTMENT ACCESS ONLY !!\n\n");
    while (k < 4)
    {

        printf("Enter the password:");
        scanf("%d", &s);
        // set password=456
        if (s == 456)
        {
            votesCount();
            getLeadingCandidate();
            break;
        }
        else
        {
            if (k < 3)
                printf("wrong password!! Retry !!\n");
            else
                printf("Wrong password !!\n");
        }
        k++;
    }
    if (k == 4)
        printf("Limit reached and you failed to access the result !!");
    return 0;
}