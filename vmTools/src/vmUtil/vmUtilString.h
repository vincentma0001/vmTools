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
// �ع�windows�е�str,memϵ�к���

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strchr(...)
// Brief     : ���ֽڴ���������һ�γ��ֵ�ciValֵ��ַ
// Return    : tchar*                           - ���ҵĵ�ַ
//             nullptr                          - δ���ҵ�ָ��������
// Parameter : cpBuf                            - ���������ַ���
//             ciVal                            - ��ʶ����
inline tchar* v_strchr(tchar* const cpBuf, const int ciVal)
{
    // ��֤�������
    _VERIFY_(v_strchr(),cpBuf);

    return vStrchr(cpBuf, ciVal);
}
// End of function v_strchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strrchr(...)
// Brief     : ���ֽڴ��з���������һ�γ��ֵ�ciVal��ַ
// Return    : tchar*                           - ���ҵĵ�ַ
//             nullptr                          - δ���ҵ�ָ��������
// Parameter : cpBuf                            - ���������ַ���
//             ciVal                            - ��ʶ����
inline tchar* v_strrchr( tchar* const cpBuf, const int ciVal )
{
    // ��֤�������
    _VERIFY_(v_strrchr(), cpBuf);

    return vStrrchr(cpBuf, ciVal);
}
// End of function v_strrchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strstr(...)
// Brief     : ���ֽڴ��в��ҵ�һ�γ������ַ����ĵ�ַ
// Return    : tchar*                           - ���ҵĵ�ַ����cpSubStrΪnullʱ������cpBuf
//             nullptr                          - δ���ҵ�ָ�����ַ���
// Parameter : cpBuf                            - ���������ַ���
//             cpSubStr                         - ��Ҫ���ҵ����ַ���
inline tchar* v_strstr( tchar* const cpBuf, const tchar* const cpSubStr )
{
    // ��֤�������
    _VERIFY_(v_strstr(), cpBuf);

    return vStrstr(cpBuf, cpSubStr);
}
// End of function v_strstr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcmp_equl(...)
// Brief     : ���ֵ�˳���ж�pStr1�ַ����Ƿ����pStr2�ַ���
// Return    : true                             - �����ַ������
//             false                            - �����ַ��������
// Parameter : pStr1                            - �ַ���֮һ
//             pStr2                            - �ַ���֮һ
inline bool v_strcmp_equl( const tchar* const pStr1, const tchar* const pStr2 )
{
    // ��֤�������
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
// Brief     : ���ֵ�˳���ж�pStr1�ַ����Ƿ����pStr2�ַ���
// Return    : true                             - pStr1�ַ�������pStr2�ַ���
//             false                            - pStr1�ַ���С�ڻ����pStr2�ַ���
// Parameter : pStr1                            - �ַ���֮һ
//             pStr2                            - �ַ���֮һ
inline bool v_strcmp_more(const tchar* const pStr1, const tchar* const pStr2)
{
    // ��֤�������
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
// Brief     : ���ֵ�˳���ж�pStr1�ַ����Ƿ�С��pStr2�ַ���
// Return    : true                             - pStr1�ַ���С��pStr2�ַ���
//             false                            - pStr1�ַ������ڻ����pStr2�ַ���
// Parameter : pStr1                            - �ַ���֮һ
//             pStr2                            - �ַ���֮һ
inline bool v_strcmp_less(const tchar* const pStr1, const tchar* const pStr2)
{
    // ��֤�������
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
// Return    : true                             - �����ַ������
//             false                            - �����ַ��������
// Parameter : pStr1                            - �ַ���֮һ
//             pStr2                            - �ַ���֮һ
inline bool v_strncmp_equl(const tchar* const pStr1, const tchar* const pStr2, const size_t csztDataLen)
{
    // ��֤�������
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
// Return    : true                             - pStr1�ַ�������pStr2�ַ���
//             false                            - pStr1�ַ���С�ڻ����pStr2�ַ���
// Parameter : pStr1                            - �ַ���֮һ
//             pStr2                            - �ַ���֮һ
inline bool v_strncmp_more(const tchar* const pStr1, const tchar* const pStr2,const size_t csztDataLen)
{
    // ��֤�������
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
// Return    : true                             - pStr1�ַ���С��pStr2�ַ���
//             false                            - pStr1�ַ������ڻ����pStr2�ַ���
// Parameter : pStr1                            - �ַ���֮һ
//             pStr2                            - �ַ���֮һ
inline bool v_strncmp_less(const tchar* const pStr1, const tchar* const pStr2, const size_t csztDataLen )
{
    // ��֤�������
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
// Brief     : ����cpSrc�ֽڴ��ĸ�����csztDataLen���ȵ��ֽ�׷�ӵ���pDst�ֽڴ���ĩβ
// Return    : tchar*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
//             csztDataLen                          - �踴�Ƶ��ַ�����С
inline tchar* v_strncat(tchar* const pDst, const size_t csztDstSize, const tchar* const cpSrc, const size_t csztDataLen)
{
    // ��֤�������
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
// Brief     : ����cpSrc�ֽڴ��ĸ���׷�ӵ���pDst�ֽڴ���ĩβ
// Return    : tchar*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
inline tchar* v_strcat(tchar* const pDst, const size_t csztDstSize, const tchar* const cpSrc)
{
    // ��֤�������
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
// Brief     : ����cpSrc�ֽڴ��ĸ�����csztDataLen���ȵ��ֽڸ��Ƶ���pDstָ��Ļ�������
// Return    : tchar*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
//             csztDataLen                          - �踴�Ƶ��ַ�����С
inline size_t v_strncpy(tchar* const pDst, const size_t csztDstSize, const tchar* const cpSrc, const size_t csztDataLen)
{
    // ��֤�������
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
// Brief     : ����cpSrc�ֽڴ��ĸ������Ƶ���pDstָ��Ļ�������
// Return    : tchar*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
inline size_t v_strcpy( tchar* const pDst, const size_t csztDstSize, const tchar* const cpSrc )
{
    // ��֤�������
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
// Method    : v_strzero(...)
// Brief     : ����pBuf��ʼcsztDataLen���Ļ�������������Ϊ0x00
// Return    : void
// Parameter : pBuf                                 - ��������ַ
//             csztDataLen                          - ��������С
inline void v_strzero(tchar* const pBuf, const size_t csztDataLen)
{
    // ��֤�������
    _VERIFY_(v_strzero(), pBuf);

    vMemset((tchar* const)pBuf, 0x00, csztDataLen);
}
// End of function v_strzero(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strset(...)
// Brief     : ����pBuf��ʼcsztDataLen���Ļ�������������ΪciVal
// Return    : void
// Parameter : pBuf                                 - ��������ַ
//             ciVal                                - ��Ҫ���õ���ֵ
//             csztDataLen                          - ���õ����ݴ�С
inline void v_strset(tchar* const pBuf, const int ciVal, const size_t csztDataLen)
{
    // ��֤�������
    _VERIFY_(v_strset(), pBuf);

    vMemset(pBuf, ciVal, csztDataLen);
}
// End of function v_strset(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_memchr(...)
// Brief     : ��cpBufָ��Ļ������в��ҵ�һ�γ���ciVal�ĵ�ַ
// Return    : void
// Parameter : cpBuf                                - �����ҵĻ�������ַ
//             iVal                                 - ��Ҫ���ҵ���ֵ
//             csztLookforLen                       - �����ҵĻ���������
inline void* v_memchr( void* const pBuf, const int iVal, const size_t csztLookforLen)
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
inline bool v_memcmp_equl( const void* const cpBuf1, const void* const cpBuf2, const size_t csztDataLen )
{
    // ��֤�����
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
inline size_t v_memmove(void* const pDst, const size_t csztDstSize, const void* const cpSrc, const size_t csztDataLen )
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
// Method    : v_vsprintf(...)
// Brief     : ��cpFmt�����õĸ�ʽ�������е��������鵽pDstָ��Ļ�������
// Return    : int                                  - ���Ƶ����ݴ�С
//             -x                                   - ���Ƴ���
// Parameter : pDst                                 - Ŀ�Ļ�������ַ
//             csztDstSize                          - Ŀ�Ļ�������С
//             cpFmt                                - ��ʽ�ַ���
//             vList                                - �����б�
inline int v_vsprintf(tchar* const pDst, const size_t csztDstSize, const tchar* const cpFmt, va_list vList)
{
    // ��֤�������
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
// Brief     : ��cpFmt�����õĸ�ʽ�������е��������鵽pDstָ��Ļ�������
// Return    : int                                  - ���Ƶ����ݴ�С
//             -x                                   - ���Ƴ���
// Parameter : pDst                                 - Ŀ�Ļ�������ַ
//             csztDstSize                          - Ŀ�Ļ�������С
//             cpFmt                                - ��ʽ�ַ���
//             ...                                  - �����б�
inline int v_sprintf( tchar* const pDst, const size_t csztDstSize, const tchar* const cpFmt, ... )
{
    // ��֤�������
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
    // ��֤�������
    _VERIFY_(v_strtrim_left(), pData);

    // TODO : ������������
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
    // ��֤�������
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
    // ��֤�������
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

    // ���ƶ�����Ķ������������
    size_t lsztRemoved    = csztDataLen - lsztNewDataLen;
    v_memset((pData+lsztNewDataLen), 0x00, lsztRemoved);
    return pData;
}

inline size_t v_strtrim_left(tchar*const         pDst, const size_t sztDstSize,
                             const tchar* const cpSrc, const size_t  sztSrcLen)
{
    // ��֤�������
    _VERIFY_2_(v_strtrim_left(), pDst, cpSrc);

    // TODO : ������������
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
    // ��֤�������
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
    // ��֤�������
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
    // ��֤�������
    _VERIFY_2_(v_str_substr(), pDst, cpSrc);

    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tchar* lpStartPos = const_cast<tchar*>(cpSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if  ( ciBFlag != vMinsInt  )
    {
        lpStartPos = v_strchr((tchar*)cpSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos+=sizeof(tchar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tchar* lpEndPos = const_cast<tchar*>(cpSrc)+csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if  (  ciEFlag != vMinsInt  )
    {
        lpEndPos = v_strrchr((tchar*)cpSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // �ж����ַ����Ƿ���Ч��������ơ�}{������
    if (lpEndPos <= lpStartPos) return 0;

    // �������ַ�������
    size_t lsztNewDataLen = (lpEndPos) - (lpStartPos);
    size_t lsztCopied     = v_strncpy( pDst, csztDstSize, lpStartPos, lsztNewDataLen );
    return lsztCopied;
}

inline size_t v_str_substr( tchar* const    pSrc, const size_t  csztSrcLen,
                            const int    ciBFlag, const int        ciEFlag )
{
    // ��֤�������
    _VERIFY_(v_str_substr(), pSrc);

    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tchar* lpStartPos = const_cast<tchar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strchr((tchar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tchar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tchar* lpEndPos = const_cast<tchar*>(pSrc) + csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tchar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // �ж����ַ����Ƿ���Ч��������ơ�}{������
    if (lpEndPos <= lpStartPos) 
        return 0;

    // �������ַ�������
    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    size_t lsztCopied     = v_memmove(pSrc, csztSrcLen, lpStartPos, lsztNewDataLen);

    // ���ƶ�����Ķ������������
    size_t lszRemoved     = csztSrcLen -lsztNewDataLen;
    v_memset((pSrc+lsztNewDataLen), 0x00, lszRemoved );
    return lsztCopied;
}

inline size_t v_str_substr_first(tchar* const    pSrc, const size_t  csztSrcLen,
                                 const int   ciBFlag, const int        ciEFlag)
{
    // ��֤�������
    _VERIFY_(v_str_substr_first(), pSrc);

    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tchar* lpStartPos = const_cast<tchar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strchr((tchar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tchar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tchar* lpEndPos = const_cast<tchar*>(pSrc) + csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strchr((tchar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // �ж����ַ����Ƿ���Ч��������ơ�}{������
    if (lpEndPos <= lpStartPos) 
        return 0;

    // �������ַ�������
    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    size_t lsztCopied     = v_memmove(pSrc,csztSrcLen, lpStartPos,lsztNewDataLen);

    // ���ƶ�����Ķ������������
    size_t lsztRemoved    = csztSrcLen - lsztNewDataLen;
    v_memset((pSrc+lsztNewDataLen), 0x00, lsztRemoved);
    return lsztCopied;
}

inline size_t v_str_substr_last( tchar* const    pSrc, const size_t  csztSrcLen,
                                 const int   ciBFlag, const int        ciEFlag)
{
    // ��֤�������
    _VERIFY_(v_str_substr_last(), pSrc);

    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tchar* lpStartPos = const_cast<tchar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strrchr((tchar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tchar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tchar* lpEndPos = const_cast<tchar*>(pSrc) + csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tchar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // �ж����ַ����Ƿ���Ч��������ơ�}{������
    if (lpEndPos <= lpStartPos) return 0;

    // �������ַ�������
    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    size_t lsztCopied = v_memmove(pSrc, csztSrcLen, lpStartPos, lsztNewDataLen);

    // ���ƶ�����Ķ������������
    size_t lsztRemoved = csztSrcLen - lsztNewDataLen;
    v_memset((pSrc + lsztNewDataLen), 0x00, lsztRemoved);
    return lsztCopied;
}

inline size_t v_str_substr_last( tchar* const         pDst, const size_t  cszDstSize,
                                 const tchar* const   pSrc, const size_t  csztSrcLen,
                                 const int         ciBFlag, const int        ciEFlag)
{
    // ��֤�������
    _VERIFY_2_(v_str_substr_last(), pDst, pSrc);

    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tchar* lpStartPos = const_cast<tchar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strrchr((tchar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tchar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tchar* lpEndPos = const_cast<tchar*>(pSrc) + csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tchar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // �ж����ַ����Ƿ���Ч��������ơ�}{������
    if (lpEndPos <= lpStartPos) return 0;

    // �������ַ�������
    size_t lsztNewDataLen = lpEndPos - lpStartPos;
    size_t lsztCopied = v_memmove(pDst, cszDstSize, lpStartPos, lsztNewDataLen);

    // �����ַ�����β
    *(pDst+lsztCopied) = 0x00;
    return lsztCopied;
}

inline void v_toupper(tchar* pData, const size_t csztDataLen)
{
    // ��֤�������
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
    // ��֤�������
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