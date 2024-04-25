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

bool DeleteMinimum(SeqList *L);
void ReverseSeqList(SeqList *L);
void DeleteElemX(SeqList *L,ElemType X);
bool DeleteRangeSandT(SeqList *L,ElemType S,ElemType T);
void DeDupSortedSeqList(SeqList * L);
bool MergeSortedSeqList(SeqList *L,SeqList *R,SeqList *output);
#endif
