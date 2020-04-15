/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmUtil.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2019/12/30 16:50:10
// Modify time 	: 2019/12/30 16:50:10
// Note         :
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __VM_UTIL_H__
#define __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
#ifndef   _INC_STDIO
#   include<stdio.h>
#endif // _INC_STDIO

#ifndef   _INC_STDARG
#   include <stdarg.h>
#endif // _INC_STDARG

#ifndef   _INC_STRING
#   include <string.h>
#endif // _INC_STRING

#ifndef   __VM_CFG_H__
#   include <vmCfg.h>
#endif // __VM_CFG_H__

#ifndef   __VM_VERIFY_H__
#   include <vmVerify.h>
#endif // __VM_VERIFY_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :

//*
#ifndef    vMemZero
#   define vMemZero(szBuf)          v_memzero(&szBuf,sizeof(szBuf))
#endif  // vMemZero

#ifndef    vMemSet
#   define vMemSet(szBuf, ciFlag)   v_memset(&szBuf,ciFlg,sizeof(szBuf))
#endif  // vMemSet

#ifndef    vStrZero
#   define vStrZero(szBuf)          v_strzero(&szBuf,vStrSizeof(szBuf))
#endif  // vStrZero

#ifndef    vStrSet
#   define vStrSet(szBuf, ciFlag)   v_strset(&szBuf,ciFlg,vStrSizeof(szBuf))
#endif  // vStrSet

#ifndef    vStrPosBegin
#   define vStrPosBegin             vMinsInt
#endif  // vStrPosBegin

#ifndef    vStrPosEnded
#   define vStrPosEnded             vMinsInt
#endif  // vStrPosEnded
//*/
/////////////////////////////////////////////////////////////////////////////////////////
//#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
// --------------------------------------------------------------------------------------
// 重构windows中的str,mem系列函数

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strchr(...)
// Brief     : 在字节串中搜索第一次出现的ciVal值地址
// Return    : tchar*                           - 查找的地址
//             nullptr                          - 未查找的指定的数据
// Parameter : cpBuf                            - 被搜索的字符串
//             ciVal                            - 标识数据
inline tchar* v_strchr(tchar* const cpBuf, const int ciVal)
{
    // 验证输入参数
    _VERIFY_(v_strchr(),cpBuf);

    return vStrchr(cpBuf, ciVal);
}
// End of function v_strchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strrchr(...)
// Brief     : 在字节串中反向搜索第一次出现的ciVal地址
// Return    : tchar*                           - 查找的地址
//             nullptr                          - 未查找的指定的数据
// Parameter : cpBuf                            - 被搜索的字符串
//             ciVal                            - 标识数据
inline tchar* v_strrchr( tchar* const cpBuf, const int ciVal )
{
    // 验证输入参数
    _VERIFY_(v_strrchr(), cpBuf);

    return vStrrchr(cpBuf, ciVal);
}
// End of function v_strrchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strstr(...)
// Brief     : 在字节串中查找第一次出现子字符串的地址
// Return    : tchar*                           - 查找的地址，当cpSubStr为null时，返回cpBuf
//             nullptr                          - 未查找到指定的字符串
// Parameter : cpBuf                            - 被搜索的字符串
//             cpSubStr                         - 需要查找的子字符串
inline tchar* v_strstr( tchar* const cpBuf, const tchar* const cpSubStr )
{
    // 验证输入参数
    _VERIFY_(v_strstr(), cpBuf);

    return vStrstr(cpBuf, cpSubStr);
}
// End of function v_strstr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcmp_equl(...)
// Brief     : 按字典顺序判断pStr1字符串是否等于pStr2字符串
// Return    : true                             - 两个字符串相等
//             false                            - 两个字符串不相等
// Parameter : pStr1                            - 字符串之一
//             pStr2                            - 字符串之一
inline bool v_strcmp_equl( const tchar* const pStr1, const tchar* const pStr2 )
{
    // 验证输入参数
    _VERIFY_2_(v_strcmp_equl(), pStr1, pStr2);

    int liRet  = vStrcmp(pStr1, pStr2);
    if ( liRet == 0 ) 
        return  true;

    return false;
}
// End of function v_strcmp_equl(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcmp_more(...)
// Brief     : 按字典顺序判断pStr1字符串是否大于pStr2字符串
// Return    : true                             - pStr1字符串大于pStr2字符串
//             false                            - pStr1字符串小于或等于pStr2字符串
// Parameter : pStr1                            - 字符串之一
//             pStr2                            - 字符串之一
inline bool v_strcmp_more(const tchar* const pStr1, const tchar* const pStr2)
{
    // 验证输入参数
    _VERIFY_2_(v_strcmp_more(), pStr1, pStr2);

    int liRet = vStrcmp(pStr1, pStr2);
    if (liRet > 0) 
        return  true;

    return false;
}
// End of function v_strcmp_more(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcmp_less(...)
// Brief     : 按字典顺序判断pStr1字符串是否小于pStr2字符串
// Return    : true                             - pStr1字符串小于pStr2字符串
//             false                            - pStr1字符串大于或等于pStr2字符串
// Parameter : pStr1                            - 字符串之一
//             pStr2                            - 字符串之一
inline bool v_strcmp_less(const tchar* const pStr1, const tchar* const pStr2)
{
    // 验证输入参数
    _VERIFY_2_(v_strcmp_less(), pStr1, pStr2);

    int liRet = vStrcmp(pStr1, pStr2);
    if (liRet < 0) 
        return  true;

    return false;
}
// End of function v_strcmp_less(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcmp_equl(...)
// Brief     :
// Return    : true                             - 两个字符串相等
//             false                            - 两个字符串不相等
// Parameter : pStr1                            - 字符串之一
//             pStr2                            - 字符串之一
inline bool v_strncmp_equl(const tchar* const pStr1, const tchar* const pStr2, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_strncmp_equl(), pStr1, pStr2);

    int liRet = vStrncmp(pStr1, pStr2, csztDataLen);
    if (liRet == 0)
        return  true;

    return false;
}
// End of function v_strcmp_equl(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcmp_more(...)
// Brief     :
// Return    : true                             - pStr1字符串大于pStr2字符串
//             false                            - pStr1字符串小于或等于pStr2字符串
// Parameter : pStr1                            - 字符串之一
//             pStr2                            - 字符串之一
inline bool v_strncmp_more(const tchar* const pStr1, const tchar* const pStr2,const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_strncmp_more(), pStr1, pStr2);

    int liRet = vStrncmp(pStr1, pStr2,csztDataLen);
    if (liRet > 0)
        return  true;

    return false;
}
// End of function v_strcmp_more(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcmp_less(...)
// Brief     :
// Return    : true                             - pStr1字符串小于pStr2字符串
//             false                            - pStr1字符串大于或等于pStr2字符串
// Parameter : pStr1                            - 字符串之一
//             pStr2                            - 字符串之一
inline bool v_strncmp_less(const tchar* const pStr1, const tchar* const pStr2, const size_t csztDataLen )
{
    // 验证输入参数
    _VERIFY_2_(v_strncmp_less(), pStr1, pStr2);

    int liRet = vStrncmp(pStr1, pStr2, csztDataLen);
    if (liRet < 0)
        return  true;

    return false;
}
// End of function v_strcmp_less(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strncat(...)
// Brief     : 将由cpSrc字节串的副本中csztDataLen长度的字节追加到由pDst字节串的末尾
// Return    : tchar*                                - 返回复制完的字符串地址
//             nullptr                              - 出现异常
// Parameter : pDst                                 - 目的内存区地址
//             csztDstSize                          - 目的内存区大小
//             cpSrc                                - 源字符串
//             csztDataLen                          - 需复制的字符串大小
inline tchar* v_strncat(tchar* const pDst, const size_t csztDstSize, const tchar* const cpSrc, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_strncat(), pDst, cpSrc);

