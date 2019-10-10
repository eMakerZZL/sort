#include "stack.h"

void stack_init(stack_t* stack)
{
    assert(stack);

    stack->size = -1;
}

bool stack_push(stack_t* stack, elem_type val)
{
    assert(stack);

    bool ret = false;

    if (stack->size < MAX_STACK_SIZE) {
        stack->data[++stack->size] = val;
        ret = true;
    }

    return ret;
}

bool stack_pop(stack_t* stack)
{
    assert(stack);

    bool ret = false;
    if (!stack_empty(stack)) {
        stack->size -= 1;
        ret = true;
    }

    return ret;
}

bool stack_top(stack_t* stack, elem_type* val)
{
    assert(stack);

    bool ret = false;
    if (!stack_empty(stack)) {
        *val = stack->data[stack->size];
        ret = true;
    }

    return ret;
}

bool stack_empty(stack_t* stack)
{
    assert(stack);

    return stack->size == -1;
}

int32_t stack_size(stack_t* stack)
{
    assert(stack);

    return stack->size + 1;
}
