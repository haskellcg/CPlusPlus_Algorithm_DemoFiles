/**************************************************************************
 * author: haskellcg
 * date: 2020-04-22
 * description: merge sort algorithm
 *************************************************************************/

#include "merge_sort.h"

void merge_sort(vector<uint32_t> &vecInt)
{
}

void merge_sort_test()
{
    print_normal_msg(">>> Test insert sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    merge_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
