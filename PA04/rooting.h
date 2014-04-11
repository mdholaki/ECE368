#ifndef rooting
#define rooting

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct _node{
  struct _node * parent;
  struct _node * left;
  struct _node * right;
  char cutline;
  double width;
  double height;
  double xc;
  double yc;
}Tree;

typedef struct _Stack{
    Tree * node;
    struct _Stack * next;
}Stack;

//Declaring Functions
Tree * Load_File(char * filename);
Stack * Create_Stack(Tree * load_tree);
Stack * Stack_push(Stack * stack, Tree * load_tree);
Stack * Stack_Pop(Stack * stack);
void PostOrder(Tree * root);
void PostOrderPack(Tree * Binary_tree);
void xy_coord(Tree * Binary_tree, double x, double y);
void rerootTree(Tree * root, Tree * parent_node);

#endif
