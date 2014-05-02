#ifndef river
#define river

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _vertex{
  int col;
  int start_row;
  int end_row;
  struct _edge * head;
}Vertex;

typedef struct _edge{
  int vertex_idx;
  int weight;
  int source;
  struct _edge * next;
}Edge; 


//Function Declarations
char * LoadFile(char * filename, int * size, int * N);
Vertex * BuildGraph(char * array, int size, int N);
int FindWeight(Vertex * vert_list, int source, int dest);
int num_vert(char * array, int size, int N);
void adj_list_build(Vertex * vert_list, int size, int N, int verts);
// void Bellman_Ford(Edge * edge, int verts, int N);
void Bellman_Ford(Vertex * vert_list, int verts, int N);
Edge * newEdge(int index, int source, int weight);


#endif
