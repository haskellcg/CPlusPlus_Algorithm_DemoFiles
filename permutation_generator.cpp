/**************************************************************************
 * author: haskellcg
 * date: 2021-01-06
 * description: generat permutation
 *************************************************************************/

#include "permutation_generator.h"

void swap_charaters(char &chL, char &chR)
{
    char chT = chL;
    chL = chR;
    chR = chT;
}

void string_permutation_generator(string &strSrc, size_t nStartIndex, vector<string> &vecPermutations)
{
    if (nStartIndex < strSrc.size()){
        for (size_t i = nStartIndex; i < strSrc.size(); ++i){
            swap_charaters(strSrc[nStartIndex], strSrc[i]);
            string_permutation_generator(strSrc, nStartIndex + 1, vecPermutations);
            swap_charaters(strSrc[nStartIndex], strSrc[i]);
        }
    } else {
        vecPermutations.push_back(strSrc);
    }
}

void permutation_generator_test()
{
    print_highlight_msg(">>> Test permutation generator functions:\n");
    string strSrc = "248";
    vector<string> vecPermutations;
    string_permutation_generator(strSrc, 0, vecPermutations);
    print_normal_msg("source string: " + strSrc + "\n");
    print_normal_msg("result permutations:\n");
    for (size_t i = 0; i < vecPermutations.size(); ++i){
        print_normal_msg("\t" + vecPermutations[i] + "\n");
    }
}
