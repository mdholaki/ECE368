#include <stdio.h>
#include <stdlib.h>
#include "river.h"
#include <time.h>

int main(int argc, char ** argv)
{
  char * array;
  int size = 0;
  int N = 0;
  
  array = LoadFile(argv[1], &size, &N);
  printf("Size: %d\n", size);
  Vertex * vert_list = BuildGraph(array,size,N);
  int verts = num_vert(array,size,N);
  adj_list_build(vert_list,size,N, verts);
  Bellman_Ford(vert_list, (verts + 2),N);
  //int weight = FindWeight(vert_list,3,4);
 // printf("Weight: %d\n", weight);
  //int i = 0; 
  //for (i = 0; i < (verts + 2); i++)
  //{
    //printf("Vertex 1 Column: %d\n", vert_list[0].col);
    //printf("Vertex 1 Head: %d\n", (vert_list[0].head) -> vertex_idx);
    //for(j = 0; j < verts + 2); j++)
    //{
      
  
  
  /*printf("Array:");
  int i;
  
  for (i = 0; i < size; i++)
  {
    printf(" %c ", array[i]);
  }
  printf("\n"); */
  
  return 0;
}


char * LoadFile(char * filename, int * size, int * N)
{
  FILE * fptr = fopen(filename, "r");
  
  int check = 0;
  int i = 0;
  check = fscanf(fptr, "%d", (N));
  //printf("N: %d\n", &N);
  (*size) = (*N) * (*N);
  (*size) = (*size) - (*N);
  char * array = malloc(sizeof(int) * (*size));
  check = fscanf(fptr, "\n");
  int index = 0;
  int j;
  for (i=0; i < ((*N) - 1);i++)
  {
    for (j = 0; j <= (*N)-1; j++)
    {
      check = fscanf(fptr,"%c", &array[index]);    
      //printf("array[%d]: %c\n", index, array[index]);
      index++;
    }
    check = fscanf(fptr, "\n");
  }
  fclose(fptr);
  
  return array;
}

Vertex * BuildGraph(char * array, int size, int N)
{
  int columns = N;
  int rows = N - 1;
  int * temp = malloc(sizeof(int) * columns);
  int i = 0;
  int idx = 0;
  int j = 0;
  int k = 0;
  int num_vertex = num_vert(array, size, N);
  int verts = 1;
  Vertex * vert_list = malloc(sizeof(Vertex) * (num_vertex + 2));
  vert_list[0].col = 0;
  vert_list[0].start_row = 0;
  vert_list[0].end_row = rows - 1;
  vert_list[0].head = NULL;
  for (j = 0; j < columns; j++)
  {
    idx = 0;
    
    for (i = j; i <= (size - N + j); i = i + N)
    {
      if (array[i] == '1')
      {
	temp[idx] = 1;
      }
      else 
      {
	temp[idx] = 0;
      }
      idx++;
    }
    k = 0;
    //printf("Index: %d\n", idx);
    while (k < idx)
    {
      if (temp[k] == 1)
      {
	//printf("Column: %d\n", j);
	//printf("Start Row: %d\n", k);
	vert_list[verts].start_row = k;
	vert_list[verts].col = j+1;
	while ((temp[k] == 1) && (k < idx))
	{
	  k++;
	}
	vert_list[verts].end_row = (k - 1);
	vert_list[verts].head = NULL;
	//printf("End Row: %d\n", (k -1));
	verts++;
      }
      else
      {
	k++;
      }
    } 
    
   /*for (k = 0; k < idx; k++)
  {
    printf("temp[%d] = %d\n", k, temp[k]);
  } */
  } 
  vert_list[verts].start_row = 0;
  vert_list[verts].col = N + 1;
  vert_list[verts].end_row = (rows - 1);
  vert_list[verts].head = NULL;
  return vert_list;
} 

int num_vert(char * array, int size, int N)
{
  int i = 0;
  int verts = 0;
  int columns = N - 1;
  int rows = N;
  int * temp = malloc(sizeof(int) * columns);
  int j = 0;
  int k = 0;
  int idx = 0;
  //int m;
  for(j = 0;j < rows; j++)
  {
    idx = 0;
    i = 0;
    for (k = j; k <= (size - N + j); k = k + N)
    {
      if (array[k] == '1')
      {
	temp[idx] = 1;
      }
      else 
      {
	temp[idx] = 0;
      }
      idx++;
    }
    /*for (m = 0; m < idx; m++)
    {
      printf("temp[%d] = %d\n", m, temp[m]);
    } */
    while (i < idx)
    {
      if (temp[i] == 1)
      {
	//printf("Array Start Row: %d\n", j);
	//printf("Array State Column: %d\n", i);
	while ((temp[i] == 1) && (i < idx))
	{
	  i++;
	}
	verts++;
      }
      else
      {
	i++;
      }
    }
  } 
  
  return verts;
}

