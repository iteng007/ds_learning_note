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
void MajorityTest();
void FindMedianOfTwoSeqListTest();
void MinPosNonExistConstTest();

void MinTripDistanceTest();
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
	//FindMedianOfTwoSeqListTest();
	//MajorityTest();
	//MinPosNonExistConstTest();
	 MinTripDistanceTest();
}

void BasicTest(){
	SeqList list;
	InitSeqList(&list);
	assert(list.Length==0);
	bool inserted = SeqListInsert(&list,0,1);
	assert(inserted);
	PrintSeqList(&list);
	assert(list.Length==1);
	ElemType elem;
	bool deleted = SeqListDelete(&list,0,&elem);
	assert(deleted);
	assert(list.Length==0);
	PrintSeqList(&list);
	DestroySeqList(&list);
}
void DeleteMinimumTest(){
	SeqList list;
	InitSeqList(&list);
	for (int i = 0; i<10; i++) {
		SeqListInsert(&list,0,i);
	}
	PrintSeqList(&list);
	assert(list.Length == 10);
	DeleteMinimum(&list);
	PrintSeqList(&list);
	DeleteMinimum(&list);
	PrintSeqList(&list);
	list.data[2]=0;
	DeleteMinimum(&list);
	PrintSeqList(&list);
	DestroySeqList(&list);
}

void ReverseSeqListTest(){
	SeqList list;
	InitSeqList(&list);
	for (int i = 0; i<15; i++) {
		SeqListInsert(&list,0,i);
	}
	PrintSeqList(&list);
	ReverseSeqList(&list);
	PrintSeqList(&list);
	DestroySeqList(&list);
}

void DeleteElemXTest(){
	SeqList list;
	InitSeqList(&list);
	for (int i = 0; i<15; i++) {
		SeqListInsert(&list,0,i);
	}
	PrintSeqList(&list);
	DeleteElemX(&list, 13);
	PrintSeqList(&list);
	DestroySeqList(&list);
}

void DeleteRangeSandTTest(){
	SeqList list;
	InitSeqList(&list);
	for (int i = 0; i<15; i++) {
		SeqListInsert(&list,0,i);
	}
	PrintSeqList(&list);
	DeleteRangeSandT(&list, 10, 13);
	PrintSeqList(&list);
	DestroySeqList(&list);
}

void DeDupSortedSeqListTest(){
	SeqList list;
	InitSeqList(&list);
	for (int i = 0; i<15; i++) {
		SeqListInsert(&list,0,i);
		SeqListInsert(&list,0,i);
	}
	PrintSeqList(&list);
	DeDupSortedSeqList(&list);
	PrintSeqList(&list);
	DestroySeqList(&list);
}

void MergeSortedSeqListTest(){
	SeqList L;
	InitSeqList(&L);
	for (int i = 15; i>=0; i--) {
		SeqListInsert(&L,0,i);
	}
	PrintSeqList(&L);
	SeqList R;
	InitSeqList(&R);
	for (int i = 15; i>=0; i--) {
		SeqListInsert(&R,0,i*2);
	}
	SeqList output;
	InitSeqList(&output);
	PrintSeqList(&R);
	MergeSortedSeqList(&L, &R, &output);
	PrintSeqList(&output);
	DestroySeqList(&L);
	DestroySeqList(&R);
	DestroySeqList(&output);
}

void MNReverseTest(){
	SeqList list;
	InitSeqList(&list);
	for (int i = 0; i<15; i++) {
		SeqListInsert(&list,0,i);
	}
	PrintSeqList(&list);
	MNReverse(&list,7, 8);
	PrintSeqList(&list);
	DestroySeqList(&list);
}

void BinarySearchTest(){
	SeqList list;
	InitSeqList(&list);
	for (int i = 14; i>=0; i--) {
		SeqListInsert(&list,0,i*2);
	}
	PrintSeqList(&list);
	int index = -1;
	int seven = BinarySearch(&list, 3,&index);
	printf("%d\n",index);
	DestroySeqList(&list);

}

