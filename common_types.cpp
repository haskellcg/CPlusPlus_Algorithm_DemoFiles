/**************************************************************************
 * author: haskellcg
 * date: 2018-11-20
 * description: common headers/macros/functions/structs
 *************************************************************************/

#include "common_types.h"

template <typename T>
string to_string(const vector<T> &vecInt)
{
    ostringstream ossResult;
    ossResult << "[";
    for (size_t i = 0; i < vecInt.size(); ++i){
        ossResult << vecInt[i];
        if (i != (vecInt.size() - 1)){
            ossResult << ", ";
        }
    }
    ossResult << "]";
    return ossResult.str();
}

string to_string(const vector<uint32_t> &vecInt)
{
    return to_string<uint32_t>(vecInt);
}

string to_string(const vector<int32_t> &vecInt)
{
    return to_string<int32_t>(vecInt);
}

void get_random_vector(vector<uint32_t> &vecInt, size_t nSize)
{
    srand(time(NULL));
    for (size_t i = 0; i < nSize; ++i){
        vecInt.push_back(rand() % 900 + 100);
    }
}

bool is_sorted_as_ascending(const vector<uint32_t> &vecInt)
{
    bool bResult = true;
    for (size_t i = 1; i < vecInt.size(); ++i){
        if (vecInt[i - 1] > vecInt[i]){
            bResult = false;
            break;
        }
    }
    return bResult;
}

void print_normal_msg(const string &strMsg)
{
    cout << strMsg;
}

void print_correct_msg(const string &strMsg)
{
    cout << "\033[32m" << strMsg << "\033[0m";
}

void print_error_msg(const string &strMsg)
{
    cout << "\033[31m" << strMsg << "\033[0m";
}

void print_warning_msg(const string &strMsg)
{
    cout << "\033[33m" << strMsg << "\033[0m";
}

void print_highlight_msg(const string &strMsg)
{
    cout << "\033[36m" << strMsg << "\033[0m";
}
