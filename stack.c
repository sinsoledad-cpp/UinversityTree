#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
Stack* InititateStack()
{
	Stack* head = (Stack*)malloc(sizeof(Stack));
	if (!head)return NULL;
	head->data = NULL;
	head->next = NULL;
	return head;
}

bool EmptyStack(Stack* head)
{
	if (head == NULL || head->next == NULL)return true;
	return false;
}

void PushStack(Stack* head, Node* newdata)
{
	if (newdata == NULL)return;
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	if (!newnode)return NULL;
	newnode->data = newdata;
	newnode->next = head->next;
	head->next = newnode;
}

Node* TopStack(Stack* head)
{
	if (head->next == NULL)
	{
		printf("Õ»ÒÑ¾­Îª¿Õ\n");
		return false;
	}
	Node* result = head->next->data;
	Stack* del = head->next;
	head->next = del->next;
	free(del);
	return result;
}

int GetStackSize(Stack* head)
{
	if (head == NULL)return -1;
	return GetStackSize(head->next) + 1;
}

