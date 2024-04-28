#include "../include/Algorithms.h"
int partition(void **array, int low, int high, CompareFunc compare, SwapFunc swap) {
    void *pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (compare(array[j], pivot) <= 0) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void QuickSortHelper(void **array, int low, int high, CompareFunc compare, SwapFunc swap) {
    if (low < high) {
        int pi = partition(array, low, high, compare, swap);
        QuickSortHelper(array, low, pi - 1, compare, swap);
        QuickSortHelper(array, pi + 1, high, compare, swap);
    }
}
void QuickSort(void **elems,int num,CompareFunc compare,SwapFunc swap){
	QuickSortHelper(elems, 0, num-1, compare, swap);
}


