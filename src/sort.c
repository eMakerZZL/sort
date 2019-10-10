#include "sort.h"

void swap(elem_type* lvalue, elem_type* rvalue)
{
    elem_type temp = *lvalue;
    *lvalue = *rvalue;
    *rvalue = temp;
}

bool increase(elem_type lvalue, elem_type rvalue)
{
    return lvalue >= rvalue;
}

bool decrease(elem_type lvalue, elem_type rvalue)
{
    return lvalue <= rvalue;
}

