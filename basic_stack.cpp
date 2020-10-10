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
    // TODO
}

basic_stack &basic_stack::operator=(const basic_stack &oStack)
{
    // TODO
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
    // TODO
    vector<int32_t> vecInt;
    for (size_t i = 0; i < m_nSize; ++i){
        vecInt.push_back(*(m_pData + i));
    }
    return ::to_string(vecInt);
}

void basic_stack::push(int32_t nInt)
{
    // TODO
}

bool basic_stack::pop(int32_t &nInt)
{
    // TODO
    return true;
}

void basic_stack::reserve(size_t nCapacity)
{
    // TODO
}

void basic_stack_test()
{
    print_highlight_msg(">>> Test basic stack straucture:\n");
    int32_t arrayInt[10] = {76, 28, -34, -56, 89, 92, 66, 49, 15, 7};
    basic_stack oStack;
    for (size_t i = 0; i < 10; ++i){
        oStack.push(arrayInt[i]);
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
