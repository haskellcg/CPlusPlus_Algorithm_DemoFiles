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
     * @brief destructor
     */
    virtual ~ATNode();

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

    /**
     * @brief copy major information from pNode
     * @param BTNode *pNode
     * @return void
     * @remarks
     */
    virtual void copy_major_info(BTNode *pNode);

private:
    /*< height of the node */
    uint32_t m_nHeight;
};

/**
 * @brief avl tree
 * @remarks
 *          The AVL tree is named after its two Soviet inventors, 
 *          Georgy Adelson-Velsky and Evgenii Landis, who published 
 *          it in their 1962 paper "An algorithm for the organization
 *          of information"
 *
 *          In an AVL tree, the heights of the two child subtrees of
 *          any node differ by at most one; if at any time they differ
 *          by more than one, rebalancing is done to restore this
 *          property
 */
class AVL_Tree: public Binary_Tree
{
public:
    /**
     * @brief default constructor
     */
    AVL_Tree();

    /**
     * @brief copy constructor
     */
    AVL_Tree(const AVL_Tree &oOtherAVLTree);

    /**
     * @brief destrcutor
     */
    virtual ~AVL_Tree();

    /**
     * @brief insert nKey to the tree
     * @param uint32_t nKey, key
     * @return ATNode *, the new node inserted,
     *                   NULL if nKey is already existed
     * @remarks
     */
    //ATNode *insert(uint32_t nKey);

protected:
    /**
     * @brief perform rotation when left left insertion
     * @param BTNode *pNodeZ, Z
     * @return void
     * @remarks
     *              |                               |
     *              Z                               Y
     *             / \                             / \
     *            Y   a                           /   \
     *           / \              =>             /     \
     *          X   b                           X       Z
     *         / \                             / \     / \
     *        c   d                           c   d   b   a
     */
    void rotation_on_left_left_insertion(BTNode *pNodeZ);

    /**
     * @brief perform rotation when left right insertion
     * @param BTNode *pNodeZ, Z
     * @return void
     * @remarks
     *              |               |              |
     *              Z               Z              X 
     *             / \             / \            / \
     *            Y   a           X   a          /   \
     *           / \      =>     / \     =>     /     \
     *          b   X           Y   d          Y       Z
     *             / \         / \            / \     / \
     *            c   d       b   c          b   c   d   a
     */
    void rotation_on_left_right_insertion(BTNode *pNodeZ);

    /**
     * @brief perform rotation when right right insertion
     * @param BTNode *pNodeZ, Z
     * @return void
     * @remarks
     *          |                                 |
     *          Z                                 Y
     *         / \                               / \
     *        a   Y                             /   \
     *           / \              =>           /     \
     *          b   X                         Z       X
     *             / \                       / \     / \
     *            c   d                     a   b   c   d
     */
    void rotation_on_right_right_insertion(BTNode *pNodeZ);

    /**
     * @brief perform rotation when right left insertion
     * @param BTNode *pNodeZ, Z
     * @return void
     * @remarks
     *            |             |                 |
     *            Z             Z                 X 
     *           / \           / \               / \
     *          a   Y         a   X             /   \
     *             / \    =>     / \     =>    /     \
     *            X   b         c   Y         Z       Y
     *           / \               / \       / \     / \
     *          c   d             d   b     a   c   d   b
     */
    void rotation_on_right_left_insertion(BTNode *pNodeZ);
    
    /**
     * @brief perform left rotation
     * @param BTNode *pNodeZ, Z
     * @return void
     * @remarks
     *              |                       |
     *              Z                       Y
     *             / \                     / \
     *            a   Y         =>        Z   c
     *               / \                 / \
     *              b   c               a   b
     */
    void left_rotation(BTNode *pNodeZ);

    /**
     * @brief perform right rotation
     * @param BTNode *pNodeZ, Z
     * @return void
     * @remarks
     *                |                    |
     *                Z                    Y
     *               / \                  / \
     *              Y   a       =>       b   Z
     *             / \                      / \
     *            b   c                    c   a
     */
    void right_rotation(BTNode *pNodeZ);
    
    /**
     * @brief create node according to different tree
     * @param
     * @return BTNode *, new node
     * @remarks
     */
    virtual BTNode *create_node() const;
};

/**
 * @brief test avl tree structure
 */
void avl_tree_test();

#endif // __AVL_TREE_H__
