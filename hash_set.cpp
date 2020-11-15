/**************************************************************************
 * author: haskellcg
 * date: 2020-11-13
 * description: use hash funtion to implement set
 *************************************************************************/

#include "hash_set.h"

Chaining_Hash_Set::Chaining_Hash_Set()
{
    for (int i = 0; i < 1 << CAPACITY_OF_HASHSET_LOG2; ++i){
        m_arrayDDL[i] = new Double_Link_List;
    }
}

Chaining_Hash_Set::~Chaining_Hash_Set()
{
    for (int i = 0; i < 1 << CAPACITY_OF_HASHSET_LOG2; ++i){
        if (NULL != m_arrayDDL[i]){
            delete m_arrayDDL[i];
            m_arrayDDL[i] = NULL;
        }
    }
}

string Chaining_Hash_Set::to_string() const
{
    ostringstream ossResult;
    ossResult << "[";
    for (int i = 0; i < 1 << CAPACITY_OF_HASHSET_LOG2; ++i){
        if (0 != i){
            ossResult << ", ";
        }
        ossResult << m_arrayDDL[i]->size();
    }
    ossResult << "]";

    return ossResult.str();
}

size_t Chaining_Hash_Set::size() const
{
    size_t nSize = 0;
    for (int i = 0; i < 1 << CAPACITY_OF_HASHSET_LOG2; ++i){
        nSize += m_arrayDDL[i]->size();
    }
    return nSize;
}

DLNode *Chaining_Hash_Set::search(uint32_t nKey) const
{
    size_t nSlotIndex = multiplication_hash(nKey, CAPACITY_OF_HASHSET_LOG2);
    return m_arrayDDL[nSlotIndex]->search(nKey);
}

bool Chaining_Hash_Set::insert(uint32_t nKey)
{
    size_t nSlotIndex = multiplication_hash(nKey, CAPACITY_OF_HASHSET_LOG2);
    if (NULL == m_arrayDDL[nSlotIndex]->search(nKey)){
        m_arrayDDL[nSlotIndex]->insert(nKey);
        return true;
    } else {
        return false;
    }
}

bool Chaining_Hash_Set::remove(uint32_t nKey)
{
    size_t nSlotIndex = multiplication_hash(nKey, CAPACITY_OF_HASHSET_LOG2);
    DLNode *pKeyNode = m_arrayDDL[nSlotIndex]->search(nKey);
    if (NULL != pKeyNode){
        m_arrayDDL[nSlotIndex]->remove(pKeyNode);
        return true;
    } else {
        return false;
    }
}

OpenAddress_Hash_Set::OpenAddress_Hash_Set()
:   m_nCapacity(1 << CAPACITY_OF_HASHSET_LOG2),
    m_nSize(0),
    m_pData(NULL)
{
    m_pData = new uint32_t[m_nCapacity];
    for (size_t i = 0; i < m_nCapacity; ++i){
        *(m_pData + i) = OPENADDRESS_INVALID_DATA;
    }
}

OpenAddress_Hash_Set::~OpenAddress_Hash_Set()
{
    m_nCapacity = 0;
    m_nSize = 0;
    if (NULL != m_pData){
        delete []m_pData;
        m_pData = NULL;
    }
}

string OpenAddress_Hash_Set::to_string() const
{
    ostringstream ossResult;
    ossResult << "capacity:" << m_nCapacity << "\n";
    ossResult << "size:" << m_nSize << "\n";
    ossResult << "data:[";
    for (size_t i = 0; i < m_nCapacity; ++i){
        if (0 != i){
            ossResult << ", ";
        }
        if (OPENADDRESS_INVALID_DATA == *(m_pData + i)){
            ossResult << "INVALID";
        } else if (OPENADDRESS_DELETED_DATA == *(m_pData + i)){
            ossResult << "DELETED";
        } else {
            ossResult << *(m_pData + i);
        }
    }
    ossResult << "]";
    return ossResult.str();
}

size_t OpenAddress_Hash_Set::size() const
{
    return m_nSize;
}

