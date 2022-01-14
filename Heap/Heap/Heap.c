#include "Heap.h"

void Swap(HPDataType* px, HPDataType* py)
{
	HPDataType tmp = *px;
	*px = *py;
	*py = tmp;
}

void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->size = hp->capacity = 0;
}


void AdjustUp(int*a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			HPDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(int* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)// 左孩子存在则继续循环
	{
		if (child + 1 < n &&  a[child + 1] > a[child])
		{
			++child;
		}// 比较左孩子和右孩子

		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	return hp->a[0];
}

bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}

int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = realloc(hp->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newCapacity;
	}

	hp->a[hp->size] = x;
	hp->size++;

	AdjustUp(hp->a, hp->size - 1);
}

void HeapPop(Heap* hp)// 最后一个元素和第一个元素交换，第一个元素向下调整
{
	assert(hp);
	assert(!HeapEmpty(hp));

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}