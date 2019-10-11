#include "heap_sort.h"

static void sift(elem_type arr[], int32_t low, int32_t high, judge_func func)
{
    int32_t parent, child;
    elem_type temp;

    parent = low;
    temp = arr[parent];
    child = 2 * parent;

    while (child <= high) {
        if (child < high && func(arr[child + 1], arr[child]))
            child++;

        if (func(arr[child], arr[parent])) {
            swap(&arr[parent], &arr[child]);
            parent = child;
            child = 2 * parent;
        } else {
            break;
        }
    }

    arr[parent] = temp;
}

void heap_sort(elem_type arr[], const int32_t length, judge_func func)
{
    assert(length);

    int32_t i;
    for (i = length / 2; i >= 1; i--)
        sift(arr, i, length - 1, func);

    for (i = length - 1; i >= 2; i--) {
        swap(&arr[1], &arr[i]);
        sift(arr, 1, i - 1, func);
    }
}
