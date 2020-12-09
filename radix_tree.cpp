/**************************************************************************
 * author: haskellcg
 * date: 2020-12-05
 * description: radix tree data structure
 *************************************************************************/

#include "radix_tree.h"

string RTBaseNode::get_value() const
{
    return m_strValue;
}

void RTBaseNode::set_value(const string &strValue)
{
    m_strValue = strValue;
}

RTNodeType RTInnerNode4::get_node_type() const
{
    return RTNodeType::INNER_NODE_4;
}

RTNodeType RTInnerNode16::get_node_type() const
{
    return RTNodeType::INNER_NODE_16;
}

RTNodeType RTInnerNode48::get_node_type() const
{
    return RTNodeType::INNER_NODE_48;
}

RTNodeType RTInnerNode256::get_node_type() const
{
    return RTNodeType::INNER_NODE_256;
}

RTNodeType RTLeafNode::get_node_type() const
{
    return RTNodeType::LEAF_NODE;
}

void radix_tree_test()
{
    print_highlight_msg(">>> Test radix tree:\n");
    print_error_msg("No test case yet.\n");
}
