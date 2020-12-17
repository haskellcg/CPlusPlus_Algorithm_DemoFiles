/**************************************************************************
 * author: haskellcg
 * date: 2020-12-05
 * description: radix tree data structure
 *************************************************************************/

#include <cstring>
#include "radix_tree.h"

string RTBaseNode::get_value() const
{
    return m_strValue;
}

void RTBaseNode::set_value(const string &strValue)
{
    m_strValue = strValue;
}

RTInnerNode4::RTInnerNode4()
{
    for (size_t i = 0; i < 4; ++i){
        m_arrayChildKeys[i] = INVALID_RT_KEY;
        m_arrayChildNodes[i] = NULL;
    }
}

RTNodeType RTInnerNode4::get_node_type() const
{
    return RTNodeType::INNER_NODE_4;
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
            break;
        }
    }
    return pRemovedNode;
}

RTInnerNode16::RTInnerNode16()
{
    m_arrayChildKeys = _mm_set1_epi8(INVALID_RT_KEY);
    for (size_t i = 0; i < 16; ++i){
        m_arrayChildNodes[i] = NULL;
    }
}

RTNodeType RTInnerNode16::get_node_type() const
{
    return RTNodeType::INNER_NODE_16;
}

string RTInnerNode16::to_string() const
{
    ostringstream ossResult;
    ossResult << "value:" << m_strValue << "\n";
    ossResult << "keys: [";
    uint8_t arrayChildKeys[16];
    memcpy(arrayChildKeys, &m_arrayChildKeys, sizeof(arrayChildKeys));
    for (size_t i = 0; i < 16; ++i){
        ossResult << (uint32_t)arrayChildKeys[i];
        if (i != 15){
            ossResult << ", ";
        }
    }
    ossResult << "]\n";
    ossResult << "pointers: [";
    for (size_t i = 0; i < 16; ++i){
        ossResult << m_arrayChildNodes[i];
        if (i != 15){
            ossResult << ", ";
        }
    }
    ossResult << "]";
    return ossResult.str();
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
    }

    return pRemovedNode;
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

RTNodeType RTInnerNode48::get_node_type() const
{
    return RTNodeType::INNER_NODE_48;
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
    }
    return pRemovedNode;
}

RTInnerNode256::RTInnerNode256()
{
    for (size_t i = 0; i < 256; ++i){
        m_arrayChildNodes[i] = NULL;
    }
}

RTNodeType RTInnerNode256::get_node_type() const
{
    return RTNodeType::INNER_NODE_256;
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
    }
    return pRemovedNode;
}

RTNodeType RTLeafNode::get_node_type() const
{
    return RTNodeType::LEAF_NODE;
}

void radix_tree_test()
{
    print_highlight_msg(">>> Test radix tree:\n");
    RTInnerNode16 oRTInnerNode16;
    for (size_t i = 0; i < 16; ++i){
        RTInnerNode4 *pChildNode = new RTInnerNode4;
        oRTInnerNode16.insert_child_node(i, pChildNode);
        print_warning_msg(oRTInnerNode16.to_string());
    }
    print_normal_msg(std::to_string(oRTInnerNode16.is_child_full()) + "\n");
    print_normal_msg(std::to_string(oRTInnerNode16.is_key_exists(9)) + "\n");
    print_error_msg("No test case yet.\n");
}
