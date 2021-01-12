/**************************************************************************
 * author: haskellcg
 * date: 2021-01-10
 * description: rod cutting problem solution
 *************************************************************************/

#include "rod_cutting_problem.h"

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

    oRodCuttingProblemSolution.top_down_memoization_method(30);
    print_normal_msg("top down memoization method result:\n");
    print_normal_msg(oRodCuttingProblemSolution.show_solution());

    oRodCuttingProblemSolution.bottom_up_method(30);
    print_normal_msg("bottom up method result:\n");
    print_normal_msg(oRodCuttingProblemSolution.show_solution());

    PRINT_DEFAULT_ERROR
}
