#include "../include/DCirLinkList.h"
#include <stdbool.h>
#include <stdio.h>
void DLinkListInsertTest();
void DLinkListPushTest();
void IsDLinkListSymmetricalTest();
int main(){
// DLinkListInsertTest();
//  DLinkListPushTest();
IsDLinkListSymmetricalTest();
}
void DLinkListInsertTest(){
	DCirLinkList list;
	InitDLinkList(&list);
	for (int i = 0; i<15; i++) {
		DLinkListInsert(&list, 0, i);
	}
	PrintDLinkList(&list);	
	PrintRDLinkList(&list);
	DestroyDLinkList(&list);
}
void DLinkListPushTest(){
	DCirLinkList list;
	InitDLinkList(&list);
	for (int i = 0; i<15; i++) {
		DLinkListPush(&list, i);
	}
	PrintDLinkList(&list);	
	PrintRDLinkList(&list);
	DestroyDLinkList(&list);
}
void IsDLinkListSymmetricalTest(){
	DCirLinkList list;
	InitDLinkList(&list);
	//头节点。
	DLinkListPush(&list, -1);
	DLinkListPush(&list, 1);
	bool is_sym = IsDLinkListSymmetrical(&list);
	
	PrintDLinkListWithoutHead(&list);	

	printf("Is sym :%d\n",is_sym);
	DLinkListPush(&list, 1);
	PrintDLinkListWithoutHead(&list);	
	is_sym = IsDLinkListSymmetrical(&list);
	printf("Is sym :%d\n",is_sym);
		DLinkListPush(&list, 2);
	PrintDLinkListWithoutHead(&list);	
	is_sym = IsDLinkListSymmetrical(&list);
	printf("Is sym :%d\n",is_sym);
	DLinkListPush(&list, 1);
	DLinkListPush(&list, 1);
	PrintDLinkListWithoutHead(&list);	
	is_sym = IsDLinkListSymmetrical(&list);
	printf("Is sym :%d\n",is_sym);
	DestroyDLinkList(&list);
}