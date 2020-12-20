/**************************************************************************
 * author: haskellcg
 * date: 2020-12-05
 * description: radix tree data structure
 *************************************************************************/

#include <cstring>
#include "radix_tree.h"

RTBaseNode::RTBaseNode()
:   m_pParent(NULL)
{
}

RTBaseNode::~RTBaseNode()
{
    m_pParent = NULL;
}

string RTBaseNode::get_value() const
{
    return m_strValue;
}

void RTBaseNode::set_value(const string &strValue)
{
    m_strValue = strValue;
}

RTBaseNode *RTBaseNode::get_parent() const
{
    return m_pParent;
}

void RTBaseNode::set_parent(RTBaseNode *pParent)
{
    m_pParent = pParent;
}

RTInnerNode4::RTInnerNode4()
{
    for (size_t i = 0; i < 4; ++i){
        m_arrayChildKeys[i] = INVALID_RT_KEY;
        m_arrayChildNodes[i] = NULL;
    }
}

RTInnerNode4::~RTInnerNode4()
{
    for (size_t i = 0; i < 4; ++i){
        if (INVALID_RT_KEY != m_arrayChildKeys[i]){
            m_arrayChildKeys[i] = INVALID_RT_KEY;
            delete m_arrayChildNodes[i];
            m_arrayChildNodes[i] = NULL;
        }
    }
}

string RTInnerNode4::to_string() const
{
    ostringstream ossResult;
    ossResult << "TYPE: INNER_NODE_4\n";
    ossResult << "value:    [" << m_strValue << "]\n";
    ossResult << "keys:     [";
    for (size_t i = 0; i < 4; ++i){
        ossResult << setw(3) << (uint32_t)m_arrayChildKeys[i];
        if (i != 3){
            ossResult << ", ";
        }
    }
    ossResult << "]\n";
    ossResult << "pointers: [";
    for (size_t i = 0; i < 4; ++i){
        ossResult << m_arrayChildNodes[i];
        if (i != 3){
            ossResult << ", ";
        }
    }
    ossResult << "]";
    return ossResult.str();
}

RTNodeType RTInnerNode4::get_node_type() const
{
    return RTNodeType::INNER_NODE_4;
}

void RTInnerNode4::get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const
{
    for (size_t i = 0; i < 4; ++i){
        if (NULL != m_arrayChildNodes[i]){
            vecValidChildNodes.push_back(m_arrayChildNodes[i]);
        }
    }
}

bool RTInnerNode4::is_child_full() const
{
    for (size_t i = 0; i < 4; ++i){
        if (INVALID_RT_KEY == m_arrayChildKeys[i]){
            return false;
        }
    }
    return true;
}

bool RTInnerNode4::is_key_exists(uint8_t nKey) const
{
    return (NULL != get_child_node(nKey));
}

RTBaseNode *RTInnerNode4::get_child_node(uint8_t nKey) const
{
    RTBaseNode *pChildNode = NULL;
    for (size_t i = 0; i < 4; ++i){
        if (nKey == m_arrayChildKeys[i]){
            pChildNode = m_arrayChildNodes[i];
            break;
        }
    }
    return pChildNode;
}

bool RTInnerNode4::insert_child_node(uint8_t nKey, RTBaseNode *pChildNode)
{
    for (size_t i = 0; i < 4; ++i){
        if (INVALID_RT_KEY == m_arrayChildKeys[i]){
            m_arrayChildKeys[i] = nKey;
            m_arrayChildNodes[i] = pChildNode;
            pChildNode->set_parent(this);
            return true;
        }
    }
    return false;
}

RTBaseNode *RTInnerNode4::remove_child_node(uint8_t nKey)
{
    RTBaseNode *pRemovedNode = NULL;
    for (size_t i= 0; i < 4; ++i){
        if (nKey == m_arrayChildKeys[i]){
            m_arrayChildKeys[i] = INVALID_RT_KEY;
            pRemovedNode = m_arrayChildNodes[i];
            m_arrayChildNodes[i] = NULL;
            pRemovedNode->set_parent(NULL);
            break;
        }
    }
    return pRemovedNode;
}

