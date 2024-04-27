#ifndef LINKLIST
#define LINKLIST
#define  ElemType int
#include <stdbool.h>
/**
 * @brief 单链表
 * 
 */
typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LNode;

/**
 * @brief 使用e初始化节点L
 * 
 * @param L 
 * @param e 
 */
void InitLNode(LNode * L,ElemType e);


typedef struct LinkList{
	LNode * head;
	LNode * tail;
	int length;
}LinkList;
/**
 * @brief 初始化链表
 * 
 * @param L 链表指针
 */
void InitList(LinkList *L);

/**
 * @brief 返回链表长
 * 
 * @param L 
 * @return int 链表长
 */
int Length(LinkList *L);

/**
 * @brief 返回第i个链表节点
 * 
 * @param L 
 * @return LNode* 
 */
LNode * GetELem(LinkList *L,int i);

/**
 * @brief 按照查找链表节点
 * 
 * @param L 
 * @param e 
 * @return LNode* 存在返回对应节点，否则NULL
 */
LNode * LocateElem(LinkList *L,ElemType e);


/**
 * @brief 将元素e插入链表
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 成功插入
 * @return false i非法
 */
bool ListInsert(LinkList *L,int i,ElemType e);

/**
 * @brief 删除链表中第i个节点
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 成功删除节点，并将被删除节点所存值放入e
 * @return false 没有该节点
 */
bool ListDelete(LinkList *L,int i,ElemType *e);

/**
 * @brief 往链表队尾插入元素e
 * 
 * @param L 
 * @param e 
 */
void ListPush(LinkList *L,ElemType e);
/**
 * @brief 打印链表内容
 * 
 * @param L 
 */
void PrintList(LinkList *L);

/**
 * @brief 单链表的析构函数
 * 
 * @param L 
 */

void DestroyList(LinkList *L);
#endif