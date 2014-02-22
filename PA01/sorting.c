#include <stdio.h>
#include <stdlib.h>


/*File Name: Load_File
  Inputs: Filname, Size
  The function extracts the data from the .txt file and inserts it into Array_unsorted. 
  It returns array unsorted to the main function. */

long *Load_File(char *Filename, int *Size)
{
  FILE * fptr = fopen(Filename, "r");
  int store;
  int j;

  if (fptr == NULL)
    {
      return NULL;
    }
  int first; //first line of the array
  first = fscanf(fptr, "%d", Size);
 

  if (first != 1)
    {
      fclose(fptr);
      return NULL;
    }
  
  long * Array_unsorted = malloc(sizeof(long) * (*Size));
  
  for (j = 0; j < (*Size); j++)
    {
      store = fscanf(fptr, "%ld", &Array_unsorted[j]);
	if (store == 0)
	  {
	    free(Array_unsorted);
	    fclose(fptr);
	    return NULL;
	  }
    }

  fclose(fptr);
  return Array_unsorted;
}

/* Function Name: Save_File
   Arguments: Filename, Size
   This function creates the output file. */

int Save_File (char *Filename, long *Array, int Size)
{
  FILE * fptr = fopen(Filename, "w");
 
  int saved = 0;
  int indexed = 0;
  
  fprintf(fptr,"%d\n", Size);
  int i = 0;
  
  for(i = 0; i < Size; i++)
  {
    indexed = fprintf(fptr,"%ld\n", Array[i]);
    saved += indexed;
  }
  
  fclose(fptr);
  
  return saved;
}
/* Function Name: Shell_Insertion_Sort

  Uses Insertion Sort to Implement shell sort. More details in Function */

void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
  int k = 1; //K Value
  int p = 0; 
  int n = Size;
  int tmp = 0; 
  int i = 0;
  int seq_count = 0; //Incremented according to P
  int gap = 0; //Incremented according to K
  int j = 0;
  
  /* While loop finds largest K and P values*/
  
  while (k < n)
  {
    k = k * 3;
    p++;
    
  }
  
  k = k / 3;
  p--;
  
  /* 'k' and 'p' values which will be used to implement shell short */
  
  /*Outermost While Loop iterates through P, or the rows. for do-while loop iterates through the columns of the shell sort 
  and the for loop does the sorting */
  
  while (p >= 0)
  {
    gap = k;
    seq_count = p;
    do
    {
      for (j = gap;j < n; j++)
      {
	tmp = Array[j];
	*N_Move += 1;
	i = j;
	while ((*N_Comp += 1) && (i >= gap) && (Array[i - gap] > tmp))
	{
	  Array[i] = Array[i - gap];
	  i = i - gap;
	  *N_Move += 1;
	}
	Array[i] = tmp; 
	*N_Move += 1;
      }
      gap = (gap/3) * 2;
      seq_count--;
    }while (seq_count >= 0);
    k = k / 3;
    p--;
  }
}

/*Function Name: Shell_Selection_Sort
  The function uses selection sort to sort the arrays and is very similar to Shell_Insertion_Sort.
  The inner loop is different and compares more elements than insertion sort. */

void Shell_Selection_Sort(long *Array, int Size, double *N_comp, double *N_move)
{
 int n = Size;
 int k = 1;
 int p = 0;
 int tmp = 0;
 int i = 0;
 int j = 0;
 int seq_count = 0;
 int gap = 0;
 
 
 while (k < n)
  {
    k = k * 3;
    p++;
  }
  
  k = k / 3;
  p--;
  
  /* 'k' and 'p' values which will be used to implement shell short */
  while (p >= 0)
  {
    gap = k;
    seq_count = p;
    do
    {
      for(i = 0; i <  n -1; i++)
      {
	for (j = i + gap; j < n; j += gap)
	{
	  if ((*N_comp += 1) && (Array[i] > Array[j]))
	  {
	    tmp = Array[i];
	    Array[i] = Array[j];
	    Array[j] = tmp;
	    *N_move += 3;
	  }
	}
      }
      gap = (gap/3) * 2;
      seq_count--;
    } while (seq_count >= 0);
    
    k = k/3;
    p--;
  }
}

/* Function Name: Print_Seq
   The function generates the sequence to be used for the Shell Short process.More details in the Function. */

int Print_Seq(char * Filename, int Size)
{
  FILE *fptr = fopen(Filename, "w");
  
  if (fptr == NULL)
  {
    return 0;
  }
  
  
  //Find Maximum K value//
  int k = 1;
  int p = 0;
  
  while (k < Size)
  {
    k = k * 3;
    p++;
  }
  
  k = k / 3;
  p--;
  int level = p + 1;
  int len = 0;
  /*Find the Height of the Triangle*/
  while (level > 0)
  {
    len += level;
    level--;
  }
  /*Allocate memory for the array*/
  int * Array = malloc(sizeof(int) * len);
  
  int i = 0;
  int gap = 0;
  int seq_count = 0;
  fprintf(fptr,"%d\n", len);
  while (p >= 0)
  { 
    gap = k;
    //printf("Gap: %d\n", gap);
    seq_count = p;
    Array[i] = k;
    //printf("P: %d\n", p);
    do
    {
      if (i < len -1) //Prevents array from surpassing the amount of memory allocated
      {
	i++;
	gap = (gap / 3) * 2;
	Array[i] = gap;
      }
      seq_count--;
      
    }while(seq_count >= 0);
    
    k = k /3;
    p--;
    
  }
  
  
  int j = 0;
  /*Print the array built earlier, but backwards*/
  for(j = len - 1; j >= 0; j--)
  {
    fprintf(fptr,"%d\n", Array[j]);
  }
  
  fclose(fptr);
  free(Array);
  
  return len; 
}
  
  
  
  

