/**************************************************************************
 * author: haskellcg
 * date: 2021-02-19
 * description: longest common subsequence problem solution
 *************************************************************************/

#include "longest_common_subsequence_problem.h"

string longest_common_subsequence_problem_solution(const string &strA, const string &strB)
{
    const uint32_t BEST_FROM_TOP = 1;
    const uint32_t BEST_FROM_LEFT = 2;
    const uint32_t BEST_FROM_TOPLEFT = 4;

    size_t nLengthA = strA.size();
    size_t nLengthB = strB.size();

    vector<vector<uint32_t>> matrixMaxLength;
    vector<vector<uint32_t>> matrixMaxPosition;
    for (size_t i = 0; i <= nLengthA; ++i){
        vector<uint32_t> vecRow;
        for (size_t j = 0; j <= nLengthB; ++j){
            vecRow.push_back(0);
        }
        matrixMaxLength.push_back(vecRow);
        matrixMaxPosition.push_back(vecRow);
    }

    for (size_t i = 1; i <= nLengthA; ++i){
        for (size_t j = 1; j <= nLengthB; ++j){
            if (strA[i - 1] == strB[j - 1]){
                matrixMaxLength[i][j] = matrixMaxLength[i - 1][j - 1] + 1;
                matrixMaxPosition[i][j] = BEST_FROM_TOPLEFT;
            } else if (matrixMaxLength[i - 1][j] > matrixMaxLength[i][j - 1]){
                matrixMaxLength[i][j] = matrixMaxLength[i - 1][j];
                matrixMaxPosition[i][j] = BEST_FROM_TOP;
            } else {
                matrixMaxLength[i][j] = matrixMaxLength[i][j - 1];
                matrixMaxPosition[i][j] = BEST_FROM_LEFT;
            }
        }
    }

    // output result
    string strLCS;
    size_t i = nLengthA;
    size_t j = nLengthB;
    uint32_t nCurrentLength = matrixMaxLength[i][j];
    while (nCurrentLength > 0){
        if (BEST_FROM_TOPLEFT == matrixMaxPosition[i][j]){
            --i;
            --j;
            nCurrentLength = matrixMaxLength[i][j];
            strLCS = strA[i] + strLCS;
        } else if (BEST_FROM_LEFT == matrixMaxPosition[i][j]){
            --j;
            nCurrentLength = matrixMaxLength[i][j];
        } else {
            --i;
            nCurrentLength = matrixMaxLength[i][j];
        }
    }

    print_warning_msg("max length matrix:\n");
    print_warning_msg(to_string(matrixMaxLength) + "\n");
    print_warning_msg("max position matrix:\n");
    print_warning_msg(to_string(matrixMaxPosition) + "\n");
    print_warning_msg("LCS:\n");
    print_warning_msg(strLCS + "\n");

    return strLCS;
}

void longest_common_subsequence_problem_solution_test()
{
    print_highlight_msg(">>> Test longest common subsequence problem solution:\n");

    // 一个DNA串由一串碱基的分支组成
    // 碱基由腺嘌呤(A)、鸟嘌呤(C)、胞嘧啶(G)、胸腺嘧啶(T)
    string strA = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    print_normal_msg("strA: " + strA + "\n");
    string strB = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    print_normal_msg("strB: " + strB + "\n");
    string strLCS12 = "GTCGTCGGAAGCCGGCCGAA";
    print_normal_msg("strLCS: " + strLCS12 + "\n");
    if (strLCS12 != longest_common_subsequence_problem_solution(strA, strB)){
        print_error_msg("longest common subsequence error.\n");
    } else {
        print_correct_msg("longest common subsequence correct.\n");
    }
}
