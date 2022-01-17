#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "BinaryTree.h"

struct BinaryTreeNode;//ǰ������
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode; 

// ���еĽṹ 
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);
