/**************************************************************************
 * author: haskellcg
 * date: 2020-04-27
 * description: counting sort algorithm
 *************************************************************************/

#ifndef __COUNTING_SORT_H__
#define __COUNTING_SORT_H__

#include "common_types.h"

/**
 * @brief sort vector vecInt with counting sort algorithm
 * @param vector<uint32_t> &vecInt, vector need to be sorted
 * @return void
 * @remarks
 *          make sure vecInt data is in [0, 1000) interval
 */
void counting_sort(vector<uint32_t> &vecInt);

/**
 * @brief test counting sort funtion
 * @param
 * @return void
 * @remarks
 */
void counting_sort_test();

#endif // __COUNTING_SORT_H__
