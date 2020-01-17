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
#   error this file need #include<stdio.h>
#endif // _INC_STDIO

#ifndef   _INC_STDARG
#	error this file need #include <stdarg.h>
#endif // _INC_STDARG

#ifndef   _INC_STRING
#	error this file need #include <string.h>
#endif // _INC_STRING

#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>
#endif // __VM_CFG_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :

#ifndef   vMemZero
#   define vMemZero(szBuf) vm::v_memzero(&szBuf,sizeof(szBuf))
#endif // vMemZero

#ifndef   vMemSet
#   define vMemSet(szBuf, ciFlag) vm::v_memset(&szBuf,ciFlg,sizeof(szBuf))
#endif // vMemSet

#ifndef    vStrPosBegin
#    define vStrPosBegin vMinsInt
#endif  // vStrPosBegin

#ifndef    vStrPosEnded
#    define vStrPosEnded vMinsInt
#endif  // vStrPosEnded


/////////////////////////////////////////////////////////////////////////////////////////
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
// --------------------------------------------------------------------------------------
// �ع�windows�е�str,memϵ�к���


/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strchr(...)
// Brief     : ���ֽڴ���������һ�γ��ֵ�ciValֵ��ַ
// Return    : tChar*                            - ���ҵĵ�ַ
//             nullptr                          - δ���ҵ�ָ��������
// Parameter : cpBuf                            - ���������ַ���
//             ciVal                            - ��ʶ����
inline tChar* v_strchr(tChar* const cpBuf, const int ciVal)
{
    return strchr(cpBuf, ciVal);
}
// End of function v_strchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strrchr(...)
// Brief     : ���ֽڴ��з���������һ�γ��ֵ�ciVal��ַ
// Return    : tChar*                            - ���ҵĵ�ַ
//             nullptr                          - δ���ҵ�ָ��������
// Parameter : cpBuf                            - ���������ַ���
//             ciVal                            - ��ʶ����
inline tChar* v_strrchr( tChar* const cpBuf, const int ciVal )
{
    return strrchr(cpBuf, ciVal);
}
// End of function v_strrchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strstr(...)
// Brief     : ���ֽڴ��в��ҵ�һ�γ������ַ����ĵ�ַ
// Return    : tChar*                            - ���ҵĵ�ַ����cpSubStrΪnullʱ������cpBuf
//             nullptr                          - δ���ҵ�ָ�����ַ���
// Parameter : cpBuf                            - ���������ַ���
//             cpSubStr                         - ��Ҫ���ҵ����ַ���
inline tChar* v_strstr( tChar* const cpBuf, const tChar* const cpSubStr )
{
    return strstr(cpBuf, cpSubStr);
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
inline bool v_strcmp_equl( const tChar* const pStr1, const tChar* const pStr2 )
{
    int liRet  = strcmp(pStr1, pStr2);
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
inline bool v_strcmp_more(const tChar* const pStr1, const tChar* const pStr2)
{
    int liRet = strcmp(pStr1, pStr2);
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
inline bool v_strcmp_less(const tChar* const pStr1, const tChar* const pStr2)
{
    int liRet = strcmp(pStr1, pStr2);
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
inline bool v_strncmp_equl(const tChar* const pStr1, const tChar* const pStr2, const size_t csztDataLen)
{
    int liRet = strncmp(pStr1, pStr2, csztDataLen);
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
inline bool v_strncmp_more(const tChar* const pStr1, const tChar* const pStr2,const size_t csztDataLen)
{
    int liRet = strncmp(pStr1, pStr2,csztDataLen);
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
inline bool v_strncmp_less(const tChar* const pStr1, const tChar* const pStr2, const size_t csztDataLen )
{
    int liRet = strncmp(pStr1, pStr2, csztDataLen);
    if (liRet < 0)
        return  true;

    return false;
}
// End of function v_strcmp_less(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strncat(...)
// Brief     : ����cpSrc�ֽڴ��ĸ�����csztDataLen���ȵ��ֽ�׷�ӵ���pDst�ֽڴ���ĩβ
// Return    : tChar*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
//             csztDataLen                          - �踴�Ƶ��ַ�����С
inline tChar* v_strncat(tChar* const pDst, const size_t csztDstSize, const tChar* const cpSrc, const size_t csztDataLen)
{

#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = strncat_s(pDst, csztDstSize, cpSrc, csztDataLen);
    if (loRet != 0) { return nullptr; };

    return pDst;
#else
    return strncat(pDst, cpSrc, csztDataLen);
#endif
}
// End of function v_strncat(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcat(...)
// Brief     : ����cpSrc�ֽڴ��ĸ���׷�ӵ���pDst�ֽڴ���ĩβ
// Return    : tChar*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
inline tChar* v_strcat(tChar* const pDst, const size_t csztDstSize, const tChar* const cpSrc)
{
#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = strcat_s(pDst, csztDstSize, cpSrc);
    if (loRet != 0) { return nullptr; /* TODO : ��Ӵ����� */ };

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
// Return    : tChar*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
//             csztDataLen                          - �踴�Ƶ��ַ�����С
inline size_t v_strncpy(tChar* const pDst, const size_t csztDstSize, const tChar* const cpSrc, const size_t csztDataLen)
{
    size_t lsztDatalen = vMin((csztDstSize-sizeof(tChar)),csztDataLen);
    
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    // errno_t loRet = strncpy_s(pDst, csztDstSize, cpSrc, csztDataLen);
    errno_t loRet = memcpy_s(pDst, csztDstSize, cpSrc, lsztDatalen);
    if (loRet != 0) { return 0;};
    
    *(pDst+lsztDatalen) = tChar(0x00);

    return csztDataLen;
#else
    tChar* lpEnd = vmemcpy(pDst, cpSrc, lsztDatalen)
    if ( lpEnd == nullptr ){ return 0; }

    size_t lsztCopied= lpEnd -pDst;
    return lsztCopied;
#endif
}
// End of function v_strncpy(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strcpy(...)
// Brief     : ����cpSrc�ֽڴ��ĸ������Ƶ���pDstָ��Ļ�������
// Return    : tChar*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
inline size_t v_strcpy( tChar* const pDst, const size_t csztDstSize, const tChar* const cpSrc )
{
    size_t lsztSrcLen = vStrLen(cpSrc);
    size_t lsztDataLen = vMin( csztDstSize, lsztSrcLen );

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    //errno_t loRet = strcpy_s(pDst,csztDstSize,cpSrc);
    errno_t loRet = memcpy_s(pDst,csztDstSize,cpSrc, lsztDataLen);
    if (loRet != 0) { return 0; };
    
    return lsztDataLen;
#else
    tChar* lpEnd = strcpy(pDst, cpSrc)
    if ( lpEnd == nullptr )
        return 0;
    
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
inline void* v_memchr( void* const cpBuf, const int iVal, const size_t csztLookforLen)
{
    return memchr(cpBuf, iVal, csztLookforLen);
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
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = _memicmp(cpBuf1, cpBuf2, csztDataLen);
    if (liRet < 0)
        return true;
    return false; 
#else
    int liRet = memicmp(cpBuf1, cpBuf2, csztDataLen);
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
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = _memicmp(cpBuf1, cpBuf2, csztDataLen);
    if (liRet > 0)
        return true;
    return false; 
#else
    int liRet = memicmp(cpBuf1, cpBuf2, csztDataLen);
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
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = _memicmp(cpBuf1, cpBuf2, csztDataLen);
    if (liRet == 0)
        return true;
    return false;
#else
    int liRet = memicmp(cpBuf1, cpBuf2, csztDataLen);
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
    int liRet = memcmp(cpBuf1, cpBuf2, csztDataLen);
    if (liRet == 0)
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
    int liRet = memcmp(cpBuf1, cpBuf2, csztDataLen);
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
    int liRet = memcmp(cpBuf1, cpBuf2, csztDataLen);
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
    size_t lsztDatalen = vMin(csztDstSize, csztDataLen);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    void* lpEnd = _memccpy(pDst, cpSrc, iVal, lsztDatalen);
    if ( lpEnd == 0 )
        return csztDataLen;
#else
    void* lpEnd = memccpy(pDst, cpSrc, iVal, lsztDatalen);
    if ( lpEnd == 0 )
        return csztDataLen
#endif

    size_t lsztCoyied = (tChar*)lpEnd - (tChar*)pDst; 
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
    size_t lsztDatalen = vMin(csztDstSize, csztDataLen);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = memcpy_s(pDst, csztDstSize, cpSrc, lsztDatalen);
    if (loRet != 0) { return 0; /* TODO : ��Ӵ����� */ };

    return csztDataLen;
#else
    void* lpEnd = memcpy(pDst, cpSrc, lsztDatalen);
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
    size_t lsztDatalen = vMin(csztDstSize, csztDataLen);

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = memmove_s(pDst, csztDstSize, cpSrc, lsztDatalen);
    if (loRet != 0) { return 0; /* TODO : ��Ӵ����� */ };

    return csztDataLen;
#else
    void* lpEnd = memmove(pDst, cpSrc, lsztDatalen);
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
inline int v_vsprintf(tChar* const pDst, const size_t csztDstSize, const tChar* const cpFmt, va_list vList)
{
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = vsprintf_s(pDst, csztDstSize, cpFmt, vList);
    if (liRet<0) { /* TODO ���������Ϣ */ };
#else
    int liRet = vsprintf(pDst, cpFmt, vList);
    if (liRet<0) { /* TODO ���������Ϣ */ };
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
inline int v_sprintf( tChar* const pDst, const size_t csztDstSize, const tChar* const cpFmt, ... )
{
    va_list vlist;
    va_start( vlist, cpFmt );
#if defined (_MSC_VER) && (_MSC_VER>=1300)
    int liRet = vsprintf_s( pDst,csztDstSize, cpFmt,vlist);
    if (liRet < 0) { /* TODO ���������Ϣ */ };
#else
    int liRet = vsprintf( pDst, cpFmt, vlist );
    if (liRet < 0) { /* TODO ���������Ϣ */ };
#endif
    va_end(vlist);

    return liRet;
}
// End of function v_sprintf(...)
/////////////////////////////////////////////////////////////////////////////////////////

inline tChar* v_strtrim_left( tChar* const pData, const size_t csztDataLen )
{
    // TODO : ������������
    if (csztDataLen <= 0) return nullptr;
    tChar* lpEnd = pData+ csztDataLen;

    tChar* lpPos = pData;
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

inline tChar* v_strtrim_right( tChar* const pData, const size_t csztDataLen )
{
    if (csztDataLen <= 0) return nullptr;
    tChar* lpEnd = pData+ csztDataLen;

    tChar* lpPos = lpEnd-1;
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

inline tChar* v_strtrim( tChar* const pData, const size_t csztDataLen )
{
    if (csztDataLen <= 0) return nullptr;
    tChar* lpEnd = pData + csztDataLen;

    tChar* lpStartPos = pData;
    size_t lsztStartOffset = 0;
    // while ((lpStartPos != lpEnd) && ((*lpStartPos == ' ') || (*lpStartPos == '\n') || (*lpStartPos == '\t')))
    while ((lpStartPos != lpEnd) && (isspace(*lpStartPos)))
    {
        lsztStartOffset++;
        lpStartPos = pData + lsztStartOffset;
    }

    tChar* lpEndPos = lpEnd;
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

inline size_t v_strtrim_left(tChar*const        pDst, const size_t sztDstSize,
                             const tChar* const pSrc, const size_t  sztSrcLen)
{
    // TODO : ������������
    if (sztSrcLen <= 0) return 0;
    tChar* lpEnd = (tChar*)pSrc + sztSrcLen;

    tChar* lpPos = (tChar*)pSrc;
    size_t lsztOffset = 0;
    // while ((lpPos != lpEnd) && ((*lpPos == ' ') || (*lpPos == '\n') || (*lpPos == '\t')))
    while ((lpPos != lpEnd) && (isspace(*lpPos)))
    {
        lsztOffset++;
        lpPos = (tChar*)pSrc + lsztOffset;
    }

    size_t lsztNewDataLen = sztSrcLen - lsztOffset;
    v_memzero(pDst,sztDstSize);
    size_t lsztCopied = v_memmove( pDst, sztDstSize, lpPos, lsztNewDataLen);

    return lsztCopied;
}

inline size_t v_strtrim_right(tChar*const        pDst, const size_t sztDstSize,
                              const tChar* const pSrc, const size_t  sztSrcLen)
{
    if (sztSrcLen <= 0) return 0;
    tChar* lpEnd = (tChar*)pSrc + sztSrcLen;

    tChar* lpPos = lpEnd;
    size_t lsztOffset = 0;
    // while ((lpPos != pSrc) && ((*lpPos == ' ') || (*lpPos == '\t') || (*lpPos == '\n')))
    while ((lpPos != pSrc) && (isspace(*lpPos)))
    {
        lsztOffset++;
        lpPos = lpEnd - lsztOffset;
    }

    size_t lsztNewDataLen = sztSrcLen - lsztOffset;
    v_memzero(pDst,sztDstSize);
    size_t lsztCopied = v_memmove(pDst, sztDstSize, pSrc, lsztNewDataLen);

    return lsztNewDataLen;
}

inline size_t v_strtrim(const tChar* const pSrc, const size_t  sztSrcLen, 
                        tChar*const        pDst, const size_t sztDstSize)
{
    if (sztSrcLen <= 0) return 0;
    tChar* lpEnd = (tChar*)pSrc + sztSrcLen;

    tChar* lpStartPos = (tChar*)pSrc;
    size_t lsztStartOffset = 0;
    // while ((lpStartPos != lpEnd) && ((*lpStartPos == ' ') || (*lpStartPos == '\n') || (*lpStartPos == '\t')))
    while ((lpStartPos != lpEnd) && (isspace(*lpStartPos)))
    {
        lsztStartOffset++;
        lpStartPos = (tChar*)pSrc + lsztStartOffset;
    }

    tChar* lpEndPos = lpEnd;
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


inline size_t v_str_substr(tChar* const       pDst, const size_t csztDstSize,
                           const tChar* const pSrc, const size_t  csztSrcLen, 
                           const int      ciBFlag, const int      ciEFlag )
{
    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tChar* lpStartPos = const_cast<tChar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if  ( ciBFlag != vMinsInt  )
    {
        lpStartPos = v_strchr((tChar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos+=sizeof(tChar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tChar* lpEndPos = const_cast<tChar*>(pSrc)+csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if  (  ciEFlag != vMinsInt  )
    {
        lpEndPos = v_strrchr((tChar*)pSrc, ciEFlag);
        if (lpEndPos == nullptr) return 0;

    } // End of if () ...

    // �ж����ַ����Ƿ���Ч��������ơ�}{������
    if (lpEndPos <= lpStartPos) return 0;

    // �������ַ�������
    size_t lsztNewDataLen = (lpEndPos) - (lpStartPos);
    size_t lsztCopied     = v_strncpy( pDst, csztDstSize, lpStartPos, lsztNewDataLen );
    return lsztCopied;
}

inline size_t v_str_substr(tChar* const    pSrc, const size_t  csztSrcLen,
                           const int   ciBFlag, const int        ciEFlag)
{
    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tChar* lpStartPos = const_cast<tChar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strchr((tChar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tChar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tChar* lpEndPos = const_cast<tChar*>(pSrc) + csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tChar*)pSrc, ciEFlag);
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

inline size_t v_str_substr_first(tChar* const    pSrc, const size_t  csztSrcLen,
                                 const int   ciBFlag, const int        ciEFlag)
{
    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tChar* lpStartPos = const_cast<tChar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strchr((tChar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tChar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tChar* lpEndPos = const_cast<tChar*>(pSrc) + csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strchr((tChar*)pSrc, ciEFlag);
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

inline size_t v_str_substr_last( tChar* const    pSrc, const size_t  csztSrcLen,
                                 const int   ciBFlag, const int        ciEFlag)
{
    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tChar* lpStartPos = const_cast<tChar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strrchr((tChar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tChar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tChar* lpEndPos = const_cast<tChar*>(pSrc) + csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tChar*)pSrc, ciEFlag);
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

inline size_t v_str_substr_last( tChar* const         pDst, const size_t  cszDstSize,
                                 const tChar* const   pSrc, const size_t  csztSrcLen,
                                 const int         ciBFlag, const int        ciEFlag)
{
    // ��ȡ�����ַ�������
    if (csztSrcLen == 0) return 0;

    // ��ȡ���ַ�����ͷ��λ��
    tChar* lpStartPos = const_cast<tChar*>(pSrc);
    // ����ciBFlag����vMinsInt,���Դ�ַ�������ʼ�ַ���Ϊ��ʼ
    if (ciBFlag != vMinsInt)
    {
        lpStartPos = v_strrchr((tChar*)pSrc, ciBFlag);
        if (lpStartPos == nullptr) return 0;

        lpStartPos += sizeof(tChar);
    }
    // End of if () ...

    // ��ȡ���ַ�����β��λ��
    tChar* lpEndPos = const_cast<tChar*>(pSrc) + csztSrcLen;
    // ����ciFFlag����vMinsInt,���Դ�ַ����Ľ����ַ���Ϊ��β
    if (ciEFlag != vMinsInt)
    {
        lpEndPos = v_strrchr((tChar*)pSrc, ciEFlag);
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

inline void v_toupper(tChar* pData, const size_t csztDataLen)
{
    tChar* lpPos = pData;
    size_t lsztOffset = 0;
    for ( size_t lsztOffset = 0; lsztOffset < csztDataLen; lsztOffset++ )
    {
        tChar* pValue = lpPos+lsztOffset;
        if (isalpha(*pValue))
            toupper(*pValue);
    }
}
inline void v_tolower(tChar* pData, const size_t csztDataLen)
{
    tChar* lpPos = pData;
    size_t lsztOffset = 0;
    for (size_t lsztOffset = 0; lsztOffset < csztDataLen; lsztOffset++)
    {
        tChar* pValue = lpPos + lsztOffset;
        if (isalpha(*pValue))
            tolower(*pValue);
    }
}

// --------------------------------------------------------------------------------------
#else // _V_PLATFORM_ != _V_PF_WIN_
// --------------------------------------------------------------------------------------
// linux util functions

// TODO : add linux until functions

// --------------------------------------------------------------------------------------
#endif // #if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_UTIL_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmUtil.h
/////////////////////////////////////////////////////////////////////////////////////////