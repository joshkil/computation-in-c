#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h> 

/*
 * This program helps us visualize the size of various integer types in memory. 
 * We use the maximum and minimum values of each type from limits.h to calculate
 * the number of bits required to represent that many unique values. We also get
 * a look at the sizeof() function which reports the number of bytes in memory
 * represented by a variable. 
*/

int main (){

    /* 
     * I like to say the = operator means 'assign the value of...' 
     * The next statement says, define an integer variable called i21 and assign 
     * the value of 21 
     */
    int i21 = 21;
    int i24 = 24;

    /* print the results of addition, subtraction, and multiplication */
    printf("i21 + i24 = %i\n", i21 + i24);
    printf("i21 - i24 = %i\n", i21 - i24);
    printf("i21 * i24 = %i\n", i21 * i24);

    /* print the results of division and modulo */
    printf("i21 / i24 = %i\n", i21 / i24);
    printf("i21 %% i24 = %i\n", i21 % i24);

    /*
     * Floating point numbers
    */
    float f1_1 = 1.1f;
    float f2_0 = 2.0f;
    printf("f1_1 + f2_0 = %f\n", f1_1 + f2_0);
    printf("f1_1 - f2_0 = %f\n", f1_1 - f2_0);
    printf("f1_1 * f2_0 = %f\n", f1_1 * f2_0);
    printf("f1_1 / f2_0 = %f\n", f1_1 / f2_0);

    /*
     * Characters 
    */
    char c_b = 'B';
    char c_c = 'C';
    printf("c_b + 1 = %c\n", c_b + 1);
    printf("c_c + 1 = %c\n", c_c + 1);

    printf("c_b + c_c = %c\n", c_b + c_c);
    printf("c_b - c_c = %c\n", c_b - c_c);
    printf("c_b * c_c = %c\n", c_b * c_c);
    printf("c_b / c_c = %c\n", c_b / c_c);

    printf("c_b = %i and  c_c = %i\n", c_b, c_c);

    printf("c_b + 1 = %c\n", c_b + 1);
    printf("c_c + 1 = %c\n", c_c + 1);


    /* print out the values of important constants from limits.h */
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

    /* determine the number of bits required to represent the total unique values for char */
    /* Remember the algebra of exponents! 
     *      2^x = y 
     * can be represented as 
     *      x * log (2) = log (y)
     *      x = log (y) / log (2) 
    */
    {
        double totalNumValuesPossible = (double) CHAR_MAX - CHAR_MIN;
        double power = (log(totalNumValuesPossible) / log(2));
        printf("Representing char requires: %f bits\n", round(power));

        char myVar = CHAR_MAX;
        printf("The sizeof() function retunrs : %lu for char\n", sizeof(myVar));
    }

    /* determine the number of bits required to represent the possible number of values for short int */
    {
        double totalNumValuesPossible = (double) SHRT_MAX - SHRT_MIN;
        double power = (log(totalNumValuesPossible) / log(2));
        printf("Representing short int requires: %f bits\n", round(power));

        short int myVar = SHRT_MAX;
        printf("The sizeof() function retunrs : %lu for short int\n", sizeof(myVar));
    }

    /* determine the number of bits required to represent the possible number of values for int */
    {
        double totalNumValuesPossible = (double) INT_MAX - INT_MIN;
        double power = (log(totalNumValuesPossible) / log(2));
        printf("Representing int requires: %f bits\n", round(power));

        int myVar = INT_MAX;
        printf("The sizeof() function retunrs : %lu for int\n", sizeof(myVar));
    }

    /* determine the number of bits required to represent the possible number of values for long int */
    {
        double totalNumValuesPossible = (double) LONG_MAX - LONG_MIN;
        double power = (log(totalNumValuesPossible) / log(2));
        printf("Representing long requires: %f bits\n", round(power));

        long int myVar = CHAR_MAX;
        printf("The sizeof() function retunrs : %lu for long int\n", sizeof(myVar));
    }

    /* look at representation of floating point numbers */
    {
        float myfloat = 34.129f;
        double mydouble = 34.129f;
        printf("The sizeof() function retunrs : %lu for float\n", sizeof(myfloat));
        printf("The sizeof() function retunrs : %lu for double\n", sizeof(mydouble));
    }

    /* Playing with value assignments - integers and characters */
    {
        char mychar1 = 'J';
        char mychar2 = 74;
        char mychar3 = (char) 0x4A;

        printf("The character J as char %c, %c, %c\n", mychar1, mychar2, mychar3);
        printf("The character J as int %i, %i, %i\n", mychar1, mychar2, mychar3);

        int myint1 = 'J';
        int myint2 = 74;
        int myint3 = (char) 0x4A;

        printf("The integer J as char %c, %c, %c\n", myint1, myint2, myint3);
        printf("The integer J as int %i, %i, %i\n", myint1, myint2, myint3);

    }

    /* Playing with overflow - unsigned char */
    {
        unsigned char myuchar = UCHAR_MAX;
        unsigned char myucharo = myuchar+1;
        printf("When we set a char to max value we get %i (0x%X)\n", myuchar, myuchar);
        printf("When we add 1 to a char at max value we get %i (0x%X)\n", myucharo, myucharo);
    }

    /* Assigning floating point numbers */
    {
        float myfloat = 123.289f;
        printf("We can print a float as a floating point decimal: %f\n", myfloat);
        printf("We can print a float as scientific notation: %e\n", myfloat);
        printf("We can print a float as an integer: %p\n", myfloat); /* generates warning */
        printf("We can print a float as an integer: %i\n", (int) myfloat);
    }

    return(0);
}