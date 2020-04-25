/**************************************************************************
 * author: haskellcg
 * date: 2020-04-22
 * description: merge sort algorithm
 *************************************************************************/

#include "merge_sort.h"

void merge(vector<uint32_t> &vecInt, size_t nLeft, size_t nMid, size_t nRight)
{
    // copy left part vector to new vector
    vector<uint32_t> vecLeftInt;
    size_t nLeftSize = nMid - nLeft + 1;
    for (size_t i = 0; i < nLeftSize; ++i){
        vecLeftInt.push_back(vecInt[nLeft + i]);
    }
    // copy right part vector to new vector
    vector<uint32_t> vecRightInt;
    size_t nRightSize = nRight - nMid;
    for (size_t i = 0; i < nRightSize; ++i){
        vecRightInt.push_back(vecInt[nMid + i + 1]);
    }
    // add sentinels for 2 vectors to simplify the code,
    // so we dont need do empty check for vectors
    vecLeftInt.push_back(MAX_UINT32);
    vecRightInt.push_back(MAX_UINT32);
    // merge process
    size_t nLeftIndex = 0;
    size_t nRightIndex = 0;
    for (size_t i = nLeft; i <= nRight; ++i){
        if (vecLeftInt[nLeftIndex] < vecRightInt[nRightIndex]){
            vecInt[i] = vecLeftInt[nLeftIndex];
            ++nLeftIndex;
        } else {
            vecInt[i] = vecRightInt[nRightIndex];
            ++nRightIndex;
        }
    }
    // DEBUG
    // print_highlight_msg(to_string(vecLeftInt) + "\n");
    // print_highlight_msg(to_string(vecRightInt) + "\n");
    // print_highlight_msg(to_string(vecInt) + "\n");
}

void merge_sort(vector<uint32_t> &vecInt, size_t nBegin, size_t nEnd)
{
    if (nBegin < nEnd){
        size_t nMid = (nBegin + nEnd) >> 1;
        merge_sort(vecInt, nBegin, nMid);
        merge_sort(vecInt, nMid + 1, nEnd);
        merge(vecInt, nBegin, nMid, nEnd);
    }
    // else (nBegin == nEnd),
    // it means only 1 element in the vector, do nothing
}

void merge_sort(vector<uint32_t> &vecInt)
{
    merge_sort(vecInt, 0, vecInt.size() - 1);
}

void merge_sort_test()
{
    print_highlight_msg(">>> Test merge sort funtion:\n");
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
