/**************************************************************************
 * author: haskellcg
 * date: 2020-11-27
 * description: avl tree data structure
 *************************************************************************/

#include "avl_tree.h"

AVLTNode::AVLTNode()
:   m_nHeight(1),
    m_nKey(MAX_UINT32),
    m_pParent(NULL),
    m_pLeft(NULL),
    m_pRight(NULL)
{
}

AVLTNode::~AVLTNode()
{
    m_nHeight = 1;
    m_nKey = MAX_UINT32;
    m_pParent = NULL;
    m_pLeft = NULL;
    m_pRight = NULL;
}

string AVLTNode::to_string() const
{
    return (std::to_string(m_nKey) + ":" + std::to_string(m_nHeight));
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

AVLTNode *AVL_Tree::insert(uint32_t nKey)
{
    AVLTNode *pNewNode = Binary_Search_Tree<AVLTNode>::insert(nKey);
    rebalance(pNewNode);
    return pNewNode;
}

void AVL_Tree::remove(AVLTNode *pNode)
{
    AVLTNode *pBalanceStartNode = get_rebalance_start(pNode);

    Binary_Search_Tree<AVLTNode>::remove(pNode);

    if (NULL != pBalanceStartNode){
        rebalance(pBalanceStartNode);
    }
}

AVLTNode *AVL_Tree::rotation_on_left_left_insertion(AVLTNode *pZNode)
{
    AVLTNode *pYNode = pZNode->get_left();

    right_rotation(pZNode);

    update_height(pZNode);
    update_height(pYNode);

    return pYNode;
}

AVLTNode *AVL_Tree::rotation_on_left_right_insertion(AVLTNode *pZNode)
{
    AVLTNode *pYNode = pZNode->get_left();
    AVLTNode *pXNode = pYNode->get_right();

    left_rotation(pYNode);
    right_rotation(pZNode);

    update_height(pZNode);
    update_height(pYNode);
    update_height(pXNode);

    return pXNode;
}

AVLTNode *AVL_Tree::rotation_on_right_right_insertion(AVLTNode *pZNode)
{
    AVLTNode *pYNode = pZNode->get_right();

    left_rotation(pZNode);

    update_height(pZNode);
    update_height(pYNode);

    return pYNode;
}

AVLTNode *AVL_Tree::rotation_on_right_left_insertion(AVLTNode *pZNode)
{
    AVLTNode *pYNode = pZNode->get_right();
    AVLTNode *pXNode = pYNode->get_left();

    right_rotation(pYNode);
    left_rotation(pZNode);

    update_height(pZNode);
    update_height(pYNode);
    update_height(pXNode);

    return pXNode;
}

uint32_t AVL_Tree::get_height(AVLTNode *pNode) const
{
    if (NULL != pNode){
        return pNode->get_height();
    } else {
        return 0;
    }
}

void AVL_Tree::update_height(AVLTNode *pNode)
{
    pNode->set_height(1 + max(get_height(pNode->get_left()),
                              get_height(pNode->get_right())));
}

void AVL_Tree::rebalance(AVLTNode *pNode)
{
    uint32_t *pInsertDirection = new uint32_t[get_height(m_pRoot) + 1];
    uint32_t nInsertDirectionIndex = 0;

    AVLTNode *pCurNode = pNode;
    AVLTNode *pParent = pCurNode->get_parent();
    while (NULL != pParent){
        update_height(pParent);

        if (pCurNode == pParent->get_left()){
            pInsertDirection[nInsertDirectionIndex++] = LEFT_INSERT;
        } else {
            pInsertDirection[nInsertDirectionIndex++] = RIGHT_INSERT;
        }

        uint32_t nHeightDifference = 0;
        uint32_t nLeftHeight = get_height(pParent->get_left());
        uint32_t nRightHeight = get_height(pParent->get_right());
        if (nLeftHeight >= nRightHeight){
            nHeightDifference = nLeftHeight - nRightHeight;
        } else {
            nHeightDifference = nRightHeight - nLeftHeight;
        }
        if (nHeightDifference > 1){
            if ((LEFT_INSERT == pInsertDirection[nInsertDirectionIndex - 1])
                && (LEFT_INSERT == pInsertDirection[nInsertDirectionIndex - 2])){
                pCurNode = rotation_on_left_left_insertion(pParent);
            } else if ((LEFT_INSERT == pInsertDirection[nInsertDirectionIndex - 1])
                       && (RIGHT_INSERT == pInsertDirection[nInsertDirectionIndex - 2])){
                pCurNode = rotation_on_left_right_insertion(pParent);
            } else if ((RIGHT_INSERT == pInsertDirection[nInsertDirectionIndex - 1])
                       && (LEFT_INSERT == pInsertDirection[nInsertDirectionIndex - 2])){
                pCurNode = rotation_on_right_left_insertion(pParent);
            } else{
                   /**
                   if ((RIGHT_INSERT == pInsertDirection[nInsertDirectionIndex - 1])
                       && (RIGHT_INSERT == pInsertDirection[nInsertDirectionIndex - 2]))
                    */
                pCurNode = rotation_on_right_right_insertion(pParent);
            }
        } else {
            pCurNode = pParent;
        }

        pParent = pCurNode->get_parent();
    }

    delete []pInsertDirection;
}

AVLTNode *AVL_Tree::get_rebalance_start(AVLTNode *pNode) const
{
    AVLTNode *pBalanceStartNode = NULL;
    if ((NULL != pNode->get_left()) && (NULL != pNode->get_right())){
        AVLTNode *pSuccessor = minimum(pNode->get_right());
        if (pSuccessor == pNode->get_right()){
            // situation 3.1
            pBalanceStartNode = maximum(pNode->get_left());
            if (NULL != pBalanceStartNode->get_left()){
                pBalanceStartNode = pBalanceStartNode->get_left();
            }
        } else {
            // situation 3.2
            pBalanceStartNode = maximum(pSuccessor->get_parent());
            if (NULL != pBalanceStartNode->get_left()){
                pBalanceStartNode = pBalanceStartNode->get_left();
            }
        }
    } else if (NULL != pNode->get_right()){
        // situation 2
        pBalanceStartNode = pNode->get_right();
    } else if (NULL != pNode->get_left()){
        // situation 2
        pBalanceStartNode = pNode->get_left();
    } else {
        // situation 1
        AVLTNode *pParent = pNode->get_parent();
        if (NULL != pParent){
            pBalanceStartNode = pParent;
            if (pNode == pParent->get_left()){
                pBalanceStartNode = maximum(pParent);
                if (NULL != pBalanceStartNode->get_left()){
                    pBalanceStartNode = pBalanceStartNode->get_left();
                }
            } else {
                pBalanceStartNode = minimum(pParent);
                if (NULL != pBalanceStartNode->get_right()){
                    pBalanceStartNode = pBalanceStartNode->get_right();
                }
            }
        } else {
            // means removing root node, no need to rebalance
        }
    }
    return pBalanceStartNode;
}

void avl_tree_test()
{
    print_highlight_msg(">>> Test avl tree:\n");
    uint32_t arrayInt[] = {10, 11, 12, 13, 14, 15, 5, 4, 3, 2, 1, 9, 8, 7, 6};
    vector<uint32_t> vecInt;
    vecInt.insert(vecInt.end(), begin(arrayInt), end(arrayInt));
    print_normal_msg(to_string(vecInt) + "\n");

    AVL_Tree oAVLTree;
    for (size_t i = 0; i < vecInt.size(); ++i){
        oAVLTree.insert(vecInt[i]);
    }
    print_warning_msg(oAVLTree.to_string() + "\n");

    print_normal_msg("deleting avl tree:\n");
    AVL_Tree oCpAVLTree(oAVLTree);
    for (size_t i = 0; i < vecInt.size(); ++i){
        AVLTNode *pRemoveNode = oCpAVLTree.search(vecInt[i]);
        oCpAVLTree.remove(pRemoveNode);
        delete pRemoveNode;
    }
    print_warning_msg(oCpAVLTree.to_string() + "\n");
}
