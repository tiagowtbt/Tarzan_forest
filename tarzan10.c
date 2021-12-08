#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tarzan.h"



void create_graph(Graph **g, int num_vert){
    int i;
	*g = (Graph*)malloc(sizeof(Graph));

	//alocate an array of pointers
	(*g)->matrix_Adj = (int**)malloc(num_vert * sizeof(int*));

	for(i = 0; i < num_vert; i++){
		
		(*g)->matrix_Adj[i] = (int*)malloc(num_vert * sizeof(int));
		for(int j = 0; j < num_vert; j++){
			(*g)->matrix_Adj[i][j] = 0;
		}
	}

	(*g)->vert = num_vert;
	(*g)->arst = 0;
}


void storm(Graph *g){

    int i;

	for (i = 1; i < g->vert; i++){
		free(g->matrix_Adj[i]);
	}

  	free(g->matrix_Adj);
  	free(g);

}


void add_edge(Graph *g, int v1, int v2){



	if((v1 != v2) && (v1 >= 0 ) && (v1 < g->vert) && (v2 >= 0) && (v2 < g->vert)&& (g->matrix_Adj[v1][v2] == 0)){
		

		g->arst++;
		g->matrix_Adj[v1][v2] = 1;
		g->matrix_Adj[v2][v1] = 1;

	}
}




void lightning(Graph *g, int v1, int v2){
	if((v1 != v2) && (v1 >=0) && (v1 < g->vert)&& (v2 >=0) && (v2 < g->vert)){

		if(g->matrix_Adj[v1][v2]!= 0){
			//decreases the number of edges
			g->arst++;
		}
		g->matrix_Adj[v1][v2] = 0;
		g->matrix_Adj[v2][v1] = 0;
	}
}


void print_graph(Graph *g){
    int i, j;
	for(i = 0; i < g->vert; i++){
		printf("Edges of vertex %d \n",i);
		for(j = 0; j < g->vert; j++){
			if(g->matrix_Adj[i][j]!= 0){
				printf("%d(%d) ",j, g->matrix_Adj[i][j]);
			}

		}
		printf("\n");
	}
	printf("\n");
}


void matrix(Graph *g){
    int i, j;
	for(i = 0; i < g->vert; i++){
		for(j = 0; j < g->vert; j++){
				printf("  %d", g->matrix_Adj[i][j]);
		}
		printf("\n");
	}
}

//busca

int search_paths(Graph *g) {

	int i, j, r;

	for(i = 0; i < g->vert; i++){
		for(r = 0, j = 0; j < g->vert; j++){
			if (g->matrix_Adj[i][j] == 0) {
			r++;

			}
			if (r == g->vert) {
				r = 0;
				return r;
			}
		}
	}
	r = 1;
	return r;
}


void generate_file(Graph *g) {
		int i, j;
		FILE *arq;
	    arq = fopen("graph.txt", "w");
	    //if (arq == NULL) {
			for(i = 0; i < g->vert; i++){
				for(j = 0; j < g->vert; j++){
	    			fprintf(arq, "%d ", g->matrix_Adj[i][j]);
	    		}
	    		
				fprintf(arq, "\n");
	    	}
	    	
		fclose(arq);
}
//generates a file with the matrix

int main(){
	srand(time(NULL));
	Graph *g;

	//Creates a graph with 10
	//vertices
	create_graph(&g,10);
	int i, j;
	//Add the edges

	for(i = 0; i < g->vert; i++){
		for(j = 0; j < g->vert; j++){
	    	add_edge(g,i,j);
	    }
	    		
	}
	

	//shows the graph
	print_graph(g);
	matrix(g);

	//storm

	//uncomment to simulate the storm
	
	/*

	for(i = 0; i < g->vert; i++){
		for(j = 0; j < g->vert; j++){
			
			int random = rand() % 10;
			if (random % 2 == 0){
				lightning(g,i,j);
			}
	    	
	    }
	    		
	}
	print_graph(g);
	matrix(g);
	*/

	printf("\n");

	int r = search_paths(g);
	if(r == 1)
		printf("Its possible to traverse the forest\n");
	else{
		printf("Its impossible to traverse the forest\n");
	}

	generate_file(g);
	//free the memory
	storm(g);

	return 0;
}
