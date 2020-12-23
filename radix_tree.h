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
     * @brief default constructor
     */
    RTBaseNode();

    /**
     * @brief virutal destructor
     */
    virtual ~RTBaseNode();

    /**
     * @brief show information about inner node 4
     * @param 
     * @return string
     * @remarks
     */
    virtual string to_string() const = 0;

    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const = 0;

    /**
     * @brief get all the non-null child nodes in the inner node
     * @param vector<RTBaseNode *> &vecValidChildNodes, all the non-null child nodes
     * @return void
     * @remarks
     */
    virtual void get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const = 0;

    /**
     * @brief is child full
     * @param
     * @return bool
     * @remarks
     */
    virtual bool is_child_full() const = 0;

    /**
     * @brief is key exist
     * @param uint8_t nKey, key
     * @return bool
     * @remarks
     */
    virtual bool is_key_exists(uint8_t nKey) const = 0;

    /**
     * @brief get child node according to key
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, child node pointer
     *                       null if ket not exist
     * @remarks
     */
    virtual RTBaseNode *get_child_node(uint8_t nKey) const = 0;

    /**
     * @brief insert child node
     * @param uint8_t nKey, child key
     * @param RTBaseNode *pChildNode, child node
     * @return bool
     * @remarks
     */
    virtual bool insert_child_node(uint8_t nKey, RTBaseNode *pChildNode) = 0;

    /**
     * @brief remove child node from inner node
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, removed node
     * @remarks
     */
    virtual RTBaseNode *remove_child_node(uint8_t nKey) = 0;

    /**
     * @brief upgrade inner node level
     * @param
     * @return RTBaseNode *, upgraded node
     * @remarks
     */
    virtual RTBaseNode *upgrade() = 0;

    /**
     * @brief downgrade inner node level
     * @param
     * @return RTBaseNode, downgraded node
     * @remarks
     */
    virtual RTBaseNode *downgrade() = 0;
    
    /**
     * @brief get value
     */
    string get_value() const;

    /**
     * @brief set value
     */
    void set_value(const string &strValue);

    /**
     * @brief get parent node
     */
    RTBaseNode *get_parent() const;

    /**
     * @brief set parent node
     */
    void set_parent(RTBaseNode *pParent);

protected:
    /*< the value of the node */
    string m_strValue;

    /*< parent node */
    RTBaseNode *m_pParent;
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
     * @brief virutal destructor
     */
    virtual ~RTInnerNode4();

    /**
     * @brief show information about inner node 4
     * @param 
     * @return string
     * @remarks
     */
    virtual string to_string() const;

    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;

    /**
     * @brief get all the non-null child nodes in the inner node
     * @param vector<RTBaseNode *> &vecValidChildNodes, all the non-null child nodes
     * @return void
     * @remarks
     */
    virtual void get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const;

    /**
     * @brief is child full
     * @param
     * @return bool
     * @remarks
     */
    virtual bool is_child_full() const;

    /**
     * @brief is key exist
     * @param uint8_t nKey, key
     * @return bool
     * @remarks
     */
    virtual bool is_key_exists(uint8_t nKey) const;

    /**
     * @brief get child node according to key
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, child node pointer
     *                       null if ket not exist
     * @remarks
     */
    virtual RTBaseNode *get_child_node(uint8_t nKey) const;

    /**
     * @brief insert child node
     * @param uint8_t nKey, child key
     * @param RTBaseNode *pChildNode, child node
     * @return bool
     * @remarks
     */
    virtual bool insert_child_node(uint8_t nKey, RTBaseNode *pChildNode);

    /**
     * @brief remove child node from inner node
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, removed node
     * @remarks
     */
    virtual RTBaseNode *remove_child_node(uint8_t nKey);

    /**
     * @brief upgrade inner node level
     * @param
     * @return RTBaseNode *, upgraded node
     * @remarks
     */
    virtual RTBaseNode *upgrade();
    
    /**
     * @brief downgrade inner node level
     * @param
     * @return RTBaseNode, downgraded node
     * @remarks
     *          if there are valid nodes in the node, call this
     *          method will cause these nodes lose
     */
    virtual RTBaseNode *downgrade();
    
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
     * @brief virutal destructor
     */
    virtual ~RTInnerNode16();

    /**
     * @brief show information about inner node 16
     * @param 
     * @return string
     * @remarks
     */
    virtual string to_string() const;

    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;

    /**
     * @brief get all the non-null child nodes in the inner node
     * @param vector<RTBaseNode *> &vecValidChildNodes, all the non-null child nodes
     * @return void
     * @remarks
     */
    virtual void get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const;

    /**
     * @brief is child full
     * @param
     * @return bool
     * @remarks
     */
    virtual bool is_child_full() const;

    /**
     * @brief is key exist
     * @param uint8_t nKey, key
     * @return bool
     * @remarks
     */
    virtual bool is_key_exists(uint8_t nKey) const;

    /**
     * @brief get child node according to key
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, child node pointer
     *                       null if ket not exist
     * @remarks
     */
    virtual RTBaseNode *get_child_node(uint8_t nKey) const;

    /**
     * @brief insert child node
     * @param uint8_t nKey, child key
     * @param RTBaseNode *pChildNode, child node
     * @return bool
     * @remarks
     */
    virtual bool insert_child_node(uint8_t nKey, RTBaseNode *pChildNode);

    /**
     * @brief remove child node from inner node
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, removed node
     * @remarks
     */
    virtual RTBaseNode *remove_child_node(uint8_t nKey);

    /**
     * @brief upgrade inner node level
     * @param
     * @return RTBaseNode *, upgraded node
     * @remarks
     */
    virtual RTBaseNode *upgrade();
    
    /**
     * @brief downgrade inner node level
     * @param
     * @return RTBaseNode, downgraded node
     * @remarks
     *          if there are 4 more valid nodes in the node, call this
     *          method will cause these nodes lose
     */
    virtual RTBaseNode *downgrade();
    
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
     * @brief default constructor
     */
    RTInnerNode48();

    /**
     * @brief virutal destructor
     */
    virtual ~RTInnerNode48();

    /**
     * @brief show information about inner node 48
     * @param 
     * @return string
     * @remarks
     */
    virtual string to_string() const;

    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;

    /**
     * @brief get all the non-null child nodes in the inner node
     * @param vector<RTBaseNode *> &vecValidChildNodes, all the non-null child nodes
     * @return void
     * @remarks
     */
    virtual void get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const;

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

    /**
     * @brief remove child node from inner node
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, removed node
     * @remarks
     */
    RTBaseNode *remove_child_node(uint8_t nKey);

    /**
     * @brief upgrade inner node level
     * @param
     * @return RTBaseNode *, upgraded node
     * @remarks
     */
    virtual RTBaseNode *upgrade();
    
    /**
     * @brief downgrade inner node level
     * @param
     * @return RTBaseNode, downgraded node
     * @remarks
     *          if there are 16 more valid nodes in the node, call this
     *          method will cause these nodes lose
     */
    virtual RTBaseNode *downgrade();
    
