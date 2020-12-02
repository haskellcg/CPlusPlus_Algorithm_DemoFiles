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

size_t Maximum_SubArray_Result::get_begin() const
{
    return m_nBegin;
}

void Maximum_SubArray_Result::set_begin(size_t nBegin)
{
    m_nBegin = nBegin;
}

size_t Maximum_SubArray_Result::get_end() const
{
    return m_nEnd;
}

void Maximum_SubArray_Result::set_end(size_t nEnd)
{
    m_nEnd = nEnd;
}

int32_t Maximum_SubArray_Result::get_sum() const
{
    return m_nSum;
}

void Maximum_SubArray_Result::set_sum(int32_t nSum)
{
    m_nSum = nSum;
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

Maximum_SubArray_Result maximum_subarray_through_mid_solver(const vector<int32_t> &vecInt,
                                                            size_t nBegin,
                                                            size_t nMid,
                                                            size_t nEnd)
{
    // calculate max sum of the left side include nMid
    int32_t nLeftSum = 0;
    int32_t nLeftMaxSum = MIN_INT32;
    size_t nLeftMaxIndex = nMid;
    for (size_t i = nMid; i >= nBegin; --i){
        nLeftSum += vecInt[i];
        if (nLeftSum > nLeftMaxSum){
            nLeftMaxSum = nLeftSum;
            nLeftMaxIndex = i;
        }
        if (0 == i){
            // if do --i operation, i will overflow
            // make program endless
            break;
        }
    }
    // calcualte max sum of the right side exclude nMid
    int32_t nRightSum = 0;
    int32_t nRightMaxSum = MIN_INT32;
    size_t nRightMaxIndex = nMid + 1;
    for (size_t i = nMid + 1; i <= nEnd; ++i){
        nRightSum += vecInt[i];
        if (nRightSum > nRightMaxSum){
            nRightMaxSum = nRightSum;
            nRightMaxIndex = i;
        }
    }
    return Maximum_SubArray_Result(nLeftMaxIndex, nRightMaxIndex, (nLeftMaxSum + nRightMaxSum));
}

Maximum_SubArray_Result maximum_subarray_solver(const vector<int32_t> &vecInt, size_t nBegin, size_t nEnd)
{
    // if only one element
    if (nBegin == nEnd){
        return Maximum_SubArray_Result(nBegin, nEnd, vecInt[nBegin]);
    } else {
        size_t nMid = (nBegin + nEnd) >> 1;
        // calculate left part
        Maximum_SubArray_Result oMaximum_SubArray_LeftResult =
            maximum_subarray_solver(vecInt, nBegin, nMid);
        // calculate right part
        Maximum_SubArray_Result oMaximum_SubArray_RightResult =
            maximum_subarray_solver(vecInt, nMid + 1, nEnd);
        // calculate mid part
        Maximum_SubArray_Result oMaximum_SubArray_MidResult =
            maximum_subarray_through_mid_solver(vecInt, nBegin, nMid, nEnd);
        if ((oMaximum_SubArray_LeftResult.get_sum() > oMaximum_SubArray_MidResult.get_sum()) &&
            (oMaximum_SubArray_LeftResult.get_sum() > oMaximum_SubArray_RightResult.get_sum())){
            return oMaximum_SubArray_LeftResult;
        } else if ((oMaximum_SubArray_RightResult.get_sum() > oMaximum_SubArray_LeftResult.get_sum()) &&
                   (oMaximum_SubArray_RightResult.get_sum() > oMaximum_SubArray_MidResult.get_sum())){
            return oMaximum_SubArray_RightResult;
        } else {
            return oMaximum_SubArray_MidResult;
        }
    }
}

Maximum_SubArray_Result maximum_subarray(const vector<int32_t> &vecInt)
{
    return maximum_subarray_solver(vecInt, 0, vecInt.size() - 1);
}

void maximum_subarray_test()
{
    print_highlight_msg(">>> Test maximum subarray funtion:\n");
    int32_t arraySrc[] = {-1, 1, 2, 3, 4, -5};
    vector<int32_t> vecSrc;
    vecSrc.insert(vecSrc.end(), begin(arraySrc), end(arraySrc));
    print_normal_msg(to_string(vecSrc) + "\n");
    Maximum_SubArray_Result oMaximum_SubArray_Result = maximum_subarray(vecSrc);
    print_normal_msg(oMaximum_SubArray_Result.to_string() + "\n");
    Maximum_SubArray_Result oMaximum_SubArray_CorrectResult(1, 4, 10);
    if (oMaximum_SubArray_CorrectResult == oMaximum_SubArray_Result){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
