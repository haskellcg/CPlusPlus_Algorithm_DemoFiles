/**************************************************************************
 * author: haskellcg
 * date: 2020-11-27
 * description: avl tree data structure
 *************************************************************************/

#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include "binary_search_tree.h"
#include "common_types.h"

#define LEFT_INSERT 69
#define RIGHT_INSERT 96

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
     * @brief to string
     * @param
     * @return string
     * @remarks
     *          in order to show node in the tree perfectly,
     *          node should only show important information,
     *          and should be less then 6 characters
     */
    string to_string() const;

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
 *          by more than one, rebalance is done to restore this
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
    AVLTNode *insert(uint32_t nKey);

    /**
     * @brief remove pNode from avl tree
     * @param AVLTNode *pNode,
     * @return void
     * @remarks
     *          pNode should be in the tree
     */
    void remove(AVLTNode *pNode);

protected:
    /**
     * @brief perform rotation when left left insertion
     * @param AVLTNode *pZNode, Z
     * @return AVLTNode *, new parent node
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
    AVLTNode *rotation_on_left_left_insertion(AVLTNode *pZNode);

    /**
     * @brief perform rotation when left right insertion
     * @param AVLTNode *pZNode, Z
     * @return AVLTNode *, new parent node
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
    AVLTNode *rotation_on_left_right_insertion(AVLTNode *pZNode);

    /**
     * @brief perform rotation when right right insertion
     * @param AVLTNode *pZNode, Z
     * @return AVLTNode *, new parent node
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
    AVLTNode *rotation_on_right_right_insertion(AVLTNode *pZNode);

    /**
     * @brief perform rotation when right left insertion
     * @param AVLTNode *pZNode, Z
     * @return AVLTNode *, new parent node
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
    AVLTNode *rotation_on_right_left_insertion(AVLTNode *pZNode);

    /**
     * @brief get height of pNode
     * @param AVLTNode *pNode, could be NULL
     * @return uint32_t, height of pNode,
     *                   0 if pNode is NULL
     * @remarks
     */
    uint32_t get_height(AVLTNode *pNode) const;

    /**
     * @brief update height of the pNode
     * @param AVLTNode *pNode
     * @return void
     * @remarks
     */
    void update_height(AVLTNode *pNode);

    /**
     * @brief rebalance the tree to restore its property
     * @param AVLTNode *pNode
     * @return void
     * @remarks
     */
    void rebalance(AVLTNode *pNode);

    /**
     * @brief get rebalance start
     * @param AVLTNode *pNode,
     * @return AVLTNode *,
     * @remarks
     *          delete Z, find the ubalanced point to
     *          call rebalance function, accoring to how
     *          to remove
     * 
     *          if remove a node from a tree, there are 3
     *          situation we need deal with
     *
     *          1. node Z have no child nodes, then we need
     *             start from Z's sibling
     *                Y                   Y
     *               / \                 / \
     *              X   Z     or        Z   X
     *             / \                     / \
     *            A   B                   A   B
     *            A or B could be NULL
     *
     *          2. node Z have only 1 child node, then we start
     *             child tree
     *               Z                   Z
     *                \      or         /
     *                 Y               Y
     *
     *          3. node Z have both child nodes, then we replace
     *             Z with its successor S, check S is Z's right
     *             or not
     *                 Z                   Z
     *                / \                 / \
     *               Y   S               Y   S
     *              / \   \             / \
     *             A   B   C    or     A   B
     *            / \ / \
     *           D  E F  G
     *           3.1 if S is Z's right, go to left tree, and
     *               get at least 2 level
     *
     *                Y
     *               / \
     *              S   X
     *               \ / \
     *               A B  C
     *          3.2 if S is not Z's right, then go to S's left
     *              sibling tree
     */
    AVLTNode *get_rebalance_start(AVLTNode *pNode) const;
};

/**
 * @brief test avl tree structure
 */
void avl_tree_test();

#endif // __AVL_TREE_H__
