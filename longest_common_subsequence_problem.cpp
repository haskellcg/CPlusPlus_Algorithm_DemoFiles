/**************************************************************************
 * author: haskellcg
 * date: 2021-02-19
 * description: longest common subsequence problem solution
 *************************************************************************/

#include "longest_common_subsequence_problem.h"

string longest_common_subsequence_problem_solution(const string &strA, const string &strB)
{
    return strA + strB;
}

void longest_common_subsequence_problem_solution_test()
{
    print_highlight_msg(">>> Test longest common subsequence problem solution:\n");
    string strA = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    print_normal_msg("strA: " + strA + "\n");
    string strB = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    print_normal_msg("strB: " + strB + "\n");
    string strLCS12 = "GTCGTCGGAAGCCGGCCCGAA";
    print_normal_msg("strLCS: " + strLCS12 + "\n");
    if (strLCS12 != longest_common_subsequence_problem_solution(strA, strB)){
        print_error_msg("longest common subsequence error.\n");
    } else {
        print_correct_msg("longest common subsequence correct.\n");
    }
}
