/**************************************************************************
 * author: haskellcg
 * date: 2020-04-26
 * description: quick sort algorithm
 *************************************************************************/

#include "quick_sort.h"


int32_t partition(vector<uint32_t> &vecInt, int32_t nBegin, int32_t nEnd, uint32_t nPivot)
{
    // while loop is running:
    //      [nBegin, nSplitIndex] are the elements that < nPivot
    //      [nSplitIndex + 1, nScanIndex - 1] are the elements that >= nPivot
    int32_t nSplitIndex = nBegin - 1;
    for(int32_t nScanIndex = nBegin; nScanIndex < nEnd; ++nScanIndex){
        if (vecInt[nScanIndex] < nPivot){
            ++nSplitIndex;
            if (nSplitIndex != nScanIndex){
                swap_data(vecInt[nSplitIndex], vecInt[nScanIndex]);
            }
        }
    }
    if ((nSplitIndex + 1) != nEnd){
        vecInt[nEnd] = vecInt[nSplitIndex + 1];
        vecInt[nSplitIndex + 1] = nPivot;
    }
    return (nSplitIndex + 1);
}

int32_t partition_random(vector<uint32_t> &vecInt, int32_t nBegin, int32_t nEnd)
{
    // randomize to avoid too bad situation
    srand(time(NULL));
    int32_t nRandomIndex = nBegin + (rand() % (nEnd - nBegin + 1));
    swap_data(vecInt[nEnd], vecInt[nRandomIndex]);
    // use last element as pivot
    uint32_t nPivot = vecInt[nEnd];
    return partition(vecInt, nBegin, nEnd, nPivot);
}

void quick_sort(vector<uint32_t> &vecInt, int32_t nBegin, int32_t nEnd)
{
    if (nBegin < nEnd){
        // (nBegin != nEnd) did't work, cause sometimes nBegin > nEnd
        // like pivot is not always in the mid
        int32_t nMid = partition_random(vecInt, nBegin, nEnd);
        quick_sort(vecInt, nBegin, nMid - 1);
        quick_sort(vecInt, nMid + 1, nEnd);
    }
}

void quick_sort(vector<uint32_t> &vecInt)
{
    quick_sort(vecInt, 0, (vecInt.size() - 1));
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