#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = vStrncat_s(pDst, csztDstSize, cpSrc, csztDataLen);
    _ASSERT_(v_strncat(), (loRet==0) );

    return pDst;
#else
    return vStrncat(pDst, cpSrc, csztDataLen);
#endif
}
// End of function v_strncat(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcat(...)
// Brief     : 将由cpSrc字节串的副本追加到由pDst字节串的末尾
// Return    : tchar*                                - 返回复制完的字符串地址
//             nullptr                              - 出现异常
// Parameter : pDst                                 - 目的内存区地址
//             csztDstSize                          - 目的内存区大小
//             cpSrc                                - 源字符串
inline tchar* v_strcat(tchar* const pDst, const size_t csztDstSize, const tchar* const cpSrc)
{
    // 验证输入参数
    _VERIFY_2_(v_strcat(), pDst, cpSrc);

#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = vStrcat_s(pDst, csztDstSize, cpSrc);
    _ASSERT_(v_strcat(), (loRet==0) );

    return pDst;
#else
    return strcat(pDst, cpSrc);
#endif
}
// End of function v_strcat(...)
///////////////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strncpy(...)
// Brief     : 将由cpSrc字节串的副本中csztDataLen长度的字节复制到由pDst指向的缓存区中
// Return    : tchar*                                - 返回复制完的字符串地址
//             nullptr                              - 出现异常
// Parameter : pDst                                 - 目的内存区地址
//             csztDstSize                          - 目的内存区大小
//             cpSrc                                - 源字符串
//             csztDataLen                          - 需复制的字符串大小
inline size_t v_strncpy(tchar* const pDst, const size_t csztDstSize, const tchar* const cpSrc, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_strncpy(), pDst, cpSrc);

    size_t lsztDatalen = vMin((csztDstSize-sizeof(tchar)),csztDataLen);
    
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    // errno_t loRet = strncpy_s(pDst, csztDstSize, cpSrc, csztDataLen);
    errno_t loRet = vMemcpy_s(pDst, csztDstSize, cpSrc, lsztDatalen);
    _ASSERT_(v_strncpy(), (loRet==0) );

    *(pDst+lsztDatalen) = tchar(0x00);
    return csztDataLen;
