#include "heap_sort.h"
#include "sort.h"
#include "unity.h"

elem_type* input_arr = NULL;
size_t arr_length = 0;

void setUp(void)
{
    const elem_type arr[] = { 0, 1, 3, 2, 4, 5 };
    arr_length = sizeof(arr) / sizeof(arr[0]);

    input_arr = (elem_type*)malloc(sizeof(elem_type) * arr_length);
    assert(input_arr);

    memcpy(input_arr, arr, sizeof(elem_type) * arr_length);
}

void tearDown(void)
{
    free(input_arr);
    input_arr = NULL;
}

void test_heap_sort_randomElemWillInCreaseSort(void)
{
    const elem_type output_arr[] = { 0, 1, 2, 3, 4, 5 };

    heap_sort(input_arr, arr_length, increase);

    TEST_ASSERT_EQUAL_UINT32_ARRAY(output_arr, input_arr, arr_length);
}

void test_heap_sort_randomElemWillDeCreaseSort(void)
{
    const elem_type output_arr[] = { 0, 5, 4, 3, 2, 1 };

    heap_sort(input_arr, arr_length, decrease);
 
    TEST_ASSERT_EQUAL_UINT32_ARRAY(output_arr, input_arr, arr_length);
}
