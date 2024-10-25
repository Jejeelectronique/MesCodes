#ifndef __BINARYTREE__H__
#define __BINARYTREE__H__
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	false,
	true
}bool;

typedef struct Tree
{
	int value;
	struct Tree *Tleft;
	struct Tree *Tright;
	struct Tree *Parent;
	
}Tree;

Tree *new_tree(int x);
void clean_tree(Tree *tr);
Tree *join_tree(Tree *Tleft, Tree *Tright, int node);
void print_tree_prefix(Tree *tr);
int count_tree_nodes(Tree *tr);

#endif