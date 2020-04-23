/**************************************************************************
 * author: haskellcg
 * date: 2020-04-23
 * description: shell sort algorithm
 *************************************************************************/

#include "shell_sort.h"

void shell_sort(vector<uint32_t> &vecInt)
{
    // calculate interval base on the formula
    // h = h * 3 + 1
    size_t nInterval = 1;
    while (nInterval < (vecInt.size() / 3)){
        nInterval = nInterval * 3 + 1;
    }
    while (nInterval > 0){
        // sort array with interval and insertion sort
        for (size_t i = nInterval; i < vecInt.size(); ++i){
            uint32_t nKey = vecInt[i];
            size_t j = i;
            while ((j >= nInterval) && (vecInt[j - nInterval] > nKey)){
                vecInt[j] = vecInt[j - nInterval];
                j -= nInterval;
            }
            vecInt[j] = nKey;
        }
        // decrease the interval base on the formula
        nInterval = (nInterval - 1) / 3;
        // DEBUG
        // print_highlight_msg(to_string(vecInt) + "\n");
    }
}

void shell_sort_test()
{
    print_highlight_msg(">>> Test shell sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    shell_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
