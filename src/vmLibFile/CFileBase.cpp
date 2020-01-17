/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : IFile.cpp
// Version      : 0.0.0.0
// Author       : v.m.
// Brief        : 
// Create time  : 2019/12/30 19:41:02
// Modify time  : 2019/12/30 19:41:02
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
#include <string>

// Config files included
#include <vmCfg.h>

// platform files included
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
#include <windows.h>
#endif // #if defined(...)

// Used files included
#include <vmLibBase/vmUtil.h>

// Declare file included
#include "CFileBase.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CFileBase(...)
// Brief     : 构造函数
// Return    : null
// Parameter : void
CFileBase::CFileBase() : mulErrCode(0)
{
    vMemZero(mszFilePath);
    vMemZero(mszFileDir);
    vMemZero(mszFileName);
    vMemZero(mszFileBase);
    vMemZero(mszFileExt);

}
// End of function CFileBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CFileBase(...)
// Brief     : 构建函数
// Return    : null
// Parameter : cpFName                      - 文件名，若为NULL则为获取当前进程的文件名
CFileBase::CFileBase(const tchar* const cpFName ) : mulErrCode(0)
{
    vMemZero(mszFilePath);
    size_t lsztExecNameLen = 0;
    tchar* lpFName = const_cast<tchar*>(cpFName); 

    // if the string address is null, get current execute file's path
    if (cpFName == nullptr)
    {
        // Get current execute file's path
        lsztExecNameLen = vm::CFileBase::GetExecName( mszFilePath, sizeof(mszFilePath) );
        if ( lsztExecNameLen ==0 )
        { mulErrCode = GetLastError(); return; }
        
        lpFName = mszFilePath;
    } 
    // End of if (cpFName == nullptr) ...

    // Check the string has direct struct or not
    bool lbHasDir = vm::CFileBase::HasDir(lpFName);
    if ( lbHasDir==false )
    {
        // if it hasn't direct struct, get current execute file's direct as direct
        vMemZero(mszFileDir);
        size_t lsztDirLen = vm::CFileBase::GetExecDir( mszFileDir, sizeof(mszFileDir) );
        // rebuild the file's path with input file's string and current execute file's direct
        vMemZero(mszFilePath);
    	lsztExecNameLen   = vm::v_sprintf(mszFilePath, sizeof(mszFilePath), vT("%s\\%s"), mszFileDir, lpFName);
    }else if( cpFName!=nullptr )
    {
        // if it has direct struct, use cpName as file's path
        vMemZero(mszFilePath);
        lsztExecNameLen = vm::v_strcpy(mszFilePath,sizeof(mszFilePath), lpFName);
    }
    // End of if ( lbHasDir==false ) ...
   
    // Get file's direct struct with path 
    vMemZero(mszFileDir);
    size_t lsztFileDir = vm::CFileBase::GetFileDir(mszFilePath, lsztExecNameLen, mszFileDir, sizeof(mszFileDir));
    if (lsztFileDir == 0)
    { mulErrCode = GetLastError(); return; }

    // Get file's name with path
    vMemZero(mszFileName);
    size_t lsztFileName = vm::CFileBase::GetFileName( mszFilePath, lsztExecNameLen, mszFileName, sizeof(mszFileName) );
    if (lsztFileName == 0)
    { mulErrCode = GetLastError(); return; }

    // Check the string has ext name or not
    bool lbRetForHasExt = vm::CFileBase::HasExt( mszFilePath );
    if (lbRetForHasExt==false)
    {
        // If it hasn't ext name, use file's name as base name
        vMemZero(mszFileBase);
        vm::v_strncpy(mszFileBase, sizeof(mszFileBase), mszFileName, lsztFileName);

        // Set file's exit name as null
        vMemZero(mszFileExt);

        return;
    } 
    // End of if (lbRetForHasExt==false) ...
    
    // Get file's base name with path
    vMemZero(mszFileBase);
    size_t lsztFileBase = vm::CFileBase::GetFileBase(mszFilePath, lsztExecNameLen, mszFileBase, sizeof(mszFileBase));
    if (lsztFileName == 0)
    { mulErrCode = GetLastError(); return; }
    
    // Get file's ext name with path
    vMemZero(mszFileExt);
    size_t lsztFileExt = vm::CFileBase::GetFileExt(mszFilePath, lsztExecNameLen, mszFileExt, sizeof(mszFileExt));
    if (lsztFileName == 0)
    { mulErrCode = GetLastError(); return; }

}
// End of function CFileBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CFileBase(...)
// Brief     : 析构函数
// Return    : null
// Parameter : void
CFileBase::~CFileBase()
{

}
// End of function ~CFileBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CFileBase(...)
// Brief     : 拷贝构造函数
// Return    : null
// Parameter : obj                                  - 源拷贝对象
CFileBase::CFileBase(const CFileBase& obj)
{
    *this = obj;
}
// End of function CFileBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     : 赋值操作
// Return    : vm::IFile&                           - 当前对象
// Parameter : obj                                  - 赋值源对象
vm::CFileBase& CFileBase::operator=(const CFileBase& obj)
{
    v_memcpy(mszFilePath, sizeof(mszFilePath), obj.mszFilePath, sizeof(mszFilePath) );
    v_memcpy(mszFileDir,  sizeof(mszFileDir),  obj.mszFileDir,  sizeof(mszFileDir)  );
    v_memcpy(mszFileBase, sizeof(mszFileBase), obj.mszFileBase, sizeof(mszFileBase) );
    v_memcpy(mszFileName, sizeof(mszFileName), obj.mszFileName, sizeof(mszFileName) );
    v_memcpy(mszFileExt,  sizeof(mszFileExt),  obj.mszFileExt,  sizeof(mszFileExt)  );

    mulErrCode = obj.mulErrCode;   
 
    return *this;
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : HasDir(...)
// Brief     :
// Return    : bool
// Parameter : _vIn_ const tchar * const cpPath
bool CFileBase::HasDir(_vIn_ const tchar* const cpPath)
{
    // 根据目录分割符判断输入的字符串是否为带有目录的文件名
    tchar* lpRetForSplite = vm::v_strrchr(const_cast<tchar*>(cpPath), _V_DIR_SPLITE_);
    // 判断是否查找到目录分割符
    if (lpRetForSplite == nullptr)
        return false;

    return true;
}
// End of function HasDir(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : HasExt(...)
// Brief     :
// Return    : bool
// Parameter : _vIn_ const tchar * const cpPath
bool CFileBase::HasExt(_vIn_ const tchar* const cpPath)
{
    // 根据目录分割符判断输入的字符串是否为带有目录的文件名
    tchar* lpRetForSplite = vm::v_strrchr(const_cast<tchar*>(cpPath), _V_EXT_SPLITE_);
    // 判断是否查找到目录分割符
    if (lpRetForSplite == nullptr)
        return false;

    tchar lpNextChar = *(lpRetForSplite + 1);
    // 判断符号是".\\"
    if ((lpNextChar == _V_DIR_SPLITE_))
    {
        return false;
    }

    tchar lpNextNextChar = *(lpRetForSplite + 2);
    // 判断符号是否是"..\\"
    if ((lpNextChar == _V_EXT_SPLITE_) && (lpNextNextChar == _V_DRV_SPLITE_))
    {
        return false;
    }

    return true;
}
// End of function HasExt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileDir(...)
// Brief     :
// Return    : tchar*
// Parameter : _vIn_ const tchar * const cpPath
// Parameter : _vIn_ const size_t csztPathLen
// Parameter : _vOt_ tchar * const pDirBuf
// Parameter : _vIn_ const size_t csztDirBufSize
size_t CFileBase::GetFileDir(_vIn_ const tchar* const cpPath, _vIn_ const size_t csztPathLen, _vOt_ tchar* const pDirBuf, _vIn_ const size_t csztDirBufSize)
{
    size_t lsztRet = vm::v_str_substr(pDirBuf, csztDirBufSize, cpPath, csztPathLen, vStrPosBegin, _V_DIR_SPLITE_);
    return lsztRet;
}
// End of function GetFileDir(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileName(...)
// Brief     :
// Return    : tchar*
// Parameter : _vIn_ const tchar * const cpPath
// Parameter : _vIn_ const size_t csztPathLen
// Parameter : _vOt_ tchar * const pDirBuf
// Parameter : _vIn_ const size_t csztDirBufSize
size_t CFileBase::GetFileName(_vIn_ const tchar* const cpPath, _vIn_ const size_t csztPathLen, _vOt_ tchar* const pDirBuf, _vIn_ const size_t csztDirBufSize)
{
    size_t lsztRet = vm::v_str_substr_last(pDirBuf, csztDirBufSize, cpPath, csztPathLen, _V_DIR_SPLITE_, vStrPosEnded);
    return lsztRet;
}
// End of function GetFileName(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileBase(...)
// Brief     :
// Return    : tchar*
// Parameter : _vIn_ const tchar * const cpPath
// Parameter : _vIn_ const size_t csztPathLen
// Parameter : _vOt_ tchar * const pDirBuf
// Parameter : _vIn_ const size_t csztDirBufSize
size_t CFileBase::GetFileBase(_vIn_ const tchar* const cpPath, _vIn_ const size_t csztPathLen, _vOt_ tchar* const pDirBuf, _vIn_ const size_t csztDirBufSize)
{
    // 获取文件名，不包含扩展名
    size_t lsztRet = vm::v_str_substr_last(pDirBuf, csztDirBufSize, cpPath, csztPathLen, _V_DIR_SPLITE_, _V_EXT_SPLITE_);
    return lsztRet;
}
// End of function GetFileBase(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileExt(...)
// Brief     :
// Return    : tchar*
// Parameter : _vIn_ const tchar * const cpPath
// Parameter : _vIn_ const size_t csztPathLen
// Parameter : _vOt_ tchar * const pDirBuf
// Parameter : _vIn_ const size_t csztDirBufSize
size_t CFileBase::GetFileExt(_vIn_ const tchar* const cpPath, _vIn_ const size_t csztPathLen, _vOt_ tchar* const pDirBuf, _vIn_ const size_t csztDirBufSize)
{
    // 获取文件扩展名
    size_t lsztRet = vm::v_str_substr_last(pDirBuf, csztDirBufSize, cpPath, csztPathLen, _V_EXT_SPLITE_, vStrPosEnded);
    return lsztRet;
}
// End of function GetFileExt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : GetExecDir(...)
// Brief     : Get current execute file's direction
// Return    : tchar*                                     - return current execute file dir
// Parameter : pOutputBuf                                - [O] the buffer for current execute file direct.
//           : csztBufSize                               - [I] the buffer's size
size_t CFileBase::GetExecDir(_vOt_ tchar* const pOutputBuf, _vIn_ const size_t csztBufSize)
{
    // Get full path.
    size_t lsztLenOfPath = ::GetModuleFileName(NULL, pOutputBuf, csztBufSize);

    // Get direct string ( from start to last '\\' )
    size_t lsztSubstrLen = vm::v_str_substr(pOutputBuf, lsztLenOfPath, vMinsInt, '\\');
    return lsztSubstrLen;
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
size_t CFileBase::GetExecName(_vOt_ tchar* const pOutputBuf, _vIn_ const size_t csztBufSize)
{
    size_t lsztRet = ::GetModuleFileName(NULL, pOutputBuf, csztBufSize);
    return lsztRet;
}
// End of function GetExecName(...)
/////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
// End of file IFile.cpp
/////////////////////////////////////////////////////////////////////////////////////////
