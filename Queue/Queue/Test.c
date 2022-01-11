#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void Test1()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	printf("%d\n", QueueSize(&pq));
	printf("%d ", QueueFront(&pq));
	QueuePop(&pq);
	printf("%d ", QueueFront(&pq));
	QueuePop(&pq);
	printf("%d ", QueueFront(&pq));
	QueuePop(&pq);
	printf("%d ", QueueFront(&pq));
	QueuePop(&pq);
}

int main()
{
	Test1();
}