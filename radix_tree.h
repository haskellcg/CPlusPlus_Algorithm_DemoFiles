/**************************************************************************
 * author: haskellcg
 * date: 2020-12-05
 * description: radix tree data structure
 *************************************************************************/

#ifndef __RADIX_TREE_H__
#define __RADIX_TREE_H__

#include <immintrin.h>
#include "common_types.h"

#define INVALID_RT_KEY 0xFF

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
class RTInnerNode4: public RTBaseNode
{
public:
    /**
     * @brief default constructor
     */
    RTInnerNode4();

    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;

    /**
     * @brief is child full
     * @param
     * @return bool
     * @remarks
     */
    bool is_child_full() const;

    /**
     * @brief is key exist
     * @param uint8_t nKey, key
     * @return bool
     * @remarks
     */
    bool is_key_exists(uint8_t nKey) const;

    /**
     * @brief get child node according to key
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, child node pointer
     *                       null if ket not exist
     * @remarks
     */
    RTBaseNode *get_child_node(uint8_t nKey) const;

    /**
     * @brief insert child node
     * @param uint8_t nKey, child key
     * @param RTBaseNode *pChildNode, child node
     * @return bool
     * @remarks
     */
    bool insert_child_node(uint8_t nKey, RTBaseNode *pChildNode);

private:
    /*< child keys, 4 at most */
    uint8_t m_arrayChildKeys[4];
    /*< child RTNode pointers, 4 at most */
    RTBaseNode *m_arrayChildNodes[4];
};

/**
 * @brief inner node 16
 */
class RTInnerNode16: public RTBaseNode
{
public:
    /**
     * @brief default constructor
     */
    RTInnerNode16();

    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;

    /**
     * @brief show information about inner node 16
     * @param 
     * @return string
     * @remarks
     */
    string to_string() const;

    /**
     * @brief is child full
     * @param
     * @return bool
     * @remarks
     */
    bool is_child_full() const;

    /**
     * @brief is key exist
     * @param uint8_t nKey, key
     * @return bool
     * @remarks
     */
    bool is_key_exists(uint8_t nKey) const;

    /**
     * @brief get child node according to key
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, child node pointer
     *                       null if ket not exist
     * @remarks
     */
    RTBaseNode *get_child_node(uint8_t nKey) const;

    /**
     * @brief insert child node
     * @param uint8_t nKey, child key
     * @param RTBaseNode *pChildNode, child node
     * @return bool
     * @remarks
     */
    bool insert_child_node(uint8_t nKey, RTBaseNode *pChildNode);

private:
    /*< child keys, 16 at most */
    __m128i m_arrayChildKeys;
    /*< child RTNode pointers, 16 at most */
    RTBaseNode *m_arrayChildNodes[16];
};

/**
 * @brief inner node 48
 */
class RTInnerNode48: public RTBaseNode
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
class RTInnerNode256: public RTBaseNode
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
class RTLeafNode: public RTBaseNode
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
 *          SSE tutorial: https://felix.abecassis.me/2011/09/cpp-getting-started-with-sse/
 *          MSDN SSE instructions: https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2010/y0dh78ez(v=vs.100)
 *                  _mm_set1_epi8: Sets the 16 signed 8-bit integer values to b
 *                 _mm_cmpeq_epi8: Compares the 16 signed or unsigned 8-bit integers in a and the 16 signed or unsigned 8-bit integers in b for equality
 *              _mm_movemask_epi8: Creates a 16-bit mask from the most significant bits of the 16 signed or unsigned 8-bit integers in a and zero extends the upper bits
 *                            ctz: https://stackoverflow.com/questions/17375743/what-library-do-i-have-to-use-for-ctz-command-in-c
 *                        headers: https://stackoverflow.com/questions/11228855/header-files-for-x86-simd-intrinsics
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
