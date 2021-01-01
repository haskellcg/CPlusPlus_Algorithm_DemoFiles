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
    RBTNode_Color enumRemovedNodeColor = pNode->get_color();
    RBTNode *pRemovedNodeParent = pNode->get_parent();
    RBTNode *pRemovedNodeChild = NULL;

    if (NULL == pNode->get_left()){
        pRemovedNodeChild = pNode->get_right();
        transplant(pNode, pRemovedNodeChild);
        pNode->set_right(NULL);
    } else if (NULL == pNode->get_right()){
        pRemovedNodeChild = pNode->get_left();
        transplant(pNode, pRemovedNodeChild);
        pNode->set_left(NULL);
    } else {
        RBTNode *pSuccessor = minimum(pNode->get_right());

        enumRemovedNodeColor = pSuccessor->get_color();
        pRemovedNodeParent = pSuccessor->get_parent();
        pRemovedNodeChild = pSuccessor->get_right();

        if (pSuccessor != pNode->get_right()){
            transplant(pSuccessor, pSuccessor->get_right());
            pSuccessor->set_right(pNode->get_right());
            pNode->get_right()->set_parent(pSuccessor);
        } else {
            pRemovedNodeParent = pSuccessor;
        }
        transplant(pNode, pSuccessor);
        pNode->set_right(NULL);
        pSuccessor->set_left(pNode->get_left());
        pNode->get_left()->set_parent(pSuccessor);
        pNode->set_left(NULL);
        pSuccessor->set_color(pNode->get_color());
        pNode->set_color(RBTNODE_RED);
    }
    --m_nSize;

    if (RBTNODE_BLACK == enumRemovedNodeColor){
        remove_fixup(pRemovedNodeChild, pRemovedNodeParent);
    }
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

void Red_Black_Tree::remove_fixup(RBTNode *pRemovedNodeChild, RBTNode *pRemovedNodeParent)
{
    if (NULL == pRemovedNodeParent){
        return;
    }

    RBTNode *pCurNode = pRemovedNodeChild;
    while ((m_pRoot != pCurNode) && ((NULL == pCurNode) || (RBTNODE_BLACK == pCurNode->get_color()))){

        RBTNode *pParent = NULL;
        if (NULL != pCurNode){
            pParent = pCurNode->get_parent();
        } else {
            pParent = pRemovedNodeParent;
        }

        if ((pCurNode == pParent->get_left()) || ((NULL == pCurNode) && (NULL != pParent->get_right()))){

            RBTNode *pBrotherNode = pParent->get_right();
            if (RBTNODE_RED == pBrotherNode->get_color()){
                pBrotherNode->set_color(RBTNODE_BLACK);
                pParent->set_color(RBTNODE_RED);
                left_rotation(pParent);
                pBrotherNode = pParent->get_right();
            }
            if (((NULL == pBrotherNode->get_left()) || (RBTNODE_BLACK == pBrotherNode->get_left()->get_color()))
                && ((NULL == pBrotherNode->get_right()) || (RBTNODE_BLACK == pBrotherNode->get_right()->get_color()))){
                pBrotherNode->set_color(RBTNODE_RED);
                pCurNode = pParent;
                pParent = pCurNode->get_parent();
            } else {
                if ((NULL == pBrotherNode->get_right()) || (RBTNODE_BLACK == pBrotherNode->get_right()->get_color())){
                    pBrotherNode->get_left()->set_color(RBTNODE_BLACK);
                    pBrotherNode->set_color(RBTNODE_RED);
                    right_rotation(pBrotherNode);
                    pBrotherNode = pParent->get_right();
                }
                pBrotherNode->set_color(pParent->get_color());
                pParent->set_color(RBTNODE_BLACK);
                pBrotherNode->get_right()->set_color(RBTNODE_BLACK);
                left_rotation(pParent);
                pCurNode = m_pRoot;
                pParent = pCurNode->get_parent();
            }
        } else {

            RBTNode *pBrotherNode = pParent->get_left();
            if ((NULL != pBrotherNode) && (RBTNODE_RED == pBrotherNode->get_color())){
                pBrotherNode->set_color(RBTNODE_BLACK);
                pParent->set_color(RBTNODE_RED);
                right_rotation(pParent);
                pBrotherNode = pParent->get_left();
            }
            if (((NULL == pBrotherNode->get_left()) || (RBTNODE_BLACK == pBrotherNode->get_left()->get_color()))
                && ((NULL == pBrotherNode->get_right()) || (RBTNODE_BLACK == pBrotherNode->get_right()->get_color()))){
                pBrotherNode->set_color(RBTNODE_RED);
                pCurNode = pParent;
                pParent = pCurNode->get_parent();
            } else {
                if ((NULL == pBrotherNode->get_left()) || (RBTNODE_BLACK == pBrotherNode->get_left()->get_color())){
                    pBrotherNode->get_right()->set_color(RBTNODE_BLACK);
                    pBrotherNode->set_color(RBTNODE_RED);
                    left_rotation(pBrotherNode);
                    pBrotherNode = pParent->get_left();
                }
                pBrotherNode->set_color(pParent->get_color());
                pParent->set_color(RBTNODE_BLACK);
                pBrotherNode->get_left()->set_color(RBTNODE_BLACK);
                right_rotation(pParent);
                pCurNode = m_pRoot;
                pParent = pCurNode->get_parent();
            }
        }
    }

    pCurNode->set_color(RBTNODE_BLACK);
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
        // print_warning_msg(oRedBlackTree.to_string() + "\n");
    }
    print_warning_msg(oRedBlackTree.to_string() + "\n");

    for (size_t i = 0; i < vecInt.size(); ++i){
        // print_error_msg("removing key :" + std::to_string(vecInt[i]) + "\n");
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
