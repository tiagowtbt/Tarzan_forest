//tarzan.h
#ifndef TARZAN
#define TARZAN

//adj matrix

typedef int pond;

typedef struct graph{
	int vert; //stores the number of vertex in a graph
	int arst;  //stores the number of edges in a graph
	int **matrix_Adj;
	int state;// 0-did not traverse
				// 1-already traversed
				// 2-traversed the node and its adjacents
	
}Graph;


void create_graph(Graph **g, int num_vert);
//creates graph
//enters the pointer's address of the graph and the number of vertices
//returns void



void storm(Graph *g);
//storm - destroy the graph
//enters pointer for graph
//returns void




void add_vertex(Graph *g, int v1, int v2);
//add edges
//entra ponteiro para grafo, vertex 1 and 2 from the edge
//returns void





void print_graph(Graph *g);
//imprime grafo
//entra ponteiro para grafo
//retorna void



#endif 