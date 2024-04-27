#include "SeqList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// 在本实现中，认为i为数组下标，顺序表位置应为i+1
void InitList(SeqList *L) {
  L->Length = 0;
  L->data = malloc(sizeof(ElemType) * InitSize);
  L->MaxSize = InitSize;
}
int Length(SeqList *L) { return L->Length; };
int LocateElem(SeqList *L, ElemType e) {
  for (int i = 0; i < L->Length; i++) {
    if (L->data[i] == e) {
      return i;
    }
  }
  return -1;
};

bool ListInsert(SeqList *L, int i, ElemType e) {
  if (i < 0 || i > L->Length) {
    return false;
  }
  if (L->Length >= L->MaxSize) {
    return false;
  }
  for (int j = L->Length; j > i; j--) {
    L->data[j] = L->data[j - 1];
  }
  L->data[i] = e;
  L->Length++;
  return true;
}
bool ListDelete(SeqList *L, int i, ElemType *e) {
  if (i < 0 || i >= L->Length) {
    return false;
  }
  *e = L->data[i];
  for (int j = i; j < L->Length; j++) {
    L->data[j] = L->data[j - 1];
  }
  L->Length--;
  return true;
}
void PrintList(SeqList *L) {
  for (int i = 0; i < L->Length; i++) {
    printf("%d\t", L->data[i]);
  }
  printf("\n");
}
bool Empty(SeqList *L) { return L->Length == 0; }

void DestroyList(SeqList *L) {
  free(L->data);
  L->MaxSize = 0;
  L->Length = 0;
}
bool BinarySearch(SeqList *L, ElemType e, int *index) {
  int l = 0, r = L->Length - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2; // 防止溢出
    if (L->data[mid] == e) {
      *index = mid;
      return true;
    }
    if (L->data[mid] < e) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  *index = l;
  return false;
}

void ReverseRange(SeqList *L, int m, int n) {
  for (int i = m, j = n; i < j; i++, j--) {
    ElemType temp = L->data[i];
    L->data[i] = L->data[j];
    L->data[j] = temp;
  }
}
bool DeleteMinimum(SeqList *L) {
  if (L->Length == 0) {
    return false;
  }
  ElemType minimum = L->data[0];
  int index = 0;
  for (int i = 1; i < L->Length; i++) {
    if (L->data[i] < minimum) {
      minimum = L->data[i];
      index = i;
    }
  }
  L->data[index] = L->data[L->Length - 1];
  L->Length--;
  return true;
}

void ReverseSeqList(SeqList *L) { ReverseRange(L, 0, L->Length - 1); }

void DeleteElemX(SeqList *L, ElemType X) {
  int numnx = 0;
  for (int i = 0; i < L->Length; i++) {
    if (L->data[i] != X) {
      L->data[numnx] = L->data[i];
      numnx++;
    }
  }
  L->Length = numnx;
}

bool DeleteRangeSandT(SeqList *L, ElemType S, ElemType T) {
  if (L->Length == 0 || S >= T) {
    return false;
  }
  int numx = 0;
  for (int i = 0; i < L->Length; i++) {
    if (L->data[i] < S || L->data[i] > T) {
      L->data[numx] = L->data[i];
      numx++;
    }
  }
  L->Length = numx;
  return true;
}

void DeDupSortedSeqList(SeqList *L) {
  if (L->Length == 1) {
    return;
  }
  int i, j;
  for (i = 0, j = 1; j < L->Length; j++) {
    if (L->data[i] != L->data[j]) {
      L->data[++i] = L->data[j];
    }
  }
  L->Length = i + 1;
}

bool MergeSortedSeqList(SeqList *L, SeqList *R, SeqList *output) {
  if (output->MaxSize < L->Length + R->Length) {
    return false;
  }
  int i = 0, j = 0;
  int output_index = 0;
  while (i < L->Length && j < R->Length) {
    if (L->data[i] < R->data[j]) {
      output->data[output_index] = L->data[i++];
    } else {
      output->data[output_index] = R->data[j++];
    }
    output_index++;
  }
  while (i < L->Length) {
    output->data[output_index++] = L->data[i++];
  }
  while (j < R->Length) {
    output->data[output_index++] = R->data[j++];
  }
  output->Length = L->Length + R->Length;
  return true;
}

