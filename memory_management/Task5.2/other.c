#include "header.h"

// Only in this file you can directly call malloc, realloc, etc.
#undef malloc
#undef realloc

void *alloc (size_t size){
  void *mempool;
  mempool = malloc(size);
  if (mempool != NULL) return mempool;
  else {
    printf("Out of memory");
    exit(EXIT_FAILURE);
  }
}

void *re_alloc(void *ptr, size_t size){
  void *mempool;
  mempool = realloc(ptr, size);
  if (mempool != NULL) return mempool;
  else {
    printf("Out of memory");
    exit(EXIT_FAILURE);
  }
}

void initialize_memory(int *array, int size){
  for(int i=0; i<size; i++){
    array[i] = rand() % 100; // populate with random values
  }
}

void show_memory(int *array, int size){
  for(int i=0; i<size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

