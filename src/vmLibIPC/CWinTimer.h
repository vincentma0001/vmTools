/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinTimer.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/11 20:38:49
// Modify time  : 2020/01/11 20:38:49
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

#ifndef __CWINTIMER_H__
#define __CWINTIMER_H__

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
// class CWinTimer : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinTimer : public CWinKernal
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
typedef void (*vpfTimeRapcRoutine) ( void* lpArgToCompletionRoutine, unsigned long dwTimerLowValue, unsigned long dwTimerHighValue );

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinTimer(){};
    // Destruct define
    virtual ~CWinTimer(){};
    
private:
    // No Copy
    CWinTimer(const CWinTimer& obj){};
    // No Assignment
    CWinTimer& operator = ( const CWinTimer& obj ){};
    
public:
    CWinTimer& operator = (vpfTimeRapcRoutine pCallBack){ mpCallBack=pCallBack; return *this; }

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    vpfTimeRapcRoutine mpCallBack;

public:
    void SetCallBack( vpfTimeRapcRoutine pCallBack ){ mpCallBack = pCallBack; }

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    long Create( const tChar* const cpName, bool bManualReset )
    {
        mhHandle = ::CreateWaitableTimer( &mstSecurityAttributes, bManualReset, cpName );
        return CheckHandle();
    }

    long Open( const tChar* const cpName, const unsigned long cdwDesiredAccess, const bool cbInheritHandle )
    {
        mhHandle = ::OpenWaitableTimer(cdwDesiredAccess, cbInheritHandle, cpName );
        return CheckHandle();
    }

    bool SetTimer( const unsigned long culDueTime, const long clPeriod, const bool cbResume = true,  const void* const cpArg = nullptr )
    {
        LARGE_INTEGER lIntger;
        lIntger.QuadPart = culDueTime*(-10000);
        BOOL lbRet = ::SetWaitableTimer(mhHandle, &lIntger, clPeriod, (PTIMERAPCROUTINE)mpCallBack, (LPVOID)cpArg, cbResume );
        if ( lbRet == TRUE )
            return true;

        mulErrCode = GetLastError();
        return false;
    }

    bool Cancel()
    {
        BOOL lbRet = ::CancelWaitableTimer( mhHandle );
        if ( lbRet == TRUE )
            return true;
    
        mulErrCode = GetLastError();
        return false;
    }

}; // End of class CWinTimer
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINTIMER_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinTimer.h
/////////////////////////////////////////////////////////////////////////////////////////