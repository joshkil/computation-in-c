#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* We will limit this Trie to only 5 letter words because it's focused on the 
 * Wordle game. 
*/
#define WORD_SIZE 6
#define ALPHABET_SIZE 26

struct TrieNode {
    char prefix [WORD_SIZE];
    int isword;
    struct TrieNode* children [ALPHABET_SIZE];
};

struct TrieNode* createnode(void){
    struct TrieNode* t =  malloc(sizeof(struct TrieNode));

    if(!t) exit(1);
    t->prefix[0] = '\0';
    t->isword = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        t->children[i] = NULL;
    }
    return t;
}