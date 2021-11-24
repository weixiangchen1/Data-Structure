#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	if (pHead == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	pHead->next = pHead;
	pHead->prev = pHead;

	return pHead;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);

	ListNode* tail = pHead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = pHead;
	pHead->prev = newnode;
	
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* tail = pHead->prev;
	ListNode* tailPrev = tail->prev;
	free(tail);

	tailPrev->next = pHead;
	pHead->prev = tailPrev;
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newnode = BuyListNode(x);
	ListNode* next = pHead->next;

	newnode->next = next;
	next->prev = newnode;
	pHead->next = newnode;
	newnode->prev = pHead;

}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* next = pHead->next;
	ListNode* nextNext = next->next;
	free(next);

	pHead->next = nextNext;
	nextNext->prev = pHead;

}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = BuyListNode(x);
	ListNode* posPrev = pos->prev;

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;

}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);

	posPrev->next = posNext;
	posNext->prev = posPrev;
}