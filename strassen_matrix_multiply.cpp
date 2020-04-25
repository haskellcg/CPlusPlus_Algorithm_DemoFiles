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

void recursive_matrix_multiply(const vector<vector<int32_t>> &matrixA,
                               const vector<vector<int32_t>> &matrixB,
                               vector<vector<int32_t>> &matrixC)
{
    // assum matrixA and matrixB are all n x n, and n is power of 2
    size_t nN = matrixA.size();
    if (1 == nN){
        vector<int32_t> vecInt;
        vecInt.push_back(matrixA[0][0] * matrixB[0][0]);
        matrixC.push_back(vecInt);
    } else {
        size_t nPartN = nN >> 1;
        vector<vector<int32_t>> matrixA11;
        copy_part_of_matrix(matrixA, 0, 0, nPartN, nPartN, matrixA11);
        vector<vector<int32_t>> matrixA12;
        copy_part_of_matrix(matrixA, 0, nPartN, nPartN, nPartN, matrixA12);
        vector<vector<int32_t>> matrixA21;
        copy_part_of_matrix(matrixA, nPartN, 0, nPartN, nPartN, matrixA21);
        vector<vector<int32_t>> matrixA22;
        copy_part_of_matrix(matrixA, nPartN, nPartN, nPartN, nPartN, matrixA22);
        vector<vector<int32_t>> matrixB11;
        copy_part_of_matrix(matrixB, 0, 0, nPartN, nPartN, matrixB11);
        vector<vector<int32_t>> matrixB12;
        copy_part_of_matrix(matrixB, 0, nPartN, nPartN, nPartN, matrixB12);
        vector<vector<int32_t>> matrixB21;
        copy_part_of_matrix(matrixB, nPartN, 0, nPartN, nPartN, matrixB21);
        vector<vector<int32_t>> matrixB22;
        copy_part_of_matrix(matrixB, nPartN, nPartN, nPartN, nPartN, matrixB22);

        vector<vector<int32_t>> matrixC11;
        vector<vector<int32_t>> matrixA11xB11;
        recursive_matrix_multiply(matrixA11, matrixB11, matrixA11xB11);
        vector<vector<int32_t>> matrixA12xB21;
        recursive_matrix_multiply(matrixA12, matrixB21, matrixA12xB21);
        matrix_add(matrixA11xB11, matrixA12xB21, matrixC11);

        vector<vector<int32_t>> matrixC12;
        vector<vector<int32_t>> matrixA11xB12;
        recursive_matrix_multiply(matrixA11, matrixB12, matrixA11xB12);
        vector<vector<int32_t>> matrixA12xB22;
        recursive_matrix_multiply(matrixA12, matrixB22, matrixA12xB22);
        matrix_add(matrixA11xB12, matrixA12xB22, matrixC12);

        vector<vector<int32_t>> matrixC21;
        vector<vector<int32_t>> matrixA21xB11;
        recursive_matrix_multiply(matrixA21, matrixB11, matrixA21xB11);
        vector<vector<int32_t>> matrixA22xB21;
        recursive_matrix_multiply(matrixA22, matrixB21, matrixA22xB21);
        matrix_add(matrixA21xB11, matrixA22xB21, matrixC21);

        vector<vector<int32_t>> matrixC22;
        vector<vector<int32_t>> matrixA21xB12;
        recursive_matrix_multiply(matrixA21, matrixB12, matrixA21xB12);
        vector<vector<int32_t>> matrixA22xB22;
        recursive_matrix_multiply(matrixA22, matrixB22, matrixA22xB22);
        matrix_add(matrixA21xB12, matrixA22xB22, matrixC22);

        for (size_t i = 0; i < nPartN; ++i){
            matrixC.push_back(matrixC11[i]);
            matrixC[i].insert(matrixC[i].end(), matrixC12[i].begin(), matrixC12[i].end());
        }
        for (size_t i = 0; i < nPartN; ++i){
            matrixC.push_back(matrixC21[i]);
            matrixC[nPartN + i].insert(matrixC[nPartN + i].end(), matrixC22[i].begin(), matrixC22[i].end());
        }
    }
}

