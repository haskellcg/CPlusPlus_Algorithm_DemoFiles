/**************************************************************************
 * author: haskellcg
 * date: 2020-11-13
 * description: some famouse string hash funtions collected from internet
 *************************************************************************/

#include "string_hash_funtions.h"

uint32_t BKDR_hash(const char *pString)
{
    /*< 31 131 1313 13131 131313 etc.. */
    uint32_t nSeed = 131; 
    uint32_t nHash = 0;

    while (*pString){
        nHash = nHash * nSeed + (*pString++);
    }

    return (nHash & 0x7FFFFFFF);
}

uint32_t SDBM_hash(const char *pString)
{
    uint32_t nHash = 0;
  
    while (*pString){
        /*< equivalent to: nHash = 65599 * nHash + (*pString++); */
        nHash = (*pString++) + (nHash << 6) + (nHash << 16) - nHash;
    }
                                   
    return (nHash & 0x7FFFFFFF);
}

uint32_t RS_hash(const char *pString)
{
    uint32_t nB = 378551;
    uint32_t nA = 63689;
    uint32_t nHash = 0;

    while (*pString){
        nHash = nHash * nA + (*pString++);
        nA *= nB;
    }

    return (nHash & 0x7FFFFFFF);
}

uint32_t AP_hash(const char *pString)
{
    uint32_t nHash = 0;

    for (int i=0; *pString; ++i){
        if ((i & 1) == 0){
            nHash ^= ((nHash << 7) ^ (*pString++) ^ (nHash >> 3));
        } else {
            nHash ^= (~((nHash << 11) ^ (*pString++) ^ (nHash >> 5)));
        }
    }

    return (nHash & 0x7FFFFFFF);
}

uint32_t JS_hash(const char *pString)
{
    uint32_t nHash = 1315423911;

    while (*pString){
        nHash ^= ((nHash << 5) + (*pString++) + (nHash >> 2));
    }

    return (nHash & 0x7FFFFFFF);
}

uint32_t DEK_hash(const char *pString)
{
    uint32_t nHash = 1315423911;  

    while (*pString){  
        nHash = ((nHash << 5) ^ (nHash >> 27)) ^ (*pString++);  
    }  

    return (nHash & 0x7FFFFFFF);
}

uint32_t FNV_hash(const char *pString)
{
    uint32_t nHash = 2166136261;  

    while (*pString){  
        nHash *= 16777619;  
        nHash ^= *pString++;  
    }  

    return (nHash & 0x7FFFFFFF);
}

uint32_t DJB_hash(const char *pString)
{
    uint32_t nHash = 5381;  

    while (*pString){  
        nHash += (nHash << 5) + (*pString++);  
    }  

    return (nHash & 0x7FFFFFFF);
}

uint32_t DJB2_hash(const char *pString)
{
    uint32_t nHash = 5381;  

    while (*pString){  
        nHash = nHash * 33 ^ (*pString++);  
    }  

    return (nHash & 0x7FFFFFFF);
}

uint32_t PJW_hash(const char *pString)
{
    uint32_t nBitsInUnignedInt = (uint32_t)(sizeof(unsigned int) * 8);
    uint32_t nThreeQuarters    = (uint32_t)((nBitsInUnignedInt  * 3) / 4);
    uint32_t nOneEighth        = (uint32_t)(nBitsInUnignedInt / 8);
    uint32_t nHighBits         = (uint32_t)(0xFFFFFFFF) << (nBitsInUnignedInt - nOneEighth);
    uint32_t nHash             = 0;
    uint32_t nTest             = 0;

    while (*pString){
        nHash = (nHash << nOneEighth) + (*pString++);
        if ((nTest = nHash & nHighBits) != 0){
            nHash = ((nHash ^ (nTest >> nThreeQuarters)) & (~nHighBits));
        }
    }

    return (nHash & 0x7FFFFFFF);
}

uint32_t ELF_hash(const char *pString)
{
    uint32_t nHash = 0;
    uint32_t nX    = 0;

    while (*pString){
        nHash = (nHash << 4) + (*pString++);
        if ((nX = nHash & 0xF0000000L) != 0){
            nHash ^= (nX >> 24);
            nHash &= ~nX;
        }
    }

    return (nHash & 0x7FFFFFFF);
}

void string_hash_funtions_test()
{
    print_highlight_msg(">>> Test string hash funtions: <<<\n");
}
