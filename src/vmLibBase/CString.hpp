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
    CString(const char* const cpStr):mszBuf{0x00}{ v_strcpy(mszBuf, sizeof(mszBuf), cpStr); };
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
    // �ӷ�����
    void* operator +  (const char* cpSrc){};
    void* operator +  (const CString& cStr) 
    {
        return v_strcat(mszBuf, sizeof(mszBuf), cStr.c_str());
    };
    // ��ֵ����
    char* operator =  (const char* const cpSrc)
    {
        v_memcpy(mszBuf, sizeof(mszBuf), cpSrc, strlen(cpSrc));
        return mszBuf;
    };
    // С�ڲ���
    bool  operator <  (const char* cpSrc){};
    // ���ڲ���
    bool  operator >  (const char* cpSrc){};
    // �ԱȲ���
    bool  operator == (const char* cpSrc){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
    char   mszBuf[sztBufSize];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // ��ȡ�ַ�������ַ
    char* operator *() { return mszBuf; };
    // ��ȡ�ַ��������ַ�����ַ
    char* operator [] (const size_t csztPos) { return (mszBuf+csztPos); };
    // ��ȡ�ַ�������ַ
    const void* c_str() {};

    // ��ȡ�ַ�������
    size_t len() { return strlen(mszBuf); };
    // ��ȡָ�����ַ��������С
    size_t size() { return sizeof(mszBuf); };
    // ��������
    inline void clear() { v_memset(mszBuf, 0x00, sizeof(mszBuf)); };

public:
    // ��ȡ�ַ��������ַ�����ַ
    void* At(const size_t csztBufOffset) {};

    // ��ʽ���ַ���
    char* Fmt(const char* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        char* lpRet = Fmt(0, cpFmt, vList);
        va_end(vList);

        return lpRet;
    };
    char* Fmt(const size_t csztBufOffset, const char* const cpFmt, ...) 
    { 
        va_list vList;
        va_start( vList, cpFmt );
        char* lpRet = Fmt(csztBufOffset,cpFmt,vList);
        va_end(vList);

        return lpRet;
    };
    char* Fmt(const char* const cpFmt, va_list vList) 
    {
        return Fmt(0, cpFmt,vList);
    };
    char* Fmt( const size_t csztBufOffset, const char* const cpFmt, va_list vList)
    {
        char* lpPos = mszBuf+csztBufOffset;
        int liRet = v_vsprintf(lpPos, sizeof(mszBuf), cpFmt, vList);
        return lpPos;
    };
    int Fmt2(const char* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        int liRet = Fmt2(0, cpFmt, vList);
        va_end(vList);

        return liRet;
    };
    int Fmt2(const size_t csztBufOffset, const char* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        int liRet = Fmt2(csztBufOffset, cpFmt, vList);
        va_end(vList);

        return liRet;
    };
    int Fmt2(const char* const cpFmt, va_list vList)
    {
        return Fmt2(0, cpFmt, vList);
    };
    int Fmt2(const size_t csztBufOffset, const char* const cpFmt, va_list vList)
    {
        char* lpPos = mszBuf + csztBufOffset;
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

    // ��cpSrc�ַ���������ӵ����ַ�����
    void* Cat(const void* cpSrc) {};
    // ��cpSrc�ַ�����csztSrcLen���ȸ�����ӵ����ַ�����
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