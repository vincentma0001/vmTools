/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinIni.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/10 09:31:02
// Modify time  : 2020/01/10 09:31:02
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

#ifndef __CWININI_H__
#define __CWININI_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

// Platform files included
#include <windows.h>

// Used files included
#include <vmLibBase/CStrPtr.h>
#include <vmLibFile/CWinFile.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinIni : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template< size_t sztBufSize >
class CWinIni
{
////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CWinIni():mszPath{0x00},mszBuf{0x00}{};
    // Destruct define
    inline virtual ~CWinIni(){};
    
private:
    // No Copy
    inline CWinIni(const CWinIni& obj){};
    // No Assignment
    inline CWinIni& operator = ( const CWinIni& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    // 存储Ini文件完整文件名
    tChar   mszPath[_V_FILE_MAX_PATH_];
    // 数据缓存区
    tChar   mszBuf[sztBufSize];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 设置Ini完整文件名
    inline tVoid Open( cpctChar szFileName);

    // 获取一个字符串类型的值
    inline ptChar GetValueStr(cpctChar szAppName, cpctChar szKeyName, cpctChar szDefaule);
    // 获取一个int型数值
    inline tInt   GetValueInt(cpctChar szAppName, cpctChar szKeyName, ctInt iDefaule);

    // 写入Ini文件值
    inline tBool  WriteValue(cpctChar szAppName, cpctChar szKeyName, cpctChar szValue);


}; // End of class CWinIni
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : 
// Brief     : # add method brief here #
// Return    : void
// Parameter : null
template< size_t sztBufSize >
inline tVoid CWinIni<sztBufSize>::Open(cpctChar szFileName)
{
    vm::CFile() loFile(szFileName);
    vm::CStrPtr lstrPath(mszPath, sizeof(mszPath));
    lstrPath = loFile.cs_Path();
}
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : 
// Brief     : # add method brief here #
// Return    : void
// Parameter : null
template< size_t sztBufSize >
inline ptChar CWinIni<sztBufSize>::GetValueStr(cpctChar szAppName, cpctChar szKeyName, cpctChar szDefaule)
{
    ::GetPrivateProfileString(szAppName, szKeyName, szDefaule, mszBuf, sizeof(mszBuf), mszPath);
    return mszBuf;
}
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : 
// Brief     : # add method brief here #
// Return    : void
// Parameter : null
template< size_t sztBufSize >
inline tInt CWinIni<sztBufSize>::GetValueInt(cpctChar szAppName, cpctChar szKeyName, ctInt iDefaule)
{
    tInt liRet = ::GetPrivateProfileInt(szAppName, szKeyName, iDefaule, mszPath);
    return liRet;
}
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : 
// Brief     : # add method brief here #
// Return    : void
// Parameter : null
template< size_t sztBufSize >
inline tBool CWinIni<sztBufSize>::WriteValue(cpctChar szAppName, cpctChar szKeyName, cpctChar szValue)
{
    BOOL lbRet = ::WritePrivateProfileString(szAppName, szKeyName, szValue, mszPath);
    return (lbRet == TRUE) ? true : false;
}
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWININI_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinIni.h
/////////////////////////////////////////////////////////////////////////////////////////