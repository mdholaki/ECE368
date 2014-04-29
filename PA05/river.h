#ifndef river
#define river

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _vertex{
  int col;
  int start_row;
  int end_row;
}Vertex;

/*typedef struct _edge{
  int vertex_idx;
  int weight;
  edge * next;
}Edge; */


//Function Declarations
char * LoadFile(char * filename, int * size, int * N);
Vertex * BuildGraph(char * array, int size, int N);
int num_vert(char * array, int size, int N);
#endif
