#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void PrintTopK(int* a, int n, int k)
{
	assert(a);
	Heap hp;
	HeapInit(&hp);
	// 1. 建堆--用a中前k个元素建堆
	for (int i = 0; i < k; ++i)
	{
		HeapPush(&hp, a[i]);
	}
	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	for (int i = k; i < n; i++)
	{
		if (a[i] > hp.a[0])
		{
			hp.a[0] = a[i];
			AdjustDown(hp.a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", hp.a[i]);
	}
}

void HeapSort(int* a, int n)
{
	assert(a);
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
	//while (n > 0)
	//{
	//	Swap(&a[0], &a[n - 1]);
	//	AdjustDown(a, n - 1, 0);
	//	n--;
	//}
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

int main()
{
	int a[] = { 70,56,30,25,15,10,75 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	/*Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	TestTopk();*/
	return 0;
}