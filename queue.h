#pragma once
#include "common.h"
#include "tree.h"

typedef struct QueueNode
{
	Node* data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

void InitiateQueue(Queue* queue);
bool EmptyQueue(const Queue* queue);
void PushQueue(Queue* queue, Node* newdata);
Node* TopQueue(Queue* queue);
int GetQueueSize(const QNode* head);


