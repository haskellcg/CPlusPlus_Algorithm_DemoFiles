/**************************************************************************
 * author: haskellcg
 * date: 2020-04-23
 * description: find maximum subarray algorithm
 *************************************************************************/

#include "maximum_subarray.h"

Maximum_SubArray_Result::Maximum_SubArray_Result()
:   m_nBegin(MIN_INT32),
    m_nEnd(MIN_INT32),
    m_nSum(MIN_INT32)
{
}

Maximum_SubArray_Result::Maximum_SubArray_Result(size_t nBegin, size_t nEnd, int32_t nSum)
:   m_nBegin(nBegin),
    m_nEnd(nEnd),
    m_nSum(nSum)
{
}

string Maximum_SubArray_Result::to_string() const
{
    ostringstream ossResult;
    ossResult << "["
              << m_nBegin << ", "
              << m_nEnd << ", "
              << m_nSum
              << "]";
    return ossResult.str();
}

bool operator==(const Maximum_SubArray_Result &oL, const Maximum_SubArray_Result &oR)
{
    if ((oL.m_nBegin == oR.m_nBegin) &&
        (oL.m_nEnd == oR.m_nEnd) &&
        (oL.m_nSum == oR.m_nSum)){
        return true;
    } else {
        return false;
    }
}

Maximum_SubArray_Result maximum_subarray(vector<int32_t> &vecInt)
{
    // TODO: add algorithm
    return Maximum_SubArray_Result();
}

void maximum_subarray_test()
{
    print_highlight_msg(">>> Test maximum subarray funtion:\n");
    int32_t arraySrc[] = {-1, 1, 2, 3, 4, -5};
    vector<int32_t> vecSrc;
    vecSrc.insert(vecSrc.begin(), begin(arraySrc), end(arraySrc));
    print_normal_msg(to_string(vecSrc) + "\n");
    Maximum_SubArray_Result oMaximum_SubArray_Result = maximum_subarray(vecSrc);
    print_normal_msg(oMaximum_SubArray_Result.to_string() + "\n");
    Maximum_SubArray_Result oMaximum_SubArray_CorrectResult(1, 4, 10);
    if (oMaximum_SubArray_CorrectResult == oMaximum_SubArray_Result){
        print_correct_msg("CORRECT\n");
    } else{
        print_error_msg("ERROR\n");
    }
}
