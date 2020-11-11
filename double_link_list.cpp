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
    m_pPrev = pPrev;
}

void DLNode::set_next(DLNode *pNext)
{
    m_pNext = pNext;
}

Double_Link_List::Double_Link_List()
{
    m_pHead = new DLNode(MAX_UINT32, NULL, NULL);
    m_pHead->set_prev(m_pHead);
    m_pHead->set_next(m_pHead);
    m_nSize = 0;
}

Double_Link_List::~Double_Link_List()
{
    while (m_nSize > 0){
        delete_node(m_pHead->get_next());
    }
    delete m_pHead;
    m_pHead = NULL;
}

DLNode *Double_Link_List::search(uint32_t nKey)
{
    DLNode *pCurDLNode = m_pHead->get_next();
    while (m_pHead != pCurDLNode){
        if (nKey == pCurDLNode->get_data()){
            return pCurDLNode;
        }
        pCurDLNode = pCurDLNode->get_next();
    }
    return NULL;
}

DLNode *Double_Link_List::insert(uint32_t nData)
{
    DLNode *pNewDLNode = new DLNode(nData, NULL, NULL);
    m_pHead->get_next()->set_prev(pNewDLNode);
    pNewDLNode->set_next(m_pHead->get_next());
    m_pHead->set_next(pNewDLNode);
    pNewDLNode->set_prev(m_pHead);
    ++m_nSize;
    return pNewDLNode;
}

void Double_Link_List::delete_node(DLNode *pDLNode)
{
    pDLNode->get_prev()->set_next(pDLNode->get_next());
    pDLNode->get_next()->set_prev(pDLNode->get_prev());
    pDLNode->set_next(NULL);
    pDLNode->set_prev(NULL);
    delete pDLNode;
    --m_nSize;
}

void double_link_list_test()
{
    print_highlight_msg(">>> Test double link list structure:\n");

    uint32_t arrayData[5] = {1, 2, 3, 4, 5};

    Double_Link_List oDLList;
    for (int i = 0; i < 5; ++i){
        oDLList.insert(arrayData[i]);
    }

    DLNode *pDLNode = oDLList.search(3);
    if ((NULL != pDLNode) && (3 == pDLNode->get_data())){
        print_correct_msg("3 is inserted\n");
    } else {
        print_error_msg("3 is not found\n");
    }

    oDLList.delete_node(pDLNode);
    if (NULL == oDLList.search(3)){
        print_correct_msg("3 is deleted\n");
    } else {
        print_error_msg("3 is not deleted\n");
    }
}
