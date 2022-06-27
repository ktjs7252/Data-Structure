#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
    if (pstack->topIndex == -1)
    {
        return TRUE;
  }
    else
    {
        return FALSE;
    }
}

void SPush(Stack* pstack, Data data)
{
    pstack->topIndex += 1;
    pstack -> stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
    int rIdx;

    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;

    return pstack->stackArr[rIdx];
}

Data SPeek(Stack* pstack)
{
    return pstack->stackArr[pstack->topIndex];
}
