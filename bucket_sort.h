/**************************************************************************
 * author: haskellcg
 * date: 2020-04-28
 * description: bucket sort algorithm
 *************************************************************************/

#ifndef __BUCKET_SORT_H__
#define __BUCKET_SORT_H__

#include "common_types.h"

/**
 * @brief sort vecInt with bucket sort algorithm
 * @param vector<uint32_t> &vecInt, vector need to be sorted
 * @return void
 * @remarks
 *          assume all int is 3 digit
 */
void bucket_sort(vector<uint32_t> &vecInt);

/**
 * @brief test bucket sort funtion
 * @param
 * @return void
 * @remarks
 */
void bucket_sort_test();

#endif // __BUCKET_SORT_H__
