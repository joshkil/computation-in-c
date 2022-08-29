#include <stdio.h>

/*
 * Program 08 : Flow of Control
 * This program provides example usages of the c language's flow of control
 * statements. We review: 
 *      if, else if, else
 *      for loops
 *      while loops
 *      do while loops
 *      switch statements
 */

int main(){

    /*
     * Example 1: Ask for the user's age, then use if-else statemments 
     * to decide what we will print to the screen. 
     */
    int myage = 45;
    int yourage = 0; 

    printf("How old are you? ");
    scanf("%i", &yourage);

    if(yourage < myage){
        printf("\nI'm older than you!\n");
        if( (myage - yourage) >= 20 ){
            printf("I could be your parent!\n");
        }
    }else if (yourage == myage){
        printf("\nWOW! We are the same age.\n");
    }else {
        printf("\nSo, you're older than me.\n");
    }

    /* 
     * Example 2: We ask the user to provide a base number and 
     * an exponent to which they want to raise the base. Then we use
     * a for-Loop to calculate the result. A for-loop is usually used 
     * when you know exactly how many times you want to execute 
     * a code block. 
     */ 
    printf("\nExponents Calculator: \n");
    int base = 0; 
    int exponent = 0;
    int result = 1;
    printf("Enter the Base Number: ");
    scanf("%i", &base);
    printf("Enter the Exponent Number: ");
    scanf("%i", &exponent);

    /* 
     * In this for loop, we count from 0 to exponent. This means
     * the loop will execute "exponent" times.  
     */
    for(int i = 0; i < exponent; i++){
        result *= base;
    }
    printf("%i to the power of %i = %i\n", base, exponent, result);

    /* 
     * Example 3: We ask the user how long they would like to continue
     * reading a statement. If they keep saying "y", we continue to print
     * the statement so they can read it again. 
     */ 
    printf("\nA Wise Saying: \n");
    char useranswer = 'y';

    /*
     * We print out a wise saying and then ask the user if they want to continue. 
     * We keep going as long as the user keeps typing 'y' for yes. 
     */
    while(useranswer == 'y'){
        printf("You must be the change you wish to see in the world. - Mahatma Gandhi\n");
        printf("Would you like to read this wise saying again (y or n):");
        scanf(" %c", &useranswer);
    }

    /* 
     * Example 4: We ask the user to choose which combo type they
     * want and then print out what was in that combo type. 
     */

    int usercombotype = 0;
    printf("\nMcDonald's Ordering System:\n");
    printf("We have three combos available:\n");
    printf("Combo 1: Junior Mc Cheeseburger with fries and a coke.\n");
    printf("Combo 2: Filet-o-fish Sandwich with fries and a coke.\n");
    printf("Combo 3: Mc Chicken Sandwich with apple pie and a coke.\n");
    printf("Which combo would you like 1, 2, or 3?\n");

    scanf("%i", &usercombotype);

    switch(usercombotype){
        case 1: 
            printf("Enjoy your Junior Mc Cheeseburger with fries and a coke.\n");
            break;
        case 2: 
            printf("Enjoy your Filet-o-fish Sandwich with fries and a coke.\n");
            break;
        case 3:
            printf("Enjoy your Mc Chicken Sandwich with apple pie and a coke.\n");
            break;
        default:
    }

    return 0;
}