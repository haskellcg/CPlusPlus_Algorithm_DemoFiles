/**************************************************************************
 * author: haskellcg
 * date: 2021-01-06
 * description: tower of hanoi problem solution
 *************************************************************************/

#ifndef __TOWER_OF_HANOI_PROBLEM_H__
#define __TOWER_OF_HANOI_PROBLEM_H__

#include "common_types.h"

/**
 * @brief move nPalletNumber of pallets from strA to strB according to game rule, strB for use
 * @param uint32_t nPalletNumber, number of pallets
 * @param const string &strA, A
 * @param const string &strB, B
 * @param const string &strC, C
 * @param vector<pair<uint32_t, string>> &vecSolution, vector of pair<pallet ID, move string>
 * @return void
 * @remarks
 */
void tower_of_hanoi_problem_solution_recursive(uint32_t nPalletNumber, const string &strA, const string &strB, const string &strC, vector<pair<uint32_t, string>> &vecSolution);

/**
 * @brief solution for tower of hanoi
 * @param uint32_t nPalletNumber, number of pallets
 * @return vector<pair<uint32_t, string>>, vector of pair<pallet ID, move string>
 * @remarks
 *          reference: https://blog.csdn.net/qq_37873310/article/details/80461767
 *          reference: https://blog.csdn.net/liujian20150808/article/details/50793101
 */
vector<pair<uint32_t, string>> tower_of_hanoi_problem_solution(uint32_t nPalletNumber);

/**
 * @brief test tower of hanoi problem solution
 * @param
 * @return
 * @remarks
 */
void tower_of_hanoi_problem_solution_test();

#endif // __TOWER_OF_HANOI_PROBLEM_H__
