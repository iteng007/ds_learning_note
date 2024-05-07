#ifndef DLINKLIST
#define DLINKLIST
#include "DNode.h"
typedef struct DLinkList{
	struct DNode * head;
	struct DNode * tail;
	int length;
}DLinkList;
#endif