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

class Red_Black_Tree: public Binary_Search_Tree<RBTNode>
{
};

/**
 * @brief test red black tree data structure
 * @param
 * @return void
 * @remarks
 */
void red_black_tree_test();

#endif // __RED_BLACK_TREE_H__
