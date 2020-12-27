/**************************************************************************
 * author: haskellcg
 * date: 2020-12-02
 * description: red balck tree data structure
 *************************************************************************/

#include "red_black_tree.h"

RBTNode::RBTNode()
:   m_enumColor(RBTNODE_BLACK),
    m_nKey(MAX_UINT32),
    m_pParent(NULL),
    m_pLeft(NULL),
    m_pRight(NULL)
{
}

RBTNode::~RBTNode()
{
    m_enumColor = RBTNODE_BLACK;
    m_nKey = MAX_UINT32;
    m_pParent = NULL;
    m_pLeft = NULL;
    m_pRight = NULL;
}

string RBTNode::to_string() const
{
    ostringstream ossResult;
    ossResult << m_nKey << ":"
              << ((RBTNODE_RED == m_enumColor) ? "R" : "B");
    return ossResult.str();
}

RBTNode_Color RBTNode::get_color() const
{
    return m_enumColor;
}

void RBTNode::set_color(RBTNode_Color enumColor)
{
    m_enumColor = enumColor;
}

uint32_t RBTNode::get_key() const
{
    return m_nKey;
}

void RBTNode::set_key(uint32_t nKey)
{
    m_nKey = nKey;
}

RBTNode *RBTNode::get_parent() const
{
    return m_pParent;
}

void RBTNode::set_parent(RBTNode *pParent)
{
    m_pParent = pParent;
}

RBTNode *RBTNode::get_left() const
{
    return m_pLeft;
}

void RBTNode::set_left(RBTNode *pLeft)
{
    m_pLeft = pLeft;
}

RBTNode *RBTNode::get_right() const
{
    return m_pRight;
}

void RBTNode::set_right(RBTNode *pRight)
{
    m_pRight = pRight;
}

void red_black_tree_test()
{
    print_highlight_msg(">>> Test red balck tree:\n");

    uint32_t arrayInt[] = {10, 11, 12, 13, 14, 15, 5, 4, 3, 2, 1, 9, 8, 7, 6};
    vector<uint32_t> vecInt;
    vecInt.insert(vecInt.end(), begin(arrayInt), end(arrayInt));
    print_normal_msg(to_string(vecInt) + "\n");

    Red_Black_Tree oRedBlackTree;
    for (size_t i = 0; i < vecInt.size(); ++i){
        oRedBlackTree.insert(vecInt[i]);
        print_warning_msg(oRedBlackTree.to_string() + "\n");
    }
        
    print_error_msg("No test case yet.\n");
}
