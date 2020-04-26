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
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#define MAX_UINT32 0xffffffff
#define MIN_UINT32 0
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
 * @brief covert matrixInt to string like this:
 *      {
 *          [x, x, x, x],
 *          ....
 *          [x, x, x, x]
 *      }
 * @param const vector<vector<int32_t>> &matrixInt, the matrix need to be convert
 * @return string
 * @remarks
 */
string to_string(const vector<vector<int32_t>> &matrixInt);

/**
 * @brief copy part of matrixSrc according to [nRowIndex, nColumnIndex, nColumns, nRows]
 * @param const vector<vector<int32_t>> &matrixSrc, source matrix
 * @param size_t nRowIndex, start point of row
 * @param size_t nColumnIndex, start point of column
 * @param size_t nColumns, number of columns to copy
 * @param size_t nRows, number of rows to copy
 * @param vector<vector<int32_t>> &matrixCp, the copy result
 * @return bool, true: copy success, false: copy failed
 * @remarks
 *          matrixCp should be empty at the start
 */
bool copy_part_of_matrix(const vector<vector<int32_t>> &matrixSrc,
                         size_t nRowIndex, size_t nColumnIndex,
                         size_t nColumns, size_t nRows,
                         vector<vector<int32_t>> &matrixCp);

/**
 * @brief do matrix (n x m) add
 * @param const vector<vector<int32_t>> &matrixA, matrix A
 * @param const vector<vector<int32_t>> &matrixB, matrix B
 * @param vector<vector<int32_t>> &matrixC, matrix C (= A + B)
 * @return void
 * @remarks
 *          make sure matrix A and matrix B are all (n x m)(n rows and m columns)
 */
void matrix_add(const vector<vector<int32_t>> &matrixA,
                const vector<vector<int32_t>> &matrixB,
                vector<vector<int32_t>> &matrixC);

/**
 * @brief do matrix (n x m) minus
 * @param const vector<vector<int32_t>> &matrixA, matrix A
 * @param const vector<vector<int32_t>> &matrixB, matrix B
 * @param vector<vector<int32_t>> &matrixC, matrix C (= A - B)
 * @return void
 * @remarks
 *          make sure matrix A and matrix B are all (n x m)(n rows and m columns)
 */
void matrix_minus(const vector<vector<int32_t>> &matrixA,
                  const vector<vector<int32_t>> &matrixB,
                  vector<vector<int32_t>> &matrixC);

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
 * @brief swap data between nL and nR
 * @param uint32_t &nL, left data
 * @param uint32_t &nR, right data
 * @return void
 * @remarks
 */
void swap_data(uint32_t &nL, uint32_t &nR);

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
