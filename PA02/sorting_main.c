#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pa02.h"

int main(int argc, char ** argv)
{
  /* Load File Into a Linked List */
  clock_t Input;
  clock_t Output;
  clock_t SortInit;
  clock_t SortFin;
  clock_t SortTime;
  clock_t IO_time;
  Node * head = NULL;
  Input = clock();
  head = Load_File(argv[1]);
  
 //Use Shell Sort to sort the list  
  SortInit = clock();
  
  head = Shell_Sort(head);
  
  SortFin = clock();
  
  int check;
  check = Save_File(argv[2], head);
  Output = clock();
  Destroy_node(head);
  
  SortTime = (SortFin - SortInit)/CLOCKS_PER_SEC;
  IO_time = ((Output - Input)/CLOCKS_PER_SEC);
  IO_time -= SortTime;
  
  printf("I/O Time: %le\n", (double) IO_time);
  printf("Sort Time: %le\n", (double) SortTime);

  return EXIT_SUCCESS;
}
  
  
  