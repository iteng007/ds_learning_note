#include "../include/DLinkListFreq.h"
#include <complex.h>
#include <stdlib.h>
void DLinkListFreqPushTest();
void DLinkListFreqLocateTest();
int main(){
	// DLinkListFreqPushTest();
	DLinkListFreqLocateTest();
}

void DLinkListFreqPushTest(){
	DLinkListFreq * L = malloc(sizeof(DLinkListFreq));
	DLinkListFreqInit(L);
	for (int i  = 0; i<10; i++) {
		DLinkListFreqPush(L, i);
	}
	PrintDLinkListFreq(L);
	DestroyDLinkListFreq(L);
}

void DLinkListFreqLocateTest(){
	DLinkListFreq * L = malloc(sizeof(DLinkListFreq));
	DLinkListFreqInit(L);
	for (int i  = 0; i<10; i++) {
		DLinkListFreqPush(L, i);
	}
	PrintDLinkListFreq(L);
	for (int i = 0; i<10; i++) {
		for (int j = i; j>=0; j--) {
			DLinkListFreqLocateElem(L, i);
		}
	}
	PrintDLinkListFreq(L);
	DestroyDLinkListFreq(L);
}