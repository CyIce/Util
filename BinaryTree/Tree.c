#include<stdio.h>
#include<stdlib.h>
#include"MyStruct.h"
#include"Traversal.h"


//创造动态链表，用于储存遍历的二叉树；
struct List *createList(int n);

//根据前序遍历和中序遍历创建二叉树；
void createTree(struct List *dlr, struct List *ldr, struct Tree *node);

//保存得到的二叉树的Head；
struct Tree *treeHead;




int main()
{
	int n;

	struct List *dlr, *ldr, *root;

	scanf_s("%d", &n);

	dlr = createList(n);
	ldr = createList(n);



	if (n == 0)
	{
		root = NULL;
	}
	else
	{
		root = (struct Tree*)malloc(sizeof(struct Tree));
		if (root != NULL)
		{
			createTree(dlr, ldr, root);
		}	
	}


	DLR(root);

	printf_s("\n");

	LDR(root);

	printf_s("\n");

	LRD(root);


	system("pause");
	return 0;
}

struct List *createList(int n)
{
	int x;

	struct List *head = NULL, *p1 = NULL, *p2 = NULL;

	for (int i = 1; i <= n; i++)
	{
		p1 = (struct List*)(malloc(sizeof(struct List)));
		if (p1 != NULL)
		{
			scanf_s("%d", &x);
			p1->val = x;
		}
		else
		{
			printf_s("error");
			return NULL;
		}

		if (i == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}

		p2 = p1;
	}

	if (p1 != NULL)
	{
		p1->next = NULL;
	}

	return head;
}

void createTree(struct List *dlr, struct List *ldr, struct Tree *node)
{	
	if (dlr == NULL || ldr == NULL)
	{
		return;
	}

	if (dlr->val == ldr->val)
	{
		node->left = NULL;
		node->right = NULL;
		node->val = dlr->val;

		return;
	}
	else
	{
		struct List *dlrHead, *ldrHead, *p;

		dlrHead = dlr;
		ldrHead = ldr;


		while (ldr->val != dlrHead->val)
		{
			ldr = ldr->next;
			dlr = dlr->next;
		}

		node->val = dlrHead->val;

		if (dlrHead->next != NULL)
		{
			p = (struct Tree*)malloc(sizeof(struct Tree));

			if (p != NULL)
			{
				node->left = p;

				createTree(dlrHead->next, ldrHead, p);
			}
			else
			{
				printf_s("error");
				return;
			}
		}
		if (dlr->next == NULL || (dlrHead->next->val == ldrHead->val&&dlr->next->val != ldr->next->val))
		{
			node->right = NULL;
			return;
		}

		if (dlr->next != NULL)
		{
			p = (struct Tree*)malloc(sizeof(struct Tree));

			if (p != NULL)
			{
				node->right = p;

				createTree(dlr->next, ldr->next, p);
			}
			else
			{
				printf_s("error");
				return;
			}
		}
	}
}