#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/DLinkList.h"

void InitDNode(DNode *node,ElemType e){
	node->data = e;
	node->next = NULL;
	node->prior = NULL;
}


void InitDLinkList(DLinkList *L){
	L->head = L->tail = NULL;
	L->length = 0;
}
bool DLinkListInsert(DLinkList *L,int i ,ElemType e){
	if (i>L->length||i<0) {
		return false;
	}
	DNode * node =  malloc(sizeof(DNode));
	InitDNode(node,e);
	if (L->length==0) {
		L->head = node;
		L->tail = node;
		node->next = node;
		node->prior = node;
		L->length++;
		return true;
	}
	if (i==0) {
		DNode * o_head = L->head;
		node->next = o_head;
		node->prior  = L->tail;
		o_head->prior = node;
		L->tail->next = node;
		L->head = node;
		L->length++;
		return true;
	}
	DNode * walk = L->head;
	while (i>1) {
		walk = walk->next;
		i--;
	}
	DNode * temp = walk->next;
	walk->next = node;
	node->prior = walk;
	node->next = temp;
	temp->prior = node;
	L->length++;
	if (node->next == L->head) {
		L->tail = node;
	}
	return true;
}

bool DLinkListDelete(DLinkList *L,int i,ElemType *e){
	if (i<0||i>=L->length) {
		return false;
	}

}

void PrintDLinkList(DLinkList *L){
	int length = L->length;
	DNode *walk = L->head;
	while (length>0) {
		printf("%d\t",walk->data);
		walk =walk->next;
		length--;
	}
	printf("\n");
}

void PrintRDLinkList(DLinkList *L){
	int length = L->length;
	DNode *walk = L->tail;
	while (length>0) {
		printf("%d\t",walk->data);
		walk =walk->prior;
		length--;
	}
	printf("\n");
}

void DestroyDLinkList(DLinkList *L){
	DNode * walk = L->head;
	DNode * temp;
	int count = L->length;
	while (count>0) {
		temp =walk;
		walk = walk->next;
		free(temp);
		count--;
	}
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
}