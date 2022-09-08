#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

/*
 * fillscores(int scores[][6][9])
 * Fill the values of the 2X6X9 multi-dimensinoal array with random scores between
 * 0 and 10. 
 * 
 * NOTE: When you define a function that will receive a multi-dimensional array, 
 * the c-language requires that you specify the dimensions of all except the first
 * dimension.
 */
void fillscores(int scores[][6][9]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 6; j++) {
            for(int k = 0; k < 9; k++){
                scores[i][j][k] = rand() % 11;
            }
        } 
    }
}

int main (void){

    srand(time(NULL));
    /* 
     * Define a multi-dimensional array to hold the baseball scores per inning
     * for two teams over a 6 game series. 
     * 
     * I need 9 integers per team per game; so, I need a total of 9 * 2 * 6 integers
     */

    /* 
     * Two teams, 6 games, 9 innings 
     *   
     *   dimension1 : [2] = two teams
     *   dimension2 : [6] = six games
     *   dimension3 : [9] = nine innings per game
     */
    int scores [2][6][9] = {0}; 

    /* Set the scores for inning 1 of game 1 for team 1 */
    scores[0][0][1] = 5; 

    /* Set the scores for inning 1 of game 1 for team 2 */
    scores[1][0][1] = 5; 

    /* 
     * Call fillscores(int scores [][6][9]) to set random scores into our array 
     * for both teams and all the games. 
     * 
     * When you pass a multi-dimensional array to a function, you just specify the 
     * name of the array. The dimensions of the array you pass MUST be equal to 
     * the dimensions specified in the function's definition for all dimentions 
     * except the first dimension which can be of any length. 
     * 
     * NOTE: normally, you would define your function to take additional parameters
     * that specify the size of the three dimensions, but to keep our code short, 
     * I've skipped that step. 
     */

    fillscores(scores);

    /*
     * Looping through multi-dimensional arrays can be a bit of a 
     * mind teaser, but if you follow the pattern I show you in the 
     * code block below, you won't have any problems
     */ 

    for(int i = 0; i < 2; i++){
        printf("Team %i\n", i+1);
        for(int j = 0; j < 6; j++) {
            printf("   Game %i: ", j+1);
            for(int k = 0; k < 9; k++){
                printf("[%02i] ", scores[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return 0;
}