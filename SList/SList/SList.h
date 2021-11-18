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

//�������ӡ
void SListPrint(SLTNode* phead);
//������β��
void SListPushBack(SLTNode** pphead, SLTDataType x);
//������ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);
//������βɾ
void SListPopBack(SLTNode** pphead);
//������ͷɾ
void SListPopFront(SLTNode** pphead);
//���������
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//������ɾ��
void SListErase(SLTNode** pphead, SLTNode* pos);
//������֮ǰ��������
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//������֮���������
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//������ָ��pos֮��ɾ������
void SListEraseAfter(SLTNode* pos);
//���ٵ�����
void SListDestory(SLTNode** pphead);
