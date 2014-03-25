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
  int x = 0;
  int y = 0;
  
  Load_Tree = Load_File(argv[1], &num_nodes, &blocks);
  root = SetRoot(Load_Tree, num_nodes);
  Binary_tree = TreeBuild(Load_Tree, root, num_nodes);
  PostOrderPack(Binary_tree);
  
  
  printf("\nPreorder: ");
  PreOrder(Binary_tree);
  printf("\n\nInorder: ");
  InOrder(Binary_tree);
  printf("\n\nPostorder: ");
  PostOrder(Binary_tree);
  
  printf("\n\nWidth: %lf", Binary_tree -> width);
  printf("\nHeight: %lf\n", Binary_tree -> height);
  xy_coord(Binary_tree,x,y, blocks);
  
  printf("\nElapsed Time: 0.00000\n");
  
  Save_File(argv[2], Binary_tree, blocks);
  
  
  
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
	scan_check = fscanf(fptr, "%lf", &load_tree[i].height);
	//printf("Length: %lf\n\n", load_tree[i].length);
      }
      load_tree[i].parent = NULL;
      load_tree[i].left = NULL;
      load_tree[i].right = NULL;
      load_tree[i].xc = 0;
      load_tree[i].yc = 0;
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

void PostOrderPack(Tree * Binary_tree)
{
  if ((Binary_tree -> left != NULL) && Binary_tree -> right != NULL)
  {
    PostOrderPack(Binary_tree -> left);
    PostOrderPack(Binary_tree -> right);
    char cut = Binary_tree -> cutline; 
    //printf("Cutline: %c\n", cut);
    //printf("Node: %d\n", Binary_tree -> thisnode);
    Tree * temp_left = NULL;
    Tree * temp_right = NULL;
    temp_left = Binary_tree -> left;
    temp_right = Binary_tree -> right;
    
    if (cut == 'V')
    {
      Binary_tree -> width = (temp_left -> width) + (temp_right -> width);
      
      if ((temp_left -> height) > (temp_right -> height))
      {
	Binary_tree -> height = temp_left -> height;
      }
      else 
      {
	Binary_tree -> height = temp_right -> height;
      }
    }
      
    if (cut == 'H')
    {
      Binary_tree -> height = (temp_left -> height) + (temp_right -> height);
      
      if ((temp_left -> width) > (temp_right -> width))
      {
	Binary_tree -> width = temp_left -> width; 
      }
      else
      {
	Binary_tree -> width = temp_right -> width;
      }
    }
   //printf("Width: %lf\n", Binary_tree -> width);
   //printf("Height: %lf\n", Binary_tree -> height);
  } 
}
    
void xy_coord(Tree * Binary_tree, double x, double y, int blocks)
{
  if (Binary_tree != NULL)
  {
    if (Binary_tree -> cutline == 'H')
    {
      xy_coord(Binary_tree -> right,x,y, blocks);
      y = ((Binary_tree -> right) -> height) + y;
      x = ((Binary_tree -> left) -> xc) + x;
      xy_coord(Binary_tree -> left,x,y, blocks);
    }
  
    if (Binary_tree -> cutline == 'V')
    {
      xy_coord(Binary_tree -> left,x,y, blocks);
      x = ((Binary_tree -> left) -> width) + x;
      y = ((Binary_tree -> right) -> yc) + y;
      xy_coord(Binary_tree -> right,x,y, blocks);
    }
    
    if (Binary_tree -> cutline == '-')
    {
      Binary_tree -> xc = x;
      Binary_tree -> yc = y;
    }
    /*printf("Node: %d\n", Binary_tree -> thisnode);
    printf("X Coordinate: %lf\n", Binary_tree -> xc);
    printf("Y Coordinate: %lf\n\n\n", Binary_tree -> yc);
    */
    if ((Binary_tree -> thisnode) == blocks)
    {
      printf("\n\n");
      printf("X-Coordinate: %lf\n", Binary_tree -> xc);
      printf("Y-Coordinate: %lf\n", Binary_tree -> yc);
    } 
  }
}
  

void PreOrder(Tree * Binary_tree)
{
  if (Binary_tree != NULL)
  {
    printf("%d ", Binary_tree -> thisnode);
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
    printf("%d ", Binary_tree -> thisnode);
  }
} 

void InOrder(Tree * Binary_tree)
{
  if (Binary_tree != NULL)
  {
    InOrder(Binary_tree -> left);
    printf("%d ", Binary_tree -> thisnode);
    InOrder(Binary_tree -> right);
    
  }
} 
      
Tree * SearchTree(Tree * Binary_tree, int i)
{
  Tree * search = NULL;
  if (Binary_tree != NULL)
  {
    search = SearchTree(Binary_tree -> left, i);
    printf("Test\n");
    search = SearchTree(Binary_tree -> right, i);
    if (search -> thisnode == i)
    {
      //printf("Final\n");
      return search;
    }
  }
  return NULL;
}
  
void Save_File(char * Filename, Tree * Binary_tree, int blocks)
{
  FILE * fptr = NULL;
  
  fptr = fopen(Filename, "w");
  fprintf(fptr, "%d\n", blocks);
  //Tree * Search = NULL;
  int i;
  for (i = 1; i <= blocks; i++)
  {
     Binary_tree = SearchTree(Binary_tree, i);
    
    fprintf(fptr, "%d ", Binary_tree -> thisnode);
    
    fprintf(fptr, "%lf ", Binary_tree -> width);
    
    fprintf(fptr, "%lf ", Binary_tree -> height);
    
    fprintf(fptr, "%lf ", Binary_tree -> xc);
    
    fprintf(fptr, "%lf \n", Binary_tree -> yc);
    printf("Over\n");
  }
  

  fclose(fptr);
}