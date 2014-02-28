#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pa02.h"

int main(int argc, char ** argv)
{
  /*if(argc != 3)
  {
    printf("Error\n");
    printf("Inputs are Invalid!\n");
    return EXIT_FAILURE
  } */
  
  
  Node * List_unsorted = NULL;
  
  List_unsorted = Load_File(argv[1]);
  /*printf("List:\n");
  while (List_unsorted != NULL)
  {
    printf("%ld\n", List_unsorted -> value);
    List_unsorted = List_unsorted -> next;
    
  } */
  int check;
  check = Save_File(argv[2], List_unsorted);
 
  

  return 0;
}
  
  
  