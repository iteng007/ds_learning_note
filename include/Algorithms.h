#ifndef ALGORITHMS
#define ALGORITHMS
typedef int (*CompareFunc)(void*, void*);
typedef void (*SwapFunc)(void* a, void* b);
void QuickSort(void **elems,int num,CompareFunc,SwapFunc);
void* Max(void **elems,int num,CompareFunc,void *min);
void* Min(void **elems,int num,CompareFunc,void *max);
int  abs_int(int a);
long abs_long(long a);
long long abs_longl(long long a);
#endif