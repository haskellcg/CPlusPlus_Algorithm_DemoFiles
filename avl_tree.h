/**************************************************************************
 * author: haskellcg
 * date: 2020-11-27
 * description: avl tree data structure
 *************************************************************************/

#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include "binary_search_tree.h"
#include "common_types.h"

/**
 * @brief avl tree node
 */
class AVLTNode
{
public:
    /**
     * @brief default constructor
     */
    AVLTNode();

    /**
     * @brief destructor
     */
    ~AVLTNode();

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
     * @brief get key
     */
    uint32_t get_key() const;

    /**
     * @brief set key
     */
    void set_key(uint32_t nKey);

    /**
     * @brief get parent node link
     */
    AVLTNode *get_parent() const;

    /**
     * @brief set parent node link
     */
    void set_parent(AVLTNode *pParent);

    /**
     * @brief get left child node link
     */
    AVLTNode *get_left() const;

    /**
     * @brief set left child node link
     */
    void set_left(AVLTNode *pLeft);

    /**
     * @brief get right child node link
     */
    AVLTNode *get_right() const;

    /**
     * @brief set right child node link
     */
    void set_right(AVLTNode *pRight);

private:
    /*< height of the node */
    uint32_t m_nHeight;
    /*< key of the node */
    uint32_t m_nKey;
    /*< link to parent node */
    AVLTNode *m_pParent;
    /*< link to left child */
    AVLTNode *m_pLeft;
    /*< link to right child */
    AVLTNode *m_pRight;
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
class AVL_Tree: public Binary_Search_Tree<AVLTNode>
{
public:
    /**
     * @brief insert nKey to the tree
     * @param uint32_t nKey, key
     * @return AVLTNode *, the new node inserted,
     *                     NULL if nKey is already existed
     * @remarks
     */
    // AVLTNode *insert(uint32_t nKey);

protected:
    /**
     * @brief perform rotation when left left insertion
     * @param AVLTNode *pZNode, Z
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
    void rotation_on_left_left_insertion(AVLTNode *pZNode);

    /**
     * @brief perform rotation when left right insertion
     * @param AVLTNode *pZNode, Z
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
    void rotation_on_left_right_insertion(AVLTNode *pZNode);

    /**
     * @brief perform rotation when right right insertion
     * @param AVLTNode *pZNode, Z
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
    void rotation_on_right_right_insertion(AVLTNode *pZNode);

    /**
     * @brief perform rotation when right left insertion
     * @param AVLTNode *pZNode, Z
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
    void rotation_on_right_left_insertion(AVLTNode *pZNode);
    
    /**
     * @brief perform left rotation
     * @param AVLTNode *pZNode, Z
     * @return void
     * @remarks
     *              |                       |
     *              Z                       Y
     *             / \                     / \
     *            a   Y         =>        Z   c
     *               / \                 / \
     *              b   c               a   b
     */
    void left_rotation(AVLTNode *pZNode);

    /**
     * @brief perform right rotation
     * @param AVLTNode *pZNode, Z
     * @return void
     * @remarks
     *                |                    |
     *                Z                    Y
     *               / \                  / \
     *              Y   a       =>       b   Z
     *             / \                      / \
     *            b   c                    c   a
     */
    void right_rotation(AVLTNode *pZNode);

    /**
     * @brief rebalance the tree to restore its property
     * @param AVLTNode *pNode
     * @return void
     * @remarks
     */
    void rebalance(AVLTNode *pNode);
};

/**
 * @brief test avl tree structure
 */
void avl_tree_test();

#endif // __AVL_TREE_H__
