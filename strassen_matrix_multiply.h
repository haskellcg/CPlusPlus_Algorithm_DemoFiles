/**************************************************************************
 * author: haskellcg
 * date: 2020-04-24
 * description: strassen matrix multiply algorithm
 *************************************************************************/

#ifndef __STRASSEN_MATRIX_MULTIPLY_H__
#define __STRASSEN_MATRIX_MULTIPLY_H__

#include "common_types.h"

/**
 * @brief do matrix (n x n) multiply with strassen algorithm
 * @param const vector<vector<int32_t>> &matrixA, matrix A
 * @param const vector<vector<int32_t>> &matrixB, matrix B
 * @param vector<vector<int32_t>> &matrixC, matrix C (= A x B)
 * @return void
 * @remarks
 *          make sure matrix A and matrix B are all (n x n)(n rows and n columns)
 *          and n is the power of 2
 *
 *          Coppersmith-Winograd algorithm: https://en.wikipedia.org/wiki/Coppersmith%E2%80%93Winograd_algorithm    
 *          Galactic algorithm: https://en.wikipedia.org/wiki/Galactic_algorithm
 */
void strassen_matrix_multiply(const vector<vector<int32_t>> &matrixA,
                              const vector<vector<int32_t>> &matrixB,
                              vector<vector<int32_t>> &matrixC);

/**
 * @brief test strassen matrix multiply algorithm
 * @param 
 * @return void
 * @remarks
 */
void strassen_matrix_multiply_test();

#endif // __STRASSEN_MATRIX_MULTIPLY_H__
