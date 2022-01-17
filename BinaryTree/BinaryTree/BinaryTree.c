#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

//����Ҷ�ӽ��ĸ���
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//�����k��Ľ�����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) 
		+ BinaryTreeLevelKSize(root->right, k - 1);
}

//��������������
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}


//�������в���ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}

	BTNode* leftRet = BinaryTreeFind(root->left, x);
	if (leftRet)
		return leftRet;
	BTNode* rightRet = BinaryTreeFind(root->right, x);
	if (rightRet)
		return rightRet;

	return NULL;//�����������Ҳ���������NULL
}

// ������ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

// �������������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	PreOrder(root->left);
	printf("%c ", root->data);
	PreOrder(root->right);
}

// �������������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	PreOrder(root->left);
	PreOrder(root->right);
	printf("%c ", root->data);
}

// �������
void LevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}

	QueueDestroy(&q);
	printf("\n");
}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		
		if (!front)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}

// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}