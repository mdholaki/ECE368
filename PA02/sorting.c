#include <stdio.h>
#include <stdlib.h>
#include "pa02.h"

Node *Load_File(char *Filename)
{
  FILE * fptr = fopen(Filename, "r");
  
  Node * Head = NULL;
  //int check = 0;
  long num = 0;
  
  //Loads the File using the insert nodes
  
  while(fscanf(fptr, "%ld", &num) != EOF)
  {
    Head = Insert_Node(Head, num);
  } 
  
  /* while (Head != NULL)
  {
    printf("Head = %ld\n", Head -> value);
    Head = Head -> next;
  } */
  
  fclose(fptr);
  
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
  int size = 0;
  fptr = fopen(Filename, "w");
  Node * tmp = head; 
  
  while(tmp != NULL)
  {
    fprintf(fptr, "%ld\n", tmp -> value);
    tmp = tmp -> next;
    size++;
  }
  
  fclose(fptr);
  
  return size;
}

void Destroy_node(Node * head)
{
  while (head != NULL)
  {
    Node * p = head -> next;
    free(head);
    head = p;
  }
}
  
/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////

//Traverses to the indicated position j

Node * ListTraverse(Node * head, int j)
{
  int count = 0;
  Node *temp = head;
  while (count < j)
  {
    temp = temp -> next;
    count++;
  }
  
  return (temp);
}

//Replaces a value in the linked list with num 

void ListSwap(int num, Node * head, int position)
{
  Node * temp1 = head;
  
  temp1 = ListTraverse(temp1, position);
  
  temp1 -> value = num;
}

//Finds the size of the linked list 
int size_count(Node * head)
{
  int count = 0;
  while (head != NULL)
  {
    head = head -> next;
    count++;
  }
  return count; 
}

Node *Shell_Sort(Node * head)
{
  int k = 1;
  int p = 0;
  int n = 0;
  n = size_count(head);
  int tmp = 0;
  int i = 0;
  int seq_count = 0;
  int gap = 0;
  int j = 0;
  
  Node * list_temp = head;
  Node * list_comp = head;
  //Node * temp = head; 
  int comp_position = 0;
  int compare = 0;
  
  while (k < n)
  {
    k = k * 3;
    p++;
  }
  
  k = k/3;
  p--;
  //Generates the largest value of K
  while (p >= 0) //Iterates level of pyramids 
  {
    gap = k;
    seq_count = p;
    do
    {
      for(j = gap; j < n; j++) 
      {
	list_temp = ListTraverse(head, j); 
	tmp = list_temp -> value; //Finds temps values 
	i = j;
	
	comp_position = i - gap; 
	list_comp = ListTraverse(head, comp_position);
	compare = list_comp -> value;
	while((i >= gap) && (compare > tmp))
	{
	 ListSwap(compare, head, i); //Swaps code
	 
	 i = i - gap; 
	 comp_position = i - gap;
	 list_comp = ListTraverse(head, comp_position);
	 compare = list_comp -> value;
	 
	}
	ListSwap(tmp, head, i);	//Puts temp value back in to the list
	
      }
      
      gap = gap/3 * 2;
      seq_count--;
      
    }while (seq_count >= 0);
    
    k = k/3;
    p--;
  }
  
  return (head);
} 
	
  



    
  
  