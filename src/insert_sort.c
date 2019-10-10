#include "insert_sort.h"

void insert_sort(elem_type arr[], const size_t length,judge_func func)
{
    int32_t i,j;
    elem_type temp;

    for (i = 1; i < length; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (func(arr[j], temp)) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
