#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include"Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
int BinaryTreeDepth(BTNode* root);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
void LevelOrder(BTNode* root);
void BinaryTreeDestory(BTNode** root);
int BinaryTreeComplete(BTNode* root);



