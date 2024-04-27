#ifndef SDLINKLIST
#define SDLINKLIST
#define  MaxSize 50
#define  ElemType int
#include <stdbool.h>
typedef struct SDLinkNode{
	ElemType data;
	struct SDLinkNode *prior,*next;
} SDLinkNode;

void InitSDLinkNode(SDLinkNode *node,ElemType e);

typedef struct SDLinkList{
	SDLinkNode nodes[MaxSize];
	int length;
} SDLinkList;

void InitSDLinkList(SDLinkList *L);

#endif