/**************************************************************************
 * author: haskellcg
 * date: 2021-01-08
 * description: solution for egg dropping puzzle
 *************************************************************************/

#include "egg_dropping_puzzle.h"

void egg_dropping_puzzle_solution(uint32_t nEggNumber, uint32_t nFloorNumber, vector<vector<uint32_t>> &matrixSolution)
{
    for (uint32_t i = 0; i < nEggNumber + 1; ++i){
        vector<uint32_t> vecSpecificEggFloors;
        for (uint32_t j = 0; j < nFloorNumber + 1; ++j){
            vecSpecificEggFloors.push_back(0);
        }
        matrixSolution.push_back(vecSpecificEggFloors);
    }

    for (uint32_t nFloorIndex = 0; nFloorIndex < nFloorNumber + 1; ++nFloorIndex){
        matrixSolution[0][nFloorIndex] = 0;
        if (nEggNumber > 0){
            matrixSolution[1][nFloorIndex] = nFloorIndex;
        }
    }

    for (uint32_t nEggIndex = 2; nEggIndex < nEggNumber + 1; ++nEggIndex){
        matrixSolution[nEggIndex][0] = 0;
        if (nFloorNumber > 0){
            matrixSolution[nEggIndex][1] = 1;
        }
    }

    for (uint32_t nEggIndex = 2; nEggIndex < nEggNumber + 1; ++nEggIndex){
        for (uint32_t nFloorIndex = 2; nFloorIndex < nFloorNumber + 1; ++nFloorIndex){

            uint32_t nMinTestTimes = MAX_INT32;
            for (uint32_t nKillFloorIndex = 1; nKillFloorIndex < nFloorIndex; ++nKillFloorIndex){
                uint32_t nLowLevelTestTimes = matrixSolution[nEggIndex - 1][nKillFloorIndex - 1];
                uint32_t nHighLevelTestTimes = matrixSolution[nEggIndex][nFloorIndex - nKillFloorIndex];
                uint32_t nLevelTestTimes = ((nLowLevelTestTimes > nHighLevelTestTimes) ? nLowLevelTestTimes : nHighLevelTestTimes);
                if (nLevelTestTimes < nMinTestTimes){
                    nMinTestTimes = nLevelTestTimes;
                }
            }

            matrixSolution[nEggIndex][nFloorIndex] = nMinTestTimes + 1;
        }
    }
}

void egg_dropping_puzzle_problem_size(uint32_t nEggNumber, uint32_t nTestTimes, vector<vector<uint32_t>> &matrixProblemSize)
{
    for (uint32_t i = 0; i < nEggNumber + 1; ++i){
        vector<uint32_t> vecSpecificEggTest;
        for (uint32_t j = 0; j < nTestTimes + 1; ++j){
            vecSpecificEggTest.push_back(0);
        }
        matrixProblemSize.push_back(vecSpecificEggTest);
    }

    for (uint32_t nTestIndex = 0; nTestIndex < nTestTimes + 1; ++nTestIndex){
        matrixProblemSize[0][nTestIndex] = 0;
        if (nEggNumber > 0){
            matrixProblemSize[1][nTestIndex] = nTestIndex;
        }
    }

    for (uint32_t nEggIndex = 2; nEggIndex < nEggNumber + 1; ++nEggIndex){
        matrixProblemSize[nEggIndex][0] = 0;
        if (nTestTimes > 0){
            matrixProblemSize[nEggIndex][1] = 1;
        }
    }

    for (uint32_t nEggIndex = 2; nEggIndex < nEggNumber + 1; ++nEggIndex){
        for (uint32_t nTestIndex = 2; nTestIndex < nTestTimes + 1; ++nTestIndex){
            if (nEggIndex >= nTestIndex){
                matrixProblemSize[nEggIndex][nTestIndex] = ((1 << nTestIndex) - 1);
            }
        }
    }

    for (uint32_t nEggIndex = 2; nEggIndex < nEggNumber + 1; ++nEggIndex){
        for (uint32_t nTestIndex = 2; nTestIndex < nTestTimes + 1; ++nTestIndex){
            matrixProblemSize[nEggIndex][nTestIndex] = matrixProblemSize[nEggIndex][nTestIndex - 1] +
                                                       matrixProblemSize[nEggIndex - 1][nTestIndex - 1] +
                                                       1;
        }
    }
}

uint32_t egg_dropping_puzzle_test_time(uint32_t nEggNumber, uint32_t nFloorNumber)
{
    uint32_t nTestTimes = 0;
    while (true){
        vector<vector<uint32_t>> matrixProblemSize;
        egg_dropping_puzzle_problem_size(nEggNumber, nTestTimes, matrixProblemSize);
        if (matrixProblemSize[nEggNumber][nTestTimes] >= nFloorNumber){
            break;
        } else {
            ++nTestTimes;
        }
    }
    return nTestTimes;
}

void egg_dropping_puzzle_solution_test()
{
    print_highlight_msg(">>> Test egg dropping puzzle solution:\n");

    vector<vector<uint32_t>> matrixSolution;
    egg_dropping_puzzle_solution(3, 36, matrixSolution);
    print_normal_msg("solution:\n");
    print_normal_msg(to_string(matrixSolution) + "\n");

    vector<vector<uint32_t>> matrixProblemSize;
    egg_dropping_puzzle_problem_size(3, 10, matrixProblemSize);
    print_normal_msg("problem size:\n");
    print_normal_msg(to_string(matrixProblemSize) + "\n");

    print_normal_msg("2 eggs, 36 floors, minmum test time is: " + to_string(egg_dropping_puzzle_test_time(2, 36)) + "\n");
}
