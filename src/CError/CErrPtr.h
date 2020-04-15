/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CErrPtr.h
// Version      : 0.0.0.0
// Author       : v.m.
// Brief        : 此文件定义了CError类为错误处理提供基类,用于存储错误代码与错误信息
// Create time  : 2019/12/20 08:33:15
// Modify time  : 2019/12/20 08:33:15
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

#ifndef __CERRPTR_H__
#define __CERRPTR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Files include : 

#ifndef   __VM_CFG_H__
#   include <vmCfg.h>
#endif // __VM_CFG_H__

#ifndef   __VM_UTIL_H__
#   include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

#ifndef   __CPARSER_H__
#   include <vmLibBase/CParser.h>
#endif // __CPARSER_H__

#ifndef   __CERRNO_H__
#   include <vmLibBase/CErrno.h>
#endif // __CERRNO_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CError : 此类封装了错误系统错误信息
//
/////////////////////////////////////////////////////////////////////////////////////////
class CErrPtr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :
#ifndef    _V_CERRPTR_MAX_BUF_
#   define _V_CERRPTR_MAX_BUF_ 1024
#endif  // _V_CERRPTR_MAX_BUF_

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CErrPtr(const unsigned long culErrCode, tchar* const cpBuf, const size_t csztBufSize);
    // Destruct define
    virtual ~CErrPtr();
    
public:
    // Copy define 
    CErrPtr(const CErrPtr& obj);
    // Assignment define
    CErrPtr& operator = ( const CErrPtr& obj );
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
public:
    // 错误代码
    unsigned long    mulErrCode;
    tchar*           mpBuf;
    size_t           msztBufSize;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // Output error code 
    unsigned long    toErrCode();
    // Output error message
    tchar*           toErrStr();
    // Format error message
    tchar*           Fmt(const tchar* const cpFmt = vT("%EC:%EM") );

protected:
    // 获取错误代码信息
    virtual tchar*   GetErrStr( tchar* pBufAddr, const size_t csztBufSzie, size_t& sztStrLen );

}; // End of class CError
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CErrPtr(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
explicit CErrPtr::CErrPtr(const unsigned long           culErrCode, 
                          tchar* const                  cpBuf, 
                          const size_t                  csztBufSize)
                         :mulErrCode(culErrCode), mpBuf(cpBuf), msztBufSize(csztBufSize) 
{
};
// End of function CErrPtr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CErrBase(...)
// Brief     :
// Return    : 
CErrPtr::~CErrPtr()
{

};
// End of function ~CErrBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CErrBase(...)
// Brief     :
// Return    : 
// Parameter : const CErrBase & obj
CErrPtr::CErrPtr(const CErrPtr& obj)
{
    *this = obj;
};
// End of function CErrBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     :
// Return    : vm::CErrBase&
// Parameter : const CErrBase & obj
vm::CErrPtr& CErrPtr::operator=(const CErrPtr& obj)
{

    mulErrCode = obj.mulErrCode;
    v_memcpy(mpBuf, msztBufSize, obj.mpBuf, obj.msztBufSize);
    return *this;
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toErrCode(...)
// Brief     :
// Return    : unsigned long
unsigned long CErrPtr::toErrCode()
{
    return mulErrCode;
}
// End of function toErrCode(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toErrStr(...)
// Brief     :
// Return    : tchar*
tchar* CErrPtr::toErrStr()
{
    size_t lsztStrLen = 0;
    return GetErrStr(mpBuf, msztBufSize, lsztStrLen);
}
// End of function toErrStr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Fmt(...)
// Brief     :
// Return    : tchar*
// Parameter : const tchar * const cpFmt
tchar* CErrPtr::Fmt(const tchar* const cpFmt /*= "%EC:%EM" */)
{
    // 获取错误代码所包含的错误信息
    tchar  lszCodeStrBuf[ _V_CERRPTR_MAX_BUF_ ] = { 0x00 };
    size_t lsztCodeStrLen = 0;
    tchar* lpCodeStr      = GetErrStr(lszCodeStrBuf, sizeof(lszCodeStrBuf), lsztCodeStrLen);

    // 初始化缓存区数据
    vm::CParser::CPattern loPatternErrCode(vT("%EC"), vm::CAny<128>(mulErrCode).s_ulong());
    vm::CParser::CPattern loPatternErrMsg (vT("%EM"), lpCodeStr);

    vm::CParser loParser(vT('%'), cpFmt);
    loParser.Regist(loPatternErrCode);
    loParser.Regist(loPatternErrMsg);

    loParser.Parse(mpBuf, msztBufSize);

    return mpBuf;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrStr(...)
// Brief     :
// Return    : tchar*
// Parameter : tchar * pBufAddr
// Parameter : const size_t csztBufSzie
// Parameter : size_t & sztStrLen
tchar* CErrPtr::GetErrStr(tchar* pBufAddr, const size_t csztBufSzie, size_t& sztStrLen)
{
    errno_t loErr = vStrerror_s( pBufAddr, csztBufSzie, mulErrCode );
    vCheckErrCode(CErrPtr::GetErrStr(), loErr);
    return pBufAddr;
}
// End of function GetErrStr(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CERRPTR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CErrPtr.h
/////////////////////////////////////////////////////////////////////////////////////////