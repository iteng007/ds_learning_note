#include "../include/DLinkList.h"
void DLinkListInsertTest();
int main(){
DLinkListInsertTest();
}
void DLinkListInsertTest(){
	DLinkList list;
	InitDLinkList(&list);
	for (int i = 0; i<15; i++) {
		DLinkListInsert(&list, 0, i);
	}
	PrintDLinkList(&list);	
	PrintRDLinkList(&list);
	DestroyDLinkList(&list);
}
