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
// include file

#include <direct.h>


#include <vmCfg.h>

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
    inline static char* GetExecDir( _vOt_ char* const pOutputBuf, _vIn_ const size_t csztBufSize  )
    {
        //DWORD ldwRet = ::GetCurrentDirectory(csztBufSize, pOutputBuf);
        //return pOutputBuf;
        char lszBuf[_V_FILE_MAX_PATH_] = {0x00};
        size_t lszRet = ::GetModuleFileName( NULL, lszBuf, csztBufSize );
        
        vm::v_str_substr( pOutputBuf, csztBufSize, lszBuf, lszRet+1, vMinsInt, '\\' );

        return ::_getcwd(pOutputBuf, csztBufSize );
    }

    inline static size_t GetExecName(_vOt_ char* const pOutputBuf, _vIn_ const size_t csztBufSize )
    {
        size_t lsztRet = ::GetModuleFileName( NULL, pOutputBuf, csztBufSize );
        if  (  lsztRet > 0  )
            return lsztRet;

        return 0;
    }
    
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