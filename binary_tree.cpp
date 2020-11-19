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
}

//Binary_Tree &operator=(const Binary_Tree &oOtherBinaryTree);

//string to_string() const;

//BTNode *search(uint32_t nKey) const;

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
        --m_nSize;
    }
}

void binary_tree_test()
{
    print_highlight_msg(">>> Test binary tree:\n");
    Binary_Tree oBinaryTree;
    print_error_msg("No test case yet.\n");
}
