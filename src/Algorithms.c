#include "../include/Algorithms.h"
static int partition(void **array, int low, int high, CompareFunc compare, SwapFunc swap) {
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

static void QuickSortHelper(void **array, int low, int high, CompareFunc compare, SwapFunc swap) {
    if (low < high) {
        int pi = partition(array, low, high, compare, swap);
        QuickSortHelper(array, low, pi - 1, compare, swap);
        QuickSortHelper(array, pi + 1, high, compare, swap);
    }
}
void QuickSort(void **elems,int num,CompareFunc compare,SwapFunc swap){
	QuickSortHelper(elems, 0, num-1, compare, swap);
}
void* Max(void **elems,int num,CompareFunc compare,void *min){
	void *max = min;
	for (int i = 0; i<num; i++) {
		if (compare(max,elems[i])<0) {
			max = elems[i];
		}
	}
	return max;
}

void* Min(void **elems,int num,CompareFunc compare,void *max){
	void *min = max;
	for (int i = 0; i<num; i++) {
		if (compare(min,elems[i])>0) {
			min = elems[i];
		}
	}
	return min;
}
