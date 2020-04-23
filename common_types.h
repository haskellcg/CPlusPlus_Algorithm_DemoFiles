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

#define MAX_UINT32 0xffffffff
#define MIN_INT32 0x80000000

using namespace std;

/**
 * @brief convert vector content to string like this "[x, x, x]"
 * @param const vector<uint32_t> &vecInt, integer vector
 * @return string
 * @remarks
 */
string to_string(const vector<uint32_t> &vecInt);

/**
 * @brief convert vector content to string like this "[x, x, x]"
 * @param const vector<int32_t> &vecInt, integer vector
 * @return string
 * @remarks
 */
string to_string(const vector<int32_t> &vecInt);

/**
 * @brief generate vector with nSize of random uint32_t [100, 1000)
 * @param vector<uint32_t> &vecInt, integer vector
 * @param size_t nSize, number of uint32_t
 * @return void
 * @remarks
 */
void get_random_vector(vector<uint32_t> &vecInt, size_t nSize);

/**
 * @brief check vecInt is sorted or not
 * @param const vector<uint32_t> &vecInt, vector need to be checked
 * @return void
 * @remarks
 */
bool is_sorted_as_ascending(const vector<uint32_t> &vecInt);

/**
 * @brief print msg as normal way
 * @param const string &strMsg, the message
 * @return void
 * @remarks
 */
void print_normal_msg(const string &strMsg);

/**
 * @brief print msg as correct way
 * @param const string &strMsg, the message
 * @return void
 * @remarks
 */
void print_correct_msg(const string &strMsg);

/**
 * @brief print msg as error way
 * @param const string &strMsg, the message
 * @return void
 * @remarks
 */
void print_error_msg(const string &strMsg);

/**
 * @brief print msg as warning way
 * @param const string &strMsg, the message
 * @return void
 * @remarks
 */
void print_warning_msg(const string &strMsg);

/**
 * @brief print msg as highlight way
 * @param const string &strMsg, the message
 * @return void
 * @remarks
 */
void print_highlight_msg(const string &strMsg);

#endif // __COMMON_TYPES_H__
