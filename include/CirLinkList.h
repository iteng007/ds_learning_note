#ifndef CIRLINKLIST
#define CIRLINKLIST
#define  ElemType int
#include "LinkList.h"
/**
 * @brief 循环单链表
 * 
 */
typedef struct CirLinkList{
	LNode * head;
	LNode * tail;
	int length;
}CirLinkList;

void InitCirLinkList(CirLinkList *L);

void CirLinkPush(CirLinkList *L,ElemType e);

void CirLinkDestroy(CirLinkList *L);

void PrintCirLink(CirLinkList *L);

void ConcatCirLink(CirLinkList *L,CirLinkList *R);
#endif