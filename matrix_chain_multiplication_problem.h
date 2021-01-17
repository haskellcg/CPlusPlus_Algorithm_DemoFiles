/**************************************************************************
 * author: haskellcg
 * date: 2021-01-14
 * description: matrix chain multiplication problem solution
 *************************************************************************/

#ifndef __MATRIX_CHAIN_MULTIPLICATION_PROBLEM_H__
#define __MATRIX_CHAIN_MULTIPLICATION_PROBLEM_H__

#include "common_types.h"

/**
 * @brief topics about matrix chain multiplication
 *          words:
 *                  vertex      => vertices
 *                  matrix      => matrices
 *                  hexagon     => https://en.wikipedia.org/wiki/Hexagon
 *
 *          matrix chain multiplication wiki:                 https://en.wikipedia.org/wiki/Matrix_chain_multiplication
 *          matrix chain multiplication youtube introduction: https://www.youtube.com/watch?v=prx1psByp7U
 *
 *          catalan number:       https://mathworld.wolfram.com/CatalanNumber.html
 *          catalan number:       https://en.wikipedia.org/wiki/Catalan_number
 *
 *          Chin-Hu-Shing Approximating Algorithm:
 *                                https://pdfs.semanticscholar.org/e8b8/40a921f7967b30ac161b3dd9654b27998ddb.pdf
 *          Hu & Shing:           http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/0211028.pdf
 *                                http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/0213017.pdf
 */
class Matrix_Chain_Multiplication_Problem_Solution
{
public:
    /**
     * @brief default constructor
     */
    Matrix_Chain_Multiplication_Problem_Solution();

    /**
     * @brief set matrices for the problem
     * @param vector<pair<uint32_t, uint32_t>> &vecMatrices, matrices
     * @return void
     * @remarks
     */
    void set_matrices(vector<pair<uint32_t, uint32_t>> &vecMatrices);

    /**
     * @brief show matrices
     * @param
     * @return string
     * @remarks
     */
    string show_matrices() const;

    /**
     * @brief solve problem with dynamic programming bottom up method
     * @param vector<vector<uint32_t>> &matrixMultiplyTimes, multiply times result
     * @param vector<vector<uint32_t>> &matrixBracketPosition, multiply best bracket position
     * @return void
     * @remarks
     */
    void dp_bottom_up_method(vector<vector<uint32_t>> &matrixMultiplyTimes, vector<vector<uint32_t>> &matrixBracketPosition);

    /**
     * @brief show dp_bottom_up_method result
     * @param const vector<vector<uint32_t>> &matrixMultiplyTimes, multiply times result
     * @param const vector<vector<uint32_t>> &matrixBracketPosition, multiply best bracket position
     * @return string, result string
     * @remarks
     */
    string dp_bottom_up_method_show_result(const vector<vector<uint32_t>> &matrixMultiplyTimes,
                                           const vector<vector<uint32_t>> &matrixBracketPosition) const;

private:
    /**
     * @brief show bracket form recursive
     * @param const vector<vector<uint32_t>> &matrixBracketPosition, bracket position result
     * @param size_t nStartIndex, start index for sub problem
     * @param size_t nEndIndex, end index for sub problem
     * @return string, bracket form string
     * @remarks
     */
    string dp_bottom_up_method_show_bracket_form_recursive(const vector<vector<uint32_t>> &matrixBracketPosition, size_t nStartIndex, size_t nEndIndex) const;

private:
    /*< matrices with <rows, columns> */
    vector<pair<uint32_t, uint32_t>> m_vecMatrices;
};

/**
 * @brief test matrix chain multiplication problem solution
 * @param
 * @return void
 * @remarks
 */
void matrix_chain_multiplication_problem_solution_test();

#endif // __MATRIX_CHAIN_MULTIPLICATION_PROBLEM_H__
