#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
 * getrandscroe - get a random score between 1 and 10
 */
int getrandscore(){
    return (rand() % 11);
}

void printteam(int team, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9){

    printf("-------------|----|----|----|----|----|----|----|----|\n");
    printf("Team %i > %4i|%4i|%4i|%4i|%4i|%4i|%4i|%4i|%4i|\n", team, i1, i2, i3, i4, i5, 
        i6, i7, i8, i9);

}

int main(){
    /* define variables for team 1 */
    int t1i1=0, t1i2=0, t1i3=0, t1i4=0, t1i5=0, t1i6=0, t1i7=0, t1i8=0, t1i9=0;
    
    /* define variables for team 2 */
    int t2i1=0, t2i2=0, t2i3=0, t2i4=0, t2i5=0, t2i6=0, t2i7=0, t2i8=0, t2i9=0;
    
    srand(time(NULL));

    printf("Initial Score Board:\n");
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 1);
    t1i1 = getrandscore();
    t2i1 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 2);
    t1i2 = getrandscore();
    t2i2 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 3);
    t1i3 = getrandscore();
    t2i3 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 4);
    t1i4 = getrandscore();
    t2i4 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 5);
    t1i5 = getrandscore();
    t2i5 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 6);
    t1i6 = getrandscore();
    t2i6 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 7);
    t1i7 = getrandscore();
    t2i7 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 8);
    t1i8 = getrandscore();
    t2i8 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    printf("Score Board (Inning %i):\n", 9);
    t1i9 = getrandscore();
    t2i9 = getrandscore();
    printteam(1, t1i1, t1i2, t1i3, t1i4, t1i5, t1i6, t1i7, t1i8, t1i9);
    printteam(2, t2i1, t2i2, t2i3, t2i4, t2i5, t2i6, t2i7, t2i8, t2i9);
    printf("\n\n");

    return 1;
}