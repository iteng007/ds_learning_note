#include "../include/SeqList.h"
#include <assert.h>
#include <stdbool.h>
void BasicTest();
void DeleteMinimumTest();
void ReverseSeqListTest();
void DeleteElemXTest();
void DeleteRangeSandTTest();
void DeDupSortedSeqListTest();
void MergeSortedSeqListTest();
int main(){
	//BasicTest();
	//DeleteMinimumTest();
	// ReverseSeqListTest();
	//DeleteElemXTest();
	//DeleteRangeSandTTest();
	 //DeDupSortedSeqListTest();
	 MergeSortedSeqListTest();
}

void BasicTest(){
	SeqList list;
	InitList(&list);
	assert(list.Length==0);
	bool inserted = ListInsert(&list,0,1);
	assert(inserted);
	PrintList(&list);
	assert(list.Length==1);
	ElemType elem;
	bool deleted = ListDelete(&list,0,&elem);
	assert(deleted);
	assert(list.Length==0);
	PrintList(&list);
	DestroyList(&list);
}
void DeleteMinimumTest(){
	SeqList list;
	InitList(&list);
	for (int i = 0; i<10; i++) {
		ListInsert(&list,0,i);
	}
	PrintList(&list);
	assert(list.Length == 10);
	DeleteMinimum(&list);
	PrintList(&list);
	DeleteMinimum(&list);
	PrintList(&list);
	list.data[2]=0;
	DeleteMinimum(&list);
	PrintList(&list);
	DestroyList(&list);
}

void ReverseSeqListTest(){
	SeqList list;
	InitList(&list);
	for (int i = 0; i<15; i++) {
		ListInsert(&list,0,i);
	}
	PrintList(&list);
	ReverseSeqList(&list);
	PrintList(&list);
	DestroyList(&list);
}

void DeleteElemXTest(){
	SeqList list;
	InitList(&list);
	for (int i = 0; i<15; i++) {
		ListInsert(&list,0,i);
	}
	PrintList(&list);
	DeleteElemX(&list, 13);
	PrintList(&list);
	DestroyList(&list);
}

void DeleteRangeSandTTest(){
	SeqList list;
	InitList(&list);
	for (int i = 0; i<15; i++) {
		ListInsert(&list,0,i);
	}
	PrintList(&list);
	DeleteRangeSandT(&list, 10, 13);
	PrintList(&list);
	DestroyList(&list);
}

void DeDupSortedSeqListTest(){
	SeqList list;
	InitList(&list);
	for (int i = 0; i<15; i++) {
		ListInsert(&list,0,i);
		ListInsert(&list,0,i);
	}
	PrintList(&list);
	DeDupSortedSeqList(&list);
	PrintList(&list);
	DestroyList(&list);
}

void MergeSortedSeqListTest(){
	SeqList L;
	InitList(&L);
	for (int i = 15; i>=0; i--) {
		ListInsert(&L,0,i);
	}
	PrintList(&L);
	SeqList R;
	InitList(&R);
	for (int i = 15; i>=0; i--) {
		ListInsert(&R,0,i*2);
	}
	SeqList output;
	InitList(&output);
	PrintList(&R);
	MergeSortedSeqList(&L, &R, &output);
	PrintList(&output);
	DestroyList(&L);
	DestroyList(&R);
	DestroyList(&output);
}