#else
    tchar* lpEnd = vMemcpy(pDst, cpSrc, lsztDatalen)
    if ( lpEnd == nullptr ){ return 0; }
    _VERIFY_(v_strncpy(), lpEnd);

    size_t lsztCopied= lpEnd -pDst;
    return lsztCopied;
#endif
}
// End of function v_strncpy(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcpy(...)
// Brief     : 将由cpSrc字节串的副本复制到由pDst指向的缓存区中
// Return    : tchar*                                - 返回复制完的字符串地址
//             nullptr                              - 出现异常
// Parameter : pDst                                 - 目的内存区地址
//             csztDstSize                          - 目的内存区大小
//             cpSrc                                - 源字符串
inline size_t v_strcpy( tchar* const pDst, const size_t csztDstSize, const tchar* const cpSrc )
{
    // 验证输入参数
    _VERIFY_2_(v_strcpy(), pDst, cpSrc);

    size_t lsztSrcLen = vStrlen(cpSrc);
    size_t lsztDataLen = vMin( csztDstSize, lsztSrcLen );

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    //errno_t loRet = strcpy_s(pDst,csztDstSize,cpSrc);
    errno_t loRet = vMemcpy_s(pDst,csztDstSize,cpSrc, lsztDataLen);
    _ASSERT_(v_strcpy(), (loRet==0) );
    
    return lsztDataLen;
#else
    tchar* lpEnd = vStrcpy(pDst, cpSrc)
    _VERIFY_(v_strncpy(), lpEnd);
    
    size_t lsztCopied = lpEnd = pDst;
    return lsztCopied;
#endif
}
// End of function v_strcpy(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memzero(...)
// Brief     : 将从pBuf开始csztDataLen长的缓存区的数据置为0x00
// Return    : void
// Parameter : pBuf                                 - 缓存区地址
//             csztDataLen                          - 缓存区大小
inline void v_memzero(void* const pBuf, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_(v_memzero(), pBuf);

    memset(pBuf, 0x00, csztDataLen);
}
// End of function v_memzero(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memset(...)
// Brief     : 将从pBuf开始csztDataLen长的缓存区的数据置为ciVal
// Return    : void
// Parameter : pBuf                                 - 缓存区地址
//             ciVal                                - 需要设置的数值
//             csztDataLen                          - 设置的数据大小
inline void v_memset(void* const pBuf, const int ciVal, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_(v_memset(), pBuf);
    
    memset(pBuf, ciVal, csztDataLen);
}
// End of function v_memset(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strzero(...)
// Brief     : 将从pBuf开始csztDataLen长的缓存区的数据置为0x00
// Return    : void
// Parameter : pBuf                                 - 缓存区地址
//             csztDataLen                          - 缓存区大小
inline void v_strzero(tchar* const pBuf, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_(v_strzero(), pBuf);

    vMemset((tchar* const)pBuf, 0x00, csztDataLen);
}
// End of function v_strzero(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strset(...)
// Brief     : 将从pBuf开始csztDataLen长的缓存区的数据置为ciVal
// Return    : void
// Parameter : pBuf                                 - 缓存区地址
//             ciVal                                - 需要设置的数值
//             csztDataLen                          - 设置的数据大小
inline void v_strset(tchar* const pBuf, const int ciVal, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_(v_strset(), pBuf);

    vMemset(pBuf, ciVal, csztDataLen);
}
// End of function v_strset(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memchr(...)
// Brief     : 在cpBuf指向的缓存区中查找第一次出现ciVal的地址
// Return    : void
// Parameter : cpBuf                                - 待查找的缓存区地址
//             iVal                                 - 需要查找的数值
//             csztLookforLen                       - 待查找的缓存区长度
inline void* v_memchr( void* const pBuf, const int iVal, const size_t csztLookforLen)
{
    // 验证输入参数
    _VERIFY_(v_memchr(), pBuf);

    return vMemchr((tchar* const)pBuf, iVal, csztLookforLen);
}
// End of function v_memchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memicmp_less(...)
// Brief     : 按字典顺序比较缓存区cpBuf1于缓存区cpBuf2，长度为csztDataLen，不区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
inline bool v_memicmp_less(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_memicmp_less(), cpBuf1, cpBuf2);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = vMemicmp((const tchar* const)cpBuf1, (const tchar* const)cpBuf2, csztDataLen);
    if (liRet < 0)
        return true;
    return false; 
