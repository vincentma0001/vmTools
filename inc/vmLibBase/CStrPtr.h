/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CStrPtr.h
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

#ifndef __CSTRPTR_H__
#define __CSTRPTR_H__

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
// Macro define

#ifndef   vCStrPtr
#   define  vCStrPtr( szBuf ) vm::CStrPtr(szBuf,sizeof(szBuf))
#endif // vCStrPtr

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CStrPtr : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CStrPtr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CStrPtr( tChar* const pBuf, const size_t cszBufSize);
    // Destruct define
    inline virtual ~CStrPtr();
    
private:
    // No Copy
    inline CStrPtr(const CStrPtr& obj):mpBuf(obj.mpBuf){};
    // No Assignment
    inline CStrPtr& operator = ( const CStrPtr& obj ){};

public:
    // �ӷ�����
    inline tChar* operator +  (const tChar* cpSrc);
    inline tChar* operator +  (const tChar  cszVal)
    {
        size_t lszBufStrLen = vStrLen(mpBuf);
        if ( lszBufStrLen>=mszBufSize )
            return nullptr;
        mpBuf[lszBufStrLen]   = cszVal;
        mpBuf[lszBufStrLen+1] = 0x00;
    };
    // ��ֵ����
    inline void  operator =  (const tChar* cpSrc);
    // С�ڲ���
    inline bool  operator <  (const tChar* cpSrc);
    // ���ڲ���
    inline bool  operator >  (const tChar* cpSrc);
    // �ԱȲ���
    inline bool  operator == (const tChar* cpSrc);
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
    // �ַ�������ַ
    tChar*    mpBuf;
    // �ַ�������
    size_t   mszBufSize;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // ��ȡ�ַ�������ַ
    inline tChar* operator *();
    // ��ȡ�ַ��������ַ�����ַ
    inline tChar* operator [] (const size_t csztPos);
    // ��ȡ�ַ�������ַ
    inline const tChar* c_str();

    // ��ȡ�ַ�������
    inline size_t len();
    // ��ȡָ�����ַ��������С
    inline size_t size();
    // ��������
    inline void clear() { vMemZero(mpBuf); };

