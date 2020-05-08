/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: main function for test
 *************************************************************************/

#include "bubble_sort.h"
#include "bucket_sort.h"
#include "counting_sort.h"
#include "heap_sort.h"
#include "insert_sort.h"
#include "maximum_subarray.h"
#include "merge_sort.h"
#include "order_statistic_funtions.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "strassen_matrix_multiply.h"

int main(int argc, char *argv[])
{
    if ((argc >= 2) && ("-a" == string(argv[1]))){
        bubble_sort_test();
        bucket_sort_test();
        counting_sort_test();
        heap_sort_test();
        insert_sort_test();
        maximum_subarray_test();
        merge_sort_test();
        order_statistic_funtions_test();
        quick_sort_test();
        radix_sort_test();
        selection_sort_test();
        shell_sort_test();
        strassen_matrix_multiply_test();
    } else {
        // default only test the current coding algorithm
        order_statistic_funtions_test();
    }

    return 0;
}
