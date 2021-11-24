#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList1()
{
	ListNode* plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);

	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

}

void TestList2()
{
	ListNode* plist = ListCreate();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
}

void TestList3()
{
	ListNode* plist = ListCreate();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);

	ListNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListInsert(pos, 20);
		ListErase(pos);
	}
	ListPrint(plist);
}
int main()
{
	//TestList1();
	//TestList2();
	TestList3();

	return 0;
}