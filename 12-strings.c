#include <stdio.h>
#include <strings.h>

/*
 * C Language Strings
 * In this program, I demonstate how to create, inspect, construct, and 
 * operate on strings in the c programming language. A version of the printmem 
 * function from challenge 11 is implemented to asist in showing contents of memory. 
 */

/*
 * Function printmem
 * This function takes a char array and the size of the array.
 * It prints a memory table to the screen.
 */
void printmem (char s[], int size){

    printf(" Idx      Mem      Adr\n");
    printf("      ------------\n");
    for(int i = 0; i < size; i++){
        printf("[%03i] | 0x%02x (%1c) |   %p \n", i, s[i], s[i], &s[i]);
        printf("      ------------\n");
    }
    printf("\n");
}

int main(void){

    /* Part 1: String Initialization and Display */
    printf("Part 1 String Initialization and Display\n");
    printf("-----------------------------------------\n\n");

    char name[] = "Joshua Kilpatrick"; /* this string has 17 characters */
    printf("Size of name: %lu (expect 18)\n", sizeof(name));
    printf("%s\n", name);
    printf("\n");
    printmem(name, (int) sizeof(name));

    char name2[] = {'J', 'o', 's', 'h', '\0'}; /* this string has 4 characters */
    printf("Size of name2: %lu (expect 5)\n", sizeof(name2));
    printf("%s\n", name2);
    printf("\n");
    printmem(name2, (int) sizeof(name2));

    char* ptr = name;
    printf("Print name[] by looping with char* pointer: ");
    while(*(ptr) != '\0'){
        printf("%c", *ptr);
        ptr += 1;
    }
    printf("\n");
    
    ptr = name;
    printf("Print name[] using char* ptr in printf: %s\n", ptr);
    printf("\n");

    char initial = 'J';
    char* firstinitial = &initial;
    printf("Size of firstinitial: %lu (expect 1)\n", sizeof(*firstinitial));
    int numchars = printf("%s.\n", firstinitial);
    printf("num chars printed %i\n", numchars);
    printf("\n");
    printmem(firstinitial, 8);

    /* Part 2: String Inspection Functions */
    /*
     * String Inspection Functions of <string.h>
     * 
     *   strcmp() & strncmp() - compare two strings for equality
     *   strchr() & strstr()  - find a char or string inside a string
     *   strlen()             - get length of a string 
     */
    printf("Part 2 String Inspection Functions\n");
    printf("-----------------------------------------\n\n");

    /* strcmp - a function to compare to strings (POTENTIALLY UNSAFE) */
    printf("strcmp:\n");
    printf("--------\n");
    char fruit[] = "Apple";
    char vegetable[] = "Zuchini";
    printf("strcmp(fruit, vegetable) = %i\n", strcmp(fruit, vegetable));
    printf("strcmp(vegetable, fruit) = %i\n", strcmp(vegetable, fruit));
    printf("strcmp(vegetable, vegetable) = %i\n", strcmp(vegetable, vegetable));
    printf("\n");

    /* 
     * strncmp - a function to compare to strings with a safety mechanism 
     * limiting comparison to a number of bytes 
     */
    printf("strncmp:\n");
    printf("--------\n");
    char desert1[] = "Apple Pie";
    char desert2[] = "Peach Pie";
    char desert3[] = "Apple Strudle";
    printf("strncmp(desert1, \"Apple\", 5) = %i\n", strncmp(desert1, "Apple", 5));
    printf("strncmp(desert2, \"Apple\", 5) = %i\n", strncmp(desert2, "Apple", 5));
    printf("strncmp(desert3, \"Apple\", 5) = %i\n", strncmp(desert3, "Apple", 5));
    printf("\n");

    /* Example Error in comparing two character arrays without null terminators. */ 
    printf("Demonstrate a strcmp error:\n");
    printf("---------------------------\n");
    char buf1[100] = {'A', 'p', 'p', 'l', 'e'};
    char buf2[100] = {'A', 'p', 'p', 'l', 'e'};
    for(int i = 5; i < 100; i++){
        buf1[i] = buf2[i] = ' ';
    }
    printf("strcmp(buf1, buf2) = %i\n", strcmp(buf1, buf2));
    printf("strncmp(buf1, buf2, 100) = %i\n", strncmp(buf1, buf2, 100));

    char buf3[100] = "Hello Friends";
    printf("strlen(buf3) = %lu; sizeof(buf3) = %lu\n", strlen(buf3), sizeof(buf3));
    printf("strlen(buf1) = %lu; sizeof(buf1) = %lu\n", strlen(buf1), sizeof(buf1));
    printf("strlen(buf2) = %lu; sizeof(buf2) = %lu\n", strlen(buf2), sizeof(buf2));

    printf("\n");

    /* finding characters or sub-strings in a string */
    printf("strchr & strstr - find a char or sub-string:\n");
    printf("-------\n");
    char sequence[] = "AbcdefgabcdefgAbcdefg";
    char* fnd = strchr(sequence, 'a');
    if(fnd) printf("Found 'a' in sequence %s\n", sequence);
    fnd = strchr(sequence, 'z');
    if(fnd) printf("Found 'z' in sequence %s\n", sequence);
    else printf("NOT Found 'z' in sequence %s\n", sequence);

    /* 
     * Here's an example loop that will help you find all occurences of 
     * the letter b in the sequence 
     */
    fnd = strchr(sequence, 'b');
    while(fnd){
        printf("Found 'b' at %li\n", fnd-sequence);
        fnd = strchr(fnd+1, 'b');
    }
    
    /* 
     * Here's an example loop that will help you find all occurences of 
     * the substring 'abc' in the sequence 
     */
    fnd = strstr(sequence, "abc");
    while(fnd){
        printf("Found \"abc\" at %li\n", fnd-sequence);
        fnd = strstr(fnd+1, "abc");
    }

    /* Part 3 Reading Strings from the Keyboard */
    /*
     * String input functions of <stdio.h>
     * 
     *   scanf("%s") & fscanf("")
     *   gets() & fgets()
     *   getchar()
     */
    printf("Part 3 Reading Strings from the Keyboard\n");
    printf("-----------------------------------------\n\n");
    char entry [500] = {""};
    printf("Enter you Name: ");
    scanf("%s", entry);
    printf("You entered : %s\n", entry);
    printf("And the following characters were left on the buffer along with a new line: \n");
    char c = '\0';
    while((c = getchar()) != '\n'){
        printf("%c", c);
    };
    printf("\n");

    printf("Enter you Name: ");
    fgets(entry, sizeof(entry), stdin);
    printf("You entered : %s\n", entry);

    /* Part 4 - Constructing Strings */
    /*
     * String construction functions <stringh> & <stdio.h>
     * 
     *   strcpy() & strncpy() - copy one string into another
     *   strcat() & strncat() - concatenate one string onto another
     *   sprintf() & snprintf() - write a formated string 
     */
    printf("Part 4 Constructing Strings\n");
    printf("-------------------------- -\n\n");

    /*
     * In the next block, we see how we can create a string from another
     * string using strcpy - string copy 
     * /
    {
        printf("strcpy & strncpy: \n");
        printf("------------------\n");
        char beginning[100] = "This is the beginning of a sentence, ";
        char end[] = "and this is the end of that sentence.";
        printf("Before (strncpy) beginning = \"%s\"\n", beginning);
        strncpy(beginning, end, sizeof(beginning));
        printf("After (strncpy) beginning = \"%s\"\n", beginning);
    }


    /*
     * In the next block, we see how to concatenate two strings together. 
     */
    {
        printf("strcat & strncat: \n");
        printf("------------------\n");
        char beginning[100] = "This is the beginning of a sentence, ";
        char end[] = "and this is the end of that sentence.";
        printf("Before (strncat) beginning = \"%s\"\n", beginning);
        strncat(beginning, end, sizeof(beginning) - (strlen(beginning) +1));
        printf("After (strncat) beginning = \"%s\"\n", beginning);
    }

    /* 
     * In the next block we see an example of how to avoid errors with strcat. 
     * We create a sample string "beginning" in an array with only enough space
     * for 49 characters plus the null character. We then ask strcat to add 
     * to the end the string "end". The result would likely crash the program
     * if we used strcat because beginning array doesn't have enough space. 
     * To avoid this, we use strncat which allows us to specify the maximum
     * number of characters that can be written into our source. 
     * 
     */
    {
        printf("Example of a strncat to prevent an error :\n");
        printf("----------------------------\n");
        char beginning[50] = "This is the beginning of a sentence, ";
        char end[] = "and this is the end of that sentence.";
        strncat(beginning, end, sizeof(beginning) - (strlen(beginning) +1));
        printf("After (strncat) beginning = \"%s\"\n", beginning);
    }

    /* Here is an example of constructing a string with springf */
    printf("sprintf:\n");
    printf("--------\n");
    char todays_weather [500];
    int maxtemp = 50;
    int mintemp = 85; 
    int humidity = 99;
    int rain = 1;
    snprintf(todays_weather, sizeof(todays_weather), 
        "Today's weather calls for a max temp of %i and min temp of %i with humitidy of %i percent and %i cm of rain.\n",
        maxtemp, mintemp, humidity, rain);
    printf("%s", todays_weather);


    return 0;
}