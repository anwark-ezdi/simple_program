#include <stdio.h>
#include <stdlib.h>
#define MONTH 12
#define GAME 8


void makeArray(FILE* inputFile, int scores[MONTH][GAME])
{
    int  i,j,input = 0;
    for (i=0 ; i< MONTH ; i++) 
    {
        for (j=0 ; j< GAME ; j++) 
        {
            fscanf(inputFile,"%d",&input);
            
            if (input!=999)
            {
                scores[i][j] = input;
            }
        }
    }

}


int getScore(int scores[MONTH][GAME],int inputMONTH,int GAMENumber)
{
    return scores[inputMONTH-1][GAMENumber-1];
}


int getMONTHMax(int scores[MONTH][GAME], int inputMONTH)
{
    int MONTHMax = scores[0][0], i;

    for (i=0;i<GAME;i++)
    {
        if (scores[inputMONTH-1][i] > MONTHMax)
            MONTHMax = scores[inputMONTH-1][i];
    }
    return MONTHMax;
}


int getYearMax(int scores[MONTH][GAME])
{
    int i, j, yearMax = 0;
    for (i=0; i<MONTH; i++)
    {
        for(j=0;j<GAME;j++)
        {
            if (scores[i][j]>yearMax)
                yearMax=scores[i][j];
        }
    }
    return yearMax;
}


float getMONTHAvg(int scores[][GAME], int inputMONTH)
{
    float totalScore=0,average;
    int i=0;
    for (i=0;i<8;i++)
    {
        totalScore += scores[inputMONTH-1][i];
    }
    average = totalScore/8;
    return average;
}


float getYearAvg(int scores[MONTH][GAME])
{
    int i=0, j=0;
    float totalScore = 0, average;
    for (i=0; i<MONTH; i++)
    {
        for(j=0;j<GAME;j++)
        {
            totalScore += scores[i][j];
        }
    }
    average = totalScore/96;
    return average;
}


int toursMissed(int scores[MONTH][GAME])
{
    int i=0, j=0, missed=0;
    for (i=0;i<MONTH;i++)
    {
        for (j=0;j<GAME;j++)
        {
            if (scores[i][j]==0)
                missed++;
        }
    }
    return missed;
}


void displayMenu()
{

    printf("What would you like to do?\n");
    printf("-----------------------------------\n");
    printf("Select from options 1-7 or 0 to stop\n"); 
    printf("Select 1 to get the score for a specific GAME\n");
    printf("Select 2 to get the max score for a specific MONTH\n");
    printf("Select 3 to get the average score for a specific MONTH\n");
    printf("Select 4 to get the max score for the year\n");
    printf("Select 5 to get the average score for the year\n");
    printf("Select 6 to get the number of tournaments missed for the year\n");
    printf("Select 7 to print all scores for the year\n");
    printf("Select 0 to stop\n");
    printf("-----------------------------------\n");
}


void printArray(int scores[MONTH][GAME])
{
    int i,j;
    printf("The scores for the year are:\n");
    for (i=0; i<MONTH; i++)
    {
        for(j=0;j<GAME;j++)
        {
            printf("%d\t",scores[i][j]);
        
        }
        printf("\n");
    }
    printf("\n");
}



int processRequest(int scores[MONTH][GAME], int userChoice)
{
    int inputMONTH,GAMENumber;

    if (userChoice == 0)
    {
        printf("Thank you! Goodbye\n");
        return -1;
    }

    if (userChoice == 1)
    {
        printf("Enter MONTH: ");
        scanf("%d", &inputMONTH);
        printf("Enter GAME number(1 to 8): ");
        scanf("%d",&GAMENumber);
        printf("%d\n\n",getScore(scores,inputMONTH,GAMENumber));
    }

    if (userChoice == 2)
    {
        printf("Enter MONTH: ");
        scanf("%d",&inputMONTH);
        printf("Month max: %d\n\n",getMONTHMax(scores,inputMONTH));
    }
    
    
    if (userChoice == 3)
    {
        printf("Enter MONTH: ");
        scanf("%d",&inputMONTH);
        printf("%.2f\n\n",getMONTHAvg( scores, inputMONTH));
    }


    if (userChoice == 4)
    {
        printf("Maximum Score of year: %d\n\n",getYearMax(scores));
    }


    if (userChoice == 5)
    {
        printf("Year average: %.2f\n\n",getYearAvg(scores));
    }
    

    if (userChoice == 6)
    {
        printf("Tours Missed: %d\n\n",toursMissed(scores));
    }


    if (userChoice == 7)
    {
        printArray(scores);
        
    }

    return 0;
}


