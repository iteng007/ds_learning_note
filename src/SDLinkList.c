#include <stddef.h>
#include "../include/SDLinkList.h"

void InitSDLinkNode(SDLinkNode *node,ElemType e){
	node->prior = NULL;
	node->next = NULL;
	node->data =  e;
}

void InitSDLinkList(SDLinkList *L){
	L->length = 0;
}