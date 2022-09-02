#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

/* 
 * Program 11 : Challenge - Write a function that displays the memory of an array
 * The function will receive an integer array and its size then print out 
 * a table to the screen which looks like this: 
 * 
 *  Idx         Mem         Adr           b1  b2  b3  b4
 *         --------------
 * [000]   | 0x02e192c9 |   0x16b4f7468   c9  92  e1  02
 *         --------------
 * [001]   | 0x276bcb99 |   0x16b4f746c   99  cb  6b  27
 *         --------------
 * [002]   | 0x1603be07 |   0x16b4f7470   07  be  03  16
 *         --------------
 * [003]   | 0x4fb0c8db |   0x16b4f7474   db  c8  b0  4f
 *         --------------
 * 
 * Column 1 (Idx)   - the index of the element
 * Column 2 (Mem)   - the content of the 4 byte block starting at the address 
 *                    of the index in hexidecimal (printf format %x)
 * Column 3 (Adr)   - the address of the first byte of the 4 byte block
 * Colunn 4 (b1-b4) - the contents of each byte of the 4 byte integer in hex
 *                    where byte 1 is the byte addressed by the address of the
 *                    index.
 */

/*
 * Function printmem
 * This function takes an integer array and the size of the array.
 * It prints a memory table to the screen.
 */
void printmem (int a[], int size){

    printf(" Idx        Mem        Adr           b1  b2  b3  b4\n");
    printf("      --------------\n");
    for(int i = 0; i < size; i++){
        /* 
         * For each element of the int array, initialize a pointer with the 
         * address of the index. Cast to a 1 byte pointer (an unsigned char). 
         * Use pointer arithmetic to get the address of each component byte of 
         * the 4-byte integer. Then dereference to get the value stored in 
         * that byte. 
         */
        unsigned char* ptr = (unsigned char*) &a[i];
        unsigned char byte1 = *ptr;
        unsigned char byte2 = *(ptr+1);
        unsigned char byte3 = *(ptr+2);
        unsigned char byte4 = *(ptr+3);

        printf("[%03i] | 0x%08x |   %p   %02x  %02x  %02x  %02x\n", 
            i, a[i], &a[i], byte1, byte2, byte3, byte4);
        printf("      --------------\n");
    }
    printf("\n");
}

int main(){
    /* Construct and initialize an array of size "SIZE" */
    int a[SIZE] = {0}; 

    srand(time(NULL));

    /* Loop and initialize the array with random numbers. */
    for(int i = 0; i < SIZE; i++){
        a[i] = rand();
    }

    /* Call the printmem function */
    printmem(a, SIZE);
    return 1;
}