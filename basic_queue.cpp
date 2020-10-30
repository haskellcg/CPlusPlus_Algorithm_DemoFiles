/**************************************************************************
 * author: haskellcg
 * date: 2020-10-28
 * description: basic queue data structure
 *************************************************************************/

#include "basic_queue.h"
#include "common_types.h"

Basic_Queue::Basic_Queue()
:   m_nHead(0),
    m_nTail(0)
{
}

bool Basic_Queue::enqueue(int32_t nInt)
{
    if (is_full()){
        return false;
    } else {
        m_arrayData[m_nTail++] = nInt;
        if (m_nTail >= QUEUE_LENGTH){
            m_nTail -= QUEUE_LENGTH;
        }
        return true;
    }
}

bool Basic_Queue::dequeue(int32_t &nInt)
{
    if (is_empty()){
        return false;
    } else {
        nInt = m_arrayData[m_nHead++];
        if (m_nHead >= QUEUE_LENGTH){
            m_nHead -= QUEUE_LENGTH;
        }
        return true;
    }
}

size_t Basic_Queue::size() const
{
    if (m_nTail < m_nHead){
        return (m_nTail + QUEUE_LENGTH - m_nHead);
    } else {
        return (m_nTail - m_nHead);
    }
}

bool Basic_Queue::is_empty() const
{
    /*< m_nHead == m_nTail */
    return (0 == size());
}

bool Basic_Queue::is_full() const
{
    /*< (m_nTail + 1) == m_nHead */
    return ((QUEUE_LENGTH - 1) == size());
}

void basic_queue_test()
{
    print_highlight_msg(">>> Test basic queue structure:\n");
    int32_t arrayData[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Basic_Queue oQueue;
    for (int i = 0; i < 5; ++i){
        oQueue.enqueue(arrayData[i]);
    }
    if (5 != oQueue.size()){
        print_error_msg("basic queue size error\n");
    } else {
        print_correct_msg("basic queue size correct\n");
    }
    for (int i = 5; i < 10; ++i){
        oQueue.enqueue(arrayData[i]);
    }
    if (9 != oQueue.size()){
        print_error_msg("basic queue size error\n");
    } else {
        print_correct_msg("basic queue size correct\n");
    }
    int nDequeueInt = MIN_UINT32;
    if (true != oQueue.dequeue(nDequeueInt)){
        print_error_msg("dequeue method return error\n");
    } else {
        print_correct_msg("dequeue method return correct\n");
    }
    if (8 == nDequeueInt){
        print_error_msg("dequeue data error\n");
    } else {
        print_correct_msg("dequeue data correct\n");
    }
}
