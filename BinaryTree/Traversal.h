#pragma once
#include<stdio.h>
#include"MyStruct.h"

//ǰ�������
void DLR(struct Tree *node);

//���������
void LDR(struct Tree *node);

//���������
void LRD(struct Tree *node);

void DLR(struct Tree *node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		printf_s("%d ", node->val);

		if (node->left != NULL)
		{
			DLR(node->left);
		}

		if (node->right != NULL)
		{
			DLR(node->right);
		}
	}
}

void LDR(struct Tree *node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		if (node->left != NULL)
		{
			LDR(node->left);
		}

		printf_s("%d ", node->val);

		if (node->right != NULL)
		{
			LDR(node->right);
		}
	}
}

void LRD(struct Tree *node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		if (node->left != NULL)
		{
			LRD(node->left);
		}

		if (node->right != NULL)
		{
			LRD(node->right);
		}

		printf_s("%d ", node->val);
	}
}
