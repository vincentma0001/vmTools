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
#ifndef   __VM_CFG_H__
#   include <vmCfg/vmCfgtString.h>
#endif // __VM_CFG_H__

// Platform files included
#ifndef   _WINDOWS_
#   include <windows.h>
#endif // _WINDOWS_

#ifndef   __CSTRINGPTR_H__
#   include <vmLibBase/CStringPtr.h>
#endif // __CSTRINGPTR_H__

#ifndef   __CWINFILE_H__
#   include <vmLibFile/CWinFile.h>
#endif // __CWINFILE_H__

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
    // �洢Ini�ļ������ļ���
    tchar   mszPath[_V_FILE_MAX_PATH_];
    // ���ݻ�����
    tchar   mszBuf[sztBufSize];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // ����Ini�����ļ���
    inline void Open( const tchar* const szFileName);

    // ��ȡһ���ַ������͵�ֵ
    inline tchar* GetValueStr(const tchar* const szAppName, const tchar* const szKeyName, const tchar* const szDefaule);
    // ��ȡһ��int����ֵ
    inline int    GetValueInt(const tchar* const szAppName, const tchar* const szKeyName, const int iDefaule);

    // д��Ini�ļ�ֵ
    inline bool   WriteValue (const tchar* const szAppName, const tchar* const szKeyName, const tchar* const szValue);


}; // End of class CWinIni
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : 
// Brief     : # add method brief here #
// Return    : void
// Parameter : null
template< size_t sztBufSize >
inline void CWinIni<sztBufSize>::Open( const tchar* const szFileName)
{
    vm::CFile() loFile(szFileName);
    vm::CStringPtr lstrPath(mszPath, sizeof(mszPath));
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
inline tchar* CWinIni<sztBufSize>::GetValueStr(const tchar* const szAppName, const tchar* const szKeyName, const tchar* const szDefaule)
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
inline int CWinIni<sztBufSize>::GetValueInt(const tchar* const szAppName, const tchar* const szKeyName, const int iDefaule)
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
inline bool CWinIni<sztBufSize>::WriteValue(const tchar* const szAppName, const tchar* const szKeyName, const tchar* const szValue)
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