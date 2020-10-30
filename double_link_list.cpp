/**************************************************************************
 * author: haskellcg
 * date: 2020-10-28
 * description: double link list data structure
 *************************************************************************/

#include "common_types.h"
#include "double_link_list.h"

DLNode::DLNode()
:   m_nData(MAX_UINT32),
    m_pPrev(NULL),
    m_pNext(NULL)
{
}
    
DLNode::DLNode(uint32_t nData, DLNode *pPrev, DLNode *pNext)
:   m_nData(nData),
    m_pPrev(pPrev),
    m_pNext(pNext)
{
}

uint32_t DLNode::get_data() const
{
    return m_nData;
}

DLNode *DLNode::get_prev() const
{
    return m_pPrev;
}

DLNode *DLNode::get_next() const
{
    return m_pNext;
}

void DLNode::set_data(uint32_t nData)
{
    m_nData = nData;
}

void DLNode::set_prev(DLNode *pPrev)
{
    m_pPrev = pPrev
}

void DLNode::set_next(DLNode *pNext)
{
    m_pNext = pNext;
}

void double_link_list_test()
{
    print_highlight_msg(">>> Test double link list structure:\n");
}
