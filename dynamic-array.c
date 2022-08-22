#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct DynamicArray {
    int size; 
    int length;
    int* a;
};

struct DyanicArray* createarray(int initialsize){
    struct DynamicArray* da = (struct DynamicArray*) malloc(sizeof(struct DynamicArray));
    da->size = initialsize;
    da->length = 0;
    da->a = (int*) malloc(sizeof(int) * initialsize);
    return da;
}

void shift(struct DynamicArray* da, int index){
    if(!da) return;
    for(int j = da->length; j > index; j--){
        da->a[j] = da->a[j-1];
    }
}

void expand(struct DynamicArray* da){
    int newsize = da->size * 2;
    int* newa = (int*) malloc(newsize);
    memcpy(newa, da->a, sizeof(int) * da->size);
    free(da->a);
    da->a = newa;
    da->size = newsize;
}

void addval(struct DynamicArray* da, int val){
    if(!da) return;

    if(da->length == da->size){
        /* need to create a larger array and copy over contents */
        expand(da);
    }

    int insertionindex = da->length;
    /* find insertion point */
    for(int i = 0; i < da->length; i++){
        if(val < da->a[i]){
            insertionindex = i;
            break;
        }
    }

    shift(da, insertionindex);
    da->a[insertionindex] = val;
    da->length += 1;
}

void printarray(struct DynamicArray* da){
    printf("size: %i, length: %i\n", da->size, da->length);
    for(int i = 0; i < da->length; i++){
        printf("%i -> ", da->a[i]);
    }
    printf("[end]\n");
}


int main(){
    struct DynamicArray* da = createarray(100);
    
    addval(da, 1);
    printarray(da);

    addval(da, 3);
    printarray(da);

    addval(da, 2);
    printarray(da);

    srand(time(NULL));
    for(int i = 0; i<500; i++){
        if(rand()%2){
            addval(da,i);
        }
    }
    printarray(da);

    return 1; 
}