/**************************************************************************
 * author: haskellcg
 * date: 2020-04-22
 * description: bubble sort algorithm
 *************************************************************************/

#include "bubble_sort.h"

void bubble_sort(vector<uint32_t> &vecInt)
{
    for (size_t i = 1; i < vecInt.size(); ++i){
        // bubble start position
        size_t j = 0;
        // flag for any element swap value
        bool bSwapped= false;
        while (j < (vecInt.size() - i)){
            if (vecInt[j] > vecInt[j + 1]){
                uint32_t nTemp = vecInt[j];
                vecInt[j] = vecInt[j + 1];
                vecInt[j + 1] = nTemp;
                bSwapped = true;
                // DEBUG
                // cout << to_string(vecInt) << endl;
            }
            ++j;
        }
        // if no element swapped this time, that means
        // vector is sorted
        if (!bSwapped){
            break;
        }
    }
}

void bubble_sort_test()
{
    print_normal_msg(">>> Test bubble sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    bubble_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
