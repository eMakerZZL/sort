#include "bubble_sort.h"

void bubble_sort(elem_type arr[], const size_t length, judge_func func)
{
    int32_t i,j;
    bool exchange = false;

    for (i = 0; i < length; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (func(arr[j], arr[j + 1])) {
               swap(&arr[j], &arr[j + 1]);
               exchange = true;
            }
        }
        if (!exchange) break;
    }
}
