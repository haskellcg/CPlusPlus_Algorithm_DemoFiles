/**************************************************************************
 * author: haskellcg
 * date: 2020-11-18
 * description: binary search tree data structure
 *************************************************************************/

#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <stack>
#include <utility>
#include "common_types.h"

/**
 * @brief binary search tree node
 */
class BSTNode
{
public:
    /**
     * @brief default constructor
     */
    BSTNode();

    /**
     * @brief destructor
     */
    ~BSTNode();

    /**
     * @brief get key
     */
    uint32_t get_key() const;

    /**
     * @brief set key
     */
    void set_key(uint32_t nKey);

    /**
     * @brief get parent node link
     */
    BSTNode *get_parent() const;

    /**
     * @brief set parent node link
     */
    void set_parent(BSTNode *pParent);

    /**
     * @brief get left child node link
     */
    BSTNode *get_left() const;

    /**
     * @brief set left child node link
     */
    void set_left(BSTNode *pLeft);

    /**
     * @brief get right child node link
     */
    BSTNode *get_right() const;

    /**
     * @brief set right child node link
     */
    void set_right(BSTNode *pRight);

private:
    /*< key of the node */
    uint32_t m_nKey;
    /*< link to parent node */
    BSTNode *m_pParent;
    /*< link to left child */
    BSTNode *m_pLeft;
    /*< link to right child */
    BSTNode *m_pRight;
};

/**
 * @brief binary search tree
 */
template <typename Node>
class Binary_Search_Tree
{
public:
    /**
     * @brief default constructor
     */
    Binary_Search_Tree()
    :   m_pRoot(NULL),
        m_nSize(0)
    {
    }

    /**
     * @brief copy constructor
     */
    Binary_Search_Tree(const Binary_Search_Tree<Node> &oOtherBSTree)
    :   m_pRoot(NULL),
        m_nSize(0)
    {
        if (NULL != oOtherBSTree.m_pRoot){
            m_pRoot = new Node;
            copy_node_recursive(oOtherBSTree.m_pRoot, m_pRoot);
        }
        m_nSize = oOtherBSTree.m_nSize;
    }

    /**
     * @brief destructor
     */
    ~Binary_Search_Tree()
    {
        delete_node_recursive(m_pRoot);
        m_pRoot = NULL;
        m_nSize = 0;
    }

    /**
     * @brief assign operator override
     */
    Binary_Search_Tree<Node> &operator=(const Binary_Search_Tree<Node> &oOtherBSTree)
    {
        if (this == &oOtherBSTree){
            return *this;
        }

        delete_node_recursive(m_pRoot);
        m_pRoot = NULL;
        m_nSize = 0;

        if (NULL != oOtherBSTree.m_pRoot){
            m_pRoot = new Node;
            copy_node_recursive(oOtherBSTree.m_pRoot, m_pRoot);
        }
        m_nSize = oOtherBSTree.m_nSize;
        return *this;
    }

