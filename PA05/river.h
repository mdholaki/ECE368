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
  struct _edge * next;
}Edge; 


//Function Declarations
char * LoadFile(char * filename, int * size, int * N);
Vertex * BuildGraph(char * array, int size, int N);
int FindWeight(Vertex * vert_list, int source, int dest);
int num_vert(char * array, int size, int N);
void adj_list_build(Vertex * vert_list, int size, int N, int verts);
Edge * newEdge(int index, int weight);


#endif
