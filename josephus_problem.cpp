/**************************************************************************
 * author: haskellcg
 * date: 2021-01-02
 * description: josephus problem solution
 *************************************************************************/

#include "common_types.h"
#include "josephus_problem.h"

uint32_t josephus_problem(uint32_t nN, uint32_t nK)
{
    if (1 == nN){
        return 1;
    } else {
        return ((josephus_problem(nN - 1, nK) + nK - 1) % nN + 1);
    }
}

uint32_t josephus_problem_with_K_is_2(uint32_t nN)
{
    uint32_t nP = 1;
    while (nP <= nN){
        nP <<= 1;
    }

    return ((nN << 1) - nP + 1);
}

void josephus_problem_permutation(uint32_t nN, uint32_t nK, vector<uint32_t> &vecPermutation)
{
    bool *pPersonLiveFlags = new bool[nN];
    for (uint32_t i = 0; i < nN; ++i){
        pPersonLiveFlags[i] = true;
    }

    uint32_t nPersonLiveNum = nN;
    uint32_t nIndex = 0;
    uint32_t nCount = 0;
    while (nPersonLiveNum > 0){
        if (pPersonLiveFlags[nIndex]){
            ++nCount;
            if (nK == nCount){
                nCount = 0;
                pPersonLiveFlags[nIndex] = false;
                vecPermutation.push_back(nIndex + 1);
                --nPersonLiveNum;
            }
        }
        nIndex = (nIndex + 1) % nN;
    }

    delete []pPersonLiveFlags;
}

void josephus_problem_test()
{
    print_highlight_msg(">>> Test josephus problem:\n");

    if (13 != josephus_problem(14, 2)){
        print_error_msg("N = 14, K = 2, result is not 13.\n");
    } else {
        print_correct_msg("N = 14, K = 2, result is 13.\n");
    }

    if (13 != josephus_problem_with_K_is_2(14)){
        print_error_msg("N = 14, K = 2(default), result is not 13.\n");
    } else {
        print_correct_msg("N = 14, K = 2(default), result is 13.\n");
    }

    uint32_t arrayExpectPermutation[] = {
         2,  4,  6,  8,
        10, 12, 14,  3,
         7, 11,  1,  9,
         5, 13
    };
    vector<uint32_t> vecExpectPermutation;
    vecExpectPermutation.insert(vecExpectPermutation.end(), begin(arrayExpectPermutation), end(arrayExpectPermutation));

    vector<uint32_t> vecActualPermutation;
    josephus_problem_permutation(14, 2, vecActualPermutation);
    if (vecExpectPermutation != vecActualPermutation){
        print_error_msg("N = 14, K = 2, permutation error.\n");
    } else {
        print_correct_msg("N = 14, K = 2, permutation correct.\n");
    }
}
