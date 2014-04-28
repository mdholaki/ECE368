#include <stdio.h>
#include <stdlib.h>
#include "river.h"
#include <time.h>

int main(int argc, char ** argv)
{
  char * array;
  int size = 0;
  
  array = LoadFile(argv[1], &size);
  printf("Size: %d\n", size);
  printf("Array:");
  int i;
  
  for (i = 0; i < size; i++)
  {
    printf(" %c ", array[i]);
  }
  printf("\n"); 
  
  return 0;
}


char * LoadFile(char * filename, int * size)
{
  FILE * fptr = fopen(filename, "r");
  
  int check = 0;
  int N;
  int i = 0;
  check = fscanf(fptr, "%d", &N);
  printf("N: %d\n", N);
  (*size) = N * N;
  (*size) = (*size) - N;
  char * array = malloc(sizeof(int) * (*size));
  check = fscanf(fptr, "\n");
  int index = 0;
  int j;
  for (i=0; i < (N - 1);i++)
  {
    for (j = 0; j <= N-1; j++)
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


  