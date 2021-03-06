/**************************************************************************
 * author: haskellcg
 * date: 2020-05-08
 * description: order statistic algorithms
 *************************************************************************/

#include "insert_sort.h"
#include "order_statistic_funtions.h"
#include "quick_sort.h"

bool get_min_value_index(const vector<uint32_t> &vecInt, size_t &nMinIndex, uint32_t &nCompareTimes)
{
    if (vecInt.empty()){
        return false;
    }
    nMinIndex = 0;
    for (size_t i = 1; i < vecInt.size(); ++i){
        if (vecInt[i] < vecInt[nMinIndex]){
            nMinIndex = i;
        }
        ++nCompareTimes;
    }

    return true;
}

bool get_min_max_value_index(const vector<uint32_t> &vecInt, pair<size_t, size_t> &pairMinMaxIndex, uint32_t &nCompareTimes)
{
    if (vecInt.empty()){
        return false;
    }
    size_t nStartIndex = MAX_UINT32;
    if (0 == (vecInt.size() % 2)){
        if (vecInt[0] < vecInt[1]){
            pairMinMaxIndex.first = 0;
            pairMinMaxIndex.second = 1;
        } else {
            pairMinMaxIndex.first = 1;
            pairMinMaxIndex.second = 0;
        }
        ++nCompareTimes;
        nStartIndex = 2;
    } else {
        pairMinMaxIndex.first = 0;
        pairMinMaxIndex.second = 0;
        nStartIndex = 1;
    }
    for (; nStartIndex < vecInt.size(); nStartIndex += 2){
        if (vecInt[nStartIndex] < vecInt[nStartIndex + 1]){
            if (vecInt[nStartIndex] < vecInt[pairMinMaxIndex.first]){
                pairMinMaxIndex.first = nStartIndex;
            }
            if (vecInt[nStartIndex + 1] > vecInt[pairMinMaxIndex.second]){
                pairMinMaxIndex.second = nStartIndex + 1;
            }
        } else {
            if (vecInt[nStartIndex + 1] < vecInt[pairMinMaxIndex.first]){
                pairMinMaxIndex.first = nStartIndex + 1;
            }
            if (vecInt[nStartIndex] > vecInt[pairMinMaxIndex.second]){
                pairMinMaxIndex.second = nStartIndex;
            }
        }
        nCompareTimes += 3;
    }
    return true;
}

bool select_nth_with_partition(vector<uint32_t> &vecInt, int32_t nBegin, int32_t nEnd, size_t nNth, uint32_t &nNthValue)
{
    if (nBegin == nEnd){
        nNthValue = vecInt[nBegin];
        return true;
    } else {
        int32_t nPartitionIndex = partition_random(vecInt, nBegin, nEnd);
        size_t nPartitionNth = (size_t)(nPartitionIndex - nBegin + 1);
        if (nNth == nPartitionNth){
            nNthValue = vecInt[nPartitionIndex];
            return true;
        } else if (nNth < nPartitionNth){
            return select_nth_with_partition(vecInt, nBegin, nPartitionIndex - 1, nNth, nNthValue);
        } else {
            return select_nth_with_partition(vecInt, nPartitionIndex + 1, nEnd, (nNth - nPartitionNth), nNthValue);
        }
    }
}

bool select_nth_with_partition(const vector<uint32_t> &vecInt, size_t nNth, uint32_t &nNthValue)
{
    if ((0 == nNth) || (nNth > vecInt.size())){
        return false;
    }
    vector<uint32_t> vecCpInt = vecInt;
    return select_nth_with_partition(vecCpInt, 0, (int32_t)(vecCpInt.size() - 1), nNth, nNthValue);
}

