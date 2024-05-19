#include <stdio.h>
#include <string.h>

// test

int compar(const void *a, const void *b){
    if(*(int *)a == *(int *)b){
        return 0;
    } else if(*(int *)a > *(int *)b) {
        return 1;
    }else{ 
        return -1;
    }
}

int binary_search(void *arr, void *elem, int low, int high, int size, int (*compar)(const void *, const void *)){
    while(low < high){
        int mid = (low + high)/2;
        if(compar((char *)arr + mid * size, elem) < 0){
            low = mid + 1;
        }else high = mid;
    }
    return low;
}

void insertion_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    /*
    Trattandosi di un puntatore a void e dovendo mantenere generica la funzione:
    - avendo size ed
    - usando i char (1 byte)
    possiamo accedere ai dati puntati da *base.
    */

    for(int i = 1; i < nitems; i++){
        char key[size];
        char *p_arr = (char *)base;
        memcpy(key, p_arr + i * size, size);
        int pos = binary_search(base, key, 0, i, size, compar);
        int j = i;
        while(j > pos){
            memcpy(p_arr + j * size, p_arr + (j - 1) * size, size);
            j = j - 1;
        }
        memcpy(p_arr + pos * size, key, size);
    }
}

void merge(void *base, int left, int mid, int right, size_t size, int (*compar)(const void *, const void *)){
    int i = left;
    int j = mid + 1;
    int k = 0;

    char *arr = (char *)base;
    char ord_arr[size * right];

    while(i <= mid && j <= right){
        if(compar(arr + i * size, arr + j * size) <= 0){
            memcpy(ord_arr + k * size, arr + i * size, size);
            i++;
        }else{
            memcpy(ord_arr + k * size, arr + j * size, size);
            j++;
        }
        k++;
    }

    while (i <= mid) {
        memcpy(ord_arr + k * size, arr + i * size, size);
        i++;
        k++;
    }

    while (j <= right) {
        memcpy(ord_arr + k * size, arr + j * size, size);
        j++;
        k++;
    }

    for (k = 0; k <= right - left; k++) {
        memcpy(arr + (left + k) * size, ord_arr + k * size, size);
    }
}

void merge_binary_insertion_sort(void *base, int left, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*)){
    /* 
    Pre-condizione: per *base è stato allocato lo spazio necessario
    Post-condizione: *base ordinato
    */

    if(nitems < 1){
        return;
    }

    if(nitems <= k){
        // sfrutta binary insertion sort
        insertion_sort(base, nitems, size, compar);
    }

    if(left < nitems){
        // sfrutta merge sort
        int mid = (left + nitems)/2;
        merge_binary_insertion_sort(base, left, mid, size, k, compar);
        merge_binary_insertion_sort(base, mid + 1, nitems, size, k, compar);
        merge(base, left, mid, nitems, size, compar);
    }
}

void merge_sort(void *base, int left, int right, size_t size, int (*compar)(const void *, const void *)){
    /* 
    Pre-condizione: per *base è stato allocato lo spazio necessario
    Post-condizione: *base ordinato
    */
    if(left < right){
        int mid = (left + right)/2;
        merge_sort(base, left, mid, size, compar);
        merge_sort(base, mid + 1, right, size, compar);
        merge(base, left, mid, right, size, compar);
    }
}

int main(){
    int *arr = malloc(10 * sizeof(int));
    int n = 10;
    for(int i = 0; i < 10; i++){
        arr[i] = n;
        n--;
    }

    printf("Unordered array: \n");

    for(int i = 0; i < 10; i++){
        printf("|%d\t", arr[i]);
    }

    printf("\n");

    merge_binary_insertion_sort((void *)arr, 0, 10, sizeof(int), 0, compar);
    //merge_sort((void *)arr, 0, 10, sizeof(int), compar);
    //insertion_sort((void *)arr, 10, sizeof(int), compar);

    printf("Ordered array: \n");

    for(int i = 0; i < 10; i++){
        printf("|%d\t", arr[i]);
    }

    printf("\n");
}