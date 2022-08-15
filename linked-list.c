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

struct Node* findprev(struct List* list, int val){
    struct Node* prev = NULL;
    if(!list) return prev;
    struct Node* cur = list->head;
    while(cur){
        if(val < cur->val) {
            /* the value to insert goes before cur node  */
            break;
        } 
        else{
            /* continue moving through the list */
            prev = cur;
            cur = cur->next;
        }
    }
    return prev;
}

void addvalue(struct List* list, int val){
    if(!list) return;
    /* construct and initialize new node */
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node*));
    printf("malloc: %p\n", newnode);
    newnode->val = val;
    newnode->next = NULL;

    /* locate the node in the current list that will proceed newnode */
    struct Node* prev = findprev(list, val);
    if(prev){
        /* the new node does not belong at the head of list */
        /* option to eliminate duplicates - uncomment next line */
        /* if(prev->val == val) return; */
        newnode->next = prev->next;
        prev->next = newnode;
    }else{
        /* the new node belongs at head of list */
        newnode->next = list->head;
        list->head = newnode;
    }
    list->size += 1;
}

void removevalue(struct List* list, int val){
    if(!list || !list->head) return;
    struct Node* cur = list->head;
    struct Node* prev = NULL;
    while(cur){
        if(cur->val == val){
            if(prev){
                prev->next = cur->next;
                free(cur);
            }else{
                /* node to remove is head */
                list->head = list->head->next;
                free(cur);
            }
            list->size -= 1;
            break;
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
}

void printlist(struct List* list){
    if(!list) return;
    printf("list size: %i\n", list->size);
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

    for(int i = 0; i<100; i++){
        if(rand()%2){
            removevalue(l,i);
        }
    }
    printlist(l);
    return 0; 
}