public:
    // ��ȡ�ַ��������ַ�����ַ
    inline tChar* At( const size_t csztBufOffset );

    // ��ʽ���ַ���
    inline tChar* Fmt(const tChar* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        tChar* lpRet = Fmt(0, cpFmt, vList);
        va_end(vList);

        return lpRet;
    };
    inline tChar* Fmt(const size_t csztBufOffset, const tChar* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        tChar* lpRet = Fmt(csztBufOffset, cpFmt, vList);
        va_end(vList);

        return lpRet;
    };
    inline tChar* Fmt(const tChar* const cpFmt, va_list vList)
    {
        return Fmt(0, cpFmt, vList);
    };
    inline tChar* Fmt(const size_t csztBufOffset, const tChar* const cpFmt, va_list vList)
    {
        tChar* lpPos = mpBuf + csztBufOffset;
        int liRet = v_vsprintf(lpPos, mszBufSize, cpFmt, vList);
        return lpPos;
    };
    inline int Fmt2(const tChar* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        int liRet = Fmt2(0, cpFmt, vList);
        va_end(vList);

        return liRet;
    };
    inline int Fmt2(const size_t csztBufOffset, const tChar* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        int liRet = Fmt2(csztBufOffset, cpFmt, vList);
        va_end(vList);

        return liRet;
    };
    inline int Fmt2(const tChar* const cpFmt, va_list vList)
    {
        return Fmt2(0, cpFmt, vList);
    };
    inline int Fmt2(const size_t csztBufOffset, const tChar* const cpFmt, va_list vList)
    {
        tChar* lpPos = mpBuf + csztBufOffset;
        return v_vsprintf(lpPos, mszBufSize, cpFmt, vList);
    };
    

    inline bool Cmp(const tChar* const cpSrc)
    {
        return v_strcmp_equl(mpBuf, cpSrc);
    }
    inline bool Cmp(const tChar* const cpSrc, const size_t csztDataLen, const size_t csztBufOffSet = 0)
    {
        tChar* lpPos = mpBuf + csztBufOffSet;
        return v_strncmp_equl(lpPos, cpSrc, csztDataLen);
    }
    inline bool iCmp(const tChar* const cpSrc, const size_t csztDataLen, const size_t csztBufOffset = 0)
    {
        void* lpPos = mpBuf + csztBufOffset;
        return v_memicmp_equl(lpPos, cpSrc, csztDataLen);
    }

    // ��cpSrc�ַ���������ӵ����ַ�����
    inline tChar* Cat( const tChar* cpSrc );
    // ��cpSrc�ַ�����csztSrcLen���ȸ�����ӵ����ַ�����
    inline tChar* Cat( const tChar* cpSrc, const size_t csztSrcLen );

    inline tChar* Sub( const tChar* const cpSubStr );
    inline tChar* Sub( const size_t csztBufOffset, const tChar* const cpSubStr);

    inline tChar* Find (const int ciFlag);
    inline tChar* Find (const size_t csztBufOffset, const int ciFlag);
    inline tChar* rFind(const int ciFlag);
    inline tChar* rFind(const size_t csztBufOffset, const int czFlag);
    
    inline size_t CopyFm( const tChar* cpSrc );
    inline size_t CopyFm( const size_t csztBufOffset, const tChar* cpSrc );
    inline size_t CopyFm( const tChar* cpSrc, const size_t csztSrcLen );
    inline size_t CopyFm( const size_t csztBufOffset, const tChar* cpSrc, const size_t csztSrcLen );

    inline size_t CopyTo( tChar* pDst );
    inline size_t CopyTo( const size_t csztBufOffset, tChar* pDst );
    inline size_t CopyTo( tChar* pDst, const size_t csztDstSize, const size_t csztDataLen );
    inline size_t CopyTo( const size_t csztBufOffset, tChar* pDst, const size_t csztDstSize, const size_t csztDataLen);

}; // End of class CStrPtr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CStrPtr(...)
// Brief     :
// Return    : 
// Parameter : tChar *  & pBuf
// Parameter : const size_t cszBufSize
CStrPtr::CStrPtr(tChar* const pBuf, const size_t cszBufSize) :mpBuf(pBuf), mszBufSize(cszBufSize)
{

}
// End of function CStrPtr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CStrPtr(...)
// Brief     :
// Return    : 
CStrPtr::~CStrPtr()
{

}
// End of function ~CStrPtr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator+(...)
// Brief     :
// Return    : tChar*
// Parameter : const tChar * cpSrc
tChar* CStrPtr::operator+(const tChar* cpSrc)
{
    return v_strcat(mpBuf, mszBufSize, cpSrc);
}
// End of function operator+(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     :
// Return    : void
// Parameter : const tChar * cpSrc
void CStrPtr::operator=(const tChar* cpSrc)
{
    size_t lsztRet = v_strcpy(mpBuf, mszBufSize, cpSrc);
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator<(...)
// Brief     :
// Return    : bool
// Parameter : const tChar * cpSrc
bool CStrPtr::operator<(const tChar* cpSrc)
{
    return v_strcmp_less(mpBuf, cpSrc);
}
// End of function operator<(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator>(...)
// Brief     :
// Return    : bool
// Parameter : const tChar * cpSrc
bool CStrPtr::operator>(const tChar* cpSrc)
{
    return v_strcmp_more(mpBuf, cpSrc);
}
// End of function operator>(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator==(...)
// Brief     :
// Return    : bool
// Parameter : const tChar * cpSrc
bool CStrPtr::operator==(const tChar* cpSrc)
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
tChar* CStrPtr::operator [](const size_t csztBufOffset)
{
    return (mpBuf + csztBufOffset);
}
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator*(...)
// Brief     :
// Return    : tChar*
tChar* CStrPtr::operator*()
{
    return mpBuf;
}
// End of function operator*(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : c_str(...)
// Brief     :
// Return    : const tChar*
const tChar* CStrPtr::c_str()
{
    return mpBuf;
}
// End of function c_str(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : len(...)
// Brief     :
// Return    : size_t
size_t CStrPtr::len()
{
    return strlen(mpBuf);
}
// End of function len(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : size(...)
// Brief     :
// Return    : size_t
size_t CStrPtr::size()
{
    return mszBufSize;
}
// End of function size(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : At(...)
// Brief     :
// Return    : tChar*
// Parameter : const size_t csztBufOffset
tChar* CStrPtr::At(const size_t csztBufOffset)
{
    return (mpBuf + csztBufOffset);
}
// End of function At(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Cat(...)
// Brief     :
// Return    : tChar*
// Parameter : const tChar * cSrc
tChar* CStrPtr::Cat(const tChar* cSrc)
{
    return v_strcat(mpBuf, mszBufSize, cSrc);
}
// End of function Cat(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Cat(...)
// Brief     :
// Return    : tChar*
// Parameter : const tChar * cpSrc
// Parameter : const size_t csztSrcLen
tChar* CStrPtr::Cat(const tChar* cpSrc, const size_t csztSrcLen)
{
    return v_strncat(mpBuf, mszBufSize, cpSrc, csztSrcLen);
}
// End of function Cat(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Sub(...)
// Brief     :
// Return    : tChar*
// Parameter : const tChar * cpSubStr
tChar* CStrPtr::Sub(const tChar* const cpSubStr)
{
    return v_strstr(mpBuf, cpSubStr);
}
// End of function Sub(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Sub(...)
// Brief     :
// Return    : tChar*
// Parameter : const size_t csztBufOffset
// Parameter : const tChar * cpSubStr
tChar* CStrPtr::Sub(const size_t csztBufOffset, const tChar* const cpSubStr)
{
    tChar* lpPos = mpBuf + csztBufOffset;
    return v_strstr(lpPos, cpSubStr);
}
// End of function Sub(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : rFind(...)
// Brief     :
// Return    : tChar*
// Parameter : const size_t csztBufOffset
// Parameter : const tChar czFlag
tChar* CStrPtr::rFind(const size_t csztBufOffset, const int ciFlag)
{
    tChar* lpPos = mpBuf + csztBufOffset;
    return v_strrchr(lpPos, ciFlag);
}
// End of function rFind(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : rFind(...)
// Brief     :
// Return    : tChar*
// Parameter : const tChar czFlag
tChar* CStrPtr::rFind(const int ciFlag)
{
    return v_strrchr(mpBuf, ciFlag);
}
// End of function rFind(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     :
// Return    : tChar*
// Parameter : const size_t csztBufOffset
// Parameter : const tChar czFlag
tChar* CStrPtr::Find(const size_t csztBufOffset, const int ciFlag)
{
    tChar* lpPos = mpBuf + csztBufOffset;
    return v_strchr(lpPos, ciFlag);
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Find(...)
// Brief     :
// Return    : tChar*
// Parameter : const tChar czFlag
tChar* CStrPtr::Find(const int ciFlag)
{
    return v_strchr(mpBuf, ciFlag);
}
// End of function Find(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm(...)
// Brief     :
// Return    : void
// Parameter : const tChar * cpSrc
size_t CStrPtr::CopyFm(const tChar* cpSrc)
{
    return v_strcpy(mpBuf, mszBufSize, cpSrc);
}
// End of function CopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm(...)
// Brief     :
// Return    : void
// Parameter : const size_t csztBufOffset
// Parameter : const tChar * cpSrc
size_t CStrPtr::CopyFm(const size_t csztBufOffset, const tChar* cpSrc)
{
    tChar* lpPos = mpBuf + csztBufOffset;
    return v_strcpy(lpPos, mszBufSize, cpSrc);
}
// End of function CopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm(...)
// Brief     :
// Return    : void
// Parameter : const tChar * cpSrc
// Parameter : const size_t csztSrcLen
size_t CStrPtr::CopyFm(const tChar* cpSrc, const size_t csztSrcLen)
{
    return v_strncpy(mpBuf, mszBufSize, cpSrc, csztSrcLen);
}
// End of function CopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyFm(...)
// Brief     :
// Return    : void
// Parameter : const size_t csztBufOffset
// Parameter : const tChar * cpSrc
// Parameter : const size_t csztSrcLen
size_t CStrPtr::CopyFm(const size_t csztBufOffset, const tChar* cpSrc, const size_t csztSrcLen)
{
    tChar* lpPos = mpBuf + csztBufOffset;
    return v_strncpy(lpPos, mszBufSize, cpSrc, csztSrcLen);
}
// End of function CopyFm(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     :
// Return    : void
// Parameter : tChar * pDst
size_t CStrPtr::CopyTo(tChar* pDst)
{
    return v_strcpy(pDst, mszBufSize, mpBuf);
}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     :
// Return    : void
// Parameter : const size_t csztBufOffset
// Parameter : tChar * pDst
size_t CStrPtr::CopyTo(const size_t csztBufOffset, tChar* pDst)
{
    tChar* lpPos = mpBuf + csztBufOffset;
    return v_strcpy(pDst, mszBufSize, lpPos);
}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     :
// Return    : void
// Parameter : tChar * pDst
// Parameter : const size_t csztDstSize
// Parameter : const size_t csztDataLen
size_t CStrPtr::CopyTo(tChar* pDst, const size_t csztDstSize, const size_t csztDataLen)
{
    return v_strncpy(pDst, csztDstSize, mpBuf, csztDataLen);
}
// End of function CopyTo(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CopyTo(...)
// Brief     :
// Return    : void
// Parameter : const size_t csztBufOffset
// Parameter : tChar * pDst
// Parameter : const size_t csztDstSize
// Parameter : const size_t csztDataLen
size_t CStrPtr::CopyTo(const size_t csztBufOffset, tChar* pDst, const size_t csztDstSize, const size_t csztDataLen)
{
    tChar* lpPos = mpBuf + csztBufOffset;
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
#endif // __CSTRPTR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CStrPtr.h
/////////////////////////////////////////////////////////////////////////////////////////