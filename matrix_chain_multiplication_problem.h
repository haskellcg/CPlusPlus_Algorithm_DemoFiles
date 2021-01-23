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
 *
 *
 *          Hu & Shing:           http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/0211028.pdf
 *                                http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/0213017.pdf
 *
 *                                The diagonals are the partial products. A partition of an n-gon corresponds to an alphabetic 
 *                            tree of n-1 leaves or the parenthesis problem of n- 1 symbols (see, for example, Gardner [6]). It 
 *                            is easy to see the one-to-one correspondence between the multiplication of n- 1 matrices to either
 *                            the alphabetic binary tree or the parenthesis problem of n- 1 symbols. Here, we establish the 
 *                            correspondence between the matrix-chain product and the partition of a convex polygon directly.
 *
 *                                LEMMA 1. Any order of multiplying n- 1 matrices corresponds to a partition of an n-gon.
 *
 *                                LEMMA 2. The minimum numbers of operations needed to evaluate the following matrix chain products are identical.
 *
 *                                The diagonals inside the polygon are called arcs.
 *                                In a partition of an n-gon, the degree of a vertex is the number of arcs incident on the vertex plus two.
 *
 *                                LEMMA 3. In any partition of an n-gon, n not less than 4, there are at least two triangles, each having a vertex
 *                                         of degree two.
 *
 *                                LEMMA 4. Let P and P’ both be n-gons where the corresponding weights of the vertices satisfy wi not less than wI. Then the 
 *                                         cost of an optimum partition of P is less than or equal to the cost of an optimum partition of P’.
 *
 *                                In the rest of the paper, we shall use V, V2," ", V, to denote vertices which are ordered according to their weights
 *                                After the vertices are labeled, we define an arc V-V. to be less than another arc V- Vq
 *
 *                                We define a partition P to be lexicographically less than a partition Q if the ordered sequence of arcs associated with
 *                                P is lexicographically less than that associated with Q.
 *
 *                                When there is more than one optimum partition, we use the l-optimum partition (i.e., lexicographically-optimum partition)
 *                                to mean the lexicographically smallest optimum partition
 *
 *                                THEOREM 1. For every way of choosing V1, V2, (as prescribed), there is always an optimum partition containing V1- V2 and VI- V3.
 *
 *                                COROLLARY 1. For every way of choosing Vx, V,... (as prescribed), the l-optimum partition always contains Va- Vz and V- V3.
 *
 *                                A polygon having .Va adjacent to Vz and V3 by sides will be called a basic polygon.
 *
 *                                THEOREM 2. A necessary but not sufficient condition for Vz-V3 to exist in an optimum partition of a basic polygon **FORMULA**
 *                                           Furthermore, if V2- V3 is not present in the l-optimum partition, then V1, V4 are always connected in the l-optimum partition.
 *
 *                                LEMMA 5. In an optimum partition of an n-gon, let Vx, Vy, Vz and Vw be four vertices of an inscribed quadrilateral V and Vz are
 *                                         not adjacent in the quadrilateral). A necessary condition for Vx-V to exist is **FORMULA**
 *
 *                                A partition is called stable if every quadrilateral in the partition satisfies Lemma5 FOPMULA
 *
 *                                COROLLARY 2. An optimum partition is stable but a stable partition may not be optimum.
 *
 *                                We define Vx - Vz to be a vertical arc if
 *                                          min (Wx, Wz) < min (Wy, Ww);
 *                                          min (Wx, Wz) = min (Wy, Ww), max (Wx, Wz) <= max (Wy, Ww);
 *                                We define Vx- Vz to be a horizontal arc if
 *                                          min (Wx, Wz) > min (Wy, Ww), max (Wx, Wz) < max (Wy, Ww).
 *
 *                                COROLLARY 3. All arcs in an optimum partition must be either vertical arcs or horizontal arcs.
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