void strassen_matrix_multiply(const vector<vector<int32_t>> &matrixA,
                              const vector<vector<int32_t>> &matrixB,
                              vector<vector<int32_t>> &matrixC)
{
    // assum matrixA and matrixB are all n x n, and n is power of 2
    size_t nN = matrixA.size();
    if (1 == nN){
        vector<int32_t> vecInt;
        vecInt.push_back(matrixA[0][0] * matrixB[0][0]);
        matrixC.push_back(vecInt);
    } else {
        size_t nPartN = nN >> 1;
        vector<vector<int32_t>> matrixA11;
        copy_part_of_matrix(matrixA, 0, 0, nPartN, nPartN, matrixA11);
        vector<vector<int32_t>> matrixA12;
        copy_part_of_matrix(matrixA, 0, nPartN, nPartN, nPartN, matrixA12);
        vector<vector<int32_t>> matrixA21;
        copy_part_of_matrix(matrixA, nPartN, 0, nPartN, nPartN, matrixA21);
        vector<vector<int32_t>> matrixA22;
        copy_part_of_matrix(matrixA, nPartN, nPartN, nPartN, nPartN, matrixA22);
        vector<vector<int32_t>> matrixB11;
        copy_part_of_matrix(matrixB, 0, 0, nPartN, nPartN, matrixB11);
        vector<vector<int32_t>> matrixB12;
        copy_part_of_matrix(matrixB, 0, nPartN, nPartN, nPartN, matrixB12);
        vector<vector<int32_t>> matrixB21;
        copy_part_of_matrix(matrixB, nPartN, 0, nPartN, nPartN, matrixB21);
        vector<vector<int32_t>> matrixB22;
        copy_part_of_matrix(matrixB, nPartN, nPartN, nPartN, nPartN, matrixB22);

        vector<vector<int32_t>> matrixS1;
        matrix_minus(matrixB12, matrixB22, matrixS1);
        vector<vector<int32_t>> matrixS2;
        matrix_add(matrixA11, matrixA12, matrixS2);
        vector<vector<int32_t>> matrixS3;
        matrix_add(matrixA21, matrixA22, matrixS3);
        vector<vector<int32_t>> matrixS4;
        matrix_minus(matrixB21, matrixB11, matrixS4);
        vector<vector<int32_t>> matrixS5;
        matrix_add(matrixA11, matrixA22, matrixS5);
        vector<vector<int32_t>> matrixS6;
        matrix_add(matrixB11, matrixB22, matrixS6);
        vector<vector<int32_t>> matrixS7;
        matrix_minus(matrixA12, matrixA22, matrixS7);
        vector<vector<int32_t>> matrixS8;
        matrix_add(matrixB21, matrixB22, matrixS8);
        vector<vector<int32_t>> matrixS9;
        matrix_minus(matrixA11, matrixA21, matrixS9);
        vector<vector<int32_t>> matrixS10;
        matrix_add(matrixB11, matrixB12, matrixS10);

        vector<vector<int32_t>> matrixP1;
        strassen_matrix_multiply(matrixA11, matrixS1, matrixP1);
        vector<vector<int32_t>> matrixP2;
        strassen_matrix_multiply(matrixS2, matrixB22, matrixP2);
        vector<vector<int32_t>> matrixP3;
        strassen_matrix_multiply(matrixS3, matrixB11, matrixP3);
        vector<vector<int32_t>> matrixP4;
        strassen_matrix_multiply(matrixA22, matrixS4, matrixP4);
        vector<vector<int32_t>> matrixP5;
        strassen_matrix_multiply(matrixS5, matrixS6, matrixP5);
        vector<vector<int32_t>> matrixP6;
        strassen_matrix_multiply(matrixS7, matrixS8, matrixP6);
        vector<vector<int32_t>> matrixP7;
        strassen_matrix_multiply(matrixS9, matrixS10, matrixP7);

        vector<vector<int32_t>> matrixC11;
        vector<vector<int32_t>> matrixP5PlusP4;
        matrix_add(matrixP5, matrixP4, matrixP5PlusP4);
        vector<vector<int32_t>> matrixAndMinusP2;
        matrix_minus(matrixP5PlusP4, matrixP2, matrixAndMinusP2);
        matrix_add(matrixAndMinusP2, matrixP6, matrixC11);
        vector<vector<int32_t>> matrixC12;
        matrix_add(matrixP1, matrixP2, matrixC12);
        vector<vector<int32_t>> matrixC21;
        matrix_add(matrixP3, matrixP4, matrixC21);
        vector<vector<int32_t>> matrixC22;
        vector<vector<int32_t>> matrixP5PlusP1;
        matrix_add(matrixP5, matrixP1, matrixP5PlusP1);
        vector<vector<int32_t>> matrixAndMinusP3;
        matrix_minus(matrixP5PlusP1, matrixP3, matrixAndMinusP3);
        matrix_minus(matrixAndMinusP3, matrixP7, matrixC22);

        for (size_t i = 0; i < nPartN; ++i){
            matrixC.push_back(matrixC11[i]);
            matrixC[i].insert(matrixC[i].end(), matrixC12[i].begin(), matrixC12[i].end());
        }
        for (size_t i = 0; i < nPartN; ++i){
            matrixC.push_back(matrixC21[i]);
            matrixC[nPartN + i].insert(matrixC[nPartN + i].end(), matrixC22[i].begin(), matrixC22[i].end());
        }
    }
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
    // test recursive matrix multiply
    print_highlight_msg("recursive funtion result:\n");
    vector<vector<int32_t>> matrixRecursiveResult;
    recursive_matrix_multiply(matrixA, matrixB, matrixRecursiveResult);
    print_normal_msg(to_string(matrixRecursiveResult) + "\n");
    if (matrixRecursiveResult == matrixC){
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
