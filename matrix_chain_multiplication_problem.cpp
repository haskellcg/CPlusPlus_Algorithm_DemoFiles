/**************************************************************************
 * author: haskellcg
 * date: 2021-01-14
 * description: matrix chain multiplication problem solution
 *************************************************************************/

#include "matrix_chain_multiplication_problem.h"

Matrix_Chain_Multiplication_Problem_Solution::Matrix_Chain_Multiplication_Problem_Solution()
{
}

void Matrix_Chain_Multiplication_Problem_Solution::set_matrices(vector<pair<uint32_t, uint32_t>> &vecMatrices)
{
    m_vecMatrices = vecMatrices;
}

void Matrix_Chain_Multiplication_Problem_Solution::dp_bottom_up_method(vector<vector<uint32_t>> &matrixMultiplyTimes, vector<vector<uint32_t>> &matrixBracketPosition)
{
    for (size_t i = 0; i < m_vecMatrices.size(); ++i){
        vector<uint32_t> vecRow;
        for (size_t j = 0; j < m_vecMatrices.size(); ++j){
            vecRow.push_back(MAX_UINT32);
        }
        matrixMultiplyTimes.push_back(vecRow);
        matrixBracketPosition.push_back(vecRow);
    }

    for (size_t i = 0; i < m_vecMatrices.size(); ++i){
        matrixMultiplyTimes[i][i] = 0;
    }

    for (size_t nSubProblemSize = 1; nSubProblemSize < m_vecMatrices.size(); ++nSubProblemSize){
        for (size_t nStartIndex = 0; nStartIndex < (m_vecMatrices.size() - nSubProblemSize); ++nStartIndex){
            size_t nEndIndex = nStartIndex + nSubProblemSize;
            // subproblem [nStartIndex, nEndIndex]
            uint32_t nMinMultiplyTimes = MAX_UINT32;
            uint32_t nBestBracketPosition = MAX_UINT32;
            for (size_t nBracketPosition = nStartIndex; nBracketPosition < nEndIndex; ++nBracketPosition){
                uint32_t nCurrentMultiplyTimes = matrixMultiplyTimes[nStartIndex][nBracketPosition] +
                                                 matrixMultiplyTimes[nBracketPosition + 1][nEndIndex] +
                                                 m_vecMatrices[nStartIndex].first * m_vecMatrices[nBracketPosition].second * m_vecMatrices[nEndIndex].second;
                if (nCurrentMultiplyTimes < nMinMultiplyTimes){
                    nMinMultiplyTimes = nCurrentMultiplyTimes;
                    nBestBracketPosition = nBracketPosition;
                }
            }

            matrixMultiplyTimes[nStartIndex][nEndIndex] = nMinMultiplyTimes;
            matrixBracketPosition[nStartIndex][nEndIndex] = nBestBracketPosition;
        }
    }
}

void matrix_chain_multiplication_problem_solution_test()
{
    print_highlight_msg(">>> Test matrix chain multiplication problem solution:\n");
    vector<pair<uint32_t, uint32_t>> vecMatrices;
    vecMatrices.push_back(make_pair(5, 4));
    vecMatrices.push_back(make_pair(4, 6));
    vecMatrices.push_back(make_pair(6, 2));
    vecMatrices.push_back(make_pair(2, 7));

    vector<vector<uint32_t>> matrixMultiplyTimes;
    vector<vector<uint32_t>> matrixBracketPosition;
    Matrix_Chain_Multiplication_Problem_Solution oMatrixChainMultiplicationProblemSolution;
    oMatrixChainMultiplicationProblemSolution.set_matrices(vecMatrices);

    /*< test dp_bottom_up_method */
    oMatrixChainMultiplicationProblemSolution.dp_bottom_up_method(matrixMultiplyTimes, matrixBracketPosition);
    if ((matrixMultiplyTimes.size() >= vecMatrices.size()) &&
        (matrixMultiplyTimes[vecMatrices.size() - 1].size() >= vecMatrices.size()) &&
        (matrixMultiplyTimes[0][vecMatrices.size() - 1] == 158)){
        print_correct_msg("dp_bottom_up_method OK.\n");
    } else {
        print_error_msg("dp_bottom_up_method Error.\n");
    }
}

