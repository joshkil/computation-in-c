#include <stdio.h>
#include <string.h>

/* 
 * Challenge 13 : Write a program to store and display a simple addressbook. 
 * The program allows users to add new entires to the address book and to
 * display the addressbook. 
 * 
 * Each entry in the addressbook is a firstname, lastname, and phone number. 
 * The phonebook supports 100 entires, firstnames up to 15 characters,
 * lastnames up to 20 characters, and phone numbers  up to 16 characters. 
 * 
 * The program has three commands the user can enter: 
 * 
 *    'a' = add an entry
 *    'd' = display phone book
 *    'm' = display memory for a selected region
 *    'q' = quit the program
 */

#define MAX_ENTRIES 100
#define FIRST_NAME_LENGTH 16
#define LAST_NAME_LENGTH 21
#define PHONE_NUMBER_LENGTH 17 /* [+nn] nnn-nnn-nnnn = 16 chars */
#define ADD_OP 'a'
#define DISPLAY_OP 'd'
#define MEMORY_OP 'm'
#define QUIT_OP 'q'

enum Entrytype {family, friend, work};
const char ENTRY_TYPE_NAMES[3][10] = 
    {"family", "friend", "work"};

struct Entry {
    char firstname[FIRST_NAME_LENGTH];
    char lastname[LAST_NAME_LENGTH];
    char phone[PHONE_NUMBER_LENGTH];
    enum Entrytype type;
};

struct Phonebook {
    struct Entry entries[MAX_ENTRIES];
    int size;
};

/*
 * printpb(char first[][FIRST_NAME_LENGTH], char last[][LAST_NAME_LENGTH], 
 *         char phone[][PHONE_NUMBER_LENGTH], int size))
 * Display a the phonebook to the screen. The first, last, and phone
 * arrays are lists of firstnames, lastnames, and phone numbers which are
 * the entries of the phonebook. The size parameter indicates the current
 * number of entries in the phonebook. 
 *
 */
void printpb(struct Phonebook* pb){

    /* Set-up a loop to run through the current number of entries */
    for(int i = 0; i < pb->size; i++){
        /* concatenate the first and last name together for display */
        char name[FIRST_NAME_LENGTH + LAST_NAME_LENGTH + 1] = "";
        strncat(name, pb->entries[i].firstname, FIRST_NAME_LENGTH);
        strcat(name, " ");
        strncat(name, pb->entries[i].lastname, LAST_NAME_LENGTH);
        printf("%-20s : %16s : %s\n", name, pb->entries[i].phone, 
            ENTRY_TYPE_NAMES[pb->entries[i].type]);
    }
}

/*
 * int add(char first[][FIRST_NAME_LENGTH], char last[][LAST_NAME_LENGTH], 
 *         char phone[][PHONE_NUMBER_LENGTH], int size)
 * Add an entry to the phone book and return the new size. The first, last, 
 * and phone arrays are lists of firstnames, lastnames, and phone numbers 
 * which are the entries of the phonebook. The size parameter indicates the 
 * current number of entries in the phonebook.
 * 
 */
void add(struct Phonebook* pb){
    char* read = NULL;
    char* newline = NULL;
    char c = '\0';

    /* 
     * We prompt the user to enter each element of the entry - firstname, 
     * lastname, and phone number. 
     * 
     * The function we use to read each string is fgets. The function reads
     * from the keyboard until it finds a "\n" (newline) - which is when the 
     * user presses enter. The fgets reference says it will include the 
     * newline in the string it stores. So, we search for the newline and
     * replace it with '\0' to elliminate the newline from our string. We don't 
     * want to print a newline after each element when we display the phonebook. 
     * 
     * If we aren't able to find a newline, it means that the user was still 
     * typing when we reached the max length allowed by our arrays. In this case, 
     * whatever the user may have typed after the max size we allow will still 
     * be in the input buffer. In this case, we execute a small loop to 
     * read the rest of what the user entered and simply throw it away. We could
     * have optionally warned the user that their entry exceeded the maximum 
     * allowed length and try again, but I decided to keep the program simple 
     * and just drop the extra characters. 
     */
    printf("Enter first name: ");
    read = fgets(pb->entries[pb->size].firstname, FIRST_NAME_LENGTH, stdin);
    if((newline = strchr(read, '\n'))){ *newline = '\0'; }
    else while((c = getchar()) != '\n') /* discard */;

    printf("Enter last name: ");
    read = fgets(pb->entries[pb->size].lastname, LAST_NAME_LENGTH, stdin);
    if((newline = strchr(read, '\n'))){ *newline = '\0'; }
    else while((c = getchar()) != '\n') /* discard */;
   
    printf("Enter phone: ");
    read = fgets(pb->entries[pb->size].phone, PHONE_NUMBER_LENGTH, stdin);
    if((newline = strchr(read, '\n'))){ *newline = '\0'; }
    else while((c = getchar()) != '\n') /* discard */;

    printf("Enter category (0-family, 1-friend, 2-work): ");
    scanf("%i", &(pb->entries[pb->size].type));
    getchar();

    pb->size += 1;

    return;
}

/*
 * Function chars
 * This function takes a char pointer and prints bytes of memory
 */
void printchars (char* s, int bytes){

    printf(" Idx      Mem      Adr\n");
    printf("      ------------\n");
    for(int i = 0; i < bytes; i++){
        unsigned char byte = (unsigned char) *(s+i);
        char* addr = s+i;
        printf("[%03i] | 0x%02x (%1c) |   %p \n", i, byte, byte, addr);
        printf("      ------------\n");
    }
    printf("\n");
}

/*
 * Function printmem(struct Phonebook* pb)
 * Print a block of memory starting at the address specified by pb of 
 * the size sizeof(struct Phonebook). The function is designed to 
 * show one byte of memory per line to help visualize how the structure
 * is packed into memory. 
 */
void printmem(struct Phonebook* pb){
    int entrynum = 0;
    printf("The Phonebook has %i entries starting at 0.\n", pb->size);
    printf("What entry to you want to display: ");
    scanf("%i", &entrynum);
    getchar();
    printchars( (char*) (&(pb->entries[entrynum])), sizeof(struct Entry));
}

int main (void){

    printf("Entry Types: %s\n", ENTRY_TYPE_NAMES[0]);

    struct Phonebook pb;
    pb.size = 0;
    char option;

    do{
        printf("PHONE BOOK\n");
        printf("enter 'a' to add, 'd' to display, 'm' to print memory, 'q' to quit: ");
        scanf(" %c", &option);
        getchar();

        /* 
         * A switch statement to check which command the user entered then
         * call the appropriate function to execute that command. 
         */

        switch (option) {
            case ADD_OP: 
                if(pb.size < MAX_ENTRIES){
                    add(&pb);
                }else{
                    printf("The phonebook is full. You can't add more entries.\n");
                }
                break;
            case DISPLAY_OP: 
                printpb(&pb);
                break;
            case MEMORY_OP: 
                printmem(&pb);
                break;
            case QUIT_OP: 
                printf("Goodbye\n");
                break;
            default: 
                printf("Invalid options. Try again.\n");
                break;
        }

    }while(option != QUIT_OP);

    return 0;
}