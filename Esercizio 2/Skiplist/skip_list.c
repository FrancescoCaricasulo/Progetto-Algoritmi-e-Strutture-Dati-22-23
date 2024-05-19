#include "skip_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <stddef.h>

typedef struct _node Node;
typedef struct _skiplist Skiplist;

Node *initNode(int size){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = (Node **)malloc(sizeof(Node *) * (size + 1));
    newNode->size = size;

    for(int i = newNode->size; i >= 0; i--){
        newNode->next[i] = NULL;
    }

    return newNode;
}

Skiplist *initSkiplist(Skiplist *list, size_t max_height, int (*compare)(const void*, const void*)){
    list = (Skiplist *)malloc(sizeof(Skiplist));
    list->compare = compare;
    list->level = 0;
    list->header = initNode(max_height);
    list->height = max_height;

    return list;
}

int randomLevel(size_t max_height){
    int level = 0;
    
    while(((double)rand()/RAND_MAX) < 0.5 && level < max_height){
        level++;
    }

    return level;
}

void addItem(Skiplist *list, void *key){
    int rnd_level = randomLevel(list->height);
    Node *new = initNode(rnd_level);
    new->val = key;

    if(new->size > list->level){
        list->level = new->size;
    }


    Node *tmp = list->header;

    for(int i = list->level; i >= 0; i--){
        if(tmp->next[i] == NULL || (list->compare(key, tmp->next[i]->val)) < 0){
            if(i <= new->size){
                new->next[i] = tmp->next[i];
                tmp->next[i] = new;
            }
        }else{
            tmp = tmp->next[i];
            i++;
        }
    }
}

void *searchSkipList(Skiplist *list, void *elem){
    Node *tmp = list->header;

    for(int i = list->level; i >= 0; i--){
        while(tmp->next[i] != NULL){
            if(list->compare(tmp->next[i]->val, elem) < 0){
                /* If the searched element is greater than the current element
                   then go to the next element of the list */
                tmp = tmp->next[i];
            }else break;
        }
    }

    tmp = tmp->next[0];
    if(tmp == NULL) return NULL;

    if(list->compare(tmp->val, elem) == 0){
        return tmp->val;
    }else return NULL;
}

void freeSkiplist(Skiplist *list) {
    Node *current = list->header->next[0];
    
    while (current != NULL) {
        Node *nextNode = current->next[0];
        free(current->next);
        free(current);
        current = nextNode;
    }
    free(list->header->next);
    free(list->header);
    free(list);
}



