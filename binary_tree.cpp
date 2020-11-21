/**************************************************************************
 * author: haskellcg
 * date: 2020-11-18
 * description: binary tree data structure
 *************************************************************************/

#include "binary_tree.h"

BTNode::BTNode()
:   m_nData(MAX_UINT32),
    m_pParent(NULL),
    m_pLeft(NULL),
    m_pRight(NULL)
{
}

BTNode::BTNode(uint32_t nData, BTNode *pParent, BTNode *pLeft, BTNode *pRight)
:   m_nData(nData),
    m_pParent(pParent),
    m_pLeft(pLeft),
    m_pRight(pRight)
{
}

uint32_t BTNode::get_data() const
{
    return m_nData;
}

void BTNode::set_data(uint32_t nData)
{
    m_nData = nData;
}

BTNode *BTNode::get_parent() const
{
    return m_pParent;
}

void BTNode::set_parent(BTNode *pParent)
{
    m_pParent = pParent;
}

BTNode *BTNode::get_left() const
{
    return m_pLeft;
}

void BTNode::set_left(BTNode *pLeft)
{
    m_pLeft = pLeft;
}

BTNode *BTNode::get_right() const
{
    return m_pRight;
}

void BTNode::set_right(BTNode *pRight)
{
    m_pRight = pRight;
}

Binary_Tree::Binary_Tree()
:   m_pRoot(NULL),
    m_nSize(0)
{
}

Binary_Tree::Binary_Tree(const Binary_Tree &oOtherBinaryTree)
:   m_pRoot(NULL),
    m_nSize(0)
{
    if (NULL != oOtherBinaryTree.m_pRoot){
        m_pRoot = new BTNode;
        copy_node_recursive(oOtherBinaryTree.m_pRoot, m_pRoot);
    }
    m_nSize = oOtherBinaryTree.m_nSize;
}

Binary_Tree::~Binary_Tree()
{
    delete_node_recursive(m_pRoot);
    m_pRoot = NULL;
    m_nSize = 0;
}

Binary_Tree &Binary_Tree::operator=(const Binary_Tree &oOtherBinaryTree)
{
    if (this == &oOtherBinaryTree){
        return *this;
    }

    delete_node_recursive(m_pRoot);
    m_pRoot = NULL;
    m_nSize = 0;

    if (NULL != oOtherBinaryTree.m_pRoot){
        m_pRoot = new BTNode;
        copy_node_recursive(oOtherBinaryTree.m_pRoot, m_pRoot);
    }
    m_nSize = oOtherBinaryTree.m_nSize;
    return *this;
}