RTBaseNode *RTInnerNode4::upgrade()
{
    RTBaseNode *pUpgradedNode = new RTInnerNode16;
    pUpgradedNode->set_value(get_value());
    for (size_t i= 0; i < 4; ++i){
        if (INVALID_RT_KEY != m_arrayChildKeys[i]){
            pUpgradedNode->insert_child_node(m_arrayChildKeys[i],
                                             remove_child_node(m_arrayChildKeys[i]));
        }
    }
    return pUpgradedNode;
}

RTInnerNode16::RTInnerNode16()
{
    m_arrayChildKeys = _mm_set1_epi8(INVALID_RT_KEY);
    for (size_t i = 0; i < 16; ++i){
        m_arrayChildNodes[i] = NULL;
    }
}

RTInnerNode16::~RTInnerNode16()
{
    m_arrayChildKeys = _mm_set1_epi8(INVALID_RT_KEY);
    for (size_t i = 0; i < 16; ++i){
        if (NULL != m_arrayChildNodes[i]){
            delete m_arrayChildNodes[i];
            m_arrayChildNodes[i] = NULL;
        }
    }
}

string RTInnerNode16::to_string() const
{
    ostringstream ossResult;
    ossResult << "TYPE: INNER_NODE_16\n";
    ossResult << "value:    [" << m_strValue << "]\n";
    ossResult << "keys:     [";
    uint8_t arrayChildKeys[16];
    memcpy(arrayChildKeys, &m_arrayChildKeys, sizeof(arrayChildKeys));
    for (size_t i = 0; i < 16; ++i){
        ossResult << setw(3) << (uint32_t)arrayChildKeys[i];
        if (i != 15){
            ossResult << ", ";
            if (0 == ((i + 1) % 4)){
                ossResult << "\n           ";
            }
        }
    }
    ossResult << "]\n";
    ossResult << "pointers: [";
    for (size_t i = 0; i < 16; ++i){
        ossResult << m_arrayChildNodes[i];
        if (i != 15){
            ossResult << ", ";
            if (0 == ((i + 1) % 4)){
                ossResult << "\n           ";
            }
        }
    }
    ossResult << "]";
    return ossResult.str();
}

RTNodeType RTInnerNode16::get_node_type() const
{
    return RTNodeType::INNER_NODE_16;
}

void RTInnerNode16::get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const
{
    for (size_t i = 0; i < 16; ++i){
        if (NULL != m_arrayChildNodes[i]){
            vecValidChildNodes.push_back(m_arrayChildNodes[i]);
        }
    }
}

bool RTInnerNode16::is_child_full() const
{
    __m128i sseInvalidKey = _mm_set1_epi8(INVALID_RT_KEY);
    __m128i sseCmp = _mm_cmpeq_epi8(sseInvalidKey, m_arrayChildKeys);
    uint32_t nMask = (1 << 16) - 1;
    uint32_t nBitField = _mm_movemask_epi8(sseCmp) & nMask;
    if (0 != nBitField){
        return false;
    } else {
        return true;
    }
}

bool RTInnerNode16::is_key_exists(uint8_t nKey) const
{
    return (NULL != get_child_node(nKey));
}

RTBaseNode *RTInnerNode16::get_child_node(uint8_t nKey) const
{
    // like: [nKey, nKey, ..., nKey]
    __m128i sseKey = _mm_set1_epi8(nKey);
    // like: [0x00, 0xFF, ..., 0x00]
    __m128i sseCmp = _mm_cmpeq_epi8(sseKey, m_arrayChildKeys);
    // like: [0x00, 0x00, 0xFF, 0xFF]
    uint32_t nMask = (1 << 16) - 1;
    // like: [0x00, 0x00, 0x08, 0x00]
    uint32_t nBitField = _mm_movemask_epi8(sseCmp) & nMask;
    if (0 != nBitField){
        return m_arrayChildNodes[__builtin_ctz(nBitField)];
    } else {
        return NULL;
    }
}


