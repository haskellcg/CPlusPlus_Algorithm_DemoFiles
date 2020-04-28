/**************************************************************************
 * author: haskellcg
 * date: 2020-04-28
 * description: radix sort algorithm
 *************************************************************************/

#ifndef __RADIX_SORT_H__
#define __RADIX_SORT_H__

#include "common_types.h"

/**
 * @brief sort vecInt with the radix sort algorithm
 * @param vector<uint32_t> &vecInt, vector need to be sorted
 * @return void
 * @remarks
 */
void radix_sort(vector<uint32_t> &vecInt);

/**
 * @brief test radix sort funtion
 * @param
 * @return void
 * @remarks
 */
void radix_sort_test();

#endif // __RADIX_SORT_H__
