#ifndef DLINKLISTFREQ
#define DLINKLISTFREQ
#include "DNode.h"
#include "SeqList.h"
typedef struct DLinkListFreq{
	struct DNodeFreq * head;
	struct DNodeFreq * tail;
	int length;
}DLinkListFreq;

void DLinkListFreqInit(DLinkListFreq *L);

DNodeFreq *DLinkListFreqLocateElem(DLinkListFreq *L, ElemType e); 


void DLinkListFreqPush(DLinkListFreq *L,ElemType e);

void PrintDLinkListFreq(DLinkListFreq *L);

void DestroyDLinkListFreq(DLinkListFreq *L);
#endif