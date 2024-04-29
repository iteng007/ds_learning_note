#ifndef DLINKLIST
#define DLINKLIST
#define ElemType int
#include <stdbool.h>
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

/**
 * @brief 双向循环链表
 * 
 */
typedef struct DLinkList{
	struct DNode * head;
	struct DNode * tail;
	int length;
}DLinkList;

/**
 * @brief 初始化一个循环链表
 * 
 * @param L 
 */
void InitDLinkList(DLinkList *L);
/**
 * @brief 将元素e插入双向链表的第i个位置
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 插入成功
 * @return false 下标非法
 */
bool DLinkListInsert(DLinkList *L,int i ,ElemType e);

/**
 * @brief 删除双向循环链表L第i个元素并将值放入e
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 
 * @return false 
 */
bool DLinkListDelete(DLinkList *L,int i,ElemType *e);

/**
 * @brief 打印双向链表
 * 
 * @param L 
 */
void PrintDLinkList(DLinkList *L);

void DestroyDLinkList(DLinkList *L);
/**
 * @brief 逆序打印
 * 
 * @param L 
 */
void PrintRDLinkList(DLinkList *L);
void PrintDLinkListWithoutHead(DLinkList *L);
void DLinkListPush(DLinkList *L,ElemType e);
/**
 * @brief 带头结点，即认为第一个头是假头。
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool IsDLinkListSymmetrical(DLinkList * L);
#endif