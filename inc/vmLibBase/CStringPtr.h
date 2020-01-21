/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CStringPtr.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2019/12/30 22:01:01
// Modify time  : 2019/12/30 22:01:01
// Note         : 
//  TODO unDoucumented
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

#ifndef __CSTRINGPTR_H__
#define __CSTRINGPTR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#ifndef   __VM_CFG_TSTRING_H__
#   include <vmCfg/vmCfgtString.h>
#endif // __VM_CFG_TSTRING_H__

// Platform files included

// Used files included
#ifndef   __VM_UTIL_H__
#   include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define

#ifndef    vCStrPtr
#   define vCStrPtr( szBuf ) vm::CStrPtr(szBuf,sizeof(szBuf))
#endif  // vCStrPtr

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CStrPtr : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CStringPtr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CStringPtr( tchar* const pBuf, const size_t cszBufSize);
    // Destruct define
    inline virtual ~CStringPtr();
    
public:
    // Copy construct define
    inline CStringPtr(const CStringPtr& obj);
    // Assignment define
    inline CStringPtr& operator = ( const CStringPtr& obj );

public:
    // 加法操作
    inline tchar* operator + (const tchar* cpSrc);
    inline tchar* operator + (const tchar cszVal);
    // 赋值操作
    inline void  operator =  (const tchar* cpSrc);
    // 小于操作
    inline bool  operator <  (const tchar* cpSrc);
    // 大于操作
    inline bool  operator >  (const tchar* cpSrc);
    // 对比操作
    inline bool  operator == (const tchar* cpSrc);
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
    // 字符串基地址
    tchar*   mpBuf;
    // 字符串长度
    size_t   mszBufSize;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 获取字符串基地址
    inline tchar*       operator *  ();
    // 获取字符串中子字符串地址
    inline tchar*       operator [] (const size_t csztPos);
    // 获取字符串基地址
    inline const tchar* c_str       ();

    // 获取字符串长度
    inline size_t len   ();
    // 获取指定的字符串缓存大小
    inline size_t size  ();
    // 清理数据
    inline void   clear () { v_memzero(mpBuf, mszBufSize); };

