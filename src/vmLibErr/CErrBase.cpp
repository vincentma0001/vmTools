/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CErrBase.cpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/14 19:17:01
// Modify time  : 2020/01/14 19:17:01
// Note         :
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Disable warning
// Example : #pragma warning(disable:4996)
// #if defined (_MSC_VER)
// #   pragma warning(disable:4996)
// #endif

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <string>

// Config files included
#include <vmCfg.h>

// platform files included
#if defined( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
#include <windows.h>
#endif // #if defined(...)

// Used files included
#include <vmLibBase/vmUtil.h>
#include <vmLibBase/CAny.hpp>
#include <vmLibBase/CStrPtr.h>
#include <vmLibBase/CParser.h>

// Declare file included
#include "CErrBase.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CErrBase(...)
// Brief     :
// Return    : 
CErrBase::CErrBase() :mulErrCode(0)
{
    vMemZero(mszBuf);
}
// End of function CErrBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CErrBase(...)
// Brief     :
// Return    : 
// Parameter : const unsigned long culErrCode
CErrBase::CErrBase(const unsigned long culErrCode) :mulErrCode(culErrCode)
{
    vMemZero(mszBuf);
}
// End of function CErrBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CErrBase(...)
// Brief     :
// Return    : 
CErrBase::~CErrBase()
{

}
// End of function ~CErrBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CErrBase(...)
// Brief     :
// Return    : 
// Parameter : const CErrBase & obj
CErrBase::CErrBase(const CErrBase& obj)
{
    *this = obj;
}
// End of function CErrBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     :
// Return    : vm::CErrBase&
// Parameter : const CErrBase & obj
vm::CErrBase& CErrBase::operator=(const CErrBase& obj)
{

    mulErrCode = obj.mulErrCode;
    v_memcpy(mszBuf, sizeof(mszBuf), obj.mszBuf, sizeof(obj.mszBuf));
    return *this;
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toErrCode(...)
// Brief     :
// Return    : unsigned long
unsigned long CErrBase::toErrCode()
{
    return mulErrCode;
}
// End of function toErrCode(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toErrStr(...)
// Brief     :
// Return    : tChar*
tChar* CErrBase::toErrStr()
{
    size_t lsztStrLen = 0;
    return GetErrStr(mszBuf, sizeof(mszBuf), lsztStrLen);
}
// End of function toErrStr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Fmt(...)
// Brief     :
// Return    : tChar*
// Parameter : const tChar * const cpFmt
tChar* CErrBase::Fmt(const tChar* const cpFmt /*= "%EC:%EM" */)
{
    // 获取错误代码所包含的错误信息
    tChar lszCodeStrBuf[ _V_ERR_MAX_BUF_ ] = { 0x00 };
    size_t lsztCodeStrLen = 0;
    tChar* lpCodeStr = GetErrStr(lszCodeStrBuf, sizeof(lszCodeStrBuf), lsztCodeStrLen);

    // 初始化缓存区数据
    vm::CParser::CPattern loPatternErrCode(vT("%EC"), vm::CAny<128>(mulErrCode).s_ulong());
    vm::CParser::CPattern loPatternErrMsg(vT("%EM"),  lpCodeStr);

    vm::CParser loParser(vT('%'), cpFmt);
    loParser.Regist(loPatternErrCode);
    loParser.Regist(loPatternErrMsg);

    loParser.Parse(mszBuf, sizeof(mszBuf));

    return mszBuf;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrStr(...)
// Brief     :
// Return    : tChar*
// Parameter : tChar * pBufAddr
// Parameter : const size_t csztBufSzie
// Parameter : size_t & sztStrLen
tChar* CErrBase::GetErrStr(tChar* pBufAddr, const size_t csztBufSzie, size_t& sztStrLen)
{
    return pBufAddr;
}
// End of function GetErrStr(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CErrBase.cpp
/////////////////////////////////////////////////////////////////////////////////////////
