#include <stdio.h>
#include <stdlib.h>

node * Load_File(char * Filename)
{
  FILE * fptr = fopen(Filename, "r");
  
  if(fptr == NULL)
  {
    return NULL;
  }
  
  node * head = NULL;
  int i = 0;
  long num;
  
  
  
  for(i = 0;fscanf(fptr, "%ld", &num) != EOF; i++)
  {
    if (i == 0)
    {
      head = Create_Node(num);
    }
    
    else 
    {
      head = Insert_Node(head, num);
    }
  }
  
  fclose(fptr);
  
  return head;
}

node * Create_Node(long num)
{
  node * head = malloc(sizeof(Node));
  head -> value = num;
  head -> next = NULL;
  return head;
}

node * Insert_Node(node * head, long num)
{
  head -> next = Create_Node(num);
  return head;
}

    
node * Destroy_node(node * head)
{
  while (head != NULL)
  {
    node * p = head -> next;
    free(head);
    head = p;
  }
}

    
  
  