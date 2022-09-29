#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Dynamic Memory
 * 
 * In this program, I review how to allocate dynamic memory for 1D and 2D arrays
 * as well as structures. Dynamic memory will be used frequently as we learn about
 * data structures. It can be a little confusing at first; so, spend some time 
 * on this and stay with it until you understand. 
 */

int main (void){

    /*
     * Allocating Memory for Arrays
     * A common use of dynamic memory allocation is to create a block of memory
     * for representing an array. You do this when you don't know the correct size
     * to make the array upfront.
     * 
     * After we've created the memory, we can access each element of the "array" using
     * the brackets [] notation OR pointer arithmetic. In the loop, I show you both
     * ways to access the elements. The first statement sets each element to its 
     * index value. The second statement adds the index value to itself creating
     * a series where the ith element equals 2*i for i from 0 to 19. 
     * 
     * NOTE: After calling malloc (memory allocate) to create memory, it's best to 
     * check the value retured to make sure it's not NULL. If a pointer, ptr, is set 
     * to the NULL value, the expression if(ptr) will be false and the code won't
     * execute. I do the reverse, if the expression if(!ptr) is true I exit the 
     * program because the malloc statement failed. If the computer can't give me 
     * memory, I can't continue the program. 
     *
     */
    int* mymem = malloc(sizeof(int) * 20);
    if(!mymem) exit(1);

    /* Loop through the array setting each element to it's index value */
    for(int i = 0; i < 20; i++){
        mymem[i] = i;

        /* 
         * In the next block of code, I will increment each element by its own
         * value using two different forms for referencing the elements. 
         * A 1D array name decays (converts) to a pointer of the type of the 
         * array (int*). This allows me to use the name of the array like it was
         * a pointer and do pointer arithmetic (mymem + i). On the left-hand-side
         * of this equality statement, I use pointer arithmetic and on the right-hand
         * side, I use traditional bracket notation. Both are valid. 
         */
        *(mymem + i) += mymem[i]; 
    }

    /* print out 10 element of the array per line */
    for(int i = 0; i < 20; i++){
        if(i % 10 == 0) printf("\n");
        printf("%2i ", mymem[i]);
    }
    printf("\n\n");

    /*
     * Allocating Dynamic Memory for a Structure
     * In the next section, I allocate memory for a structure. The sizeof
     * operator will return the number of bytes the structure needs. Once my 
     * memory is allocated, I can proceed to access the structure using the 
     * '->' dereference operator we use for accessing structures from a pointer. 
     */
    struct Id {
        char name[50];
        int age;
        char ssn[10];
    };

    struct Id * myid = malloc(sizeof(struct Id));
    if(!myid) exit(1);
    strcpy(myid->name, "Joshua Kilpatrick");
    myid->age = 44;
    strcpy(myid->ssn, "1112221234");


    /* 
     * Allocating Memory for 2-D Arrays
     * Allocating memory for 2-D arrays requires two steps. There are two common
     * ways to handle this. I will show you each way. 
     * 
     * The first block of code below is a refersher on how to declare a static 
     * 2 dimensional array with 5 rows and 5 columns of data. 
     */

    int matrix [5][5] = {
        {1, 2, 3, 4, 5}, /* matrix[0] */
        {1, 2, 3, 4, 5}, /* matrix[1] */
        {1, 2, 3, 4, 5}, /* matrix[2] */
        {1, 2, 3, 4, 5}, /* matrix[3] */
        {1, 2, 3, 4, 5}  /* matrix[4] */
    };

    /* 
     * As a refresher below, I look through the 2D array I have defined and 
     * increment each item by its current value. So, 1 becomes 2, 2 becomes 4, 
     * 3 becomes 6, ...etc. 
     * 
     * On the left-hand-side of my assignment, I reference the array elements 
     * using the normal bracket syntax, but on the righthand-hand-side I use 
     * pointer arithmetic. If I want to access the item as matrix[i][j], I need
     * to get the address of the very first element (matrix[0][0]) and then 
     * increase the address appropriately to get to the ith row and jth column. 
     * 
     * To do this, I increment by the value i * (num_of_columns) to move to the 
     * ith row. Then I increment by j to get to the jth column of that row. 
     */
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matrix[i][j] += *(&matrix[0][0] + (i * 5) + j);

            /* 
             * In this next statement, I will increment the [i][j] element 
             * by itself. On the left-hand-side I use the normal square bracket
             * notation, on the right-hand-side, I use pointer arithmetic which 
             * merits an explaination. 
             * 
             * Multi-dimensional arrays are best thought of as "arrays of arrays". 
             * The name of the array converts into a pointer to an array. This is 
             * different than a pointer to the first element of an array. The notation 
             * is : 
             *             int (*ptr)[] - a pointer to an integer array
             * 
             * To me, that notation looks really wierd; so, I prefer to write it like: 
             *            
             *             (int[])* ptr - incorrect notation, but feels like a more 
             *                            logical way to write "pointer to array"
             * 
             * When you do pointer arithmatic on a pointer to an array, you increase
             * the address by the size of the array. So, in my 5X5 matrix, the name 
             * of the matrix is a pointer to the first array of 5 integers. If I add
             * 1 to that pointer, I advance the address by 
             * 
             *           5 * sizeof(int) = 20 bytes
             * 
             * This move the pointer past the first array (the first row) and points it 
             * to the second array (the second row) in the array of arrays. 
             * 
             * Now, when I dereference a pointer to an array, I end up with a 1D array,
             * and as I've said before the "name" of a 1D array gets converted into 
             * a pointer to the first element of the array. If I add 1 to a pointer 
             * to an integer, I increase the address by sizeof(int). When I dereference
             * a pointer to an integer, I end up with an integer. 
             * 
             * Step by Step: 
             * 
             *        matrix is an address to the first array of integers in the 5X5 matrix
             * 
             *        A = (matrix + i) - add i * 5 * sizeof(int) to address
             *                         - A is an (int[])*, a pointer to an array
             *        B = *(A)         - dereference the pointer to the array
             *                         - B is an int*
             *        C = B + j        - add j * sizeof(int) to address
             *                         - C is an int*
             *        D = *(C)         - dereference the int pointer to get an integer
             *                         - D is an integer
             */
            matrix[i][j] += *(*(matrix + i) + j); 
        }
    }

    /* print the final matrix to see that each value if 2X itself */
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%2i ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    /* 
     * Option 1 to dynamically allocate a 2D array. 
     * In the next block of code, I show you how to allocate memory for a 2D array
     * using just one call to malloc. I just need to allocate enough size to hold 
     * ROWS * COLUMNS of space. This makes malloc very simple, but since I just 
     * declared a int*, I now have to use pointer math to access each items of 
     * the matrix. I can only use one bracket to address the items. 
     */
    int* dmatrix1 = NULL;
    dmatrix1 = malloc(sizeof(int) * 5 * 5);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            dmatrix1[i * 5 + j] = j + 1;
            dmatrix1[i * 5 + j] += *(dmatrix1 + (i * 5) + j);
        }
    }

    /* print the final matrix to see that each value if 2X itself */
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%2i ", dmatrix1[i * 5 + j]);
        }
        printf("\n");
    }
    printf("\n");

    /* 
     * Option 2 to dynamically allocate a 2D array. 
     * In the next block of code, I show you how to allocate memory for a 2D array
     * using 2 calls to malloc. This makes the calls to malloc a little more 
     * complicated, but the resulting memory can be accessed using the more comfortable
     * double bracket notation to access each row and column. 
     * 
     * We declare an int** variable which is a pointer to a pointer. We then allocate
     * an array of int* (an array of integer pointers) and point our int** to the first
     * location. Next, we loop through each element of the array of int* and allocate
     * a new block of int variables. 
     */

    int** dmatrix2 = NULL;
    dmatrix2 = malloc(sizeof(int*) * 5); /* create enough space for 5 pointers to integers */

    for(int i = 0; i < 5; i++){
        dmatrix2[i] = malloc(sizeof(int) * 5); /* create enough space for 5 integers */
    }

    /* 
     * In the next block fo code, first set each element of each row to j+1. 
     * Next, I use the double bracket notation on the left-hand size of an assignment 
     * and pointer math on the right handside of the assignement to add each 
     * element to itself. 
     * 
     * The first * (pointer dereference) gets a pointer to the row I want to access. 
     * The second * (pointer dereference) gets an integer pointed to by the jth 
     * element of the row. 
     */
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            dmatrix2[i][j] = j + 1;
            dmatrix2[i][j] += *(*(dmatrix2 + i) + j); 
        }
    }

    /* print the final matrix to see that each value if 2X itself */
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%2i ", dmatrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");


}