private:
    /*< child keys, 48 at most, 256 is for direct access */
    uint8_t m_arrayChildKeys[256];
    /*< child RTNode pointers, 48 at most */
    RTBaseNode *m_arrayChildNodes[48];
};

/**
 * @brief inner node 4
 */
class RTInnerNode256: public RTBaseNode
{
public:
    /**
     * @brief default constructor
     */
    RTInnerNode256();

    /**
     * @brief virutal destructor
     */
    virtual ~RTInnerNode256();

    /**
     * @brief show information about inner node 256
     * @param 
     * @return string
     * @remarks
     */
    virtual string to_string() const;

    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;

    /**
     * @brief get all the non-null child nodes in the inner node
     * @param vector<RTBaseNode *> &vecValidChildNodes, all the non-null child nodes
     * @return void
     * @remarks
     */
    virtual void get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const;

    /**
     * @brief is child full
     * @param
     * @return bool
     * @remarks
     */
    virtual bool is_child_full() const;

    /**
     * @brief is key exist
     * @param uint8_t nKey, key
     * @return bool
     * @remarks
     */
    virtual bool is_key_exists(uint8_t nKey) const;

    /**
     * @brief get child node according to key
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, child node pointer
     *                       null if ket not exist
     * @remarks
     */
    virtual RTBaseNode *get_child_node(uint8_t nKey) const;

    /**
     * @brief insert child node
     * @param uint8_t nKey, child key
     * @param RTBaseNode *pChildNode, child node
     * @return bool
     * @remarks
     */
    virtual bool insert_child_node(uint8_t nKey, RTBaseNode *pChildNode);

    /**
     * @brief remove child node from inner node
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, removed node
     * @remarks
     */
    virtual RTBaseNode *remove_child_node(uint8_t nKey);

    /**
     * @brief upgrade inner node level
     * @param
     * @return RTBaseNode *, upgraded node
     * @remarks
     */
    virtual RTBaseNode *upgrade();
    
    /**
     * @brief downgrade inner node level
     * @param
     * @return RTBaseNode, downgraded node
     * @remarks
     *          if there are 48 more valid nodes in the node, call this
     *          method will cause these nodes lose
     */
    virtual RTBaseNode *downgrade();
    
private:
    /*< child RTNode pointers, 256 at most */
    RTBaseNode *m_arrayChildNodes[256];
};

/**
 * @brief leaf node
 */
class RTLeafNode: public RTBaseNode
{
public:
    /**
     * @brief default constructor
     */
    RTLeafNode();

    /**
     * @brief virutal destructor
     */
    virtual ~RTLeafNode();

    /**
     * @brief show information about leaf node
     * @param 
     * @return string
     * @remarks
     */
    string to_string() const;

