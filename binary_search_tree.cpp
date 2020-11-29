/**************************************************************************
 * author: haskellcg
 * date: 2020-11-18
 * description: binary search tree data structure
 *************************************************************************/

#include "binary_search_tree.h"

BSTNode::BSTNode()
:   m_nKey(MAX_UINT32),
    m_pParent(NULL),
    m_pLeft(NULL),
    m_pRight(NULL)
{
}

BSTNode::~BSTNode()
{
    m_nKey = MAX_UINT32;
    m_pParent = NULL;
    m_pLeft = NULL;
    m_pRight = NULL;
}

uint32_t BSTNode::get_key() const
{
    return m_nKey;
}

void BSTNode::set_key(uint32_t nKey)
{
    m_nKey = nKey;
}

BSTNode *BSTNode::get_parent() const
{
    return m_pParent;
}

void BSTNode::set_parent(BSTNode *pParent)
{
    m_pParent = pParent;
}

BSTNode *BSTNode::get_left() const
{
    return m_pLeft;
}

void BSTNode::set_left(BSTNode *pLeft)
{
    m_pLeft = pLeft;
}

BSTNode *BSTNode::get_right() const
{
    return m_pRight;
}

void BSTNode::set_right(BSTNode *pRight)
{
    m_pRight = pRight;
}

void binary_search_tree_test()
{
    print_highlight_msg(">>> Test binary search tree:\n");

    uint32_t arrayInt[] = {8, 5, 10, 2, 6, 9, 11, 7, 3, 1, 4};
    vector<uint32_t> vecInt;
    vecInt.insert(vecInt.begin(), begin(arrayInt), end(arrayInt));
    print_normal_msg(to_string(vecInt) + "\n");

    Binary_Search_Tree<BSTNode> oBSTree;
    for (size_t i = 0; i < vecInt.size(); ++i){
        if(NULL == oBSTree.insert(vecInt[i])){
            print_warning_msg(std::to_string(vecInt[i]) + " already exist!\n");
        }
    }
    print_warning_msg(oBSTree.to_string() + "\n");

    if ("[  1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11]" == to_string(oBSTree.inorder_tree_walk())){
        print_correct_msg("inorder tree walk correct.\n");
    } else {
        print_error_msg("inorder tree walk wrong.\n");
    }

    if ("[  8,   5,   2,   1,   3,   4,   6,   7,  10,   9,  11]" == to_string(oBSTree.preorder_tree_walk())){
        print_correct_msg("preorder tree walk correct.\n");
    } else {
        print_error_msg("preorder tree walk wrong.\n");
    }

    if ("[  1,   4,   3,   2,   7,   6,   5,   9,  11,  10,   8]" == to_string(oBSTree.postorder_tree_walk())){
        print_correct_msg("postorder tree walk correct.\n");
    } else {
        print_error_msg("postorder tree walk wrong.\n");
    }

    if ("[  1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11]" == to_string(oBSTree.inorder_tree_walk_iterative())){
        print_correct_msg("inorder tree walk iterative correct.\n");
    } else {
        print_error_msg("inorder tree walk iterative wrong.\n");
    }

    if ("[  8,   5,   2,   1,   3,   4,   6,   7,  10,   9,  11]" == to_string(oBSTree.preorder_tree_walk_iterative())){
        print_correct_msg("preorder tree walk iterative correct.\n");
    } else {
        print_error_msg("preorder tree walk iterative wrong.\n");
    }

    if ("[  1,   4,   3,   2,   7,   6,   5,   9,  11,  10,   8]" == to_string(oBSTree.postorder_tree_walk_iterative())){
        print_correct_msg("postorder tree walk iterative correct.\n");
    } else {
        print_error_msg("postorder tree walk iterative wrong.\n");
    }

    if ("[  1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11]" == to_string(oBSTree.inorder_tree_walk_morris())){
        print_correct_msg("inorder tree walk morris correct.\n");
    } else {
        print_error_msg("inorder tree walk morris wrong.\n");
    }

    if ("[  8,   5,   2,   1,   3,   4,   6,   7,  10,   9,  11]" == to_string(oBSTree.preorder_tree_walk_morris())){
        print_correct_msg("preorder tree walk morris correct.\n");
    } else {
        print_error_msg("preorder tree walk morris wrong.\n");
    }

    if ("[  1,   4,   3,   2,   7,   6,   5,   9,  11,  10,   8]" == to_string(oBSTree.postorder_tree_walk_morris())){
        print_correct_msg("postorder tree walk morris correct.\n");
    } else {
        print_error_msg("postorder tree walk morris wrong.\n");
    }

    BSTNode *pMaximumNode = oBSTree.maximum();
    if ((NULL != pMaximumNode) && (11 == pMaximumNode->get_key())){
        print_correct_msg("maximum node correct.\n");
    } else {
        print_error_msg("maximum node wrong.\n");
    }

    BSTNode *pMinimumNode = oBSTree.minimum();
    if ((NULL != pMinimumNode) && (1 == pMinimumNode->get_key())){
        print_correct_msg("minimum node correct.\n");
    } else {
        print_error_msg("minimum node wrong.\n");
    }

    BSTNode *p6Node = oBSTree.search(6);
    if ((NULL != p6Node) && (6 == p6Node->get_key())){
        print_correct_msg("search 6 correct.\n");

        BSTNode *p6SuccessorNode = oBSTree.successor(p6Node);
        if ((NULL != p6SuccessorNode) && (7 == p6SuccessorNode->get_key())){
            print_correct_msg("find correct 6'successor.\n");
        } else {
            print_error_msg("can't find 6'successor.\n");
        }
        BSTNode *p6PredecessorNode = oBSTree.predecessor(p6Node);
        if ((NULL != p6PredecessorNode) && (5 == p6PredecessorNode->get_key())){
            print_correct_msg("find correct 6'predecessor.\n");
        } else {
            print_error_msg("can't find 6'predecessor.\n");
        }
    } else {
        print_error_msg("can't find 6 and no successor/predecessor is tested.\n");
    }

    for (size_t i = 0; i < vecInt.size(); ++i){
        uint32_t nKey = vecInt[i];
        BSTNode *pCurNode = oBSTree.search(nKey);

        BSTNode *pSuccessor = oBSTree.successor(pCurNode);
        if ((NULL != pSuccessor) && ((nKey + 1) == pSuccessor->get_key())){
            // print_correct_msg(std::to_string(nKey) + " successor is :" + std::to_string(pSuccessor->get_key()) + "\n");
        } else if (11 == nKey){
            print_correct_msg("only " + std::to_string(nKey) + " has no successor.\n");
        } else {
            print_error_msg("successor function error.\n");
        }

        BSTNode *pPredecessor = oBSTree.predecessor(pCurNode);
        if ((NULL != pPredecessor) && ((nKey - 1) == pPredecessor->get_key())){
            // print_correct_msg(std::to_string(nKey) + " predecessor is :" + std::to_string(pPredecessor->get_key()) + "\n");
        } else if (1 == nKey){
            print_correct_msg("only " + std::to_string(nKey) + " has no predecessor.\n");
        } else {
            print_error_msg("predecessor funtion error.\n");
        }
    }

    Binary_Search_Tree<BSTNode> oCpBSTree;
    oCpBSTree = oBSTree;
    for (size_t i = 0; i < vecInt.size(); ++i){
        BSTNode *pRemoveNode = oCpBSTree.search(vecInt[i]);
        oCpBSTree.remove(pRemoveNode);
        delete pRemoveNode;
    }
    print_normal_msg("deleting binary tree:\n");
    print_warning_msg(oCpBSTree.to_string() + "\n");
}
