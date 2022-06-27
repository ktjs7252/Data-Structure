#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq) // 맨 처음은 텅 빈 경우니까, f,r은 동일한 위치(0) 가리킴.
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
    if (pq->front == pq->rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
int NextPosIdx(int pos) // 큐의 다음 위치에 해당하는 인덱스 값 반환
{
    if (pos == QUE_LEN - 1)
    {
        return 0;
   }
    else
    {
        return pos + 1;
    }
}

void Enqueue(Queue* pq, Data data)
{
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}
Data Dequeue(Queue * pq)
{
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
    return pq->queArr[pq->front];
}
