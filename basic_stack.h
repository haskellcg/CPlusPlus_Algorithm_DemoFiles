/**************************************************************************
 * author: haskellcg
 * date: 2020-09-30
 * description: stack data structure
 *************************************************************************/

#ifndef __BASIC_STACK__H__
#define __BASIC_STACK__H__

#include "common_types.h"

/**
 * @brief basic stack data structure
 */
class Basic_Stack
{
public:
    /**
     * @brief constructor
     * @param
     * @return
     * @remarks
     */
    Basic_Stack();

    /**
     * @brief copy constructor
     * @param const Basic_Stack &oStack, other stack
     * @return
     * @remarks
     */
    Basic_Stack(const Basic_Stack &oStack);

    /**
     * @brief override operator =
     * @param const Basic_Stack &oStack, other stack
     * @return Basic_Stack &, *this
     * @remarks
     */
    Basic_Stack &operator=(const Basic_Stack &oStack);

    /**
     * @brief destructor
     * @param
     * @return
     * @remarks
     */
    ~Basic_Stack();
    
    /**
     * @brief get the size of the stack
     * @param
     * @return size_t, number of element in the stack
     * @remarks
     */
    size_t size() const;

    /**
     * @brief print detail information
     * @param
     * @return string
     * @remarks
     */
    string to_string() const;

    /**
     * @brief push nInt into stack
     * @param int32_t nInt,
     * @return void
     * @remarks
     */
    void push(int32_t nInt);

    /**
     * @brief get the top element of stack and remove it from stack
     * @param int32_t &nInt, top element
     * @return bool, false if no element left
     * @remarks
     */
    bool pop(int32_t &nInt);

private:
    /**
     * @brief change the capacity of the stack
     * @param size_t nCapacity, new capacity
     * @return void
     * @remarks
     */
    void reserve(size_t nCapacity);

private:
    /*< data of stack */
    int32_t *m_pData;
    /*< number of element in the stack */
    size_t m_nSize;
    /*< total capacity */
    size_t m_nCapacity;
};

/**
 * @brief test data structure stack
 * @param
 * @return void
 * @remarks
 */
void basic_stack_test();

#endif // __BASIC_STACK__H__