#else
    int liRet = vMemicmp((const tchar* const)cpBuf1, (const tchar* const)cpBuf2, csztDataLen);
    if (liRet < 0)
        return true;
    return false; 
#endif
}
// End of function v_memicmp_less(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memicmp_more(...)
// Brief     : 按字典顺序比较缓存区cpBuf1于缓存区cpBuf2，长度为csztDataLen，不区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
inline bool v_memicmp_more(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_memicmp_more(), cpBuf1, cpBuf2);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = vMemicmp((const tchar* const)cpBuf1, (const tchar* const)cpBuf2, csztDataLen);
    if (liRet > 0)
        return true;
    return false; 
#else
    int liRet = vMemicmp((const tchar* const)cpBuf1, (const tchar* const)cpBuf2, csztDataLen);
    if (liRet > 0)
        return true;
    return false;
#endif
}
// End of function v_memicmp_more(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memicmp_equl(...)
// Brief     : 按字典顺序比较缓存区cpBuf1于缓存区cpBuf2，长度为csztDataLen，不区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
inline bool v_memicmp_equl(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_memicmp_equl(), cpBuf1, cpBuf2);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = vMemicmp((const tchar* const)cpBuf1, (const tchar* const)cpBuf2, csztDataLen);
    if (liRet == 0)
        return true;
    return false;
#else
    int liRet = vMemicmp((const tchar* const)cpBuf1, (const tchar* const)cpBuf2, csztDataLen);
    if (liRet == 0)
        return true;
    return false;
