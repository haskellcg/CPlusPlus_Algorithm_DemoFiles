/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: common headers/macros/functions/structs
 *************************************************************************/

#ifndef __COMMON_TYPES_H__
#define __COMMON_TYPES_H__

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief print vector content like this "[x, x, x]"
 * @param const vector<uint32_t> &vecInt, integer vector
 * @return void
 * @remarks
 */
string print(const vector<uint32_t> &vecInt);

/**
 * @brief generate vector with nIntNum of random uint32_t
 * @param vector<uint32_t> &vecInt, integer vector
 * @param size_t nIntNum, number of uint32_t
 * @param uint32_t nMode, mode
 * @return void
 * @remarks
 */
void random(vector<uint32_t> &vecInt, size_t nIntNum, uint32_t nMode);

#endif // __COMMON_TYPES_H__
