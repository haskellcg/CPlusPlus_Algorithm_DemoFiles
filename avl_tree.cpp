/**************************************************************************
 * author: haskellcg
 * date: 2020-11-27
 * description: avl tree data structure
 *************************************************************************/

#include "avl_tree.h"

ATNode::ATNode()
:   BTNode(),
    m_nHeight(0)
{
}

ATNode::ATNode(uint32_t nData, BTNode *pParent, BTNode *pLeft, BTNode *pRight, uint32_t nHeight)
:   BTNode(nData, pParent, pLeft, pRight),
    m_nHeight(nHeight)
{
}

uint32_t ATNode::get_height() const
{
    return m_nHeight;
}

void ATNode::set_height(uint32_t nHeight)
{
    m_nHeight = nHeight;
}

void AVL_Tree::rotation_on_left_left_insertion(BTNode *pNodeZ)
{
    right_rotation(pNodeZ);
}

void AVL_Tree::rotation_on_left_right_insertion(BTNode *pNodeZ)
{
    left_rotation(pNodeZ->get_left());
    right_rotation(pNodeZ);
}

void AVL_Tree::rotation_on_right_right_insertion(BTNode *pNodeZ)
{
    left_rotation(pNodeZ);
}

void AVL_Tree::rotation_on_right_left_insertion(BTNode *pNodeZ)
{
    right_rotation(pNodeZ->get_right());
    left_rotation(pNodeZ);
}

void AVL_Tree::left_rotation(BTNode *pNodeZ)
{
    BTNode *pNodeY = pNodeZ->get_right();
    transplant(pNodeZ, pNodeY);

    BTNode *pNodeB = pNodeY->get_left();
    pNodeY->set_left(pNodeZ);
    pNodeZ->set_parent(pNodeY);
    if (NULL != pNodeB){
        pNodeB->set_parent(pNodeZ);
        pNodeZ->set_right(pNodeB);
    }
}

void AVL_Tree::right_rotation(BTNode *pNodeZ)
{
    BTNode *pNodeY = pNodeZ->get_left();
    transplant(pNodeZ, pNodeY);

    BTNode *pNodeC = pNodeY->get_right();
    pNodeY->set_right(pNodeZ);
    pNodeZ->set_parent(pNodeY);
    if (NULL != pNodeC){
        pNodeZ->set_left(pNodeC);
        pNodeC->set_parent(pNodeZ);
    }
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
    }
    print_warning_msg(oAVLTree.to_string() + "\n");
    print_error_msg("No test case yet.\n");
}
