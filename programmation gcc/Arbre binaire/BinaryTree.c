#include "BinaryTree.h"

Tree *new_tree(int x)
{
	Tree *tr = malloc(sizeof(*tr));

	if(tr == NULL)
	{
		fprintf(stderr, "Erreur allocation memoire\n");
		exit(EXIT_FAILURE);
	}

	tr->value = x;
	tr->Tleft = NULL;
	tr->Parent = NULL;

	printf("Creation de %d\n", tr->value);

	return tr;
}


void clean_tree(Tree *tr)
{
	if(tr == NULL)
		return;

	printf("Suppression de %d\n", tr->value);

	clean_tree(tr->Tleft);
	clean_tree(tr->Tright);

	free(tr);
}

Tree *join_tree(Tree *left, Tree *right, int node)
{
	Tree *tr = new_tree(node);

	tr->Tleft = left;
	tr->Tright = right;

	if(left != NULL)
		left->Parent = tr;

	if(right != NULL)
		right->Parent = tr;

	return tr;
}

void print_tree_prefix(Tree *tr)
{
	if(tr == NULL)
		return;

	if(tr->Parent != NULL)
		printf("(%d) -> (%d)\n", tr->Parent->value, tr->value);
	else
		printf("(%d)\n", tr->value);

	if(tr->Tleft != NULL)
		print_tree_prefix(tr->Tleft);
	if(tr->Tright != NULL)
		print_tree_prefix(tr->Tright);
}


int count_tree_nodes(Tree *tr)
{
	if(tr == NULL)
	{
		printf("Aucun noeud\n");
		return 0;
	}

	return (count_tree_nodes(tr->Tleft) + count_tree_nodes(tr->Tright) + 1);
}