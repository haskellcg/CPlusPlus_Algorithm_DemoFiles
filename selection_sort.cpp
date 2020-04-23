/**************************************************************************
 * author: haskellcg
 * date: 2020-04-23
 * description: selection sort algorithm
 *************************************************************************/

#include "selection_sort.h"

void selection_sort(vector<uint32_t> &vecInt)
{
}

void selection_sort_test()
{
    print_highlight_msg(">>> Test selection sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    selection_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
