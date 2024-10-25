#include "Graph.h"

Graph new_graph(int vertices, bool is_oriented)
{
	int i;
	GraphElement *element;		//creation d'un pointeur de structure temporaire pour la création du graph

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Probeleme allocation de mémoire\n");
		exit(EXIT_FAILURE);
	}

	element->is_oriented = is_oriented;
	element->nb_vertices = vertices;

	element->tab_neighbours = malloc(vertices * sizeof(AdjencyListElement));			//Allocation memeoire pour le pointeur de struct en fonction du nombres de noeud du graph	

	if(element->tab_neighbours == NULL)
	{
		fprintf(stderr, "Erreur allocation memoire\n");
		exit(EXIT_FAILURE);
	}
	for(i = 1; i < (element->nb_vertices + 1) ;i++)						//Mise à nul des pointeurs, mise à 1 de l'itérateur pour de l'affichage
		element->tab_neighbours[i - 1].begin = NULL;

	if(element->is_oriented)
		element->graph_file = fopen("digraph.out","w");
	else
		element->graph_file = fopen("graph.out","w");

	if(element->graph_file == NULL)
	{
		fprintf(stderr, "Erreur de creation du fichier\n");
		exit(EXIT_FAILURE);
	}

	if(element->is_oriented)
		fprintf(element->graph_file,"digraph My_graph\n{\n");
	else
		fprintf(element->graph_file,"graph My_graph\n{\n");

	return element;
}



bool is_empty_graph(Graph g)
{
	if(g == NULL)
		return true;

	return false;
}


NodeList add_node(int x)
{
	NodeList n = malloc(sizeof(NodeListElement));

	if(n == NULL)
	{
		fprintf(stderr, "Erreur allocation memoire\n");
		exit(EXIT_FAILURE);
	}

	n->value = x;
	n->next = NULL;

	return n;
}


void erase_graph(Graph g)
{
	if(is_empty_graph(g))
	{
		printf("Rien a effacer, le graph n'existe pas\n");
		return;
	}

	//si sommets adjacents
	if(g->tab_neighbours)
	{
		int i;

		for(i = 1; i < g->nb_vertices +1;i++)
		{
			NodeList n = g->tab_neighbours[i-1].begin;

			while(n != NULL)
			{
				NodeList tmp = n;
				n = n->next;
				free(tmp);
			}
		}
		// Libération de la liste d'adjacence
		free(g->tab_neighbours);
	}
	//Fin et fermeture du fichier
	fprintf(g->graph_file,"}\n");
	fclose(g->graph_file);

	//Libération du graph 
	free(g);

	if(is_empty_graph(g))
		printf("Graph effacer avec succes\n");
	else
		printf("Erreur lors de l'effacement du graph\n");
}


void add_edge(Graph g, int src, int dst)
{
	NodeList n = add_node(dst);
	n->next = g->tab_neighbours[src-1].begin;
	g->tab_neighbours[src-1].begin = n;
	g->tab_neighbours[src-1].begin = n;

	//Si le graphe est orienté alors il faut éxécuter des fonction supplémentaire
	if(!g->is_oriented)
	{
		n = add_node(src);
		n->next = g->tab_neighbours[dst-1].begin;
		g->tab_neighbours[dst-1].begin = n;
		g->tab_neighbours[dst-1].begin = n;
	}

	//Ajour d'un lien dans le fichier graphviz
	if(g->is_oriented)
		fprintf(g->graph_file, "\t%d -> %d;\n", src, dst);
	else
		fprintf(g->graph_file, "\t%d -- %d;\n", src, dst);
}



void print_graph(Graph g)
{
	int i;
 
	for(i = 1; i < g->nb_vertices + 1; i++)
	{
		NodeList n = g->tab_neighbours[i-1].begin;
		printf("(%d) : ", i);

		while(n != NULL)
		{
			printf("%d,", n->value);
			n = n->next;
		}

		printf("NULL\n");
	}
}


void display_graph(Graph g)
{	//Commande systeme windows
	if(g->is_oriented)
	{
		//system("D:/Graphviz/bin/dotty.exe");
		//system("%CD%/digraph.out");	//%CD% = Mon directory actuelle	
	}
	else
		//system("D:/Graphviz/bin/dotty.exe");
		//system("%CD%/graph.out");	//%CD% = Mon directory actuelle		
}	