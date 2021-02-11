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

string Matrix_Chain_Multiplication_Problem_Solution::show_matrices() const
{
    ostringstream ossResult;
    for (size_t i = 0; i < m_vecMatrices.size(); ++i){
        if (0 != i){
            ossResult << " x ";
        }
        ossResult << "[";
        ossResult << m_vecMatrices[i].first;
        ossResult << ", ";
        ossResult << m_vecMatrices[i].second;
        ossResult << "]";
    }
    return ossResult.str();
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
            size_t nBestBracketPosition = MAX_UINT32;
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

string Matrix_Chain_Multiplication_Problem_Solution::dp_bottom_up_method_show_result(const vector<vector<uint32_t>> &matrixMultiplyTimes,
                                                                                     const vector<vector<uint32_t>> &matrixBracketPosition) const
{
    ostringstream ossResult;

    ossResult << "multiplication times result:\n";
    ossResult << "{\n";
    for (size_t i = 0; i < matrixMultiplyTimes.size(); ++i){
        ossResult << "\t[";
        for (size_t j = 0; j < matrixMultiplyTimes[i].size(); ++j){
            if (0 != j){
                ossResult << ", ";
            }
            if (MAX_UINT32 != matrixMultiplyTimes[i][j]){
                ossResult << setw(4) << matrixMultiplyTimes[i][j];
            } else {
                ossResult << setw(4) << '-';
            }
        }
        ossResult << "]\n";
    }
    ossResult << "}\n";

    ossResult << "bracket position result:\n";
    ossResult << "{\n";
    for (size_t i = 0; i < matrixBracketPosition.size(); ++i){
        ossResult << "\t[";
        for (size_t j = 0; j < matrixBracketPosition[i].size(); ++j){
            if (0 != j){
                ossResult << ", ";
            }
            if (MAX_UINT32 != matrixBracketPosition[i][j]){
                ossResult << setw(4) << matrixBracketPosition[i][j];
            } else {
                ossResult << setw(4) << '-';
            }
        }
        ossResult << "]\n";
    }
    ossResult << "}\n";

    ossResult << "Bracket form:\n";
    ossResult << dp_bottom_up_method_show_bracket_form_recursive(matrixBracketPosition, 0, m_vecMatrices.size() - 1);

    return ossResult.str();
}

string Matrix_Chain_Multiplication_Problem_Solution::dp_bottom_up_method_show_bracket_form_recursive(const vector<vector<uint32_t>> &matrixBracketPosition, size_t nStartIndex, size_t nEndIndex) const
{
    ostringstream ossResult;

    if (nStartIndex == nEndIndex){
        ossResult << "[";
        ossResult << m_vecMatrices[nStartIndex].first;
        ossResult << ", ";
        ossResult << m_vecMatrices[nStartIndex].second;
        ossResult << "]";
    } else {
        ossResult << "(";
        size_t nBracketPosition = matrixBracketPosition[nStartIndex][nEndIndex];
        ossResult << dp_bottom_up_method_show_bracket_form_recursive(matrixBracketPosition, nStartIndex, nBracketPosition);
        ossResult << " x ";
        ossResult << dp_bottom_up_method_show_bracket_form_recursive(matrixBracketPosition, nBracketPosition + 1, nEndIndex);
        ossResult << ")";
    }

    return ossResult.str();
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
    print_normal_msg("matrices: " + oMatrixChainMultiplicationProblemSolution.show_matrices() + "\n");

    /*< test dp_bottom_up_method */
    oMatrixChainMultiplicationProblemSolution.dp_bottom_up_method(matrixMultiplyTimes, matrixBracketPosition);
    if ((matrixMultiplyTimes.size() >= vecMatrices.size()) &&
        (matrixMultiplyTimes[vecMatrices.size() - 1].size() >= vecMatrices.size()) &&
        (matrixMultiplyTimes[0][vecMatrices.size() - 1] == 158)){
        print_correct_msg("dp_bottom_up_method OK.\n");
    } else {
        print_error_msg("dp_bottom_up_method Error.\n");
    }
    print_warning_msg("dp_bottom_up_method result:\n");
    print_warning_msg(oMatrixChainMultiplicationProblemSolution.dp_bottom_up_method_show_result(matrixMultiplyTimes,
                                                                                                matrixBracketPosition) + "\n");

    /*< test l-optimal partition of convex polygon method */
    print_normal_msg("l-optimal partition of convex polygon method:\n");
    print_normal_msg("algorithm P:\n");
    PRINT_DEFAULT_ERROR
    print_normal_msg("algorithm M:\n");
    PRINT_DEFAULT_ERROR
}

