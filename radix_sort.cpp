/**************************************************************************
 * author: haskellcg
 * date: 2020-04-28
 * description: radix sort algorithm
 *************************************************************************/

#include "radix_sort.h"

void counting_sort_with_data(vector<uint32_t> &vecDigit, vector<uint32_t> &vecData)
{
    // DEBUG
    // print_warning_msg(to_string(vecDigit) + "\n");
    // print_warning_msg(to_string(vecData) + "\n");
    // assume vecDigit data is all [0, 9]
    uint32_t arrayRepeatTimes[10] = {0};
    for (size_t i = 0; i < vecDigit.size(); ++i){
        arrayRepeatTimes[vecDigit[i]] += 1;
    }
    for (uint32_t i = 1; i < 10; ++i){
        arrayRepeatTimes[i] += arrayRepeatTimes[i - 1];
    }
    vector<uint32_t> vecCpDigit = vecDigit;
    vector<uint32_t> vecCpData = vecData;
    for (int32_t i = vecCpDigit.size() - 1; i >= 0; --i){
        vecDigit[arrayRepeatTimes[vecCpDigit[i]] - 1] = vecCpDigit[i];
        vecData[arrayRepeatTimes[vecCpDigit[i]] - 1] = vecCpData[i];
        arrayRepeatTimes[vecCpDigit[i]] -= 1;
    }
    // DEBUG
    // print_warning_msg(to_string(vecDigit) + "\n");
    // print_warning_msg(to_string(vecData) + "\n");
}

void radix_sort(vector<uint32_t> &vecInt)
{
    vector<uint32_t> vecFirstDigit;
    for (size_t i = 0; i < vecInt.size(); ++i){
        vecFirstDigit.push_back(vecInt[i] % 10);
    }
    counting_sort_with_data(vecFirstDigit, vecInt);

    vector<uint32_t> vecSecondDigit;
    for (size_t i = 0; i < vecInt.size(); ++i){
        vecSecondDigit.push_back((vecInt[i] / 10) % 10);
    }
    counting_sort_with_data(vecSecondDigit, vecInt);

    vector<uint32_t> vecThirdDigit;
    for (size_t i = 0; i < vecInt.size(); ++i){
        vecThirdDigit.push_back((vecInt[i] / 100) % 10);
    }
    counting_sort_with_data(vecThirdDigit, vecInt);
}

void radix_sort_test()
{
    print_highlight_msg(">>> Test radix sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    radix_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
