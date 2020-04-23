/**************************************************************************
 * author: haskellcg
 * date: 2020-04-23
 * description: find maximum subarray algorithm
 *************************************************************************/

#ifndef __MAXIMUM_SUBARRAY_H__
#define __MAXIMUM_SUBARRAY_H__

#include "common_types.h"

/**
 * @brief class for maximum subarray problem to store result
 */
class Maximum_SubArray_Result
{
public:
    size_t m_nBegin;        // maximum subarray begin index
    size_t m_nEnd;          // maximum subarray end index
    int32_t m_nSum;         // sum of the maximum

public:
    /**
     * @brief construct method to init the memeber
     * @param
     * @return
     * @remarks
     */
    Maximum_SubArray_Result();

    /**
     * @brief construct method to init the memeber
     * @param size_t nBegin, 
     * @param size_t nEnd,
     * @param int32_t nSum
     * @return
     * @remarks
     */
    Maximum_SubArray_Result(size_t nBegin, size_t nEnd, int32_t nSum);

    /**
     * @brief convert to string
     * @param
     * @return string
     * @remarks
     */
    string to_string() const;

    friend bool operator==(const Maximum_SubArray_Result &oL, const Maximum_SubArray_Result &oR);
};

/**
 * @brief override operator == for Maximum_SubArray_Result
 * @param const Maximum_SubArray_Result &oL, left object 
 * @param const Maximum_SubArray_Result &oR, right object 
 * @return bool, true if equal, false if not equal
 * @remarks
 */
bool operator==(const Maximum_SubArray_Result &oL, const Maximum_SubArray_Result &oR);

/**
 * @brief find the maximum subarray in vecInt
 * @param const vector<int32_t> &vecInt, array to be found maximum subarray
 * @return Maximum_SubArray_Result, result
 * @remarks
 */
Maximum_SubArray_Result maximum_subarray(const vector<int32_t> &vecInt);

/**
 * @brief test the algorithm find the maximum subarray
 * @param
 * @return void
 * @remarks
 */
void maximum_subarray_test();

#endif // __MAXIMUM_SUBARRAY_H__
