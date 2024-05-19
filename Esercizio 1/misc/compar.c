#include <ctype.h>
#include <string.h>
#include <stdio.h>

#define STR_LEN 20

typedef struct data {
    int id;
    char string[STR_LEN];
    int integer;
    double floating;
} Data;

int compar_int(const void *a, const void *b){
    if(*(int *)a == *(int *)b){
        return 0;
    } else if(*(int *)a > *(int *)b) {
        return 1;
    }else{ 
        return -1;
    }
}

int compar_double(const void *a, const void *b){
    if(*(double *)a == *(double *)b){
        return 0;
    } else if(*(double *)a > *(double *)b) {
        return 1;
    }else{ 
        return -1;
    }
}

int compar_char(const void *a, const void *b){
    if(tolower(*(char *)a) == tolower(*(char *)b)){
        return 0;
    } else if(tolower(*(char *)a) > tolower(*(char *)b)) {
        return 1;
    }else{ 
        return -1;
    }
}

int compar_string(const void *a, const void *b) {
    return strcmp(((char *)a), ((char *)b));
}