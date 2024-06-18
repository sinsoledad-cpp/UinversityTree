#pragma once
#include "common.h"
#include "tree.h"

typedef struct Stack
{
	Node* data;
	struct Stack* next;
}Stack;

Stack* InititateStack();
bool EmptyStack(Stack* head);
void PushStack(Stack* head, Node* newdata);
Node* TopStack(Stack* head);
int GetStackSize(Stack* head);

void PrintTreeNodeByStack(Node* root);