#include "library.h"
#include <stdio.h>
#include <string.h>

int binary_search(void *arr, void *elem, int low, int high, int size, int (*compar)(const void *, const void *)){
    while(low < high){
        int mid = (low + high)/2;
        if(compar((char *)arr + mid * size, elem) < 0){
            low = mid + 1;
        }else high = mid;
    }
    return low;
}

void insertion_sort(void *base, long low, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    /*
    Trattandosi di un puntatore a void e dovendo mantenere generica la funzione:
    - avendo size ed
    - usando i char (1 byte)
    possiamo accedere ai dati puntati da *base.
    */

    for(int i = low + 1; i < nitems; i++){
        char key[size];
        char *p_arr = (char *)base;
        memcpy(key, p_arr + i * size, size);
        int pos = binary_search(base, key, low, i, size, compar);
        int j = i;
        while(j > pos){
            memcpy(p_arr + j * size, p_arr + (j - 1) * size, size);
            j = j - 1;
        }
        memcpy(p_arr + pos * size, key, size);
    }
}

void merge(void *base, int left, int mid, int right, size_t size, int (*compar)(const void *, const void *)){
    int len1 = mid - left + 1;
    int len2 = right - mid;

    char leftArr[len1 * size];
    char rightArr[len2 * size];
    char *arr = (char *)base;

    for(int i = 0; i < len1; i++){
        memcpy(leftArr + i * size, arr + (left + i) * size, size);
    }   
    for(int i = 0; i < len2; i++){
        memcpy(rightArr + i * size, arr + (mid + 1 + i) * size, size);
    }   
    
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while(i < len1 && j < len2){
        if(compar(leftArr + i * size, rightArr + j * size) <= 0){
            memcpy(arr + k * size, leftArr + i * size, size);
            i++;
        }else{
            memcpy(arr + k * size, rightArr + j * size, size);
            j++;
        }
        k++;
    }

    while (i < len1) {
        memcpy(arr + k * size, leftArr + i * size, size);
        i++;
        k++;
    }

    while (j < len2) {
        memcpy(arr + k * size, rightArr + j * size, size);
        j++;
        k++;
    }
}

void merge_binary_insertion_sort(void *base, int left, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){
    /* 
    Pre-condizione: per *base è stato allocato lo spazio necessario
    Post-condizione: *base ordinato
    */

    if((nitems - left) <= k){
        insertion_sort(base, left, nitems, size, compar);
    }

    else if(left < nitems){
        int mid = left + (nitems - left)/2;
        merge_binary_insertion_sort(base, left, mid, size, k, compar);
        merge_binary_insertion_sort(base, mid + 1, nitems, size, k, compar);
        merge(base, left, mid, nitems, size, compar);
    }
}