bool RTInnerNode16::insert_child_node(uint8_t nKey, RTBaseNode *pChildNode)
{
    __m128i sseInvalidKey = _mm_set1_epi8(INVALID_RT_KEY);
    __m128i sseCmp = _mm_cmpeq_epi8(sseInvalidKey, m_arrayChildKeys);
    uint32_t nMask = (1 << 16) - 1;
    uint32_t nBitField = _mm_movemask_epi8(sseCmp) & nMask;
    if (0 != nBitField){
        uint32_t nInsertIndex = __builtin_ctz(nBitField);
        uint8_t arrayChildKeys[16];
        memcpy(arrayChildKeys, &m_arrayChildKeys, sizeof(arrayChildKeys));
        arrayChildKeys[nInsertIndex] = nKey;
        memcpy(&m_arrayChildKeys, arrayChildKeys, sizeof(arrayChildKeys));
        m_arrayChildNodes[nInsertIndex] = pChildNode;
        pChildNode->set_parent(this);
        return true;
    } else {
        return false;
    }
}

RTBaseNode *RTInnerNode16::remove_child_node(uint8_t nKey)
{
    RTBaseNode *pRemovedNode = NULL;

    __m128i sseKey = _mm_set1_epi8(nKey);
    __m128i sseCmp = _mm_cmpeq_epi8(sseKey, m_arrayChildKeys);
    uint32_t nMask = (1 << 16) - 1;
    uint32_t nBitField = _mm_movemask_epi8(sseCmp) & nMask;
    if (0 != nBitField){
        uint32_t nRemoveIndex = __builtin_ctz(nBitField);
        uint8_t arrayChildKeys[16];
        memcpy(arrayChildKeys, &m_arrayChildKeys, sizeof(arrayChildKeys));
        arrayChildKeys[nRemoveIndex] = INVALID_RT_KEY;
        memcpy(&m_arrayChildKeys, arrayChildKeys, sizeof(arrayChildKeys));
        pRemovedNode = m_arrayChildNodes[nRemoveIndex];
        m_arrayChildNodes[nRemoveIndex] = NULL;
        pRemovedNode->set_parent(NULL);
    }

    return pRemovedNode;
}

RTBaseNode *RTInnerNode16::upgrade()
{
    RTBaseNode *pUpgradedNode = new RTInnerNode48;
    pUpgradedNode->set_value(get_value());

    uint8_t arrayChildKeys[16];
    memcpy(arrayChildKeys, &m_arrayChildKeys, sizeof(arrayChildKeys));
    for (size_t i= 0; i < 16; ++i){
        if (INVALID_RT_KEY != arrayChildKeys[i]){
            pUpgradedNode->insert_child_node(arrayChildKeys[i],
                                             remove_child_node(arrayChildKeys[i]));
        }
    }
    return pUpgradedNode;
}

RTInnerNode48::RTInnerNode48()
{
    for (size_t i = 0; i < 256; ++i){
        m_arrayChildKeys[i] = INVALID_RT_KEY;
    }
    for (size_t i = 0; i < 48; ++i){
        m_arrayChildNodes[i] = NULL;
    }
}

RTInnerNode48::~RTInnerNode48()
{
    for (size_t i = 0; i < 256; ++i){
        uint8_t nChildPointerIndex = m_arrayChildKeys[i];
        m_arrayChildKeys[i] = INVALID_RT_KEY;
        if (INVALID_RT_KEY != nChildPointerIndex){
            delete m_arrayChildNodes[nChildPointerIndex];
            m_arrayChildNodes[nChildPointerIndex] = NULL;
        }
    }
}

string RTInnerNode48::to_string() const
{
    ostringstream ossResult;
    ossResult << "TYPE: INNER_NODE_48\n";
    ossResult << "value:    [" << m_strValue << "]\n";
    ossResult << "keys:     [";
    for (size_t i = 0; i < 256; ++i){
        ossResult << setw(3) << (uint32_t)m_arrayChildKeys[i];
        if (i != 255){
            ossResult << ", ";
            if (0 == ((i + 1) % 12)){
                ossResult << "\n           ";
            }
        }
    }
    ossResult << "]\n";
    ossResult << "pointers: [";
    for (size_t i = 0; i < 48; ++i){
        ossResult << m_arrayChildNodes[i];
        if (i != 47){
            ossResult << ", ";
            if (0 == ((i + 1) % 12)){
                ossResult << "\n           ";
            }
        }
    }
    ossResult << "]";
    return ossResult.str();
}

