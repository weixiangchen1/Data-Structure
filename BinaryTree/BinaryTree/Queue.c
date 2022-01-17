#include "Queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}
// ��β����� 
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
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	
	return q->head->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q)
{
	return q->head == NULL;
}
// ���ٶ��� 
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
