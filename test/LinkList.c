#include "../include/LinkList.h"
#include <stdio.h>
void ListPushTest();
void GetELemTest();
void LocateElemTest();
void ListInsertTest();
void ListDeleteTest();
void DeleteNodeWithValueXTest();
void DelteMinValueNodeTest();
void ReverseLinkListTest();
void LinkListDeleteRangeTest();
void  CommonLNodeTest();
int main(){
	// ListPushTest();
	// void GetELemTest();
	// LocateElemTest();
	// ListInsertTest();
	// ListDeleteTest();
    // DeleteNodeWithValueXTest();
	// DelteMinValueNodeTest();
	// ReverseLinkListTest();
	// LinkListDeleteRangeTest();
	CommonLNodeTest();
}
void ListPushTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 0 ; i<15; i++) {
		LinkListPush(&list, i);
	}
	PrintLinkList(&list);
	printf("list length:%d\n",list.length);
	printf("head:%d\n",list.head->data);
	printf("tail:%d\n",list.tail->data);
	DestroyLinkList(&list);
}


void GetELemTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 0 ; i<15; i++) {
		LinkListPush(&list, i);
	}
	PrintLinkList(&list);
	printf("list length:%d\n",list.length);
	printf("head:%d\n",list.head->data);
	printf("tail:%d\n",list.tail->data);
	for (int i = 0 ; i<18; i++) {
		LNode * node = LinkListGetELem(&list, i);
		if (node) {
			printf("%dth item's data is %d\n",i,node->data);
		}else {
		    printf("%dth item is not exsit\n",i);
		}
	}
	DestroyLinkList(&list);
}


void LocateElemTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 0 ; i<15; i++) {
		LinkListPush(&list, i*2);
	}
	PrintLinkList(&list);
	printf("list length:%d\n",list.length);
	printf("head:%d\n",list.head->data);
	printf("tail:%d\n",list.tail->data);
	for (int i = 0 ; i<18; i++) {
		LNode * node = LinkListLocateElem(&list, i);
		if (node) {
			printf("Node contains %d exists \n",i);
		}else {
		    printf("Node contains %d does not  exist\n",i);
		}
	}
	DestroyLinkList(&list);
};

void ListInsertTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 0 ; i<15; i++) {
		LinkListInsert(&list,i,i);
	}
	PrintLinkList(&list);
	LinkListInsert(&list,0,1);
	PrintLinkList(&list);
	LinkListInsert(&list,16,30);
	PrintLinkList(&list);
	printf("List length is %d\n",list.length);
	DestroyLinkList(&list);
}


void ListDeleteTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 0 ; i<15; i++) {
		LinkListInsert(&list,i,i);
	}
	PrintLinkList(&list);
	ElemType d;
	LinkListDelete(&list,14,&d);
	printf("Deleted item is %d\n",d);
	PrintLinkList(&list);

	LinkListDelete(&list,12,&d);
	printf("Deleted item is %d\n",d);
	PrintLinkList(&list);

	LinkListDelete(&list,0,&d);
	printf("Deleted item is %d\n",d);
	PrintLinkList(&list);
	printf("List length is %d\n",list.length);
	DestroyLinkList(&list);
}

void DeleteNodeWithValueXTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 0 ; i<15; i++) {
		LinkListInsert(&list,i,i);
	}
	PrintLinkListWithFakeHead(&list);
	DeleteNodeWithValueX(&list,1);
	PrintLinkListWithFakeHead(&list);
	DestroyLinkList(&list);
}

void DelteMinValueNodeTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list,0,i);
	}
	PrintLinkListWithFakeHead(&list);
	DelteMinValueNode(&list);
	PrintLinkListWithFakeHead(&list);
	DestroyLinkList(&list);
}
void ReverseLinkListTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list,0,i);
	}
	PrintLinkListWithFakeHead(&list);
	ReverseLinkList(&list);
	PrintLinkListWithFakeHead(&list);
	DestroyLinkList(&list);
}

void LinkListDeleteRangeTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list,0,i);
	}
	PrintLinkListWithFakeHead(&list);
	LinkListDeleteRange(&list,7,13);
	PrintLinkListWithFakeHead(&list);
	DestroyLinkList(&list);
}


void CommonLNodeTest(){
	LinkList list1;
	InitLinkList(&list1);
	LinkList list2;
	InitLinkList(&list2);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list1,0,i);
	}
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list2,0,i+1);
	}
	// PrintLinkListWithFakeHead(&list1);
	// PrintLinkListWithFakeHead(&list2);
	int len;
	CommonLNode(&list1, &list2, &len);
	DestroyLinkList(&list1);
	DestroyLinkList(&list2);
}