RTNodeType RTInnerNode48::get_node_type() const
{
    return RTNodeType::INNER_NODE_48;
}

void RTInnerNode48::get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const
{
    for (size_t i = 0; i < 48; ++i){
        if (NULL != m_arrayChildNodes[i]){
            vecValidChildNodes.push_back(m_arrayChildNodes[i]);
        }
    }
}

bool RTInnerNode48::is_child_full() const
{
    for (size_t i = 0; i < 48; ++i){
        if (NULL == m_arrayChildNodes[i]){
            return false;
        }
    }
    return true;
}

bool RTInnerNode48::is_key_exists(uint8_t nKey) const
{
    return (INVALID_RT_KEY != m_arrayChildKeys[nKey]);
}

RTBaseNode *RTInnerNode48::get_child_node(uint8_t nKey) const
{
    uint8_t nChildPointerIndex = m_arrayChildKeys[nKey];
    if (INVALID_RT_KEY != nChildPointerIndex){
        return m_arrayChildNodes[nChildPointerIndex];
    } else {
        return NULL;
    }
}

bool RTInnerNode48::insert_child_node(uint8_t nKey, RTBaseNode *pChildNode)
{
    if (INVALID_RT_KEY == m_arrayChildKeys[nKey]){
        size_t nInsertIndex = 0;
        for (; nInsertIndex < 48; ++nInsertIndex){
            if (NULL == m_arrayChildNodes[nInsertIndex]){
                m_arrayChildNodes[nInsertIndex] = pChildNode;
                pChildNode->set_parent(this);
                break;
            }
        }
        if (nInsertIndex < 48){
            m_arrayChildKeys[nKey] = nInsertIndex;
            return true;
        }
    }
    return false;
}

RTBaseNode *RTInnerNode48::remove_child_node(uint8_t nKey)
{
    RTBaseNode *pRemovedNode = NULL;
    uint8_t nChildPointerIndex = m_arrayChildKeys[nKey];
    if (INVALID_RT_KEY != nChildPointerIndex){
        pRemovedNode = m_arrayChildNodes[nChildPointerIndex];
        m_arrayChildNodes[nChildPointerIndex] = NULL;
        m_arrayChildKeys[nKey] = INVALID_RT_KEY;
        pRemovedNode->set_parent(NULL);
    }
    return pRemovedNode;
}

RTBaseNode *RTInnerNode48::upgrade()
{
    RTBaseNode *pUpgradedNode = new RTInnerNode256;
    pUpgradedNode->set_value(get_value());

    for (size_t i= 0; i < 256; ++i){
        if (INVALID_RT_KEY != m_arrayChildKeys[i]){
            pUpgradedNode->insert_child_node(i,
                                             remove_child_node(i));
        }
    }
    return pUpgradedNode;
}

RTInnerNode256::RTInnerNode256()
{
    for (size_t i = 0; i < 256; ++i){
        m_arrayChildNodes[i] = NULL;
    }
}

RTInnerNode256::~RTInnerNode256()
{
    for (size_t i = 0; i < 256; ++i){
        if (NULL != m_arrayChildNodes[i]){
            delete m_arrayChildNodes[i];
            m_arrayChildNodes[i] = NULL;
        }
    }
}

string RTInnerNode256::to_string() const
{
    ostringstream ossResult;
    ossResult << "TYPE: INNER_NODE_256\n";
    ossResult << "value:    [" << m_strValue << "]\n";
    ossResult << "keys:     [";
    ossResult << "]\n";
    ossResult << "pointers: [";
    for (size_t i = 0; i < 256; ++i){
        ossResult << m_arrayChildNodes[i];
        if (i != 255){
            ossResult << ", ";
            if (0 == ((i + 1) % 12)){
                ossResult << "\n           ";
            }
        }
    }
    ossResult << "]";
    return ossResult.str();
}

RTNodeType RTInnerNode256::get_node_type() const
{
    return RTNodeType::INNER_NODE_256;
}

