/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CException.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 9/1/2016 20:26:06
// Modify time 	: 9/1/2016 20:26:06
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
#include <string.h>

#include "CException.h"
#include "VerifyDef.h"
#include "CFile.h"
#include "CValue.h"

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#define EX_MAX_BUF 2048

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

namespace vm {

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CException
// Full name : CException::CException
// Access    : public 
// Brief     : 构造函数
// Parameter :  const char* szFormat,                                       -- 异常信息格式
//              const char* szFunc,                                         -- 异常产生的函数名
//              const unsigned long culExpType /*= MAKEUSEREXP(ET_USER)*/,  -- 异常类型
//              const unsigned long culExpCode /*= MAKEUSEREXP(ET_USER)*/,  -- 异常代码
//              const unsigned long culLine /*= __LINE__*/,                 -- 异常产生的函数行数
//              const char* szFile /*= __FILE__*/,                          -- 异常产生的文件名
//              const char* szTime /*= NULL*/,                              -- 异常产生的时间
//              ...
// Return    : 
// Notes     : 
CException::CException( const char* szFormat, 
                        const char* szFunc, 
                        const unsigned long culLine, 
                        const char* szFile, 
                        const unsigned long culExpType /*= MAKEUSEREXP(ET_USER)*/, 
                        const unsigned long culExpCode /*= MAKEUSEREXP(ET_USER)*/, 
                        const char* szTime /*= NULL*/, 
                        ...)
{
    // 验证输入
    _VERIFY_3_(szFormat, szFunc, szFile);

    // 获取异常信息
    char szBuf[EX_MAX_BUF] = { 0 };
    va_list vp;
    va_start(vp, szTime);
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    vsprintf(szBuf, szFormat, vp);
#else
    vsprintf_s(szBuf, EX_MAX_BUF, szFormat, vp);
#endif
    va_end(vp);
    mstrMsg = szBuf;

    // 设置异常类型
    mulExpType = culExpType;

    // 设置异常代码
    mulExpCode = culExpCode;

    // 设置异常位置
    mulLine = culLine;
    mstrFunc = szFunc;
    mstrFile = vm::CFile::GetFileBase( szFile );

    // 设置异常时间
    if ( szTime != NULL )
    {
        mstrTime = szTime;
    }
    

} // End of function CException(...
/////////////////////////////////////////////////////////////////////////////////////////

#if defined (_MSC_VER) && (_MSC_VER<=1300)
CException::CException( 
           const char* szFunc,
           const unsigned long culLine,
           const char* szFile )
{
    // 验证输入
    _VERIFY_2_(szFunc, szFile);
    
 /*   ,
        const unsigned long culExpType = MAKEUSEREXP(ET_UNKNOWN),
        const unsigned long culExpCode = MAKEUSEREXP(ET_UNKNOWN),
           const char* szTime = NULL
    // 设置异常类型
    mulExpType = culExpType;
    
    // 设置异常代码
    mulExpCode = culExpCode;
   */ 
    // 设置异常位置
    mulLine = culLine;
    mstrFunc = szFunc;
    vm::CFile loFile(szFile);
    mstrFile = loFile.mstrFileBase.c_str();
    
//     // 设置异常时间
//     if ( szTime != NULL )
//     {
//         mstrTime = szTime;
//     }
}

CException& CException::operator()( const char* szFormat, ... ) 
{
    // 获取异常信息
    char szBuf[EX_MAX_BUF] = { 0 };
    va_list vp;
    va_start(vp, szFormat);
    vsprintf(szBuf, szFormat, vp);
    va_end(vp);
    mstrMsg = szBuf;

    return *this;
}
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CException
// Full name : CException::CException
// Access    : public 
// Brief     : 
// Parameter : const CException& ex, const char* szFunc/*= "func"*/, const unsigned long culLine /*= __LINE__*/, const char* szFile /*= __FILE__*/, const char* szTime /*= NULL */
// Return    : 
// Notes     : 
CException::CException(const vm::CException& ex, 
                       const char* szFunc,
                       const unsigned long culLine /*= __LINE__*/, 
                       const char* szFile /*= __FILE__*/, 
                       const char* szTime /*= NULL */)
{
    mstrMsg = ex.mstrMsg;

    // 设置异常类型
    mulExpType = ex.mulExpType;

    // 设置异常代码
    mulExpCode = ex.mulExpCode;

    // 设置异常位置
    mulLine = culLine;
    mstrFunc = szFunc;
    mstrFile = vm::CFile::GetFileBase( szFile );

    // 设置异常时间
    if ( szTime != NULL )
    {
        mstrTime = szTime;
    }

} // End of function CException(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CException
// Full name : CException::CException
// Access    : public 
// Brief     : 
// Parameter : const CException& ex
// Return    : 
// Notes     : 
CException::CException(const vm::CException& ex)
{
    mulExpType  = ex.mulExpType;             // 异常类型: 详见异常类型定义

    mulExpCode  = ex.mulExpCode;             // 异常代码

    mulLine     = ex.mulLine;                // 异常产生的文件行数
    mstrFile    = ex.mstrFile;               // 异常产生的文件名
    mstrFunc    = ex.mstrFunc;               // 异常产生的函数名

    mstrTime    = ex.mstrTime;               // 异常产生的时间
    mstrMsg     = ex.mstrMsg;                // 异常信息
    mstrBuf     = ex.mstrBuf;                // 异常信息

} // End of function CException(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CException::ToString
// Access    : virtual public 
// Brief     : 格式化输出异常信息
// Parameter : const char* szFormat                                 -- 异常格式
// Return    : const char*                                          -- 异常信息
// Notes     : 异常格式  
//             %M                -- 异常产生的函数名
//             %L                -- 异常产生的行数
//             %F                -- 异常产生的文件名
//             %T                -- 异常类型
//             %C                -- 异常代码
//             %I                -- 异常信息
//             %D                -- 异常产生的时间
const char* CException::Format(const char* szFormat)
{
    _VERIFY_( szFormat );

    char szBuf[EX_MAX_BUF] = { 0 };

    size_t lstLenForTmp = strlen( szFormat );
    size_t lstMinLen = _MIN_( EX_MAX_BUF, lstLenForTmp );

    char* lpBuf = szBuf;
    char* lpFormat = const_cast<char*>(szFormat);

    size_t lstCopied = 0;
    char *p = NULL;
    do 
    {
#if defined (_MSC_VER) && (_MSC_VER<=1300)
        p = (char*)memccpy( lpBuf, lpFormat, '%', lstMinLen );
#else
        p = (char*)_memccpy( lpBuf, lpFormat, '%', lstMinLen );
#endif
        
        if ( p==NULL )
        {
            break;
        }

        unsigned int luiLeft = p-lpBuf;
        lpBuf       += luiLeft-1;
        lpFormat    += luiLeft;
        char cFlag = *(lpFormat);
        switch( cFlag )
        {
        case 'M':
            {
                memcpy(lpBuf,mstrFunc.c_str(), mstrFunc.size());
                lpBuf+=mstrFunc.size();
                lpFormat+=1;
            }
            break;
        case 'L':
            {
                CValue lValue(mulLine);
                memcpy( lpBuf, lValue.ToString(), lValue.Size() );
                lpBuf+=lValue.Size();
                lpFormat+=1;
            }
            break;
        case 'T':
            {
                CValue lValue(mulExpType);
                memcpy( lpBuf, lValue.ToHexStr(), lValue.Size() );
                lpBuf+=lValue.Size();
                lpFormat+=1;
            }
            break;
        case 'C':
            {
                CValue lValue(mulExpCode);
                memcpy( lpBuf, lValue.ToHexStr(), lValue.Size() );
                lpBuf+=lValue.Size();
                lpFormat+=1;
            }
            break;
        case 'F':
            {
                memcpy(lpBuf,mstrFile.c_str(), mstrFile.size());
                lpBuf+=mstrFile.size();
                lpFormat+=1;
            }
            break;
        case 'I':
            {
                memcpy(lpBuf,mstrMsg.c_str(), mstrMsg.size());
                lpBuf+=mstrMsg.size();
                lpFormat+=1;
            }
            break;
        case 'D':
            {
                memcpy(lpBuf,mstrTime.c_str(), mstrTime.size());
                lpBuf+=mstrTime.size();
                lpFormat+=1;
            }
        case '%':
            {
                memcpy(lpBuf,lpFormat, sizeof(char));
                lpBuf+=sizeof(char);
                lpFormat+=1;
            }
            break;
        }

        lstCopied = lpBuf-szBuf;
    } while ((lstCopied<1024) && (p!=NULL));

    mstrBuf = szBuf;
    return mstrBuf.c_str();
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=
// Full name : CException::operator=
// Access    : public 
// Brief     : 赋值操作
// Parameter : const CException& ex
// Return    : CException&
// Notes     : 
CException& CException::operator=(const CException& ex)
{
    mulExpType = ex.mulExpType;
    mulExpCode = ex.mulExpCode;
    mulLine = ex.mulLine;
    mstrFile = ex.mstrFile;
    mstrFunc = ex.mstrFunc;
    mstrTime = ex.mstrTime;
    mstrMsg = ex.mstrMsg;
    mstrBuf = ex.mstrBuf;

    return *this;
} // End of function operator=(...
/////////////////////////////////////////////////////////////////////////////////////////

} // End of namespace JL

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CException.cpp...
/////////////////////////////////////////////////////////////////////////////////////////