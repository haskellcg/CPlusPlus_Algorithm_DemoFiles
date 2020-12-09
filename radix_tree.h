/**************************************************************************
 * author: haskellcg
 * date: 2020-12-05
 * description: radix tree data structure
 *************************************************************************/

#ifndef __RADIX_TREE_H__
#define __RADIX_TREE_H__

#include "common_types.h"

/**
 * @brief radix tree node types
 */
enum RTNodeType
{
    INNER_NODE_4,
    INNER_NODE_16,
    INNER_NODE_48,
    INNER_NODE_256,
    LEAF_NODE
};

/**
 * @brief base radix tree node
 */
class RTBaseNode
{
public:
    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const = 0;
    
    /**
     * @brief get value
     */
    string get_value() const;

    /**
     * @brief set value
     */
    void set_value(const string &strValue);

protected:
    /*< the value of the node */
    string m_strValue;
};

/**
 * @brief inner node 4
 */
class RTInnerNode4
{
public:
    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;
};

/**
 * @brief inner node 16
 */
class RTInnerNode16
{
public:
    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;
};

/**
 * @brief inner node 48
 */
class RTInnerNode48
{
public:
    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;
};

/**
 * @brief inner node 4
 */
class RTInnerNode256
{
public:
    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;
};

/**
 * @brief leaf node
 */
class RTLeafNode
{
public:
    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;
};

/**
 * @brief radix tree
 * @remarks
 *          IPs problem: https://blog.sqreen.com/demystifying-radix-trees/
 *          Bloom Filter: https://en.wikipedia.org/wiki/Bloom_filter
 *
 *          Visualization: https://www.cs.usfca.edu/~galles/visualization/RadixTree.html
 *          Assocaitive Array: https://en.wikipedia.org/wiki/Associative_array
 *          Radix Tree: https://en.wikipedia.org/wiki/Radix_tree
 *          Difference Radix Tree with Trie: https://stackoverflow.com/questions/14708134/
 *                                           what-is-the-difference-between-trie-and-radix-trie-data-structures
 *          Radix Tree in Linux: https://lwn.net/Articles/175432/
 *          Radix Tree Adaptive: https://db.in.tum.de/~leis/papers/ART.pdf
 *                               T tree
 *                               B+ tree
 *                               CSB+ tree
 *                               k-ary search tree
 *                               FAST-the fast architecture sensitive tree
 *                               ART-adaptive radix tree: path compression, lazy expansion
 *                                                        Space usage can be excessive when most child pointers are null
 *                                                        GTP use span 4 bits; linux kernel use span 6 bits
 *                                                        binary comparable keys(difination/transformations)
 *                               burst trie
 *                               HAT-trie
 *                               the Generalized Prefix tree
 *                               KISS tree
 *          Cache: https://www.geeksforgeeks.org/cache-memory-in-computer-organization/
 *                 https://www.geeksforgeeks.org/cache-organization-set-1-introduction/?ref=lbp
 *                 https://www.geeksforgeeks.org/whats-difference-between-cpu-cache-and-tlb/?ref=lbp
 *          Reiser4 FS: https://web.archive.org/web/20071024001500/http://www.namesys.com/v4/v4.html#soft_eng
 */
class Radix_Tree
{
};

/**
 * @brief test radix tree data structure
 * @param
 * @return void
 * @remarks
 */
void radix_tree_test();

#endif // __RADIX_TREE_H__
