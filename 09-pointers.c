#include <stdio.h>

/*
 * Define a function to receive an integer passed-by-value. Increase the value of the 
 * local integer by one and return its value. 
 */
int increase_by_one(int val){
    val = val + 1;
    return val;
}

/*
 * Define a function to receive an integer passed-by-reference. Increase the value of the 
 * remote integer by one and return its value. This version of the function will alter the 
 * value of the variable whose pointer was passed as an argument. 
 */
int increase_by_one_v2(int* val){
    *val = *val + 1;
    return *val;
}

int main(){

    /*
     * We create two integer variables and use the address operator '&' to store their memory
     * addresses in two integer pointers. 
     */
    int a = 10; 
    int b = 20; 
    int* ptr_a = &a;
    int* ptr_b = &b; 

    /*
     * Using our variable names and pointers, we can show the values and the addresses of 
     * variables a and b. Notice in the second statement that we use the '*' de-reference 
     * operator to get the value of variable b using pointer-b. 
     */
    printf("The variable a is stored in address %p and has the value %i\n", ptr_a, a);
    printf("The variable b is stored in address %p and has the value %i\n", ptr_b, *ptr_b);

    /*
     * When we de-reference a pointer, we can alter the value of the variable to which it points 
     */
    *ptr_a = *ptr_a + 1;
    printf("The variable a is stored in address %p and has the value %i (expect 11)\n", ptr_a, a);

    /*
     * We can change the address stored in a pointer by assigning it to the value of another pointer. 
     */
    ptr_b = ptr_a;
    printf("pointer-a and pointer-b are now equal. ptr_a = %p and ptr_b = %p\n", ptr_a, ptr_b);

    /*
     * Since pointer-b now equals pointer-a, they both point to the same thing. They both point
     * to the variable a. I can use the ptr_b to change the value of variable a.  
     */
    ptr_b = ptr_a;
    *ptr_b += 10;
    printf("I used pointer-b to add 10 to the variable a. a = %i (expect 21)\n", a);

    /*
     * Pointers in Functions
     * In the next sections, we use pointers in the signature of a function to alter and 
     * demonstrate the difference between pass-by-value and pass-by-reference argument 
     * types. 
     */

    /*
     * In the next block of code, we don't get the result we expect. The computer will 
     * print 10 to the screen because the variable "val" scoped to the main function 
     * is not altered by the function increase_by_one
     */

    int val = 10;
    increase_by_one(val);
    printf("val = %i (expect 10)\n", val);

    /*
     * In this block of code, we get the results we expect. The computer will print 11. 
     * This code works because we assign (copy) the value returned by the function into 
     * the variable "val" scoped to the main function. 
     */
    val = increase_by_one(val);
    printf("val = %i (expect 11)\n", val);

    /*
     * In the next code block, we use version 2 of our function, "increase_by_one_v2". 
     * The result is that the computer prints 11 and then 12. Even if we don't assign
     * the return value to the var variable, the varialbe is still incremented because we
     * passed the variable by reference into the function. The function was able to 
     * alter the actual variable. 
     */ 
    val = 10;
    increase_by_one_v2(&val);
    printf("val = %i (expect 11)\n", val);
    val = increase_by_one_v2(&val);
    printf("val = %i (expect 12)\n", val);
    return 1; 
}
