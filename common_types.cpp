/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: common headers/macros/functions/structs
 *************************************************************************/

#include "common_types.h"

string to_string(const vector<uint32_t> &vecInt)
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

void get_random_vector(vector<uint32_t> &vecInt, size_t nSize)
{
    srand(time(NULL));
    for (size_t i = 0; i < nSize; ++i){
        vecInt.push_back(rand() % 90 + 10);
    }
}
