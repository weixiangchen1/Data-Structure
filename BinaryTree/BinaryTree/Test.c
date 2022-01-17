#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
#include "Queue.h"
BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');
	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;
	return nodeA;
}
int main()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeDepth:%d\n", BinaryTreeDepth(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root, 3));

	BTNode* ret = BinaryTreeFind(root, 'B');
	printf("ret = %c\n", ret->data);
	LevelOrder(root);
	return 0;
}