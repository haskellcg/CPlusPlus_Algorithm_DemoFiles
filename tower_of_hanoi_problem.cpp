/**************************************************************************
 * author: haskellcg
 * date: 2021-01-06
 * description: tower of hanoi problem solution
 *************************************************************************/

#include "tower_of_hanoi_problem.h"

void tower_of_hanoi_problem_solution_recursive(uint32_t nPalletNumber, const string &strA, const string &strB, const string &strC, vector<pair<uint32_t, string>> &vecSolution)
{
    if (0 != nPalletNumber){
        tower_of_hanoi_problem_solution_recursive(nPalletNumber - 1, strA, strC, strB, vecSolution);
        vecSolution.push_back(make_pair(nPalletNumber, strA + "->" + strC));
        tower_of_hanoi_problem_solution_recursive(nPalletNumber - 1, strB, strA, strC, vecSolution);
    }
}

vector<pair<uint32_t, string>> tower_of_hanoi_problem_solution(uint32_t nPalletNumber)
{
    vector<pair<uint32_t, string>> vecSolution;
    tower_of_hanoi_problem_solution_recursive(nPalletNumber, "A", "B", "C", vecSolution);
    return vecSolution;
}

void tower_of_hanoi_problem_solution_test()
{
    print_highlight_msg(">>> Test tower of hanoi problem solution:\n");
    vector<pair<uint32_t, string>> vecSolution = tower_of_hanoi_problem_solution(3);
    for (size_t i = 0; i < vecSolution.size(); ++i){
        print_normal_msg("step " + std::to_string(i) + ": pallet[" + 
                         std::to_string(vecSolution[i].first) + "] do " +
                         vecSolution[i].second + "\n");
    }
}
