/**************************************************************************
 * author: haskellcg
 * date: 2020-11-27
 * description: avl tree data structure
 *************************************************************************/

#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include "binary_tree.h"
#include "common_types.h"

/**
 * @brief avl tree node
 */
class ATNode: public BTNode
{
public:
    /**
     * @brief default constructor
     */
    ATNode();

    /**
     * @brief constructor to initialize all member
     */
    ATNode(uint32_t nData, BTNode *pParent, BTNode *pLeft, BTNode *pRight, uint32_t nHeight);

    /**
     * @brief get height
     * @param
     * @return uint32_t
     * @remarks
     */
    uint32_t get_height() const;

    /**
     * @brief set height
     * @param
     * @return void
     * @remarks
     */
    void set_height(uint32_t nHeight);

private:
    /*< height of the node */
    uint32_t m_nHeight;
};

/**
 * @brief avl tree
 */
class AVL_Tree: public Binary_Tree
{
};

/**
 * @brief test avl tree structure
 */
void avl_tree_test();

#endif // __AVL_TREE_H__
