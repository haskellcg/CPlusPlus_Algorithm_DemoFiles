/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: insert sort algorithm
 *************************************************************************/

#ifndef __INSERT_SORT_H__
#define __INSERT_SORT_H__

#include "common_types.h"

/**
 * @brief insert sort function
 * @param vector<uint32_t> &vecInt, vector of integers that need to be sorted
 * @return void
 * @remarks
 */
void insert_sort(vector<uint32_t> &vecInt);
 
/**
 * @brief insert sort test function
 * @param
 * @return void
 * @remarks
 */
void insert_sort_test();

#endif // __INSERT_SORT_H__
