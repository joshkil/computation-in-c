#include <stdio.h>

/*
 * This is a simple calculator that adds two numbers. 
 * We practice using the scanf and printf functions to read and
 * write data from the screen. In the computing field, we call this 
 * "standard input" (stdin) and "standard output" (stdout) because we 
 * are reading from and writing to the terminal screen. 
 */

/* 
 * BASIC SCANF REFERENCE 
 *   scanf("%<format-string>", &<variable-name>);
 *     - <format-string> starts with '%' and then uses one of the following: 
 *          c - read a character
 *          i - read a integer
 *          f - read a floating point number
 *     - <variable-name> starts with '&' then a previously defined variable. 
 *  
 *   The function will read from the screen and store the value into the 
 *   variable you specify. Google "scanf stdio" for more options. 
 */

/* 
 * BASIC PRINTF REFERENCE 
 *   printf("%<format-string>", <variable-name>);
 *     - <format-string> uses one of the following: 
 *          %c - print a character
 *          %i - print an integer
 *          %f - print a floating point number
 *          \n - print a new line (a return)
 *     - <variable-name> is a previously defined variable. Don't use '&'!
 *  
 *   The function will print to the screen the value in the 
 *   variable you specify. Google "printf stdio" for more options. 
 */

int main(void){

    /* delare variables to hold the left operand, right operand, and answer */
    int lop = 0;
    int rop = 0;
    int ans = 0;
    
    /* Request and read input from the user */
    printf("Addition Program:\n");
    printf("Enter Left Operand: ");
    scanf("%i", &lop);
    printf("\n");
    printf("Enter Right Operand: ");
    scanf("%i", &rop);
    printf("\n");
    
    /* do the math and store the answer */
    ans = lop + rop;

    /* print out the answer */ 
    /* 
     * Notice the number '4' in front of each format string. This tells
     * the printf function to always print 4 positions and if there aren't
     * enough digits, it fills the remaining positions with a space. Experiment
     * with removing the '4' and see the difference. 
     */
    printf("%4i %4c %4i = %4i\n", lop, '+', rop, ans);
    return 0;
}