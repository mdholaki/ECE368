#ifndef PA02
#define PA02

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _node{
  long value;
  struct _node *next;
} Node;

typedef struct _list{
  Node *node;
  struct _list *next;
} List;


/*Declaring Functions*/
Node * Load_File(char * Filename);
Node * Create_Node(long num);
void Destroy_node(Node * head);
Node * Insert_Node(Node * head, long num);
int Save_File(char *Filename, Node *list);

#endif
