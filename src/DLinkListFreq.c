#include "../include/DLinkListFreq.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief 按照p43第13题的定义，每次locate到了就将node的freq+1。
 * 然后将freq更高的放置在更前面，freq相同则将更近访问的放置在前面
 * 
 * @param L 
 * @param e 
 * @return DNodeFreq* 
 */
DNodeFreq *DLinkListFreqLocateElem(DLinkListFreq *L, ElemType e){
	DNodeFreq*walk = L->head;
	while (walk) {
	if (walk->data == e) {
		walk->freq++;
		DNodeFreq * result = walk;
		walk = L->head;
		if (result==walk) {
			walk = walk->next;
		}
		//先无脑断开原本链接。
		if (result->prior) {
			result->prior->next = result->next;
		}
		if (result->next) {
			result->next->prior = result->prior;
		}
		result->next = NULL;
		result->prior = NULL;
		//找到新位置
		while (walk&&result->freq<walk->freq) {
			walk = walk->next;
		}
		//找到第一个比result小或等于的节点，放它前面
		if (walk) {
			result->prior = walk->prior;
			result->next = walk;
			if (walk->prior) {
				walk->prior->next = result;
			}
			walk->prior = result;
			if (walk==L->head) {
				L->head = result;
			}
		}else {
		    result->next = NULL;
			result->prior = L->tail;
			L->tail->next = result;
			L->tail = result;
		}
		return result;
	}
    walk = walk->next;
  }
  return NULL;
}

void DLinkListFreqPush(DLinkListFreq *L,ElemType e){
	L->length++;
	DNodeFreq * node = malloc(sizeof(DNodeFreq));
	InitDNodeFreq(node, e);
	if (L->length==1) {
	  L->head = node;
	  L->tail = node;
	  return;
	}
	node->prior = L->tail;
	L->tail->next = node;
	L->tail = node;
}

void PrintDLinkListFreq(DLinkListFreq *L){
	DNodeFreq * walk = L->head;
	while (walk) {
		printf("data:\t%d,freq:\t%d\t",walk->data,walk->freq);
		walk =walk->next;
	}
	printf("\n");
}

void DestroyDLinkListFreq(DLinkListFreq *L){
	DNodeFreq * walk = L->head;
	DNodeFreq * temp;
	while (walk) {
		temp = walk;
		walk = walk->next;
		free(temp);
	}
	free(L);
}

void DLinkListFreqInit(DLinkListFreq *L){
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
}