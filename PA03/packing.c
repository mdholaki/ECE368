#include <stdio.h>
#include <stdlib.h>
#include "packing.h"

int main(int argc, char ** argv)
{
  Tree * root = NULL;
  Tree * Binary_tree = NULL;
  Tree * Load_Tree = NULL;
  int num_nodes = 0;
  int blocks = 0;
  //int height = 0;
  //int width = 0;
  
  Load_Tree = Load_File(argv[1], &num_nodes, &blocks);
  root = SetRoot(Load_Tree, num_nodes);
  Binary_tree = TreeBuild(Load_Tree, root, num_nodes);
  PostOrder(Binary_tree);
  //PostOrderPack(Binary_tree, num_nodes);
  
  
  return EXIT_SUCCESS;
}

Tree * Load_File(char * Filename, int * num_nodes, int * blocks)
{
  FILE * fptr = fopen(Filename, "r");
  
  
  int scan_check = 0;
  
  scan_check = fscanf(fptr, "%d", blocks);
  
  scan_check = fscanf(fptr, "%d", num_nodes);
  
  Tree * load_tree = malloc(sizeof(Tree) * (*num_nodes));
  //printf("num_nodes: %d\n", *num_nodes);
  //printf("Blocks: %d\n", *blocks);
  
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
      load_tree[i].parent = NULL;
      load_tree[i].left = NULL;
      load_tree[i].right = NULL;
    }
  }
  fclose(fptr);
  
  return load_tree;
}

Tree * SetRoot(Tree * Load_Tree, int num_nodes)
{
  Tree * root = &Load_Tree[num_nodes - 1];
  root -> parent = NULL;
  
  return root;
}


Tree * TreeBuild(Tree * Load_Tree, Tree * root, int num_nodes)
{
  int left_child = root -> lcnode;
  //printf("Left Child: %d\n", left_child);
  int right_child = root -> rcnode;
  //printf("Right Child: %d\n", right_child);
  int parent_node = root -> parnode;
  
    
    if (parent_node != -1)
    {
      root -> parent = &Load_Tree[parent_node];
    }
    
    if (left_child != -1)
    {
      root -> left = &Load_Tree[left_child - 1];
      TreeBuild(Load_Tree, root -> left, num_nodes);
    }
    
    
    if (right_child != -1)
    {
      root -> right = &Load_Tree[right_child - 1];
      TreeBuild(Load_Tree, root -> right, num_nodes);
    }
    
  return root;
}

void PostOrderPack(Tree * Binary_tree, int num_nodes)
{
  if ((Binary_tree -> left != NULL) && Binary_tree -> right != NULL)
  {
    
    //Tree * left = PostOrderPack(Binary_tree -> left, num_nodes);
    //Tree * right = PostOrderPack(Binary_tree -> right, num_nodes);
    PostOrderPack(Binary_tree -> left, num_nodes);
    PostOrderPack(Binary_tree -> right, num_nodes);
    char cut = Binary_tree -> cutline; 
    printf("Cutline: %c\n", cut);
    printf("Left: %d\n", Binary_tree -> lcnode);
    printf("Right: %d\n", Binary_tree -> rcnode);
  }
}
    
  
  

void PreOrder(Tree * Binary_tree)
{
  if (Binary_tree != NULL)
  {
    printf("%d\n", Binary_tree -> thisnode);
    PreOrder(Binary_tree -> left);
    PreOrder(Binary_tree -> right);
  }
} 

void PostOrder(Tree * Binary_tree)
{
  if (Binary_tree != NULL)
  {
    PostOrder(Binary_tree -> left);
    PostOrder(Binary_tree -> right);
    printf("Node: %d\n", Binary_tree -> thisnode);
    printf("Cutline: %c\n", Binary_tree -> cutline);
  }
} 
      

