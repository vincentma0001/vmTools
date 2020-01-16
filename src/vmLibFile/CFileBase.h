/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CFileBase.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2019/12/30 15:18:11
// Modify time  : 2019/12/30 15:18:11
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

#ifndef __CFILEBASE_H__
#define __CFILEBASE_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <direct.h>

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define :

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CFileBase : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CFileBase
{

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CFileBase();
    explicit CFileBase( const char* cpFName );
    // Destruct define
    virtual ~CFileBase();
    
public:
    // Copy construct define
    explicit CFileBase(const CFileBase& obj);
    // Assignment define
    CFileBase& operator = ( const CFileBase& obj );
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
protected:
    // 文件路径
    char mszPath  [ _V_FILE_MAX_PATH_];
    // 驱动器名
    char mszDriver[ _V_FILE_MAX_PATH_];
    // 文件目录
    char mszDir   [ _V_FILE_MAX_DIR_ ];
    // 文件名
    char mszFName [_V_FILE_MAX_FNAME_];
    // 文件扩展名
    char mszExt   [ _V_FILE_MAX_EXT_ ];

protected:
    // 错误代码
    unsigned long mulErrCode;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 判断是否有错误发生
    bool          HasError() { return (mulErrCode == 0) ? true : false; }
    // 获取错误代码
    unsigned long Errno() { return mulErrCode; };

public:
    // 获取文件路径信息
    inline const char* cs_Path()  { return mszPath;  };
    // 获取文件驱动器名
    inline const char* cs_Driver(){ return mszDriver;}
    // 获取文件目录信息
    inline const char* cs_Dir()   { return mszDir;   };
    // 获取文件名
    inline const char* cs_Name()  { return mszFName; };
    // 获取文件扩展名
    inline const char* cs_Ext()   { return mszExt;  };

/////////////////////////////////////////////////////////////////////////////////////////
// Static functions :
public:
    /////////////////////////////////////////////////////////////////////////////////////////
    // Method    : GetExecDir(...)
    // Brief     : Get current execute file's direction
    // Return    : char*                                     - return current execute file dir
    // Parameter : pOutputBuf                                - [O] the buffer for current execute file dir.
    //           : csztBufSize                               - [I] the buffer's size
    inline static char* GetExecDir( _vOt_ char* const pOutputBuf, _vIn_ const size_t csztBufSize  )
    {
        // Get full path.
        size_t lsztLenOfPath = ::GetModuleFileName( NULL, pOutputBuf, csztBufSize );
        
        // Get dir string ( from start to last '\\' )
        size_t lsztSubstrLen = vm::v_str_substr( pOutputBuf, lsztLenOfPath, vMinsInt, '\\' );

        // return the buffer's address
        return pOutputBuf;
    }
    // End of function GetExecDir(...)
    /////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////
    // Method    : GetExecName(...)
    // Brief     : Get current execute file's name
    // Return    : size_t                                    - the length of the string that is copied to the buffer.
    //             0                                         - the function is failed, get error by GetLastError().  
    // Parameter : pOutputBuf                                - [O] the buffer for the execute file's full path
    //           : csztBufSize                               - [I] the buffer's size
    inline static size_t GetExecName(_vOt_ char* const pOutputBuf, _vIn_ const size_t csztBufSize )
    {
        size_t lsztRet = ::GetModuleFileName( NULL, pOutputBuf, csztBufSize );
        return lsztRet;
    }
    // End of function GetExecName(...)
    /////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////    
}; // End of class CFileBase
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CFILEBASE_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CFileBase.h
/////////////////////////////////////////////////////////////////////////////////////////