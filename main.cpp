/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: main function for test
 *************************************************************************/

#include "avl_tree.h"
#include "basic_queue.h"
#include "basic_stack.h"
#include "binary_search_tree.h"
#include "bubble_sort.h"
#include "bucket_sort.h"
#include "counting_sort.h"
#include "double_link_list.h"
#include "egg_dropping_puzzle.h"
#include "fusion_tree.h"
#include "hash_set.h"
#include "heap_sort.h"
#include "insert_sort.h"
#include "josephus_problem.h"
#include "matrix_circle_print.h"
#include "maximum_subarray.h"
#include "merge_sort.h"
#include "nowcoder_com_first_part.h"
#include "order_statistic_funtions.h"
#include "permutation_generator.h"
#include "quick_sort.h"
#include "radix_heap.h"
#include "radix_sort.h"
#include "radix_tree.h"
#include "red_black_tree.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "strassen_matrix_multiply.h"
#include "string_hash_funtions.h"
#include "tower_of_hanoi_problem.h"

int main(int argc, char *argv[])
{
    if ((argc >= 2) && ("-a" == string(argv[1]))){
        avl_tree_test();
        basic_queue_test();
        basic_stack_test();
        binary_search_tree_test();
        bubble_sort_test();
        bucket_sort_test();
        counting_sort_test();
        double_link_list_test();
        egg_dropping_puzzle_solution_test();
        fusion_tree_test();
        hash_set_test();
        heap_sort_test();
        insert_sort_test();
        josephus_problem_test();
        matrix_circle_print_test();
        maximum_subarray_test();
        merge_sort_test();
        nowcoder_com_test();
        order_statistic_funtions_test();
        permutation_generator_test();
        quick_sort_test();
        radix_heap_test();
        radix_sort_test();
        radix_tree_test();
        red_black_tree_test();
        selection_sort_test();
        shell_sort_test();
        strassen_matrix_multiply_test();
        string_hash_funtions_test();
        tower_of_hanoi_problem_solution_test();
    } else {
        // default: only test the current coding algorithm
        egg_dropping_puzzle_solution_test();
        fusion_tree_test();
        nowcoder_com_test();
        string_hash_funtions_test();
    }

    return 0;
}
