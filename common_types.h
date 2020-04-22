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
 * @brief convert vector content to string like this "[x, x, x]"
 * @param const vector<uint32_t> &vecInt, integer vector
 * @return string
 * @remarks
 */
string to_string(const vector<uint32_t> &vecInt);

/**
 * @brief generate vector with nSize of random uint32_t [100, 1000)
 * @param vector<uint32_t> &vecInt, integer vector
 * @param size_t nSize, number of uint32_t
 * @return void
 * @remarks
 */
void get_random_vector(vector<uint32_t> &vecInt, size_t nSize);

#endif // __COMMON_TYPES_H__
