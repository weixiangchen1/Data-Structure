#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void Test1()
{
	SLTNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushFront(&s, 6);
	SListPushFront(&s, 7);
	SListPushFront(&s, 8);
	SListPushFront(&s, 9);
	SListPrint(s);
}

void Test2()
{
	SLTNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPrint(s);

	SListPopFront(&s);
	SListPrint(s);

	SListPopFront(&s);
	SListPrint(s);

	SListPopFront(&s);
	SListPrint(s);
}

void Test3()
{
	SLTNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);

	SLTNode* pos = SListFind(s, 2);
	if (pos)
	{
		SListInsert(&s, pos, 20);
		SListInsertAfter(pos, 20);
	}

	SListPrint(s);
}

void Test4()
{
	SLTNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPrint(s);

	SLTNode* pos = SListFind(s, 2);
	SListInsertAfter(pos, 20);
	SListPrint(s);

}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();


	return 0;
}