#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	int size;//�������Ч���ݸ���
	int capacity;//������������

}SL;

//��ʼ��˳���
void SeqListInit(SL* ps);
//��ӡ˳���
void SeqListPrint(SL* ps);
//����˳���
void SeqListDestory(SL* ps);
//˳���β��
void SeqListPushBack(SL* ps, SLDateType x);
//˳���ͷ��
void SeqListPushFront(SL* ps, SLDateType x);
//˳���βɾ
void SeqListPopBack(SL* ps);
//˳���ͷɾ
void SeqListPopFront(SL* ps);
// ˳������
int SeqListFind(SL* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SL* ps, int pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SL* ps, int pos);