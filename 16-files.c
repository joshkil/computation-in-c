#include <stdio.h>
#include <string.h>

/*
 * File Input and Output
 * In this program, I show you how to open, read, write, and close files in a c program. 
 * Until now, the programs in this series have only used computer memory, and that means
 * when the program exits, all the work and calculations we've done are discarded. If
 * you want to write programs that "remember things" even after the program has exited, 
 * you need to learn how to use files. 
 * 
 * Files must be read into memory before they can be accessed by the program. Since files
 * can potentially be much larger than available memory on a computer system, the tools
 * for accessing the data in files are based on reading a little bit of the file at a time. 
 * In this way, accessing a file is more like using a book. You have to move to the location
 * in the book you want to read before you can start reading. 
 * 
 */

#define TEXT_DICT_FILE_NAME "../computing-foundations/16-words_alpha.txt"
#define OUT_FILE_NAME "../out/results.txt"
#define WORD_SUFFIX "tion"
#define BIN_FILE_NAME "../out/mybin"

struct Entry {
    char name [100];
    int age;
};


int main(void){

    /* 
     * In the next block of code, I access a file containing a list of 300K english words. 
     * The file (16-words_alpha.txt) has one word for each line. You can open the file in 
     * a text editor to see how it is formatted. Afer I open the file, I step through each
     * line of the file looking for words that end in WORD_SUFFIX. You can see the value
     * of WORD_SUFFIX above, as its a declared constant. 
     * 
     */
    int wrdcnt = 0; 
    int sfxwrdcnt = 0;
    /* 
     * I create a character array to read in each line of the file. The longest word 
     * in English is 45 characters; so, an array of 50 characters will be enough 
     * */
    char w [50] = "";

    /* Now open two files. One is the dictionary, and the second is a file where I will
     * write out all the words I find which end in WORD_SUFFIX
     */
    FILE* words = fopen(TEXT_DICT_FILE_NAME, "r");

    /* After you open a file, check for NULL. If the file failed to open, the 
     * perror function will "print the error" that occurred. 
     */
    if (words == NULL){ 
        perror (TEXT_DICT_FILE_NAME);
        return 0;
    }

    FILE* out = fopen(OUT_FILE_NAME, "w");
    if (words == NULL){ 
        perror (OUT_FILE_NAME);
        return 0;
    }

    while((fgets(w, 50, words)) != NULL){
        wrdcnt++;
        /* I subract two here to account for the face that each line of my dictionary
         * file is terminated with a \n\r character sequence. Depending on which operating
         * system was used to create a text file, each line could have a different line termination
         * characters. One way to check the contents of a file is with the command 
         *          od -xa <file_name> | head
         * 
         * 0000000      0d61    610a    0d61    610a    6161    0a0d    6161    0d68
         *              a  \r  \n   a   a  \r  \n   a   a   a  \r  \n   a   a   h  \r
         * 0000020      610a    6861    6465    0a0d    6161    6968    676e    0a0d
         *              \n   a   a   h   e   d  \r  \n   a   a   h   i   n   g  \r  \n
         * 
         * This command will show you the data in hexadecimal that is contained in the file. 
         * Notice how after each word there is a '\r' and '\n' character. 
         */
        int sfxstart = strlen(w) - strlen(WORD_SUFFIX) - 2;
        if(sfxstart >= 0 && strncmp(&w[sfxstart], WORD_SUFFIX, strlen(WORD_SUFFIX)) == 0){
            sfxwrdcnt++;
            /* This next line writes the word I found into the out file */
            fputs(w, out);
        }
    }
    fclose(words);
    fflush(out);
    fclose(out);

    printf("Searched %i words\n", wrdcnt);
    printf("Found %i words ending %s\n", sfxwrdcnt, WORD_SUFFIX);

    /* In this next block of code, I demonstrate how to write binary data to a file
     * I create a struct, fill it with in formation, then write its data to my file. 
     * In order to demonstrate how reading and writing work, first I check if my out
     * file exists. If you are running this program for the first time, the out file
     * will not exist. When the file doesn't exist, I create it and add the data to 
     * the file. The next time you run the program, the file will exist and in this case
     * I will open it, read the contents, and print them to the screen. This is intended
     * as a demonstration of how you can write a state into a file so when your program 
     * opens the next time, you can pick back up where you left off. 
     */

    struct Entry e;
    FILE* bin = fopen(BIN_FILE_NAME, "rb");
    if (bin == NULL){ 
        /* file was empty, let's write it. */
        strcpy(e.name, "Joshua Kilpatrick");
        e.age = 45;

        printf("The binary file was empty. We are writing it now.\n");
        printf("The next time you run this program, we will read it.\n");

        FILE* bin = fopen(BIN_FILE_NAME, "wb");
        if(bin == NULL){
            perror(BIN_FILE_NAME);
            return 0;
        }
        if(!fwrite(&e, sizeof(struct Entry), 1, bin)){
            perror(BIN_FILE_NAME);
            printf("Failed to write binary file.\n");
        }
        fflush(bin);
        fclose(bin);
    }else{
        printf("Binary File Exists. Opening...\n");
        if(fread(&e, sizeof(struct Entry), 1, bin)){
            /* we read an Entry struct from the file */
            printf("The binary file %s contained: \n", BIN_FILE_NAME);
            printf("Name: %s\n", e.name);
            printf("Age: %i\n", e.age);
        }else{
            printf("Something is wrong. We didn't read the entry we expected.\n");
        }
    
    }
    fclose(bin);

}