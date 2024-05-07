#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/DCirLinkList.h"



void InitCirDLinkList(DCirLinkList *L){
	L->head = L->tail = NULL;
	L->length = 0;
}
bool DLinkListInsert(DCirLinkList *L,int i ,ElemType e){
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

bool DLinkListDelete(DCirLinkList *L,int i,ElemType *e){
	if (i<0||i>=L->length) {
		return false;
	}

}

void PrintDLinkList(DCirLinkList *L){
	int length = L->length;
	DNode *walk = L->head;
	while (length>0) {
		printf("%d\t",walk->data);
		walk =walk->next;
		length--;
	}
	printf("\n");
}

void PrintDLinkListWithoutHead(DCirLinkList *L){
	int length = L->length;
	DNode *walk = L->head->next;
	while (length>1) {
		printf("%d\t",walk->data);
		walk =walk->next;
		length--;
	}
	printf("\n");
}

void PrintRDLinkList(DCirLinkList *L){
	int length = L->length;
	DNode *walk = L->tail;
	while (length>0) {
		printf("%d\t",walk->data);
		walk =walk->prior;
		length--;
	}
	printf("\n");
}

void DestroyDLinkList(DCirLinkList *L){
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

void DLinkListPush(DCirLinkList *L,ElemType e){
	L->length++;
	DNode *node = malloc(sizeof(DNode));
	InitDNode(node, e);
	if (L->length==1) {
		L->head = node;
		L->tail = node;
		node->next = node;
		node->prior = node;
		return;
	}
	node->prior = L->tail;
	node->next = L->head;
	L->tail->next = node;
	L->head->prior = node;
	L->tail = node;
}

bool IsDLinkListSymmetrical(DCirLinkList * L){
	DNode * walkh = L->head->next;
	DNode * walkt = L->tail;
	while (walkh!=walkt&&walkt->next!=walkh) {
		if (walkh->data!=walkt->data) {
			return false;
		}
		walkh = walkh->next;
		walkt = walkt->prior;
	}
	return true;
}