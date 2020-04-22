/**************************************************************************
 * author: haskellcg
 * date: 2020-04-22
 * description: merge sort algorithm
 *************************************************************************/

#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "common_types.h"

/**
 * @brief use merge sort algorithm to sort vecInt
 * @param vector<uint32_t> &vecInt, vector need to sort
 * @return void
 * @remarks
 */
void merge_sort(vector<uint32_t> &vecInt);

/**
 * @brief test merge sort algorithm
 * @param
 * @return void
 * @remarks
 */
void merge_sort_test();

#endif // __MERGE_SORT_H__
