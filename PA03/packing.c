#include <stdio.h>
#include <stdlib.h>
#include "packing.h"

int main(int argc, char ** argv)
{
  Tree * root = NULL;
  Tree * Binary_tree = NULL;
  int num_nodes = 0;
  int blocks = 0;
  
  root = Load_File(argv[1], &num_nodes, &blocks);
  Binary_Tree = TreeBuild(Tree * Load_Tree, int num_nodes);
  
  return EXIT_SUCCESS;
}

Tree * Load_File(char * Filename, int * num_nodes, int * blocks)
{
  FILE * fptr = fopen(Filename, "r");
  
  
  int scan_check = 0;
  
  scan_check = fscanf(fptr, "%d", blocks);
  
  scan_check = fscanf(fptr, "%d", num_nodes);
  
  Tree * load_tree = malloc(sizeof(Tree) * (*num_nodes));
  printf("num_nodes: %d\n", *num_nodes);
  printf("Blocks: %d\n", *blocks);
  
  int i;
  int j;
  for(i = 0; i < (*num_nodes); i++)
  {
    for (j = 0; j < 7; j++)
    {
      if (j == 0)
      {
	scan_check = fscanf(fptr, "%d", &load_tree[i].thisnode);
	//printf("This node: %d\n", load_tree[i].thisnode);
      }
      else if (j == 1)
      {
	scan_check = fscanf(fptr, "%d", &load_tree[i].parnode);
	//printf("Parent Node: %d\n", load_tree[i].parnode);
      }
      
      else if (j == 2)
      {
	scan_check = fscanf(fptr, "%d", &load_tree[i].lcnode);
	//printf("Left Node: %d\n", load_tree[i].lcnode);
      }
      
      else if (j == 3)
      {
	scan_check = fscanf(fptr, "%d", &load_tree[i].rcnode);
	//printf("Right Node: %d\n", load_tree[i].rcnode);
      }
      
      else if (j == 4)
      {
	scan_check = fscanf(fptr, " %c", &load_tree[i].cutline);
	//printf("Cut Line: %c\n", load_tree[i].cutline);
      }
      
      else if (j == 5)
      {
	scan_check = fscanf(fptr, "%lf", &load_tree[i].width);
	//printf("Width: %lf\n", load_tree[i].width);
      }
      
      else
      {
	scan_check = fscanf(fptr, "%lf", &load_tree[i].length);
	//printf("Length: %lf\n\n", load_tree[i].length);
      }
      //load_tree[i].parent = NULL;
      //load_tree[i].left = NULL;
      //load_tree[i].right = NULL;
    }
  }
  fclose(fptr);
  
  return load_tree;
}

