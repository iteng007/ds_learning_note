#ifndef DNODE
#define DNODE
#define  ElemType int
typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode;

/**
 * @brief 初始化一个双向链表节点
 * 
 * @param node 
 */
void InitDNode(DNode *node,ElemType e);
#endif