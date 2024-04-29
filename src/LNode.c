#include "../include/LNode.h"
#include <stddef.h>
void InitLNode(LNode *L, ElemType e) {
  L->data = e;
  L->next = NULL;
}