/**************************************************************************
 * author: haskellcg
 * date: 2020-10-28
 * description: basic queue data structure
 *************************************************************************/

#ifndef __BASIC_QUEUE_H__
#define __BASIC_QUEUE_H__

#include "common_types.h"

#define QUEUE_LENGTH 20

/**
 * @brief basic queue data structure
 *        capacity is (QUEUE_LENGTH - 1)
 */
class Basic_Queue
{
public:
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
