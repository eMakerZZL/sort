#ifndef STACK_H
#define STACK_H

#include "sort.h"

#define MAX_STACK_SIZE (100)

typedef uint32_t elem_type;

typedef struct _stack_t {
  elem_type data[MAX_STACK_SIZE];
  int32_t size;
} stack_t;

void stack_init(stack_t* stack);
bool stack_push(stack_t* stack, elem_type val);
bool stack_pop(stack_t* stack);
bool stack_top(stack_t* stack, elem_type* val);
bool stack_empty(stack_t* stack);
int32_t stack_size(stack_t* stack);

#endif /* end of include guard: STACK_H */