    /**
     * @brief get node type
     * @param
     * @return RTNodeType, node type enum
     * @remarks
     */
    virtual RTNodeType get_node_type() const;

    /**
     * @brief get all the non-null child nodes in the inner node
     * @param vector<RTBaseNode *> &vecValidChildNodes, all the non-null child nodes
     * @return void
     * @remarks
     */
    virtual void get_valid_child_nodes(vector<RTBaseNode *> &vecValidChildNodes) const;

    /**
     * @brief is child full
     * @param
     * @return bool
     * @remarks
     */
    virtual bool is_child_full() const;

    /**
     * @brief is key exist
     * @param uint8_t nKey, key
     * @return bool
     * @remarks
     */
    virtual bool is_key_exists(uint8_t nKey) const;

    /**
     * @brief get child node according to key
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, child node pointer
     *                       null if ket not exist
     * @remarks
     */
    virtual RTBaseNode *get_child_node(uint8_t nKey) const;

    /**
     * @brief insert child node
     * @param uint8_t nKey, child key
     * @param RTBaseNode *pChildNode, child node
     * @return bool
     * @remarks
     */
    virtual bool insert_child_node(uint8_t nKey, RTBaseNode *pChildNode);

    /**
     * @brief remove child node from inner node
     * @param uint8_t nKey, child key
     * @return RTBaseNode *, removed node
     * @remarks
     */
    virtual RTBaseNode *remove_child_node(uint8_t nKey);

    /**
     * @brief upgrade inner node level
     * @param
     * @return RTBaseNode *, upgraded node
     * @remarks
     */
    virtual RTBaseNode *upgrade();

    /**
     * @brief downgrade inner node level
     * @param
     * @return RTBaseNode, downgraded node
     * @remarks
     */
    virtual RTBaseNode *downgrade();
    
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
public:
    /**
     * @brief default constructor
     */
    Radix_Tree();

    /**
     * @brief destructor
     */
    ~Radix_Tree();

    /**
     * @brief print all the keys
     */
    string to_string() const;

    /**
     * @brief search strKey to the tree
     * @param const string &strKey, key string
     * @return bool, true if key exist
     *               false if key not in the tree
     * @remarks
     */
    bool search(const string &strKey) const;

    /**
     * @brief insert strKey to the tree
     * @param const string &strKey, key string
     * @return bool, true if insert success
     *               false if key already exists
     * @remarks
     */
    bool insert(const string &strKey);

    /**
     * @brief remove strKey from the tree
     * @param const string &strKey, the key need to remove
     * @return bool, true if key get removed
     *               false if key is not exist
     * @remarks
     */
    bool remove(const string &strKey);

private:
    /**
     * @brief private copy constructor
     */
    Radix_Tree(const Radix_Tree &oOtherRadixTree);

    /**
     * @brief private assign operator
     */
    Radix_Tree &operator=(const Radix_Tree &oOtherRadixTree);

    /**
     * @brief print pCurNode's result to the vecResult according to strParent
     * @param RTBaseNode *pCurNode, current root node
     * @param const string &strParent, parent string so far
     * @param vector<string> &vecResult, result strings
     * @return void
     * @remarks
     */
    void to_string_recursive(RTBaseNode *pCurNode, const string &strParent, vector<string> &vecResult) const;

    /**
     * @brief search key in pCurNode
     * @param RTBaseNode *pCurNode, current node
     * @param const string &strKey, key
     * @param size_t nStartIndex, start index to do match
     * @return bool, true if key exists
     *               false if key not exists
     */
    bool search_recursive(RTBaseNode *pCurNode, const string &strKey, size_t nStartIndex) const;

    /**
     * @brief replace pOldNode with pNewNode
     * @param RTBaseNode *pOldNode, old node
     * @param RTBaseNode *pNewNode, new node
     * @return void
     * @remarks
     */
    void replace_nodes(RTBaseNode *pOldNode, RTBaseNode *pNewNode);

    /**
     * @brief insert key into pCurNode
     * @param RTBaseNode *pCurNode, current node
     * @param const string &strKey, key
     * @param size_t nStartIndex, start index to do match
     * @return bool, true if success inserted
     *               false if key already exists
     */
    bool insert_recursive(RTBaseNode *pCurNode, const string &strKey, size_t nStartIndex);

    /**
     * @brief remove key in pCurNode
     * @param RTBaseNode *pCurNode, current node
     * @param const string &strKey, key
     * @param size_t nStartIndex, start index to do match
     * @return bool, true if key exists
     *               false if key not exists
     */
    bool remove_recursive(RTBaseNode *pCurNode, const string &strKey, size_t nStartIndex);

private:
    /*< root node of the tree */
    RTBaseNode *m_pRoot;
};

/**
 * @brief test radix tree data structure
 * @param
 * @return void
 * @remarks
 */
void radix_tree_test();

#endif // __RADIX_TREE_H__
