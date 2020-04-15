/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinKernal.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/12 17:14:46
// Modify time  : 2020/01/12 17:14:46
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

#ifndef __CWINKERNAL_H__
#define __CWINKERNAL_H__

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
#include <vmTools/vmUtil.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinKernal : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinKernal
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
public:
typedef enum emRet
{
    vSucceed    = 0,
    vUnknown    = -1,
    vTimeout    = -2,

    vIsInvalied = -10,
    vIsExisted  = -20,

    vError      = vMinsInt,
    vlError     = vMinsLong,
    vulError    = vMaxuLong
}*PRET;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinKernal():mhHandle(INVALID_HANDLE_VALUE)
    {
        vMemZero(mstSecurityAttributes);
        mstSecurityAttributes.nLength = sizeof(mstSecurityAttributes);
        mstSecurityAttributes.bInheritHandle = false;
        mstSecurityAttributes.lpSecurityDescriptor = nullptr;
    };
    // Destruct define
    virtual ~CWinKernal()
    {
        if ( CheckHandle()==emRet::vSucceed )
            CloseHandle(mhHandle);
    };
    
private:
    // No Copy
    CWinKernal(const CWinKernal& obj){};
    // No Assignment
    CWinKernal& operator = ( const CWinKernal& obj ){};

public:
    void* operator *(){ return mhHandle; }
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
protected:
    HANDLE  mhHandle;
    SECURITY_ATTRIBUTES mstSecurityAttributes;

public:
    HANDLE Handle(){ return mhHandle; };

/////////////////////////////////////////////////////////////////////////////////////////
public:
    void SetSecurityAttriibutes( const bool bInheritHandle,void* const lpSecurityDescriptor=nullptr)
    {
        mstSecurityAttributes.bInheritHandle        = bInheritHandle;
        mstSecurityAttributes.lpSecurityDescriptor  = lpSecurityDescriptor;
    }
    long CheckHandle()
    {
        if ( mhHandle == INVALID_HANDLE_VALUE )
            return emRet::vIsInvalied;

        if ( mhHandle != NULL )
            return emRet::vSucceed;

        mulErrCode = GetLastError();

        if ( mulErrCode == ERROR_ALREADY_EXISTS )
            return emRet::vIsExisted;

        return emRet::vUnknown; 
    }

public:
    unsigned long mulErrCode;

public:
    unsigned long toErrCode(){ return mulErrCode; }
    bool HasError(){ return mulErrCode != 0 ? true:false; }

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    long SetHandleInfo( DWORD dwMask, DWORD dwFlags )
    {
        BOOL lbRet = ::SetHandleInformation( mhHandle, dwMask, dwFlags );
        if ( lbRet == TRUE )
            return emRet::vSucceed;

        mulErrCode = GetLastError();
        return emRet::vlError;
    }

    unsigned long GetHandleInfo()
    {
        DWORD ldwFlags = 0;
        BOOL lbRet = ::GetHandleInformation( mhHandle, &ldwFlags );
        if ( lbRet == TRUE )
            return ldwFlags;

        mulErrCode = GetLastError();
        return emRet::vulError;
    }
   
    long DuplicateFm( HANDLE hSrcProcHandle, HANDLE hSrcObjHandle, DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions )
    {
        HANDLE lhCurrProc = ::GetCurrentProcess();
        long llRetForGetCurrProc = CheckHandle();
        if ( CheckHandle() != emRet::vSucceed )
            return llRetForGetCurrProc;
        
        BOOL lbRet =  ::DuplicateHandle( hSrcProcHandle, hSrcObjHandle, lhCurrProc, &mhHandle, 
                                         dwDesiredAccess, bInheritHandle, dwOptions );
        if ( lbRet == TRUE )
            return emRet::vSucceed;
        
        mulErrCode = GetLastError();
        return emRet::vlError;
    }

}; // End of class CWinKernal
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINKERNAL_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinKernal.h
/////////////////////////////////////////////////////////////////////////////////////////