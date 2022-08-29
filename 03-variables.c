#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h> 

/*
 * Program 03 : Variables 
 * This program helps you understand how to declare variables in the c language. 
 * This program helps us visualize the size of various integer variable types in memory. 
 * We use the maximum and minimum values of each type from limits.h to calculate
 * the number of bits required to represent that many unique values. We also get
 * a look at the sizeof() function which reports the number of bytes in memory
 * represented by a variable. 
*/

int main (){

    /* 
     * Understanding Variables is the first step in learning a new computer programming
     * language. Below we define various variables and show you how to assign a value. 
     * You've probably mostly heard the word "variable" in your algebra math classes. In math, 
     * the idea of a variable is often associated with a single value. You solve the 
     * equasion to find the value of the variable. In a computer program, a variable 
     * is more like a container that can hold any value you want.
     * 
     * You can name variables using letters, numbers, and the underscore '_'. 
     *    1. A variable can have alphabets, digits, and underscore.
     *    2. A variable name can start with the alphabet, and underscore only. 
     *       It can't start with a digit.
     *    3. No whitespace is allowed within the variable name.
     *    4. A variable name must not be any reserved word or keyword, e.g. int, for, while
     * 
     * There is no limit to the length of a variable name. 
    */

    /*
     * The smallest and simplest variable type in the c language is the character. 
    */
    char my_first_initial = 'J'; /* a char variable holds one letter or number up to 127 */
    char my_weird_character = 10; /* you can also assign a number to character */

    /*
     * Define various integer type variables. The type you pick sets the number of 
     * bytes the computer reserves for the variable and therefore sets a limit on the 
     * maximum value. 
    */
    short short_integer = 32767; /* a short integer holds a number up to 32 million-ish */
    int normal_integer = 2147483647; /* a normal integer holds a number up to 2 billion-ish */
    long large_integer = 9223372036854775807; /* a large integer holds a number up to 9 quintillion */

    /*
     * Define various floating-point type variables. Use floating points to represent
     * rational (fractional) numbers. The type you pick sets the number of bytes
     * the computer reserves for the variable and therefore sets a limit on the 
     * maximum value and/or maximum precision of the variable. 
    */
    float rational_number = 1.123456f; /* 6 to 7 significant bits */
    double double_precision_rational_number = 1.012345678912345f; /* 15 to 16 significant bits */

    /*
     * After you assign one value to a variable, you can later change the value. 
     * You can reuse a variable as much as you want. 
    */

    my_first_initial = 'A'; /* Re-assign the letter A to a variable defined earlier */


    /* 
     * In the next secion, we define more variables and demonstrate how to print them out. 
     */
    int i21 = 21;
    int i24 = 24;

    /* 
     * Print the results of addition, subtraction, and multiplication. We are using the
     * "printf" function which is defined in the standard c library "stdio.h". This 
     * function lets us define a "format" and then the computer replaces the format 
     * with the value of a variable. For now, there are four important format options
     * you need to know. 
     * 
     *   1. '%c" = format the variable as a character
     *   2. '%i' = format the variable as an integer
     *   3. '%f' = format the variable as a floating point (rational) number
     *   4. '%x' = format the variable in scientific notation
     */
    printf("i21 + i24 = %i\n", i21 + i24);
    printf("i21 - i24 = %i\n", i21 - i24);
    printf("i21 * i24 = %i\n", i21 * i24);

    /* 
     * Print the results of division and modulo. Modulo is an operation performed
     * on integers. It returns the remainder of the division of the first number
     * by the second number. 
     */
    printf("i21 / i24 = %i\n", i21 / i24);
    printf("i21 %% i24 = %i\n", i21 % i24);

    /*
     * Floating point numbers (rational numbers)
    */
    float f1_1 = 1.1f;
    float f2_0 = 2.0f;
    printf("f1_1 + f2_0 = %f\n", f1_1 + f2_0);
    printf("f1_1 - f2_0 = %f\n", f1_1 - f2_0);
    printf("f1_1 * f2_0 = %f\n", f1_1 * f2_0);
    printf("f1_1 / f2_0 = %f\n", f1_1 / f2_0);

    /*
     * Characters. Characters are a little strange because they are letters, 
     * but also numbers. To understand this, you need to think about ASCII encoding
     * (https://www.asciitable.com/). Every letter is really just a number that the 
     * computer assigned to represent that letter. Since they are numbers under the covers, 
     * you can still do normal math operations on them. Just keep in mind that the results
     * may not always make sense. 
    */
    char c_b = 'B';
    char c_c = 'C';
    printf("c_b + 1 = %c\n", c_b + 1); /* capital B is 65\6. Add 1 to get 67 the code for C */
    printf("c_c + 1 = %c\n", c_c + 1);

    printf("c_b + c_c = %c\n", c_b + c_c); /* 66 + 67 = 133, which doesn't represent any letter*/
    printf("c_b - c_c = %c\n", c_b - c_c);
    printf("c_b * c_c = %c\n", c_b * c_c);
    printf("c_b / c_c = %c\n", c_b / c_c);

    printf("c_b = %i and  c_c = %i\n", c_b, c_c); /* print characters formatted as an integer */

    /* 
     * The Standard C Library "limits.h" provides constants to represent the 
     * size and min/max values of various variables tyles. 
     * Print out the values of important constants from limits.h 
    */
    printf("The number of bits in a byte %d\n", CHAR_BIT);

    printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

    printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
    printf("The maximum value of SHORT INT = %d\n", SHRT_MAX); 

    printf("The minimum value of INT = %d\n", INT_MIN);
    printf("The maximum value of INT = %d\n", INT_MAX);

    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);

    printf("The minimum value of LONG = %ld\n", LONG_MIN);
    printf("The maximum value of LONG = %ld\n", LONG_MAX);

    /* 
     * Determine the number of bits required to represent the total unique values for char 
     * Remember the algebra of exponents! 
     *      2^x = y 
     * can be represented as 
     *      x * log (2) = log (y)
     *      x = log (y) / log (2) 
    */
    {
        double totalNumValuesPossible = (double) CHAR_MAX - CHAR_MIN;
        double power = (log(totalNumValuesPossible) / log(2));
        printf("Representing char requires: %f bits\n", round(power));

        /*
         * The sizeof() function is a built-in function in C which shows you how many 
         * bytes are used by a variable. 
         */
        char myVar = CHAR_MAX;
        printf("The sizeof() function returns : %lu for char\n", sizeof(myVar));
    }

    /* determine the number of bits required to represent the possible number of values for short int */
    {
        double totalNumValuesPossible = (double) SHRT_MAX - SHRT_MIN;
        double power = (log(totalNumValuesPossible) / log(2));
        printf("Representing short int requires: %f bits\n", round(power));

        short int myVar = SHRT_MAX;
        printf("The sizeof() function returns : %lu for short int\n", sizeof(myVar));
    }

    /* determine the number of bits required to represent the possible number of values for int */
    {
        double totalNumValuesPossible = (double) INT_MAX - INT_MIN;
        double power = (log(totalNumValuesPossible) / log(2));
        printf("Representing int requires: %f bits\n", round(power));

        int myVar = INT_MAX;
        printf("The sizeof() function returns : %lu for int\n", sizeof(myVar));
    }

    /* determine the number of bits required to represent the possible number of values for long int */
    {
        double totalNumValuesPossible = (double) LONG_MAX - LONG_MIN;
        double power = (log(totalNumValuesPossible) / log(2));
        printf("Representing long requires: %f bits\n", round(power));

        long int myVar = CHAR_MAX;
        printf("The sizeof() function returns : %lu for long int\n", sizeof(myVar));
    }

    /* 
     * Look at representation of floating point numbers. Floating points numbers are
     * strange because they are represented in memory in a special format where a certain
     * number of bits is reserved for the scientific notation exponent value and another portion
     * is reserfved for the significant bits. As such, they don't exactly have a max value, but 
     * we can use the sizeof function to see how many bytes are used to represent them. 
     */
    {
        float myfloat = 34.129f;
        double mydouble = 34.129f;
        printf("The sizeof() function returns : %lu for float\n", sizeof(myfloat));
        printf("The sizeof() function returns : %lu for double\n", sizeof(mydouble));
    }

    /* 
     * Playing with overflow in unsigned character. An unsigned character is represented
     * as 1 byte (8 bits). So, the max value is 2^8 = 255. If we assign the max value 
     * to a variable and add 1, we get an overflow. This means, we've exceeded the max
     * value the variable can hold, and the variable rotates back to zero + the value
     * of the overflow minus 1.  
     */
    {
        unsigned char myuchar = UCHAR_MAX;
        unsigned char myucharo = myuchar+1;
        printf("When we set a char to max value we get %i (0x%X)\n", myuchar, myuchar);
        printf("When we add 1 to a char at max value we get %i (0x%X)\n", myucharo, myucharo);
    }

    /* 
     * Printing floating point numbers. You can display a floating point in floating 
     * point (decimal) notation or scientific notation. If you choose to print a float
     * as an integer, you simply drop off the decimal portion and show the integer part. 
     */
    {
        float myfloat = 123.289f;
        printf("We can print a float as a floating point decimal: %f\n", myfloat);
        printf("We can print a float as scientific notation: %e\n", myfloat);
        printf("We can print a float as an integer: %i\n", (int) myfloat);
    }

    /*
     * Any variable can be defined as a constant which means it cannot be changed 
     * after it is assigned.
    */
    const int ci = 15;
    /* If we wrote the statement below, the compiler would give us an error. 
    ci = 20;
    */

    return(0);
}