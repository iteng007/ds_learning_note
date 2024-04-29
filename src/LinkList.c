#include "../include/LinkList.h"
#include "../include/Algorithms.h"
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



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

void PrintLinkListWithOutFakeHead(LinkList *L) {
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

int LNodeCompare(LNode *L, LNode *R) {
  if (L < R) {
    return -1;
  } else if (L == R) {
    return 0;
  }
  return 1;
}

void LNodeSwap(LNode **L, LNode **R) {
  LNode *temp = *L;
  *L = *R;
  *R = temp;
}

// 最简单粗暴：哈希表，但我现在还没实现。
// 或者存数组，数组按链表节点地址排序。
// 然后就转化为找两个数组相同元素。
LNode **CommonLNode(LinkList *L, LinkList *R, int *len) {
  LNode *nodesl[L->length - 1]; // 去除头结点。
  LNode *nodesr[R->length - 1];
  LNode *walkl = L->head->next;
  LNode *walkr = R->head->next;
  for (int i = 0; walkl; i++, walkl = walkl->next) {
    nodesl[i] = walkl;
  }
  printf("\n");
  for (int i = 0; walkr; i++, walkr = walkr->next) {
    nodesr[i] = walkr;
  }
  QuickSort((void **)nodesl, L->length - 1, (CompareFunc)LNodeCompare,
            (SwapFunc)LNodeSwap);
  QuickSort((void **)nodesr, R->length - 1, (CompareFunc)LNodeCompare,
            (SwapFunc)LNodeSwap);
  int lenth = L->length > R->length ? L->length : R->length;
  LNode **result = malloc(sizeof(LNode *) * lenth);

  int i = 0, j = 0;
  int output_index = 0;
  while (i < L->length - 1 && j < R->length - 1) {
    if (nodesl[i] == nodesr[j]) {
      result[output_index++] = nodesl[i];
      i++;
      j++;
    } else if (nodesl[i] < nodesr[j]) {
      i++;
    } else {
      j++;
    }
  }
  *len = output_index;
  return result;
}

void LinkListDivide(LinkList *L, LinkList *R) {
  // i为偶数放入L
  // i为奇数放入R
  // 即将奇数R的从L中删除然后链接。
  // 垃圾头节点
  LinkListPush(R, -1);
  LNode *walk = L->head->next;
  LNode *temp;
  while (walk->next) {
    temp = walk->next;
    if (!temp->next) {
      L->tail = walk;
    }
    walk->next = walk->next->next;
    // 删除
    // 放入R的末尾
    R->tail->next = temp;
    R->tail = temp;
    R->length++;
    L->length--;
    if (!walk->next) {
      break;
    }
    walk = walk->next;
  }
}
void LinkListStatus(LinkList *L) {
  printf("Without fake head:\n");
  PrintLinkListWithOutFakeHead(L);
  printf("With fake head:\n");
  PrintLinkList(L);
  printf("Fake head:\t%d\n", L->head->data);
  if (L->head->next) {
    printf("Head:\t%d\n", L->head->next->data);
  }
  printf("Tail:\t%d\n", L->tail->data);
}

void LinkListDeDup(LinkList *L) {
  LNode *walk = L->head;
  LNode *temp;
  LNode *to_free;
  while (walk->next) {
    temp = walk->next->next;
    while (temp && walk->next->data == temp->data) {
      to_free = temp;
      if (to_free->next == NULL) {
        L->tail = walk->next;
      }
      temp = temp->next;
      L->length--;
      free(to_free);
    }
    walk->next->next = temp;
    walk = walk->next;
  }
}

LinkList *CreateLinkListFromCommonNodeVal(LinkList *L, LinkList *R) {
  LinkList *result = malloc(sizeof(LinkList));
  InitLinkList(result);
  LinkListPush(result, -1); // 头节点；
  LNode *walkl = L->head;
  LNode *walkr = R->head;
  while (walkl->next && walkr->next) {
    if (walkl->next->data == walkr->next->data) {
      LinkListPush(result, walkl->next->data);
      walkl = walkl->next;
      walkr = walkr->next;
    } else if (walkl->next->data < walkr->next->data) {
      walkl = walkl->next;
    } else {
      walkr = walkr->next;
    }
  }
  return result;
}

void LinkListIntersection(LinkList *L, LinkList *R) {
  LNode *walkl = L->head;
  LNode *walkr = R->head;
  LNode *arr[L->length];
  LNode *to_free[L->length];
  int index = 0;
  int index_free = 0;
  while (walkl && walkl->next && walkr && walkr->next) {
    if (walkl->next->data == walkr->next->data) {
      walkl = walkl->next;
      walkr = walkr->next;
      arr[index++] = walkl;
    } else {
      if (walkl->next->data < walkr->next->data) {
        walkl = walkl->next;
        to_free[index_free++] = walkl;
      } else {
        walkr = walkr->next;
      }
    }
  }
  LNode *walk = L->head;
  for (int i = 0; i < index; i++) {
    walk->next = arr[i];
    walk = walk->next;
  }
  walk->next = NULL;
  for (int i = 0; i < index_free; i++) {
    free(to_free[i]);
  }
  L->length = index;
};

bool IsSubLinkListVal(LinkList *L,LinkList *R){
   LNode * walkl =  L->head;
   LNode * walkr =  R->head;
   LNode *arr[L->length];
   int index = 0;
   while (walkl->next&&walkr->next) {
        if (walkl->next->data==walkr->next->data) {
            walkl =walkl->next;
            walkr = walkr->next;
            arr[index++] = walkr;
        }else if (walkl->next->data<walkr->next->data) {
            walkl = walkl->next;
        }else {
            walkr = walkr->next;
        }
   }
   walkr = R->head;
   int i = 0;
   while (walkr->next&&i<index) {
      if (walkr->next!=arr[i]) {
        return false;
      }
      walkr = walkr->next;
      i++;
   }
   if (!(walkr&&!walkr->next&&i==index)) {
    return false;
   }
   return true;
}