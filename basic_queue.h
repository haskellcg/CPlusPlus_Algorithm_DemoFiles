/**************************************************************************
 * author: haskellcg
 * date: 2020-10-28
 * description: basic queue data structure
 *************************************************************************/

#ifndef __BASIC_QUEUE_H__
#define __BASIC_QUEUE_H__

#include "common_types.h"

#define QUEUE_LENGTH 10

/**
 * @brief basic queue data structure
 *        capacity is (QUEUE_LENGTH - 1)
 */
class Basic_Queue
{
public:
    /**
     * @brief default constructor
     * @param
     * @return
     * @remarks
     */
    Basic_Queue();

    /**
     * @brief put data to the queue
     * @param int nInt, the data
     * @return bool, false if queue if full
     * @remarks
     */
    bool enqueue(int nInt);

    /**
     * @brief remove data from the queue
     * @param int &nInt, the data removed
     * @return bool, false if queue is empty
     * @remarks
     */
    bool dequeue(int &nInt);

    /**
     * @brief get the size of the queue
     * @param
     * @return size_t
     * @remarks
     */
    size_t size() const;

    /**
     * @brief queue is empty or not
     * @param
     * @return bool
     * @remarks
     */
    bool is_empty() const;

    /**
     * @brief queue is empty or not
     * @param
     * @return bool
     * @remarks
     */
    bool is_full() const;

private:
    /*< array for queue use */
    int m_arrayData[QUEUE_LENGTH];
    /*< head of the queue */
    size_t m_nHead;
    /*< tail of the queue */
    size_t m_nTail;
};

/**
 * @brief test basic queue data structure
 * @param
 * @return void
 * @remarks
 */
void basic_queue_test();

#endif // __BASIC_QUEUE_H__
