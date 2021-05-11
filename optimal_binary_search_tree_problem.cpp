/**************************************************************************
 * author: haskellcg
 * date: 2021-03-02
 * description: optimal binary search tree problem solution
 *************************************************************************/

#include "optimal_binary_search_tree_problem.h"

void optimal_binay_search_tree_problem_solution(const vector<double> &vecQ, const vector<double> &vecP, vector<vector<double>> &matrixE, vector<vector<double>> &matrixW, vector<vector<uint32_t>> &matrixRoot)
{
    size_t nKeyNumber = vecP.size();
    for (size_t i = 0; i < nKeyNumber + 1; ++i){
        vector<double> vecDoubleRow;
        vector<uint32_t> vecIntRow;
        for (size_t j = 0; j < nKeyNumber + 1; ++j){
            vecDoubleRow.push_back(0);
            vecIntRow.push_back(0);
        }
        matrixE.push_back(vecDoubleRow);
        matrixW.push_back(vecDoubleRow);
        matrixRoot.push_back(vecIntRow);
    }

    for (size_t i = 0; i <nKeyNumber + 1; ++i){
        matrixE[][] = 
    }
}

void optimal_binary_search_tree_problem_solution_test()
{
    print_highlight_msg(">>> Test optimal binary search tree problem solution:\n");
    PRINT_DEFAULT_ERROR

    double arrayP[] = {0.15, 0.10, 0.05, 0.10, 0.20};
    vector<double> vecP;
    vecP.insert(vecP.end(), begin(arrayP), end(arrayP));
    print_normal_msg("p:" + to_string(vecP) + "\n");

    double arrayQ[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
    vector<double> vecQ;
    vecQ.insert(vecQ.end(), begin(arrayQ), end(arrayQ));
    print_normal_msg("q:" + to_string(vecQ) + "\n");

    vector<vector<double>> matrixE;
    vector<vector<double>> matrixW;
    vector<vector<uint32_t>> matrixRoot;
    optimal_binay_search_tree_problem_solution(vecQ, vecP, matrixE, matrixW, matrixRoot);

    print_highlight_msg("matrix E:\n");
    print_highlight_msg(to_string(matrixE) + "\n");

    print_highlight_msg("matrix W:\n");
    print_highlight_msg(to_string(matrixW) + "\n");

    print_highlight_msg("matrix root:\n");
    print_highlight_msg(to_string(matrixRoot) + "\n");
}
