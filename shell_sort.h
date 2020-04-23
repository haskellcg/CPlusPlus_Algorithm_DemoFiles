/**************************************************************************
 * author: haskellcg
 * date: 2020-04-23
 * description: shell sort algorithm
 *************************************************************************/

#ifndef __SHELL_SORT_H__
#define __SHELL_SORT_H__

#include "common_types.h"

/**
 * @brief use shell sort algorithm to sort vecInt
 * @param vector<uint32_t> &vecInt, vector need to be sorted
 * @return void
 * @remarks
 */
void shell_sort(vector<uint32_t> &vecInt);

/**
 * @brief test shell sort algorithm
 * @param
 * @return void
 * @remarks
 */
void shell_sort_test();

#endif // __SHELL_SORT_H__