public:
    // 获取字符串中子字符串地址
    inline tchar* At    ( const size_t csztBufOffset );

    // 格式化字符串
    inline tchar* Fmt   (                            const tchar* const cpFmt,           ...);
    inline tchar* Fmt   (const size_t csztBufOffset, const tchar* const cpFmt,           ...);
    inline tchar* Fmt   (const size_t csztBufOffset, const tchar* const cpFmt, va_list vList);

    inline int    Fmt2  (                            const tchar* const cpFmt,           ...);
    inline int    Fmt2  (const size_t csztBufOffset, const tchar* const cpFmt,           ...);
    inline int    Fmt2  (const size_t csztBufOffset, const tchar* const cpFmt, va_list vList);
    
    inline bool   Cmp   ( const tchar* const cpSrc );
    inline bool   Cmp   ( const tchar* const cpSrc, const size_t csztDataLen, const size_t csztBufOffSet = 0 );
    inline bool   iCmp  ( const tchar* const cpSrc, const size_t csztDataLen, const size_t csztBufOffset = 0 );

    // 将cpSrc字符串副本添加到本字符串中
    inline tchar* Cat   ( const tchar* cpSrc );
    // 将cpSrc字符串中csztSrcLen长度副本添加到本字符串中
    inline tchar* Cat   ( const tchar* cpSrc, const size_t csztSrcLen );

    inline tchar* Sub   ( const tchar* const cpSubStr, const size_t csztBufOffset = 0 );

    inline tchar* Find  ( const int ciFlag, const size_t csztBufOffset = 0 );
    inline tchar* rFind ( const int czFlag, const size_t csztBufOffset = 0 );
    
    inline size_t CopyFm( const tchar* cpSrc, const size_t csztBufOffset = 0 );
    inline size_t CopyFm( const tchar* cpSrc, const size_t csztSrcLen, const size_t csztBufOffset );

    inline size_t CopyTo( tchar* const pDst, const size_t csztBufOffset = 0 );
    inline size_t CopyTo( tchar* const pDst, const size_t csztDstSize, const size_t csztDataLen, const size_t csztBufOffset = 0 );

}; // End of class CStrPtr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CStrPtr(...)
// Brief     :
// Return    : 
// Parameter : tchar *  & pBuf
// Parameter : const size_t cszBufSize
CStringPtr::CStringPtr(tchar* const pBuf, const size_t cszBufSize) :mpBuf(pBuf), mszBufSize(cszBufSize)
{

}
// End of function CStrPtr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CStrPtr(...)
// Brief     :
// Return    : 
CStringPtr::~CStringPtr()
{

}
// End of function ~CStrPtr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CStringPtr(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline CStringPtr::CStringPtr(const CStringPtr& obj) 
{ 
    *this = obj; 
};
// End of function CStringPtr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator = (...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
// Assignment define
inline CStringPtr& CStringPtr::operator = (const CStringPtr& obj)
{
    v_strcpy(mpBuf, mszBufSize, obj.mpBuf);
};
// End of function operator = (...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator+(...)
// Brief     :
// Return    : tchar*
// Parameter : const tchar * cpSrc
tchar* CStringPtr::operator+(const tchar* cpSrc)
{
    return v_strcat(mpBuf, mszBufSize, cpSrc);
}
// End of function operator+(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator +(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline tchar* CStringPtr::operator +  (const tchar  cszVal)
{
    size_t lszBufStrLen = vStrlen(mpBuf);
    if (lszBufStrLen >= mszBufSize)
        return nullptr;
    mpBuf[ lszBufStrLen ] = cszVal;
    mpBuf[ lszBufStrLen + 1 ] = 0x00;
};
// End of function operator +(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     :
// Return    : void
// Parameter : const tchar * cpSrc
void CStringPtr::operator=(const tchar* cpSrc)
{
    size_t lsztRet = v_strcpy(mpBuf, mszBufSize, cpSrc);
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator<(...)
// Brief     :
// Return    : bool
// Parameter : const tchar * cpSrc
bool CStringPtr::operator<(const tchar* cpSrc)
{
    return v_strcmp_less(mpBuf, cpSrc);
}
// End of function operator<(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator>(...)
// Brief     :
// Return    : bool
// Parameter : const tchar * cpSrc
bool CStringPtr::operator>(const tchar* cpSrc)
{
    return v_strcmp_more(mpBuf, cpSrc);
}
// End of function operator>(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator==(...)
// Brief     :
// Return    : bool
// Parameter : const tchar * cpSrc
bool CStringPtr::operator==(const tchar* cpSrc)
{
    return v_strcmp_equl(mpBuf, cpSrc);
}
// End of function operator==(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : 
// Brief     : # add method brief here #
// Return    : void
// Parameter : null
tchar* CStringPtr::operator [](const size_t csztBufOffset)
{
    return (mpBuf + csztBufOffset);
}
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator*(...)
// Brief     :
// Return    : tchar*
tchar* CStringPtr::operator*()
{
    return mpBuf;
}
// End of function operator*(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : c_str(...)
// Brief     :
// Return    : const tchar*
const tchar* CStringPtr::c_str()
{
    return mpBuf;
}
// End of function c_str(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : len(...)
// Brief     :
// Return    : size_t
size_t CStringPtr::len()
{
    return vStrlen(mpBuf);
}
// End of function len(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : size(...)
// Brief     :
// Return    : size_t
size_t CStringPtr::size()
{
    return mszBufSize;
}
// End of function size(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : At(...)
// Brief     :
// Return    : tchar*
// Parameter : const size_t csztBufOffset
tchar* CStringPtr::At(const size_t csztBufOffset)
{
    return (mpBuf + csztBufOffset);
}
// End of function At(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline tchar* CStringPtr::Fmt(const tchar* const cpFmt, ...)
{
    va_list vList;
    va_start(vList, cpFmt);
    tchar* lpRet = Fmt(0, cpFmt, vList);
    va_end(vList);

    return lpRet;
};
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline tchar* CStringPtr::Fmt(const size_t csztBufOffset, const tchar* const cpFmt, ...)
{
    va_list vList;
    va_start(vList, cpFmt);
    tchar* lpRet = Fmt(csztBufOffset, cpFmt, vList);
    va_end(vList);

    return lpRet;
};
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline tchar* CStringPtr::Fmt(const size_t csztBufOffset, const tchar* const cpFmt, va_list vList)
{
    tchar* lpPos = mpBuf + csztBufOffset;
    int liRet = v_vsprintf(lpPos, mszBufSize, cpFmt, vList);
    return lpPos;
};
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt2(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline int CStringPtr::Fmt2(const tchar* const cpFmt, ...)
{
    va_list vList;
    va_start(vList, cpFmt);
    int liRet = Fmt2(0, cpFmt, vList);
    va_end(vList);

    return liRet;
};
// End of function Fmt2(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt2(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline int CStringPtr::Fmt2(const size_t csztBufOffset, const tchar* const cpFmt, ...)
{
    va_list vList;
    va_start(vList, cpFmt);
    int liRet = Fmt2(csztBufOffset, cpFmt, vList);
    va_end(vList);

    return liRet;
};
// End of function Fmt2(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt2(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline int CStringPtr::Fmt2(const size_t csztBufOffset, const tchar* const cpFmt, va_list vList)
{
    tchar* lpPos = mpBuf + csztBufOffset;
    return v_vsprintf(lpPos, mszBufSize, cpFmt, vList);
};
// End of function Fmt2(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Cmp(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline bool CStringPtr::Cmp(const tchar* const cpSrc)
{
    return v_strcmp_equl(mpBuf, cpSrc);
}
// End of function Cmp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Cmp(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline bool CStringPtr::Cmp(const tchar* const cpSrc, const size_t csztDataLen, const size_t csztBufOffSet = 0)
{
    tchar* lpPos = mpBuf + csztBufOffSet;
    return v_strncmp_equl(lpPos, cpSrc, csztDataLen);
}
// End of function Cmp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : iCmp(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
inline bool CStringPtr::iCmp(const tchar* const cpSrc, const size_t csztDataLen, const size_t csztBufOffset = 0)
{
    void* lpPos = mpBuf + csztBufOffset;
    return v_memicmp_equl(lpPos, cpSrc, csztDataLen);
}
// End of function iCmp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Cat(...)
// Brief     :
// Return    : tchar*
// Parameter : const tchar * cSrc
tchar* CStringPtr::Cat(const tchar* cSrc)
{
    return v_strcat(mpBuf, mszBufSize, cSrc);
}
// End of function Cat(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Cat(...)
// Brief     :
// Return    : tchar*
// Parameter : const tchar * cpSrc
// Parameter : const size_t csztSrcLen
tchar* CStringPtr::Cat(const tchar* cpSrc, const size_t csztSrcLen)
{
    return v_strncat(mpBuf, mszBufSize, cpSrc, csztSrcLen);
}
// End of function Cat(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Sub(...)
// Brief     :
// Return    : tchar*
// Parameter : const size_t csztBufOffset
// Parameter : const tchar * cpSubStr
tchar* CStringPtr::Sub(const tchar* const cpSubStr, const size_t csztBufOffset )
{
    tchar* lpPos = mpBuf + csztBufOffset;
    return v_strstr(lpPos, cpSubStr);
}
// End of function Sub(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : rFind(...)
// Brief     :
// Return    : tchar*
// Parameter : const size_t csztBufOffset
// Parameter : const tchar czFlag
tchar* CStringPtr::rFind(const int ciFlag, const size_t csztBufOffset)
{
    tchar* lpPos = mpBuf + csztBufOffset;
    return v_strrchr(lpPos, ciFlag);
}
// End of function rFind(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     :
// Return    : tchar*
// Parameter : const size_t csztBufOffset
// Parameter : const tchar czFlag
tchar* CStringPtr::Find(const int ciFlag, const size_t csztBufOffset)
{
    tchar* lpPos = mpBuf + csztBufOffset;
    return v_strchr(lpPos, ciFlag);
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm(...)
// Brief     :
// Return    : void
// Parameter : const size_t csztBufOffset
// Parameter : const tchar * cpSrc
size_t CStringPtr::CopyFm(const tchar* cpSrc, const size_t csztBufOffset)
{
    tchar* lpPos = mpBuf + csztBufOffset;
    return v_strcpy(lpPos, mszBufSize, cpSrc);
}
// End of function CopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm(...)
// Brief     :
// Return    : void
// Parameter : const size_t csztBufOffset
// Parameter : const tchar * cpSrc
// Parameter : const size_t csztSrcLen
size_t CStringPtr::CopyFm(const tchar* cpSrc, const size_t csztSrcLen, const size_t csztBufOffset)
{
    tchar* lpPos = mpBuf + csztBufOffset;
    return v_strncpy(lpPos, mszBufSize, cpSrc, csztSrcLen);
}
// End of function CopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     :
// Return    : void
// Parameter : const size_t csztBufOffset
// Parameter : tchar * pDst
size_t CStringPtr::CopyTo(tchar* pDst, const size_t csztBufOffset)
{
    tchar* lpPos = mpBuf + csztBufOffset;
    return v_strcpy(pDst, mszBufSize, lpPos);
}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     :
// Return    : void
// Parameter : const size_t csztBufOffset
// Parameter : tchar * pDst
// Parameter : const size_t csztDstSize
// Parameter : const size_t csztDataLen
size_t CStringPtr::CopyTo(tchar* pDst, const size_t csztDstSize, const size_t csztDataLen, const size_t csztBufOffset)
{
    tchar* lpPos = mpBuf + csztBufOffset;
    return v_strncpy(pDst, csztDstSize, lpPos, csztDataLen);
}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/*/////////////////////////////////////////////////////////////////////////////////////////
ASCII values	characters	                iscntrl	isblank	isspace	isupper	islower	isalpha	isdigit	isxdigit	isalnum	ispunct	isgraph	isprint
0x00 .. 0x08	NUL, (other control codes)	x
0x09	tab('\t')	                        x	x	x
0x0A .. 0x0D	(white - space control codes : '\f', '\v', '\n', '\r')	x		x
0x0E .. 0x1F	(other control codes)	x
0x20	space(' ')		x	x									x
0x21 .. 0x2F	!"#$%&'()*+,-./										x	x	x
0x30 .. 0x39	0123456789							x	x	x		x	x
0x3a .. 0x40	:; <= > ? @										x	x	x
0x41 .. 0x46	ABCDEF				x		x		x	x		x	x
0x47 .. 0x5A	GHIJKLMNOPQRSTUVWXYZ				x		x			x		x	x
0x5B .. 0x60[\] ^ _`										x	x	x
0x61 .. 0x66	abcdef					x	x		x	x		x	x
0x67 .. 0x7A	ghijklmnopqrstuvwxyz					x	x			x		x	x
0x7B .. 0x7E	{ | }~x	x	x
0x7F	(DEL)x
*/

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSTRINGPTR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CStringPtr.h
/////////////////////////////////////////////////////////////////////////////////////////