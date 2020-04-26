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

    /**
     * @brief convert this to string
     * @param
     * @return string
     * @remarks
     */
    string to_string() const;

    /**
     * @brief convert this to friendly string
     * @param
     * @return string
     * @remarks
     */
    string to_friendly_string() const;

    /**
     * @brief build min heap with current data
     * @param
     * @return void
     * @remarks
     */
    void build_min_heap();

    /**
     * @brief insert a new nValue to the heap
     * @param uint32_t nValue, new value to insert
     * @return void
     * @remarks
     */
    void insert(uint32_t nValue);

    /**
     * @brief get the minimum value
     * @param
     * @return uint32_t, the minimum value
     * @remarks
     *          if heap is empty, return the MAX_UINT32
     */
    uint32_t get_minimum() const;

    /**
     * @brief extract the minimum and return it
     * @param
     * @return uint32_t, the minimum value
     * @remarks
     *          if heap is empty, return the MAX_UINT32
     */
    uint32_t extract_minimum();

    /**
     * @brief change the value of the nIndex
     * @param size_t nIndex, position of element to change value
     * @param uint32_t nValue, new value
     * @return bool, true: success, false: failed
     * @remarks
     */
    bool change_value(size_t nIndex, uint32_t nValue);

private:
    /**
     * @brief calculate parent's index of nIndex
     * @param size_t nIndex, current index
     * @return size_t, parent index
     * @remarks
     */
    inline size_t get_parent_index(size_t nIndex) const;

    /**
     * @brief calculate left child's index of nIndex
     * @param size_t nIndex, current index
     * @return size_t, left child index
     * @remarks
     */
    inline size_t get_left_child_index(size_t nIndex) const;

    /**
     * @brief calculate right child's index of nIndex
     * @param size_t nIndex, current index
     * @return size_t, right child index
     * @remarks
     */
    inline size_t get_right_child_index(size_t nIndex) const;

    /**
     * @brief calculate height of the heap with nIndex as root
     * @param size_t nIndex, current root of the heap
     * @return size_t, height of the nIndex
     * @remarks
     */
    inline size_t get_node_height(size_t nIndex) const;

    /**
     * @brief adjust heap with nIndex as root
     * @param size_t nRoot, root of the current heap
     * @return void
     * @remarks
     */
    void min_heapify(size_t nRoot);

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
