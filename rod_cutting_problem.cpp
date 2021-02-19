/**************************************************************************
 * author: haskellcg
 * date: 2021-01-10
 * description: rod cutting problem solution
 *************************************************************************/

#include "rod_cutting_problem.h"

Rod_Cutting_Problem_Solution::Rod_Cutting_Problem_Solution()
{
}

string Rod_Cutting_Problem_Solution::show_solution() const
{
    return to_string(m_vecCutSolution);
}

void Rod_Cutting_Problem_Solution::set_price_table(const map<uint32_t, uint32_t> &mapPriceTable)
{
    m_mapPriceTable = mapPriceTable;
}

void Rod_Cutting_Problem_Solution::top_down_memoization_method(uint32_t nLength)
{
    m_vecTopDownTable.clear();
    m_vecCutSolution.clear();

    for (uint32_t i = 0; i < nLength + 1; ++i){
        m_vecTopDownTable.push_back(0);
        m_vecCutSolution.push_back(0);
    }

    top_down_memoization_method_recursive(nLength);
    print_warning_msg(to_string(m_vecTopDownTable) + "\n");
}

void Rod_Cutting_Problem_Solution::bottom_up_method(uint32_t nLength)
{
    m_vecBottomUpTable.clear();
    m_vecCutSolution.clear();

    for (uint32_t i = 0; i < nLength + 1; ++i){
        m_vecBottomUpTable.push_back(0);
        m_vecCutSolution.push_back(0);
    }

    for (uint32_t i = 1; i < (nLength + 1); ++i){
        uint32_t nMaxProfit = 0;
        for (uint32_t nCutPosition = 1; nCutPosition <= i; ++nCutPosition){
            uint32_t nCurrentProfit = 0;

            uint32_t nLeftPartLength = nCutPosition;
            if (0 != m_vecBottomUpTable[nLeftPartLength]){
                nCurrentProfit += m_vecBottomUpTable[nLeftPartLength];
            } else {
                nCurrentProfit += get_price(nLeftPartLength);
            }

            uint32_t nRightPartLength = i - nCutPosition;
            if (0 != m_vecBottomUpTable[nRightPartLength]){
                nCurrentProfit += m_vecBottomUpTable[nRightPartLength];
            } else {
                nCurrentProfit += get_price(nRightPartLength);
            }

            if (nCurrentProfit > nMaxProfit){
                nMaxProfit = nCurrentProfit;
                m_vecCutSolution[i] = nCutPosition;
            }
        }

        m_vecBottomUpTable[i] = nMaxProfit;
    }

    print_warning_msg(to_string(m_vecBottomUpTable) + "\n");
}

void Rod_Cutting_Problem_Solution::top_down_memoization_method_recursive(uint32_t nLength)
{
    uint32_t nMaxProfit = 0;
    for (uint32_t nCutPosition = 1; nCutPosition <= nLength; ++nCutPosition){
        uint32_t nCurrentProfit = 0;

        uint32_t nLeftPartLength = nCutPosition;
        if ((0 == m_vecTopDownTable[nLeftPartLength]) &&
            (nLeftPartLength != nLength)){
            top_down_memoization_method_recursive(nLeftPartLength);
        }
        uint32_t nLeftPartLengthPrice = get_price(nLeftPartLength);
        if (m_vecTopDownTable[nLeftPartLength] > nLeftPartLengthPrice){
            nCurrentProfit += m_vecTopDownTable[nLeftPartLength];
        } else {
            nCurrentProfit += nLeftPartLengthPrice;
        }

        uint32_t nRightPartLength = nLength - nCutPosition;
        if ((0 == m_vecTopDownTable[nRightPartLength]) &&
            (nRightPartLength != nLength)){
            top_down_memoization_method_recursive(nRightPartLength);
        }
        uint32_t nRightPartLengthPrice = get_price(nRightPartLength);
        if (m_vecTopDownTable[nRightPartLength] > nRightPartLengthPrice){
            nCurrentProfit += m_vecTopDownTable[nRightPartLength];
        } else {
            nCurrentProfit += nRightPartLengthPrice;
        }

        if (nCurrentProfit > nMaxProfit){
            nMaxProfit = nCurrentProfit;
            m_vecCutSolution[nLength] = nCutPosition;
        }
    }

    m_vecTopDownTable[nLength] = nMaxProfit;
}

uint32_t Rod_Cutting_Problem_Solution::get_price(uint32_t nLength) const
{
    map<uint32_t, uint32_t>::const_iterator itrmapPriceTable = m_mapPriceTable.find(nLength);
    if (m_mapPriceTable.end() != itrmapPriceTable){
        return itrmapPriceTable->second;
    } else {
        return 0;
    }
}

void rod_cutting_problem_solution_test()
{
    print_highlight_msg(">>> Test rod cutting problem solution:\n");
    map<uint32_t, uint32_t> mapPriceTable;
    mapPriceTable.insert(make_pair(1, 1));
    mapPriceTable.insert(make_pair(2, 5));
    mapPriceTable.insert(make_pair(3, 8));
    mapPriceTable.insert(make_pair(4, 9));
    mapPriceTable.insert(make_pair(5, 10));
    mapPriceTable.insert(make_pair(6, 17));
    mapPriceTable.insert(make_pair(7, 17));
    mapPriceTable.insert(make_pair(8, 20));
    mapPriceTable.insert(make_pair(9, 24));
    mapPriceTable.insert(make_pair(10, 30));

    Rod_Cutting_Problem_Solution oRodCuttingProblemSolution;
    oRodCuttingProblemSolution.set_price_table(mapPriceTable);

    print_normal_msg("top down memoization method result:\n");
    oRodCuttingProblemSolution.top_down_memoization_method(30);
    print_normal_msg(oRodCuttingProblemSolution.show_solution() + "\n");

    print_normal_msg("bottom up method result:\n");
    oRodCuttingProblemSolution.bottom_up_method(30);
    print_normal_msg(oRodCuttingProblemSolution.show_solution() + "\n");
}
