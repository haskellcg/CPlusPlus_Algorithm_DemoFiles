/**************************************************************************
 * author: haskellcg
 * date: 2020-11-13
 * description: use hash funtion to implement set
 *************************************************************************/

#include "hash_set.h"

void hash_set_test()
{
    print_highlight_msg(">>> Test hash set:\n");
    if (67 == multiplication_hash(123456, 14)){
        print_correct_msg("multiplication hash function correct\n");
    } else {
        print_error_msg("multiplication hash function error\n");
    }
    print_error_msg("no test case yet\n");
}
