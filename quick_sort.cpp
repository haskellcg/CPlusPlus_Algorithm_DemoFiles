/**************************************************************************
 * author: haskellcg
 * date: 2020-04-26
 * description: quick sort algorithm
 *************************************************************************/

#include "quick_sort.h"

void quick_sort(vector<uint32_t> &vecInt)
{
    // TODO: add code
}

void quick_sort_test()
{
    print_highlight_msg(">>> Test quick sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    quick_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
