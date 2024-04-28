#include "../include/LinkList.h"
#include <stdio.h>
void ListPushTest();
void GetELemTest();
void LocateElemTest();
void ListInsertTest();
void ListDeleteTest();
void DeleteNodeWithValueXTest();
void DelteMinValueNodeTest();
void ReverseListTest();
int main(){
	// ListPushTest();
	// void GetELemTest();
	// LocateElemTest();
	// ListInsertTest();
	// ListDeleteTest();
    // DeleteNodeWithValueXTest();
	// DelteMinValueNodeTest();
	ReverseListTest();
}
void ListPushTest(){
	LinkList list;
	InitList(&list);
	for (int i = 0 ; i<15; i++) {
		ListPush(&list, i);
	}
	PrintList(&list);
	printf("list length:%d\n",list.length);
	printf("head:%d\n",list.head->data);
	printf("tail:%d\n",list.tail->data);
	DestroyList(&list);
}


void GetELemTest(){
	LinkList list;
	InitList(&list);
	for (int i = 0 ; i<15; i++) {
		ListPush(&list, i);
	}
	PrintList(&list);
	printf("list length:%d\n",list.length);
	printf("head:%d\n",list.head->data);
	printf("tail:%d\n",list.tail->data);
	for (int i = 0 ; i<18; i++) {
		LNode * node = GetELem(&list, i);
		if (node) {
			printf("%dth item's data is %d\n",i,node->data);
		}else {
		    printf("%dth item is not exsit\n",i);
		}
	}
	DestroyList(&list);
}


void LocateElemTest(){
	LinkList list;
	InitList(&list);
	for (int i = 0 ; i<15; i++) {
		ListPush(&list, i*2);
	}
	PrintList(&list);
	printf("list length:%d\n",list.length);
	printf("head:%d\n",list.head->data);
	printf("tail:%d\n",list.tail->data);
	for (int i = 0 ; i<18; i++) {
		LNode * node = LocateElem(&list, i);
		if (node) {
			printf("Node contains %d exists \n",i);
		}else {
		    printf("Node contains %d does not  exist\n",i);
		}
	}
	DestroyList(&list);
};

void ListInsertTest(){
	LinkList list;
	InitList(&list);
	for (int i = 0 ; i<15; i++) {
		ListInsert(&list,i,i);
	}
	PrintList(&list);
	ListInsert(&list,0,1);
	PrintList(&list);
	ListInsert(&list,16,30);
	PrintList(&list);
	printf("List length is %d\n",list.length);
	DestroyList(&list);
}


void ListDeleteTest(){
	LinkList list;
	InitList(&list);
	for (int i = 0 ; i<15; i++) {
		ListInsert(&list,i,i);
	}
	PrintList(&list);
	ElemType d;
	ListDelete(&list,14,&d);
	printf("Deleted item is %d\n",d);
	PrintList(&list);

	ListDelete(&list,12,&d);
	printf("Deleted item is %d\n",d);
	PrintList(&list);

	ListDelete(&list,0,&d);
	printf("Deleted item is %d\n",d);
	PrintList(&list);
	printf("List length is %d\n",list.length);
	DestroyList(&list);
}

void DeleteNodeWithValueXTest(){
	LinkList list;
	InitList(&list);
	for (int i = 0 ; i<15; i++) {
		ListInsert(&list,i,i);
	}
	PrintListWithFakeHead(&list);
	DeleteNodeWithValueX(&list,1);
	PrintListWithFakeHead(&list);
	DestroyList(&list);
}

void DelteMinValueNodeTest(){
	LinkList list;
	InitList(&list);
	for (int i = 15 ; i>0; i--) {
		ListInsert(&list,0,i);
	}
	PrintListWithFakeHead(&list);
	DelteMinValueNode(&list);
	PrintListWithFakeHead(&list);
	DestroyList(&list);
}
void ReverseListTest(){
	LinkList list;
	InitList(&list);
	for (int i = 15 ; i>0; i--) {
		ListInsert(&list,0,i);
	}
	PrintListWithFakeHead(&list);
	ReverseList(&list);
	PrintListWithFakeHead(&list);
	DestroyList(&list);
}