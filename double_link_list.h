/**************************************************************************
 * author: haskellcg
 * date: 2020-10-28
 * description: double link list data structure
 *************************************************************************/

#ifndef __DOUBLE_LINK_LIST_H__
#define __DOUBLE_LINK_LIST_H__

#include "common_types.h"

/**
 * @brief node for double link list
 */
class DLNode
{
public:
    /**
     * @brief default constructor
     */
    DLNode();
        
    /**
     * @brief constructor for initialize all the members
     */
    DLNode(uint32_t nData, DLNode *pPrev, DLNode *pNext);

    /**
     * @brief getter for data
     */
    uint32_t get_data() const;

    /**
     * @brief getter for prev
     */
    DLNode *get_prev() const;

    /**
     * @brief getter for next
     */
    DLNode *get_next() const;

    /**
     * @brief setter for data
     */
    void set_data(uint32_t nData);

    /**
     * @brief setter for prev
     */
    void set_prev(DLNode *pPrev);

    /**
     * @brief setter for next
     */
    void set_next(DLNode *pNext);

private:
    /*< data in the node */
    uint32_t m_nData;
    /*< link to the prev node */
    DLNode *m_pPrev;
    /*< link to the next node */
    DLNode *m_pNext;
};

/**
 * @brief double link list
 */
class Double_Link_List
{
public:
    /**
     * @brief default constructor
     */
    Double_Link_List();

    /**
     * @brief destructor
     */
    virtual ~Double_Link_List();

    /**
     * @brief search nKey in the list
     * @param uint32_t nKey, key
     * @return DLNode *, the DLNode that has the value equals to nKey,
     *                   NULL if can't find it
     * @remarks
     */
    DLNode *search(uint32_t nKey);

    /**
     * @brief insert nData to the list head
     * @param uint32_t nData, data
     * @return DLNode *, the DLNode inserted
     * @remarks
     */
    DLNode *insert(uint32_t nData);

    /**
     * @brief delete pDLNode from list
     * @param DLNode *pDLNode, then DLNode
     * @return void
     * @remarks
     *          make sure pDLNode is in the list
     */
    void delete_node(DLNode *pDLNode);

private:
    /**
     * @brief private copy constructor
     */
    Double_Link_List(const Double_Link_List &oDLList);

    /**
     * @brief private assign override
     */
    Double_Link_List &operator=(const Double_Link_List &oDLList);

private:
    /*< head of the list */
    DLNode *m_pHead;
    /*< number of the data */
    size_t m_nSize;
};

/**
 * @brief test double link list data structure
 * @param
 * @return void
 * @remarks
 */
void double_link_list_test();

#endif // __DOUBLE_LINK_LIST_H__
