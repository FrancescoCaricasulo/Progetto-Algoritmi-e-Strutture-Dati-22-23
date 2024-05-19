#include <stddef.h>

#ifndef skip_list_h
#define skip_list_h

typedef struct _node {
    void *val;
    int size;
    struct _node **next;
} Node;
 
typedef struct _skiplist {
    int level;
    int height;
    int (*compare)(const void*, const void*);
    struct _node *header;
} Skiplist;

Skiplist *initSkiplist(Skiplist *, size_t max_height, int (*compare)(const void*, const void*));
void addItem(Skiplist *, void*);
void * searchSkipList(Skiplist *, void *);
void freeSkiplist(Skiplist *);

#endif