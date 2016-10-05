/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: Log.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 10/1/2016 12:55:52
// Modify time 	: 10/1/2016 12:55:52
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
#include <stdarg.h>
#include "Log.h"
#include <Comm/VerifyDef.h>
#include <Comm/CFile.h>
#include <Comm/CException.h>
#include "CLog.h"


/////////////////////////////////////////////////////////////////////////////////////////
// macro define :
#define LOG_MAX_BUF 2048
#define LOG_FORMAT  "[%s:%d] %s [%s]"

/////////////////////////////////////////////////////////////////////////////////////////
// Gloab value :
unsigned long gulLogFlag = LOGFLAG_ALL;

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Log
// Full name : Log
// Access    : public 
// Brief     : 
// Parameter : const char* cszFormat,const char* cszFunc, const unsigned long culLine, const char* cszFile, ...
// Return    : void
// Notes     : 
void Log(const char* cszFormat, const char* cszFunc, const unsigned long culLine, const char* cszFile, ...)
{
    _VERIFY_3_(cszFormat, cszFunc, cszFile);
    try{
        // 获取日志信息
        char szBuf[LOG_MAX_BUF] = { 0 };
        va_list vp;
        va_start(vp, cszFile);
        vsprintf_s(szBuf, LOG_MAX_BUF,cszFormat,vp);
        va_end(vp);

        // 分解文件名
        CFile loFile(cszFile);

        // 格式化日志信息
        char szBuf2[LOG_MAX_BUF] = { 0 };
        sprintf_s(szBuf2, LOG_MAX_BUF, LOG_FORMAT, cszFunc, culLine, szBuf, loFile.mstrFileBase.c_str());

        // 获取日志对象
        CLog* lpLog = CSingleton< CLog, CWinCS >::Instance();
        _VERIFY_(lpLog);

        // 输出日志信息
        lpLog->Output(szBuf2);
    }
    catch (CException& ex){
        throw ex;
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function Log(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Log_show
// Full name : Log_show
// Access    : public 
// Brief     : 
// Parameter : const char* cszFormat, ...
// Return    : void
// Notes     : 
void Log_show(const char* cszFormat, ...)
{
    _VERIFY_(cszFormat);
    try{
        // 获取日志信息
        char szBuf[LOG_MAX_BUF] = { 0 };
        va_list vp;
        va_start(vp, cszFormat);
        vsprintf_s(szBuf, LOG_MAX_BUF, cszFormat, vp);
        va_end(vp);

        // 获取日志对象
        CLog* lpLog = CSingleton< CLog, CWinCS >::Instance();
        _VERIFY_(lpLog);

        // 输出日志信息
        lpLog->Output(szBuf);
    }
    catch (CException& ex){
        throw ex;
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }

} // End of function Log_show(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetLogFlag
// Full name : SetLogFlag
// Access    : public 
// Brief     : 
// Parameter : const unsigned long culLogFlag
// Return    : void
// Notes     : 
void SetLogFlag(const unsigned long culLogFlag)
{
    gulLogFlag = culLogFlag;
} // End of function SetLogFlag(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetLogBase
// Full name : SetLogBase
// Access    : public 
// Brief     : 
// Parameter : CAbsLogImp* pLogImp
// Return    : void
// Notes     : 
void SetLogBase(CAbsLogImp& oLogImp)
{
    CLog* lpLog = CSingleton< CLog, CWinCS >::Instance();
    _VERIFY_(lpLog);

    lpLog->SetLogBase(&oLogImp);
} // End of function SetLogBase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file Log.cpp...
/////////////////////////////////////////////////////////////////////////////////////////