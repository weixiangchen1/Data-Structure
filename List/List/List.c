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
// �������������ͷ���.
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
// ˫����������
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
// ˫�������ӡ
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
// ˫������β��
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
// ˫������βɾ
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
// ˫������ͷ��
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
// ˫������ͷɾ
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
// ˫���������
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
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);

	posPrev->next = posNext;
	posNext->prev = posPrev;
}