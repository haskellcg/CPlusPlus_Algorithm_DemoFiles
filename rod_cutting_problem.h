/**************************************************************************
 * author: haskellcg
 * date: 2021-01-10
 * description: rod cutting problem solution
 *************************************************************************/

#ifndef __ROD_CUTTING_PROBLEM_H__
#define __ROD_CUTTING_PROBLEM_H__

#include <map>
#include "common_types.h"

/**
 * @brief solution for rod cutting problem
 */
class Rod_Cutting_Problem_Solution
{
public:
    /**
     * @brief default constructor
     */
    Rod_Cutting_Problem_Solution();

    /**
     * @brief print cut solution given certain length of rod
     * @param
     * @return string
     * @remarks
     */
    string show_solution() const;

    /**
     * @brief set price table for current solution
     * @param const map<uint32_t, uint32_t> &mapPriceTable, price table
     * @return void
     * @remarks
     */
    void set_price_table(const map<uint32_t, uint32_t> &mapPriceTable);

    /**
     * @brief find solution with top-down memoization method
     * @param uint32_t nLength, length of the rod
     * @return void
     * @remarks
     */
    void top_down_memoization_method(uint32_t nLength);

    /**
     * @brief find solution with down-up method
     * @param uint32_t nLength, length of the rod
     * @return void
     * @remarks
     */
    void bottom_up_method(uint32_t nLength);

private:
    /**
     * @brief calculate max profit for nLength rod cutting problem
     * @param uint32_t nLength, length
     * @return void
     * @remarks
     */
    void top_down_memoization_method_recursive(uint32_t nLength);

    /**
     * @brief get price according to the length
     * @param uint32_t nLength, length
     * @return uint32_t, price, 0 if price not in the table
     * @remarks
     */
    uint32_t get_price(uint32_t nLength) const;

private:
    /*< rod price table, <rod length, price> */
    map<uint32_t, uint32_t> m_mapPriceTable;
    /*< optimal solution for certain length */
    vector<uint32_t> m_vecCutSolution;
    /*< top-down memoization result table */
    vector<uint32_t> m_vecTopDownTable;
    /*< bottom-up result table */
    vector<uint32_t> m_vecBottomUpTable;
};

/**
 * @brief test rod cutting problem solution 
 * @param
 * @return void
 * @remarks
 */
void rod_cutting_problem_solution_test();

#endif // __ROD_CUTTING_PROBLEM_H__
