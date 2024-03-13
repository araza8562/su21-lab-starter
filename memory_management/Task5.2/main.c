
#include "header.h"

int main()
{
  srand(time(0)); // for generating random numbers

  integer *array = MALLOC(SIZE, integer);
  initialize_memory(array, SIZE);
  show_memory(array, SIZE);

  array = REALLOC(array, NEW_SIZE, integer);
  initialize_memory(array + SIZE, SIZE); // initialize the new elements
  show_memory(array, NEW_SIZE);

  free(array);
  
  return EXIT_SUCCESS;
}

