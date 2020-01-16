/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CStdExp.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/02 17:59:57
// Modify time  : 2020/01/02 17:59:57
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

#ifndef __CSTDEXP_H__
#define __CSTDEXP_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#ifndef _EXCEPTION_
#	error this file need #include <exception>
#endif // _EXCEPTION_

#ifndef   __VM_CFG_DLL_H__
#	error this file need #include <vmCfgDll.h>
#endif // __VM_CFG_DLL_H__

#ifndef __CEXP_H__
#	error this file need #include <vmExpLib/CExp.h>
#endif // __CEXP_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CStdExp : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CStdExp : public CExp
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CStdExp( const std::exception& coExp,
                      const tChar* const     cpFile, 
                      const unsigned long   culLine,
                      const tChar* const     cpTimeFmt );
    // Destruct define
    virtual ~CStdExp();
    
public:
    // Copy construct define
    CStdExp(const CStdExp& obj);
    // Assignment define
    CStdExp& operator = ( const CStdExp& obj );
    

}; // End of class CStdExp
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSTDEXP_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CStdExp.h
/////////////////////////////////////////////////////////////////////////////////////////