#endif
}
// End of function v_memicmp_equl(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memcmp_less(...)
// Brief     : 按字典顺序比较字符串cpBuf1于字符串cpBuf2，长度为csztDataLen，区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
inline bool v_memcmp_less(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_memcmp_less(), cpBuf1, cpBuf2);

    int liRet = vMemcmp((const tchar* const)cpBuf1, (const tchar* const)cpBuf2, csztDataLen);
    if (liRet < 0)
        return true;

    return  false;
}
// End of function v_memcmp_less(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memcmp_more(...)
// Brief     : 按字典顺序比较字符串cpBuf1于字符串cpBuf2，长度为csztDataLen，区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
inline bool v_memcmp_more(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_2_(v_memcmp_more(), cpBuf1, cpBuf2);

    int liRet = vMemcmp((const tchar* const)cpBuf1, (const tchar* const)cpBuf2, csztDataLen);
    if (liRet == 0)
        return true;

    return  false;
}
// End of function v_memcmp_more(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memcmp_equl(...)
// Brief     : 按字典顺序比较字符串cpBuf1于字符串cpBuf2，长度为csztDataLen，区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
inline bool v_memcmp_equl( const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen )
{
    // 验证输入参
    _VERIFY_2_(v_memcmp_equl(), cpBuf1, cpBuf2);

    int liRet = vMemcmp((tchar*)cpBuf1, (tchar*)cpBuf2, csztDataLen);
    if ( liRet ==0 )
        return true;

    return  false;
}
// End of function v_memcmp_equl(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memccpy(...)
// Brief     : 将cpSrc指向的数据区中的数据副本拷贝到pDst指向的数据去中，当遇到iVal值时，或复制csztDataLen长度的数据时停止。
// Return    : void*                                - 返回完成后的缓存区地址
// Parameter : pDst                                 - 目标缓存区
//             csztDstSize                          - 目标缓存区大小
//             cpSrc                                - 源缓存区
//             iVal                                 - 终止标识
//             csztDataLen                          - 复制的数据长度
inline size_t v_memccpy(void* const pDst, const size_t csztDstSize, const void* const cpSrc, int iVal, const size_t csztDataLen)
{
    // 验证输入参
    _VERIFY_2_(v_memccpy(), pDst, cpSrc);

    size_t lsztDatalen = vMin(csztDstSize, csztDataLen);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    void* lpEnd = vMemccpy((tchar* const)pDst,( const tchar* const )cpSrc, iVal, lsztDatalen);
    if ( lpEnd == 0 )
        return 0;
#else
    void* lpEnd = vMemccpy((tchar* const)pDst, (const tchar* const)cpSrc, iVal, lsztDatalen);
    if ( lpEnd == 0 )
        return 0;
#endif

    size_t lsztCoyied = (tchar*)lpEnd - (tchar*)pDst; 
    return lsztCoyied;
}
// End of function v_memccpy(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memcpy(...)
// Brief     : 将cpSrc指向的数据区中的数据副本拷贝到pDst指向的数据去中，当复制csztDataLen长度的数据时停止。
// Return    : void*                                - 返回完成后的缓存区地址
// Parameter : pDst                                 - 目标缓存区
//             csztDstSize                          - 目标缓存区大小
//             cpSrc                                - 源缓存区
//             csztDataLen                          - 复制的数据长度
inline size_t v_memcpy(void* const pDst, const size_t csztDstSize, const void* const cpSrc, const size_t csztDataLen)
{
    // 验证输入参
    _VERIFY_2_(v_memcpy(), pDst, cpSrc);

    size_t lsztDatalen = vMin(csztDstSize, csztDataLen);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = vMemcpy_s((tchar* const)pDst, csztDstSize, (const tchar* const)cpSrc, lsztDatalen);
    _ASSERT_(v_memmove(), (loRet == 0));

    return csztDataLen;
#else
    void* lpEnd = vMemcpy((tchar* const)pDst, (const tchar* const)cpSrc, lsztDatalen);
    if (lpEnd == 0)
        return 0
    
    return csztDataLen;
#endif
}
// End of function v_memcpy(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memmove(...)
// Brief     : 将cpSrc指向的数据区中的数据副本拷贝到pDst指向的数据去中，当复制csztDataLen长度的数据时停止。
// Return    : void*                                - 返回完成后的缓存区地址
// Parameter : pDst                                 - 目标缓存区
//             csztDstSize                          - 目标缓存区大小
//             cpSrc                                - 源缓存区
//             csztDataLen                          - 复制的数据长度
inline size_t v_memmove(void* const pDst, const size_t csztDstSize, const void* const cpSrc, const size_t csztDataLen )
{
    // 验证输入参
    _VERIFY_2_(v_memmove(), pDst, cpSrc);

    size_t lsztDatalen = vMin(csztDstSize, csztDataLen);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = vMemmove_s((tchar* const)pDst, csztDstSize, (const tchar* const)cpSrc, lsztDatalen);
    _ASSERT_(v_memmove(), (loRet == 0));
    return csztDataLen;
#else
    void* lpEnd = vMemmove((tchar* const)pDst, (const tchar* const)cpSrc, lsztDatalen);
    if (lpEnd == 0)
        return 0

        return csztDataLen;
#endif
}
// End of function v_memmove(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_vsprintf(...)
// Brief     : 按cpFmt所设置的格式将参数中的数据重组到pDst指向的缓存区中
// Return    : int                                  - 复制的数据大小
//             -x                                   - 复制出错
// Parameter : pDst                                 - 目的缓存区地址
//             csztDstSize                          - 目的缓存区大小
//             cpFmt                                - 格式字符串
//             vList                                - 参数列表
inline int v_vsprintf(tchar* const pDst, const size_t csztDstSize, const tchar* const cpFmt, va_list vList)
{
    // 验证输入参数
    _VERIFY_2_(v_vsprintf(), pDst, cpFmt);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = vSprintf_s(pDst, csztDstSize, cpFmt, vList);
    if (liRet < 0) { _ASSERT_(v_memmove(), (errno == 0)); };
    
#else
    int liRet = vSprintf(pDst, cpFmt, vList);
    if (liRet < 0) { _ASSERT_(v_memmove(), (errno == 0)); };
#endif
    return liRet;
}
// End of function v_vsprintf(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_sprintf(...)
// Brief     : 按cpFmt所设置的格式将参数中的数据重组到pDst指向的缓存区中
// Return    : int                                  - 复制的数据大小
//             -x                                   - 复制出错
// Parameter : pDst                                 - 目的缓存区地址
//             csztDstSize                          - 目的缓存区大小
//             cpFmt                                - 格式字符串
//             ...                                  - 参数列表
inline int v_sprintf( tchar* const pDst, const size_t csztDstSize, const tchar* const cpFmt, ... )
{
    // 验证输入参数
    _VERIFY_2_(v_sprintf(), pDst, cpFmt);

    va_list vlist;
    va_start( vlist, cpFmt );
#if defined (_MSC_VER) && (_MSC_VER>=1300)
    int liRet = vVsprintf_s( pDst,csztDstSize, cpFmt,vlist);
    if (liRet < 0) { _ASSERT_(v_sprintf(), (errno == 0)); };
#else
    int liRet = vVsprintf( pDst, cpFmt, vlist );
    if (liRet < 0) { _ASSERT_(v_sprintf(), (errno == 0)); };
#endif
    va_end(vlist);

    return liRet;
}
// End of function v_sprintf(...)
/////////////////////////////////////////////////////////////////////////////////////////

inline tchar* v_strtrim_left( tchar* const pData, const size_t csztDataLen )
{
    // 验证输入参数
    _VERIFY_(v_strtrim_left(), pData);

    // TODO : 添加输入错误处理
    if (csztDataLen <= 0) return nullptr;
    tchar* lpEnd = pData+ csztDataLen;

    tchar* lpPos = pData;
    size_t lsztOffset = 0;
    // while ( (lpPos!=lpEnd) && ( (*lpPos == ' ') || (*lpPos=='\n') || (*lpPos=='\t') )  )
    while ( (lpPos!=lpEnd) && (isspace(*lpPos)))
    {
        lsztOffset++;
        lpPos = pData+lsztOffset;
    }
    
    size_t lsztNewDataLen = csztDataLen -lsztOffset;
    size_t lsztCopied = v_memmove( pData, csztDataLen, lpPos, lsztNewDataLen);

    lpEnd = pData+lsztNewDataLen;
    v_memset(lpEnd, 0x00, lsztOffset );

    return pData;
}

