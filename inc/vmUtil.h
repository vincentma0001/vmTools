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

#ifndef   __VM_CFGPLATFORM_H__
#	error this file need #include <vmCfgPlatform.h>
#endif // __VM_CFGPLATFORM_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :

#ifndef vMemZero
#   define vMemZero(szBuf) v_memzero(szBuf,sizeof(szBuf))
#endif // !vZero

#ifndef vMemSet
#   define vMemSet(szBuf, ciFlag) v_memset(szBuf,ciFlg,sizeof(szBuf))
#endif // !vMemSet

/////////////////////////////////////////////////////////////////////////////////////////
#if defined (_V_PLATFORM) && (_V_PLATFORM==__V_PLATFORM_WIN__)
// --------------------------------------------------------------------------------------
// �ع�windows�е�str,memϵ�к���


/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strchr(...)
// Brief     : ���ֽڴ���������һ�γ��ֵ�ciValֵ��ַ
// Return    : char*                            - ���ҵĵ�ַ
//             nullptr                          - δ���ҵ�ָ��������
// Parameter : cpBuf                            - ���������ַ���
//             ciVal                            - ��ʶ����
inline char* v_strchr(char* const cpBuf, const int ciVal)
{
    return strchr(cpBuf, ciVal);
}
// End of function v_strchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strrchr(...)
// Brief     : ���ֽڴ��з���������һ�γ��ֵ�ciVal��ַ
// Return    : char*                            - ���ҵĵ�ַ
//             nullptr                          - δ���ҵ�ָ��������
// Parameter : cpBuf                            - ���������ַ���
//             ciVal                            - ��ʶ����
inline char* v_strrchr( char* const cpBuf, const int ciVal )
{
    return strrchr(cpBuf, ciVal);
}
// End of function v_strrchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strstr(...)
// Brief     : ���ֽڴ��в��ҵ�һ�γ������ַ����ĵ�ַ
// Return    : char*                            - ���ҵĵ�ַ����cpSubStrΪnullʱ������cpBuf
//             nullptr                          - δ���ҵ�ָ�����ַ���
// Parameter : cpBuf                            - ���������ַ���
//             cpSubStr                         - ��Ҫ���ҵ����ַ���
inline char* v_strstr( char* const cpBuf, const char* const cpSubStr )
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
inline bool v_strcmp_equl( const char* const pStr1, const char* const pStr2 )
{
    int liRet  = strcmp(pStr1, pStr1);
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
inline bool v_strcmp_more(const char* const pStr1, const char* const pStr2)
{
    int liRet = strcmp(pStr1, pStr1);
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
inline bool v_strcmp_less(const char* const pStr1, const char* const pStr2)
{
    int liRet = strcmp(pStr1, pStr1);
    if (liRet < 0) 
        return  true;

    return false;
}
// End of function v_strcmp_less(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strncat(...)
// Brief     : ����cpSrc�ֽڴ��ĸ�����csztDataLen���ȵ��ֽ�׷�ӵ���pDst�ֽڴ���ĩβ
// Return    : char*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
//             csztDataLen                          - �踴�Ƶ��ַ�����С
inline char* v_strncat(char* const pDst, const size_t csztDstSize, const char* const cpSrc, const size_t csztDataLen)
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
// Return    : char*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
inline char* v_strcat(char* const pDst, const size_t csztDstSize, const char* const cpSrc)
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
// Return    : char*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
//             csztDataLen                          - �踴�Ƶ��ַ�����С
inline size_t v_strncpy(char* const pDst, const size_t csztDstSize, const char* const cpSrc, const size_t csztDataLen)
{
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = strncpy_s(pDst, csztDstSize, cpSrc, csztDataLen);
    if (loRet != 0) { return 0;};

    return csztDataLen;
#else
    char* lpEnd = strncpy(pDst, cpSrc, csztDataLen)
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
// Return    : char*                                - ���ظ�������ַ�����ַ
//             nullptr                              - �����쳣
// Parameter : pDst                                 - Ŀ���ڴ�����ַ
//             csztDstSize                          - Ŀ���ڴ�����С
//             cpSrc                                - Դ�ַ���
inline size_t v_strcpy( char* const pDst, const size_t csztDstSize, const char* const cpSrc )
{
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = strcpy_s(pDst,csztDstSize,cpSrc);
    if (loRet != 0) { return 0; };
    
    return strlen(pDst);
#else
    char* lpEnd = strcpy(pDst, cpSrc)
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
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    void* lpEnd = _memccpy(pDst, cpSrc, iVal, csztDataLen);
    if ( lpEnd == 0 )
        return csztDataLen;
#else
    void* lpEnd = memccpy(pDst, cpSrc, iVal, csztDataLen);
    if ( lpEnd == 0 )
        return csztDataLen
#endif

    size_t lsztCoyied = (char*)lpEnd - (char*)pDst; 
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
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = memcpy_s(pDst, csztDstSize, cpSrc, csztDataLen);
    if (loRet != 0) { return 0; /* TODO : ��Ӵ����� */ };

    return csztDataLen;
#else
    void* lpEnd = memcpy(pDst, cpSrc, csztDataLen);
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
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = memmove_s(pDst, csztDstSize, cpSrc, csztDataLen);
    if (loRet != 0) { return 0; /* TODO : ��Ӵ����� */ };

    return csztDataLen;
#else
    void* lpEnd = memmove(pDst, cpSrc, csztDataLen);
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
inline int v_vsprintf(char* const pDst, const size_t csztDstSize, const char* const cpFmt, va_list vList)
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
inline int v_sprintf( char* const pDst, const size_t csztDstSize, const char* const cpFmt, ... )
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

inline char* v_strtrim_left( char* const pData )
{
    // TODO : ������������
    size_t lsztDataLen = strlen(pData);
    if (lsztDataLen <= 0) return nullptr;
    char* lpEnd = pData+lsztDataLen;

    char* lpPos = pData;
    size_t lsztOffset = 0;
    while ( (lpPos!=lpEnd) && ( (*lpPos == ' ') || (*lpPos=='\n') || (*lpPos=='\t') )  )
    {
        lsztOffset++;
        lpPos = pData+lsztOffset;
    }
    
    size_t lsztNewDataLen = lsztDataLen-lsztOffset;
    size_t lsztCopied = v_memmove( pData, lsztDataLen, lpPos, lsztNewDataLen);

    lpEnd = pData+lsztNewDataLen;
    v_memset(lpEnd, 0x00, lsztOffset );

    return pData;
}

inline char* v_strtrim_right( char* const pData )
{
    size_t lsztDataLen = strlen(pData);
    if (lsztDataLen <= 0) return nullptr;
    char* lpEnd = pData+lsztDataLen;

    char* lpPos = lpEnd;
    size_t lsztOffset = 0;
    while( (lpPos!=pData) && ((*lpPos==' ') || (*lpPos=='\t') || (*lpPos=='\n') ) )
    {
        lsztOffset++;
        lpPos = lpEnd-lsztOffset;
    }
    
    v_memset(lpPos, 0x00, lsztOffset);

    return pData;
}

inline char* v_strtrim(char* const pData)
{
    size_t lsztDataLen = strlen(pData);
    if (lsztDataLen <= 0) return nullptr;
    char* lpEnd = pData + lsztDataLen;

    char* lpStartPos = pData;
    size_t lsztStartOffset = 0;
    while ((lpStartPos != lpEnd) && ((*lpStartPos == ' ') || (*lpStartPos == '\n') || (*lpStartPos == '\t')))
    {
        lsztStartOffset++;
        lpStartPos = pData + lsztStartOffset;
    }

    char* lpEndPos = lpEnd;
    size_t lsztEndOffset = 0;
    while ((lpEndPos != lpStartPos) && ((*lpEndPos == ' ') || (*lpEndPos == '\t') || (*lpEndPos == '\n')))
    {
        lsztEndOffset++;
        lpEndPos = lpEnd - lsztEndOffset;
    }

    size_t lsztNewDataLen = lpEndPos -lpStartPos;
    size_t lsztCopied = v_memmove(pData, lsztDataLen, lpStartPos, lsztNewDataLen);

    lpEnd = pData + lsztNewDataLen;
    size_t lsztDateRemove = lsztStartOffset + lsztEndOffset;
    v_memset(lpEnd, 0x00, lsztDateRemove);

    return pData;
}


// --------------------------------------------------------------------------------------
#else // _V_PLATFORM != __V_PLATFORM_WIN__
// --------------------------------------------------------------------------------------
// linux util functions

// TODO : add linux until functions

// --------------------------------------------------------------------------------------
#endif // #if defined (_V_PLATFORM) && (_V_PLATFORM==__V_PLATFORM_WIN__)
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