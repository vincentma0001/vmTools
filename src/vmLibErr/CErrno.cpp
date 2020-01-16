/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CErrno.cpp
// Version      : 0.0.0.0
// Author       : v.m.
// Brief        : 
// Create time  : 2019/12/31 10:49:52
// Modify time  : 2019/12/31 10:49:52
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
#if defined (_MSC_VER)
#   pragma warning(disable:4996)
#endif

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
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
#include <windows.h>
#include <errors.h>
#endif // #if defined(...)

// Used files included
#include <vmLibBase/vmUtil.h>

// Declare file included
#include "CErrno.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Global variable initialize

errno_t CErrno::moErrCode = 0;
char    CErrno::mszErrMsg[_V_ERRNO_MAX_BUF_] = {0x00};

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toErrCode(...)
// Brief     :
// Return    : errno_t
errno_t CErrno::toErrCode()
{
    return moErrCode;
}
// End of function toErrCode(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : HasErrno(...)
// Brief     : ÅÐ¶ÏiErrnoÊÇ·ñ´æ´íÎó
// Return    : void
// Parameter : null
inline bool CErrno::HasErrno()
{
    if (errno == 0)
        return false;

    moErrCode = errno;
    return true;
}
// End of function HasErrno(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : HasErrno()
// Brief     : ÅÐ¶ÏÊÇ·ñ´æÔÚerrno´íÎó
// Return    : void
// Parameter : null
inline bool CErrno::isError(const errno_t oErrCode)
{
    if (oErrCode == 0)
        return false;

    moErrCode = oErrCode;
    return true;
}
// End of function HasErrno()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MsgErrno(...)
// Brief     : Êä³ö´íÎóÐÅÏ¢
// Return    : char*                        - ·µ»Ø´íÎóÐÅÏ¢
// Parameter : null
inline char* CErrno::MsgErrno()
{
    vMemZero(mszErrMsg);

#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = strerror_s(mszErrMsg, moErrCode);
    if (loRet != 0)
    {
        v_sprintf(mszErrMsg, sizeof(mszErrMsg), "CErrno::MsgErrno() - strerror_s failed(%d)", loRet);
        throw mszErrMsg;
    }

#else 
    char* lpErr = strerror(moErrCode);
    char* lpRet = strcpy(mszErrMsg, lpErr);
#endif
    return  mszErrMsg;
}
// End of function MsgErrno(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MsgErrno(...)
// Brief     : Êä³ö´íÎóÐÅÏ¢
// Return    : char*                        - ·µ»Ø´íÎóÐÅÏ¢
// Parameter : null
inline char* CErrno::MsgErrno(const errno_t oErrCode)
{
    vMemZero(mszErrMsg);

#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = strerror_s(mszErrMsg, oErrCode);
    if (loRet != 0)
    {
        v_sprintf(mszErrMsg, sizeof(mszErrMsg), "CErrno::MsgErrno() - strerror_s failed(%d)", loRet);
        throw mszErrMsg;
    }

#else 
    char* lpErr = strerror(oErrCode);
    char* lpRet = strcpy(mszErrMsg, lpErr);
#endif
    return  mszErrMsg;
}
// End of function MsgErrno(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CErrno.cpp
/////////////////////////////////////////////////////////////////////////////////////////