void RTInnerNode256::get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const
{
    for (size_t i = 0; i < 256; ++i){
        if (NULL != m_arrayChildNodes[i]){
            vecValidChildNodes.push_back(m_arrayChildNodes[i]);
        }
    }
}

bool RTInnerNode256::is_child_full() const
{
    for (size_t i = 0; i < 256; ++i){
        if (NULL == m_arrayChildNodes[i]){
            return false;
        }
    }
    return true;
}

bool RTInnerNode256::is_key_exists(uint8_t nKey) const
{
    return (NULL != m_arrayChildNodes[nKey]);
}

RTBaseNode *RTInnerNode256::get_child_node(uint8_t nKey) const
{
    return m_arrayChildNodes[nKey];
}

bool RTInnerNode256::insert_child_node(uint8_t nKey, RTBaseNode *pChildNode)
{
    if (NULL == m_arrayChildNodes[nKey]){
        m_arrayChildNodes[nKey] = pChildNode;
        pChildNode->set_parent(this);
        return true;
    } else {
        return false;
    }
}

RTBaseNode *RTInnerNode256::remove_child_node(uint8_t nKey)
{
    RTBaseNode *pRemovedNode = NULL;
    if (NULL != m_arrayChildNodes[nKey]){
        pRemovedNode = m_arrayChildNodes[nKey];
        m_arrayChildNodes[nKey] = NULL;
        pRemovedNode->set_parent(NULL);
    }
    return pRemovedNode;
}

RTBaseNode *RTInnerNode256::upgrade()
{
    return this;
}

RTLeafNode::RTLeafNode()
{
}

RTLeafNode::~RTLeafNode()
{
}

string RTLeafNode::to_string() const
{
    ostringstream ossResult;
    ossResult << "TYPE: LEAF_NODE\n";
    ossResult << "value:    [" << m_strValue << "]";
    return ossResult.str();
}

RTNodeType RTLeafNode::get_node_type() const
{
    return RTNodeType::LEAF_NODE;
}

void RTLeafNode::get_valid_child_nodes(vector<RTBaseNode *> & /*< vecValidChildNodes */) const
{
}

bool RTLeafNode::is_child_full() const
{
    return true;
}

bool RTLeafNode::is_key_exists(uint8_t /*< nKey */) const
{
    return false;
}

RTBaseNode *RTLeafNode::get_child_node(uint8_t /*< nKey */) const
{
    return NULL;
}

bool RTLeafNode::insert_child_node(uint8_t /*< nKey */, RTBaseNode * /*< pChildNode */)
{
    return false;
}

RTBaseNode *RTLeafNode::remove_child_node(uint8_t /*< nKey */)
{
    return NULL;
}

RTBaseNode *RTLeafNode::upgrade()
{
    return this;
}

Radix_Tree::Radix_Tree()
:   m_pRoot(NULL)
{
}

Radix_Tree::~Radix_Tree()
{
    if (NULL != m_pRoot){
        delete m_pRoot;
        m_pRoot = NULL;
    }
}

string Radix_Tree::to_string() const
{
    vector<string> vecResult;
    if (NULL != m_pRoot){
        to_string_recursive(m_pRoot, "", vecResult);
    }

    string strResult = "Radix Tree:\n";
    for (size_t i = 0; i < vecResult.size(); ++i){
        strResult += ">";
        strResult += vecResult[i];
        if (i != (vecResult.size() - 1)){
            strResult += "\n";
        }
    }
    return strResult;
}

bool Radix_Tree::insert(const string &strKey)
{
    if (NULL != m_pRoot){
        return insert_recursive(m_pRoot, strKey, 0);
    } else {
        m_pRoot = new RTLeafNode;
        m_pRoot->set_value(strKey);
        return true;
    }
}

void Radix_Tree::to_string_recursive(RTBaseNode *pCurNode, const string &strParent, vector<string> &vecResult) const
{
    string strCur = strParent + pCurNode->get_value();
    RTNodeType enumCurNodeType = pCurNode->get_node_type();
    switch (enumCurNodeType){
        case INNER_NODE_4:
        case INNER_NODE_16:
        case INNER_NODE_48:
        case INNER_NODE_256:
            {
                vector<RTBaseNode *> vecValidChildNodes;
                pCurNode->get_valid_child_nodes(vecValidChildNodes);
                for (size_t i = 0; i < vecValidChildNodes.size(); ++i){
                    to_string_recursive(vecValidChildNodes[i], strCur, vecResult);
                }
            }
            break;
        case LEAF_NODE:
            {
                vecResult.push_back(strParent + pCurNode->get_value());
            }
            break;
        default:
            break;
    }
}

