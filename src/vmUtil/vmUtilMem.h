/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmUtilMem.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/04/15 12:32:28
// Modify time 	: 2020/04/15 12:32:28
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

#ifndef __VMUTILMEM_H__
#define __VMUTILMEM_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#ifndef   _INC_STDIO
#   include<stdio.h>
#endif // _INC_STDIO

#ifndef   _INC_STDARG
#   include <stdarg.h>
#endif // _INC_STDARG

// Config files included
#include <vmCfg.h>
#include <vmVerify.h>

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :
#ifndef    vMemZero
#   define vMemZero(szBuf)          v_memzero(&szBuf,sizeof(szBuf))
#endif  // vMemZero

#ifndef    vMemSet
#   define vMemSet(szBuf, ciFlag)   v_memset(&szBuf,ciFlg,sizeof(szBuf))
#endif  // vMemSet

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
// Method    : v_memchr(...)
// Brief     : 在cpBuf指向的缓存区中查找第一次出现ciVal的地址
// Return    : void
// Parameter : cpBuf                                - 待查找的缓存区地址
//             iVal                                 - 需要查找的数值
//             csztLookforLen                       - 待查找的缓存区长度
inline void* v_memchr(void* const pBuf, const int iVal, const size_t csztLookforLen)
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
inline bool v_memcmp_equl(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // 验证输入参
    _VERIFY_2_(v_memcmp_equl(), cpBuf1, cpBuf2);

    int liRet = vMemcmp((tchar*)cpBuf1, (tchar*)cpBuf2, csztDataLen);
    if (liRet == 0)
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
    void* lpEnd = vMemccpy((tchar* const)pDst, (const tchar* const)cpSrc, iVal, lsztDatalen);
    if (lpEnd == 0)
        return 0;
#else
    void* lpEnd = vMemccpy((tchar* const)pDst, (const tchar* const)cpSrc, iVal, lsztDatalen);
    if (lpEnd == 0)
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
inline size_t v_memmove(void* const pDst, const size_t csztDstSize, const void* const cpSrc, const size_t csztDataLen)
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
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VMUTILMEM_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmUtilMem.h
/////////////////////////////////////////////////////////////////////////////////////////