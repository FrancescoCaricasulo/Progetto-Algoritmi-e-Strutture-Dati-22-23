#include <stdlib.h>

void merge_binary_insertion_sort(void *base, int left, size_t nitems, size_t size, size_t k, int (*compar)(const void *, const void*));
int binary_search(void *arr, void *elem, int low, int high, int size, int (*compar)(const void *, const void *));
void insertion_sort(void *base, long low, size_t nitems, size_t size, int (*compar)(const void *, const void *));
void merge(void *base, int left, int mid, int right, size_t size, int (*compar)(const void *, const void *));