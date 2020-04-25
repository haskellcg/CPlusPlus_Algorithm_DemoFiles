/**************************************************************************
 * author: haskellcg
 * date: 2020-04-25
 * description: heap sort algorithm
 *************************************************************************/

#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__

#include "common_types.h"

/**
 * @brief implement binary min heap with the array
 */
class Binary_Min_Heap
{
public:
    /**
     * @brief destroctor funtion
     * @param
     * @return
     * @remarks
     */
    ~Binary_Min_Heap();

    /**
     * @brief default constrcution funtion
     * @param
     * @return
     * @remarks
     */
    Binary_Min_Heap();

    /**
     * @brief constrcutor with vecSrc
     * @param const vector<uint32_t> &vecSrc, source vector
     * @return
     * @remarks
     */
    Binary_Min_Heap(const vector<uint32_t> &vecSrc);

    /**
     * @brief copy constructor
     * @param const Binary_Min_Heap &oAnotherHeap, another heap
     * @return
     * @remarks
     */
    Binary_Min_Heap(const Binary_Min_Heap &oAnotherHeap);

    /**
     * @brief override operator = 
     * @param const Binary_Min_Heap &oAnotherHeap, another heap
     * @return Binary_Min_Heap &, *this
     * @remarks
     */
    Binary_Min_Heap &operator=(const Binary_Min_Heap &oAnotherHeap);

private:
    /*< array for store data and make heap */
    uint32_t *m_pArray;
    /*< number of data in the array */
    size_t m_nSize;
    /*< capacity of the array */
    size_t m_nCapacity;
};

/**
 * @brief sort the vecInt with the heap sort algorithm
 * @param vector<uint32_t> &vecInt, vector need to be sorted
 * @return void
 * @remarks
 */
void heap_sort(vector<uint32_t> &vecInt);

/**
 * @brief test heap sort funtion
 * @param
 * @return void
 * @remarks
 */
void heap_sort_test();

#endif // __HEAP_SORT_H__