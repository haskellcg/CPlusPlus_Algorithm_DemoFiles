/**************************************************************************
 * author: haskellcg
 * date: 2021-01-06
 * description: generat permutation
 *************************************************************************/

#ifndef __PERMUTATION_GENERATOR_H__
#define __PERMUTATION_GENERATOR_H__

#include "common_types.h"

/**
 * @brief generate permution according to strSrc
 * @param string &strSrc, string to permutation
 * @param size_t nStartIndex, the index start to do permutation
 * @param vector<string> &vecPermutations, result permutations
 * @return void
 * @remarks
 *          reference: https://www.geeksforgeeks.org/generate-all-the-permutation-of-a-list-in-python/
 *          reference: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
 */
void string_permutation_generator(string &strSrc, size_t nStartIndex, vector<string> &vecPermutations);

/**
 * @brief test permutation generator
 * @param
 * @return void
 * @remarks
 */
void permutation_generator_test();

#endif // __PERMUTATION_GENERATOR_H__
