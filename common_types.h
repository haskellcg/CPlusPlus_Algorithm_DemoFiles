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
#define PRINT_DEFAULT_ERROR print_error_msg("No test case yet.\n");

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

/**
 * @brief h(k) = k mod m
 * @param uint32_t nK, k
 * @param uint32_t nM, m
 * @return uint32_t, hash value
 * @remarks
 *          nM 最好选择不太接近2的整数幂的素数
 */
uint32_t division_hash(uint32_t nK, uint32_t nM);

/**
 * @brief h(k) = floor(m * (kA mod 1))
 * @param uint32_t nK, k
 * @param uint32_t nLogM, 14 if according to the @remarks
 * @return uint32_t, hash value
 * @remarks
 *          这里公式中涉及取整以及取小数部分,但是如果将部分参数
 *          设置为2的整数幂,将会简化为移位操作,极大的简化代码和 
 *          提升性能 
 *
 *          w -- 32, 32位
 *          m -- 2^14, so floor(m * y) == y * 2 ^ (-32 + 14) == y * 2 ^ (-18)
 *          A -- ((sqrt(5) - 1) / 2) * 2 ^ 31 == 2654435769 / 2 ^ 32, so 
 *               (kA mod 1) == (2654435769 * k) mod 2 ^ 32
 */
uint32_t multiplication_hash(uint32_t nK, uint32_t nLogM);

#endif // __COMMON_TYPES_H__
