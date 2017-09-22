/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CLog.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 10/1/2016 13:25:51
// Modify time 	: 10/1/2016 13:25:51
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <windows.h>

#include "CLog.h"
#include <Comm/CException.h>
#include <Comm/VerifyDef.h>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#ifndef NULL
#   define NULL 0
#endif // End of #ifndef NULL

#ifndef __FUNCTION__
#   define __FUNCTION__ "func"
#endif // End of #ifndef __FUNCTION__


CWinCS CSingleton<CLog,CWinCS>::mtMutex;		            // 锁，要考虑多线程，多核计算机同步问题
CLog*	CSingleton<CLog,CWinCS>::mptInstance=NULL;			// 实例对象

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Output
// Full name : CLog::Output
// Access    : public 
// Brief     : 
// Parameter : const char* szOutput
// Return    : void
// Notes     : 
void CLog::Output(const char* szOutput)
{
    try{
        _VERIFY_2_(szOutput, mcAbsLogImp);

        mcAbsLogImp->Output(szOutput);
    }catch( CException& ex ){	
        throw ex;
    }catch( ... ){
        throw CEXP("Get an unknown exception！");
    }
} // End of function Output(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetLogBase
// Full name : CLog::SetLogBase
// Access    : public 
// Brief     : 
// Parameter : CAbsLogImp* ccLogImp
// Return    : void
// Notes     : 
void CLog::SetLogBase(CAbsLogImp* ccLogImp)
{
    try{
        _VERIFY_( ccLogImp );

        if (mcAbsLogImp != NULL)
        {
            delete mcAbsLogImp;
            mcAbsLogImp = NULL;
        } // End of if
        mcAbsLogImp = ccLogImp->clone();

    }catch( CException& ex ){
        throw ex;
    }catch( ... ){
        throw CEXP("Get an unknown exception!");
    }
} // End of function SetLogBase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CLog
// Full name : CLog::~CLog
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CLog::~CLog()
{
    try{
        if (mcAbsLogImp != NULL)
        {
            delete mcAbsLogImp;
        } // End of if mcAbsLogImp!=NULL
    }catch( CException& ex ){
        throw ex;
    }catch( ... ){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ~CLog(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CLog.cpp...
/////////////////////////////////////////////////////////////////////////////////////////