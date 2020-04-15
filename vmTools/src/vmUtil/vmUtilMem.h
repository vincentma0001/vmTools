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
// Brief     : ����pBuf��ʼcsztDataLen���Ļ�������������Ϊ0x00
// Return    : void
// Parameter : pBuf                                 - ��������ַ
//             csztDataLen                          - ��������С
inline void v_memzero(void* const pBuf, const size_t csztDataLen)
{
    // ��֤�������
    _VERIFY_(v_memzero(), pBuf);

    memset(pBuf, 0x00, csztDataLen);
}
// End of function v_memzero(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memset(...)
// Brief     : ����pBuf��ʼcsztDataLen���Ļ�������������ΪciVal
// Return    : void
// Parameter : pBuf                                 - ��������ַ
//             ciVal                                - ��Ҫ���õ���ֵ
//             csztDataLen                          - ���õ����ݴ�С
inline void v_memset(void* const pBuf, const int ciVal, const size_t csztDataLen)
{
    // ��֤�������
    _VERIFY_(v_memset(), pBuf);

    memset(pBuf, ciVal, csztDataLen);
}
// End of function v_memset(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memchr(...)
// Brief     : ��cpBufָ��Ļ������в��ҵ�һ�γ���ciVal�ĵ�ַ
// Return    : void
// Parameter : cpBuf                                - �����ҵĻ�������ַ
//             iVal                                 - ��Ҫ���ҵ���ֵ
//             csztLookforLen                       - �����ҵĻ���������
inline void* v_memchr(void* const pBuf, const int iVal, const size_t csztLookforLen)
{
    // ��֤�������
    _VERIFY_(v_memchr(), pBuf);

    return vMemchr((tchar* const)pBuf, iVal, csztLookforLen);
}
// End of function v_memchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memicmp_less(...)
// Brief     : ���ֵ�˳��Ƚϻ�����cpBuf1�ڻ�����cpBuf2������ΪcsztDataLen�������ִ�Сд
// Return    : true                                 - ������cpBuf1�ڻ�����cpBuf2��ͬ
//             false                                - ������cpBuf1�ڻ�����cpBuf2��ͬ
// Parameter : cpBuf1                               - ������֮һ
//             cpBuf2                               - ������֮һ
//             csztDataLen                          - �Աȵ����ݴ�С
inline bool v_memicmp_less(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // ��֤�������
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
// Brief     : ���ֵ�˳��Ƚϻ�����cpBuf1�ڻ�����cpBuf2������ΪcsztDataLen�������ִ�Сд
// Return    : true                                 - ������cpBuf1�ڻ�����cpBuf2��ͬ
//             false                                - ������cpBuf1�ڻ�����cpBuf2��ͬ
// Parameter : cpBuf1                               - ������֮һ
//             cpBuf2                               - ������֮һ
//             csztDataLen                          - �Աȵ����ݴ�С
inline bool v_memicmp_more(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // ��֤�������
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
// Brief     : ���ֵ�˳��Ƚϻ�����cpBuf1�ڻ�����cpBuf2������ΪcsztDataLen�������ִ�Сд
// Return    : true                                 - ������cpBuf1�ڻ�����cpBuf2��ͬ
//             false                                - ������cpBuf1�ڻ�����cpBuf2��ͬ
// Parameter : cpBuf1                               - ������֮һ
//             cpBuf2                               - ������֮һ
//             csztDataLen                          - �Աȵ����ݴ�С
inline bool v_memicmp_equl(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // ��֤�������
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
// Brief     : ���ֵ�˳��Ƚ��ַ���cpBuf1���ַ���cpBuf2������ΪcsztDataLen�����ִ�Сд
// Return    : true                                 - ������cpBuf1�ڻ�����cpBuf2��ͬ
//             false                                - ������cpBuf1�ڻ�����cpBuf2��ͬ
// Parameter : cpBuf1                               - ������֮һ
//             cpBuf2                               - ������֮һ
//             csztDataLen                          - �Աȵ����ݴ�С
inline bool v_memcmp_less(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // ��֤�������
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
// Brief     : ���ֵ�˳��Ƚ��ַ���cpBuf1���ַ���cpBuf2������ΪcsztDataLen�����ִ�Сд
// Return    : true                                 - ������cpBuf1�ڻ�����cpBuf2��ͬ
//             false                                - ������cpBuf1�ڻ�����cpBuf2��ͬ
// Parameter : cpBuf1                               - ������֮һ
//             cpBuf2                               - ������֮һ
//             csztDataLen                          - �Աȵ����ݴ�С
inline bool v_memcmp_more(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // ��֤�������
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
// Brief     : ���ֵ�˳��Ƚ��ַ���cpBuf1���ַ���cpBuf2������ΪcsztDataLen�����ִ�Сд
// Return    : true                                 - ������cpBuf1�ڻ�����cpBuf2��ͬ
//             false                                - ������cpBuf1�ڻ�����cpBuf2��ͬ
// Parameter : cpBuf1                               - ������֮һ
//             cpBuf2                               - ������֮һ
//             csztDataLen                          - �Աȵ����ݴ�С
inline bool v_memcmp_equl(const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen)
{
    // ��֤�����
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
// Brief     : ��cpSrcָ����������е����ݸ���������pDstָ�������ȥ�У�������iValֵʱ������csztDataLen���ȵ�����ʱֹͣ��
// Return    : void*                                - ������ɺ�Ļ�������ַ
// Parameter : pDst                                 - Ŀ�껺����
//             csztDstSize                          - Ŀ�껺������С
//             cpSrc                                - Դ������
//             iVal                                 - ��ֹ��ʶ
//             csztDataLen                          - ���Ƶ����ݳ���
inline size_t v_memccpy(void* const pDst, const size_t csztDstSize, const void* const cpSrc, int iVal, const size_t csztDataLen)
{
    // ��֤�����
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
// Brief     : ��cpSrcָ����������е����ݸ���������pDstָ�������ȥ�У�������csztDataLen���ȵ�����ʱֹͣ��
// Return    : void*                                - ������ɺ�Ļ�������ַ
// Parameter : pDst                                 - Ŀ�껺����
//             csztDstSize                          - Ŀ�껺������С
//             cpSrc                                - Դ������
//             csztDataLen                          - ���Ƶ����ݳ���
inline size_t v_memcpy(void* const pDst, const size_t csztDstSize, const void* const cpSrc, const size_t csztDataLen)
{
    // ��֤�����
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
// Brief     : ��cpSrcָ����������е����ݸ���������pDstָ�������ȥ�У�������csztDataLen���ȵ�����ʱֹͣ��
// Return    : void*                                - ������ɺ�Ļ�������ַ
// Parameter : pDst                                 - Ŀ�껺����
//             csztDstSize                          - Ŀ�껺������С
//             cpSrc                                - Դ������
//             csztDataLen                          - ���Ƶ����ݳ���
inline size_t v_memmove(void* const pDst, const size_t csztDstSize, const void* const cpSrc, const size_t csztDataLen)
{
    // ��֤�����
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