void Radix_Tree::replace_nodes(RTBaseNode *pOldNode, RTBaseNode *pNewNode)
{
    RTBaseNode *pParent = pOldNode->get_parent();
    if (NULL != pParent){
        uint8_t nKey = (pOldNode->get_value())[0];
        pParent->remove_child_node(nKey);
        pParent->insert_child_node(nKey, pNewNode);
    } else {
        m_pRoot = pNewNode;
    }
}

bool Radix_Tree::insert_recursive(RTBaseNode *pCurNode, const string &strKey, size_t nStartIndex)
{
    string strCurValue = pCurNode->get_value();
    size_t nCurValueIndex = 0;
    size_t nKeyIndex = nStartIndex;
    for (; (nCurValueIndex < strCurValue.size()) && (nKeyIndex < strKey.size()); ++nCurValueIndex, ++nKeyIndex){
        if (strCurValue[nCurValueIndex] != strKey[nKeyIndex]){
            break;
        }
    }

    if ((nCurValueIndex >= strCurValue.size()) && (nKeyIndex < strKey.size())){
        uint8_t nKey = strKey[nKeyIndex];
        switch (pCurNode->get_node_type()){
            case INNER_NODE_4:
            case INNER_NODE_16:
            case INNER_NODE_48:
            case INNER_NODE_256:
                {
                    if (pCurNode->is_key_exists(nKey)){
                        return insert_recursive(pCurNode->get_child_node(nKey), strKey, nKeyIndex);
                    } else {
                        if (pCurNode->is_child_full()){
                            RTBaseNode *pUpgradedNode = pCurNode->upgrade();
                            replace_nodes(pCurNode, pUpgradedNode);
                            delete pCurNode;
                            pCurNode = pUpgradedNode;
                        }
                        RTBaseNode *pLeafNode = new RTLeafNode;
                        pLeafNode->set_value(strKey.substr(nKeyIndex));
                        pCurNode->insert_child_node(nKey, pLeafNode);
                        return true;
                    }
                }
                break;
            case LEAF_NODE:
                {
                    RTBaseNode *pInnerNode4 = new RTInnerNode4;
                    pInnerNode4->set_value(strCurValue);
                    replace_nodes(pCurNode, pInnerNode4);
                    delete pCurNode;
                    pCurNode = pInnerNode4;

                    RTBaseNode *pOriginLeafNode = new RTLeafNode;
                    pOriginLeafNode->set_value("\0");
                    pCurNode->insert_child_node(0, pOriginLeafNode);

                    RTBaseNode *pNewNode = new RTLeafNode;
                    pNewNode->set_value(strKey.substr(nKeyIndex));
                    pCurNode->insert_child_node(nKey, pNewNode);
                    return true;
                }
                break;
            default:
                break;
        }
    } else if ((nCurValueIndex < strCurValue.size()) && (nKeyIndex >= strKey.size())){
        uint8_t nKey_1 = strCurValue[nCurValueIndex];
        string strValue_1 = strCurValue.substr(nCurValueIndex);
        uint8_t nKey_2 = 0;
        string strValue_2 = "\0";

        RTBaseNode *pParent = new RTInnerNode4;
        pParent->set_value(strCurValue.substr(0, nCurValueIndex));
        replace_nodes(pCurNode, pParent);

        pCurNode->set_value(strValue_1);
        RTBaseNode *pNewNode = new RTLeafNode;
        pNewNode->set_value(strValue_2);

        pParent->insert_child_node(nKey_1, pCurNode);
        pParent->insert_child_node(nKey_2, pNewNode);
        return true;
    } else if ((nCurValueIndex >= strCurValue.size()) && (nKeyIndex >= strKey.size())){
        switch (pCurNode->get_node_type()){
            case INNER_NODE_4:
            case INNER_NODE_16:
            case INNER_NODE_48:
            case INNER_NODE_256:
                {
                    if (!pCurNode->is_key_exists(0)){
                        if (pCurNode->is_child_full()){
                            RTBaseNode *pUpgradedNode = pCurNode->upgrade();
                            replace_nodes(pCurNode, pUpgradedNode);
                            delete pCurNode;
                            pCurNode = pUpgradedNode;
                        }
                        RTBaseNode *pLeafNode = new RTLeafNode;
                        pLeafNode->set_value("\0");
                        pCurNode->insert_child_node(0, pLeafNode);
                        return true;
                    }
                }
                break;
            case LEAF_NODE:
                break;
            default:
                break;
        }
    } else {
        // (strCurValue[nCurValueIndex] != strKey[nKeyIndex])
        uint8_t nKey_1 = strCurValue[nCurValueIndex];
        string strValue_1 = strCurValue.substr(nCurValueIndex);
        uint8_t nKey_2 = strKey[nKeyIndex];
        string strValue_2 = strKey.substr(nKeyIndex);

        RTBaseNode *pParent = new RTInnerNode4;
        pParent->set_value(strCurValue.substr(0, nCurValueIndex));
        replace_nodes(pCurNode, pParent);

        pCurNode->set_value(strValue_1);
        RTBaseNode *pNewNode = new RTLeafNode;
        pNewNode->set_value(strValue_2);

        pParent->insert_child_node(nKey_1, pCurNode);
        pParent->insert_child_node(nKey_2, pNewNode);
        return true;
    }
    return false;
}

