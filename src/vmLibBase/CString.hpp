/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CString.hpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/01 13:38:09
// Modify time  : 2020/01/01 13:38:09
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

#ifndef __CSTRING_HPP__
#define __CSTRING_HPP__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>
#endif // __VM_CFG_H__

// Platform files included

// Used files included
#ifndef   __VM_UTIL_H__
#	error this file need #include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CString : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template <size_t sztBufSize>
class CString
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    CString():mszBuf{0x00}{};
    CString(const tchar* const cpStr):mszBuf{0x00}{ v_strcpy(mszBuf, sizeof(mszBuf), cpStr); };
    // Destruct define
    virtual ~CString(){};
    
public:
    // Copy construct define
    CString(const CString<sztBufSize>& obj)
    {
        *this = obj;
    };
    // Assignment define
    CString& operator = ( const CString<sztBufSize>& obj )
    {
        v_memcpy(mszBuf, sizeof(mszBuf), obj.mszBuf, sizeof(obj.mszBuf));
        return *this;
    };

public:
    // 加法操作
    void* operator +  (const tchar* cpSrc){};
    void* operator +  (const CString& cStr) 
    {
        return v_strcat(mszBuf, sizeof(mszBuf), cStr.c_str());
    };
    // 赋值操作
    tchar* operator =  (const tchar* const cpSrc)
    {
        v_memcpy(mszBuf, sizeof(mszBuf), cpSrc, vStrlen(cpSrc));
        return mszBuf;
    };
    // 小于操作
    bool  operator <  (const tchar* cpSrc){};
    // 大于操作
    bool  operator >  (const tchar* cpSrc){};
    // 对比操作
    bool  operator == (const tchar* cpSrc){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
    tchar   mszBuf[sztBufSize];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 获取字符串基地址
    tchar* operator *() { return mszBuf; };
    // 获取字符串中子字符串地址
    tchar* operator [] (const size_t csztPos) { return (mszBuf+csztPos); };
    // 获取字符串基地址
    const void* c_str() {};

    // 获取字符串长度
    size_t len() { return strlen(mszBuf); };
    // 获取指定的字符串缓存大小
    size_t size() { return sizeof(mszBuf); };
    // 清理数据
    inline void clear() { v_memset(mszBuf, 0x00, sizeof(mszBuf)); };

public:
    // 获取字符串中子字符串地址
    void* At(const size_t csztBufOffset) {};

    // 格式化字符串
    tchar* Fmt(const tchar* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        tchar* lpRet = Fmt(0, cpFmt, vList);
        va_end(vList);

        return lpRet;
    };
    tchar* Fmt(const size_t csztBufOffset, const tchar* const cpFmt, ...) 
    { 
        va_list vList;
        va_start( vList, cpFmt );
        tchar* lpRet = Fmt(csztBufOffset,cpFmt,vList);
        va_end(vList);

        return lpRet;
    };
    tchar* Fmt(const tchar* const cpFmt, va_list vList) 
    {
        return Fmt(0, cpFmt,vList);
    };
    tchar* Fmt( const size_t csztBufOffset, const tchar* const cpFmt, va_list vList)
    {
        tchar* lpPos = mszBuf+csztBufOffset;
        int liRet = v_vsprintf(lpPos, sizeof(mszBuf), cpFmt, vList);
        return lpPos;
    };
    int Fmt2(const tchar* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        int liRet = Fmt2(0, cpFmt, vList);
        va_end(vList);

        return liRet;
    };
    int Fmt2(const size_t csztBufOffset, const tchar* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        int liRet = Fmt2(csztBufOffset, cpFmt, vList);
        va_end(vList);

        return liRet;
    };
    int Fmt2(const tchar* const cpFmt, va_list vList)
    {
        return Fmt2(0, cpFmt, vList);
    };
    int Fmt2(const size_t csztBufOffset, const tchar* const cpFmt, va_list vList)
    {
        tchar* lpPos = mszBuf + csztBufOffset;
        size_t lsztBufLeft = sztBufSize-csztBufOffset;
        return v_vsprintf(lpPos, lsztBufLeft, cpFmt, vList);
    };


    bool Cmp(const void* const cpSrc)
    {
        return v_strcmp_equl(mszBuf, cpSrc);
    }
    bool Cmp(const size_t csztBufOffSet, const void* const cpSrc, const size_t csztDataLen)
    {
        void* lpPos = mszBuf + csztBufOffSet;
        return v_memcmp_equl(lpPos, cpSrc, csztDataLen);
    }
    bool iCmp(const size_t csztBufOffSet, const void* const cpSrc, const size_t csztDataLen)
    {
        void* lpPos = mszBuf + csztBufOffSet;
        return v_memicmp_equl(lpPos, cpSrc, csztDataLen);
    }

    // 将cpSrc字符串副本添加到本字符串中
    void* Cat(const void* cpSrc) {};
    // 将cpSrc字符串中csztSrcLen长度副本添加到本字符串中
    void* Cat(const void* cpSrc, const size_t csztSrcLen) {};

    void* Sub(const void* cpSubStr) 
    {
        return v_strstr( mszBuf, cpSubStr );
    };
    void* Sub(const size_t csztBufOffset, const void* cpSubStr) {};

    void* Find(const int ciFlag) 
    {
        return v_strchr( mszBuf, ciFlag );
    };
    void* Find(const size_t csztBufOffset, const int ciFlag) {};
    void* rFind(const int ciFlag) {};
    void* rFind(const size_t csztBufOffset, const int ciFlag) {};

    size_t CopyFm(const void* cpSrc) {};
    size_t CopyFm(const size_t csztBufOffset, const void* cpSrc) {};
    size_t CopyFm(const void* cpSrc, const size_t csztSrcLen) {};
    size_t CopyFm(const size_t csztBufOffset, const void* cpSrc, const size_t csztSrcLen) {};

    size_t CopyTo(void* pDst) {};
    size_t CopyTo(const size_t csztBufOffset, void* pDst) {};
    size_t CopyTo(void* pDst, const size_t csztDstSize, const size_t csztDataLen) {};
    size_t CopyTo(const size_t csztBufOffset, void* pDst, const size_t csztDstSize, const size_t csztDataLen) {};

}; // End of class CString
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSTRING_HPP__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CString.hpp
/////////////////////////////////////////////////////////////////////////////////////////