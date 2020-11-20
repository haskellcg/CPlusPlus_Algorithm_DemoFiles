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
    // TODO
    ossResult << "size:" << m_nSize;
    return ossResult.str();
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

void binary_tree_test()
{
    print_highlight_msg(">>> Test binary tree:\n");

    uint32_t arrayInt[] = {8, 5, 10, 2, 6, 9, 11, 7};

    vector<uint32_t> vecInt;
    vecInt.insert(vecInt.begin(), begin(arrayInt), end(arrayInt));
    print_normal_msg(to_string(vecInt) + "\n");

    Binary_Tree oBinaryTree;
    for (size_t i = 0; i < vecInt.size(); ++i){
        oBinaryTree.insert(vecInt[i]);
    }
    print_normal_msg(oBinaryTree.to_string() + "\n");

    print_error_msg("No test case yet.\n");
}
