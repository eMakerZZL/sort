#include "select_sort.h"

void select_sort(elem_type arr[], const size_t length,judge_func func)
{
    int32_t i, j;

    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (func(arr[i], arr[j])) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
