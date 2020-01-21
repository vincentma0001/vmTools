/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CLog.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/05 15:43:27
// Modify time  : 2020/01/05 15:43:27
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

#ifndef __CLOG_H__
#define __CLOG_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included
#include <vmStdcUtil.h>

#include <vmLibBase/CBit08.h>
#include <vmLibBase/CStringPtr.h>
#include "CLogImp.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{
/////////////////////////////////////////////////////////////////////////////////////////

#define _V_CLOG_MAX_TIME_ 128
#define _V_CLOG_MAX_TYPE_ 4
#define _V_CLOG_MAX_MSG_ 20480

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CLog : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CLog
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
typedef enum emLogFlag
{
    DBG = 0x01,
    INF = 0x02,
    WRN = 0x04,
    ERR = 0x08,
} EMLF, *PEMFL;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CLog():mpLogImp(nullptr){};
    // Destruct define
    virtual ~CLog()
    {
        if ( mpLogImp!=nullptr)
        {   delete [] mpLogImp;
        }
    };
    
private:
    // No Copy
    CLog(const CLog& obj){};
    // No Assignment
    CLog& operator = ( const CLog& obj ){};

public:
    void WriteLine( const tchar* const cpFmt, va_list vList )
    {
        if ( mpLogImp == nullptr )
            return;

        mpLogImp->WriteLine(cpFmt,vList);
    }
    void WriteLine( const tchar* const cpFmt, ... )
    {
        if ( mpLogImp == nullptr )
            return;
        vm::CString<_V_CLOG_MAX_MSG_> lszMsg();
        lszMsg().Fmt2(cpFmt,vList);

        va_list vList;
        va_start(vList,cpFmt);
        mpLogImp->WriteLine(cpFmt,vList);
        va_end(vList);
    }
    
    void MakeMsg(const tchar* const cpFmt, va_list vList)
    {
        
    }
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tchar    mcLogFlag;

    CLogImp* mpLogImp;
    
    tchar  mszDateTime[_V_CLOG_MAX_TIME_];
    tchar  mszLogType[_V_CLOG_MAX_TYPE_];

    tchar  mszDateTimeFmt[_V_CLOG_MAX_TIME_];
    tchar  mszLogFmt[]

    tchar  mszLogMsg[]
    
/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    void AddImp( CLogImp& coImp )
    {
        if ( mpLogImp==nullptr )
        {
            mpLogImp = &coImp;
        }
        else
        {
            mpLogImp->AddImp(coImp);
        }        
    }
    
    void SetDateTimeFmt( const tchar* const cpTimeFmt )
    {
        vCStrPtr(mszDateTimeFmt) = cpTimeFmt;
    }

    // %D -- log 产生时间
    // %T -- log 类型
    // %M -- log 内容
    void SetLogFmt(const tchar* const cpLogFmt )
    {
        vCStrPtr(mszLogFmt) = cpLogFmt;
    }

    void unSet( emLogFlag emFlag )
    {
        vm::CBit8Ptr loBit(mcLogFlag);
        loBit.unSet( (tchar)emFlag );
    }
    void Set( emLogFlag emFlag )
    {
        vm::CBit8Ptr loBit(mcLogFlag);
        loBit.Set( (tchar)emFlag );
    }
    bool isSet( emLogFlag emFlag )
    {
        vm::CBit8Ptr loBit(mcLogFlag);
        return loBit.isSet( emFlag );
    }

}; // End of class CLog
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CLOG_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CLog.h
/////////////////////////////////////////////////////////////////////////////////////////