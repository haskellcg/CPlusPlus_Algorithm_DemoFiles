/**************************************************************************
 * author: haskellcg
 * date: 2021-01-06
 * description: circle print matrix
 *************************************************************************/

#ifndef __MATRIX_CIRCLE_PRINT_H__
#define __MATRIX_CIRCLE_PRINT_H__

#include "common_types.h"

/**
 * @brief circle print matrix outline with (nX, nY, nX + nWidth, nY + nHeight)
 * @param const vector<vector<int32>> &matrixSrc, matrix to print
 * @param size_t nX,
 * @param size_t nY,
 * @param size_t nWidth,
 * @param size_t nHeight,
 * @return string
 * @remarks
 */
string circle_print_matrix_outline(const vector<vector<int32_t>> &matrixSrc, size_t nX, size_t nY, size_t nWidth, size_t nHeight);

/**
 * @brief circle print matrixSrc
 * @param const vector<vector<int32>> &matrixSrc, matrix to print
 * @return string, circle print
 * @remarks
 */
string circle_print_matrix(const vector<vector<int32_t>> &matrixSrc);

/**
 * @brief test matrix circle print function
 * @param
 * @return void
 * @remarks
 */
void matrix_circle_print_test();

#endif // __MATRIX_CIRCLE_PRINT_H__
