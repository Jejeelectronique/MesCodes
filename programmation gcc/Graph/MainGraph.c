#include "Graph.h"
/*
Graph new_graph(int vertices, bool is_oriented);
bool is_empty_graph(Graph g);
NodeList add_node(int x);
void add_edge(Graph g, int src, int dst);
void erase_graph(Graph g);
void print_graph(Graph g);
*/

int main(void)
{
	Graph g1 = new_graph(5, false);

	add_edge(g1,1,2);
	add_edge(g1,1,5);
	add_edge(g1,4,5);
	add_edge(g1,3,5);

	print_graph(g1);

	printf("-----------------------------------------------------------------------\n");

	erase_graph(g1);

	print_graph(g1);


	return 0;
}