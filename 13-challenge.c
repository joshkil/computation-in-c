#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100
#define FIRST_NAME_LENGTH 16
#define LAST_NAME_LENGTH 21
#define PHONE_NUMBER_LENGTH 17 /* [+nn] nnn-nnn-nnnn = 16 chars */
#define ADD_OP 'a'
#define DISPLAY_OP 'd'
#define QUIT_OP 'q'

void printpb(char first[][FIRST_NAME_LENGTH], char last[][LAST_NAME_LENGTH], 
             char phone[][PHONE_NUMBER_LENGTH], int size){

    for(int i = 0; i < size; i++){
        char name[FIRST_NAME_LENGTH + LAST_NAME_LENGTH + 1] = "";
        int numchars = 0;
        strncat(name, &first[i][0], FIRST_NAME_LENGTH);
        strcat(name, " ");
        strncat(name, &last[i][0], LAST_NAME_LENGTH);
        printf("%-35s : %14s\n", name, &phone[i][0]);
    }
}

int add(char first[][FIRST_NAME_LENGTH], char last[][LAST_NAME_LENGTH], 
    char phone[][PHONE_NUMBER_LENGTH], int size){
    char* read = NULL;
    char* newline = NULL;
    char c = '\0';
    printf("Enter first name: ");
    read = fgets(&first[size][0], FIRST_NAME_LENGTH, stdin);
    if((newline = strchr(read, '\n'))){ *newline = '\0'; }
    else while((c = getchar()) != '\n' && c != EOF) /* discard */;

    printf("Enter last name: ");
    read = fgets(&last[size][0], LAST_NAME_LENGTH, stdin);
    if((newline = strchr(read, '\n'))){ *newline = '\0'; }
    else while((c = getchar()) != '\n' && c != EOF) /* discard */;
   
    printf("Enter phone: ");
    read = fgets(&phone[size][0], PHONE_NUMBER_LENGTH, stdin);
    if((newline = strchr(read, '\n'))){ *newline = '\0'; }
    else while((c = getchar()) != '\n' && c != EOF) /* discard */;

    return size+1;
}

int main (void){

    char firstname[MAX_ENTRIES][FIRST_NAME_LENGTH];
    char lastname [MAX_ENTRIES][LAST_NAME_LENGTH];
    char phone[MAX_ENTRIES][PHONE_NUMBER_LENGTH];
    int size = 0;
    char option;

    do{
        printf("PHONE BOOK\n");
        printf("enter 'a' to add, 'd' to display, 'q' to quit: ");
        scanf(" %c", &option);
        getchar();

        switch (option) {
            case ADD_OP: 
                if(size < MAX_ENTRIES){
                    size = add(firstname, lastname, phone, size);
                }else{
                    printf("The phonebook is full. You can't add more entries.\n");
                }
                break;
            case DISPLAY_OP: 
                printpb(firstname, lastname, phone, size);
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