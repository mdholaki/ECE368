#include <stdio.h>
#include <stdlib.h>
#include "rooting.h"
#include <time.h>

int main(int argc, char ** argv)
{
  Tree * root = NULL;
  
  root = Load_File(argv[1]);
  //double x = 0;
  //double y = 0;
  Tree * parent_node = NULL;
  
  rerootTree(root, parent_node);
  
  
  //PostOrder(root);
  //PostOrderPack(root);
  
  /*xy_coord(root, x, y);
  Tree * xycord = root;
 
  
  while (xycord -> left != NULL)
  {
    xycord = xycord -> left;
  }
  
  printf("\n");
  printf("X-Coordinate: %le\n", xycord -> xc);
  printf("Y-Coordinate: %le\n", xycord -> yc);
  
  //PostOrder(root);
  printf("\n");
  printf("Width: %le\n", root -> width);
  printf("Height: %le\n", root -> height); */
  
  return EXIT_SUCCESS;
}

Tree * Load_File(char * filename)
{
  FILE * fptr = fopen(filename, "r");
  char leaf_or_non;
  int scan_check = 0;
  double wid;
  double len;
  
  
  //Tree * load_tree = malloc(sizeof(Tree));
  Stack * stack = malloc(sizeof(Stack));
  
  while (fscanf(fptr,"%c",&leaf_or_non) != -1)
  {
    Tree * load_tree = malloc(sizeof(Tree));
    if (leaf_or_non == '(')
    {
      scan_check = fscanf(fptr,"%le,", &wid);
      
      scan_check = fscanf(fptr,"%le)", &len);
      
      load_tree -> width = wid;
      
      load_tree -> height = len; 
      
      load_tree -> cutline = '-';
        
      load_tree -> parent = NULL;
      load_tree -> left = NULL;
      load_tree -> right = NULL; 
      load_tree -> xc = 0;
      load_tree -> yc = 0;
      
      stack = Stack_push(stack,load_tree);
      
    }
      
      else
      {
	load_tree -> cutline = leaf_or_non;
	
	load_tree -> xc = 0;
	
	load_tree -> yc = 0;
	
	load_tree -> width = -1;
	
	load_tree -> height = -1;
	
	load_tree -> right = stack -> node;
	
	stack = Stack_Pop(stack);
	
	load_tree -> left = stack -> node;
	
	stack = Stack_Pop(stack);
	
	stack = Stack_push(stack,load_tree);
      }
    }
  
  fclose(fptr);
  return stack -> node;
}

Stack * Create_Stack(Tree * load_tree)
{
  
  Stack * stack_new = malloc(sizeof(Stack));
  
  stack_new -> node = load_tree;
  
  stack_new -> next = NULL;
  
  return stack_new;
}

Stack * Stack_push(Stack * stack, Tree * load_tree)
{   
  Stack * stack_new = Create_Stack(load_tree);
  
  stack_new -> next = stack;
  
  return stack_new;
}

