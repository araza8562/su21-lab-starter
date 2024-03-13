#ifndef _HEADER_GUARD_
#define _HEADER_GUARD_

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Added for generating the random numbers

#define SIZE 5
#define NEW_SIZE (SIZE * 2)

#define malloc "Do not call malloc directly in main!"
#define realloc "Do not call realloc directly in main!"

#define MALLOC(num,type)  (type *)alloc( (num)* sizeof(type) )
#define REALLOC(ptr,num,type)  (type *)re_alloc(ptr, (num)* sizeof(type) )

typedef int integer;

void *alloc(size_t);
void *re_alloc(void *, size_t);

void initialize_memory(int *, int);
void show_memory(int *, int);

#endif

