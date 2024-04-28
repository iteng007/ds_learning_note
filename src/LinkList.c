#include "../include/LinkList.h"
#include "../include/Algorithms.h"
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void InitLNode(LNode *L, ElemType e) {
  L->data = e;
  L->next = NULL;
}

void InitLinkList(LinkList *L) {
  L->head = NULL;
  L->tail = NULL;
  L->length = 0;
}

int LinkListLength(LinkList *L) { return L->length; }

LNode *LinkListGetELem(LinkList *L, int i) {
  if (i < 0 || i > L->length) {
    return NULL;
  }
  LNode *walk = L->head;
  while (walk && i) {
    walk = walk->next;
    i--;
  }
  return walk;
}

LNode *LinkListLocateElem(LinkList *L, ElemType e) {
  LNode *walk = L->head;
  while (walk) {
    if (walk->data == e) {
      return walk;
    }
    walk = walk->next;
  }
  return NULL;
}
bool LinkListInsert(LinkList *L, int i, ElemType e) {
  if (i < 0 || i > L->length) {
    return false;
  }
  LNode *node = malloc(sizeof(LNode));
  InitLNode(node, e);
  if (L->length == 0) {
    L->head = node;
    L->tail = node;
    L->length++;
    return true;
  }
  if (i == 0) {
    node->next = L->head;
    L->head = node;
    L->length++;
    return true;
  }
  if (i == L->length) {
    L->tail->next = node;
    L->tail = node;
    L->length++;
    return true;
  }
  LNode *walk = L->head;
  while (walk && i > 1) {
    walk = walk->next;
    i--;
  }
  node->next = walk->next;
  walk->next = node;
  L->length++;
  return true;
}

bool LinkListDelete(LinkList *L, int i, ElemType *e) {
  if (i < 0 || i >= L->length) {
    return false;
  }
  LNode *walk = L->head;
  if (i == 0) {
    *e = L->head->data;
    L->head = walk->next;
    free(walk);
    L->length--;
    return true;
  }
  while (walk && i > 1) {
    walk = walk->next;
    i--;
  }
  LNode *to_delete = walk->next;
  *e = to_delete->data;
  walk->next = walk->next->next;
  free(to_delete);
  if (!walk->next) {
    L->tail = walk->next;
  }
  L->length--;
  return true;
}

void LinkListPush(LinkList *L, ElemType e) {
  LNode *node = malloc(sizeof(LNode));
  InitLNode(node, e);
  if (L->length == 0) {
    L->head = node;
  } else {
    LNode *tail = L->tail;
    L->tail->next = node;
  }
  L->tail = node;
  L->length++;
}

void PrintLinkList(LinkList *L) {
  LNode *walk = L->head;
  while (walk) {
    printf("%d\t", walk->data);
    walk = walk->next;
  }
  printf("\n");
}

void PrintLinkListWithFakeHead(LinkList *L) {
  LNode *walk = L->head->next;
  while (walk) {
    printf("%d\t", walk->data);
    walk = walk->next;
  }
  printf("\n");
}

void DestroyLinkList(LinkList *L) {
  LNode *walk = L->head;
  LNode *walk_next = walk->next;
  while (walk) {
    free(walk);
    walk = walk_next;
    if (walk_next) {
      walk_next = walk_next->next;
    }
  }
  L->head = NULL;
  L->tail = NULL;
  L->length = 0;
}
/**
 * @brief p43.01
 * 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一
 *
 * @param L 带头节点的单链表
 */
void DeleteNodeWithValueX(LinkList *L, ElemType X) {
  LNode *walk = L->head;
  LNode *temp;
  while (walk) {
    if (walk->next && walk->next->data == X) {
      temp = walk->next;
      walk->next = temp->next;
      free(temp);
      continue;
    }
    walk = walk->next;
  }
}

void DelteMinValueNode(LinkList *L) {
  LNode *walk = L->head;
  ElemType min = INT_MAX;
  LNode *min_node_prev = NULL;
  while (walk->next) {
    if (walk->next->data < min) {
      min_node_prev = walk;
      min = walk->next->data;
    }
    walk = walk->next;
  }
  if (min_node_prev) {
    LNode *to_free = min_node_prev->next;
    min_node_prev->next = min_node_prev->next->next;
    free(to_free);
  }
}

void ReverseLinkList(LinkList *L) {
  // 原头结点指针域指向原链表尾。
  // 其余节点指针域指向原直接前驱。
  // 首节点指针域为NULL
  LNode *prev = L->head;
  LNode *walk = L->head->next;
  LNode *temp;
  LNode *n_tail = L->head->next;
  while (walk) {
    temp = walk->next;
    if (prev == L->head) {
      walk->next = NULL;
    } else {
      walk->next = prev;
    }
    prev = walk;
    walk = temp;
  }
  LNode *o_tail = L->tail;
  L->tail = n_tail;
  L->head->next = o_tail;
}

void LinkListDeleteRange(LinkList *L, ElemType start, ElemType end) {
  LNode *walk = L->head;
  LNode *temp;
  while (walk->next) {
    if (walk->next->data > start && walk->next->data < end) {
      temp = walk->next;
      walk->next = temp->next;
      free(temp);
      continue;
    }
    walk = walk->next;
  }
}


int LNodeCompare(LNode *L,LNode *R){
	if (L<R) {
		return -1;
	}else if (L==R) {
		return 0;
	}
	return 1;
}

void LNodeSwap(LNode **L,LNode **R){
	LNode *temp = *L;
	*L = *R;
	*R = temp;
}

// 最简单粗暴：哈希表，但我现在还没实现。
// 或者存数组，数组按链表节点地址排序。
// 然后就转化为找两个数组相同元素。
LNode **CommonLNode(LinkList *L, LinkList *R, int *len) {
	LNode * nodesl[L->length-1];//去除头结点。
	LNode * nodesr[R->length-1];
	LNode * walkl = L->head->next;
	LNode * walkr = R->head->next;
	for (int i = 0; walkl; i++,walkl =walkl->next) {
		nodesl[i]  =walkl;
		printf("%p\t",walkl);
	}
	printf("\n");
	for (int i = 0; walkr; i++,walkr =walkr->next) {
		nodesr[i]  =walkr;
	}
	QuickSort((void**)nodesl, L->length-1, (CompareFunc)LNodeCompare, (SwapFunc)LNodeSwap);
	QuickSort((void**)nodesr, R->length-1, (CompareFunc)LNodeCompare, (SwapFunc)LNodeSwap);
	return NULL;
}