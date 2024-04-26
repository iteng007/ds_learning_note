#ifndef SEQLIST
#define SEQLIST

#define InitSize 50
#define ElemType int
#include <stdbool.h>
typedef struct {
  ElemType *data;
  int MaxSize, Length;
} SeqList;

void InitList(SeqList *L);
int Length(SeqList *L);
int LocateElem(SeqList *L, ElemType e);
bool ListInsert(SeqList *L, int i, ElemType e);
bool ListDelete(SeqList *L, int i, ElemType *e);
void PrintList(SeqList *L);
bool Empty(SeqList *L);
void DestroyList(SeqList *L);
/**
 * @brief 找到顺序表中的元素e
 * 
 * @param L 
 * @param e 
 * @param index 找到则为对应下标，否则为一个离e最近的值下标
 * @return 若找到，返回true，否则false
 */
bool BinarySearch(SeqList *L,ElemType e,int * index);

/**
 * @brief 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位
 * 置由最后一个元素填补,若顺序表为空,则显示出错信息并退出运行。
 *
 * @param L 指向待操作的顺序表的指针
 * @return 若成功删除最小值，则返回true；否则返回false
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
bool DeleteMinimum(SeqList *L);
/**
 * @brief p19.02：
 * 将顺序表L的所有元素逆置,要求算法的空间复杂度为0(1)。
 *
 * @param L 指向待操作的顺序表的指针
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
void ReverseSeqList(SeqList *L);
/**
 * @brief p19.03 对长度为n的顺序表L,编写一个时间复杂度为O(n)、空间复杂度为(1)的算法,该算
 * 法删除顺序表中所有值为x的数据元素。
 *
 * @param L 指向待操作的顺序表的指针
 * @param X 待删除的元素值
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 算法设计思想：使用numnx 记录所有非x元素,并跟踪当前已移动的位置。
 * 随后将非x元素依次向前移动
 */
void DeleteElemX(SeqList *L,ElemType X);
/**
 * @brief 从顺序表中删除其值在给定值s和t之间(包含s和t,要求s<t)的所有元素,若s或
 * t不合理或顺序表为空,则显示出错信息并退出运行。
 *
 * @param L 指向待操作的顺序表的指针
 * @param S 下限值
 * @param T 上限值
 * @return 若成功删除，则返回true；否则返回false
 *
 * 算法设计思想：可以考虑使用DeleteElemX 相同思想，实现O(n)的时间复杂度完成删除
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
bool DeleteRangeSandT(SeqList *L,ElemType S,ElemType T);
/**
 * @brief p19.05 双指针.从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同。
 *
 * @param L 指向待操作的顺序表的指针
 *
 * 算法设计思想：双指针。一根指针指向下一个需要被非重复元素替换的位置，一根用于遍历找到下一个非重复元素。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
void DeDupSortedSeqList(SeqList * L);

/**
 * @brief p19.06 合并两个已排序的顺序表
 * 
 * 此函数将两个已排序的顺序表合并为一个新的顺序表，并将结果存储在output中。
 * 
 * @param L 左侧顺序表
 * @param R 右侧顺序表
 * @param output 合并结果的顺序表
 * @return 合并是否成功，成功返回true，否则返回false
 */
bool MergeSortedSeqList(SeqList *L, SeqList *R, SeqList *output);

/**
 * @brief p19.07 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2, a3,･･･,am)和(b1,b2,b3...,b)。编写一
 * 个函数,将数组中两个顺序表的位置互换,即将(b1,b2,b₃,.., b)放在(a1,a2, a3,…,am)的前面。
 * 
 * @param L 
 * @param m 一维数组中前半部分数组的长度
 * @param n 一维数组中后半部分数组的长度
 */
void MNReverse(SeqList *L,int m,int n);

/**
 * @brief p19 08 线性表(a1, a2, a3,…, an)中的元素递增有序且按顺序存储于计算机内。要求设计一个算法,
 * 完成用最少时间在表中查找数值为x的元素,若找到,则将其与后继元素位置相交换,
 * 若找不到,则将其插入表中并使表中元素仍递增有序。
 * 
 * @param L 
 * @param x 
 * 算法设计思想：二分查找。
 */
void FindAndExchangeX(SeqList *L,ElemType x);

/**
 * @brief  p19.09 给定三个序列A、B、C、长度均为n,且均为无重复元素的递增序列,请设计一个时间
 *上尽可能高效的算法,逐行输出同时存在于这三个序列中的所有元素。例如,数组A为
 * {1,2,3},数组B为{2,3,4},数组C为{-1,0,2},则输出2
 * 
 * @param L1 
 * @param L2 
 * @param L3 
 * 算法设计思想：使用三个下标变量从小到大遍历数组。当三个下标变量指向的元素相等时,输出并向前推进
 * 指针,否则仅移动小于最大元素的下标变量,直到某个下标变量移出数组范围,即可停止。
 * 算法复杂度分析：每个指针移动的次数不超过n次,且每次循环至少有一个指针后移,所以时间复杂度为
 * O(n),算法只用到了常数个变量,空间复杂度为0(1)。
 */
void OutputCommonElem(SeqList *L1,SeqList *L2,SeqList *L3);

/**
 * @brief 找到两个等长升序顺序表中的中位数
 * 
 * @param L1 
 * @param L2 
 * @return ElemType 
 * 算法设计思想：
 */
ElemType FindMedianOfTwoSeqList(SeqList *L1,SeqList *L2);
#endif