string Binary_Tree::to_string() const
{
    ostringstream ossResult;
    ossResult << "binary tree:\n";

    const string strStartSpace = "    ";
    const string strSpace = "     ";
    const string strHorizental = "-----";
    const string strVertical = "|";
    
    vector<BTNode *> vecpBTNode;
    vecpBTNode.push_back(m_pRoot);
    while (!vecpBTNode.empty()){
        
        // print number
        string strNodeLine = strStartSpace;
        size_t nUsedCoefficientInThisLine = 0;
        for (size_t nNodeIndex = 0; nNodeIndex < vecpBTNode.size(); ++nNodeIndex){
            BTNode *pCurNode = vecpBTNode[nNodeIndex];
            size_t nCurNodePositionCoefficient = node_position_coefficient(pCurNode);
            for (size_t i = 0; i < (nCurNodePositionCoefficient - nUsedCoefficientInThisLine); ++i){
                strNodeLine += strSpace;
            }
            strNodeLine = adjust_string(strNodeLine, std::to_string(pCurNode->get_data()));
            nUsedCoefficientInThisLine = nCurNodePositionCoefficient;
        }
        ossResult << strNodeLine << "\n";

        // print | for current node
        string strCurVerticalLine = strStartSpace;
        nUsedCoefficientInThisLine = 0;
        for (size_t nNodeIndex = 0; nNodeIndex < vecpBTNode.size(); ++nNodeIndex){
            BTNode *pCurNode = vecpBTNode[nNodeIndex];
            if ((NULL == pCurNode->get_left()) && (NULL == pCurNode->get_right())){
                continue;
            }
            size_t nCurNodePositionCoefficient = node_position_coefficient(pCurNode);
            for (size_t i = 0; i < (nCurNodePositionCoefficient - nUsedCoefficientInThisLine); ++i){
                strCurVerticalLine += strSpace;
            }
            strCurVerticalLine = adjust_string(strCurVerticalLine, strVertical);
            nUsedCoefficientInThisLine = nCurNodePositionCoefficient;
        }
        ossResult << strCurVerticalLine << "\n";

        // print ---- for branch
        string strCurHorizentalLine = strStartSpace;
        nUsedCoefficientInThisLine = 0;
        for (size_t nNodeIndex = 0; nNodeIndex < vecpBTNode.size(); ++nNodeIndex){
            BTNode *pCurNode = vecpBTNode[nNodeIndex];
            if ((NULL == pCurNode->get_left()) && (NULL == pCurNode->get_right())){
                continue;
            }
            size_t nHorizentalStartCoefficient = 0;
            if (NULL != pCurNode->get_left()){
                nHorizentalStartCoefficient = node_position_coefficient(pCurNode->get_left());
            } else {
                nHorizentalStartCoefficient = node_position_coefficient(pCurNode);
            }
            size_t nHorizentalEndCoefficient = 0;
            if (NULL != pCurNode->get_right()){
                nHorizentalEndCoefficient = node_position_coefficient(pCurNode->get_right());
            } else {
                nHorizentalEndCoefficient = node_position_coefficient(pCurNode);
            }
            for (size_t i = 0; i < (nHorizentalStartCoefficient - nUsedCoefficientInThisLine); ++i){
                strCurHorizentalLine += strSpace;
            }
            for (size_t i = 0; i < (nHorizentalEndCoefficient - nHorizentalStartCoefficient); ++i){
                strCurHorizentalLine += strHorizental;
            }
            strCurHorizentalLine = adjust_string(strCurHorizentalLine, " ");
            nUsedCoefficientInThisLine = nHorizentalEndCoefficient;
        }
        ossResult << strCurHorizentalLine << "\n";

        // print | for children nodes
        string strChildVerticalLine = strStartSpace;
        nUsedCoefficientInThisLine = 0;
        vector<BTNode *> vecpChildBTNode;
        for (size_t nNodeIndex = 0; nNodeIndex < vecpBTNode.size(); ++nNodeIndex){
            BTNode *pCurNode = vecpBTNode[nNodeIndex];
            if ((NULL == pCurNode->get_left()) && (NULL == pCurNode->get_right())){
                continue;
            }
            if (NULL != pCurNode->get_left()){
                size_t nLeftPositionCoefficient = node_position_coefficient(pCurNode->get_left());
                for (size_t i = 0; i < (nLeftPositionCoefficient - nUsedCoefficientInThisLine); ++i){
                    strChildVerticalLine += strSpace;
                }
                strChildVerticalLine = adjust_string(strChildVerticalLine, strVertical);
                nUsedCoefficientInThisLine = nLeftPositionCoefficient;
                vecpChildBTNode.push_back(pCurNode->get_left());
            }
            if (NULL != pCurNode->get_right()){
                size_t nRightPositionCoefficient = node_position_coefficient(pCurNode->get_right());
                for (size_t i = 0; i < (nRightPositionCoefficient - nUsedCoefficientInThisLine); ++i){
                    strChildVerticalLine += strSpace;
                }
                strChildVerticalLine = adjust_string(strChildVerticalLine, strVertical);
                nUsedCoefficientInThisLine = nRightPositionCoefficient;
                vecpChildBTNode.push_back(pCurNode->get_right());
            }
        }
        ossResult << strChildVerticalLine << "\n";

        vecpBTNode = vecpChildBTNode;
    }

    ossResult << "size:" << m_nSize;
    return ossResult.str();
}

