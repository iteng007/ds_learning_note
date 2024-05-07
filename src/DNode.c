#include "../include/DNode.h"
#include <stddef.h>
void InitDNode(DNode *node,ElemType e){
	node->data = e;
	node->next = NULL;
	node->prior = NULL;
}

void InitDNodeFreq(DNodeFreq *node,ElemType e){
	node->data = e;
	node->next = NULL;
	node->prior = NULL;
	node->freq = 0;
}