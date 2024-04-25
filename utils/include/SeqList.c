#include "SeqList.h"
#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 在本实现中，认为i为数组下标，顺序表位置应为i+1
void InitList(SeqList *L) {
  L->Length = 0;
  L->data = malloc(sizeof(ElemType) * InitSize);
  L->MaxSize = InitSize;
}
int Length(SeqList *L) { return L->Length; };
int LocateElem(SeqList *L, ElemType e) {
  for (int i = 0; i < L->Length; i++) {
    if (L->data[i] == e) {
      return i;
    }
  }
  return -1;
};

bool ListInsert(SeqList *L, int i, ElemType e) {
  if (i < 0 || i > L->Length) {
    return false;
  }
  if (L->Length >= L->MaxSize) {
    return false;
  }
  for (int j = L->Length; j > i; j--) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i] = e;
  L->Length++;
  return true;
}
bool ListDelete(SeqList *L, int i, ElemType *e) {
  if (i < 0 || i >= L->Length) {
    return false;
  }
  *e = L->data[i];
  for (int j = i; j < L->Length; j++) {
    L->data[j] = L->data[j - 1];
  }
  L->Length--;
  return true;
}
void PrintList(SeqList *L) {
  for (int i = 0; i < L->Length; i++) {
    printf("%d\t", L->data[i]);
  }
  printf("\n");
}
bool Empty(SeqList *L) { return L->Length == 0; }

void DestroyList(SeqList *L){
	free(L->data);
	L->MaxSize = 0;
	L->Length = 0;
}

//m:start index,n end index;
//both is inclusive
void ReverseRange(SeqList *L,int m,int n){
	for (int i =  0,j = n; i<j; i++,j++) {
		ElemType temp = L->data[i];
		L->data [i] = L->data[j];
		L->data [j]  =temp;
	}
}


//p19.01
bool DeleteMinimum(SeqList *L){
	if (L->Length==0) {
		return false;
	}
	ElemType minimum  = L->data[0];
	int index = 0;
	for (int i = 1; i<L->Length; i++) {
		if (L->data[i]<minimum) {
			minimum = L->data[i];
			index = i;
		}
	}
	L->data[index] = L->data[L->Length-1];
	L->Length--;
	return true;
}

//p19.02
void ReverseSeqList(SeqList *L){
	for (int i = 0,j = L->Length-1; i<j; i++,j--) {
		ElemType temp = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = temp; 
	}
}

//p19.03
//使用numnx 记录所有非x元素,并跟踪当前已移动的位置。
//随后将非x元素依次向前移动。
void DeleteElemX(SeqList *L,ElemType X){
	int numnx = 0;
	for (int i =  0; i<L->Length; i++) {
		if (L->data[i]!=X) {
			L->data[numnx] = L->data[i]; 
			numnx++;
		}
	}
	L->Length = numnx;
}

//p19.04
//可以考虑使用DeleteElemX 相同思想，实现O(n)的时间复杂度完成删除
bool DeleteRangeSandT(SeqList *L,ElemType S,ElemType T){
	if(L->Length == 0||S>=T){
		return false;
	}
	int numx  = 0;
	for (int i = 0; i<L->Length; i++) {
		if (L->data[i]<S || L->data[i]>T) {
			L->data[numx] = L->data[i];
			numx++;
		}
	}
	L->Length = numx;
	return true;
}

//p19.05 双指针
//一根指针指向下一个需要被非重复元素替换的位置
//一根用于遍历找到下一个非重复元素。
void DeDupSortedSeqList(SeqList * L){
	if (L->Length==1) {
		return;
	}
	int i,j;
	for (i = 0,j = 1; j<L->Length; j++) {
		if (L->data[i]!=L->data[j]) {
			L->data[++i] = L->data[j];
		}
	}
	L->Length = i+1;
}

//p19.06
bool MergeSortedSeqList(SeqList *L,SeqList *R,SeqList *output){
	if(output->MaxSize<L->Length+R->Length){
		return false;
	}
	int i = 0,j = 0;
	int output_index = 0;
	while (i<L->Length&&j<R->Length) {
		if(L->data[i]<R->data[j]){
			output->data[output_index]=L->data[i++];
		}else {
		   output->data[output_index] = R->data[j++];
		}
		output_index++;
	}
	while (i<L->Length) {
		output->data[output_index++]=L->data[i++];
	}
	while (j<R->Length) {
		output->data[output_index++]=R->data[j++];
	}
	output->Length  = L->Length + R->Length;
	return true;
}

//p19.07

void MNReverse(SeqList *L,int m,int n){

}