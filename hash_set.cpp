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

void hash_set_test()
{
    print_highlight_msg(">>> Test hash set:\n");
    if (67 == multiplication_hash(123456, 14)){
        print_correct_msg("multiplication hash function correct\n");
    } else {
        print_error_msg("multiplication hash function error\n");
    }

    vector<uint32_t> vecInt;
    get_random_vector(vecInt, 1 << (CAPACITY_OF_HASHSET_LOG2 + 1));
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

    print_error_msg("no test case yet\n");
}
