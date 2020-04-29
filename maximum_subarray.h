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

    /**
     * @brief get begin
     * @param
     * @return size_t, begin's value
     * @remarks
     */
    size_t get_begin() const;

    /**
     * @brief set begin's value
     * @param size_t nBegin, new begin's value
     * @return void
     * @remarks
     */
    void set_begin(size_t nBegin);
    
    /**
     * @brief get end 
     * @param
     * @return size_t, end's value
     * @remarks
     */
    size_t get_end() const;

    /**
     * @brief set end's value
     * @param size_t nEnd, new end's value
     * @return void
     * @remarks
     */
    void set_end(size_t nEnd);

    /**
     * @brief get sum
     * @param
     * @return int32_t, sum's value
     * @remarks
     */
    int32_t get_sum() const;

    /**
     * @brief set sum's value
     * @param int32_t nSum, new sum's value
     * @return void
     * @remarks
     */
    void set_sum(int32_t nSum);

    friend bool operator==(const Maximum_SubArray_Result &oL, const Maximum_SubArray_Result &oR);

private:
    size_t m_nBegin;        // maximum subarray begin index
    size_t m_nEnd;          // maximum subarray end index
    int32_t m_nSum;         // sum of the maximum

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
