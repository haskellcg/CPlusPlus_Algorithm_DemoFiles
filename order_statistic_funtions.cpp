/**************************************************************************
 * author: haskellcg
 * date: 2020-05-08
 * description: order statistic algorithms
 *************************************************************************/

#include "order_statistic_funtions.h"

void order_statistic_funtions_test()
{
    print_highlight_msg(">>> Test order statistic funtions:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (false){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
