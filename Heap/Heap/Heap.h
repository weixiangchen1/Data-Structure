#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	int* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
void HeapPrint(Heap* hp);
bool HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
HPDataType HeapTop(Heap* hp);
void AdjustDown(int* a, int n, int parent);
void AdjustUp(int* a, int child);
void Swap(HPDataType* px, HPDataType* py);
