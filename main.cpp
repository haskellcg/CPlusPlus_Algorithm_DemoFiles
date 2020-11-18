/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: main function for test
 *************************************************************************/

#include "basic_queue.h"
#include "basic_stack.h"
#include "binary_tree.h"
#include "bubble_sort.h"
#include "bucket_sort.h"
#include "counting_sort.h"
#include "double_link_list.h"
#include "hash_set.h"
#include "heap_sort.h"
#include "insert_sort.h"
#include "maximum_subarray.h"
#include "merge_sort.h"
#include "nowcoder_com_first_part.h"
#include "order_statistic_funtions.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "strassen_matrix_multiply.h"
#include "string_hash_funtions.h"

int main(int argc, char *argv[])
{
    if ((argc >= 2) && ("-a" == string(argv[1]))){
        basic_queue_test();
        basic_stack_test();
        binary_tree_test();
        bubble_sort_test();
        bucket_sort_test();
        counting_sort_test();
        double_link_list_test();
        hash_set_test();
        heap_sort_test();
        insert_sort_test();
        maximum_subarray_test();
        merge_sort_test();
        nowcoder_com_test();
        order_statistic_funtions_test();
        quick_sort_test();
        radix_sort_test();
        selection_sort_test();
        shell_sort_test();
        strassen_matrix_multiply_test();
        string_hash_funtions_test();
    } else {
        // default: only test the current coding algorithm
        binary_tree_test();
        nowcoder_com_test();
        order_statistic_funtions_test();
        string_hash_funtions_test();
    }

    return 0;
}
