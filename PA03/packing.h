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
  double height;
  double xc;
  double yc;
}Tree;

//Declaring Functions
Tree * Load_File(char * Filename, int * num_nodes, int * blocks);
Tree * SetRoot(Tree * Load_Tree, int num_nodes);
Tree * TreeBuild(Tree * Load_Tree,Tree * root, int num_nodes);
//Tree * SearchTree(Tree * Binary_tree, int i);
void PreOrder(Tree * Binary_tree);
void PostOrder(Tree * Binary_tree);
void InOrder(Tree * Binary_tree);
void PostOrderPack(Tree * Binary_tree);
void xy_coord(Tree * Binary_tree, double x, double y, int blocks);
void Save_File(char * Filename, Tree * Binary_tree, int blocks);

#endif
