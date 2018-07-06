#pragma once

struct Tree
{
	int val;
	struct Tree *left;
	struct Tree *right;
};

struct List
{
	int val;
	struct List *next;
};