    /**
     * @brief print binary search tree as string
     * @param
     * @return string
     * @remarks
     *                                             8
     *                                             |
     *                               ------------------------ 
     *                              |                        |
     *                              5                       10
     *                              |                        |
     *                -------------------                --------- 
     *               |                   |              |         |
     *               2                   6              9        11
     *               |                   |
     *           ---------                ---- 
     *          |         |                   |
     *          1         3                   7
     *                    |
     *                     ---- 
     *                         |
     *                         4
     */
    string to_string() const
    {
        ostringstream ossResult;
        ossResult << "binary search tree:\n";

        const string strStartSpace = "    ";
        const string strSpace = "     ";
        const string strHorizental = "-----";
        const string strVertical = "|";
        
        vector<Node *> vecpNode;
        if (NULL != m_pRoot){
            vecpNode.push_back(m_pRoot);
        }
        while (!vecpNode.empty()){
            
            // print number
            string strNodeLine = strStartSpace;
            size_t nUsedCoefficientInThisLine = 0;
            for (size_t nNodeIndex = 0; nNodeIndex < vecpNode.size(); ++nNodeIndex){
                Node *pCurNode = vecpNode[nNodeIndex];
                size_t nCurNodePositionCoefficient = node_position_coefficient(pCurNode);
                for (size_t i = 0; i < (nCurNodePositionCoefficient - nUsedCoefficientInThisLine); ++i){
                    strNodeLine += strSpace;
                }
                strNodeLine = adjust_string(strNodeLine, std::to_string(pCurNode->get_key()));
                nUsedCoefficientInThisLine = nCurNodePositionCoefficient;
            }
            ossResult << strNodeLine << "\n";

            // print | for current node
            string strCurVerticalLine = strStartSpace;
            nUsedCoefficientInThisLine = 0;
            for (size_t nNodeIndex = 0; nNodeIndex < vecpNode.size(); ++nNodeIndex){
                Node *pCurNode = vecpNode[nNodeIndex];
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
            for (size_t nNodeIndex = 0; nNodeIndex < vecpNode.size(); ++nNodeIndex){
                Node *pCurNode = vecpNode[nNodeIndex];
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
            vector<Node *> vecpChildNode;
            for (size_t nNodeIndex = 0; nNodeIndex < vecpNode.size(); ++nNodeIndex){
                Node *pCurNode = vecpNode[nNodeIndex];
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
                    vecpChildNode.push_back(pCurNode->get_left());
                }
                if (NULL != pCurNode->get_right()){
                    size_t nRightPositionCoefficient = node_position_coefficient(pCurNode->get_right());
                    for (size_t i = 0; i < (nRightPositionCoefficient - nUsedCoefficientInThisLine); ++i){
                        strChildVerticalLine += strSpace;
                    }
                    strChildVerticalLine = adjust_string(strChildVerticalLine, strVertical);
                    nUsedCoefficientInThisLine = nRightPositionCoefficient;
                    vecpChildNode.push_back(pCurNode->get_right());
                }
            }
            ossResult << strChildVerticalLine << "\n";

            vecpNode = vecpChildNode;
        }

        ossResult << "size:" << m_nSize;
        return ossResult.str();
    }

    /**
     * @brief inorder tree walk
     * @param
     * @return vector<uint32_t>,
     * @remarks
     */
    vector<uint32_t> inorder_tree_walk() const
    {
        vector<uint32_t> vecWalkPath;
        inorder_tree_walk_recursive(m_pRoot, vecWalkPath);
        return vecWalkPath;
    }

    /**
     * @brief preorder tree walk
     * @param
     * @return vector<uint32_t>,
     * @remarks
     */
    vector<uint32_t> preorder_tree_walk() const
    {
        vector<uint32_t> vecWalkPath;
        preorder_tree_walk_recursive(m_pRoot, vecWalkPath);
        return vecWalkPath;
    }
    
    /**
     * @brief postorder tree walk
     * @param
     * @return vector<uint32_t>,
     * @remarks
     */
    vector<uint32_t> postorder_tree_walk() const
    {
        vector<uint32_t> vecWalkPath;
        postorder_tree_walk_recursive(m_pRoot, vecWalkPath);
        return vecWalkPath;
    }

    /**
     * @brief inorder tree walk iteratively
     * @param
     * @return vector<uint32_t>,
     * @remarks
     */
    vector<uint32_t> inorder_tree_walk_iterative() const
    {
        vector<uint32_t> vecInorderResult;
        if (NULL != m_pRoot){
            stack<pair<Node *, bool>> stackNodeVisited;
            stackNodeVisited.push(make_pair(m_pRoot, false));
            while (!stackNodeVisited.empty()){
                pair<Node *, bool> pairCurNodeVisited = stackNodeVisited.top();
                stackNodeVisited.pop();

                if (pairCurNodeVisited.second){
                    vecInorderResult.push_back(pairCurNodeVisited.first->get_key());
                } else {
                    pairCurNodeVisited.second = true;
                    if (NULL != pairCurNodeVisited.first->get_right()){
                        stackNodeVisited.push(make_pair(pairCurNodeVisited.first->get_right(), false));
                    }
                    stackNodeVisited.push(pairCurNodeVisited);
                    if (NULL != pairCurNodeVisited.first->get_left()){
                        stackNodeVisited.push(make_pair(pairCurNodeVisited.first->get_left(), false));
                    }
                }
            }
        }
        return vecInorderResult;
    }

    /**
     * @brief preorder tree walk iteratively
     * @param
     * @return vector<uint32_t>,
     * @remarks
     */
    vector<uint32_t> preorder_tree_walk_iterative() const
    {
        vector<uint32_t> vecPreorderResult;
        if (NULL != m_pRoot){
            stack<Node *> stackNode;
            stackNode.push(m_pRoot);
            while (!stackNode.empty()){
                Node *pCurNode = stackNode.top();
                stackNode.pop();

                vecPreorderResult.push_back(pCurNode->get_key());
                if (NULL != pCurNode->get_right()){
                    stackNode.push(pCurNode->get_right());
                }
                if (NULL != pCurNode->get_left()){
                    stackNode.push(pCurNode->get_left());
                }
            }
        }
        return vecPreorderResult;
    }

    /**
     * @brief postorder tree walk iteratively
     * @param
     * @return vector<uint32_t>,
     * @remarks
     */
    vector<uint32_t> postorder_tree_walk_iterative() const
    {
        vector<uint32_t> vecPostorderResult;
        if (NULL != m_pRoot){
            stack<pair<Node *, bool>> stackNodeVisited;
            stackNodeVisited.push(make_pair(m_pRoot, false));
            while (!stackNodeVisited.empty()){
                pair<Node *, bool> pairCurNodeVisited = stackNodeVisited.top();
                stackNodeVisited.pop();

                if (pairCurNodeVisited.second){
                    vecPostorderResult.push_back(pairCurNodeVisited.first->get_key());
                } else {
                    pairCurNodeVisited.second = true;
                    stackNodeVisited.push(pairCurNodeVisited);
                    if (NULL != pairCurNodeVisited.first->get_right()){
                        stackNodeVisited.push(make_pair(pairCurNodeVisited.first->get_right(), false));
                    }
                    if (NULL != pairCurNodeVisited.first->get_left()){
                        stackNodeVisited.push(make_pair(pairCurNodeVisited.first->get_left(), false));
                    }
                }
            }
        }
        return vecPostorderResult;
    }

    /**
     * @brief inorder tree walk use morris algorithm
     * @param
     * @return vector<uint32_t>,
     * @remarks
     *          reference: https://blog.csdn.net/yangfeisc/article/details/45673947
     */
    vector<uint32_t> inorder_tree_walk_morris() const
    {
        vector<uint32_t> vecInorderResult;
        Node *pCurNode = m_pRoot;
        while (NULL != pCurNode){
            if (NULL == pCurNode->get_left()){
                vecInorderResult.push_back(pCurNode->get_key());
                pCurNode = pCurNode->get_right();
            } else {
                Node *pPredecessor = pCurNode->get_left();
                while ((NULL != pPredecessor->get_right()) && (pCurNode != pPredecessor->get_right())){
                    pPredecessor = pPredecessor->get_right();
                }

                if (NULL == pPredecessor->get_right()){
                    pPredecessor->set_right(pCurNode);
                    pCurNode = pCurNode->get_left();
                } else {
                    pPredecessor->set_right(NULL);
                    vecInorderResult.push_back(pCurNode->get_key());
                    pCurNode = pCurNode->get_right();
                }
            }
        }
        return vecInorderResult;
    }

    /**
     * @brief preorder tree walk use morris algorithm
     * @param
     * @return vector<uint32_t>,
     * @remarks
     *          reference: https://blog.csdn.net/yangfeisc/article/details/45673947
     */
    vector<uint32_t> preorder_tree_walk_morris() const
    {
        vector<uint32_t> vecPreorderResult;
        Node *pCurNode = m_pRoot;
        while (NULL != pCurNode){
            if (NULL == pCurNode->get_left()){
                vecPreorderResult.push_back(pCurNode->get_key());
                pCurNode = pCurNode->get_right();
            } else {
                Node *pPredecessor = pCurNode->get_left();
                while ((NULL != pPredecessor->get_right()) && (pCurNode != pPredecessor->get_right())){
                    pPredecessor = pPredecessor->get_right();
                }

                if (NULL == pPredecessor->get_right()){
                    pPredecessor->set_right(pCurNode);
                    vecPreorderResult.push_back(pCurNode->get_key());
                    pCurNode = pCurNode->get_left();
                } else {
                    pPredecessor->set_right(NULL);
                    pCurNode = pCurNode->get_right();
                }
            }
        }
        return vecPreorderResult;
    }

    /**
     * @brief postorder tree walk use morris algorithm
     * @param
     * @return vector<uint32_t>,
     * @remarks
     *          reference: https://blog.csdn.net/yangfeisc/article/details/45673947
     */
    vector<uint32_t> postorder_tree_walk_morris() const
    {
        vector<uint32_t> vecPostorderResult;
        Node oTopNode;
        oTopNode.set_left(m_pRoot);
        Node *pCurNode = &oTopNode;
        while (NULL != pCurNode){
            if (NULL == pCurNode->get_left()){
                pCurNode = pCurNode->get_right();
            } else {
                Node *pPredecessor = pCurNode->get_left();
                while ((NULL != pPredecessor->get_right()) && (pCurNode != pPredecessor->get_right())){
                    pPredecessor = pPredecessor->get_right();
                }

                if (NULL == pPredecessor->get_right()){
                    pPredecessor->set_right(pCurNode);
                    pCurNode = pCurNode->get_left();
                } else {
                    pPredecessor->set_right(NULL);
                    vector<uint32_t> vecLeftChildToPredecessor;
                    Node *pNode = pCurNode->get_left();
                    vecLeftChildToPredecessor.push_back(pNode->get_key());
                    while (NULL != pNode->get_right()){
                        pNode = pNode->get_right();
                        vecLeftChildToPredecessor.push_back(pNode->get_key());
                    }
                    vecPostorderResult.insert(vecPostorderResult.end(),
                                              vecLeftChildToPredecessor.rbegin(),
                                              vecLeftChildToPredecessor.rend());
                    pCurNode = pCurNode->get_right();
                }
            }
        }
        return vecPostorderResult;
    }

    /**
     * @brief maximum node in the tree
     * @param
     * @return Node *, maximum node pointer,
     *                 null if tree is empty
     * @remarks
     */
    Node *maximum() const
    {
        return maximum(m_pRoot);
    }

    /**
     * @brief minimum node in the tree
     * @param
     * @return Node *, minimum node pointer
     *                 null if tree is empty
     * @remarks
     */
    Node *minimum() const
    {
        return minimum(m_pRoot);
    }

    /**
     * @brief successor of the pNode in inorder tree walk
     * @param Node *pNode, current node
     * @return Node *, the successor
     * @remarks
     *          pNode must be in the tree, this is not checked in funtion
     */
    Node *successor(Node *pNode) const
    {
        if (NULL != pNode->get_right()){
            return minimum(pNode->get_right());
        } else {
            Node *pCurNode = pNode;
            Node *pParent = pCurNode->get_parent();
            while ((NULL != pParent) && (pCurNode != pParent->get_left())){
                pCurNode = pParent;
                pParent = pCurNode->get_parent();
            }
            return pParent;
        }
    }

    /**
     * @brief predecessor of the pNode in inorder tree walk
     * @param Node *pNode, current node
     * @return Node *, the predecessor
     * @remarks
     *          pNode must be in the tree, this is not checked in funtion
     */
    Node *predecessor(Node *pNode) const
    {
        if (NULL != pNode->get_left()){
            return maximum(pNode->get_left());
        } else {
            Node *pCurNode = pNode;
            Node *pParent = pCurNode->get_parent();
            while ((NULL != pParent) && (pCurNode != pParent->get_right())){
                pCurNode = pParent;
                pParent = pCurNode->get_parent();
            }
            return pParent;
        }
    }

    /**
     * @brief search nKey in the tree
     * @param uint32_t nKey, key
     * @return Node *, null if nKey not in the tree,
     *                 or node contain the nKey will be returned
     * @remarks
     */
    Node *search(uint32_t nKey) const
    {
        Node *pCurNode = m_pRoot;
        while (NULL != pCurNode){
            if (nKey == pCurNode->get_key()){
                break;
            } else if (nKey > pCurNode->get_key()){
                pCurNode = pCurNode->get_right();
            } else {
                pCurNode = pCurNode->get_left();
            }
        }
        return pCurNode;
    }

    /** 
     * @brief insert nKey as Node to binary search tree
     * @param uint32_t nKey, key
     * @return Node *, null if nKey already in the tree,
     *                 or node created
     * @remarks
     */
    Node *insert(uint32_t nKey)
    {
        if (NULL == search(nKey)){
            Node *pNewNode = new Node;
            pNewNode->set_key(nKey);
            insert(pNewNode);
            ++m_nSize;
            return pNewNode;
        } else {
            return NULL;
        }
    }

    /**
     * @brief remove pNode from binary search tree
     * @param Node *pNode,
     * @return void
     * @remarks
     *          pNode must be in the tree
     */
    void remove(Node *pNode)
    {
        if (NULL == pNode->get_left()){
            transplant(pNode, pNode->get_right());
            pNode->set_right(NULL);
        } else if (NULL == pNode->get_right()){
            transplant(pNode, pNode->get_left());
            pNode->set_left(NULL);
        } else {
            Node *pSuccessor = successor(pNode);
            if (pSuccessor != pNode->get_right()){
                transplant(pSuccessor, pSuccessor->get_right());
                pSuccessor->set_right(pNode->get_right());
                pNode->get_right()->set_parent(pSuccessor);
            }
            transplant(pNode, pSuccessor);
            pNode->set_right(NULL);
            pSuccessor->set_left(pNode->get_left());
            pNode->get_left()->set_parent(pSuccessor);
            pNode->set_left(NULL);
        }
        --m_nSize;
    }

protected:
    /**
     * @brief copy pNode children nodes to pCopyNode
     * @param Node *pNode, current node
     * @param Node *pCopyNode, copy node
     * @return void
     * @remarks
     */
    void copy_node_recursive(Node *pNode, Node *pCopyNode) const
    {
        *pCopyNode = *pNode;
        if (NULL != pNode->get_left()){
            Node *pCopyLeftNode = new Node;
            copy_node_recursive(pNode->get_left(), pCopyLeftNode);
            pCopyNode->set_left(pCopyLeftNode);
            pCopyLeftNode->set_parent(pCopyNode);
        }
        if (NULL != pNode->get_right()){
            Node *pCopyRightNode = new Node;
            copy_node_recursive(pNode->get_right(), pCopyRightNode);
            pCopyNode->set_right(pCopyRightNode);
            pCopyRightNode->set_parent(pCopyNode);
        }
    }

    /**
     * @brief delete a node recursive version
     * @param Node *pNode, node to be deleted
     * @return void
     * @remarks
     */
    void delete_node_recursive(Node *pNode) const
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

    /**
     * @brief get the node width coefficient
     * @param Node *pNode,
     * @return size_t, width coefficient
     * @remarks
     *                  x(2 + 1 + 2 = 5)
     *                  |
     *          ------------------
     *          |                |
     *          x(2)             x(1)
     *          |                |
     *      ---------            ------
     *      |       |                 |
     *      x(0)    x(0)              x(0)
     */
    size_t node_width_coefficient(Node *pNode) const
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

    /**
     * @brief get node position coefficient
     * @param Node *pNode,
     * @return size_t, position coefficient
     * @remarks
     *                  x(3)
     *                  |
     *          ------------------
     *          |                |
     *          x(1)             x(4)
     *          |                |
     *      ---------            ------
     *      |       |                 |
     *      x(0)    x(2)              x(5)
     */
    size_t node_position_coefficient(Node *pNode) const
    {
        size_t nNodePositionCoefficient = 0;
        if (NULL == pNode->get_parent()){
            if (NULL != pNode->get_left()){
                nNodePositionCoefficient += node_width_coefficient(pNode->get_left());
                nNodePositionCoefficient += 1;
            }
        } else {
            Node *pParent = pNode->get_parent();
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

    /**
     * @brief adjust string to fit display string, like:
     *        (abcdefg, 67) => (abcde67)
     * @param const string &strLine, string
     * @param const string &strDisplay, string need to display
     * @return string
     * @remarks
     */
    string adjust_string(const string &strLine, const string &strDisplay) const
    {
        if (strDisplay.size() > strLine.size()){
            return strDisplay;
        } else {
            return (strLine.substr(0, strLine.size() - strDisplay.size()) + strDisplay);
        }
    }

    /**
     * @brief inorder tree(pNode) walk
     * @param Node *pNode, current tree root node
     * @param vector<uint32_t> &vecWalkPath, walk result
     * @return void
     * @remarks
     */
    void inorder_tree_walk_recursive(Node *pNode, vector<uint32_t> &vecWalkPath) const
    {
        if (NULL != pNode){
            inorder_tree_walk_recursive(pNode->get_left(), vecWalkPath);
            vecWalkPath.push_back(pNode->get_key());
            inorder_tree_walk_recursive(pNode->get_right(), vecWalkPath);
        }
    }

    /**
     * @brief preorder tree(pNode) walk
     * @param Node *pNode, current tree root node
     * @param vector<uint32_t> &vecWalkPath, walk result
     * @return void
     * @remarks
     */
    void preorder_tree_walk_recursive(Node *pNode, vector<uint32_t> &vecWalkPath) const
    {
        if (NULL != pNode){
            vecWalkPath.push_back(pNode->get_key());
            preorder_tree_walk_recursive(pNode->get_left(), vecWalkPath);
            preorder_tree_walk_recursive(pNode->get_right(), vecWalkPath);
        }
    }

    /**
     * @brief postorder tree(pNode) walk
     * @param Node *pNode, current tree root node
     * @param vector<uint32_t> &vecWalkPath, walk result
     * @return void
     * @remarks
     */
    void postorder_tree_walk_recursive(Node *pNode, vector<uint32_t> &vecWalkPath) const
    {
        if (NULL != pNode){
            postorder_tree_walk_recursive(pNode->get_left(), vecWalkPath);
            postorder_tree_walk_recursive(pNode->get_right(), vecWalkPath);
            vecWalkPath.push_back(pNode->get_key());
        }
    }

    /**
     * @brief maximum node in the tree which pNode as root
     * @param
     * @return Node *, maximum node pointer,
     *                 null if tree is empty
     * @remarks
     */
    Node *maximum(Node *pNode) const
    {
        Node *pCurNode = pNode;
        if (NULL != pCurNode){
            while (NULL != pCurNode->get_right()){
                pCurNode = pCurNode->get_right();
            }
        }
        return pCurNode;
    }

    /**
     * @brief maximum node in the tree which pNode as root
     * @param
     * @return Node *, maximum node pointer,
     *                 null if tree is empty
     * @remarks
     */
    Node *minimum(Node *pNode) const
    {
        Node *pCurNode = pNode;
        if (NULL != pCurNode){
            while (NULL != pCurNode->get_left()){
                pCurNode = pCurNode->get_left();
            }
        }
        return pCurNode;
    }

    /**
     * @brief transplant Y sub-tree to X sub-tree
     * @param Node *pNodeX, X sub-tree
     * @param Node *pNodeY, Y sub-tree
     * @return void
     * @remarks
     *           P                       p
     *           |                       |
     *           X           =>          Y
     *          / \                     / \
     *
     *          X should not be NULL
     *          Y could be NULL
     */
    void transplant(Node *pXNode, Node *pYNode)
    {
        Node *pParent = pXNode->get_parent();
        if (NULL == pParent){
            m_pRoot = pYNode;
        } else {
            if (pXNode == pParent->get_left()){
                pParent->set_left(pYNode);
            } else {
                pParent->set_right(pYNode);
            }
        }

        if (NULL != pYNode){
            pYNode->set_parent(pParent);
        }
        pXNode->set_parent(NULL);
    }

    /**
     * @brief insert pNewNode to the tree
     * @param Node *pNewNode, new node
     * @return new node pointer
     * @remarks
     *          make sure pNewNode->get_key() is not in the tree
     */
    Node *insert(Node *pNewNode)
    {
        if (NULL == m_pRoot){
            m_pRoot = pNewNode;
        } else {
            Node *pParent = m_pRoot;
            while (true){
                if (pNewNode->get_key() == pParent->get_key()){
                    break;
                } else if (pNewNode->get_key() > pParent->get_key()){
                    if (NULL != pParent->get_right()){
                        pParent = pParent->get_right();
                    } else {
                        pNewNode->set_parent(pParent);
                        pParent->set_right(pNewNode);
                        break;
                    }
                } else {
                    if (NULL != pParent->get_left()){
                        pParent = pParent->get_left();
                    } else {
                        pNewNode->set_parent(pParent);
                        pParent->set_left(pNewNode);
                        break;
                    }
                }
            }
        }
        return pNewNode;
    }

protected:
    /*< root node of the tree */
    Node *m_pRoot;
    /*< number of node in the tree */
    size_t m_nSize;
};

/**
 * @brief test binary search tree
 * @param
 * @return void
 * @remarks
 */
void binary_search_tree_test();

#endif // __BINARY_SEARCH_TREE_H__