void FindAndExchangeXTest(){
	SeqList list;
	InitSeqList(&list);
	for (int i = 14; i>=0; i--) {
		SeqListInsert(&list,0,i*2);
	}
	PrintSeqList(&list);
	FindAndExchangeX(&list,1);
	PrintSeqList(&list);
	DestroySeqList(&list);
}

void OutputCommonElemTest(){
	SeqList list1;
	InitSeqList(&list1);
	SeqListInsert(&list1,0,5);
	SeqListInsert(&list1,0,2);
	SeqListInsert(&list1,0,1);
	SeqList list2;
	InitSeqList(&list2);
	SeqListInsert(&list2,0,5);
	SeqListInsert(&list2,0,3);
	SeqListInsert(&list2,0,2);
	SeqList list3;
	InitSeqList(&list3);
	SeqListInsert(&list3,0,5);
	SeqListInsert(&list3,0,4);
	SeqListInsert(&list3,0,3);
	PrintSeqList(&list1);
	PrintSeqList(&list2);
	PrintSeqList(&list3);
	OutputCommonElem(&list1, &list2, &list3);

	DestroySeqList(&list1);
	DestroySeqList(&list2);
	DestroySeqList(&list3);
}

void FindMedianOfTwoSeqListTest(){
	SeqList list1;
	InitSeqList(&list1);
	SeqListInsert(&list1,0,19);
	SeqListInsert(&list1,0,17);
	SeqListInsert(&list1,0,15);
	SeqListInsert(&list1,0,13);
	SeqListInsert(&list1,0,11);
	SeqList list2;
	InitSeqList(&list2);
	SeqListInsert(&list2,0,20);
	SeqListInsert(&list2,0,8);
	SeqListInsert(&list2,0,6);
	SeqListInsert(&list2,0,4);
	SeqListInsert(&list2,0,2);
	ElemType median = FindMedianOfTwoSeqList(&list1, &list2);
	PrintSeqList(&list1);
	PrintSeqList(&list2);
	printf("Median is %d\n",median);

	DestroySeqList(&list1);
	DestroySeqList(&list2);
}
void MajorityTest(){
	SeqList list1;
	InitSeqList(&list1);
	SeqListInsert(&list1,0,13);
	SeqListInsert(&list1,0,13);
	SeqListInsert(&list1,0,13);
	SeqListInsert(&list1,0,11);
	SeqListInsert(&list1,0,11);
	PrintSeqList(&list1);
	ElemType majority = Majority(&list1);
	printf("%d\n",majority);
	DestroySeqList(&list1);
}

void MinPosNonExistConstTest(){
	SeqList list1;
	InitSeqList(&list1);
	SeqListInsert(&list1,0,1);
	SeqListInsert(&list1,0,3);
	SeqListInsert(&list1,0,4);
	SeqListInsert(&list1,0,5);
	SeqListInsert(&list1,0,7);
	PrintSeqList(&list1);
	ElemType min = MinPosNonExistConst(&list1);
	printf("%d\n",min);
	DestroySeqList(&list1);
}

void MinTripDistanceTest(){
	SeqList list1;
	InitSeqList(&list1);
	SeqListInsert(&list1,0,9);
	SeqListInsert(&list1,0,0);
	SeqListInsert(&list1,0,-1);
	SeqList list2;
	InitSeqList(&list2);
	SeqListInsert(&list2,0,113);
	SeqListInsert(&list2,0,10);
	SeqListInsert(&list2,0,-10);
	SeqListInsert(&list2,0,-25);
	SeqList list3;
	InitSeqList(&list3);
	SeqListInsert(&list3,0,41);
	SeqListInsert(&list3,0,30);
	SeqListInsert(&list3,0,17);
	SeqListInsert(&list3,0,9);
	SeqListInsert(&list3,0,2);
	PrintSeqList(&list1);
	PrintSeqList(&list2);
	PrintSeqList(&list3);
	int min_distance = MinTripDistance(&list1, &list2, &list3);
	printf("%d\n",min_distance);
	DestroySeqList(&list1);
	DestroySeqList(&list2);
	DestroySeqList(&list3);
}