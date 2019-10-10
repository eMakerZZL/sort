#ifndef SORT_H
#define SORT_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef uint32_t elem_type;
typedef bool(*judge_func)(elem_type lvalue, elem_type rvalue);

void swap(elem_type* lvalue, elem_type* rvalue);
bool increase(elem_type lvalue, elem_type rvalue);
bool decrease(elem_type lvalue, elem_type rvalue);

#endif /* end of include guard: SORT_H */
