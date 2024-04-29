#ifndef LNODE
#define LNODE
#define ElemType int
typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LNode;
void InitLNode(LNode *L, ElemType e);
#endif

