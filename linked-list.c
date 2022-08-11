#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Node {
    struct Node * next;
    int val;
};

struct List {
    struct Node* head;
    int size;
};

struct List* createlist(){
    struct List* newlist = (struct List*) malloc(sizeof(struct List));
    newlist->head = NULL;
    newlist->size = 0;
    return newlist;
}

int addvalue(struct List* list, int val){
    int success = 0;
    if(list->size == 0){
        struct Node* newnode = (struct Node*) malloc(sizeof(struct Node*));
        newnode->val = val;
        list->head = newnode;
        list->size += 1;
        success = 1;
    }else{
        struct Node* cur = list->head;
        struct Node* prev = NULL;
        while(cur){
            if(val < cur->val) {
                /* the value to insert goes before cur node  */
                struct Node* newnode = (struct Node*) malloc(sizeof(struct Node*));
                newnode->val = val;
                if(prev){
                    prev->next = newnode;
                    newnode->next = cur;
                }
                else{
                    /* special case: prev is NULL so we need to insert at the head. */
                    list->head = newnode;
                    newnode->next = cur;
                }
                success = 1;
                break;
            } 
            else{
                /* continue moving through the list */
                prev = cur;
                cur = cur->next;
            }
        }

        if(!success){
            /* we reached the end of the list, insert at tail */
            struct Node* newnode = (struct Node*) malloc(sizeof(struct Node*));
            newnode->val = val;
            newnode->next = NULL;
            prev->next = newnode;
        }
    }

    return success;
}

void printlist(struct List* list){
    if(!list) return;
    struct Node* cur = list->head;
    printf("head -> ");
    while(cur){
        printf("%02i -> ", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    struct List* l = createlist();
    addvalue(l, 1);
    addvalue(l, 3);
    addvalue(l, 4);
    addvalue(l, 2);

    srand(time(NULL));
    for(int i = 0; i<100; i++){
        if(rand()%2){
            addvalue(l,i);
        }
    }
    printlist(l);
    return 0;
}