void MNReverse(SeqList *L, int m, int n) {
  ReverseSeqList(L);
  ReverseRange(L, 0, n - 1);
  ReverseRange(L, n, n + m - 1);
}

void FindAndExchangeX(SeqList *L, ElemType x) {
  int index;
  bool result = BinarySearch(L, x, &index);
  if (result) {
    ElemType temp = L->data[index];
    L->data[index] = L->data[index + 1];
    L->data[index + 1] = temp;
  } else {
    for (int i = L->Length; i > index; i--) {
      L->data[i] = L->data[i - 1];
    }
    L->data[index] = x;
  }
  L->Length++;
}

ElemType max(int *elem, int num) {
  int max_val = elem[0];
  for (int i = 0; i < num; i++) {
    if (elem[i] > max_val) {
      max_val = elem[i];
    }
  }
  return max_val;
}

ElemType min(int *elem, int num) {
  int min_val = elem[0];
  for (int i = 0; i < num; i++) {
    if (elem[i] < min_val) {
      min_val = elem[i];
    }
  }
  return min_val;
}


void OutputCommonElem(SeqList *L1, SeqList *L2, SeqList *L3) {
  int n = L1->Length;
  int i = 0, j = 0, k = 0;
  int elems[3];
  while (i < n && j < n && k < n) {
    if (L1->data[i] == L2->data[j] && L2->data[j] == L3->data[k]) {
      printf("%d\t", L1->data[i]);
      i++;
      j++;
      k++;
    } else {
      elems[0] = L1->data[i];
      elems[1] = L2->data[j];
      elems[2] = L3->data[k];
      int max_val = max(elems, 3);
      if (L1->data[i] < max_val) {
        i++;
      }
      if (L2->data[j] < max_val) {
        j++;
      }
      if (L3->data[k] < max_val) {
        k++;
      }
    }
  }
}

ElemType MedianHelper(SeqList *L1,SeqList *L2,int start1,int end1,int start2,int end2){
	if (start1==end1&&start2==end2) {
		ElemType elems[2];
		elems[0] = L1->data[start1];
		elems[1] = L2->data[start2];
		return min(elems, 2);
	}
	int mid_index1 = (start1+end1)/2;
	int mid_index2 = (start2+end2)/2;
	int mid_val1 = L1->data[mid_index1];
	int mid_val2 = L2->data[mid_index2];
	if (mid_val1==mid_val2) {
		return mid_val1;
	}
	if (mid_val1<mid_val2) {//舍弃L1的左边，以及L2的右边
		if ((start1+end1)%2==0) {//奇数个。保留中间
			start1 = mid_index1;
			end2 = mid_index2;
		}else {
		    start1 = mid_index1+1;
			end2 = mid_index2-1;
			if (end2<0) {
				end2 = 0;
			}
		}
	}else {//舍弃L1右边，L2左边
	   if ((start1+end1)%2==0) {//奇数个
			end1 = mid_index1;
			start2 = mid_index2;
	   }else {
	        end1 = mid_index1-1;
			if (end1<0) {
				end1 = 0;
			}
			start2 = mid_index2+1;
	   }
	}
	return MedianHelper(L1, L2, start1, end1, start2, end2);
}

ElemType FindMedianOfTwoSeqList(SeqList *L1,SeqList *L2){
	return MedianHelper(L1, L2, 0, L1->Length-1, 0, L2->Length-1);
}

ElemType Majority(SeqList *L){
	ElemType e = L->data[0];
	int count = 1;
	for (int i = 1; i<L->Length; i++) {
		if (L->data[i]==e) {
			count++;
		}else {
		   if (count>0) {
			count--;
		   }else {
		    e = L->data[i];
			count=1;
		   }
		}
	}
	if (count<=0) {
		return -1;
	}
	count = 0;
	for (int i = 0; i<L->Length; i++) {
		if (L->data[i]==e) {
			count++;
		}
	}
	if (count>L->Length/2) {
		return e;
	}
	return -1;
}