Stack * Stack_Pop(Stack * stack)
{
  stack = stack -> next;
  
  return stack;
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

void xy_coord(Tree * Binary_tree, double x, double y)
{
  if (Binary_tree != NULL)
  {
    if (Binary_tree -> cutline == 'H')
    {
      //printf("TestH\n");
      xy_coord(Binary_tree -> right,x,y);
      y = ((Binary_tree -> right) -> height) + y;
      x = ((Binary_tree -> left) -> xc) + x;
      xy_coord(Binary_tree -> left,x,y);
    }
  
    if (Binary_tree -> cutline == 'V')
    {
      //printf("TestV\n");
      xy_coord(Binary_tree -> left,x,y);
      x = ((Binary_tree -> left) -> width) + x;
      y = ((Binary_tree -> right) -> yc) + y;
      xy_coord(Binary_tree -> right,x,y);
    }
    
    if (Binary_tree -> cutline == '-')
    {
      //printf("Test-\n");
      Binary_tree -> xc = x;
      Binary_tree -> yc = y;
    }
    /*printf("Node: %d\n", Binary_tree -> thisnode);
    printf("X Coordinate: %lf\n", Binary_tree -> xc);
    printf("Y Coordinate: %lf\n\n\n", Binary_tree -> yc);
    */
    /* if ((Binary_tree -> thisnode) == blocks)
    {
      printf("\n\n");
      printf("X-Coordinate: %le\n", Binary_tree -> xc);
      printf("Y-Coordinate: %le\n", Binary_tree -> yc);
    } */
  }
}
  
/*void rerootTree(Tree * root, Tree * parent_node)
{
  printf("(%le , %le)\n", root -> width, root -> height);
  if ((root -> left) -> cutline != '-' || (root -> right) -> cutline != '-')
  { 
    //Declarations  
    parent_node = root; 
    //printf("Parent Node\n");
    
    //Rerooting Left Side
    parent_node -> left = (root -> left) -> right;
    //printf("Parent Node left\n");
    (root -> left) -> right = parent_node;
    printf("Left\n");
    
    rerootTree(root -> left, parent_node);
    
    parent_node -> left = (root -> left) -> left;
    (root -> left) -> left = parent_node;
    rerootTree(root -> left, parent_node);   
    
    //Rerooting Right Side
    parent_node -> right = (root -> right) -> right;
    (root -> right) -> right = parent_node;
    rerootTree(root -> right, parent_node);
    
    parent_node -> right = (root -> right) -> left;
    (root -> right) -> left = parent_node;
    rerootTree(root -> right, parent_node);
  }   
} */

/* void rerootTree(Tree * root, Tree * parent_node)
{
  printf("Cutline: %c\n", root -> cutline);
  printf("(%le , %le)\n", root -> width, root -> height);
  if ((root ->left) -> cutline != '-' || (root -> right) -> cutline != '-'  )
  {
    //Declarations  
    parent_node = root; 
    
    
    Tree * current_node = root -> left;
    //Rerooting Left Side
    
    parent_node -> left = current_node -> right;
    current_node -> right = parent_node;
    rerootTree(current_node, parent_node);
    
    
    parent_node -> left = current_node -> left;
    current_node -> left = parent_node;
    rerootTree(current_node, parent_node);   
    
    //Rerooting Right Side
    current_node = root -> right;
    parent_node -> right = current_node -> right;
    current_node -> right = parent_node;
    rerootTree(current_node, parent_node);
    
    
    parent_node -> right = current_node -> left;
    current_node -> left = parent_node;
    rerootTree(current_node, parent_node);
  }
} */

void rerootTree(Tree * root, Tree * parent_node)
{
  //printf("Cutline: %c\n", root -> cutline);
  //printf("(%le , %le)\n", root -> width, root -> height);
  //Declarations  
  Tree * current_node = root -> left;
  Tree * swap_node = root;
  if ((root -> left) -> cutline == '-' || (root -> right) -> cutline == '-') 
  {
    return;
  }
  else
  {
    //Rerooting Left Side
    
    swap_node -> left = current_node -> right;
    current_node -> right = swap_node;
    rerootTree(current_node, root);  
    
  
    swap_node -> left = current_node -> left;
    
    current_node -> left = swap_node;
    
    rerootTree(current_node, root);
    
  }
  
   //printf("Test1\n");
   
    //Rerooting Right Side
    root = parent_node;
    current_node = root -> right;
    swap_node = root;
    swap_node -> right = current_node -> right;
    current_node -> right = swap_node;
    rerootTree(current_node, root);
    
    
    
    swap_node -> right = current_node -> left;
    current_node -> left = swap_node;
    rerootTree(current_node, root);
    
}


    
    
  
  
    
  
  
  
  


void PostOrder(Tree * root)
{
  if (root != NULL)
  {
    PostOrder(root -> left);
    PostOrder(root -> right);
    if (root -> width != -1)
    {
      printf("(%le,%le)", root -> width, root->height);
    }
    else
    {
      printf(" %c ", root -> cutline);
    }
  }
} 

      
      