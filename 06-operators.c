#include <stdio.h>

/*
 * This program provides example usages of the c languages operators. The program 
 * reviews: 
 *      assignment = 
 *      math * / % + -
 *      math & assignment combos += -= *= /= %=
 *      variable incrementation ++ -- 
 *      comparison < > <= >= == !=
 *      logial && || !
 */

int main(){

    /* 
     * Assignment Operator 
     * The assignment operator is evaluated left to right and can be 
     * chained together with other operators. Here's how to think about 
     * it. 
     * 
     * Step 1: c = 10 is evaluated. 10 is assigned to c, and the value 
     *         10 is returned from the expression to the next assignment
     *         operator.
     * 
     * Step 2: b = (c = 10) is evaluated. From step 2, 10 can be substituted 
     *         for c = 10. So its "b = 10". 10 is assigned to b and 10 is
     *         returned. 
     * 
     * Step 3: a = (b = 10) is evaluated. Similarly to step 2, 10 can be
     *         substituted for b = 10. 10 is assigned to a and 10 is returned. 
     *         Since there are no other assignments, the statement completes. 
     *         
     */

    int a, b, c; 
    a = b = c = 10;
    printf("a: %i; b: %i; c: %i\n", a, b, c);

    /*
     * Math Operators 
     * The typical math operators you'd expect are supported. 
     * 
     *  + = addition
     *  - = subtraction and negation
     *  * = multiplication
     *  / = division
     *  % = modulo (remainder of division, integers only) 
     */

    int numrooms = 6; 
    int numguests = 15;
    printf("If we have %i rooms and %i guests, we need %i guests per room,\n", 
        numrooms, numguests, numguests / numrooms);
    printf("and %i rooms will need to accomodate one extra guest each.\n", 
        numguests % numrooms);

    /* Operators are evaluated in the order : * / % + - */
    int result = 5 - 2 * 7 / 10;
    printf("Results: %i (expect 4)\n", result);

    /* We can use parenthesis to alter order of evaluation. Expressions in parenthesis
     * are always evaluated first. 
     */
    result = (5 - 2) * 7 / 10;
    printf("Results: %i (expect 2)\n", result);

    result = (5 - 2) * (7 / 10);
    printf("Results: %i (expect 0)\n", result);

    result = 5 - (2 * (7 / 10));
    printf("Results: %i (expect 5)\n", result);

    /* 
     * Special operator for increasing and decresing a variable. 
     * You can use += and -= to increase or decrease a variable's value. 
     * These two statements have the same effect, but the first is shorter to type. 
     *     result += 5 
     *     result = result + 5;
     */

    result = 10;
    result += 5; /* now result is equal to 15 */
    result = result + 5; /* now result is equal to 20 */
    printf("Results: %i (expect 20)\n", result);
    result -= 10;
    printf("Results: %i (expect 10)\n", result);

    /* 
     * Special increment and decrement operators to increase or decrease
     * a variable by 1. Note that in the order of precedence of operations, 
     * ++ and -- come before multiplication. So, the full order is : 
     *    ++ -- * / % + -
     */

    result = 10;
    result++; /* now results equals 11 */
    printf("Results: %i (expect 11)\n", result);
    result--; /* now results equals 10 again */
    printf("Results: %i (expect 10)\n", result);

    /* 
     * Consider this complex expression. Can you determine the final values 
     * of the variables? Don't worry if you can't. I wrote this example to 
     * be controversial and make the point that the order of operations can 
     * be confusing. Because of this, always try to write expressions that are 
     * very clear and use parenthesis to clarify the order of evaluation you want. 
     */ 
    a = 10; 
    b = 20; 
    c = 30; 

    a += b = 100 % 1 - a * c++ / a; 
    printf("a: %i (expect -20); b: %i (expect -30); c: %i (expect 31)\n", a, b, c);

    /*
     * Comparison Operators. 
     * In the previous sections, we reviewed the mathematical and assignment 
     * operators. Another kind of operator is the comparison operator. These 
     * operators return either 1 (true) or 0 (false). They are used to "compare"
     * two expressions. 
     */
    a = 10; 
    b = 20; 
    c = 30; 
    printf("a < b : %i (expect 1 : true)\n", a < b);    /* less than */
    printf("c < b : %i (expect 0 : false)\n", c < b);   /* less than operator */
    printf("c > b : %i (expect 1 : true)\n", c > b);    /* greater than operator */
    printf("a <= b: %i (expect 1 : true)\n", a <= b);   /* less than or equal operator */
    printf("a <= 10: %i (expect 1 : true)\n", a <= 10); /* less than or equal operator */
    printf("a == b: %i (expect 0 : false)\n", a == b);  /* equality operator */
    printf("a != b: %i (expect 1 : true)\n", a != b);   /* inequality operator */
    printf("a == 10: %i (expect 1 : true)\n", a == 10); /* equality operator */

    /*
     * Logical Operators. 
     * Logical operators allow us to combine multiple comparison operators together
     * and get a final result. 
     * 
     *   && = AND ; returns 1 if both sides are true (1)
     *   || = OR  ; returns 1 if either side is true (1)
     *   !  = NOT ; returns 1 if operand is false (0)
     */

    a = 10; 
    b = 20; 
    c = 30; 

    printf("a < b && c > b: %i (expect 1 : true)\n", a < b && c > b);  
    printf("a < b || c > b: %i (expect 1 : true)\n", a < b || c > b);
    printf("a < b || b > c: %i (expect 1 : true)\n", a < b || c > b);
    printf("a < b && b > c: %i (expect 0 : false)\n", a < b || b > c);


    return 0;
}