bool OpenAddress_Hash_Set::search(uint32_t nKey, size_t &nIndex) const
{
    size_t nProbTimes = 0;
    while (nProbTimes < m_nCapacity){
        size_t nProbIndex = probing(nKey, nProbTimes);
        if (nKey == *(m_pData + nProbIndex)){
            nIndex = nProbIndex;
            return true;
        } else if (OPENADDRESS_INVALID_DATA == *(m_pData + nProbIndex)){
            break;
        }
        ++nProbTimes;
    }
    return false;
}

bool OpenAddress_Hash_Set::insert(uint32_t nKey)
{
    size_t nProbTimes = 0;
    while (nProbTimes < m_nCapacity){
        size_t nProbIndex = probing(nKey, nProbTimes);
        if ((OPENADDRESS_INVALID_DATA == *(m_pData + nProbIndex))
            || (OPENADDRESS_DELETED_DATA == *(m_pData + nProbIndex))){
            *(m_pData + nProbIndex) = nKey;
            ++m_nSize;
            return true;
        }
        ++nProbTimes;
    }
    return false;
}

bool OpenAddress_Hash_Set::remove(uint32_t nKey)
{
    size_t nProbTimes = 0;
    while (nProbTimes < m_nCapacity){
        size_t nProbIndex = probing(nKey, nProbTimes);
        if (nKey == *(m_pData + nProbIndex)){
            *(m_pData + nProbIndex) = OPENADDRESS_DELETED_DATA;
            --m_nSize;
            return true;
        } else if (OPENADDRESS_INVALID_DATA == *(m_pData + nProbIndex)){
            break;
        }
        ++nProbTimes;
    }
    return false;
}

size_t OpenAddress_Hash_Set::probing(uint32_t nKey, size_t nProbTimes) const
{
    size_t nGK = division_hash(nKey, m_nCapacity);
    return ((nGK + (nProbTimes * multiplication_hash(nKey, CAPACITY_OF_HASHSET_LOG2))) % m_nCapacity);
}

void hash_set_test()
{
    print_highlight_msg(">>> Test hash set:\n");
    if (67 == multiplication_hash(123456, 14)){
        print_correct_msg("multiplication hash function correct\n");
    } else {
        print_error_msg("multiplication hash function error\n");
    }

    vector<uint32_t> vecInt;
    get_random_vector(vecInt, 1 << (CAPACITY_OF_HASHSET_LOG2 + 0));
    print_highlight_msg("data to be inserted:\n");
    print_normal_msg(to_string(vecInt) + "\n");

    Chaining_Hash_Set oChainingHashSet;

    print_highlight_msg("chaining hash set state when inserting:\n");

    for (size_t i = 0; i < vecInt.size(); ++i){
        if (!oChainingHashSet.insert(vecInt[i])){
            print_warning_msg("data contains same key\n");
        }
    }
    print_normal_msg(oChainingHashSet.to_string() + "\n");

    print_highlight_msg("chaining hash set state when deleteing:\n");

    for (size_t i = 0; i < vecInt.size(); ++i){
        if (!oChainingHashSet.remove(vecInt[i])){
            print_warning_msg("can't find key\n");
        }
    }
    print_normal_msg(oChainingHashSet.to_string() + "\n");

    OpenAddress_Hash_Set oOpenAddressHashSet;

    print_highlight_msg("open addressing hash set state when inserting:\n");

    for (size_t i = 0; i < vecInt.size(); ++i){
        if (!oOpenAddressHashSet.insert(vecInt[i])){
            print_warning_msg("data contains same key\n");
        }
    }
    print_normal_msg(oOpenAddressHashSet.to_string() + "\n");

    print_highlight_msg("open addressing hash set state when deleteing:\n");

    for (size_t i = 0; i < vecInt.size(); ++i){
        if (!oOpenAddressHashSet.remove(vecInt[i])){
            print_warning_msg("can't find key\n");
        }
    }
    print_normal_msg(oOpenAddressHashSet.to_string() + "\n");
}
