#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	int size;//数组的有效数据个数
	int capacity;//数组的最大容量

}SL;

//初始化顺序表
void SeqListInit(SL* ps);
//打印顺序表
void SeqListPrint(SL* ps);
//销毁顺序表
void SeqListDestory(SL* ps);
//顺序表尾插
void SeqListPushBack(SL* ps, SLDateType x);
//顺序表头插
void SeqListPushFront(SL* ps, SLDateType x);
//顺序表尾删
void SeqListPopBack(SL* ps);
//顺序表头删
void SeqListPopFront(SL* ps);
// 顺序表查找
int SeqListFind(SL* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SL* ps, int pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SL* ps, int pos);