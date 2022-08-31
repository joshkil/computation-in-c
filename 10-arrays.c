#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_STUDENTS 10

int main (void){

    /*
     * Defining Arrays. 
     * Arrays are like single variables in that they have a type and a name, 
     * but when you define an array, it's like defining many variables all 
     * at once. The code below shows the definition of 100 integers. 
     */

    int iarray [100];

    /*
     * Accessing the Elements of the Array.
     * After you define an array, you can access it's elements 
     * as shown in the code below. Each element has an index to which
     * you can refer inside the brackets. For an array of size n, 
     * indexes go from 0 to n-1. 
     */ 

    iarray[0] = 1; /* set a value in the first element of the array */
    iarray[99] = 100; /* set a value in the final element of the array */

    printf("iarray[0] = %i (expect 1)\n", iarray[0]);
    printf("iarray[99] = %i (expect 100)\n", iarray[99]);

    /*
     * Accessing Undefined Elements. 
     * If you access an array element before you've assigned a value, 
     * the value will be undefined. It could be any number, but many
     * compilers will auto initialize the array to zero. 
     */
    printf("iarray[1] = %i (undefined)\n", iarray[1]);

    /*
     * Initializing Arrays. 
     * You have the option to initialize arrays at the moment you 
     * delcare them as shown below. 
     */
    float farray[5] = {1.0, 2.2, 3.4, 4.5, 5.6};

    /*
     * A Practical Example
     * Below is a practical example of using an array to store the grades
     * of a group of students. Notice that I use a new technique to define
     * the size of the grades array. Rather than using a literal constant, 
     * I use a named constant which I defined at the top of the file. This is
     * a good practice because it avoids scattering a number around in the 
     * code. If you just scatter a number around in the code in a bunch of 
     * places, it's hard to update and a person who comes behind you may not 
     * understand the rationale for the number. A named constant makes things
     * more clear. 
     */

    int grades[NUM_OF_STUDENTS];
    int min = 100;
    int max = 0;
    float average = 0.0;

    /*
     * Initialize the random function and loop through the array filling
     * each element with a random number. I ensure the number is between 
     * 0 and 99 by using modulo (%) 100 on a random number chosen by the 
     * computer. I set the grades randomly, just to make the code more 
     * interesting. 
     */
    srand(time(NULL));

    for(int i = 0; i < NUM_OF_STUDENTS; i++){
        grades[i] = rand() % 100;
    }

    /*
     * Loop through the array searching for the min and max, and to sum all
     * grades. 
     */

    for(int i = 0; i < NUM_OF_STUDENTS; i++){
        if(min > grades[i]){
            min = grades[i];
        }

        if(max < grades[i]){
            max = grades[i];
        }

        average += grades[i];
    }

    /* Calculate the average */
    average = average / NUM_OF_STUDENTS;

    printf("Min Grade : %i\n", min);
    printf("Max Grade : %i\n", max);
    printf("Average Grade : %.2f\n", average);

    /* print out the contents of the array so we can check the result */
    printf("All Grades : \n");
    for(int i = 0; i < NUM_OF_STUDENTS; i++){
        printf("%3i  ", grades[i]);

        /* The next code block is used to add a return (a new line)
         * after every 4 numbers in the array
         */
        if(i % 4 == 3){
            printf("\n");
        }
    }
    printf("\n");

    return 1; 
}