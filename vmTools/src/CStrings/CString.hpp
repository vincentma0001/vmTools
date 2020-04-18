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

// Platform files included

// Used files included
#ifndef   __VM_UTIL_H__
#   include <vmTools/vmUtil.h>
#endif // __VM_UTIL_H__

#ifndef   __CSTRPTR_H__
#   include <vmTools/CStringPtr.h>
#endif // __CSTRPTR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CString : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template <size_t sztBufSize>
class DLL_API CString : public CStringPtr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    CString():CStringPtr(mszBuf,sztBufSize),mszBuf{0x00}
    {
        // Test for mszBuf address
        // printf("mszBuf(%p)\n", &mszBuf);
    };
    CString(const tchar* const cpStr):CStringPtr(mszBuf, sztBufSize),mszBuf{0x00}{ v_strcpy(mszBuf, sizeof(mszBuf), cpStr); };
    // Destruct define
    virtual ~CString(){};
    
public:
    // Copy construct define
    CString(const CString<sztBufSize>& obj)
    { *this = obj; };
    // Assignment define
    CString& operator = ( const CString<sztBufSize>& obj )
    { v_memcpy(mszBuf, sizeof(mszBuf), obj.mszBuf, sizeof(obj.mszBuf)); return *this; };

/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
    tchar   mszBuf[sztBufSize];

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