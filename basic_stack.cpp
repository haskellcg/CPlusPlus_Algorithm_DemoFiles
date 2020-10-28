/**************************************************************************
 * author: haskellcg
 * date: 2020-09-30
 * description: stack data structure
 *************************************************************************/

#include "basic_stack.h"

basic_stack::basic_stack()
{
    m_nCapacity = 1;
    m_nSize = 0;
    m_pData = new int32_t[m_nCapacity];
}

basic_stack::basic_stack(const basic_stack &oStack)
{
    m_nCapacity = oStack.m_nCapacity;
    m_nSize = oStack.m_nSize;
    m_pData = new int32_t[m_nCapacity];
    for (size_t i = 0; i < m_nSize; ++i){
        *(m_pData + i) = *(oStack.m_pData + i);
    }
}

basic_stack &basic_stack::operator=(const basic_stack &oStack)
{
    if (&oStack == this){
        return *this;
    }
    delete []m_pData;
    m_nCapacity = oStack.m_nCapacity;
    m_nSize = oStack.m_nSize;
    m_pData = new int32_t[m_nCapacity];
    for (size_t i = 0; i < m_nSize; ++i){
        *(m_pData + i) = *(oStack.m_pData + i);
    }
    return *this;
}

basic_stack::~basic_stack()
{
    if (NULL != m_pData){
        delete []m_pData;
    }
    m_nSize = 0;
    m_nCapacity = 0;
}

size_t basic_stack::size() const
{
    return m_nSize;
}

string basic_stack::to_string() const
{
    ostringstream oss;
    vector<int32_t> vecInt;
    for (size_t i = 0; i < m_nSize; ++i){
        vecInt.push_back(*(m_pData + i));
    }
    oss << "Data:" << ::to_string(vecInt) << "\n";
    oss << "Size:" << m_nSize << "\n";
    oss << "Capacity:" << m_nCapacity;
    return oss.str();
}

void basic_stack::push(int32_t nInt)
{
    if (m_nSize >= m_nCapacity){
        reserve(m_nCapacity << 1);
    }
    *(m_pData + m_nSize) = nInt;
    ++m_nSize;
}

bool basic_stack::pop(int32_t &nInt)
{
    if (m_nSize > 0){
        nInt = *(m_pData + m_nSize - 1);
        --m_nSize;
        return true;
    } else {
        return false;
    }
}

void basic_stack::reserve(size_t nCapacity)
{
    if (nCapacity > m_nCapacity){
        int32_t *pNewData = new int32_t[nCapacity];
        for (size_t i = 0; i < m_nSize; ++i){
            *(pNewData + i) = *(m_pData + i);
        }
        delete []m_pData;
        m_pData = pNewData;
        m_nCapacity = nCapacity;
    }
}

void basic_stack_test()
{
    print_highlight_msg(">>> Test basic stack structure:\n");
    int32_t arrayInt[10] = {76, 28, -34, -56, 89, 92, 66, 49, 15, 7};
    basic_stack oStack;
    for (size_t i = 0; i < 10; ++i){
        oStack.push(arrayInt[i]);
        // print_warning_msg(oStack.to_string() + "\n");
    }
    if (10 != oStack.size()){
        print_error_msg("basic stack size error\n");
    } else {
        print_correct_msg("basic stack size correct\n");
    }
    basic_stack oStackCopy;
    oStackCopy = oStack;
    if (10 != oStackCopy.size()){
        print_error_msg("basic stack copy size error\n");
    } else {
        print_correct_msg("basic stack copy size correct\n");
    }
    int32_t nTop = MIN_INT32;
    oStack.pop(nTop);
    oStack.pop(nTop);
    oStack.pop(nTop);
    if (arrayInt[7] != nTop){
        print_error_msg("basic stack pop error\n");
    } else {
        print_correct_msg("basic stack pop correct\n");
    }
}
