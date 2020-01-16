/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinSema.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/11 21:29:54
// Modify time  : 2020/01/11 21:29:54
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

#ifndef __CWINSEMA_H__
#define __CWINSEMA_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

// Platform files included
#include <windows.h>

// Used files included
#include <vmLibIPC/CWinKernal.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinSema : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinSema : public CWinKernal
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinSema(){};
    // Destruct define
    virtual ~CWinSema(){};
    
private:
    // No Copy
    CWinSema(const CWinSema& obj){};
    // No Assignment
    CWinSema& operator = ( const CWinSema& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    long Create( const vChar* const cpName, const long clInitialCount, const long clMaxmumCount, void* pSamephoneAttributes = nullptr )
    {
        mhHandle = ::CreateSemaphore( &mstSecurityAttributes,clInitialCount, clMaxmumCount, cpName );
        return CheckHandle();
    }

    long Open( const vChar* const cpName, const unsigned long culDesiredAccess, const bool cbInheritHandle = false )
    {
        mhHandle = ::OpenSemaphore( culDesiredAccess, cbInheritHandle, cpName );
        return CheckHandle();
    }
    
    long Release( const long clReleaseCount )
    {
        long llPreviousCount = 0;
        BOOL lbRet = ::ReleaseSemaphore( mhHandle, clReleaseCount, &llPreviousCount );
        if ( lbRet == true )
            return emRet::vSucceed;

        mulErrCode = ::GetLastError();
        return emRet::vlError;
    }

}; // End of class CWinSema
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINSEMA_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinSema.h
/////////////////////////////////////////////////////////////////////////////////////////