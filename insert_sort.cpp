/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: insert sort algorithm
 *************************************************************************/

#include "insert_sort.h"

void insert_sort(vector<uint32_t> &vecInt)
{
    // repeat (n - 1) times
    for (size_t i = 1; i < vecInt.size(); ++i){
        uint32_t nKey = vecInt[i];
        size_t j = i - 1;
        // look back for the insert position
        while ((j >= 0) && (vecInt[j] > nKey)){
            vecInt[j + 1] = vecInt[j];
            --j;
            // DEBUG
            // cout << "inner loop:" << to_string(vecInt) << endl;
        }
        vecInt[j + 1] = nKey;
        // DEBUG
        // cout << to_string(vecInt) << endl;
    }
}

void insert_sort_test()
{
    cout << ">>> Test insert sort funtion:" << endl;
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    cout << to_string(vecSrc) << endl;
    insert_sort(vecSrc);
    cout << to_string(vecSrc) << endl;
}
