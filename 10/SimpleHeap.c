#include "SimpleHeap.h"

void HeapInit(Heap* ph) // 힙 초기화
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) // 힙이 비어있는지 확인
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)  // 부모 노드 인덱스 값 반환
{
    return idx / 2;
}

int GetLChildIDX(int idx)  // 왼쪽 자식 노드 인덱스 값 반환
{
    return idx * 2;
}

int GetRChildIDX(int idx)  // 오른쪽 자식 노드 인덱스 값 반환
{
    return GetLChildIDX(idx) + 1;
}

/* 두개의 자식 노드 중, 높은 우선순위의 자식 노드 인덱스 값 반환 */
int GetHiPriChildIDX(Heap* ph, int idx)
{
    if (GetLChildIDX(idx) > ph->numOfData) {
        return 0;
    }
    else if (GetLChildIDX(idx) == ph->numOfData) {
        return GetLChildIDX(idx);
    }
    else {
        if (ph->heapArr[GetLChildIDX(idx)].pr
                > ph->heapArr[GetRChildIDX(idx)].pr) {
            return GetRChildIDX(idx);
        }
        else {
            return GetLChildIDX(idx);
        }
    }
}

// 만약 현재 인덱스의 왼쪽 오른쪽 자식의 인덱스가 없다면 자기자신
// 한개있다면 그 놈 리턴
// 둘다 있다면 저거

/* 힙에 데이터 저장
                   1
                 /     \
               4         7
              /   \     /   \
             8     9   12    13
            /   \
           15   '3'

        1. 새로운 데이터는 '우선순위' 가장 낮다고 가정하고 '마지막 위치'에 저장.
        2. 부모 노드와 우선순위 비교하면서 자기자리 찾아감.

        - 3을 맨 마지막 위치에 넣고, 부모(8)와 비교 -> 부모와 자리 바꿈.
        - 또 새로운 부모(4)와 비교 -> 부모와 자리 바꿈.
        - 또 새로운 부모(1)와 비교 -> 자리 안바꿈. 여기가 내자리.
*/
void HInsert(Heap* ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1;
    HeapElem nelem = { pr, data };

    while (idx != 1) {
        if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else {
            break;
        }
    }

    ph->heapArr[idx] = nelem;
    ph->numOfData += 1;

} // 일단 인덱스 ++하고 데이터랑 우선수위 넣기
  // 그리고 엄마랑 비교하기

/* 힙의 데이터 삭제
      - 마지막 노드를 루트 노드의 자리로 옮긴 다음, 자식 노드와 비교해서 제자리 찾아가게 하자!
                  '8'
                 /     \
               3         7
              /   \     /   \
             4     9   12    13
            /   \
           15

       - 8은 두개의 자식노드(3,7)중 우선순위 높은 3과 자신의 위치를 바꾼다.
         (물론 오른쪽 자식이 우선순위 더 높다면 오른쪽 자식과 바꿔야지)
       - 그 다음 또 두 자식(4,9)중 우선순위 더 높은 4와 자신의 위치를 바꾼다.
       - 다시 또 자식(15,공집합)이랑 비교하는데, 내가 더 높다. 내 자리는 여기다.
*/
HData HDelete(Heap* ph)
{
    char retData = (ph->heapArr[1]).data;
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
        if (lastElem.pr <= ph->heapArr[childIdx].pr)
            break;

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;

}
//일단 첫번째꺼 잠깐 저장해둿다가 나중에 리턴
// 맨뒤에 있던 데이터가 1번째 인덱스가 되어 GetHiPriChildIDX(Heap * ph, int idx)이거 해서 자신과 비교
// 우선순위 자기가 낮을때까지
