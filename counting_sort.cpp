/**************************************************************************
 * author: haskellcg
 * date: 2020-04-27
 * description: counting sort algorithm
 *************************************************************************/

#include "counting_sort.h"

void counting_sort(vector<uint32_t> &vecInt)
{
    // assume all the int is in [0, 1000)
    uint32_t arrayIntRepeatTimes[1000] = {0};
    for (size_t i = 0; i < vecInt.size(); ++i){
        arrayIntRepeatTimes[vecInt[i]] += 1;
    }
    // calculate relative order according to repeat times
    // [4, 1, 2, 5]
    // [4, 5, 7, 12]
    // after this loop:
    //      (arrayIntRepeatTimes[vecInt]i]] - 1) is the exactly index of
    //      last same value of vecInt[i]
    //      and this is why we need reverse loop in the end
    for (size_t i = 1; i < 1000; ++i){
        arrayIntRepeatTimes[i] += arrayIntRepeatTimes[i - 1];
    }
    // vecCp copy the value of vecInt,
    // so vecInt can store new value
    vector<uint32_t> vecCp = vecInt;
    // reverse loop to keep the same value in same order as they loop before
    for (vector<uint32_t>::reverse_iterator ritrCp = vecCp.rbegin(); ritrCp != vecCp.rend(); ++ritrCp){
        vecInt[(arrayIntRepeatTimes[*ritrCp]) - 1] = *ritrCp;
        arrayIntRepeatTimes[*ritrCp] -= 1;
    }
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
