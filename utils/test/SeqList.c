#include "../include/SeqList.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
void BasicTest();
void DeleteMinimumTest();
void ReverseSeqListTest();
void DeleteElemXTest();
void DeleteRangeSandTTest();
void DeDupSortedSeqListTest();
void MergeSortedSeqListTest();
void MNReverseTest();
void BinarySearchTest();
void FindAndExchangeXTest();
void OutputCommonElemTest();

void FindMedianOfTwoSeqListTest();
int main(){
	//BasicTest();
	//DeleteMinimumTest();
	// ReverseSeqListTest();
	//DeleteElemXTest();
	//DeleteRangeSandTTest();
	 //DeDupSortedSeqListTest();
	//  MergeSortedSeqListTest();
	// MNReverseTest();
	//  BinarySearchTest();
	// FindAndExchangeXTest();
	// OutputCommonElemTest();
	FindMedianOfTwoSeqListTest();
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

void MNReverseTest(){
	SeqList list;
	InitList(&list);
	for (int i = 0; i<15; i++) {
		ListInsert(&list,0,i);
	}
	PrintList(&list);
	MNReverse(&list,7, 8);
	PrintList(&list);
	DestroyList(&list);
}

void BinarySearchTest(){
	SeqList list;
	InitList(&list);
	for (int i = 14; i>=0; i--) {
		ListInsert(&list,0,i*2);
	}
	PrintList(&list);
	int index = -1;
	int seven = BinarySearch(&list, 3,&index);
	printf("%d\n",index);
	DestroyList(&list);

}

void FindAndExchangeXTest(){
	SeqList list;
	InitList(&list);
	for (int i = 14; i>=0; i--) {
		ListInsert(&list,0,i*2);
	}
	PrintList(&list);
	FindAndExchangeX(&list,1);
	PrintList(&list);
	DestroyList(&list);
}

void OutputCommonElemTest(){
	SeqList list1;
	InitList(&list1);
	ListInsert(&list1,0,5);
	ListInsert(&list1,0,2);
	ListInsert(&list1,0,1);
	SeqList list2;
	InitList(&list2);
	ListInsert(&list2,0,5);
	ListInsert(&list2,0,3);
	ListInsert(&list2,0,2);
	SeqList list3;
	InitList(&list3);
	ListInsert(&list3,0,5);
	ListInsert(&list3,0,4);
	ListInsert(&list3,0,3);
	PrintList(&list1);
	PrintList(&list2);
	PrintList(&list3);
	OutputCommonElem(&list1, &list2, &list3);

	DestroyList(&list1);
	DestroyList(&list2);
	DestroyList(&list3);
}

void FindMedianOfTwoSeqListTest(){
	SeqList list1;
	InitList(&list1);
	ListInsert(&list1,0,19);
	ListInsert(&list1,0,17);
	ListInsert(&list1,0,15);
	ListInsert(&list1,0,13);
	ListInsert(&list1,0,11);
	SeqList list2;
	InitList(&list2);
	ListInsert(&list2,0,20);
	ListInsert(&list2,0,8);
	ListInsert(&list2,0,6);
	ListInsert(&list2,0,4);
	ListInsert(&list2,0,2);
	ElemType median = FindMedianOfTwoSeqList(&list1, &list2);
	PrintList(&list1);
	PrintList(&list2);
	printf("Median is %d\n",median);

	DestroyList(&list1);
	DestroyList(&list2);
}