inline tchar* v_strtrim_right( tchar* const pData, const size_t csztDataLen )
{
    // 验证输入参数
    _VERIFY_(v_strtrim_right(), pData);

    if (csztDataLen <= 0) return nullptr;
    tchar* lpEnd = pData+ csztDataLen;

    tchar* lpPos = lpEnd-1;
    size_t lsztOffset = 0;
    // while( (lpPos!=pData) && ((*lpPos==' ') || (*lpPos=='\t') || (*lpPos=='\n') ) )
    while( (lpPos>pData) && (isspace(*lpPos)))
    {
        lsztOffset++;
        lpPos = lpEnd-lsztOffset;
    }
    
    v_memset(lpPos, 0x00, lsztOffset);

    return pData;
}

inline tchar* v_strtrim( tchar* const pData, const size_t csztDataLen )
{
    // 验证输入参数
    _VERIFY_(v_strtrim(), pData);

    if (csztDataLen <= 0) return nullptr;
    tchar* lpEnd = pData + csztDataLen;

    tchar* lpStartPos = pData;
    size_t lsztStartOffset = 0;
    // while ((lpStartPos != lpEnd) && ((*lpStartPos == ' ') || (*lpStartPos == '\n') || (*lpStartPos == '\t')))
    while ((lpStartPos != lpEnd) && (isspace(*lpStartPos)))
    {
        lsztStartOffset++;
        lpStartPos = pData + lsztStartOffset;
    }

    tchar* lpEndPos = lpEnd;
    size_t lsztEndOffset = 0;
    // while ((lpEndPos != lpStartPos) && ((*lpEndPos == ' ') || (*lpEndPos == '\t') || (*lpEndPos == '\n')))
    while ((lpEndPos != lpStartPos) && (isspace(*lpEndPos)))
    {
        lsztEndOffset++;
        lpEndPos = lpEnd - lsztEndOffset;
    }

    size_t lsztNewDataLen = lpEndPos -lpStartPos;
    size_t lsztCopied = v_memmove(pData, csztDataLen, lpStartPos, lsztNewDataLen);

    // 将移动过后的多出的数据置零
    size_t lsztRemoved    = csztDataLen - lsztNewDataLen;
    v_memset((pData+lsztNewDataLen), 0x00, lsztRemoved);
    return pData;
}

inline size_t v_strtrim_left(tchar*const         pDst, const size_t sztDstSize,
                             const tchar* const cpSrc, const size_t  sztSrcLen)
{
    // 验证输入参数
    _VERIFY_2_(v_strtrim_left(), pDst, cpSrc);

    // TODO : 添加输入错误处理
    if (sztSrcLen <= 0) return 0;
    tchar* lpEnd = (tchar*)cpSrc + sztSrcLen;

    tchar* lpPos = (tchar*)cpSrc;
    size_t lsztOffset = 0;
    // while ((lpPos != lpEnd) && ((*lpPos == ' ') || (*lpPos == '\n') || (*lpPos == '\t')))
    while ((lpPos != lpEnd) && (isspace(*lpPos)))
    {
        lsztOffset++;
        lpPos = (tchar*)cpSrc + lsztOffset;
    }

    size_t lsztNewDataLen = sztSrcLen - lsztOffset;
    v_memzero(pDst,sztDstSize);
    size_t lsztCopied = v_memmove( pDst, sztDstSize, lpPos, lsztNewDataLen);

    return lsztCopied;
}

inline size_t v_strtrim_right(tchar*const        pDst, const size_t sztDstSize,
                              const tchar* const cpSrc, const size_t  sztSrcLen)
{
    // 验证输入参数
    _VERIFY_2_(v_strtrim_right(), pDst, cpSrc);

    if (sztSrcLen <= 0) return 0;
    tchar* lpEnd = (tchar*)cpSrc + sztSrcLen;

    tchar* lpPos = lpEnd;
    size_t lsztOffset = 0;
    // while ((lpPos != pSrc) && ((*lpPos == ' ') || (*lpPos == '\t') || (*lpPos == '\n')))
    while ((lpPos != cpSrc) && (isspace(*lpPos)))
    {
        lsztOffset++;
        lpPos = lpEnd - lsztOffset;
    }

    size_t lsztNewDataLen = sztSrcLen - lsztOffset;
    v_memzero(pDst,sztDstSize);
    size_t lsztCopied = v_memmove(pDst, sztDstSize, cpSrc, lsztNewDataLen);

    return lsztNewDataLen;
}

