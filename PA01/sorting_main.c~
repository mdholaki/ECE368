#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Declaring Functions*/
long * Load_File(char * Filename, int * Size);
int Save_File(char * Filename, long * Array, int Size);
void Shell_Insertion_Sort(long * Array, int Size, double *n_comp, double *n_move);
void Shell_Selection_Sort(long * Array, int Size, double *n_comp, double *n_move);
int Print_Seq(char *Filename, int Size);

int main(int argc, char ** argv)
{
  /*Initialize clock variables*/
  clock_t t_input_start = 0;
  clock_t t_input_end = 0;
  clock_t t_input = 0;
  clock_t t_output_start = 0;
  clock_t t_output_end = 0;
  clock_t t_output = 0;
  clock_t t_sorting_start = 0;
  clock_t t_sorting_end = 0;
  clock_t t_sorting = 0;
  
  /*Make sure inputs are valid*/
  if(argc != 5)
  {
    printf("Error\n");
    printf("Intputs are Invalid!\n");
    return EXIT_FAILURE;
  }
  
  /*Load File into Array_unsorted*/
  
  long * Array_unsorted;
  int Size; 
  t_input_start = clock();
  Array_unsorted = Load_File(argv[2], &Size);
  t_input_end = clock(); 
  
  t_input = (t_input_end - t_input_start)/CLOCKS_PER_SEC;
  //printf("t_input: %le\n", (double) t_input);
  
  if (Array_unsorted == NULL)
  {
    return EXIT_FAILURE;
  }
  
  
  /*Call either Insertion Sort or Selection Sort */
  
  double N_comp = 0;
  double N_move = 0;
  t_sorting_start = clock();
  if (*argv[1] == 'i')
  {
    Shell_Insertion_Sort(Array_unsorted, Size, &N_comp, &N_move); 
  }
  
  else if(*argv[1] == 's')
  {
    Shell_Selection_Sort(Array_unsorted, Size, &N_comp, &N_move); 
  }
  else
  {
    printf("Please enter an 'i' or 's' to indicate sorting method.\n");
    return EXIT_FAILURE;
  }
  t_sorting_end = clock();
  
  t_sorting = (t_sorting_end - t_sorting_start)/CLOCKS_PER_SEC;
  
  /*Print Number of moves and comparisons */
  
  printf("Number of comparisons: %le\n", N_comp);
  printf("Number of moves: %le\n", N_move);
  
  
  t_output_start = clock();
  int SeqLen = 0;
  SeqLen = Print_Seq(argv[3], Size);
  
  int print;
  print = Save_File(argv[4], Array_unsorted, Size);
  if (print == 0)
  {
    printf("File did not save\n");
    free(Array_unsorted);
  }
  t_output_end = clock();
  
  free(Array_unsorted);
  t_output = (t_output_end - t_output_start)/CLOCKS_PER_SEC;
  
  /*Print Time Outputs */
  
  printf("I/O Time: %le\n", (double) (t_input + t_output));
  printf("Sort Time: %le\n", (double) (t_sorting));
  
  return EXIT_SUCCESS;
}
  
  