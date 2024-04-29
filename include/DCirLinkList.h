#ifndef DCIRLINKLIST
#define DCIRLINKLIST
#define ElemType int
#include "DNode.h"
#include <stdbool.h>


/**
 * @brief 双向循环链表
 * 
 */
typedef struct DLinkList{
	struct DNode * head;
	struct DNode * tail;
	int length;
}DCirLinkList;

/**
 * @brief 初始化一个循环链表
 * 
 * @param L 
 */
void InitDLinkList(DCirLinkList *L);
/**
 * @brief 将元素e插入双向链表的第i个位置
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 插入成功
 * @return false 下标非法
 */
bool DLinkListInsert(DCirLinkList *L,int i ,ElemType e);

/**
 * @brief 删除双向循环链表L第i个元素并将值放入e
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 
 * @return false 
 */
bool DLinkListDelete(DCirLinkList *L,int i,ElemType *e);

/**
 * @brief 打印双向链表
 * 
 * @param L 
 */
void PrintDLinkList(DCirLinkList *L);

void DestroyDLinkList(DCirLinkList *L);
/**
 * @brief 逆序打印
 * 
 * @param L 
 */
void PrintRDLinkList(DCirLinkList *L);
void PrintDLinkListWithoutHead(DCirLinkList *L);
void DLinkListPush(DCirLinkList *L,ElemType e);
/**
 * @brief 带头结点，即认为第一个头是假头。
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool IsDLinkListSymmetrical(DCirLinkList * L);
#endif