/**************************************************************************
 * author: haskellcg
 * date: 2020-04-23
 * description: selection sort algorithm
 *************************************************************************/

#include "selection_sort.h"

void selection_sort(vector<uint32_t> &vecInt)
{
    // repeat (n - 1) times
    for (size_t i = 1; i < vecInt.size(); ++i){
        // find the minimum value and put it te the position j
        size_t nMinIndex = i - 1;
        size_t j = i;
        while (j < vecInt.size()){
            if (vecInt[j] < vecInt[nMinIndex]){
                nMinIndex = j;
            }
            ++j;
        }
        // swap value if they are in 2 position
        if (nMinIndex != (i - 1)){
            uint32_t nTemp = vecInt[i - 1];
            vecInt[i - 1] = vecInt[nMinIndex];
            vecInt[nMinIndex] = nTemp;
        }
    }
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
