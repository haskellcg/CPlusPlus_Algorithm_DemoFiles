/**************************************************************************
 * author: haskellcg
 * date: 2020-11-27
 * description: avl tree data structure
 *************************************************************************/

#include "avl_tree.h"

AVLTNode::AVLTNode()
:   m_nHeight(0),
    m_nKey(MAX_UINT32),
    m_pParent(NULL),
    m_pLeft(NULL),
    m_pRight(NULL)
{
}

AVLTNode::~AVLTNode()
{
    m_nHeight = 0;
    m_nKey = MAX_UINT32;
    m_pParent = NULL;
    m_pLeft = NULL;
    m_pRight = NULL;
}

uint32_t AVLTNode::get_height() const
{
    return m_nHeight;
}

void AVLTNode::set_height(uint32_t nHeight)
{
    m_nHeight = nHeight;
}

uint32_t AVLTNode::get_key() const
{
    return m_nKey;
}

void AVLTNode::set_key(uint32_t nKey)
{
    m_nKey = nKey;
}

AVLTNode *AVLTNode::get_parent() const
{
    return m_pParent;
}

void AVLTNode::set_parent(AVLTNode *pParent)
{
    m_pParent = pParent;
}

AVLTNode *AVLTNode::get_left() const
{
    return m_pLeft;
}

void AVLTNode::set_left(AVLTNode *pLeft)
{
    m_pLeft = pLeft;
}

AVLTNode *AVLTNode::get_right() const
{
    return m_pRight;
}

void AVLTNode::set_right(AVLTNode *pRight)
{
    m_pRight = pRight;
}

void AVL_Tree::rotation_on_left_left_insertion(AVLTNode *pZNode)
{
    right_rotation(pZNode);
}

void AVL_Tree::rotation_on_left_right_insertion(AVLTNode *pZNode)
{
    left_rotation(pZNode->get_left());
    right_rotation(pZNode);
}

void AVL_Tree::rotation_on_right_right_insertion(AVLTNode *pZNode)
{
    left_rotation(pZNode);
}

void AVL_Tree::rotation_on_right_left_insertion(AVLTNode *pZNode)
{
    right_rotation(pZNode->get_right());
    left_rotation(pZNode);
}

void AVL_Tree::left_rotation(AVLTNode *pZNode)
{
    AVLTNode *pYNode = pZNode->get_right();
    transplant(pZNode, pYNode);

    AVLTNode *pBNode = pYNode->get_left();
    pYNode->set_left(pZNode);
    pZNode->set_parent(pYNode);
    if (NULL != pBNode){
        pBNode->set_parent(pZNode);
        pZNode->set_right(pBNode);
    }
}

void AVL_Tree::right_rotation(AVLTNode *pZNode)
{
    AVLTNode *pYNode = pZNode->get_left();
    transplant(pZNode, pYNode);

    AVLTNode *pCNode = pYNode->get_right();
    pYNode->set_right(pZNode);
    pZNode->set_parent(pYNode);
    if (NULL != pCNode){
        pZNode->set_left(pCNode);
        pCNode->set_parent(pZNode);
    }
}

void AVL_Tree::rebalance(AVLTNode *pNode)
{
    delete pNode;
}

void avl_tree_test()
{
    print_highlight_msg(">>> Test avl tree:\n");
    uint32_t arrayInt[] = {10, 11, 12, 13, 14, 15/*, 5, 4, 3, 2, 1, 9, 6, 8, 7*/};
    vector<uint32_t> vecInt;
    vecInt.insert(vecInt.end(), begin(arrayInt), end(arrayInt));

    AVL_Tree oAVLTree;
    for (size_t i = 0; i < vecInt.size(); ++i){
        oAVLTree.insert(vecInt[i]);
        print_warning_msg(oAVLTree.to_string() + "\n");
    }

    AVL_Tree oOtherAVLTree(oAVLTree);

    print_error_msg("No test case yet.\n");
}