vector<uint32_t> Binary_Tree::inorder_tree_walk() const
{
    vector<uint32_t> vecWalkPath;
    inorder_tree_walk_recursive(m_pRoot, vecWalkPath);
    return vecWalkPath;
}

vector<uint32_t> Binary_Tree::preorder_tree_walk() const
{
    vector<uint32_t> vecWalkPath;
    preorder_tree_walk_recursive(m_pRoot, vecWalkPath);
    return vecWalkPath;
}

vector<uint32_t> Binary_Tree::postorder_tree_walk() const
{
    vector<uint32_t> vecWalkPath;
    postorder_tree_walk_recursive(m_pRoot, vecWalkPath);
    return vecWalkPath;
}

BTNode *Binary_Tree::search(uint32_t nKey) const
{
    BTNode *pCurNode = m_pRoot;
    while (NULL != pCurNode){
        if (nKey == pCurNode->get_data()){
            break;
        } else if (nKey > pCurNode->get_data()){
            pCurNode = pCurNode->get_right();
        } else {
            pCurNode = pCurNode->get_left();
        }
    }
    return pCurNode;
}

BTNode *Binary_Tree::insert(uint32_t nData)
{
    if (NULL == m_pRoot){
        m_pRoot = new BTNode(nData, NULL, NULL, NULL);
        ++m_nSize;
        return m_pRoot;
    } else {
        BTNode *pParent = m_pRoot;
        BTNode *pNewBTNode = NULL;
        while (true){
            if (nData == pParent->get_data()){
                break;
            } else if (nData > pParent->get_data()){
                if (NULL != pParent->get_right()){
                    pParent = pParent->get_right();
                } else {
                    pNewBTNode = new BTNode(nData, pParent, NULL, NULL);
                    pParent->set_right(pNewBTNode);
                    ++m_nSize;
                    break;
                }
            } else {
                if (NULL != pParent->get_left()){
                    pParent = pParent->get_left();
                } else {
                    pNewBTNode = new BTNode(nData, pParent, NULL, NULL);
                    pParent->set_left(pNewBTNode);
                    ++m_nSize;
                    break;
                }
            }
        }
        return pNewBTNode;
    }
}

void Binary_Tree::copy_node_recursive(BTNode *pNode, BTNode *pCopyNode)
{
    pCopyNode->set_data(pNode->get_data());
    if (NULL != pNode->get_left()){
        BTNode *pCopyLeftNode = new BTNode;
        copy_node_recursive(pNode->get_left(), pCopyLeftNode);
        pCopyNode->set_left(pCopyLeftNode);
        pCopyLeftNode->set_parent(pCopyNode);
    }
    if (NULL != pNode->get_right()){
        BTNode *pCopyRightNode = new BTNode;
        copy_node_recursive(pNode->get_right(), pCopyRightNode);
        pCopyNode->set_right(pCopyRightNode);
        pCopyRightNode->set_parent(pCopyNode);
    }
}

void Binary_Tree::delete_node_recursive(BTNode *pNode)
{
    if (NULL != pNode){
        if (NULL != pNode->get_left()){
            delete_node_recursive(pNode->get_left());
            pNode->set_left(NULL);
        }
        if (NULL != pNode->get_right()){
            delete_node_recursive(pNode->get_right());
            pNode->set_right(NULL);
        }
        delete pNode;
    }
}

size_t Binary_Tree::node_width_coefficient(BTNode *pNode)
{
    size_t nNodeWidthCoefficient = 0;
    if (NULL != pNode){
        if (NULL != pNode->get_left()){
            nNodeWidthCoefficient += node_width_coefficient(pNode->get_left());
            nNodeWidthCoefficient += 1;
        }
        if (NULL != pNode->get_right()){
            nNodeWidthCoefficient += node_width_coefficient(pNode->get_right());
            nNodeWidthCoefficient += 1;
        }
    }
    return nNodeWidthCoefficient;
}

