/**************************************************************************
 * author: haskellcg
 * date: 2020-04-25
 * description: heap sort algorithm
 *************************************************************************/

#include "heap_sort.h"

Binary_Min_Heap::~Binary_Min_Heap()
{
    if (NULL != m_pArray){
        delete []m_pArray;
        m_pArray = NULL;
    }
    m_nSize = 0;
    m_nCapacity = 0;
}

Binary_Min_Heap::Binary_Min_Heap()
:   m_pArray(NULL),
    m_nSize(0),
    m_nCapacity(0)
{
}

Binary_Min_Heap::Binary_Min_Heap(const vector<uint32_t> &vecSrc)
{
    m_nSize = vecSrc.size();
    m_nCapacity = m_nSize << 1;
    m_pArray = new uint32_t[m_nCapacity];
    for (size_t i = 0; i < m_nSize; ++i){
        *(m_pArray + i) = vecSrc[i];
    }
}

Binary_Min_Heap::Binary_Min_Heap(const Binary_Min_Heap &oAnotherHeap)
{
    m_nSize = oAnotherHeap.m_nSize;
    m_nCapacity = oAnotherHeap.m_nCapacity;
    m_pArray = new uint32_t[m_nCapacity];
    for (size_t i = 0; i < m_nSize; ++i){
        *(m_pArray + i) = *(oAnotherHeap.m_pArray + i);
    }
}

Binary_Min_Heap &Binary_Min_Heap::operator=(const Binary_Min_Heap &oAnotherHeap)
{
    if (this == &oAnotherHeap){
        return *this;
    } else {
        if (NULL != m_pArray){
            delete []m_pArray;
            m_pArray = NULL;
        }
        m_nSize = oAnotherHeap.m_nSize;
        m_nCapacity = oAnotherHeap.m_nCapacity;
        m_pArray = new uint32_t[m_nCapacity];
        for (size_t i = 0; i < m_nSize; ++i){
            *(m_pArray + i) = *(oAnotherHeap.m_pArray + i);
        }
    }
    return *this;
}

string Binary_Min_Heap::to_string() const
{
    ostringstream ossResult;
    ossResult << "size:" << m_nSize << endl;
    ossResult << "capacity:" << m_nCapacity << endl;
    ossResult << "[";
    for (size_t i = 0; i < m_nSize; ++i){
        ossResult << *(m_pArray + i);
        if (i != (m_nSize - 1)){
            ossResult << ", ";
        }
    }
    ossResult << "]";
    return ossResult.str();
}

size_t Binary_Min_Heap::get_parent_index(size_t nIndex) const
{
    if (0 == nIndex){
        return nIndex;
    } else {
        return (((nIndex + 1) >> 1) - 1);
    }
}

size_t Binary_Min_Heap::get_left_child_index(size_t nIndex) const
{
    return (((nIndex + 1) << 1) - 1);
}

size_t Binary_Min_Heap::get_right_child_index(size_t nIndex) const
{
    return ((nIndex + 1) << 1);
}

void heap_sort(vector<uint32_t> &vecInt)
{
    // TODO: add code
    Binary_Min_Heap oHeapZero;
    print_normal_msg(oHeapZero.to_string() + "\n");
    Binary_Min_Heap oHeap(vecInt);
    print_normal_msg(oHeap.to_string() + "\n");
    oHeapZero = oHeap;
    print_normal_msg(oHeapZero.to_string() + "\n");
}

void heap_sort_test()
{
    print_highlight_msg(">>> Test heap sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    heap_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
