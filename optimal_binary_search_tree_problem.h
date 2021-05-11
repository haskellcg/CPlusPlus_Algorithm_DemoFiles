/**************************************************************************
 * author: haskellcg
 * date: 2021-03-02
 * description: optimal binary search tree problem solution
 *************************************************************************/

#ifndef __OPTIMAL_BINARY_SEARCH_TREE_PROBLEM_H__
#define __OPTIMAL_BINARY_SEARCH_TREE_PROBLEM_H__

#include "common_types.h"

/**
 * @brief optimal binary search tree problem solution
 * @param const vector<double> %vecQ, ratio of Ks, N
 * @param const vector<double> %vecP, ratio of Ds, N + 1
 * @param vector<vector<double>> &matrixE, matrix of E(N + 1, N)
 * @param vector<vector<double>> &matrixW, matrix of W(N, N)
 * @param vector<vector<uint32_t>> &matrixRoot, matrix of root index
 * @return void
 * @remarks
 *
 *        sorted key array K [K1, K2, ..., Kn], K1 < K2 < ... < Kn, so pick one of them as root is automaticlly a BST
 *        sorted leaf array D [D0, D1, D2, ..., Dn], D0 < D1 < D2 < ... < Dn, so D0 < K1, Ki < Di, so they can be automatically a leaf node
 *
 *        subproblem formular:
 *          E[i, j] = Pr + (E[i, r-1] + W[i, r-1]) + (E[r+1, j] + W[r+1, j])
 *          since:
 *          W(i, r-1) + Pr + W(r+1, j) = W(i, j)
 *          =>
 *          E[i, j] = E(i, r-1) + E(r+1, j) + W(i, j)
 *          W(i, j) = W(i, j-1) + Pj + Qj
 */
void optimal_binay_search_tree_problem_solution(const vector<double> &vecQ, const vector<double> &vecP, vector<vector<double>> &matrixE, vector<vector<double>> &matrixW, vector<vector<uint32_t>> &matrixRoot);

/**
 * @brief test optimal binary search problem solution
 * @param
 * @return void
 * @remarks
 */
void optimal_binary_search_tree_problem_solution_test();

#endif // __OPTIMAL_BINARY_SEARCH_TREE_PROBLEM_H__
