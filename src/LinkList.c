#include "../include/LinkList.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void InitLNode(LNode * L,ElemType e){
	L->data = e;
	L->next = NULL;
}


void InitList(LinkList *L){
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
}

int Length(LinkList *L){
	return L->length;
}

LNode * GetELem(LinkList *L,int i){\
	if (i<0||i>L->length) {
		return NULL;
	}
	LNode * walk = L->head;
	while (walk&&i) {
		walk = walk->next;
		i--;
	}
	return walk;
}

LNode * LocateElem(LinkList *L,ElemType e){
	LNode *walk = L->head;
	while (walk) {
		if (walk->data == e) {
			return walk;
		}
		walk = walk->next;
	}
	return NULL;
}
bool ListInsert(LinkList *L,int i,ElemType e){
	if (i<0||i>L->length) {
		return false;
	}
	LNode * node = malloc(sizeof(LNode));
	InitLNode(node, e);
	if (L->length==0) {
		L->head = node;
		L->tail = node;
		L->length++;
		return true;
	}
	if (i==0) {
		node->next = L->head;
		L->head = node;
		L->length++;
		return true;
	}
	if (i==L->length) {
		L->tail->next = node;
		L->tail = node;
		L->length++;
		return true;
	}
	LNode * walk = L->head;
	while (walk&&i>1) {
		walk = walk->next;
		i--;
	}
	node->next = walk->next;
	walk->next = node;
	L->length++;
	return true;
}

bool ListDelete(LinkList *L,int i,ElemType *e){
	if (i<0||i>=L->length) {
		return false;
	}
	LNode * walk = L->head;
	if (i==0) {
		*e = L->head->data;
		L->head = walk->next;
		free(walk);
		L->length--;
		return true;
	}	
	while (walk&&i>1) {
		walk = walk->next;
		i--;
	}
	LNode *to_delete = walk->next;
	*e = to_delete->data;
	walk->next = walk->next->next;
	free(to_delete);
	if (!walk->next) {
		L->tail= walk->next;
	}
	L->length--;
	return true;
}

void ListPush(LinkList *L,ElemType e){
	LNode * node = malloc(sizeof(LNode));
	InitLNode(node, e);
	if (L->length==0) {	
		L->head = node;
	}else {
	   LNode *tail = L->tail;
	   L->tail->next = node;
	}
	L->tail = node;
	L->length++;
}

void PrintList(LinkList *L){
	LNode * walk = L->head;
	while (walk) {
		printf("%d\t",walk->data);
		walk = walk->next;
	}
	printf("\n");
}

void DestroyList(LinkList *L){
	LNode * walk = L->head;
	LNode * walk_next = walk->next;
	while (walk) {
		free(walk);
		walk = walk_next;
		if (walk_next) {
			walk_next = walk_next->next;
		}
	}
	L->head = NULL;
	L->tail = NULL;
	L->length  = 0;
}