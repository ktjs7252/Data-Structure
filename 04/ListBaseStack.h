#ifndef __lb_stack_h__
#define __lb_stack_h__

#define TRUE   1
#define FALSE   0

typedef int Data;

typedef struct _node // 연결 리스트의 노드 표현
{
	Data data;
	struct _node* next;
} Node;

typedef struct _liststack // 연결 리스트 기반 스택을 표현한 구조체
{
	Node* head;
} liststack;


typedef liststack Stack;

void stackinit(Stack* pstack);
int sisempty(Stack* pstack);

void spush(Stack* pstack, Data data);
Data spop(Stack* pstack);
Data speek(Stack* pstack);
