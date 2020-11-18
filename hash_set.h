/**************************************************************************
 * author: haskellcg
 * date: 2020-11-13
 * description: use hash funtion to implement set
 *************************************************************************/

#ifndef __HASH_SET_H__
#define __HASH_SET_H__

#include "common_types.h"
#include "double_link_list.h"

#define CAPACITY_OF_HASHSET_LOG2 4
#define OPENADDRESS_INVALID_DATA MAX_UINT32

// DELETED is not same with INVALID, if not, 
// data inserted can't get found if it probing through DELETED data
#define OPENADDRESS_DELETED_DATA (MAX_UINT32 - 1)

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
 * @brief use open addressing to deal with collision
 */
class OpenAddress_Hash_Set
{
public:
    /**
     * @brief default constructor
     */
    OpenAddress_Hash_Set();

    /**
     * @brief destructor
     */
    ~OpenAddress_Hash_Set();

    /**
     * @brief print member information
     * @param
     * @return string, information
     * @remarks
     */
    string to_string() const;

    /**
     * @brief number of valid elements in the hash set
     * @param
     * @return size
     * @remarks
     */
    size_t size() const;

    /**
     * @brief search key in the hash set
     * @param uint32_t nKey, key
     * @param size_t &nIndex, index of the key if key is in hash set
     * @return bool, true if key is in hash set, false if not
     * @remarks
     */
    bool search(uint32_t nKey, size_t &nIndex) const;

    /**
     * @brief insert key to the hash set
     * @param uint32_t nKey, key
     * @return bool, true if inserted, false if not
     * @remarks
     */
    bool insert(uint32_t nKey);

    /**
     * @brief remove nKey from hash set
     * @param uint32_t nKey, key
     * @return bool, true if deleted, false if key not in the hash set
     * @remarks
     */
    bool remove(uint32_t nKey);

private:
    /**
     * @brief return the index need to be prob
     * @param uint32_t nKey, key
     * @param size_t nProbTimes, probe times
     * @return size_t, index of next probing
     * @remarks
     *          m -- capacity of the hash set
     *          i -- times of probing
     *          linear probing: 
     *                          h(k, i) = (h'(k) + i) mod m
     *          quadratic probing: 
     *                          h(k, i) = (h'(k) + (a * i) + (b * i ^ 2)) mod m
     *          double probing:
     *                          h(k, i) = (g(k) + i * f(k)) mod m
     *          we use double probing here
     */
    size_t probing(uint32_t nKey, size_t nProbTimes) const;

    /**
     * @brief private copy constructor
     */
    OpenAddress_Hash_Set(const OpenAddress_Hash_Set &oOtherOpenAddressHashSet);

    /**
     * @brief private assign funtion
     */
    OpenAddress_Hash_Set &operator=(const OpenAddress_Hash_Set &oOtherOpenAddressHashSet);

private:
    /*< capacity of the hash set */
    size_t m_nCapacity;
    /*< number of element in the hash set */
    size_t m_nSize;
    /*< store data */
    uint32_t *m_pData;
};

/**
 * @brief test hash set
 * @param
 * @return void
 * @remarks
 */
void hash_set_test();

#endif // __HASH_SET_H__
