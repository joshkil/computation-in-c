#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_OF_INNINGS 9

/* 
 * Program 10 : Challenge "Use Arrays to Rewrite the 10-bad-baseball.c program"
 * In this fine, I provide a clear solution to the 10-bad-baseball.c program. The 
 * "bad" program uses 18 integer variables to store the scores for 2 baseball teams. 
 * In the c-language, when we want to store numberous elements of data that are related
 * to one another, we use arrays to more uniformly store and access the data. 
 */


/*
 * getrandscroe - get a random score between 1 and 10
 * This is a helpful function to generate a random score between 0 and 10
 */
int getrandscore(){
    return (rand() % 11);
}

/*
 * printteam - print out a scoreboard for a single team
 * team arg is the number of the team
 * innings[] argument is an integer array of scores for 9 innings
 */
void printteam(int team, int innings[]){

    printf("-------------|----|----|----|----|----|----|----|----|\n");

    printf("Team %i > %4i|", team, innings[0]);

    for(int i = 1; i < NUM_OF_INNINGS; i++){
        printf("%4i|", innings[i]);
    }
    printf("\n");
}

int main(){
    /* define array for team 1 and initialize all elements to zero */
    int t1_innings[9] = {0};
    
    /* define array for team 2 and initialize all elements to zero*/
    int t2_innings[9] = {0};
    
    srand(time(NULL));

    /* print the initial scoreboard to verify it's all zeros */
    printf("Initial Score Board:\n");
    printteam(1, t1_innings);
    printteam(2, t2_innings);
    printf("\n\n");

    /* loop through 9 innings, set a random score for each team, and print the scroreboard */
    for(int i = 0; i < NUM_OF_INNINGS; i++){
        printf("Score Board (Inning %i):\n", i+1);
        t1_innings[i] = getrandscore();
        t2_innings[i] = getrandscore();
       
        printteam(1, t1_innings);
        printteam(2, t2_innings);
        printf("\n\n");
    }

    return 1;
}