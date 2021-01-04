/**************************************************************************
 * author: haskellcg
 * date: 2020-12-02
 * description: red balck tree data structure
 *************************************************************************/

#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__

#include "binary_search_tree.h"
#include "common_types.h"

/**
 * @brief Red_Black_Tree Node color
 */
enum RBTNode_Color
{
    RBTNODE_RED,
    RBTNODE_BLACK
};

/**
 * @brief Red_Black_Tree Node
 */
class RBTNode
{
public:
    /**
     * @brief default constructor
     */
    RBTNode();

    /**
     * @brief destructor
     */
    ~RBTNode();
    
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
     * @brief get node color
     */
    RBTNode_Color get_color() const;

    /**
     * @brief set node color
     */
    void set_color(RBTNode_Color enumColor);

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
    RBTNode *get_parent() const;

    /**
     * @brief set parent node link
     */
    void set_parent(RBTNode *pParent);

    /**
     * @brief get left child node link
     */
    RBTNode *get_left() const;

    /**
     * @brief set left child node link
     */
    void set_left(RBTNode *pLeft);

    /**
     * @brief get right child node link
     */
    RBTNode *get_right() const;

    /**
     * @brief set right child node link
     */
    void set_right(RBTNode *pRight);

private:
    /*< color of the node */
    RBTNode_Color m_enumColor;
    /*< key of the node */
    uint32_t m_nKey;
    /*< link to parent node */
    RBTNode *m_pParent;
    /*< link to left child */
    RBTNode *m_pLeft;
    /*< link to right child */
    RBTNode *m_pRight;
};

/**
 * @brief red black tree properties:
 *          1. every node has a color either red or black
 *          2. the root of tree is always black
 *          3. there are no two adjacent red nodes (a red node cannot have a red parent or red child)
 *          4. every path from a node (include root) to any of its descendant NULL node has the same number of black node
 *
 *          Visual of insertion and deletion: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
 *          Skip Lists: https://web.archive.org/web/20081018112547/http://www.cs.auckland.ac.nz/software/AlgAnim/niemann/s_skl.htm
 *          Skip Lists Introduction: https://web.archive.org/web/20081019102355/http://www.cs.auckland.ac.nz/software/AlgAnim/niemann/s_skip.pdf
 *          Redis SortedSet by Skip List: https://blog.csdn.net/yanshuanche3765/article/details/82121043
 *          Splay Tree: https://en.wikipedia.org/wiki/Splay_tree
 *          Scapegoat Tree: https://en.wikipedia.org/wiki/Scapegoat_tree
 *          Self Balancing Binary Search Trees: https://www.geeksforgeeks.org/self-balancing-binary-search-trees-comparisons/
 *          AA Tree: https://en.wikipedia.org/wiki/AA_tree
 *          Treap: https://en.wikipedia.org/wiki/Treap
 *          Treap, Randomized Search Tree: http://faculty.washington.edu/aragon/pubs/rst89.pdf
 *          Treap Visual Introduction: https://medium.com/carpanese/a-visual-introduction-to-treap-data-structure-part-1-6196d6cc12ee
 *          A Visual Introduction to Centroid Decomposition: https://medium.com/carpanese/an-illustrated-introduction-to-centroid-decomposition-8c1989d53308
 *
 *          Variation:
 *              1. add size attribute: x.size = x.left.size + x.right.size + 1
 *              2. interval tree: overlap --  ((i.low <= j.high) && (j.low <= i.high))
 *                                i.max   --  max value of the subtree of i as root
 *                                check: https://iq.opengenus.org/interval-tree/
 */
class Red_Black_Tree: public Binary_Search_Tree<RBTNode>
{
public:
    /** 
     * @brief insert nKey as RBTNode to red black tree
     * @param uint32_t nKey, key
     * @return RBTNode *, null if nKey already in the tree,
     *                    or node created
     * @remarks
     */
    RBTNode *insert(uint32_t nKey);

    /**
     * @brief remove pNode from red black tree
     * @param RBTNode *pNode,
     * @return void
     * @remarks
     *          pNode must be in the tree
     */
    void remove(RBTNode *pNode);

private:
    /**
     * @brief fixup the attribute if pNode break them after insert
     * @param RBTNode *pNode, new node
     * @return void
     * @remarks
     *          insert explain: https://www.geeksforgeeks.org/red-black-tree-set-2-insert/
     *
     *          1. parent and uncle nodes are all red, only do re-coloring
     *                  G:B
     *                 /   \
     *              P:R     U:R
     *             /
     *          C:R
     *
     *          2. parent is red, but uncle is black, do LL rotation and re-coloring
     *                  G:B
     *                 /   \
     *              P:R     U:B
     *             /
     *          C:R
     *
     *          3. parent is red, but uncle is black, do LR rotation and re-coloring
     *                  G:B
     *                 /   \
     *              P:R     U:B
     *                 \
     *                  C:R
     *
     *          4./5./6. same as above, but P is G.right
     */
    void insert_fixup(RBTNode *pNode);

    /**
     * @brief fixup the attribute if pNode break them after remove
     * @param RBTNode *pRemovedNodeChild, child of the removed node
     * @param RBTNode *pRemovedNodeParent, parent of the removed node
     * @return void
     * @remarks
     *          pNode could be NULL
     *
     *          remove explain: https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/?ref=lbp
     *
     *          0. unlike the book, if pRemovedNodeChild is NULL, do rotation with pRemovedNodeParent
     *              P:RB
     *                  \
     *                   B:RB
     *
     *          1. brother is red, do re-coloring and left rotation, and check 2./3./4. situations
     *              P:B
     *             /   \
     *          C:B     B:R
     *
     *          2. brother is black, and both all his children is black, do recoloring and make C = P
     *              P:R
     *             /   \
     *          C:B     B:B
     *                 /   \
     *             BL:B     BR:B
     *
     *          3. brother is black, and only his right child is black, do recoloring and rotation
     *              P:R
     *             /   \
     *          C:B     B:B
     *                 /   \
     *             BL:R     BR:B
     *
     *          3. brother is black, and only his left child is black, do recoloring and rotation
     *              P:R
     *             /   \
     *          C:B     B:B
     *                 /   \
     *             BL:B     BR:R
     */
    void remove_fixup(RBTNode *pRemovedNodeChild, RBTNode *pRemovedNodeParent);
};

/**
 * @brief test red black tree data structure
 * @param
 * @return void
 * @remarks
 */
void red_black_tree_test();

#endif // __RED_BLACK_TREE_H__
