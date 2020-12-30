/**************************************************************************
 * author: haskellcg
 * date: 2020-12-02
 * description: red balck tree data structure
 *************************************************************************/

#include "red_black_tree.h"

RBTNode::RBTNode()
:   m_enumColor(RBTNODE_RED),
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

RBTNode *Red_Black_Tree::insert(uint32_t nKey)
{
    RBTNode *pNewNode = Binary_Search_Tree<RBTNode>::insert(nKey);
    insert_fixup(pNewNode);
    return pNewNode;
}

void Red_Black_Tree::remove(RBTNode *pNode)
{
    Binary_Search_Tree<RBTNode>::remove(pNode);
}

void Red_Black_Tree::insert_fixup(RBTNode *pNode)
{
    RBTNode *pCurNode = pNode;
    RBTNode *pParent = pCurNode->get_parent();
    while ((NULL != pParent) && (RBTNODE_RED == pParent->get_color())){

        if (pParent == pParent->get_parent()->get_left()){
            RBTNode *pUncle = pParent->get_parent()->get_right();

            if ((NULL != pUncle) && (RBTNODE_RED == pUncle->get_color())){
                pParent->set_color(RBTNODE_BLACK);
                pUncle->set_color(RBTNODE_BLACK);
                pParent->get_parent()->set_color(RBTNODE_RED);
                pCurNode = pParent->get_parent();
                pParent = pCurNode->get_parent();
            } else{
                if (pCurNode == pParent->get_right()){
                    pCurNode = pParent;
                    left_rotation(pCurNode);
                    pParent = pCurNode->get_parent();
                }
                pParent->set_color(RBTNODE_BLACK);
                pParent->get_parent()->set_color(RBTNODE_RED);
                right_rotation(pParent->get_parent());
            }
        } else {
            RBTNode *pUncle = pParent->get_parent()->get_left();

            if ((NULL != pUncle) && (RBTNODE_RED == pUncle->get_color())){
                pParent->set_color(RBTNODE_BLACK);
                pUncle->set_color(RBTNODE_BLACK);
                pParent->get_parent()->set_color(RBTNODE_RED);
                pCurNode = pParent->get_parent();
                pParent = pCurNode->get_parent();
            } else {
                if (pCurNode == pParent->get_left()){
                    pCurNode = pParent;
                    right_rotation(pCurNode);
                    pParent = pCurNode->get_parent();
                }
                pParent->set_color(RBTNODE_BLACK);
                pParent->get_parent()->set_color(RBTNODE_RED);
                left_rotation(pParent->get_parent());
            }
        }
    }

    m_pRoot->set_color(RBTNODE_BLACK);
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

    for (size_t i = 0; i < vecInt.size(); ++i){
        RBTNode *pRemoveNode = oRedBlackTree.search(vecInt[i]);
        if (NULL != pRemoveNode){
            oRedBlackTree.remove(pRemoveNode);
            delete pRemoveNode;
            // print_warning_msg(oRedBlackTree.to_string() + "\n");
        } else {
            print_error_msg("remove key: " + std::to_string(vecInt[i]) + " failed.\n");
        }
    }
}
