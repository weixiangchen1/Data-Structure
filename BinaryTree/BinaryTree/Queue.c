#include "Queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = data;
	newnode->next = NULL;

	if (q->head == NULL)
	{
		q->head = q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QueueNode* next = q->head->next;
	free(q->head);
	q->head = next;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	
	return q->head->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	int size = 0;
	QueueNode* cur = q->head;
	while (cur != NULL)
	{
		++size;
		cur = cur->next;
	}
	return size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q)
{
	return q->head == NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
