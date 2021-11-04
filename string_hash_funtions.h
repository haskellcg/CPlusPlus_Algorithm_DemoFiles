/**************************************************************************
 * author: haskellcg
 * date: 2020-11-13
 * description: some famouse string hash funtions collected from internet
 *************************************************************************/

#ifndef __STRING_HASH_FUNTIONS_H__
#define __STRING_HASH_FUNTIONS_H__

#include "common_types.h"

/**
 * @brief more about hash functions
 * @remarks
 *          murmurhash: https://en.wikipedia.org/wiki/MurmurHash)
 *          hash function: http://www.azillionmonkeys.com/qed/hash.html)
 *          hash funtions and test: https://www.strchr.com/hash_functions)
 *          non-cryptographic hash functions: https://en.wikipedia.org/wiki/List_of_hash_functions#Non-cryptographic_hash_functions)
 *          hash functions: http://burtleburtle.net/bob/hash/doobs.html
 *          SipHash: https://en.wikipedia.org/wiki/SipHash)
 */

/**
 * @brief BKDR hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          本算法由于在Brian Kernighan与Dennis Ritchie的《The C Programming Language》一书被展示而得名，
 *          是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法（累乘因子为31）
 */
uint32_t BKDR_hash(const char *pString);

/**
 * @brief SDBM hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          本算法是由于在开源项目SDBM（一种简单的数据库引擎）中被应用而得名，它与BKDRHash思想一致，
 *          只是种子不同而已
 */
uint32_t SDBM_hash(const char *pString);

/**
 * @brief RS hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          因Robert Sedgwicks在其《Algorithms in C》一书中展示而得名
 */
uint32_t RS_hash(const char *pString);

/**
 * @brief AP hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          由Arash Partow发明的一种hash算法
 */
uint32_t AP_hash(const char *pString);

/**
 * @brief JS hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          由Justin Sobel发明的一种hash算法
 */
uint32_t JS_hash(const char *pString);

/**
 * @brief DEK hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          本算法是由于Donald E. Knuth在《Art Of Computer Programming Volume 3》中展示而得名
 */
uint32_t DEK_hash(const char *pString);

/**
 * @brief FNV hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          Unix system系统中使用的一种著名hash算法，后来微软也在其hash_map中实现
 */
uint32_t FNV_hash(const char *pString);

/**
 * @brief DJB hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          由Daniel J. Bernstein教授发明的一种hash算法
 */
uint32_t DJB_hash(const char *pString);

/**
 * @brief DJB2 hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          由Daniel J. Bernstein 发明的另一种hash算法
 */
uint32_t DJB2_hash(const char *pString);

/**
 * @brief PJW hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          本算法是基于AT&T贝尔实验室的Peter J. Weinberger的论文而发明的一种hash算法
 */
uint32_t PJW_hash(const char *pString);

/**
 * @brief ELF hash
 * @param const char *pString, string
 * @return uint32_t,
 * @remarks
 *          由于在Unix的Extended Library Function被附带而得名的一种hash算法，它其实就是PJW Hash的变形
 */
uint32_t ELF_hash(const char *pString);

/**
 * @brief test string hash funtions
 * @param
 * @return void
 * @remarks
 */
void string_hash_funtions_test();

#endif // __STRING_HASH_FUNTIONS_H__
