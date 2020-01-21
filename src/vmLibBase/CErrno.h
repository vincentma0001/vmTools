/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CErrno.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2019/12/31 10:24:43
// Modify time  : 2019/12/31 10:24:43
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

#ifndef __CERRNO_H__
#define __CERRNO_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#ifndef   _INC_ERRNO
#   include <errno.h>
#endif // _INC_ERRNO

#ifndef   __VM_UTIL_H__
#   include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

#define vCheckErrCode( func, oErrCode )   vm::CErrno( oErrCode ).CheckError( vT(#func) )
#define vCheckError( func )               vm::CErrno( ).CheckError( vT(#func) );

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CErrno : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CErrno
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro define :
#define _V_ERRNO_MAX_BUF_ 1024

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CErrno( const errno_t oErrCode):moErrCode(oErrCode){};
    explicit CErrno():moErrCode(errno){};
    // Destruct define
    virtual  ~CErrno(){};
    
private:
    // No Copy
    CErrno(const CErrno& obj) {};
    // No Assignment
    CErrno& operator = ( const CErrno& obj ){ return *this; };
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
public:
    // ´íÎó´úÂë
    errno_t  moErrCode;
    
    // ´íÎóÐÅÏ¢
    tchar    mszErrMsg[_V_ERRNO_MAX_BUF_];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // »ñÈ¡µ±Ç°´íÎó´úÂë
    errno_t toErrCode();

    // ÅÐ¶ÏiErrnoÊÇ·ñ´æ´íÎó
    bool isError( const int iErrno );
    // ÅÐ¶ÏÊÇ·ñ´æÔÚerrno´íÎó
    bool HasErrno();

    // ¼ì²â´íÎó£¬ÈôÓÐ´íÎóÅ×³öÒì³£
    void CheckError( const tchar* const cpFunc );

    // Êä³ö´íÎóÐÅÏ¢
    tchar* MsgErrno();
    tchar* MsgErrno(const errno_t oErrCode);

}; // End of class CErrno
/////////////////////////////////////////////////////////////////////////////////////////

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
// Method    : CheckError(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
void CErrno::CheckError(const tchar* const cpFunc)
{
    if (moErrCode == 0)
        return;

    v_sprintf(mszErrMsg, sizeof(mszErrMsg), vT("%s - has an error(%d, %s) launched!"), cpFunc, moErrCode, vStrerror(moErrCode));
    throw mszErrMsg;
}
// End of function CheckError(...)
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
// Return    : tchar*                        - ·µ»Ø´íÎóÐÅÏ¢
// Parameter : null
inline tchar* CErrno::MsgErrno()
{
    vMemZero(mszErrMsg);

#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = vStrerror_s(mszErrMsg, moErrCode);
    if (loRet != 0)
    {
        v_sprintf(mszErrMsg, sizeof(mszErrMsg), "CErrno::MsgErrno() - strerror_s failed(%d)", loRet);
        throw mszErrMsg;
    }

#else 
    tchar* lpErr = vStrerror(moErrCode);
    tchar* lpRet = vStrcpy(mszErrMsg, lpErr);
#endif
    return  mszErrMsg;
}
// End of function MsgErrno(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MsgErrno(...)
// Brief     : Êä³ö´íÎóÐÅÏ¢
// Return    : tchar*                        - ·µ»Ø´íÎóÐÅÏ¢
// Parameter : null
inline tchar* CErrno::MsgErrno(const errno_t oErrCode)
{
    vMemZero(mszErrMsg);

#if defined (_MSC_VER) && (_MSC_VER>=1300)
    errno_t loRet = vStrerror_s(mszErrMsg, oErrCode);
    if (loRet != 0)
    {
        v_sprintf(mszErrMsg, sizeof(mszErrMsg), "CErrno::MsgErrno() - strerror_s failed(%d)", loRet);
        throw mszErrMsg;
    }

#else 
    tchar* lpErr = vStrerror(oErrCode);
    tchar* lpRet = vStrcpy(mszErrMsg, lpErr);
#endif
    return  mszErrMsg;
}
// End of function MsgErrno(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CERRNO_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CErrno.h
/////////////////////////////////////////////////////////////////////////////////////////