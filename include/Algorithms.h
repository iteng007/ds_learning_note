#ifndef ALGORITHMS
#define ALGORITHMS
#include <stdbool.h>
typedef int (*CompareFunc)(void*, void*);
typedef void (*SwapFunc)(void* a, void* b);
void QuickSort(void **elems,int num,CompareFunc,SwapFunc);
void Max(void **elems,int num,CompareFunc);
#endif