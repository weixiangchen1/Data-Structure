#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void test1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);

	SeqListPrint(&sl);
	SeqListDestory(&sl);

}

void test2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	//SeqListErase(&sl, 3);
	int pos = SeqListFind(&sl, 2);
	if (pos != -1)
	{
		SeqListInsert(&sl, pos, 20);

	}
	SeqListPrint(&sl);
	SeqListDestory(&sl);
	//int ret = SeqListFind(&sl, 6);
	//printf("%d\n", ret);
}

void test3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	/*SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);*/
	/*SeqListPrint(&sl);
	SeqListErase(&sl, 1);*/
	/*SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);*/
	int pos = SeqListFind(&sl, 3);
	if (pos != -1)
	{
		SeqListErase(&sl, pos);
	}

	SeqListPrint(&sl);

	SeqListDestory(&sl);
}


int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}