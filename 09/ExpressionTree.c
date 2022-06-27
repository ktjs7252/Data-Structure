#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

/*
   - 매개변수 exp : 후위표기법 수식
   - 반환값 : 수식 트리의 Root node 주소값.

   1. 피연산자 만나면 스택으로 옮긴다.
   2. 연산자 만나면 스택에서 두개의 피연산자 꺼내서 자식 노드로 연결.
   3. 자식 노드 연결해서 만들어진 트리는 다시 스택으로 옮김.

*/
BTreeNode* MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode* pnode;

    int expLen = strlen(exp);
    int i;

    StackInit(&stack);

    for (i = 0; i < expLen; i++)
    {
        pnode = MakeBTreeNode();

        if (isdigit(exp[i]))      // 피연산자라면
        {
            SetData(pnode, exp[i] - '0');
        }
        else               // 연산자라면
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));

            SetData(pnode, exp[i]);
        }

        SPush(&stack, pnode);
    }

    return SPop(&stack);
}


int EvaluateExpTree(BTreeNode* bt)
{
    int op1, op2;

     //1. 재귀 탈출 조건 
         if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
         {
             return GetData(bt);
         }
     //2. 재귀 함수 호출
    op1 = EvaluateExpTree(bt->left);
    op2 = EvaluateExpTree(bt->right);

    switch (GetData(bt))
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }

    return 0;
}

void ShowNodeData(int data)
{
    if (0 <= data && data <= 9)
        printf("%d ", data);
    else
        printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
    InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
    PostorderTraverse(bt, ShowNodeData);
}
