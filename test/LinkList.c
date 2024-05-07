#include "../include/LinkList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
void LinkListDivideTest();
void  LinkListDeDupTest();
void CreateLinkListFromCommonNodeValTest();
void LinkListIntersectionTest();
void IsSubLinkListValTest();
void IsSubLinkListValTest2();
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
	// CommonLNodeTest();
	// LinkListDivideTest();
	// LinkListDeDupTest();
	// CreateLinkListFromCommonNodeValTest();
	// LinkListIntersectionTest();
	// IsSubLinkListValTest();
	IsSubLinkListValTest2();
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
		LNode * node = LinkListFreqLocateElem(&list, i);
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
	PrintLinkListWithOutFakeHead(&list);
	DeleteNodeWithValueX(&list,1);
	PrintLinkListWithOutFakeHead(&list);
	DestroyLinkList(&list);
}

void DelteMinValueNodeTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list,0,i);
	}
	PrintLinkListWithOutFakeHead(&list);
	DelteMinValueNode(&list);
	PrintLinkListWithOutFakeHead(&list);
	DestroyLinkList(&list);
}
void ReverseLinkListTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list,0,i);
	}
	PrintLinkListWithOutFakeHead(&list);
	ReverseLinkList(&list);
	PrintLinkListWithOutFakeHead(&list);
	DestroyLinkList(&list);
}

void LinkListDeleteRangeTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list,0,i);
	}
	PrintLinkListWithOutFakeHead(&list);
	LinkListDeleteRange(&list,7,13);
	PrintLinkListWithOutFakeHead(&list);
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
	PrintLinkListWithOutFakeHead(&list1);
	PrintLinkListWithOutFakeHead(&list2);
	list1.tail->next = list2.head->next;
	list1.tail = list2.tail;
	list1.length+=(list2.length-1);
	int len;
	LNode ** result = CommonLNode(&list1, &list2, &len);
	for (int i = 0; i<len; i++) {
		printf("%d\t",result[i]->data);
	}
	printf("\n");
	free(result);
	DestroyLinkList(&list1);
	free(list2.head);
}


void LinkListDivideTest(){
	LinkList list;
	InitLinkList(&list);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list,0,i);
	}
	PrintLinkListWithOutFakeHead(&list);
	LinkList list2;
	InitLinkList(&list2);
	LinkListDivide(&list, &list2);
	PrintLinkListWithOutFakeHead(&list);
	PrintLinkListWithOutFakeHead(&list2);
	DestroyLinkList(&list);
	DestroyLinkList(&list2);
}

void LinkListDeDupTest(){
	LinkList list;
	InitLinkList(&list);
	LinkListInsert(&list, 0, -1);//头节点
	for (int i = 0 ; i<5; i++) {
		LinkListPush(&list, 1);
	}
	for (int i = 0; i<3; i++) {
		LinkListPush(&list, 2);
	}
	PrintLinkListWithOutFakeHead(&list);
	LinkListDeDup(&list);
	PrintLinkListWithOutFakeHead(&list);
	LinkListStatus(&list);
	DestroyLinkList(&list);
}
void CreateLinkListFromCommonNodeValTest(){
	LinkList list1;
	InitLinkList(&list1);
	LinkList list2;
	InitLinkList(&list2);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list1,0,i);
	}
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list2,0,i*2);
	}
	PrintLinkListWithOutFakeHead(&list1);
	PrintLinkListWithOutFakeHead(&list2);
	LinkList * new_list = CreateLinkListFromCommonNodeVal(&list1, &list2);
	PrintLinkListWithOutFakeHead(new_list);	
	DestroyLinkList(new_list);
	free(new_list);
	DestroyLinkList(&list1);
	DestroyLinkList(&list2);
}


void LinkListIntersectionTest(){
	LinkList list1;
	InitLinkList(&list1);
	LinkList list2;
	InitLinkList(&list2);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list1,0,i);
	}
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list2,0,i*2);
	}
	PrintLinkListWithOutFakeHead(&list1);
	PrintLinkListWithOutFakeHead(&list2);
	LinkListIntersection(&list1, &list2);
	PrintLinkListWithOutFakeHead(&list1);
	DestroyLinkList(&list1);
	DestroyLinkList(&list2);
}
void IsSubLinkListValTest(){
	LinkList list1;
	InitLinkList(&list1);
	LinkList list2;
	InitLinkList(&list2);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list1,0,i);
	}
	for (int i = 6 ; i>0; i--) {
		LinkListInsert(&list2,0,i*2);
	}
	PrintLinkListWithOutFakeHead(&list1);
	PrintLinkListWithOutFakeHead(&list2);
	bool is_sub = IsSubLinkListVal(&list1, &list2);
	printf("Is sub ?: %d",is_sub);
	DestroyLinkList(&list1);
	DestroyLinkList(&list2);
}
void IsSubLinkListValTest2(){
	LinkList list1;
	InitLinkList(&list1);
	LinkList list2;
	InitLinkList(&list2);
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list1,0,i);
	}
	for (int i = 15 ; i>0; i--) {
		LinkListInsert(&list2,0,i*2);
	}
	PrintLinkListWithOutFakeHead(&list1);
	PrintLinkListWithOutFakeHead(&list2);
	bool is_sub = IsSubLinkListVal(&list1, &list2);
	printf("Is sub ?: %d",is_sub);
	DestroyLinkList(&list1);
	DestroyLinkList(&list2);
}