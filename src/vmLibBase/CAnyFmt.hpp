/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CAnyFmt.hpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/20 22:35:37
// Modify time  : 2020/01/20 22:35:37
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

#ifndef __CANYFMT_HPP__
#define __CANYFMT_HPP__

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
// using namespace
namespace vm{
namespace vAny{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CAnyFmt : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template< size_t sztBufSize >
class CFmt
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :

#ifndef    _V_CFMT_MAX_BUF_
#   define _V_CFMT_MAX_BUF_ 256
#endif  // _V_CFMT_MAX_BUF_

#ifndef    vAnyFmt
#   define vAnyFmt(x) vm::vAny::CFmt<x>
#endif  // vAnyFmt

#ifndef    vAnyFmtD
#   define vAnyFmtD vm::vAny::CFmt<_V_CFMT_MAX_BUF_>
#endif  // vAnyFmtD

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CFmt(): mszBuf{ 0x00 }, msztOffset(0)
    {
        mszBuf[ msztOffset ] = vT('%');
        msztOffset += 1;
    };

    // Destruct define
    virtual ~CFmt(){};
    
private:
    // No Copy
    CFmt(const CFmt& obj){};
    // No Assignment
    CFmt& operator = ( const CFmt& obj ){};

public:
    tchar* operator*() { return mszBuf; }
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tchar  mszBuf[ sztBufSize ];
    size_t msztOffset;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    size_t len() { return msztOffset; };

public:
    CFmt& F(const tchar* const cpFlag)
    {
        v_strcat(mszBuf, cpFlag);
        msztOffset += vStrlen(cpFlag);

        return *this;
    };
    CFmt& W(const size_t csztWight)
    {
        tchar lszBuf[ 128 ] = { 0x00 };
        vItoa(csztWight, lszBuf, 10);

        v_strcat(mszBuf, lszBuf);
        msztOffset += vStrlen(lszBuf);

        return *this;
    };
    CFmt& W(const tchar* const cpWight)
    {
        v_strcat(mszBuf, cpWight);
        msztOffset += vStrlen(cpWight);

        return *this;
    };
    CFmt& P(const tchar* const cpPrec)
    {
        mszBuf[ msztOffset ] = vT('.');

        v_strcat(mszBuf, cpPrec);
        msztOffset += vStrlen(cpPrec);

        return *this;
    }
    CFmt& P(const size_t csztPrec)
    {
        mszBuf[ msztOffset ] = vT('.');

        tchar lszBuf[ 128 ] = { 0x00 };
        vItoa(csztPrec, lszBuf, 10);

        v_strcat(mszBuf, lszBuf);
        msztOffset += vStrlen(lszBuf);

        return *this;
    }
    CFmt& S(const tchar* const cpSpecifier)
    {
        v_strcat(mszBuf, cpSpecifier);
        msztOffset += vStrlen(cpSpecifier);
    }


}; // End of class CAnyFmt
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vAny
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CANYFMT_HPP__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CAnyFmt.hpp
/////////////////////////////////////////////////////////////////////////////////////////