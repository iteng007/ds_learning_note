#ifndef ALGORITHMS
#define ALGORITHMS
typedef int (*CompareFunc)(void*, void*);
typedef void (*SwapFunc)(void* a, void* b);
void QuickSort(void **elems,int num,CompareFunc,SwapFunc);
void* Max(void **elems,int num,CompareFunc,void *min);
void* Min(void **elems,int num,CompareFunc,void *max);
#endif