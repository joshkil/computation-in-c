
#include <stdio.h>

/* 
 * Pointers Arithmetic. 
 * In this program, I am experimenting with pointer arithmetic to help you
 * understand the relationship between arrays and pointers. The goal is to 
 * help you get more comfortable with pointers, memory addresses, and arrays. 
 * The more you understand about this important concepts, the easier it will 
 * be to write powerful programs and to debug errors that are going to occur
 * when you make mistakes. It can be a little challenging at first, but just 
 * keep experimenting and reviewing these examples. It will become more clear
 * as you practice. 
 */

int main(){

    /*
     * When you delcare a pointer, you are creating a special type of variable. 
     * Because you used the special '*' symbol in the declaration, the compiler
     * treats your variable in special ways when you use math operators. 
     * 
     * First, let's understand how arrays and pointers relate. Below, I show you 
     * two techniques to get a pointer (an address) of the first element of an 
     * array. 
     */

    int a10 [10] = {0};
    int* ptr1 = a10;
    int* ptr2 = &a10[0]; 
    printf("ptr1 = %p\nptr2 = %p (expect equal values)\n", ptr1, ptr2);
    printf("\n");

    /*
     * Now, let's do some math on these pointers and see what happens. 
     * If you look at the output of this code, you will see that adding 
     * 1 to the pointer gives you the same address as the address
     * of the second element (a100[1]) of the array. 
     * 
     * Conclusion: When you add a number to a pointer, the compiler increases
     * the adress by the size of the data type of the pointer. In this case, 
     * the data type was an int (4 bytes). 
     */
    printf("ptr1 + 1 = %p\n", ptr1 + 1);
    printf("&a100[1] = %p (expect equal values)\n", &a10[1]);
    printf("\n");

    /*
     * Let's prove to oursevles that adding 1 to an integer pointer increases 
     * the address by 4. To do this, you need to understand that the computer
     * prints out addresses in "hexadecimal" notation. To see how much
     * the address increased, we need to convert the pointer to an unsigned 
     * long integer before we do math. To do that, we just add the type 
     * to which we want to convert the pointer in parenthesis before the 
     * varialbe name. This is called "type casting", because it changes a 
     * variable from one type to another. 
     * 
     *                  (unsigned long) ptr1;
     * 
     * NOTE: A pointer variable is stored in 8 bytes of memory. That's the 
     * size of an unsigned long. Eight bytes is 64 bits and 
     *      2^64 = 1.8e19 (possible numbers)
     * In laymans terms, that's 18 followed by 18 zeros. 
     * 1,000                      - thousand    (3  zeros)
     * 1,000,000                  - million     (6  zeros)
     * 1,000,000,000              - billion     (9  zeros)
     * 1,000,000,000,000          - trillion    (12 zeros)
     * 1,000,000,000,000,000      - quadrillion (15 zeros) 
     * 1,000,000,000,000,000,000  - quintillion (18 zeros)
     * 
     * So, there are roughly 18 quintillion possible addresses the computer 
     * can assign. Since each address is 1 byte, then the toal memory size
     * my computer could address is 1.8e19 bytes. There are 1e12 bytes in a 
     * TB (terabyte); so, a modern computer could theoretically address 
     * 
     *           1.8e19 / 1.0e12 = 1.8e7 TB
     *           18,000,000 (18 Million TB) 
     * 
     * In 2022, Seagate's popular external backup drives are between 1 and 5 TB; 
     * so, you'd need quite a few of those (5 to 18 million of them) to exhaust 
     * the address space of your computer. 
     * 
     *    https://www.seagate.com/consumer/backup/backup-plus/#specs
     *  
     */ 

    printf("ptr1 + 1 = %p (%020lu)\n", ptr1 + 1, (unsigned long) (ptr1 + 1));
    printf("ptr1     = %p (%020lu)\n", ptr1,     (unsigned long) ptr1);
    printf("--------------------------------------------- (subtraction)\n");
    printf("           0x%09x (%020li) (expect 4)\n", 
        (unsigned int)((unsigned long) (ptr1 + 1) - (unsigned long) ptr1), 
                       (unsigned long) (ptr1 + 1) - (unsigned long) ptr1);
    printf("\n");

    /*
     * NOTE: The code above is very hard to read. Don't stress too much if you
     * can't understand it easily. In summary, the code converts ptr and (ptr+1)
     * into unsigned long integers so we can perform the math to subtract
     * the adresses represented by ptr and (ptr+1). In the end, we prove that the 
     * difference in the addresses is 4. 
     */

    /* 
     * Arrays are Pointers! 
     * So far we've seen that I can increase the address stored in a pointer
     * by the size of the data type of the pointer simply by adding 1 to the 
     * pointer. 
     * 
     * We've also seen that adding 1 to a pointer gives us the same address 
     * as if we indexed the second element of an array. 
     * 
     * Let's solidify our understanding with some examples of equivalent code. 
     */

    /* 
     * Each statement below is quivalent. 
     * This means that referencing an index of an array is the same as doing 
     * pointer arithmetic on the address of the first element of an array. 
     * In the final 2 statement we see that the name of an array IS a pointer
     * and array style indexes can be applied to pointers. Or said another way, 
     * a pointer to the address of the first element of an array IS an array!  
     */ 
    a10[5] = 100;
    printf("a100[5] = %i (expect 100)\n", a10[5]);
    *(ptr1 + 5) = 101;
    printf("a100[5] = %i (expect 101)\n", a10[5]);
    *(a10 + 5) = 102;
    printf("a100[5] = %i (expect 102)\n", a10[5]);
    ptr1[5] = 103;
    printf("a100[5] = %i (expect 103)\n", a10[5]);
    printf("\n");

    /*
     * Arrays are Contiguous Spaces of Memory. 
     *
     * An array is a named area of contiguous memory. The size and type 
     * of the array determine the amount of memory the computer assigns. 
     * The assigned memory is always one contiguous block. 
     * 
     * The size of the array defined in the block below is equal to 
     * 
     *       sizeof(int) * 10 = 40 bytes (on most computers)
     * 
     * We will prove it to ourselves using pointers. The code below gets a 
     * pointer to the first and last element of the array. Then we subtract 
     * the memory addresses. The difference should be 9 * sizeof(int) on your
     * computer. Why isn't it 10 * sizeof(int)? It's because subtracting the 
     * address of the last element from the first element doesn't account 
     * for the final 4 bites referenced by the address of the last element.
     * The lastelement_address is the beginning of a 4 byte block that 
     * "starts" at that address.    
     * 
     *              Index                              Address
     *                   ------------------     <firstelement_address>
     *                0  |    4 bytes     |               |
     *                   ------------------               |
     *                1  |    4 bytes     |               |
     *                   ------------------               |
     *                2  |    4 bytes     |               |
     *                   ------------------               |
     *                3  |    4 bytes     |               |
     *                   ------------------               |
     *                4  |    4 bytes     |               | --> 36 bytes between the 
     *                   ------------------               |     firstelement_address and 
     *                5  |    4 bytes     |               |     lastelement_address. 
     *                   ------------------               |
     *                6  |    4 bytes     |               |
     *                   ------------------               |
     *                7  |    4 bytes     |               |
     *                   ------------------               |
     *                8  |    4 bytes     |               |
     *                   ------------------     <lastelement_address>
     *                9  |    4 bytes     |               | --> These final 4 bytes are not 
     *                   ------------------                     counted when I simply subtract 
     *                                                          the lastelement_address from 
     *                                                          the firstelement_address.
     */

    int* firstelement = &a10[0];
    int* lastelement = &a10[9];
    unsigned long memdiff = (unsigned long)lastelement - (unsigned long)firstelement;

    printf("Address of array2[0] = %p\nAddress of array2[9] = %p\n",
        firstelement, lastelement);
    printf("Difference between addresses: %lu\n", memdiff);
    printf("\n");

    return 1;
}