/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CExp.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2019/12/30 21:55:32
// Modify time  : 2019/12/30 21:55:32
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

#ifndef __CEXP_H__
#define __CEXP_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file

#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>_
#endif // __VM_CFG_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define

#ifndef     _VM_CEXP_TIMEFMT_
#   define  _VM_CEXP_TIMEFMT_ "%Y/%m/%d %H:%M:%S.%Mill"
#endif // ! _VM_CEXP_TIMEFMT_

/////////////////////////////////////////////////////////////////////////////////////////
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
//---------------------------------------------------------------------------------------

#   define _V_CEXP_MAX_FUNC_ _MAX_FNAME
#   define _V_CEXP_MAX_FILE_ _MAX_FNAME
#   define _V_CEXP_MAX_MSG_  1024
#   define _V_CEXP_MAX_BUF_  2048
#   define _V_CEXP_TIME_BUF_ 128

//---------------------------------------------------------------------------------------
#else // ! #if defined (_V_PLATFORM)...
//---------------------------------------------------------------------------------------

#   define _V_CEXP_MAX_FUNC_ 256
#   define _V_CEXP_MAX_FILE_ 256
#   define _V_CEXP_MAX_MSG_  1024
#   define _V_CEXP_MAX_BUF_  2048
#   define _V_CEXP_TIME_BUF_ 128

//---------------------------------------------------------------------------------------
#endif // #if defined (_V_PLATFORM)...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CExp : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CExp
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedef :
typedef enum emExpLevel
{
    emExp = 1,
    emWrn = 2
} EMEXPLEVEL;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CExp();
    explicit CExp( const tchar* const      cpFile,
                   const unsigned long    culLine,
                   const tchar* const   cpTimeFmt);
    explicit CExp( const CExp&               oExp,
                   const tchar* const      cpFile, 
                   const unsigned long    culLine,
                   const tchar* const   cpTimeFmt);
    // Destruct define
    virtual ~CExp();
    
public:
    // Copy construct define
    CExp(const CExp& obj);
    // Assignment define
    CExp& operator = ( const CExp& obj );

public:
    // ()操作
    CExp& operator()(const tchar* const cpFunc,
                     const tchar* const cpFmt , ...);
    CExp& operator()(const tchar* const cpFunc,
                     const tchar* const cpFmt , va_list vList);
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
protected:
    // where
    // 异常发生时所在的函数名
    tchar   mszFunc[_V_CEXP_MAX_FUNC_];
    // 异常发生时所在的文件名
    tchar   mszFile[_V_CEXP_MAX_FILE_];
    // 异常发生时说咋的文件行数
    unsigned int    muiLine;

    // when
    // 异常发生的时间
    tchar   mszDateTime[_V_CEXP_TIME_BUF_];
    
    // what
    // 异常信息
    tchar   mszMsg[_V_CEXP_MAX_MSG_];

    // format msg buffer
    // 格式化缓存
    tchar   mszBuf[_V_CEXP_MAX_BUF_];

private:
    // 异常等级
    emExpLevel                   mExpLevel;
    // 上一级异常信息
    CExp*                        mpExpNext;
    
/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 格式化输出异常信息
    // FMT : %M(Method)                      - 函数名
    //       %F(File)                        - 文件名
    //       %L(Line)                        - 文件函数
    //       %N(Notification)                - 异常信息
    //       %T(Time)                        - 异常触发的时间
    tchar* Fmt( const tchar* const cpFmt );

public:
    // 获取下上一级异常信息
    CExp* Next();

}; // End of class CExp
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CEXP_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CExp.h
/////////////////////////////////////////////////////////////////////////////////////////