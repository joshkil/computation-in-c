#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Program 07 : Challenge "Count Prime Numbers to 4 Billion"
 * This is a challenge program in from the computing foundations channel. It
 * is designed to help you practice variable types, math operators, 
 * comparison operators, and flow of control. 
 * 
 * CHALLENGE: Write a program to count the quantity of prime numbers between 
 *            2 and 4,294,967,295 - the max value of 4 byte unsigned int (2^32); 
 * 
 * Below is a solution to the challenge. How did you do? 
 * 
 * OUTPUT: 100.00% Complete
 * Between 1 and 4294967295, there are 203280221 prime numbers!
 * The largest prime number is 4294967291!
 */

int main(){
    unsigned int numofprimes = 0;
    unsigned int largestprime = 0;

    /*
     * Below, we define a variable that is the maximum number we want to test. 
     * This is the largest number that a 32 bit value can hold.  
     */
    unsigned int max = 4294967295;

    /*
     * Start a for-loop that will run between i = 2 and i = 4,294,967,295. Be careful
     * since you need to go all the way to the max value, your iterator variable needs to be
     * large enough to hold 2^32 + 1. That means you need a "long" variable (8 bytes, 64 bits), 
     * otherwise, i will overflow before reaching "max" and the program will never end. 
     */
    for(unsigned long i = 2; i <= max; i++){
        /* 
         * All numbers are divisible by 1 and by themselves. We want to see 
         * if there is any other number that will evenly divide into i; 
         */
    
        int isprime = 1; /* Assume the number is prime until we proove otherwise */

        /* 
         * This next statement is completely optional. I use it to show some 
         * status while the program is running. Once every 1,000 
         * numbers I will print the percentage of numbers analyzed. 
         * This just gives confidence that the program is running. Below, I use
         * two special functions you've never seen. 
         *   system(char*) is from stdlib.h and allows you to run a command on the 
         *                 terminal. I run "clear", which clears the screen. 
         *   fflush(stdout) forces the computer to print to the screen. Sometimes
         *                  the computer does not immediately print to the screen
         *                  unless you use the flush function.
         * 
         * Finally, I use typecasting. When you put a type in parenthesis in front
         * of an existing variable, you ask the computer to create a temporary variable
         * of the type you indicated and to copy the variable into that temporary location. 
         * This allows you to change the type of a variable on the spot. 
         */
        if(i % 10000 == 0){
            system("clear");
            printf("%4.2f%% Complete", 100.0 * ( (double)i / (double)max) );
            fflush(stdout);
        } 

        /*
         * Start another loop from 2 to sqrt(i) - square root of i. If there are any 
         * factors of i one must be less than the square root of i. As soon
         * as we find a number that divides evently, we can stop becasuse finding just
         * one factor is sufficient to prove i is NOT a prime. 
         * 
         * What's up with this square root business? How do we know a non-prime i must have a  
         * factor less than square root of i. 
         * 
         *      n = sqrt(i) if and only if (iff) n * n = i
         * 
         * If i is NOT prime, there exist two numbers a and b such that 
         * 
         *      a * b = i 
         * 
         * and one of the numbers a or b needs to be less than or equal to sqrt(i) because 
         * if both were greater than sqrt(i) then
         * 
         *      a * b > i 
         */ 

        for (unsigned long j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isprime = 0;
                break; /* the break statement stops the loop */ 
            }
        }

        /* 
         * At this point, either we finished the loop and found no numbers
         * that divide eveninly into i OR we broke out early and we did find
         * at least one number that divided evenly. 
         */

        if(isprime){
            /* we found a prime number, increment our prime number counter */
            numofprimes += 1; 
            largestprime = i;
        }
    }

    printf("\nBetween 2 and %u, there are %u prime numbers!\n", max, numofprimes);
    printf("The largest prime number is %u!\n", largestprime);

    return 1;
}