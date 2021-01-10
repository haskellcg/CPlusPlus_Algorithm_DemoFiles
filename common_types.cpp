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
        ossResult << setw(3) << vecInt[i];
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

bool copy_part_of_matrix(const vector<vector<int32_t>> &matrixSrc,
                         size_t nRowIndex, size_t nColumnIndex,
                         size_t nColumns, size_t nRows,
                         vector<vector<int32_t>> &matrixCp)
{
    if ((nRowIndex >= matrixSrc.size()) ||
        ((nRowIndex + nRows - 1) >= matrixSrc.size())){
        return false;
    }
    for (size_t i = 0; i < nRows; ++i){
        vector<int32_t> vecInt;
        for (size_t j = 0; j < nColumns; ++j){
            if ((nColumnIndex >= matrixSrc[nRowIndex + i].size()) ||
                ((nColumnIndex + nColumns - 1) >= matrixSrc[nRowIndex + i].size())){
                return false;
            }   
            vecInt.push_back(matrixSrc[nRowIndex + i][nColumnIndex + j]);
        }
        matrixCp.push_back(vecInt);
    }
    return true;
}

void matrix_add(const vector<vector<int32_t>> &matrixA,
                const vector<vector<int32_t>> &matrixB,
                vector<vector<int32_t>> &matrixC)
{
    for (size_t i = 0; i < matrixA.size(); ++i){
        vector<int32_t> vecInt;
        for (size_t j = 0; j < matrixA[i].size(); ++j){
            vecInt.push_back(matrixA[i][j] + matrixB[i][j]);
        }
        matrixC.push_back(vecInt);
    }
}

void matrix_minus(const vector<vector<int32_t>> &matrixA,
                  const vector<vector<int32_t>> &matrixB,
                  vector<vector<int32_t>> &matrixC)
{
    for (size_t i = 0; i < matrixA.size(); ++i){
        vector<int32_t> vecInt;
        for (size_t j = 0; j < matrixA[i].size(); ++j){
            vecInt.push_back(matrixA[i][j] - matrixB[i][j]);
        }
        matrixC.push_back(vecInt);
    }
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

void swap_data(uint32_t &nL, uint32_t &nR)
{
    uint32_t nTemp = nR;
    nR = nL;
    nL = nTemp;
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

uint32_t division_hash(uint32_t nK, uint32_t nM)
{
    return (nK % nM);
}

uint32_t multiplication_hash(uint32_t nK, uint32_t nLogM)
{
    uint32_t nKAMod1 = (uint32_t)((uint64_t)nK * 2654435769) % ((uint64_t)2 << 32);
    return (nKAMod1 >> (32 - nLogM));
}
