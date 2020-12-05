/**************************************************************************
 * author: haskellcg
 * date: 2020-12-05
 * description: radix heap data structure
 *************************************************************************/

#ifndef __RADIX_HEAP_H__
#define __RADIX_HEAP_H__

#include "common_types.h"

/**
 * @brief radix heap
 * @remarks
 *          introduction: http://ssp.impulsetrain.com/radix-heap.html
 *          radix heap wiki: https://en.wikipedia.org/wiki/Radix_heap
 *          monotone priority queue: https://en.wikipedia.org/wiki/Monotone_priority_queue
 *          asm: https://en.cppreference.com/w/cpp/language/asm
 *          bsr instruction: https://stackoverflow.com/questions/57633304/how-to-get-bsr-instruction-to-work-on-64-bits
 */
class Radix_Heap
{
public:
    /**
     * @brief constructor
     */
    Radix_Heap();

    /**
     * @brief show radix heap
     */
    string to_string() const;

    /**
     * @brief insert nInt to heap
     * @param uint32_t nInt, nInt
     * @return void
     * @remarks
     */
    void insert(uint32_t nInt);

    /**
     * @brief extract min element for heap
     * @param
     * @return uint32_t, min element
     * @remarks
     */
    uint32_t extract_min();

private:
    /**
     * @brief get the position of the highest set bit in nInt
     * @param uint32_t nInt, integer
     * @return int32_t, position of the highest set bit
     *                  -1 if nInt is 0
     */
    int32_t get_highest_set_bit_pos(uint32_t nInt) const;

private:
    /*< buckets */
    vector<vector<uint32_t>> m_vecBuckets;
    /*< last deleted */
    uint32_t m_nLastDeleted;
};

/**
 * @brief test radix heap data structure
 * @param
 * @return void
 * @remarks
 */
void radix_heap_test();

#endif // __RADIX_HEAP_H__
