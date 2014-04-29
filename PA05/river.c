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
  printf("\n\n\n");
  vert_list = BuildGraph(array,size,N);

  
  printf("verts: %d\n", verts);
  
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
      printf("array[%d]: %c\n", index, array[index]);
      index++;
    }
    check = fscanf(fptr, "\n");
  }
  fclose(fptr);
  
  return array;
}

Vertex * BuildGraph(char * array, int size, int N)
{
  int columns = N -1;
  int rows = N;
  int * temp = malloc(sizeof(int) * columns);
  int i = 0;
  int idx = 0;
  int j = 0;
  int k = 0;
  int num_vertex = numvert(array, size, N);
  int verts = 0;
  Vertex * vert_list = malloc(sizeof(int) * (num_vertex+2));
  
  for (j = 0; j < rows; j++)
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
    while (k < idx)
    {
      if (temp[k] == 1)
      {
	vert_list[verts].start_row = k;
	vert_list[verts].col = j;
	while ((temp[k] == 1) && (k < idx))
	{
	  k++;
	}
	vert_list[verts].end_row = k;
	verts++;
      }
      else
      {
	k++;
      }
    } 
  /* for (k = 0; k < idx; k++)
  {
    printf("temp[%d] = %d\n", k, temp[k]);
  } */
  }
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

      
  
      
  
  
  