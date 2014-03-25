#ifndef Packing
#define Packing

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _node{
  int thisnode;
  int parnode;
  int lcnode;
  int rcnode;
  struct _node * parent;
  struct _node * left;
  struct _node * right;
  char cutline;
  double width;
  double length;
}Tree;

//Declaring Functions
Tree * Load_File(char * Filename, int * num_nodes, int * blocks);
Tree * SetRoot(Tree * Load_Tree, int num_nodes);
Tree * TreeBuild(Tree * Load_Tree,Tree * root, int num_nodes);
void PreOrder(Tree * Binary_tree);
void PostOrder(Tree * Binary_tree);
void PostOrderPack(Tree * Binary_tree, int num_nodes);
#endif
