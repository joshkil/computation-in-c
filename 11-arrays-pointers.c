
#include <stdio.h>

int main(){
    
    /* 
     * Pointers and Arrays. 
     * In the next block of code, I will show how pointers and arrays
     * are related and can be used together. 
     *
     * An array is a named area of memory the size and type of the array
     * determine the amount of memory the computer assigns. The assigned
     * memory is always one consecutive block. 
     * 
     * The array defined in the line below is assigned a number of bytes
     * of memory equal to sizeof(int) * 10
     * 
     * We will prove it to ourselves using pointers. The code below gets a 
     * pointer to the first and last element of the array. Then we subtract 
     * the memory addresses. The difference should be 9 * sizeof(int) on your
     * computer. Why isn't it 10 * sizeof(int)? Just think about it the address
     * of the last element of the array is the start of an integer. 
     * 
     * 
     *                   ------------------     <firstelement_address>
     *                   |    4 bytes     |               |
     *                   ------------------               |
     *                   |    4 bytes     |               |
     *                   ------------------               |
     *                   |    4 bytes     |               |
     *                   ------------------               |
     *                   |    4 bytes     |               |
     *                   ------------------               |
     *                   |    4 bytes     |               | -- 
     *                   ------------------               |
     *                   |    4 bytes     |               |
     *                   ------------------               |
     *                   |    4 bytes     |               |
     *                   ------------------               |
     *                   |    4 bytes     |               |
     *                   ------------------               |
     *                   |    4 bytes     |               |
     *                   ------------------     <lastelement_address>
     *                   |    4 bytes     |
     *                   ------------------
     */

    int array2[10];
    int* firstelement = &array2[0];
    int* lastelement = &array2[9];
    long memdiff = (long)lastelement - (long)firstelement;

    printf("Address of array2[0] = %p. Address of array2[9] = %p\n",
        firstelement, lastelement);
    printf("Difference between addresses: %li\n", memdiff);

    return 1;
}