size_t Binary_Tree::node_position_coefficient(BTNode *pNode)
{
    size_t nNodePositionCoefficient = 0;
    if (NULL == pNode->get_parent()){
        if (NULL != pNode->get_left()){
            nNodePositionCoefficient += node_width_coefficient(pNode->get_left());
            nNodePositionCoefficient += 1;
        }
    } else {
        BTNode *pParent = pNode->get_parent();
        if (pNode == pParent->get_left()){
            nNodePositionCoefficient = node_position_coefficient(pParent) - 1;
            if (NULL != pNode->get_right()){
                nNodePositionCoefficient -= node_width_coefficient(pNode->get_right());
                nNodePositionCoefficient -= 1;
            }
        } else {
            nNodePositionCoefficient = node_position_coefficient(pParent) + 1;
            if (NULL != pNode->get_left()){
                nNodePositionCoefficient += node_width_coefficient(pNode->get_left());
                nNodePositionCoefficient += 1;
            }
        }
    }
    return nNodePositionCoefficient;
}

string Binary_Tree::adjust_string(const string &strLine, const string &strDisplay)
{
    if (strDisplay.size() > strLine.size()){
        return strDisplay;
    } else {
        return (strLine.substr(0, strLine.size() - strDisplay.size()) + strDisplay);
    }
}

void Binary_Tree::inorder_tree_walk_recursive(BTNode *pNode, vector<uint32_t> &vecWalkPath)
{
    if (NULL != pNode){
        inorder_tree_walk_recursive(pNode->get_left(), vecWalkPath);
        vecWalkPath.push_back(pNode->get_data());
        inorder_tree_walk_recursive(pNode->get_right(), vecWalkPath);
    }
}

void Binary_Tree::preorder_tree_walk_recursive(BTNode *pNode, vector<uint32_t> &vecWalkPath)
{
    if (NULL != pNode){
        vecWalkPath.push_back(pNode->get_data());
        inorder_tree_walk_recursive(pNode->get_left(), vecWalkPath);
        inorder_tree_walk_recursive(pNode->get_right(), vecWalkPath);
    }
}

void Binary_Tree::postorder_tree_walk_recursive(BTNode *pNode, vector<uint32_t> &vecWalkPath)
{
    if (NULL != pNode){
        inorder_tree_walk_recursive(pNode->get_left(), vecWalkPath);
        inorder_tree_walk_recursive(pNode->get_right(), vecWalkPath);
        vecWalkPath.push_back(pNode->get_data());
    }
}

void binary_tree_test()
{
    print_highlight_msg(">>> Test binary tree:\n");

    uint32_t arrayInt[] = {8, 5, 10, 2, 6, 9, 11, 7, 3, 1, 4};
    vector<uint32_t> vecInt;
    vecInt.insert(vecInt.begin(), begin(arrayInt), end(arrayInt));
    print_normal_msg(to_string(vecInt) + "\n");

    Binary_Tree oBinaryTree;
    for (size_t i = 0; i < vecInt.size(); ++i){
        if(NULL == oBinaryTree.insert(vecInt[i])){
            print_warning_msg(std::to_string(vecInt[i]) + " already exist!\n");
        }
    }
    print_warning_msg(oBinaryTree.to_string() + "\n");

    print_normal_msg("inorder   :" + to_string(oBinaryTree.inorder_tree_walk()) + "\n");
    print_normal_msg("preorder  :" + to_string(oBinaryTree.preorder_tree_walk()) + "\n");
    print_normal_msg("postorder :" + to_string(oBinaryTree.postorder_tree_walk()) + "\n");

    print_error_msg("No test case yet.\n");
}
