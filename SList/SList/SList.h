#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

//单链表打印
void SListPrint(SLTNode* phead);
//单链表尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);
//单链表头插
void SListPushFront(SLTNode** pphead, SLTDataType x);
//单链表尾删
void SListPopBack(SLTNode** pphead);
//单链表头删
void SListPopFront(SLTNode** pphead);
//单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//单链表删除
void SListErase(SLTNode** pphead, SLTNode* pos);
//单链表之前插入数据
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//单链表之后插入数据
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//单链表指定pos之后删除数据
void SListEraseAfter(SLTNode* pos);
//销毁单链表
void SListDestory(SLTNode** pphead);
