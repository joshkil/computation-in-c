#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STORAGE_START_SIZE 10
#define STORAGE_GROWTH_RATE 2
#define READ_BUF_SIZE 10


/*
 * Challenge 15 : Create an application to read input from the keyboard until
 * the user types a 'q' (quit) on a single line followed by return. Store the user's input 
 * into a dynamically allocated character array. After the user enters 'q' to quit, print 
 * statistics about the input to the screen. Print the size of input, size of storage array, 
 * and word count in the string. 
 * 
 * HINT: Computing word-count is a little tricky; so, enjoy solving this part of the 
 * problem last. 
 */ 

/*
 * char* nextwhitespace(char* str) - for a null terminated string pointed to 
 * by str, return a pointer to the first occurrence of whitespace. 
 * 
 * Whitespace is defined as a space or newline.
 */
char* nextwhitespace(char* str){

    if(!str) return NULL;

    /* use strchr function to find the first space and new line in str if they exist */
    char* nextspace = strchr(str, ' ');
    char* nextnl = strchr(str, '\n');

    /* 
     * There are three options: 1) we found both a space and a newline, 2) we found only
     * one, or 3) we found neither. If we found both, we return the one that occurred 
     * first. You know a character occurred before another in a string if its pointer
     * address is smaller. 
     */
    if(nextspace && nextnl){
        if(nextspace < nextnl) return nextspace;
        else return nextnl;
    }else{
        if(nextspace) return nextspace;
        else return nextnl;
    }
}

/*
 * int wrdcnt(char* str) - count the words in a null terminated string. 
 * 
 * This function assumes that a word is any letter or symbol surrounded by whitespace. 
 * Whitespace is defined as a space or newline. 
 * 
 * NOTE: The algorithm I use is a little naive, because it will count punctuation 
 * as a word if it stands alone surrounded by whitespace. 
 */
int wrdcnt(char* str){
    if(!str) return 0;
    int wordcount = 0; 

    /* 
     * we set up two pointers. one holds the current whitespace found and the 
     * other holds the prior whitespace found. 
     */
    char* curwspace = str;
    char* prevwspace = str;

    while( (curwspace = nextwhitespace(curwspace)) != NULL ){
        /* 
         * The next statement helps us avoid counting a string of 
         * whitespaces as words. We reuire that the currently found 
         * whitespace be separated from the previously found whitespace
         * by some non-whitespace character
         */ 
        if((curwspace - 1) != prevwspace) wordcount++;
        prevwspace = curwspace;
        curwspace += 1;
    }
    return wordcount;
}

int main(void){
    /* set up a character array to store the user's input */
    int storsize = STORAGE_START_SIZE;
    char* stor = malloc(storsize * sizeof(char));
    if(!stor) exit(1);
    stor[0] = '\0';
    int stortail = 0;

    /* a buffer for reading strings from the keyboard */
    char* buf = malloc(READ_BUF_SIZE * sizeof(char));
    if(!buf) exit(1);
    buf[0] = '\0';

    /* 
     * We will execute an infinite loop until the user enters a 'q' on a single line. 
     * As we read input from the user into our buffer, we will add it to our storage
     * array. If we need more space, we will allocate a new larger array, copy over 
     * the existing data we have stored, and proceed. 
     */
    while(1){
        /* Read from the keyboard and then check to see if the input read into our 
         * buffer is null terminated. If not, we will assume the whole array size 
         * (READ_BUF_SIZE) is full of user input. 
         */
        fgets(buf, READ_BUF_SIZE, stdin);
        int stringlen = 0;
        char* nullchar = strchr(buf, '\0');
        if(nullchar == NULL){
            /* 
             * The buffer doesn't include a null termination. This should not
             * happen, but in this case, we will assume the buffer is full 
             */
            stringlen = READ_BUF_SIZE;
        }else{
            /* the buffer is partially full */
            stringlen = strlen(buf);
        }

        /* EXIT CONDITION: We received the quit command on a single line, exit the loop */
        if(strncmp(buf, "q\n", READ_BUF_SIZE) == 0) break;

        /* 
         * check size of available storage to see if there is room for the new data. 
         */
        if( (storsize - stortail)  <= stringlen){
            /* We need to expand our storage before we can add in the current buf */
            char* newstor = malloc(storsize * STORAGE_GROWTH_RATE * sizeof(char));
            strncpy(newstor, stor, storsize);
            free(stor);
            stor = newstor;
            storsize *= STORAGE_GROWTH_RATE;
        }

        /* add new buffer into storage */
        strncpy(&stor[stortail], buf, stringlen);

        /* 
         * We advance the storage tail variable to the array index just after the 
         * last of the user input. We set that location to the null character to 
         * terminate the string. The variable stortail will always hold the index 
         * where the new buffer of user input will be stored. The "tail" represents
         * the end of our current string in storage. 
         */
        stortail += stringlen;
        stor[stortail] = '\0';
    }

    /* user asked to quit. calculate statistics */
    printf("Storage Size: %i\n", storsize);
    printf("String Length: %lu\n", strlen(stor));
    printf("Word Count: %i\n", wrdcnt(stor));
}