int main() 
{
   
    int scores[MONTH][GAME];
    int userChoice,temp;
    
    FILE* inputfile;                   /* declare a pointer for input file  */
    inputfile = fopen("scores.txt", "r");  /* open the inputfile */
    makeArray(inputfile,scores);
    
    while(1)
    {
        displayMenu();
        scanf("%d",&userChoice);
        temp = processRequest(scores,userChoice);
        if(temp == -1) break;
    }
    
    fclose(inputfile);
    return 0;
}


/*
output:

What would you like to do?
-----------------------------------
Select from options 1-7 or 0 to stop
Select 1 to get the score for a specific GAME
Select 2 to get the max score for a specific MONTH
Select 3 to get the average score for a specific MONTH
Select 4 to get the max score for the year
Select 5 to get the average score for the year
Select 6 to get the number of tournaments missed for the year
Select 7 to print all scores for the year
Select 0 to stop
-----------------------------------
7
The scores for the year are:
26  35  25  92  0   6   47  68  
26  72  67  33  84  28  22  36  
53  66  23  86  36  75  14  62  
43  11  42  5   14  58  0   23  
30  87  80  81  13  35  94  45  
1   53  14  55  46  19  13  0   
25  28  66  86  69  0   81  15  
55  60  26  70  22  36  15  67  
62  16  71  7   29  92  84  37  
2   30  7   5   4   50  0   67  
2   53  69  87  8   23  74  58  
86  0   78  88  85  12  1   52  

What would you like to do?
-----------------------------------
Select from options 1-7 or 0 to stop
Select 1 to get the score for a specific GAME
Select 2 to get the max score for a specific MONTH
Select 3 to get the average score for a specific MONTH
Select 4 to get the max score for the year
Select 5 to get the average score for the year
Select 6 to get the number of tournaments missed for the year
Select 7 to print all scores for the year
Select 0 to stop
-----------------------------------
1
Enter MONTH: 11
Enter GAME number(1 to 8): 3
69

What would you like to do?
-----------------------------------
Select from options 1-7 or 0 to stop
Select 1 to get the score for a specific GAME
Select 2 to get the max score for a specific MONTH
Select 3 to get the average score for a specific MONTH
Select 4 to get the max score for the year
Select 5 to get the average score for the year
Select 6 to get the number of tournaments missed for the year
Select 7 to print all scores for the year
Select 0 to stop
-----------------------------------
2
Enter MONTH: 3
Month max: 86


What would you like to do?
-----------------------------------
Select from options 1-7 or 0 to stop
Select 1 to get the score for a specific GAME
Select 2 to get the max score for a specific MONTH
Select 3 to get the average score for a specific MONTH
Select 4 to get the max score for the year
Select 5 to get the average score for the year
Select 6 to get the number of tournaments missed for the year
Select 7 to print all scores for the year
Select 0 to stop
-----------------------------------
3
Enter MONTH: 3
51.88

What would you like to do?
-----------------------------------
Select from options 1-7 or 0 to stop
Select 1 to get the score for a specific GAME
Select 2 to get the max score for a specific MONTH
Select 3 to get the average score for a specific MONTH
Select 4 to get the max score for the year
Select 5 to get the average score for the year
Select 6 to get the number of tournaments missed for the year
Select 7 to print all scores for the year
Select 0 to stop
-----------------------------------
4
Maximum Score of year: 94

What would you like to do?
-----------------------------------
Select from options 1-7 or 0 to stop
Select 1 to get the score for a specific GAME
Select 2 to get the max score for a specific MONTH
Select 3 to get the average score for a specific MONTH
Select 4 to get the max score for the year
Select 5 to get the average score for the year
Select 6 to get the number of tournaments missed for the year
Select 7 to print all scores for the year
Select 0 to stop
-----------------------------------
5
Year average: 41.71

What would you like to do?
-----------------------------------
Select from options 1-7 or 0 to stop
Select 1 to get the score for a specific GAME
Select 2 to get the max score for a specific MONTH
Select 3 to get the average score for a specific MONTH
Select 4 to get the max score for the year
Select 5 to get the average score for the year
Select 6 to get the number of tournaments missed for the year
Select 7 to print all scores for the year
Select 0 to stop
-----------------------------------
6
Tours Missed: 6

What would you like to do?
-----------------------------------
Select from options 1-7 or 0 to stop
Select 1 to get the score for a specific GAME
Select 2 to get the max score for a specific MONTH
Select 3 to get the average score for a specific MONTH
Select 4 to get the max score for the year
Select 5 to get the average score for the year
Select 6 to get the number of tournaments missed for the year
Select 7 to print all scores for the year
Select 0 to stop
-----------------------------------
0
Thank you! Goodbye
*/