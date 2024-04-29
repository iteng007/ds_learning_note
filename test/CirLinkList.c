#include "../include/CirLinkList.h"

void CirLinkPushTest();
void ConcatCirLinkTest();
int main(){
	 ConcatCirLinkTest();
}

void CirLinkPushTest(){
	CirLinkList list;
	InitCirLinkList(&list);
	for (int i = 0; i<15; i++) {
		CirLinkPush(&list, i);
	}
	PrintCirLink(&list);
	CirLinkDestroy(&list);
}

void ConcatCirLinkTest(){
	CirLinkList list1;
	InitCirLinkList(&list1);
	for (int i = 0; i<7; i++) {
		CirLinkPush(&list1, i);
	}
	CirLinkList list2;
	InitCirLinkList(&list2);
	for (int i = 0; i<7; i++) {
		CirLinkPush(&list2, i+1);
	}
	ConcatCirLink(&list1, &list2);
	PrintCirLink(&list1);
	CirLinkDestroy(&list1);
}