inline size_t v_strtrim( tchar*const         pDst, const size_t sztDstSize,
                         const tchar* const cpSrc, const size_t  sztSrcLen )
{
    // 验证输入参数
    _VERIFY_2_(v_strtrim(), pDst, cpSrc);

    if (sztSrcLen <= 0) return 0;
    tchar* lpEnd = (tchar*)cpSrc + sztSrcLen;

    tchar* lpStartPos = (tchar*)cpSrc;
    size_t lsztStartOffset = 0;
    // while ((lpStartPos != lpEnd) && ((*lpStartPos == ' ') || (*lpStartPos == '\n') || (*lpStartPos == '\t')))
    while ((lpStartPos != lpEnd) && (isspace(*lpStartPos)))
    {
        lsztStartOffset++;
        lpStartPos = (tchar*)cpSrc + lsztStartOffset;
    }

    tchar* lpEndPos = lpEnd;
    size_t lsztEndOffset = 0;
    // while ((lpEndPos != lpStartPos) && ((*lpEndPos == ' ') || (*lpEndPos == '\t') || (*lpEndPos == '\n')))
    while ((lpEndPos != lpStartPos) && ( isspace(*lpEndPos)))
    {
        lsztEndOffset++;
        lpEndPos = lpEnd - lsztEndOffset;
    }

    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    v_memzero(pDst,sztDstSize);
    size_t lsztCopied = v_memmove(pDst, sztDstSize, lpStartPos, lsztNewDataLen);

    return lsztNewDataLen;
}


