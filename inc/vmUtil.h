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
// 重构windows中的str,mem系列函数


/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strchr(...)
// Brief     : 在字节串中搜索第一次出现的ciVal值地址
// Return    : char*                            - 查找的地址
//             nullptr                          - 未查找的指定的数据
// Parameter : cpBuf                            - 被搜索的字符串
//             ciVal                            - 标识数据
inline char* v_strchr(char* const cpBuf, const int ciVal)
{
    return strchr(cpBuf, ciVal);
}
// End of function v_strchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strrchr(...)
// Brief     : 在字节串中反向搜索第一次出现的ciVal地址
// Return    : char*                            - 查找的地址
//             nullptr                          - 未查找的指定的数据
// Parameter : cpBuf                            - 被搜索的字符串
//             ciVal                            - 标识数据
inline char* v_strrchr( char* const cpBuf, const int ciVal )
{
    return strrchr(cpBuf, ciVal);
}
// End of function v_strrchr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : v_strstr(...)
// Brief     : 在字节串中查找第一次出现子字符串的地址
// Return    : char*                            - 查找的地址，当cpSubStr为null时，返回cpBuf
//             nullptr                          - 未查找到指定的字符串
// Parameter : cpBuf                            - 被搜索的字符串
//             cpSubStr                         - 需要查找的子字符串
inline char* v_strstr( char* const cpBuf, const char* const cpSubStr )
{
    return strstr(cpBuf, cpSubStr);
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
// Brief     : 按字典顺序判断pStr1字符串是否大于pStr2字符串
// Return    : true                             - pStr1字符串大于pStr2字符串
//             false                            - pStr1字符串小于或等于pStr2字符串
// Parameter : pStr1                            - 字符串之一
//             pStr2                            - 字符串之一
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
// Brief     : 按字典顺序判断pStr1字符串是否小于pStr2字符串
// Return    : true                             - pStr1字符串小于pStr2字符串
//             false                            - pStr1字符串大于或等于pStr2字符串
// Parameter : pStr1                            - 字符串之一
//             pStr2                            - 字符串之一
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
// Brief     : 将由cpSrc字节串的副本中csztDataLen长度的字节追加到由pDst字节串的末尾
// Return    : char*                                - 返回复制完的字符串地址
//             nullptr                              - 出现异常
// Parameter : pDst                                 - 目的内存区地址
//             csztDstSize                          - 目的内存区大小
//             cpSrc                                - 源字符串
//             csztDataLen                          - 需复制的字符串大小
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
// Brief     : 将由cpSrc字节串的副本追加到由pDst字节串的末尾
// Return    : char*                                - 返回复制完的字符串地址
//             nullptr                              - 出现异常
// Parameter : pDst                                 - 目的内存区地址
//             csztDstSize                          - 目的内存区大小
//             cpSrc                                - 源字符串
inline char* v_strcat(char* const pDst, const size_t csztDstSize, const char* const cpSrc)
{
#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = strcat_s(pDst, csztDstSize, cpSrc);
    if (loRet != 0) { return nullptr; /* TODO : 添加错误处理 */ };

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
// Return    : char*                                - 返回复制完的字符串地址
//             nullptr                              - 出现异常
// Parameter : pDst                                 - 目的内存区地址
//             csztDstSize                          - 目的内存区大小
//             cpSrc                                - 源字符串
//             csztDataLen                          - 需复制的字符串大小
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
// Brief     : 将由cpSrc字节串的副本复制到由pDst指向的缓存区中
// Return    : char*                                - 返回复制完的字符串地址
//             nullptr                              - 出现异常
// Parameter : pDst                                 - 目的内存区地址
//             csztDstSize                          - 目的内存区大小
//             cpSrc                                - 源字符串
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
// Brief     : 将从pBuf开始csztDataLen长的缓存区的数据置为0x00
// Return    : void
// Parameter : pBuf                                 - 缓存区地址
//             csztDataLen                          - 缓存区大小
inline void v_memzero(void* const pBuf, const size_t csztDataLen)
{
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
inline void* v_memchr( void* const cpBuf, const int iVal, const size_t csztLookforLen)
{
    return memchr(cpBuf, iVal, csztLookforLen);
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
// Brief     : 按字典顺序比较缓存区cpBuf1于缓存区cpBuf2，长度为csztDataLen，不区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
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
// Brief     : 按字典顺序比较缓存区cpBuf1于缓存区cpBuf2，长度为csztDataLen，不区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
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
// Brief     : 按字典顺序比较字符串cpBuf1于字符串cpBuf2，长度为csztDataLen，区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
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
// Brief     : 按字典顺序比较字符串cpBuf1于字符串cpBuf2，长度为csztDataLen，区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
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
// Brief     : 按字典顺序比较字符串cpBuf1于字符串cpBuf2，长度为csztDataLen，区分大小写
// Return    : true                                 - 缓存区cpBuf1于缓存区cpBuf2相同
//             false                                - 缓存区cpBuf1于缓存区cpBuf2不同
// Parameter : cpBuf1                               - 缓存区之一
//             cpBuf2                               - 缓存区之一
//             csztDataLen                          - 对比的数据大小
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
// Brief     : 将cpSrc指向的数据区中的数据副本拷贝到pDst指向的数据去中，当遇到iVal值时，或复制csztDataLen长度的数据时停止。
// Return    : void*                                - 返回完成后的缓存区地址
// Parameter : pDst                                 - 目标缓存区
//             csztDstSize                          - 目标缓存区大小
//             cpSrc                                - 源缓存区
//             iVal                                 - 终止标识
//             csztDataLen                          - 复制的数据长度
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
// Brief     : 将cpSrc指向的数据区中的数据副本拷贝到pDst指向的数据去中，当复制csztDataLen长度的数据时停止。
// Return    : void*                                - 返回完成后的缓存区地址
// Parameter : pDst                                 - 目标缓存区
//             csztDstSize                          - 目标缓存区大小
//             cpSrc                                - 源缓存区
//             csztDataLen                          - 复制的数据长度
inline size_t v_memcpy(void* const pDst, const size_t csztDstSize, const void* const cpSrc, const size_t csztDataLen)
{
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = memcpy_s(pDst, csztDstSize, cpSrc, csztDataLen);
    if (loRet != 0) { return 0; /* TODO : 添加错误处理 */ };

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
// Brief     : 将cpSrc指向的数据区中的数据副本拷贝到pDst指向的数据去中，当复制csztDataLen长度的数据时停止。
// Return    : void*                                - 返回完成后的缓存区地址
// Parameter : pDst                                 - 目标缓存区
//             csztDstSize                          - 目标缓存区大小
//             cpSrc                                - 源缓存区
//             csztDataLen                          - 复制的数据长度
inline size_t v_memmove(void* const pDst, const size_t csztDstSize, const void* const cpSrc, const size_t csztDataLen )
{
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    errno_t loRet = memmove_s(pDst, csztDstSize, cpSrc, csztDataLen);
    if (loRet != 0) { return 0; /* TODO : 添加错误处理 */ };

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
// Brief     : 按cpFmt所设置的格式将参数中的数据重组到pDst指向的缓存区中
// Return    : int                                  - 复制的数据大小
//             -x                                   - 复制出错
// Parameter : pDst                                 - 目的缓存区地址
//             csztDstSize                          - 目的缓存区大小
//             cpFmt                                - 格式字符串
//             vList                                - 参数列表
inline int v_vsprintf(char* const pDst, const size_t csztDstSize, const char* const cpFmt, va_list vList)
{
#if defined (_MSC_VER) && (_MSC_VER > 1300)
    int liRet = vsprintf_s(pDst, csztDstSize, cpFmt, vList);
    if (liRet<0) { /* TODO 处理错误信息 */ };
#else
    int liRet = vsprintf(pDst, cpFmt, vList);
    if (liRet<0) { /* TODO 处理错误信息 */ };
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
inline int v_sprintf( char* const pDst, const size_t csztDstSize, const char* const cpFmt, ... )
{
    va_list vlist;
    va_start( vlist, cpFmt );
#if defined (_MSC_VER) && (_MSC_VER>=1300)
    int liRet = vsprintf_s( pDst,csztDstSize, cpFmt,vlist);
    if (liRet < 0) { /* TODO 处理错误信息 */ };
#else
    int liRet = vsprintf( pDst, cpFmt, vlist );
    if (liRet < 0) { /* TODO 处理错误信息 */ };
#endif
    va_end(vlist);

    return liRet;
}
// End of function v_sprintf(...)
/////////////////////////////////////////////////////////////////////////////////////////

inline char* v_strtrim_left( char* const pData )
{
    // TODO : 添加输入错误处理
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