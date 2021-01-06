/**************************************************************************
 * author: haskellcg
 * date: 2021-01-06
 * description: circle print matrix
 *************************************************************************/

#include "matrix_circle_print.h"

string circle_print_matrix_outline(const vector<vector<int32_t>> &matrixSrc, size_t nX, size_t nY, size_t nWidth, size_t nHeight)
{
    ostringstream ossResult;
    if ((1 == nWidth) || (1 == nHeight)){
        if (1 == nWidth){
            for(size_t i = 0; i < nHeight; ++i){
                ossResult << ",";
                ossResult << matrixSrc[nX + i][nY];
            }
        } else{
            for (size_t i = 0; i < nWidth; ++i){
                ossResult << ",";
                ossResult << matrixSrc[nX][nY + i];
            }
        }
    } else {
        for (size_t i = 0; i < nWidth - 1; ++i){
            ossResult << ", ";
            ossResult << matrixSrc[nX][nY + i];
        }
        for (size_t i = 0; i < nHeight - 1; ++i){
            ossResult << ", ";
            ossResult << matrixSrc[nX + i][nY + nWidth - 1];
        }
        for (size_t i = 0; i < nWidth - 1; ++i){
            ossResult << ", ";
            ossResult << matrixSrc[nX + nHeight - 1][nY + nWidth - 1 - i];
        }
        for (size_t i = 0; i < nHeight - 1; ++i){
            ossResult << ", ";
            ossResult << matrixSrc[nX + nHeight - 1 - i][nY];
        }
    }
    return ossResult.str();
}

string circle_print_matrix(const vector<vector<int32_t>> &matrixSrc)
{
    string strResult;
    size_t nX = 0;
    size_t nY = 0;
    size_t nWidth = 5;
    size_t nHeight = 5;
    while ((nWidth >= 1) && (nHeight >= 1)){
        strResult += circle_print_matrix_outline(matrixSrc, nX, nY, nWidth, nHeight);
        print_warning_msg(strResult + "\n");
        if (nWidth > 1){
            nX += 1;
            nWidth -= 2;
        } else {
            nWidth = 0;
        }
        if (nHeight > 1){
            nY += 1;
            nHeight -= 2;
        } else {
            nHeight = 0;
        }
    }
    return strResult;
}

void matrix_circle_print_test()
{
    print_highlight_msg(">>> Test matrix circle print:\n");

    int32_t arraySrc[5][5] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    vector<vector<int32_t>> matrixSrc;
    for (size_t i = 0; i < 5; ++i){
        vector<int32_t> vecInt;
        vecInt.insert(vecInt.end(), begin(arraySrc[i]), end(arraySrc[i]));
        matrixSrc.push_back(vecInt);
    }
    print_normal_msg(to_string(matrixSrc) + "\n");
    print_warning_msg("circle print matrix:\n");
    print_normal_msg(circle_print_matrix(matrixSrc) + "\n");
}
