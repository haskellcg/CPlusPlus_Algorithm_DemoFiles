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

string Binary_Min_Heap::to_friendly_string() const
{
    ostringstream ossResult;
    // only use root's height, cause children maybe have different height
    // so I calculate next level point to minus Height
    // level point is like [0, 0+2, 0+2+4, 0+2+4+8, ...]
    size_t nHeight= get_node_height(0);
    size_t nDepthPoint = 0;
    size_t nDepth = 1;
    for (size_t i = 0; i < m_nSize; ++i){
        size_t nTimes = (1 << (nHeight - 1));
        // left space number = (1 << nHeight)
        for (size_t j = 0; j < nTimes; ++j){
            ossResult << "\t";
        }
        ossResult << *(m_pArray + i);
        // right space number = (1 << nHeight)
        for (size_t j = 0; j < nTimes; ++j){
            ossResult << "\t";
        }
        // make sure i is in nDepthPoint and i is not the last one
        if ((i == nDepthPoint) && ((i + 1) < m_nSize)){
            ossResult << endl;
            nDepthPoint += (1 << nDepth);
            nDepth += 1;
            nHeight -= 1;
        }
    }
    return ossResult.str();
}

void Binary_Min_Heap::build_min_heap()
{
    for (int32_t i = (m_nSize >> 1); i >=0; --i){
        min_heapify(i);
    }
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

size_t Binary_Min_Heap::get_node_height(size_t nIndex) const
{
    if (nIndex >= m_nSize){
        return 0;
    } else {
        size_t nLeftHeight= get_node_height(get_left_child_index(nIndex));
        size_t nRightHeight= get_node_height(get_right_child_index(nIndex));
        if (nLeftHeight > nRightHeight){
            return (nLeftHeight + 1);
        } else {
            return (nRightHeight + 1);
        }
    }
}

void Binary_Min_Heap::min_heapify(size_t nRoot)
{
    while (true){
        size_t nLeftChild = get_left_child_index(nRoot);
        size_t nRightChild = get_right_child_index(nRoot);
        size_t nMinIndex = nRoot;
        // find the min value node between left,right
        // until no root is the min value
        if ((nLeftChild < m_nSize) && (*(m_pArray + nLeftChild) < *(m_pArray + nMinIndex))){
            nMinIndex = nLeftChild;
        }
        if ((nRightChild < m_nSize) && (*(m_pArray + nRightChild) < *(m_pArray + nMinIndex))){
            nMinIndex = nRightChild;
        }
        if (nRoot != nMinIndex){
            uint32_t nTemp = *(m_pArray + nRoot);
            *(m_pArray + nRoot) = *(m_pArray + nMinIndex);
            *(m_pArray + nMinIndex) = nTemp;
        } else {
            break;
        }
        nRoot = nMinIndex;
    }
}

void heap_sort(vector<uint32_t> &vecInt)
{
    // TODO: add code
    Binary_Min_Heap oHeap(vecInt);
    print_normal_msg(oHeap.to_string() + "\n");
    print_warning_msg(oHeap.to_friendly_string() + "\n");
    oHeap.build_min_heap();
    print_normal_msg(oHeap.to_string() + "\n");
    print_warning_msg(oHeap.to_friendly_string() + "\n");
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
