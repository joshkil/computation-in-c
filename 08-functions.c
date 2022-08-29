#include <stdio.h>

/*
 * Program 08 : Functions
 * In this program we take a look at defining functions. We define two functions and then 
 * use them in the main program (also a function called 'main') to simplify our code. 
 */


/*
 * Function: will_it_fit(...)
 * In this function we take 6 arguments. The first three are the 
 * width (w), length (l), and height (h) of an item. The second three
 * are the width (bw), length (bl), and height (bh) of a box. The function
 * returns true (a non-zero value) if the item fits and false (0) otherwise. 
 */
int will_it_fit(int w, int l, int h, int bw, int bl, int bh){
    int itfits = 0; 
    if(w <= bw && l <= bl && h <= bh){
        itfits = 1;
    }
    return itfits; 
}

/*
 * Function: print_msg(...)
 * This function print a message to the screen. It has a single argument box_number which 
 * indicates which box to mention in the message. 
 */
void print_msg(int box_number){
    printf("Your lamp will fit into box %i\n", box_number);
    return; /* notice how our return statement doesn't specify any value or variable. */ 
}

/*
 * The main function is a program to test whether an item will fit into one of three boxes. 
 * The program prints out which boxes the item will fit into. 
 */

int main(){

    /* define the width, length, and depth of 3 shipping boxes */ 

    int width_box1 = 10;
    int length_box1 = 30;
    int depth_box1 = 20;

    int width_box2 = 20;
    int length_box2 = 20;
    int depth_box2 = 40;

    int width_box3 = 20;
    int length_box3 = 30;
    int depth_box3 = 40;

    /* imagine we asked the user for the size of an item they wanted to store */

    int width_lamp = 15;
    int length_lamp = 10;
    int depth_lamp = 25;

    /* 
     * What code would we need to write to determine if the user's item, a lamp,
     * will fit in our boxes? Consider the code below. 
     */

    if(width_lamp <= width_box1 && 
       length_lamp <= length_box1 &&
       depth_lamp <= depth_box1){

        printf("Your lamp will fit into box 1\n");
    }

    if(width_lamp <= width_box2 && 
       length_lamp <= length_box2 &&
       depth_lamp <= depth_box2){

        printf("Your lamp will fit into box 2\n");
    }

    if(width_lamp <= width_box3 && 
       length_lamp <= length_box3 &&
       depth_lamp <= depth_box3){

        printf("Your lamp will fit into box 3\n");
    }

    /* 
     * What do you think of the code above? It was a little tideous to write and read, 
     * and it repeats the exact same statements 3 times: 
     * 
     *      if(width_lamp <= width_boxN && 
     *          length_lamp <= width_boN &&
     *          depth_lamp <= depth_boxN){
     * 
     *          printf...
     *      }
     * 
     * This is a great example of when defining a function can 
     * help us simplify our code and reduce repetition in our program.
     * In the next lines, we re-write this code using our function 
     * will_it_fit(). 
     * 
     * Notice that we define a variable 'itfits' which is in the scope of the main function. 
     * We also defined a variable with this name in the scope of the will_if_fit function. 
     * These two variable are not related from the perspective of the computer. They are in 
     * differnt scopes and do not affect one another. The only reason the variable 'itfits', 
     * which is local to main ends up with the same value as the variable 'itfits' in 
     * the function will_it_fit is because we assign the return value of the function to our 
     * local itfits variable in the main function. 
     * 
     */

    int itfits = 0;
    itfits = will_it_fit(width_lamp, length_lamp, depth_lamp, width_box1, depth_box1, depth_box1);
    if(itfits){

        printf("Your lamp will fit into box 1\n");
    }

    itfits = will_it_fit(width_lamp, length_lamp, depth_lamp, width_box2, depth_box2, depth_box2);
    if(itfits){

        printf("Your lamp will fit into box 2\n");
    }

    itfits = will_it_fit(width_lamp, length_lamp, depth_lamp, width_box3, depth_box3, depth_box3);
    if(itfits){

        printf("Your lamp will fit into box 3\n");
    }

    /* 
     * What do you think of the rewritten code above? Though it's not much shorter, we avoid 
     * rewriting the same comparison statements again and again. That's what makes the rewrite better. 
     * Why is it better? Well, imagine after testing our packaging, we realized that items need a 1 inch
     * clearance to pack well into each box. We'd need to adjust our logic to test if an item will fit. 
     * In the rewritten code which uses a function, we can simply adjust code in the function to account 
     * for the extra inch we require. We only have to change the code in one spot! That makes our software
     * easier to maintain and less error prone. 
     * 
     * We are going to re-write this code one more time and make use of another function called print_msg(). 
     * The print_msg() function is unique because it doesn't have any return value. It just prints a message
     * to the screen for us. Look how we use this second function to even further simplify our code.  
     */

    itfits = will_it_fit(width_lamp, length_lamp, depth_lamp, width_box1, depth_box1, depth_box1);
    if(itfits){
        print_msg(1);
    }

    itfits = will_it_fit(width_lamp, length_lamp, depth_lamp, width_box2, depth_box2, depth_box2);
    if(itfits){
        print_msg(2);
    }

    itfits = will_it_fit(width_lamp, length_lamp, depth_lamp, width_box3, depth_box3, depth_box3);
    if(itfits){
        print_msg(3); 
    }

    return 1;
}