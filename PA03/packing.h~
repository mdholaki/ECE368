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
  //struct _node * parent;
  //struct _node * left;
  //struct _node * right;
  char cutline;
  double width;
  double length;
}Tree;

//Declaring Functions
Tree * Load_File(char * Filename, int * num_nodes, int * blocks);
Tree * TreeBuild(Tree * Load_Tree, int num_nodes);
#endif
