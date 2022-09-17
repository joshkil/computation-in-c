#include <stdio.h>
#include <string.h>

/*
 * Structures and Enumerations
 * In this program, I demonstrate how to define and use Structures and 
 * Enumerations. Both are tools in the c language for creating user-defined
 * types. After you create your own type, you instantiate (create) variables
 * of that type. User defined types are a powerful tool to help you organize
 * your programs and make them easier to read. 
 */

/*
 * Enumerations are defined using the 'enum" keyword. 
 *   enum <type-name> { <values> }; 
 * 
 * My enum below is called "Months". It defines 12 values that can be 
 * assigned to any variable of type "Months". I set the first value to 
 * 1. This results in each other value getting an increasing value starting
 * from 1. Assigning a specific integer value to enum values is optional, but
 * you might find it handy if you want to use the values in your program. 
 * For instance, the month "january" is often represented as a "1" when you 
 * print out a date; so, by giving it the value 1, I can more easily print
 * out the enum values in a meaningful way.  
 */

enum Months {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

/*
 * Structures
 * In the code block below, I define two structures. When you define a structure
 * you are grouping together a set of variables of potentially various types. 
 * My first structure is designed to store an entry in a phonebook. My second
 * structure is defined to represent the phonebook itself. It contains an 
 * array of structures of type Entry to hold the various entries of the phonebook. 
 */

struct Entry {
    char firstname[16];
    char lastname[21];
    char phone[17];
    int age;
    enum Months birthmonth;
};

struct Phonebook {
    struct Entry entries[100];
    int size;
};

/*
 * updateentry(struct Entry* e, char fname[], char lname[], char phone[], 
 *  int age, enum Months birthmonth)
 * The updateentry function takes a pointer to an Entry structure and updates
 * its fields as specified by the parameters of the function. 
 */

void updateentry(struct Entry* e, char fname[], char lname[], char phone[], 
    int age, enum Months birthmonth){
    strncpy(e->firstname, fname, 16);
    strncpy(e->lastname, lname, 21);
    strncpy(e->phone, phone, 17);
    e->age = age;
    e->birthmonth = birthmonth;
}

/*
 * printph(struct Phonebook* pb)
 * Print the entries of the phonebook, one entry on each line. 
 * I choose to pass the phonebook by reference not because I want to change
 * its value but because I don't want to make a copy of it. I add a special 
 * keyword called "const" infront of the parameter definition. This tells the 
 * compiler and other programmers who use my function that the function must 
 * not (cannot) alter the memory referenced by the pointer. If you try to 
 * make an assignement (= operator), the compiler will issue an error. 
 */
void printph(const struct Phonebook* pb){
    for(int i = 0; i < pb->size; i++){
        printf("%s, %s, %s, (age: %i), (birthmonth: %i)\n", 
            pb->entries[i].firstname,
            pb->entries[i].lastname,
            pb->entries[i].phone,
            pb->entries[i].age,
            pb->entries[i].birthmonth
            );
    }
}

/*
 * A main program to utilize the new structures and enumerations I've defined
 * above. First, I show you how to create a variable of type Phonebook and
 * then directly manipulate it. Next, we pass a pointer to our phonebook 
 * into the updateentry and printph functions. 
 */
int main(void){

    struct Phonebook ph;
    ph.size = 0;

    strncpy(ph.entries[0].firstname, "Josh", 16);
    strncpy(ph.entries[0].lastname, "Kilpatrick", 21);
    strncpy(ph.entries[0].phone, "+1 251-215-9256", 17);
    ph.entries[0].age = 45;
    ph.entries[0].birthmonth = nov;
    ph.size += 1;

    updateentry(&ph.entries[1], "Josh", "Kilpatrick", "+1 251-215-9256",
        45, nov);
    ph.size += 1;

    printph(&ph);

    return 0;
}