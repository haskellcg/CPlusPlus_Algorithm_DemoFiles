/**************************************************************************
 * author: haskellcg
 * date: 2021-01-02
 * description: josephus problem solution
 *************************************************************************/

#ifndef __JOSEPHUS_PROBLEM_H__
#define __JOSEPHUS_PROBLEM_H__

/**
 * @brief josephus problem solution
 * @param uint32_t nN, number of person
 * @param uint32_t nK, count to kill
 * @return uint32_t, index of the last stand person
 * @remarks
 *          Wolfram MathWorld - Josephus Problem: https://mathworld.wolfram.com/JosephusProblem.html
 *          Formulae - Josephus Problem:          https://wiki.formulae.org/Josephus_problem
 *          Wiki - Josephus Problem:              https://en.wikipedia.org/wiki/Josephus_problem
 *          Online Solution:                      http://webspace.ship.edu/deensley/mathdl/Joseph.html
 *          Explain:                              https://medium.com/@rrfd/explaining-the-josephus-algorithm-11d0c02e7212
 *          Solution:                             https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
 *          Solution when K is 2:                 https://www.geeksforgeeks.org/josephus-problem-set-2-simple-solution-k-2/
 */
uint32_t josephus_problem(uint32_t nN, uint32_t nK);

/**
 * @brief josephus problem solution
 * @param uint32_t nN, number of person
 * @return uint32_t, index of the last stand person
 * @remarks
 *          Solution when K is 2:                 https://www.geeksforgeeks.org/josephus-problem-set-2-simple-solution-k-2/
 */
uint32_t josephus_problem_with_K_is_2(uint32_t nN);

/**
 * @brief josephus problem solution
 * @param uint32_t nN, number of person
 * @param uint32_t nK, count to kill
 * @param vector<uint32_t> &vecPermutation, josephus problem permutation
 * @return void
 * @remarks
 */
void josephus_problem_permutation(uint32_t nN, uint32_t nK, vector<uint32_t> &vecPermutation);

/**
 * @brief test josephus problem solution
 * @param
 * @return void
 * @remarks
 */
void josephus_problem_test();

#endif // __JOSEPHUS_PROBLEM_H__