bool select_nth_with_5group(const vector<uint32_t> &vecInt, size_t nNth, uint32_t &nNthValue)
{
    if ((0 == nNth) || (nNth > vecInt.size())){
        return false;
    }
    vector<vector<uint32_t>> vec5Groups;
    vector<uint32_t> vec5Group;
    for (size_t i = 0; i < vecInt.size(); ++i){
        if (0 == (i % 5)){
            if (!vec5Group.empty()){
                vec5Groups.push_back(vec5Group);
            }
            vec5Group.clear();
        }
        vec5Group.push_back(vecInt[i]);
    }
    if (!vec5Group.empty()){
        vec5Groups.push_back(vec5Group);
    }

    // use insertion sort to sort every 5group
    // and put every mid to group
    vector<uint32_t> vecMids;
    for (size_t i = 0; i < vec5Groups.size(); ++i){
        insert_sort(vec5Groups[i]);
        vecMids.push_back(vec5Groups[i][vec5Groups[i].size() / 2]);
    }

    insert_sort(vecMids);
    uint32_t nPivot = vecMids[vecMids.size() / 2];

    vector<uint32_t> vecCpInt = vecInt;
    int32_t nPartitionIndex = partition(vecCpInt, 0, vecCpInt.size() - 1, nPivot);
    size_t nPartitionNth = (size_t)(nPartitionIndex + 1);
    if (nNth == nPartitionNth){
        nNthValue = vecCpInt[nPartitionIndex];
        return true;
    } else if (nNth < nPartitionNth){
        vector<uint32_t> vecCpLowPart;
        for (size_t i = 0; i < (size_t)nPartitionIndex; ++i){
            vecCpLowPart.push_back(vecCpInt[i]);
        }
        return select_nth_with_5group(vecCpLowPart, nNth, nNthValue);
    } else {
        vector<uint32_t> vecCpHighPart;
        for (size_t i = nPartitionIndex + 1; i < vecCpInt.size(); ++i){
            vecCpHighPart.push_back(vecCpInt[i]);
        }
        return select_nth_with_5group(vecCpHighPart, nNth - nPartitionNth, nNthValue);
    }
}

void order_statistic_funtions_test()
{
    print_highlight_msg(">>> Test order statistic funtions:\n");
    uint32_t arrayInt[] = {384, 559, 341, 384, 154, 460, 981, 648, 900, 844};
    vector<uint32_t> vecSrc;
    vecSrc.insert(vecSrc.end(), begin(arrayInt), end(arrayInt));
    print_normal_msg(to_string(vecSrc) + "\n");

    size_t nMinIndex = MAX_UINT32;
    uint32_t nMinFuntionCompareTimes = 0;
    get_min_value_index(vecSrc, nMinIndex, nMinFuntionCompareTimes);
    // DEBUG
    /**
    print_warning_msg("min index: " + to_string(nMinIndex) + "\n" +
                      "compare times: " + to_string(nMinFuntionCompareTimes) + "\n");
    */

    if ((4 == nMinIndex) &&
        ((10 - 1) == nMinFuntionCompareTimes)){
        print_correct_msg("get_min_value_index CORRECT\n");
    } else {
        print_error_msg("get_min_value_index ERROR\n");
    }

    pair<size_t, size_t> pairMinMaxIndex = make_pair(MAX_UINT32, MAX_UINT32);
    uint32_t nMinMaxFuntionCompareTimes = 0;
    get_min_max_value_index(vecSrc, pairMinMaxIndex, nMinMaxFuntionCompareTimes);
    // DEBUG
    /**
    print_warning_msg("<min, max> index: <" + to_string(pairMinMaxIndex.first) +
                                            ", " + to_string(pairMinMaxIndex.second) + ">" + "\n" +
                      "compare times: " + to_string(nMinMaxFuntionCompareTimes) + "\n");
    */

    if ((4 == pairMinMaxIndex.first) &&
        (6 == pairMinMaxIndex.second) &&
        ((3 * (10 / 2) - 2) == nMinMaxFuntionCompareTimes)){
        print_correct_msg("get_min_max_value_index CORRECT\n");
    } else {
        print_error_msg("get_min_max_value_index ERROR\n");
    }

    uint32_t nNthValueWithParition = MAX_UINT32;
    select_nth_with_partition(vecSrc, 7, nNthValueWithParition);
    if (648 == nNthValueWithParition){
        print_correct_msg("select_nth_with_partition CORRECT\n");
    } else {
        print_error_msg("select_nth_with_partition ERROR\n");
    }

    uint32_t nNthValueWith5Group = MAX_UINT32;
    select_nth_with_5group(vecSrc, 5, nNthValueWith5Group);
    if (460 == nNthValueWith5Group){
        print_correct_msg("select_nth_with_5group CORRECT\n");
    } else {
        print_error_msg("select_nth_with_5group ERROR\n");
    }
}
