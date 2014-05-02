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
  int col_diff = -1;
  int row_diff = -1;
  int weight = 0;
//   printf("Col_source: %d\n", col_source);
//   printf("Col_Dest: %d\n", col_dest);
//   printf("Start Row Source: %d\n", Start_Row_source);
//   printf("End Row Source: %d\n", End_Row_Source);
//   printf("Start Row Dest: %d\n", Start_Row_dest);
//   printf("End Row Dest: %d\n", End_Row_dest);
  //Initialize Column and Row Differences
   if (col_dest > col_source)
   {
    col_diff = col_dest - col_source;
   }
   else
   {
     col_diff = col_source - col_dest;
   }
   
   if (End_Row_Source <= Start_Row_dest)
    {
      row_diff = Start_Row_dest - End_Row_Source;
    }
    else if (End_Row_dest <= Start_Row_source)
    {
      row_diff = Start_Row_source - End_Row_dest;
    }
    
   
  //Find which Weight you need to use 
  if (col_dest == col_source)
  { 
    weight = 2 * row_diff;
  }
  else if ((Start_Row_source == Start_Row_dest) && (End_Row_dest == End_Row_Source))
  {
    weight = (2 * col_diff) -1;
  }
  
  else if (col_dest != col_source)
  {
    if ((Start_Row_source <= Start_Row_dest) && (End_Row_dest <= End_Row_Source) )
    {
      weight = (col_diff * 2) - 1;
    }
    else if ((Start_Row_source >= Start_Row_dest) && (End_Row_dest >= End_Row_Source))
    {
      weight = (col_diff * 2) - 1;
    }
    else if (row_diff == 0)
    {
      weight = (col_diff * 2) - 1;
    }
    else if (col_diff > row_diff)
    {
      weight = (col_diff * 2) - 1;
    }
    else if (row_diff >= col_diff)
    {
      weight = (row_diff * 2);
    }
  }
  
  if (col_source == 0 || col_dest == 0)
  {
    if (col_dest > 2)
    {
      weight = weight - 2;
    }
    else
    {
      weight--;
    }
  }

  return weight;
}     

Edge * newEdge(int index, int source, int weight)
{
  Edge * edge = malloc(sizeof(Edge));
  edge -> vertex_idx = index;
  edge -> weight = weight;
  edge -> source = source;
  edge -> next = NULL;
  
  return edge;
}

Edge * InsertEdge(Edge * Head, int index, int source, int weight)
{
  Edge * temp = newEdge(index, source, weight);
  
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
	vert_list[index].head = InsertEdge(vert_list[index].head,i, index, weight);
     }
    }
  }
  Edge * Head = vert_list[1].head;
  while (Head != NULL)
  {
    printf("Head Source = %d\n", Head -> source);
    printf("Head Dest = %d\n", Head -> vertex_idx);
    printf("Head Weight = %d\n", Head -> weight);
    Head = Head -> next;
  } 
}

/*int Turns_Helper(Vertex * vert_list, int N, int verts)
{
  int i;
  Edge * edge = 0;
  int Best = (2 * N + 1);
  int current = 0;
  for (i = 0; i < verts; i++)
  {
    edge = vert_list[i].head;
    current = edge -> weight; 
    TurnsBest(vert_list, edge, Best, Current);
  }
}

void TurnsBest(Vertex * vert_list, Edge * edge, int * Best, int current)
{
  */
  
  
/*Edge * adj_list_build(Vertex * vert_list, int size, int N, int verts)
{
  int i = 0;
  int weight;
  int index;
  verts = verts + 2;
  Edge * edge = malloc(sizeof(Edge) * (verts - 1));
  //int num_edges = (verts - 1) * (verts);
  
  //Vertex * adj_list = malloc(sizeof(Vertex) * (verts));
  int edge_idx = 0;
  
  for (index = 0; index < verts;index++)
  {
    for (i = 0; i < verts; i++)
    {
      if (i != index)
      {
	edge[edge_idx].source = index;
	edge[edge_idx].vertex_idx = i;
	weight = FindWeight(vert_list,index,i);
	edge[edge_idx].weight = weight;
	edge_idx++;
      }
    }
    //printf("for\n");
  }
  for (i = 0; i < edge_idx; i++)
  {
    printf("Source = %d\n", edge[i].source);
    printf("Edge Index = %d\n", edge[i].vertex_idx);
    printf("Weight = %d\n", edge[i].weight);
    printf("\n\n");
  } 
  return edge;
} */

/*void Bellman_Ford(Edge * edge, int verts, int N)
{
  int dist[verts];
  int i,j,k;
  
  for (k = 0; k < verts; k++)
  {
    dist[k] = 1994;
  }
  
  dist[0] = 0;
  int num_edges = verts * (verts -1);
   for (i = 1; i <= verts - 1; i++)
   {
      for (j = 0; j < num_edges ; j++)
      {
        int u = edge[j].source;
        int v = edge[j].vertex_idx;
        int weight = edge[j].weight;
        if (dist[u] + weight < dist[v])
	{
           dist[v] = dist[u] + weight;
	}
      }
    }
  int m = 0;
  for (m = 0; m < verts; m++)
  {
    printf("Turns: %d\n", dist[m]);
  } 
} */
    
    
  
      
void Bellman_Ford(Vertex * vert_list, int verts, int N)
{
  int dist[verts];
  int i,k;
  int weight = 0;
  Edge * tmp = NULL;
  for (i = 0; i < verts; i++)
  {
    dist[i] = 1994;
  }
  
  dist[0] = 0;
  
  for (k = 0; k <= (verts - 1); k++)
  {
    tmp = vert_list[k].head;
    for (i = 1; i <= (verts -1); i++)
    {
      while (tmp != NULL)
      {
	//tmp = vert_list[j].head;
	int u = tmp -> source;
	//int u = vert_list -> head[1].source; //source
	//int v = vert_list -> head[1].vertex_idx; //dest
	int v = tmp -> vertex_idx;
	weight = tmp -> weight;
	//weight = vert_list -> head[1].weight; //weight
	if (dist[v] > dist[u] + weight)
	{
	  dist[v] = dist[u] + weight;
	}
	//printf("Bellman:\n");
	//printf("Source: %d\n", u);
	//printf("Dest: %d\n", v);
	//printf("Weight: %d\n", weight);
	//printf("\n");
	tmp = tmp -> next; 
      }
    }
  printf("\n");
  int m = 0;
  for (m = 0; m < verts; m++)
  {
    printf("Turns: %d\n", dist[m]);
  } 
  printf("\n");  
  } 
} 


      
      
      
 
  
  
  
      
  
  
  