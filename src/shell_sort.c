#include "shell_sort.h"

void shell_sort(elem_type arr[], const size_t length, judge_func func)
{
    assert(length);

    int32_t i, j;
    elem_type temp;
    uint32_t gap = length / 2;

    while (gap > 0) {
        for (i = 0; i < length; i += gap) {
            temp = arr[i];
            for (j = i - gap; j >= 0; j -= gap) {
                if (func(arr[j], temp)) {
                    arr[j + gap] = arr[j];
                } else {
                    break;
                }
            }
            arr[j + gap] = temp;
        }

        gap /= 2;
    }
}
