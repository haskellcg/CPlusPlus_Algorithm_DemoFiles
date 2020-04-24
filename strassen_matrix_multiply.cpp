/**************************************************************************
 * author: haskellcg
 * date: 2020-04-24
 * description: strassen matrix multiply algorithm
 *************************************************************************/

#include "strassen_matrix_multiply.h"

void force_matrix_multiply(const vector<vector<int32_t>> &matrixA,
                           const vector<vector<int32_t>> &matrixB,
                           vector<vector<int32_t>> &matrixC)
{
    // assume matrixA and matrixB are all n x n, and n is not 0
    size_t nRows = matrixA.size();
    size_t nColumns = nRows;
    for (size_t i = 0; i < nRows; ++i){
        vector<int32_t> vecInt;
        for (size_t j = 0; j < nColumns; ++j){
            vecInt.push_back(0);
            for (size_t k = 0; k < nColumns; ++k){
                vecInt[j] += (matrixA[i][k] * matrixB[k][j]);
            }
        }
        matrixC.push_back(vecInt);
    }
}

void strassen_matrix_multiply(const vector<vector<int32_t>> &matrixA,
                              const vector<vector<int32_t>> &matrixB,
                              vector<vector<int32_t>> &matrixC)
{
    // TODO: add strassen algorithm
}

void strassen_matrix_multiply_test()
{
    print_highlight_msg(">>> Test strassen matrix multiply funtion:\n");
    int32_t matrixSrcA[4][4] = {
        {5, -2, 4, 7},
        {-1, 9, 3, 2},
        {8, 6, -6, 4},
        {-4, 2, 7, 1}
    };
    vector<vector<int32_t>> matrixA;
    for (size_t i = 0; i < 4; ++i){
        vector<int32_t> vecInt;
        vecInt.insert(vecInt.begin(), begin(matrixSrcA[i]), end(matrixSrcA[i]));
        matrixA.push_back(vecInt);
    }
    print_normal_msg(to_string(matrixA) + "\n");
    int32_t matrixSrcB[4][4] = {
        {1, 4, 9, -2},
        {8, 4, 2, 6},
        {4, -5, 4, 5},
        {8, 3, 6, -4}
    };
    vector<vector<int32_t>> matrixB;
    for (size_t i = 0; i < 4; ++i){
        vector<int32_t> vecInt;
        vecInt.insert(vecInt.begin(), begin(matrixSrcB[i]), end(matrixSrcB[i]));
        matrixB.push_back(vecInt);
    }
    print_normal_msg(to_string(matrixB) + "\n");
    int32_t matrixSrcC[4][4] = {
        {61, 13, 99, -30},
        {99, 23, 33, 63},
        {64, 98, 84, -26},
        {48, -40, 2, 51}
    };
    vector<vector<int32_t>> matrixC;
    for (size_t i = 0; i < 4; ++i){
        vector<int32_t> vecInt;
        vecInt.insert(vecInt.begin(), begin(matrixSrcC[i]), end(matrixSrcC[i]));
        matrixC.push_back(vecInt);
    }
    print_highlight_msg("expect result:\n");
    print_normal_msg(to_string(matrixC) + "\n");
    // test force matrix multiply
    print_highlight_msg("force funtion result:\n");
    vector<vector<int32_t>> matrixForceResult;
    force_matrix_multiply(matrixA, matrixB, matrixForceResult);
    print_normal_msg(to_string(matrixForceResult) + "\n");
    if (matrixForceResult == matrixC){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
    // test strassen matrix multiply
    print_highlight_msg("strassen funtion result:\n");
    vector<vector<int32_t>> matrixStrassenResult;
    strassen_matrix_multiply(matrixA, matrixB, matrixStrassenResult);
    print_normal_msg(to_string(matrixStrassenResult) + "\n");
    if (matrixStrassenResult == matrixC){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
