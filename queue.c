#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

void InitiateQueue(Queue *queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

bool EmptyQueue(const Queue *queue)
{
	if (queue->front == NULL)return true;
	return false;
}

void PushQueue(Queue* queue, Node* newdata)
{
	if (!newdata)return;
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode)return;
	newnode->data = newdata;
	newnode->next = NULL;

	if (queue->rear != NULL)queue->rear->next = newnode;
	queue->rear = newnode;
	if (queue->front == NULL)queue->front = newnode;
}

Node* TopQueue(Queue* queue)
{
	if (queue->front == NULL)return NULL;
	QNode* del = queue->front;
	Node* result = del->data;
	queue->front = del->next;
	if (queue->front == NULL)queue->rear = NULL;
	free(del);
	return result;
}

int GetQueueSize(const QNode* head)
{
	if (head == NULL)return 0;
	return GetQueueSize(head->next) + 1;
}