#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"


/*
head -> [DMY, *]
*/
void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;

}

void FInsert(List * plist, LData data)  // 머리에 새 노드 추가
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head ->next= newNode;

	(plist->numOfData)++;
}

void SInsert(List * plist, LData data) 
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	Node* pred = plist->head;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

/*
사용자는, 외부에서 LInsert()만을 호출한다. 
내부적으로, comp 초기화에 따라서, 
(1)FInsert() 아니면, (2)SInsert() 호출되는데, 이건 내부적으로 해주는 것. 
단지, 우리는 comp 초기화를 어떻게 할래?만 정하면 되는 것. 
*/
void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;
	
	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;

	return TRUE;

}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL)
	{
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
	
}
/*
바로 이전에 호출된 LFirst or LNext 함수가 반환한 데이터를 삭제한다.
 -> 다른말로 cur 위치에 있는 녀석을 삭제한다. 

*/
LData LRemove(List * plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;

	return rdata;
}

int LCount(List * plist)
{
   return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
   plist->comp = comp;
}
