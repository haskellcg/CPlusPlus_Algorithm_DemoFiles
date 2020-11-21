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
     *                                             8
     *                                             |
     *                               ------------------------ 
     *                              |                        |
     *                              5                       10
     *                              |                        |
     *                -------------------                --------- 
     *               |                   |              |         |
     *               2                   6              9        11
     *               |                   |
     *           ---------                ---- 
     *          |         |                   |
     *          1         3                   7
     *                    |
     *                     ---- 
     *                         |
     *                         4
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

    /** 
     * @brief insert nData as BTNode to binary tree
     * @param uint32_t nData, data
     * @return BTNode *, null if nData already in the tree,
     *                   or node created
     * @remarks
     */
    BTNode *insert(uint32_t nData);

    // TODO: add more methods

private:
    /**
     * @brief copy pNode children nodes to pCopyNode
     * @param BTNode *pNode, current node
     * @param BTNode *pCopyNode, copy node
     * @return void
     * @remarks
     */
    static void copy_node_recursive(BTNode *pNode, BTNode *pCopyNode);

    /**
     * @brief delete a node recursive version
     * @param BTNode *pNode, node to be deleted
     * @return void
     * @remarks
     */
    static void delete_node_recursive(BTNode *pNode);

    /**
     * @brief get the node width coefficient
     * @param BTNode *pNode,
     * @return size_t, width coefficient
     * @remarks
     *                  x(2 + 1 + 2 = 5)
     *                  |
     *          ------------------
     *          |                |
     *          x(2)             x(1)
     *          |                |
     *      ---------            ------
     *      |       |                 |
     *      x(0)    x(0)              x(0)
     */
    static size_t node_width_coefficient(BTNode *pNode);

    /**
     * @brief get node position coefficient
     * @param BTNode *pNode,
     * @return size_t, position coefficient
     * @remarks
     *                  x(3)
     *                  |
     *          ------------------
     *          |                |
     *          x(1)             x(4)
     *          |                |
     *      ---------            ------
     *      |       |                 |
     *      x(0)    x(2)              x(5)
     */
    static size_t node_position_coefficient(BTNode *pNode);

    /**
     * @brief adjust string to fit display string, like:
     *        (abcdefg, 67) => (abcde67)
     * @param const string &strLine, string
     * @param const string &strDisplay, string need to display
     * @return string
     * @remarks
     */
    static string adjust_string(const string &strLine, const string &strDisplay);

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
