#include "quick_sort.h"

#define QSORT 2

static void deal_pivot(elem_type arr[], const int32_t low, const int32_t high);
static void quick_sort_(elem_type arr[], const int32_t lpos, const int32_t rpos, judge_func func);

void quick_sort(elem_type arr[], const size_t length, judge_func func)
{
    quick_sort_(arr, (int32_t)0, (int32_t)(length - 1), func);
}

#if (QSORT == 0)
void quick_sort_(elem_type arr[], const int32_t lpos, const int32_t rpos, judge_func func)
{
    int32_t low, high;
    elem_type temp;

    if (lpos < rpos) {
        low = lpos;
        high = rpos;
        temp = arr[low];

        while (low < high) {
            while (low < high && func(arr[high], temp))
                high--;
            if (low < high)
                arr[low++] = arr[high];

            while (low < high && func(temp, arr[low]))
                low++;
            if (low < high)
                arr[high--] = arr[low];
        }
        arr[low] = temp;

        quick_sort_(arr, lpos, low - 1, func);
        quick_sort_(arr, low + 1, rpos, func);
    }
}
#elif (QSORT == 1)
void quick_sort_(elem_type arr[], const int32_t lpos, const int32_t rpos, judge_func func)
{
    int32_t low, high, mid;
    elem_type temp;

    if (lpos < rpos) {
        low = lpos;
        high = rpos;
        deal_pivot(arr, low, high);
        temp = arr[low];

        while (low < high) {
            while (low < high && func(arr[high], temp))
                high--;
            if (low < high)
                arr[low++] = arr[high];

            while (low < high && func(temp, arr[low]))
                low++;
            if (low < high)
                arr[high--] = arr[low];
        }
        arr[low] = temp;

        quick_sort_(arr, lpos, low - 1, func);
        quick_sort_(arr, low + 1, rpos, func);
    }
}
#elif (QSORT == 2)
static int32_t quick_sort_adjust(elem_type arr[], const int32_t lpos, const int32_t rpos, judge_func func)
{
    int32_t low, high, mid;
    elem_type temp;

    low = lpos;
    high = rpos;
    deal_pivot(arr, low, high);
    temp = arr[low];

    while (low < high) {
        while (low < high && func(arr[high], temp))
            high--;
        if (low < high)
            arr[low++] = arr[high];

        while (low < high && func(temp, arr[low]))
            low++;
        if (low < high)
            arr[high--] = arr[low];
    }
    arr[low] = temp;

    return low;
}

void quick_sort_(elem_type arr[], const int32_t lpos, const int32_t rpos, judge_func func)
{
    int32_t low, high, index;

    stack_t stack;
    stack_init(&stack);

    stack_push(&stack, lpos);
    stack_push(&stack, rpos);

    while (!stack_empty(&stack)) {
        stack_top(&stack, &high);
        stack_pop(&stack);
        stack_top(&stack, &low);
        stack_pop(&stack);

        index = quick_sort_adjust(arr, low, high, func);

        if (index + 1 < high) {
            stack_push(&stack, index + 1);
            stack_push(&stack, high);
        }

        if (index - 1 > low) {
            stack_push(&stack, low);
            stack_push(&stack, index - 1);
        }

    }
}
#endif

void deal_pivot(elem_type arr[], const int32_t low, const int32_t high)
{
    int32_t mid = low + ((high - low) >> 1);
    assert(mid >= 0);

    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[high] < arr[mid])
        swap(&arr[high], &arr[mid]);

    swap(&arr[low], &arr[mid]);
}
