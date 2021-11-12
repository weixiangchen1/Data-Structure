#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void CheckCapacity(SL* ps)
{
	//空间不够需要增容
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDateType x)
{
	CheckCapacity(ps);

	/*ps->a[ps->size] = x;
	ps->size++;*/

	SeqListInsert(ps, ps->size, x);

}

void SeqListPushFront(SL* ps, SLDateType x)
{
	CheckCapacity(ps);
	//往后挪数据
	/*int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[0] = x;
	ps->size++;*/

	SeqListInsert(ps, 0, x);

}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListPopBack(SL* ps)
{
	/*assert(ps->size > 0);

	ps->size--;*/

	SeqListErase(ps, ps->size - 1);

}

void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);

	//往前挪数据
	/*int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;*/
	SeqListErase(ps, 0);
}

int SeqListFind(SL* ps, SLDateType x)
{
	
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDateType x)
{
	//if (pos<0 || pos>ps->size)
	//{
	//	printf("pos invalid\n");
	//	return;
	//}
	assert(pos >= 0 && pos <= ps->size);

	CheckCapacity(ps);
	
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	int begin = pos;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}

	ps->size--;
}