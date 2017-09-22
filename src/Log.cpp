/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: Log.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 9/3/2016 9:40:59
// Modify time 	: 9/3/2016 9:40:59
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "jlLogger.h"
#include "Log.h"
#include "Comm/VerifyDef.h"

char gcFileNameBuf[MAX_PATH] = {0};


jlLogger* gpJlLoger = new jlLogger;

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileBase
// Full name : GetFileBase
// Access    : public 
// Brief     : 
// Parameter : const char* cszFileName /*= __FILE__ */
// Return    : const char*
// Notes     : 
const char* GetFileBase(const char* cszFileName /*= __FILE__ */)
{
    try{
        memset( gcFileNameBuf, 0, MAX_PATH );
        const char *lp = strrchr(cszFileName, int('\\'));
        strcpy(gcFileNameBuf, lp+1);

        return gcFileNameBuf;
    }catch (...){
        throw std::logic_error("Get an unknown exception!");
        return NULL;
    }
} // End of function GetFileBase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CLog
// Full name : CLog::CLog
// Access    : public 
// Brief     : 
// Parameter : const char* cszFuncName, const long clLine/*=__LINE__*/, const char* cszFileName
// Return    : 
// Notes     : 
CLog::CLog(const char* cszFuncName, const long clLine/*=__LINE__*/, const char* cszFileName)
{
    _VERIFY_2_( cszFuncName, cszFileName );
    mstrFuncName            = cszFuncName;
    mlBegineLine            = clLine;

    msoAtom.CompareExchange( (_MAX_LOG_ACCOUNT_), 0 );
    mlAccount               = msoAtom.Add( 1 );

    gpJlLoger->TraceMessage( LOG_INF, "[%4d][%s:%d] ---------- %s BEGIN  ---------- ", 
        mlAccount, 
        mstrFuncName.c_str(), 
        mlBegineLine, 
        mstrFuncName.c_str() );
} // End of function CLog(...
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
    gpJlLoger->TraceMessage( LOG_INF, "[%4d][%s:%d] ---------- %s FINISH ---------- ", 
        mlAccount, 
        mstrFuncName.c_str(), 
        mlBegineLine, 
        mstrFuncName.c_str() );
} // End of function ~CLog(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Log
// Full name : CLog::Log
// Access    : public 
// Brief     : 
// Parameter : const char* cszMsg, const long clLine, ...
// Return    : void
// Notes     : 
void CLog::Log(const char* cszMsg, const long clLine, ...)
{
    _VERIFY_2_( cszMsg, cszFileName );

    // 获取日志信息
    char szBuf[LOG_MAX_BUF] = { 0 };
    va_list vp;
    va_start(vp, cszFileName);
    vsprintf(szBuf, cszMsg, vp);
    va_end(vp);

    gpJlLoger->TraceMessage( LOG_INF, "[%4d][%s:%d] %s [%s] :", mlAccount, mstrFuncName.c_str(), clLine, szBuf, mstrFileName.c_str() );
} // End of function Log(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file Log.cpp
/////////////////////////////////////////////////////////////////////////////////////////