/**************************************************************************
 * author: haskellcg
 * date: 2020-05-08
 * description: order statistic algorithms
 *************************************************************************/

#ifndef __ORDER_STATISTIC_FUNTIONS_H__
#define __ORDER_STATISTIC_FUNTIONS_H__

#include "common_types.h"

/**
 * @brief get the min value's index in the vector
 * @param const vector<uint32_t> &vecInt, vector int
 * @param size_t &nMinIndex, min value's index
 * @param uint32_t &nCompareTimes, compare times in the funtion
 * @return bool, true if find the min value, false if cant find min value
 * @remarks
 */
bool get_min_value_index(const vector<uint32_t> &vecInt, size_t &nMinIndex, uint32_t &nCompareTimes);

/**
 * @brief get the <min, max> values' index in the vector
 * @param const vector<uint32_t> &vecInt, vector int
 * @param pair<size_t, size_t> &pairMinMaxIndex, <min value's index, max value's index>
 * @param uint32_t &nCompareTimes, compare times in the funtion
 * @return bool, true if find the min/max value, false if cant find min/max value
 * @remarks
 */
bool get_min_max_value_index(const vector<uint32_t> &vecInt, pair<size_t, size_t> &pairMinMaxIndex, uint32_t &nCompareTimes);

/**
 * @brief test order statistic funtions
 * @param
 * @return void
 * @remarks
 */
void order_statistic_funtions_test();

#endif // __ORDER_STATISTIC_FUNTIONS_H__
