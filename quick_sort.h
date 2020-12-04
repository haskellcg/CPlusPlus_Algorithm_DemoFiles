/**************************************************************************
 * author: haskellcg
 * date: 2020-04-26
 * description: quick sort algorithm
 *************************************************************************/

#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "common_types.h"

/**
 * @brief partition vecInt with pivot
 * @param vector<uint32_t> &vecInt, vecInt
 * @param int32_t nBegin, begin
 * @param int32_t nEnd, end
 * @param uint32_t nPivot, pivot
 * @return int32_t, final pivot index
 * @remarks
 */
int32_t partition(vector<uint32_t> &vecInt, int32_t nBegin, int32_t nEnd, uint32_t nPivot);

/**
 * @brief chose a element in [nBegin, nEnd] as pivot, and then partition vecInt with it
 * @param vector<uint32_t> &vecInt, vecInt
 * @param int32_t nBegin, begin
 * @param int32_t nEnd, end
 * @return int32_t, final pivot index
 * @remarks
 */
int32_t partition_random(vector<uint32_t> &vecInt, int32_t nBegin, int32_t nEnd);

/**
 * @brief sort vecInt with quick sort algorithm
 * @param vector<uint32_t> &vecInt, vector need to be sorted
 * @return void
 * @remarks
 */
void quick_sort(vector<uint32_t> &vecInt);

/**
 * @brief test quick sort funtion
 * @param
 * @return void
 * @remarks
 */
void quick_sort_test();

#endif // __QUICK_SORT_H__
