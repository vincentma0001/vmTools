/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinWaitObjs.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/11 09:46:36
// Modify time  : 2020/01/11 09:46:36
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

#ifndef __CWINWAITOBJS_H__
#define __CWINWAITOBJS_H__

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
#include <vmLibBase/vmUtil.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :
#ifndef    _V_INFINITE_
#   define _V_INFINITE_ 0xFFFFFFFF
#endif  // _V_INFINITE_

// Macro defines :
#define _V_MAX_WAIT_OBJS_ 1024

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinObjs : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinWaitObjs 
{
/////////////////////////////////////////////////////////////////////////////////////////
// Type defines :
public:
    typedef void(*vpfWaitTimeout)( const void* const arg );
    typedef void(*vpfWaitError)  ( unsigned long ulErrCode, const void* const arg );
    typedef void(*vpfWaitAction) ( void* const   hHandle,   const void* const arg );

public:
    typedef enum emRet
    {
        vSucceed = 0,
        vUnknown = -1,
        vTimeout = -2,

        vIsInvalied = -10,
        vIsExisted = -20,

        vError = vMinsInt,
        vlError = vMinsLong,
        vulError = vMaxuLong
    }*PRET;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinWaitObjs( ):mhHandles{0},mpActions{0},mpDoTimeout(nullptr), mpDoError(nullptr){};
    // Destruct define
    virtual ~CWinWaitObjs()
    {
    
        mpDoTimeout= nullptr;
        mpDoError = nullptr;
    };
    
private:
    // No Copy
    CWinWaitObjs(const CWinWaitObjs& obj){};
    // No Assignment
    CWinWaitObjs& operator = ( const CWinWaitObjs& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    void*           mhHandles[_V_MAX_WAIT_OBJS_];
    vpfWaitAction   mpActions[_V_MAX_WAIT_OBJS_];
    unsigned long   mulCount;
    
    vpfWaitTimeout  mpDoTimeout;
    vpfWaitError    mpDoError;

public:
    unsigned long mulErrCode;

public:
    unsigned long toErrCode() { return mulErrCode; }
    bool HasError() { return mulErrCode != 0 ? true : false; }


public:
    void*         Handle( const unsigned int cuiPos ){ return mhHandles[cuiPos]; }
    vpfWaitAction Action( const unsigned int cuiPos ){ return mpActions[cuiPos]; }

public:
    void SetDoTimeout( vpfWaitTimeout pDoTimeout ) { mpDoTimeout = pDoTimeout; }
    void SetDoError( vpfWaitError pDoError ){ mpDoError = pDoError; }

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    bool Add( void* const hHandle, const vpfWaitAction pAction = nullptr )
    {
        if ( mulCount >= _V_MAX_WAIT_OBJS_ )
            return false;

        mhHandles[mulCount] = hHandle;
        mpActions[mulCount] = pAction;
        
        mulCount ++;

        return true;
    }

    long Wait( const bool  bWaitAll   = true, 
               const bool  bAlertable = true, 
               const unsigned long ulTimeout = _V_INFINITE_,
               const void* const argAction  = nullptr, 
               const void* const argTimeout = nullptr, 
               const void* const argError   = nullptr )
    {
        DWORD ldwRet = WaitForMultipleObjectsEx(mulCount, mhHandles, bWaitAll, ulTimeout, bAlertable);
        if (ldwRet == WAIT_TIMEOUT)
        {
            if ( mpDoTimeout != nullptr )
                mpDoTimeout( argTimeout );

            return emRet::vTimeout;
        }
        if (ldwRet == WAIT_FAILED)
        {
            mulErrCode = GetLastError();

            if ( mpDoError != nullptr )
                mpDoError( mulErrCode, argError );

            return emRet::vlError;
        }
        for (DWORD i = 0; i < mulCount; i++)
        {
            if ((WAIT_OBJECT_0 + i) == ldwRet)
            {
                HANDLE lhHandle         = mhHandles[ldwRet];
                vpfWaitAction lpAction  = mpActions[ldwRet];
                if ( lpAction != nullptr )
                    lpAction( lhHandle, argAction );

                return ldwRet;
            }
        }

        return emRet::vUnknown;

    }

}; // End of class CWinWaitObjs
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINWAITOBJS_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinWaitObjs.h
/////////////////////////////////////////////////////////////////////////////////////////