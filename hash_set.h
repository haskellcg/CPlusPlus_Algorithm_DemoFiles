/**************************************************************************
 * author: haskellcg
 * date: 2020-11-13
 * description: use hash funtion to implement set
 *************************************************************************/

#include "common_types.h"
#include "double_link_list.h"

#define CAPACITY_OF_HASHSET_LOG2 4

/**
 * @brief hash set with chaining to deal with collision
 */
class Chaining_Hash_Set
{
public:
    /**
     * @brief constructor
     */
    Chaining_Hash_Set();

    /**
     * @brief destructor
     */
    ~Chaining_Hash_Set();

    /**
     * @brief print everyone slots' size information
     * @param
     * @return string, like [x, y, z, ...]
     * @remarks
     */
    string to_string() const;

    /**
     * @brief number of element in the hash set
     * @param
     * @return size_t, number of element
     * @remarks
     */
    size_t size() const;

    /**
     * @brief search nKey if it is in the hash set
     * @param uint32_t nKey, key
     * @return NULL if it is not in the set, or return the DLNode
     * @remarks
     */
    DLNode *search(uint32_t nKey) const;

    /**
     * @brief insert nKey to the hash map 
     * @param uint32_t nKey, key
     * @return bool, true if inserted, false if nKey is not in hash set
     * @remarks
     */
    bool insert(uint32_t nKey);

    /**
     * @brief delete nKey from hash set
     * @param uint32_t nKey, key
     * @return bool, true if deleted, false if key not in the hash set
     * @remarks
     */
    bool remove(uint32_t nKey);

private:
    /**
     * @brief private copy constrcutor
     */
    Chaining_Hash_Set(const Chaining_Hash_Set &oOtherChainingHashSet);

    /**
     * @brief private assign operator
     */
    Chaining_Hash_Set &operator=(const Chaining_Hash_Set &oOtherChainingHashSet);

private:
    /*< use double linked list as chaining */
    Double_Link_List *m_arrayDDL[1 << CAPACITY_OF_HASHSET_LOG2];
};

/**
 * @brief test hash set
 * @param
 * @return void
 * @remarks
 */
void hash_set_test();
