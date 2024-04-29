#include "../include/CirLinkList.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
void InitCirLinkList(CirLinkList *L){
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
}

void CirLinkPush(CirLinkList *L,ElemType e){
	L->length++;
	LNode * node = malloc(sizeof(LNode));
	InitLNode(node, e);
	if (L->length==1) {
		L->head = node;
		L->tail = node;
		node->next = node;
		return;
	}
	node->next = L->head;
	L->tail->next = node;
	L->tail = node;
}

void CirLinkDestroy(CirLinkList *L){
	LNode * walk = L->head;
	LNode * temp;
	while (walk->next!=L->head) {
		temp = walk;
		walk = walk->next;
		free(temp);
	}
	if (walk) {
	free(walk);
	}
	
}

void PrintCirLink(CirLinkList *L){
	LNode * walk = L->head;
	LNode * temp;
	while (walk->next!=L->head) {
		printf("%d\t",walk->data);
		walk = walk->next;
	}
	if (walk) {
		printf("%d\t",walk->data);
	}
	printf("\n");
}

void ConcatCirLink(CirLinkList *L,CirLinkList *R){
	if (!L|!R) {
		return;
	}
	L->tail->next = R->head;
	R->tail->next = L->head;
	L->tail = R->tail;
}