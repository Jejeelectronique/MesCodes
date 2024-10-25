#ifndef __GRAPH__H__
#define __GRAPH__H__

#include <stdlib.h>
#include <stdio.h>

/*Définition d'un booléen*/
typedef enum
{
	false,
	true
}bool;



/*Définition d'un noeud*/
typedef struct NodeListElement
{
	int value;
	struct NodeListElement *next;
}NodeListElement, *NodeList;



/*Définition d'une liste adjacente*/
typedef struct AdjencyListElement
{
	NodeListElement *begin;
}AdjencyListElement, *AdjencyList;

/*Définition d'un graphe*/
typedef struct GraphElement
{
	bool is_oriented;		//Si le graph est orienté, l'on peut se déplacer de tous les sommets vers tous les sommets. Si il est orienté, l'on pourra se déplacer uniquement de certains sommet vers d'autres
	int nb_vertices;		//Nb de sommets
	AdjencyList tab_neighbours;
	FILE *graph_file;
}GraphElement, *Graph;


Graph new_graph(int vertices, bool is_oriented);
bool is_empty_graph(Graph g);
NodeList add_node(int x);
void add_edge(Graph g, int src, int dst);
void erase_graph(Graph g);
void print_graph(Graph g);
void display_graph(Graph g);

#endif