inline size_t v_str_substr(tchar* const        pDst, const size_t csztDstSize,
                           const tchar* const cpSrc, const size_t  csztSrcLen, 
                           const int      ciBFlag, const int      ciEFlag )
{
    // 验证输入参数
    _VERIFY_2_(v_str_substr(), pDst, cpSrc);

    // 获取整个字符串长度
    if (csztSrcLen == 0) return 0;

    // 获取子字符串开头的位置
    tchar* lpStartPos = const_cast<tchar*>(cpSrc);
    // 若但ciBFlag传入vMinsInt,则从源字符串的起始字符作为开始
    if  ( ciBFlag != vMinsInt  )
    {
        lpStartPos = v_strchr((tchar*)cpSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos+=sizeof(tchar);
    }
    // End of if () ...

    // 获取子字符串结尾的位置
    tchar* lpEndPos = const_cast<tchar*>(cpSrc)+csztSrcLen;
    // 若但ciFFlag传入vMinsInt,则从源字符串的结束字符作为结尾
    if  (  ciEFlag != vMinsInt  )
    {
        lpEndPos = v_strrchr((tchar*)cpSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // 判断子字符串是否有效，解决类似“}{”问题
    if (lpEndPos <= lpStartPos) return 0;

    // 计算子字符串长度
    size_t lsztNewDataLen = (lpEndPos) - (lpStartPos);
    size_t lsztCopied     = v_strncpy( pDst, csztDstSize, lpStartPos, lsztNewDataLen );
    return lsztCopied;
}

inline size_t v_str_substr( tchar* const    pSrc, const size_t  csztSrcLen,
                            const int    ciBFlag, const int        ciEFlag )
{
    // 验证输入参数
    _VERIFY_(v_str_substr(), pSrc);

    // 获取整个字符串长度
    if (csztSrcLen == 0) return 0;

    // 获取子字符串开头的位置
    tchar* lpStartPos = const_cast<tchar*>(pSrc);
    // 若但ciBFlag传入vMinsInt,则从源字符串的起始字符作为开始
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strchr((tchar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tchar);
    }
    // End of if () ...

    // 获取子字符串结尾的位置
    tchar* lpEndPos = const_cast<tchar*>(pSrc) + csztSrcLen;
    // 若但ciFFlag传入vMinsInt,则从源字符串的结束字符作为结尾
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tchar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // 判断子字符串是否有效，解决类似“}{”问题
    if (lpEndPos <= lpStartPos) 
        return 0;

    // 计算子字符串长度
    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    size_t lsztCopied     = v_memmove(pSrc, csztSrcLen, lpStartPos, lsztNewDataLen);

    // 将移动过后的多出的数据置零
    size_t lszRemoved     = csztSrcLen -lsztNewDataLen;
    v_memset((pSrc+lsztNewDataLen), 0x00, lszRemoved );
    return lsztCopied;
}

inline size_t v_str_substr_first(tchar* const    pSrc, const size_t  csztSrcLen,
                                 const int   ciBFlag, const int        ciEFlag)
{
    // 验证输入参数
    _VERIFY_(v_str_substr_first(), pSrc);

    // 获取整个字符串长度
    if (csztSrcLen == 0) return 0;

    // 获取子字符串开头的位置
    tchar* lpStartPos = const_cast<tchar*>(pSrc);
    // 若但ciBFlag传入vMinsInt,则从源字符串的起始字符作为开始
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strchr((tchar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tchar);
    }
    // End of if () ...

    // 获取子字符串结尾的位置
    tchar* lpEndPos = const_cast<tchar*>(pSrc) + csztSrcLen;
    // 若但ciFFlag传入vMinsInt,则从源字符串的结束字符作为结尾
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strchr((tchar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // 判断子字符串是否有效，解决类似“}{”问题
    if (lpEndPos <= lpStartPos) 
        return 0;

    // 计算子字符串长度
    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    size_t lsztCopied     = v_memmove(pSrc,csztSrcLen, lpStartPos,lsztNewDataLen);

    // 将移动过后的多出的数据置零
    size_t lsztRemoved    = csztSrcLen - lsztNewDataLen;
    v_memset((pSrc+lsztNewDataLen), 0x00, lsztRemoved);
    return lsztCopied;
}

inline size_t v_str_substr_last( tchar* const    pSrc, const size_t  csztSrcLen,
                                 const int   ciBFlag, const int        ciEFlag)
{
    // 验证输入参数
    _VERIFY_(v_str_substr_last(), pSrc);

    // 获取整个字符串长度
    if (csztSrcLen == 0) return 0;

    // 获取子字符串开头的位置
    tchar* lpStartPos = const_cast<tchar*>(pSrc);
    // 若但ciBFlag传入vMinsInt,则从源字符串的起始字符作为开始
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strrchr((tchar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tchar);
    }
    // End of if () ...

    // 获取子字符串结尾的位置
    tchar* lpEndPos = const_cast<tchar*>(pSrc) + csztSrcLen;
    // 若但ciFFlag传入vMinsInt,则从源字符串的结束字符作为结尾
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tchar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // 判断子字符串是否有效，解决类似“}{”问题
    if (lpEndPos <= lpStartPos) return 0;

    // 计算子字符串长度
    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    size_t lsztCopied = v_memmove(pSrc, csztSrcLen, lpStartPos, lsztNewDataLen);

    // 将移动过后的多出的数据置零
    size_t lsztRemoved = csztSrcLen - lsztNewDataLen;
    v_memset((pSrc + lsztNewDataLen), 0x00, lsztRemoved);
    return lsztCopied;
}

inline size_t v_str_substr_last( tchar* const         pDst, const size_t  cszDstSize,
                                 const tchar* const   pSrc, const size_t  csztSrcLen,
                                 const int         ciBFlag, const int        ciEFlag)
{
    // 验证输入参数
    _VERIFY_2_(v_str_substr_last(), pDst, pSrc);

    // 获取整个字符串长度
    if (csztSrcLen == 0) return 0;

    // 获取子字符串开头的位置
    tchar* lpStartPos = const_cast<tchar*>(pSrc);
    // 若但ciBFlag传入vMinsInt,则从源字符串的起始字符作为开始
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strrchr((tchar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tchar);
    }
    // End of if () ...

    // 获取子字符串结尾的位置
    tchar* lpEndPos = const_cast<tchar*>(pSrc) + csztSrcLen;
    // 若但ciFFlag传入vMinsInt,则从源字符串的结束字符作为结尾
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tchar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // 判断子字符串是否有效，解决类似“}{”问题
    if (lpEndPos <= lpStartPos) return 0;

    // 计算子字符串长度
    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    size_t lsztCopied = v_memmove(pDst, cszDstSize, lpStartPos, lsztNewDataLen);

    // 设置字符串结尾
    *(pDst+lsztCopied) = 0x00;
    return lsztCopied;
}

inline void v_toupper(tchar* pData, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_(v_toupper(), pData);

    tchar* lpPos = pData;
    size_t lsztOffset = 0;
    for ( size_t lsztOffset = 0; lsztOffset < csztDataLen; lsztOffset++ )
    {
        tchar* pValue = lpPos+lsztOffset;
        if (isalpha(*pValue))
            toupper(*pValue);
    }
}
inline void v_tolower(tchar* pData, const size_t csztDataLen)
{
    // 验证输入参数
    _VERIFY_(v_tolower(), pData);

    tchar* lpPos = pData;
    size_t lsztOffset = 0;
    for (size_t lsztOffset = 0; lsztOffset < csztDataLen; lsztOffset++)
    {
        tchar* pValue = lpPos + lsztOffset;
        if (isalpha(*pValue))
            tolower(*pValue);
    }
}

// --------------------------------------------------------------------------------------
//#else // _V_PLATFORM_ != _V_PF_WIN_
// --------------------------------------------------------------------------------------
// linux util functions

// TODO : add linux until functions

// --------------------------------------------------------------------------------------
//#endif // #if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_UTIL_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmUtil.h
/////////////////////////////////////////////////////////////////////////////////////////