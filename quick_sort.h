/**************************************************************************
 * author: haskellcg
 * date: 2020-04-26
 * description: quick sort algorithm
 *************************************************************************/

#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "common_types.h"

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