void radix_tree_test()
{
    print_highlight_msg(">>> Test radix tree:\n");

    /*< inner node 4 test */
    RTInnerNode4 oRTInnerNode4;
    oRTInnerNode4.set_value("inner_node_4");
    if (!oRTInnerNode4.is_child_full()){
        print_correct_msg("inner node 4 start with empty child.\n");
    } else {
        print_error_msg("inner node 4 start with not empty child.\n");
    }
    for (size_t i = 0; i < 4; ++i){
        RTLeafNode *pChildNode = new RTLeafNode;
        oRTInnerNode4.insert_child_node(i, pChildNode);

        if (NULL == oRTInnerNode4.get_child_node(i)){
            print_error_msg("child node with key: " + std::to_string(i) + " insert failed.\n");
        }
    }
    print_warning_msg(oRTInnerNode4.to_string() + "\n");
    if (oRTInnerNode4.is_child_full()){
        print_correct_msg("inner node 4 is full after 4 times insertion.\n");
    } else {
        print_error_msg("inner node 4 is not full after 4 times insertion.\n");
    }
    for (size_t i = 0; i < 3; ++i){
        RTBaseNode *pRemovedNode = oRTInnerNode4.remove_child_node(i);
        if (NULL != pRemovedNode){
            delete pRemovedNode;
            pRemovedNode = NULL;
        } else {
            print_error_msg("remove child with key: " + std::to_string(i) + " failed.\n");
        }
    }
    if (oRTInnerNode4.is_key_exists(3)){
        print_correct_msg("child node 3 is not removed.\n");
    } else {
        print_error_msg("child not 3 is not found.\n");
    }

    /*< inner node 16 test */
    RTInnerNode16 oRTInnerNode16;
    oRTInnerNode16.set_value("inner_node_16");
    if (!oRTInnerNode16.is_child_full()){
        print_correct_msg("inner node 16 start with empty child.\n");
    } else {
        print_error_msg("inner node 16 start with not empty child.\n");
    }
    for (size_t i = 0; i < 16; ++i){
        RTLeafNode *pChildNode = new RTLeafNode;
        oRTInnerNode16.insert_child_node(i, pChildNode);

        if (NULL == oRTInnerNode16.get_child_node(i)){
            print_error_msg("child node with key: " + std::to_string(i) + " insert failed.\n");
        }
    }
    print_warning_msg(oRTInnerNode16.to_string() + "\n");
    if (oRTInnerNode16.is_child_full()){
        print_correct_msg("inner node 16 is full after 16 times insertion.\n");
    } else {
        print_error_msg("inner node 16 is not full after 16 times insertion.\n");
    }
    for (size_t i = 0; i < 15; ++i){
        RTBaseNode *pRemovedNode = oRTInnerNode16.remove_child_node(i);
        if (NULL != pRemovedNode){
            delete pRemovedNode;
            pRemovedNode = NULL;
        } else {
            print_error_msg("remove child with key: " + std::to_string(i) + " failed.\n");
        }
    }
    if (oRTInnerNode16.is_key_exists(15)){
        print_correct_msg("child node 15 is not removed.\n");
    } else {
        print_error_msg("child not 15 is not found.\n");
    }

    /*< inner node 48 test */
    RTInnerNode48 oRTInnerNode48;
    oRTInnerNode48.set_value("inner_node_48");
    if (!oRTInnerNode48.is_child_full()){
        print_correct_msg("inner node 48 start with empty child.\n");
    } else {
        print_error_msg("inner node 48 start with not empty child.\n");
    }
    for (size_t i = 0; i < 48; ++i){
        RTLeafNode *pChildNode = new RTLeafNode;
        oRTInnerNode48.insert_child_node(i, pChildNode);

        if (NULL == oRTInnerNode48.get_child_node(i)){
            print_error_msg("child node with key: " + std::to_string(i) + " insert failed.\n");
        }
    }
    print_warning_msg(oRTInnerNode48.to_string() + "\n");
    if (oRTInnerNode48.is_child_full()){
        print_correct_msg("inner node 48 is full after 48 times insertion.\n");
    } else {
        print_error_msg("inner node 48 is not full after 48 times insertion.\n");
    }
    for (size_t i = 0; i < 47; ++i){
        RTBaseNode *pRemovedNode = oRTInnerNode48.remove_child_node(i);
        if (NULL != pRemovedNode){
            delete pRemovedNode;
            pRemovedNode = NULL;
        } else {
            print_error_msg("remove child with key: " + std::to_string(i) + " failed.\n");
        }
    }
    if (oRTInnerNode48.is_key_exists(47)){
        print_correct_msg("child node 47 is not removed.\n");
    } else {
        print_error_msg("child not 47 is not found.\n");
    }

    /*< inner node 256 test */
    RTInnerNode256 oRTInnerNode256;
    oRTInnerNode256.set_value("inner_node_256");
    if (!oRTInnerNode256.is_child_full()){
        print_correct_msg("inner node 256 start with empty child.\n");
    } else {
        print_error_msg("inner node 256 start with not empty child.\n");
    }
    for (size_t i = 0; i < 256; ++i){
        RTLeafNode *pChildNode = new RTLeafNode;
        oRTInnerNode256.insert_child_node(i, pChildNode);

        if (NULL == oRTInnerNode256.get_child_node(i)){
            print_error_msg("child node with key: " + std::to_string(i) + " insert failed.\n");
        }
    }
    print_warning_msg(oRTInnerNode256.to_string() + "\n");
    if (oRTInnerNode256.is_child_full()){
        print_correct_msg("inner node 256 is full after 256 times insertion.\n");
    } else {
        print_error_msg("inner node 256 is not full after 256 times insertion.\n");
    }
    for (size_t i = 0; i < 255; ++i){
        RTBaseNode *pRemovedNode = oRTInnerNode256.remove_child_node(i);
        if (NULL != pRemovedNode){
            delete pRemovedNode;
            pRemovedNode = NULL;
        } else {
            print_error_msg("remove child with key: " + std::to_string(i) + " failed.\n");
        }
    }
    if (oRTInnerNode256.is_key_exists(255)){
        print_correct_msg("child node 255 is not removed.\n");
    } else {
        print_error_msg("child not 255 is not found.\n");
    }

    /*< radix tree test */
    Radix_Tree oRadixTree;
    oRadixTree.insert("she");
    oRadixTree.insert("shemale");
    oRadixTree.insert("shea");
    oRadixTree.insert("sheab");
    oRadixTree.insert("sheabc");
    oRadixTree.insert("her");
    oRadixTree.insert("him");
    oRadixTree.insert("sh");
    oRadixTree.insert("h");
    print_warning_msg(oRadixTree.to_string() + "\n");
}
