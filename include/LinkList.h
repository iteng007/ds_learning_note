#ifndef LINKLIST
#define LINKLIST
#define  ElemType int
#include "LNode.h"
#include <stdbool.h>



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
void InitLinkList(LinkList *L);

/**
 * @brief 返回链表长
 * 
 * @param L 
 * @return int 链表长
 */
int LinkListLength(LinkList *L);

/**
 * @brief 返回第i个链表节点
 * 
 * @param L 
 * @return LNode* 
 */
LNode * LinkListGetELem(LinkList *L,int i);

/**
 * @brief 按照查找链表节点
 * 
 * @param L 
 * @param e 
 * @return LNode* 存在返回对应节点，否则NULL
 */
LNode * LinkListLocateElem(LinkList *L,ElemType e);

void PrintLinkList(LinkList *L);
/**
 * @brief 将元素e插入链表
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 成功插入
 * @return false i非法
 */
bool LinkListInsert(LinkList *L,int i,ElemType e);

/**
 * @brief 删除链表中第i个节点
 * 
 * @param L 
 * @param i 
 * @param e 
 * @return true 成功删除节点，并将被删除节点所存值放入e
 * @return false 没有该节点
 */
bool LinkListDelete(LinkList *L,int i,ElemType *e);

/**
 * @brief 往链表队尾插入元素e
 * 
 * @param L 
 * @param e 
 */
void LinkListPush(LinkList *L,ElemType e);
/**
 * @brief 打印链表内容
 * 
 * @param L 
 */


void PrintLinkListWithOutFakeHead(LinkList *L);
/**
 * @brief 单链表的析构函数
 * 
 * @param L 
 */

void DestroyLinkList(LinkList *L);

void DeleteNodeWithValueX(LinkList *L,ElemType X);

/**
 * @brief 
 * 
 * @param L 带头节点的链表。 
 */
void DelteMinValueNode(LinkList *L);

/**
 * @brief 原地逆置
 * 
 * @param L 带头节点的链表。 
 */
void ReverseLinkList(LinkList *L);

void LinkListDeleteRange(LinkList *L,ElemType start,ElemType end);

/**
 * @brief p43.05返回两个链表的公共节点的数组，LNode *的内存应由caller释放。
 * 
 * @param L 
 * @param R 
 * @param len 该数组的长度
 * @return LNode** 
 */
LNode ** CommonLNode(LinkList *L,LinkList *R,int *len);

/**
 * @brief 
 * 
 * @param L 
 * @param R 
 */
void LinkListDivide(LinkList *L,LinkList *R);

void LinkListStatus(LinkList *L);

void LinkListDeDup(LinkList *L);

LinkList *CreateLinkListFromCommonNodeVal(LinkList *L,LinkList *R);
/**
 * @brief 找出两个链表的值的交集，并放置在L1中，其余节点会被释放。
 * 
 * @param L 
 * @param R 
 */
void LinkListIntersection(LinkList *L,LinkList *R);
/**
 * @brief 根据值判断R是否为L的子序列
 * 
 * @param L 
 * @param R 
 */
bool IsSubLinkListVal(LinkList *L,LinkList *R);

/**
 * @brief p44.14 循环右移K
 * L:0->1->2->3 N:1
 * Result: 3->0->1->2
 * @param L 
 * @param N 
 */
void LinkListRightShiftK(LinkList *L,int K);

/**
 * @brief p44.16
 * 孪生节点和的定义为第i个节点与第L.length-i-1个节点的和
 * i从0开始
 * @param L 
 * @return ElemType 最大孪生节点和
 */
ElemType LinkListMaxTwinVal(LinkList *L);
#endif