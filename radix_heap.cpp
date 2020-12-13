/**************************************************************************
 * author: haskellcg
 * date: 2020-12-05
 * description: radix heap data structure
 *************************************************************************/

#include "radix_heap.h"

Radix_Heap::Radix_Heap()
:   m_nLastDeleted(0)
{
    for (size_t i = 0; i < BUCKETS_NUMBER; ++i){
        m_vecBuckets.push_back(vector<uint32_t>());
    }
}

string Radix_Heap::to_string() const
{
    ostringstream ossResult;
    ossResult << "last deleted:" << m_nLastDeleted << "\n";
    ossResult << "radix heap:\n";
    for (size_t i = 0; i < BUCKETS_NUMBER; ++i){
        ossResult << "\t" << ::to_string(m_vecBuckets[i]);
        if ((BUCKETS_NUMBER - 1) != i){
            ossResult << "\n";
        }
    }
    return ossResult.str();
}

void Radix_Heap::insert(uint32_t nInt)
{
    size_t nBucketIndex = (size_t)(get_highest_set_bit_pos(nInt ^ m_nLastDeleted) + 1);
    m_vecBuckets[nBucketIndex].push_back(nInt);
}

uint32_t Radix_Heap::extract_min()
{
    uint32_t nMin = MAX_UINT32;
    for (size_t nBucketIndex = 0; nBucketIndex < BUCKETS_NUMBER; ++nBucketIndex){
        vector<uint32_t> &vecInts = m_vecBuckets[nBucketIndex];
        for (size_t i = 0; i < vecInts.size(); ++i){
            if (vecInts[i] < nMin){
                nMin = vecInts[i];
            }
        }
        if (MAX_UINT32 != nMin){
            break;
        }
    }

    m_nLastDeleted = nMin;
    for (size_t nBucketIndex = 0; nBucketIndex < BUCKETS_NUMBER; ++nBucketIndex){
        vector<uint32_t> &vecInts = m_vecBuckets[nBucketIndex];
        vector<uint32_t> vecNewInts;
        for (size_t i = 0; i < vecInts.size(); ++i){
            size_t nNewBucketIndex = (size_t)(get_highest_set_bit_pos(vecInts[i] ^ m_nLastDeleted) + 1);
            if (nNewBucketIndex != nBucketIndex){
                m_vecBuckets[nNewBucketIndex].push_back(vecInts[i]);
            } else {
                vecNewInts.push_back(vecInts[i]);
            }
        }
        m_vecBuckets[nBucketIndex] = vecNewInts;
    }

    // clear same min element
    m_vecBuckets[0].clear();
    return m_nLastDeleted;
}

int32_t Radix_Heap::get_highest_set_bit_pos(uint32_t nInt) const
{
    if (0 == nInt){
        return -1;
    } else {
        int32_t nHighestSetBitPos = -1;
        asm(
            "BSR %1, %0\n"
            : "=r" (nHighestSetBitPos)
            : "mr" (nInt)
            : "cc"
        );
        return nHighestSetBitPos;
    }
}

void radix_heap_test()
{
    print_highlight_msg(">>> Test radix heap:\n");
    uint32_t arrayInts[] = {461, 376, 233, 725, 748, 251, 913, 988, 188, 993,
                            964, 260, 260, 646, 404, 763, 737, 359, 179, 500,
                            347, 220, 286, 845, 620, 465, 828, 214, 552, 697,
                            454, 965, 973, 639, 691, 773, 790, 656, 813, 930,
                            701, 777, 242, 861, 423, 546, 676, 213, 806, 756,
                            0x8000ffff, 0x04000000, 0x00000008, 0x00000080, 0x00000200,
                            0x00000001, 0x00008000, 0x004EF0000, 0x000EEFEF};
    vector<uint32_t> vecInts;
    vecInts.insert(vecInts.end(), begin(arrayInts), end(arrayInts));
    print_normal_msg(to_string(vecInts) + "\n");

    Radix_Heap oRadixHeap;
    for (size_t i = 0; i < vecInts.size(); ++i){
        oRadixHeap.insert(vecInts[i]);
    }
    for (size_t i = 0; i < 35; ++i){
        oRadixHeap.extract_min();
    }
    print_warning_msg(oRadixHeap.to_string() + "\n");
    print_correct_msg("CORRECT.\n");
}
