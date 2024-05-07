#ifndef DNODE
#define DNODE
#include "SeqList.h"
#define  ElemType int
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode;


/**
 * @brief 根据p43的第12题所给描述
 * 
 */
typedef struct DNodeFreq{
	ElemType data;
	struct DNodeFreq *prior,*next;
	int freq;
}DNodeFreq;


/**
 * @brief 初始化一个双向链表节点
 * 
 * @param node 
 */
void InitDNode(DNode *node,ElemType e);
void InitDNodeFreq(DNodeFreq *node,ElemType e);
#endif