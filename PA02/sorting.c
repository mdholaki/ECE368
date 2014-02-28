#include <stdio.h>
#include <stdlib.h>
#include "pa02.h"

Node *Load_File(char *Filename)
{
  FILE * fptr = fopen(Filename, "r");
  
  Node * Head = NULL;
  //int check = 0;
  long num = 0;
  
  while(fscanf(fptr, "%ld", &num) == 1)
  {
    Head = Insert_Node(Head, num);
  }
  
  /* while (Head != NULL)
  {
    printf("Head = %ld\n", Head -> value);
    Head = Head -> next;
  } */
  
  return Head;
}

Node *Create_Node(long num)
{
  Node * new = malloc(sizeof(Node));
  new -> value = num;
  new -> next = NULL;
  return new;
}

Node *Insert_Node(Node *Head, long num)
{
  Node * new = Create_Node(num);
  new -> next = Head;
  
  return new;
}

int Save_File(char *Filename, Node * head)
{
  FILE * fptr = NULL;
  int i = 0;
  fptr = fopen(Filename, "w");
  Node * tmp = head; 
  
  while(tmp != NULL)
  {
    fprintf(fptr, "%ld\n", tmp -> value);
    tmp = tmp -> next;
    i++;
  }
  
  fclose(fptr);
  
  return i;
}

  
 
  
  
 








/*node * ListTraverse(Node * head, int j)
{
  while (count <= j)
  {
    head = head -> next;
  }
  
  return head;
}

node * ListInsert(Node * head, int i, int compare)
{
  
  

void Shell_Insertion_Sort(Node * head, int * Size)
{
  int k = 1;
  int p = 0;
  int n = size; 
  int tmp = 0;
  int i = 0;
  int seq_count = 0;
  int gap = 0;
  int j = 0;
  Node * list_tmp = head;
  Node * list_comp = head;
  
  while (k < n)
  {
    k = k * 3;
    p++
  }
  
  k = k/3;
  p--;
  
  while (p >= 0)
  {
    gap = k;
    seq_count = p;
    do
    {
      for(j = gap; j < n; j++)
      {
	list = ListTraverse(list_tmp, j);
	tmp = list_tmp -> value;
	i = j;
	while((i >= gap))
	{
	  compare = ListTraverse((head, i - gap));
	  if (compare > tmp)
	  {
	    head = ListInsert(head,i,compare);
	    i = i - gap;
	  }
	}
	head = ListInsert(head,i,tmp);
      }
      gap = gap/3 * 2;
      seq_count--;
    }while (seq_count >= 0)
    
    k = k/3;
    p--;
  }
} */
	
  



    
  
  