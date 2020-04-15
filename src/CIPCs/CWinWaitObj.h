/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinWaitObj.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/11 09:13:11
// Modify time  : 2020/01/11 09:13:11
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

#ifndef __CWINWAITOBJ_H__
#define __CWINWAITOBJ_H__

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

////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :
#ifndef    _V_INFINITE_
#   define _V_INFINITE_ 0xFFFFFFFF
#endif  // _V_INFINITE_

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinObj : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinWaitObj
{
/////////////////////////////////////////////////////////////////////////////////////////
// Type defines :
public:
    typedef void(*vpfWaitTimeout)(void* const hHandle, const void* const arg );
    typedef void(*vpfWaitError)  (void* const hHandle, const unsigned long culErrCode, const void* const arg );
    typedef void(*vpfWaitAction) (void* const hHandle, const void* const arg );

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
    explicit CWinWaitObj():mpDoAction(nullptr),mpDoTimeout(nullptr),mpDoError(nullptr)
    {};
    // Destruct define
    virtual ~CWinWaitObj()
    {
        mpDoAction  = nullptr;
        mpDoTimeout = nullptr;
        mpDoError   = nullptr;
    };
    
private:
    // No Copy
    CWinWaitObj(const CWinWaitObj& obj):mpDoAction(obj.mpDoAction),mpDoTimeout(obj.mpDoTimeout),mpDoError(obj.mpDoError){};
    // No Assignment
    CWinWaitObj& operator = ( const CWinWaitObj& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    vpfWaitAction  mpDoAction;
    vpfWaitTimeout mpDoTimeout;
    vpfWaitError   mpDoError;

public:
    unsigned long mulErrCode;

public:
    unsigned long toErrCode() { return mulErrCode; }
    bool HasError() { return mulErrCode != 0 ? true : false; }

public:
    void SetDoAction(vpfWaitAction pDoAction){ mpDoAction = pDoAction; }
    void SetDoTimeout(vpfWaitTimeout pDoTimeout) { mpDoTimeout = pDoTimeout; }
    void SetDoError(vpfWaitError pDoError) { mpDoError = pDoError; }

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    long Wait( void* const          hHandle,
               const unsigned long  ulTimeout   = _V_INFINITE_,
               const void* const    argAction   = nullptr,
               const void* const    argTimeout  = nullptr,
               const void* const    argError    = nullptr )
    {
        DWORD result = ::WaitForSingleObject( (HANDLE)hHandle, ulTimeout);
        
        if (result == WAIT_OBJECT_0)
        {
            if (mpDoAction!= nullptr)
                mpDoAction(hHandle, argAction);

            return emRet::vSucceed;
        }
        else if (result == WAIT_TIMEOUT)
        {
            if (mpDoTimeout != nullptr)
                mpDoTimeout(hHandle, argTimeout);

            return emRet::vTimeout;

        } // end of else if
        else
        {
            mulErrCode = GetLastError();

            if (mpDoError != nullptr)
                mpDoError(hHandle , mulErrCode, argError);

            return emRet::vlError;
        } // end of if
    
        return emRet::vUnknown;
    }

}; // End of class CWinObj
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINWAITOBJ_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinWaitObj.h
/////////////////////////////////////////////////////////////////////////////////////////