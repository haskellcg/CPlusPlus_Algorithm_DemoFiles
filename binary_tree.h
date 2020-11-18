/**************************************************************************
 * author: haskellcg
 * date: 2020-11-18
 * description: binary tree data structure
 *************************************************************************/

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "common_types.h"

/**
 * @brief binary tree node
 */
class BTNode
{
public:
    /**
     * @brief default constructor
     */
    BTNode();

    /**
     * @brief constructor to initialize all the members
     * @param uint32_t nData, data
     * @param BTNode *pParent, parent node link
     * @param BTNode *pLeft, left child node link
     * @param BTNode *pRight, right child node link
     * @return
     * @remarks
     */
    BTNode(uint32_t nData, BTNode *pParent, BTNode *pLeft, BTNode *pRight);

    /**
     * @brief get data
     */
    uint32_t get_data() const;

    /**
     * @brief set data
     */
    void set_data(uint32_t nData);

    /**
     * @brief get parent node link
     */
    BTNode *get_parent() const;

    /**
     * @brief set parent node link
     */
    void set_parent(BTNode *pParent);

    /**
     * @brief get left child node link
     */
    BTNode *get_left() const;

    /**
     * @brief set left child node link
     */
    void set_left(BTNode *pLeft);

    /**
     * @brief get right child node link
     */
    BTNode *get_right() const;

    /**
     * @brief set right child node link
     */
    void set_right(BTNode *pRight);

private:
    /*< data of the node */
    uint32_t m_nData;
    /*< link to parent node */
    BTNode *m_pParent;
    /*< link to left child */
    BTNode *m_pLeft;
    /*< link to right child */
    BTNode *m_pRight;
};

/**
 * @brief binary tree
 */
class Binary_Tree
{
public:
    /**
     * @brief default constructor
     */
    Binary_Tree();

    /**
     * @brief copy constructor
     */
    Binary_Tree(const Binary_Tree &oOtherBinaryTree);

    /**
     * @brief destructor
     */
    ~Binary_Tree();

    /**
     * @brief assign operator override
     */
    Binary_Tree &operator=(const Binary_Tree &oOtherBinaryTree);

    /**
     * @brief print binary tree as string
     * @param
     * @return string
     * @remarks
     */
    string to_string() const;

    /**
     * @brief search nKey in the tree
     * @param uint32_t nKey, key
     * @return BTNode *, null if nKey not in the tree,
     *                   or node contain the nKey will be returned
     * @remarks
     */
    BTNode *search(uint32_t nKey) const;

    // TODO: add more methods

private:
    /**
     * @brief copy pNode children nodes to pCopyNode
     * @param BTNode *pNode, current node
     * @param BTNode *pCopyNode, copy node
     * @return void
     * @remarks
     */
    void copy_node_recursive(BTNode *pNode, BTNode *pCopyNode);

    /**
     * @brief delete a node recursive version
     * @param BTNode *pNode, node to be deleted
     * @return void
     * @remarks
     */
    void delete_node_recursive(BTNode *pNode);

private:
    /*< root node of the tree */
    BTNode *m_pRoot;
    /*< number of node in the tree */
    size_t m_nSize;
};

/**
 * @brief test binary tree
 * @param
 * @return void
 * @remarks
 */
void binary_tree_test();

#endif // __BINARY_TREE_H__
