/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: insert sort algorithm
 *************************************************************************/

#include "insert_sort.h"

void insert_sort(vector<uint32_t> &vecInt)
{
    for (size_t i = 1; i < vecInt.size(); ++i){
        for (size_t j = i - 1; j >= 0; --j){
            if (vecInt[j + 1] < vecInt[j]){
                uint32_t nTemp = vecInt[j + 1];
                vecInt[j + 1] = vecInt[j];
                vecInt[j] = nTemp;
            } else {
                break;
            }
        }
    }
}

void insert_sort_test()
{
    vector<uint32_t> vecSrc;
    random(vecSrc, 10, 50);
    cout << print(vecSrc) << endl;
    insert_sort(vecSrc);
    cout << print(vecSrc) << endl;
}
