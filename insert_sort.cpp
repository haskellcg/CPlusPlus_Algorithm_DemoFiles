/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: insert sort algorithm
 *************************************************************************/

#include "insert_sort.h"

void insert_sort(vector<uint32_t> &vecInt)
{
    // repeat (n - 1) times
    for (int i = 1; i < (int)vecInt.size(); ++i){
        uint32_t nKey = vecInt[i];
        int j = i - 1;
        // look back for the insert position
        while ((j >= 0) && (vecInt[j] > nKey)){
            vecInt[j + 1] = vecInt[j];
            --j;
            // DEBUG
            // print_highlight_msg("inner loop:" + to_string(vecInt) + "\n");
        }
        vecInt[j + 1] = nKey;
        // DEBUG
        // print_highlight_msg(to_string(vecInt) + "\n");
    }
}

void insert_sort_test()
{
    print_highlight_msg(">>> Test insert sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    insert_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
