/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: common headers/macros/functions/structs
 *************************************************************************/

#include "common_types.h"

string print(const vector<uint32_t> &vecInt)
{
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < vecInt.size(); ++i){
        oss << vecInt[i];
        if (i != (vecInt.size() - 1)){
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

void random(vector<uint32_t> &vecInt, size_t nIntNum, uint32_t nMode)
{
    srand(time(NULL));
    for (size_t i = 0; i < nIntNum; ++i){
        vecInt.push_back(rand() % nMode);
    }
}
