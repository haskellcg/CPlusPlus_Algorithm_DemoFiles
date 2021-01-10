/**************************************************************************
 * author: haskellcg
 * date: 2021-01-08
 * description: solution for egg dropping puzzle
 *************************************************************************/

#ifndef __EGG_DROPPING_PUZZLE_H__
#define __EGG_DROPPING_PUZZLE_H__

#include "common_types.h"

/**
 * @brief egg dropping puzzle solution
 * @param uint32_t nEggNumber, number of eggs
 * @param uint32_t nFloorNumber, number of floors
 * @param vector<vector<uint32_t>> &matrixSolution, solution: table as following
 *                  floor_0 floor_1 floor_2 ... floor_m
 *          egg_0
 *          egg_1
 *          egg_2
 *          ...
 *          egg_n
 * @return void
 * @remarks
 *          solutions for 2 eggs, 36 floors:
 *          egg_1 drop floor: 8  15  21  26  30  33
 *          egg_2 drop floor: 27 28 29 if egg_1 drop 30 broken
 */
void egg_dropping_puzzle_solution(uint32_t nEggNumber, uint32_t nFloorNumber, vector<vector<uint32_t>> &matrixSolution);

/**
 * @brief get problem size can be tested given egg number and test times
 * @param uint32_t nEggNumber, number of eggs
 * @param uint32_t nTestTimes, number of test can be done
 * @param vector<vector<uint32_t>> &matrixProblemSize, 
 * @return void
 * @remarks
 */
void egg_dropping_puzzle_problem_size(uint32_t nEggNumber, uint32_t nTestTimes, vector<vector<uint32_t>> &matrixProblemSize);

/**
 * @brief get minmum test time given eggs number and floors number
 * @param uint32_t nEggNumber, number of eggs
 * @param uint32_t nFloorNumber, number of floors
 * @return uint32_t, minmum test to do
 * @remarks
 */
uint32_t egg_dropping_puzzle_test_time(uint32_t nEggNumber, uint32_t nFloorNumber);

/**
 * @brief test egg dropping puzzle solution
 * @param
 * @return void
 * @remarks
 */
void egg_dropping_puzzle_solution_test();

#endif // __EGG_DROPPING_PUZZLE_H__
