/**************************************************************************
 * author: haskellcg
 * date: 2020-04-28
 * description: bucket sort algorithm
 *************************************************************************/

#include "bucket_sort.h"

void bucket_sort(vector<uint32_t> &vecInt)
{
    // TODO: add code
}

void bucket_sort_test()
{
    print_highlight_msg(">>> Test bucket sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    bucket_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}