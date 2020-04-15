/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinThrd.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/11 09:11:08
// Modify time  : 2020/01/11 09:11:08
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

#ifndef __CWINTHRD_H__
#define __CWINTHRD_H__

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
#include <vmLibIPC/CWinWaitObjs.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinThrd : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinThrd
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
public:
    typedef unsigned long (*vpfAction)     ( void* arg );
    typedef void  (*vpfWaitAction) ( void* const hHandle, const void* const arg );

public:
    typedef enum  emRet
    {
        vSucceed       = 0,
        vUnknown       = -1,
        vInvalidHandle = -2,
        
        vError         = vMinsInt,
        vErrExit       = vMaxuLong
    }*PEMRET;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinThrd(vpfAction pAction):mpAction(pAction),mhHandle(0),mulThrdId(0),mulErrCode(0){};
    // Destruct define
    virtual ~CWinThrd()
    {
        if ( mhHandle != INVALID_HANDLE_VALUE )
            ::CloseHandle( mhHandle );
    };
    
private:
    // No Copy
    CWinThrd(const CWinThrd& obj){};
    // No Assignment
    CWinThrd& operator = ( const CWinThrd& obj ){};
    
public:
    CWinThrd& operator = (vpfAction pAction) { mpAction = pAction; };
    HANDLE operator*(){ return mhHandle; }

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    void*           mhHandle;
    unsigned long   mulThrdId;
    vpfAction       mpAction;

    static vm::CWinWaitObjs goWaitObjs;

public:
    void SetAction( vpfAction pAction ){ mpAction=pAction; }
    unsigned long GetId(){ return mulThrdId; }

public:
    unsigned long   mulErrCode;

    bool  HasError(){ if ( mulErrCode != 0 ) return true; return false; }
    unsigned long toErrCode() { return mulErrCode; };

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 创建新线程
    int Create( void* arg=nullptr, unsigned long dwCreationFlags = 0 /*CREATE_SUSPENDED*/)
    {  
        // 判断当前句柄是否有效
        if ( mhHandle != INVALID_HANDLE_VALUE )
            return emRet::vInvalidHandle;
        
        // 创建新线程
        mhHandle = ::CreateThread(NULL,
                                  0,
                                  (LPTHREAD_START_ROUTINE)mpAction,
                                  arg,
                                  dwCreationFlags,
                                  &mulThrdId);

        // 检验创建结果
        if ( mhHandle == INVALID_HANDLE_VALUE )
        {
            mulErrCode = GetLastError();
            return emRet::vError;
        }

        // 暂停线程运行
        int liRet = Suspend();
        if ( liRet != emRet::vSucceed )
            return liRet;
        
        return emRet::vSucceed;
    }

    // 阻塞方式等待线程结束
    bool Join( vpfWaitAction* const pAction = nullptr )
    {
        bool lbRet = goWaitObjs.Add( mhHandle, (vm::CWinWaitObjs::vpfWaitAction)pAction );
        if ( lbRet != true ) 
            return false;
       
        bool lbRetForResume = Resume();
        if ( lbRetForResume != true )
            return false;

        return true;
    }

    // 非柱塞方式等待线程
    bool Detach()
    {
        return Resume();
    }

    // 回复
    bool Resume()
    {
        DWORD ldwRet = ::ResumeThread( mhHandle );
        if ( ldwRet == -1)
        {
            mulErrCode = GetLastError();
            return false;
        }

        return true;
    }
    // 挂起
    int Suspend(  )
    {
        if ( mhHandle == INVALID_HANDLE_VALUE )
            return emRet::vInvalidHandle;

        DWORD ldwRet = ::SuspendThread( mhHandle );
        if ( ldwRet == -1 )
        {
            mulErrCode = GetLastError();
            return emRet::vError;
        }

        return emRet::vSucceed;
    }

    // 标准退出
    void Exit( const unsigned long culExitCode )
    {
        ::ExitThread( culExitCode );
    }
    // 强制终止
    bool Terminate( const unsigned long culExitCode )
    {  
        return ::TerminateThread( mhHandle, culExitCode )==TRUE?true:false;
    }

    unsigned long GetExitCode()
    {
        DWORD ldwExitCode = 0;
        BOOL lbRet = ::GetExitCodeThread(mhHandle,&ldwExitCode );
        if ( lbRet != true )
        {
            mulErrCode = GetLastError();
            return emRet::vErrExit;
        }
        return ldwExitCode;
    }

    static int Wait(const bool  bWaitAll = true,
                    const bool  bAlertable = true,
                    const unsigned long ulTimeout = _V_INFINITE_,
                    const void* const   argAction  = nullptr,
                    const void* const   argTimeout = nullptr,
                    const void* const   argError   = nullptr)
    {
        return goWaitObjs.Wait(bWaitAll, bAlertable, ulTimeout, argAction, argTimeout, argError);
    }

    static bool Terminate(void* const hHandle, const unsigned long culExitCode)
    {
        return ::TerminateThread(hHandle, culExitCode) == TRUE ? true : false;
    }

    static unsigned long GetThrdId( void* hHandle )
    {
        return ::GetThreadId( hHandle );
    }
    
    static void* GetCurrThrdHandle()
    {
        return ::GetCurrentThread();
    }

    static unsigned long GetCurrThrdId()
    {
        return ::GetCurrentThreadId();
    };

    //GetPriority
    //SetPriority

    // CreateRemoteThread
    // PostThreadMessage

}; // End of class CWinThrd
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINTHRD_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinThrd.h
/////////////////////////////////////////////////////////////////////////////////////////