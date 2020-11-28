/**************************************************************************
 * author: haskellcg
 * date: 2020-10-28
 * description: nowcoder.com practice codes
 *************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_types.h"
#include "nowcoder_com_first_part.h"

using namespace std;

void nowcoder_com_hw_hj1()
{
    char cBuff[5000];

    // cin.get(cBuff, 5000);
    cin.getline(cBuff, 5000);
    int nIndex = 0;
    int nWordLength = 0;
    while (true){
        if (('\0' != cBuff[nIndex]) && (' ' != cBuff[nIndex])){
            ++nWordLength;
        } else if ('\0' == cBuff[nIndex]){
            break;
        } else {
            nWordLength = 0;
        }
        ++nIndex;
    }
    cout << nWordLength;

    /*
     * 方法二
    // scanf stops when met space or enter, so cBuff will store the last word
    // EOF == -1, so ~EOF == 0
    // Ctrl + D in linux is EOF
    while (EOF != scanf("%s", cBuff));
    printf("%lu", strlen(cBuff));
    */
}

void nowcoder_com_hw_hj2()
{
    char cBuff[1024];
    char cCharacter;
    cin.getline(cBuff, 1024);
    cin >> cCharacter;
    for (int i = 0; i < 1024; ++i){
        if ('\0' == cBuff[i]){
            break;
        }
        if ((cBuff[i] >= 'A') && (cBuff[i]) <= 'Z'){
            cBuff[i] += 'a' - 'A';
        }
    }
    if ((cCharacter >= 'A') && (cCharacter <= 'Z')){
        cCharacter += 'a' - 'A';
    }
    int nSameCharNumber = 0;
    for (int i = 0; i < 1024; ++i){
        if ('\0' == cBuff[i]){
            break;
        }
        if (cBuff[i] == cCharacter){
            ++nSameCharNumber;
        }
    }
    cout << nSameCharNumber;
}

void nowcoder_com_test()
{
    print_highlight_msg(">>> Test nowcoder.com testers:\n");
    // nowcoder_com_hw_hj1();
    // nowcoder_com_hw_hj2();
    print_correct_msg("OK.\n");
}
