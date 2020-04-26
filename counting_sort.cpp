/**************************************************************************
 * author: haskellcg
 * date: 2020-04-27
 * description: counting sort algorithm
 *************************************************************************/

#include "counting_sort.h"

void counting_sort(vector<uint32_t> &vecInt)
{
    // TODO: add counting sort code
}

void counting_sort_test()
{
    print_highlight_msg(">>> Test counting sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    counting_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