int FindWeight(Vertex * vert_list, int source, int dest)
{
  int col_source = vert_list[source].col;
  int Start_Row_source = vert_list[source].start_row;
  int End_Row_Source = vert_list[source].end_row;
  int col_dest = vert_list[dest].col;
  int Start_Row_dest = vert_list[dest].start_row;
  int End_Row_dest = vert_list[dest].end_row;
  int col_diff;
  int row_diff;
  int weight = 0;
  //printf("Col Dest: %d\n", Start_Row_source);
  if (col_dest > col_source)
  {
    col_diff = col_dest - col_source;
  }
  else
  {
    col_diff = col_source - col_dest;
  }
  //printf("col_diff %d\n", col_diff);
  //Smallest Difference in Rows of the Node
  if (Start_Row_source > Start_Row_dest)
  {
    row_diff = Start_Row_source - End_Row_dest;
  }
  else
  {
    row_diff = Start_Row_dest - End_Row_Source;
  }
  /*printf("Start Row Source: %d\n", Start_Row_source);
  printf("End Row Source: %d\n", End_Row_Source);
  printf("Start Row Dest: %d\n", Start_Row_dest);
  printf("End Row Dest: %d\n", End_Row_dest);
  printf("\n");
  printf("Row Diff %d\n", row_diff); */
  //Calculate the Weight
  int weight_row = (2 * row_diff) - 2;
  int weight_col = (2 * col_diff) - 1;
  //printf("Row Weight: %d\n\n", weight_row);
  //printf("Row Diff: %d\n", row_diff);
  
  /*if ((weight_row > weight_col) &&  (weight_col > 0))
  {
    weight = weight_col;
  }
  else if ((weight_row < weight_col) &&  (weight_row > 0))
  {
    weight = weight_row;
  }
  else if ((weight_col > weight_row) && (weight_row < 0))
  {
    weight = weight_col;
  }
  else if ((weight_row > weight_col) && (weight_col < 0))
  {
    weight = weight_row;
  } */
  if ((row_diff > col_diff))
  {
    weight = weight_row;
  }
  else if ((col_diff > row_diff))
  {
    weight = weight_col;
  }
  if ((row_diff < 0))
  {
    weight = weight_col;
  }
  if ((col_diff < 0))
  {
    weight = weight_row;
  }
  
    
  //printf("Weight: %d\n", weight);
  if ((col_source == 0))
  {
    //printf("test\n");
    weight--;
    //weight--;
  }
  //printf("Weight: %d\n", weight);
 return weight; 
}

Edge * newEdge(int index, int weight)
{
  Edge * edge = malloc(sizeof(Edge));
  edge -> vertex_idx = index;
  edge -> weight = weight;
  edge -> next = NULL;
  
  return edge;
}

Edge * InsertEdge(Edge * Head, int index, int weight)
{
  Edge * temp = newEdge(index,weight);
  
  if (Head == NULL)
  {
    Head = temp;
    return Head; 
  }
  else 
  {
    Edge * last = Head;
    while (last -> next != NULL)
    {
      last = last -> next;
    }
    last -> next = temp; 
    return Head;
  }
  
}

void adj_list_build(Vertex * vert_list, int size, int N, int verts)
{
  int i = 0;
  int weight;
  int index;
  //Edge * head = NULL;
  //Vertex * adj_list = malloc(sizeof(Vertex) * (verts));
  
  for (index = 0; index < (verts + 2); index++)
  { 
    for (i = 0;i < (verts + 2);i++)
    {
      if (i != index)
      {
	weight = FindWeight(vert_list,index,i);
	vert_list[index].head = InsertEdge(vert_list[index].head,i,weight);
     }
    }
  }
  /* Edge * Head = vert_list[0].head;
  while (Head != NULL)
  {
    printf("Head Index = %d\n", Head -> vertex_idx);
    printf("Head Weight = %d\n", Head -> weight);
    Head = Head -> next;
  } */ 
}
      
      
void Bellman_Ford(Vertex * vert_list, int verts, int N)
{
  int dist[verts];
  int i,j;
  int weight = 0;
  //Edge * Head = NULL;
  for (i = 0; i < verts; i++)
  {
    dist[i] = 1994;
  }
  
  dist[0] = 0;
  
  for (i = 1; i <= (verts - 1); i++)
  {
    for(j = 0; j < verts; j++)
    {
      int u = i -1; //Source
      int v = vert_list -> head[j].vertex_idx; //dest
      weight = vert_list -> head[j].weight; //weight
      if (dist[v] > dist[u] + weight)
      {
	dist[v] = dist[u] + weight;
        //pred[v] = vert_list[i-1];
      }
      printf("Test\n");
    }
    printf("More Test\n");
  }
  printf("hmmm\n");
  int m;
  for (m = 0; m < (verts -1);m++)
  {
   printf("Turns: %d\n", dist[m]);
  }
}
  
      
      
      
 
  
  
  
      
  
  
  