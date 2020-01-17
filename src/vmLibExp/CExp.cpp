/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CExp.cpp
// Version      : 0.0.0.0
// Author       : v.m.
// Brief        : 
// Create time  : 2020/01/02 20:51:18
// Modify time  : 2020/01/02 20:51:18
// Note         :
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Disable warnings :
// Example : #pragma warning(disable:4996)

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <exception>
#include <time.h>

// Config files included
#include <vmCfg.h>

// platform files included
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
#include <windows.h>
#endif // #if defined(...)

// Used files included
#include <vmLibBase/vmUtil.h>
#include <vmLibErr.h>

#include <vmLibBase/CMemPtr.h>
#include <vmLibBase/CStrPtr.h>
#include <vmLibBase/CDateTime.hpp>

#include <vmLibFile.h>

// Declare file included
#include "CExp.h"
#include "vmVerify.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
CExp::CExp(): mExpLevel(emExp),mpExpNext(nullptr)
{

}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CExp(...)
// Brief     :
// Return    : 
CExp::~CExp()
{
    if ( mpExpNext != nullptr )
        delete mpExpNext;
    
    mpExpNext = nullptr;
}
// End of function ~CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const tchar * const cpFile
// Parameter : const unsigned int cuiLine
CExp::CExp( const tchar* const   cpFile, 
            const unsigned long culLine,
            const tchar* const   cpTimeFmt ):mExpLevel(emExp),mpExpNext(nullptr)
{
    vCStrPtr(mszFile)     = vm::CFileBase(cpFile).cs_FileName();
    muiLine               = culLine;
    vCStrPtr(mszDateTime) = vm::CDateTime<_V_CDATETIME_MAX_BUF_>::GetCurrTime().Fmt(cpTimeFmt);
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const CExp & oExp
// Parameter : const tchar * const cpFile
// Parameter : const unsigned int cuiLine
CExp::CExp( const CExp&               oExp, 
            const tchar* const      cpFile, 
            const unsigned long    culLine,
            const tchar* const   cpTimeFmt)
           :mExpLevel(emExp), mpExpNext(nullptr)
{
    mpExpNext       = new CExp();
    *mpExpNext      = oExp;

    vm::CFileBase::GetFileName( cpFile, vStrLen(cpFile), mszFile, sizeof(mszFile) ); 
    muiLine                   = culLine;
    vCStrPtr(mszDateTime)     = vm::CDateTime<_V_CDATETIME_MAX_BUF_>::GetCurrTime().Fmt(cpTimeFmt);
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const CExp & obj
CExp::CExp(const CExp& obj)
{
    *this = obj;
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     :
// Return    : vm::CExp&
// Parameter : const CExp & obj
vm::CExp& CExp::operator=(const CExp& obj)
{
    // 复制CExp中的数据
    vCStrPtr(mszFunc)        = obj.mszFunc;
    vCStrPtr(mszFile)        = obj.mszFile;
    muiLine                  = obj.muiLine;
    vCStrPtr(mszDateTime)    = obj.mszDateTime;
    vCStrPtr(mszMsg)         = obj.mszMsg;

    // 循环复制上一级异常信息
    if ( obj.mpExpNext == nullptr )
        return *this;

    if ( mpExpNext != nullptr )
        delete [] mpExpNext;

    mpExpNext = new CExp();
    *mpExpNext = *obj.mpExpNext;

    return *this;
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator()(...)
// Brief     :
// Return    : void
// Parameter : const tchar * const cpFunc
// Parameter : const tchar * const cpFmt
// Parameter : ...
CExp& CExp::operator()(const tchar* const cpFunc, const tchar* const cpFmt, ...)
{
    vCStrPtr(mszFunc) = cpFunc;

    va_list vList;
    va_start(vList, cpFmt);
    vCMemPtr(mszMsg).Fmt(cpFmt, vList);
    va_end(vList);

    return *this;
}
// End of function operator()(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator()(...)
// Brief     :
// Return    : void
// Parameter : const tchar * const cpFunc
// Parameter : const tchar * const cpFmt
// Parameter : va_list vList
CExp& CExp::operator()(const tchar* const cpFunc, const tchar* const cpFmt, va_list vList)
{
    vCStrPtr(mszFunc) = cpFunc;
    vCStrPtr(mszMsg).Fmt(cpFmt, vList);

    return *this;
}
// End of function operator()(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Fmt(...)
// Brief     :
// Return    : int
// Parameter : const tchar * const cpFmt
tchar* CExp::Fmt(const tchar* const cpFmt)
{
    // 验证格式代码是否正确
    _VERIFY_(cpFmt);

    // 初始化缓存区数据
    vm::CParser::CPattern loPatternExpFunc(vT("%M"), mszFunc);
    vm::CParser::CPattern loPatternExpFile(vT("%F"), mszFile);
    vm::CParser::CPattern loPatternExpLine(vT("%L"), vm::CAny<128>(muiLine).s_ulong());
    vm::CParser::CPattern loPatternExpTime(vT("%T"), mszDateTime);
    vm::CParser::CPattern loPatternExpMsgs(vT("%N"), mszMsg);

    vm::CParser loParser(vT('%'), cpFmt);
    loParser.Regist(loPatternExpFunc);
    loParser.Regist(loPatternExpFile);
    loParser.Regist(loPatternExpLine);
    loParser.Regist(loPatternExpTime);
    loParser.Regist(loPatternExpMsgs);

    vMemZero(mszBuf);
    loParser.Parse(mszBuf, sizeof(mszBuf));

    return mszBuf;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Next(...)
// Brief     :
// Return    : vm::CExp*
vm::CExp* CExp::Next()
{
    return mpExpNext;
}
// End of function Next(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CExp.cpp
/////////////////////////////////////////////////////////////////////////////////////////
