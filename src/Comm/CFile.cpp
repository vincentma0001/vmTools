/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CFile.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 10/1/2016 16:42:25
// Modify time 	: 10/1/2016 16:42:25
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <windows.h>

#include "CFile.h"
#include "CException.h"
#include "CWinSehExp.h"
#include "CCppExp.h"
#include "VerifyDef.h"
#include "CWinError.h"

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#ifndef MAX_PATH
#   define MAX_PATH 260
#endif // !MAX_PATH

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

namespace JL{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CFile
// Full name : CFile::CFile
// Access    : private 
// Brief     : 构造函数
// Parameter : 
// Return    : 
// Notes     : 
CFile::CFile() :mstrFileName(""), mstrFileBase(""), mstrFileDir(""), mhFile(NULL)
{

} // End of function CFile(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CFile
// Full name : CFile::CFile
// Access    : private 
// Brief     : 构造函数
// Parameter : const char* szFileName                          -- 文件名
// Return    : 
// Notes     : 
CFile::CFile(const char* szFileName): mhFile(NULL)
{
    try{
        // 验证输入
        _VERIFY_(szFileName);

        // 获取全文件名
        mstrFileName = szFileName;

        // 获取文件名
        char szBuf[MAX_PATH] = { 0 };
        GetFileBase(szFileName, szBuf, MAX_PATH);
        mstrFileBase = szBuf;

        // 获取文件路径
        memset(szBuf, 0, MAX_PATH);
        GetFileDir(szFileName, szBuf, MAX_PATH);
        mstrFileDir = szBuf;

    }catch (JL::CException& ex){
        throw ex;
    }catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function CFile(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileBase
// Full name : CFile::GetFileBase
// Access    : public 
// Brief     : 获取文件名（不含路径）
// Parameter : const char* cszFileName,                     -- [in]  文件名
//             char* szBuf,                                 -- [out] 文件名缓存
//             const unsigned long culMaxBuf                -- [in]  文件名缓存长度
// Return    : void
// Notes     : 
void CFile::GetFileBase(const char* cszFileName, char* szBuf, const unsigned long culMaxBuf)
{
    try{
        _VERIFY_2_(cszFileName, szBuf);

        const char *lp = strrchr(cszFileName, int('\\'));
        _VERIFY_(lp);
#if defined (_MSC_VER) && (_MSC_VER<=1300)
        strcpy( szBuf, lp+1 );
#else
        strcpy_s(szBuf, culMaxBuf, lp+1);
#endif

    }catch (JL::CException& ex){
        throw ex;
    }catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function GetFileBase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileDir
// Full name : CFile::GetFileDir
// Access    : public 
// Brief     : 获取文件路径
// Parameter : const char* cszFileName,                         -- [in]  文件名
//             char* szBuf,                                     -- [out] 文件路径缓存
//             const unsigned long culMaxBuf                    -- [in]  文件路径缓存大小
// Return    : void
// Notes     : 
void CFile::GetFileDir(const char* cszFileName, char* szBuf, const unsigned long culMaxBuf)
{
    try{
        _VERIFY_2_(cszFileName, szBuf);

        const char *lp = strrchr(cszFileName, int('\\'));
        _VERIFY_(lp);

        memcpy(szBuf, cszFileName, (lp - cszFileName));
    }catch (JL::CException& ex){
        throw ex;
    }catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function GetFileDir(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrFile
// Full name : CFile::GetCurrFile
// Access    : public 
// Brief     : 获取当前执行文件文件名
// Parameter : 
// Return    : const char*                                      -- 文件名
// Notes     : 
const char* CFile::GetCurrFile()
{
    try{
        // 获取当前模块文件名
        char szBuf[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, szBuf, MAX_PATH);
        mstrFileName = szBuf;

        // 获取当前文件名
        memset(szBuf, 0, MAX_PATH);
        GetFileBase(mstrFileName.c_str(), szBuf, MAX_PATH);
        mstrFileBase = szBuf;

        //获取文件路径
        memset(szBuf, 0, MAX_PATH);
        GetFileDir(mstrFileName.c_str(), szBuf, MAX_PATH);
        mstrFileDir = szBuf;

        return mstrFileName.c_str();
    }catch (JL::CException& ex){
        throw ex;
    }catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function GetCurrFile(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrDir
// Full name : CFile::GetCurrDir
// Access    : public 
// Brief     : 获取当前可执行文件所在的路径
// Parameter : 
// Return    : const char*                                          -- 文件路径
// Notes     : 
const char* CFile::GetCurrDir()
{
    try{
        GetCurrFile();

        return mstrFileDir.c_str();
    }catch( JL::CException& ex ){
        throw ex;
    }catch( std::exception& ex ){
        throw CEXP_CPP(ex);
    }catch( CWinSeh& seh ){
        throw CEXP_SEH(seh);
    }catch( ... ){
        throw CEXP("Get an unknown exception!");
    }
} // End of function GetCurrDir(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Open
// Full name : CFile::Open
// Access    : private 
// Brief     : 
// Parameter : const char* szFileName
// Return    : void
// Notes     : 
void CFile::Open(const char* szFileName)
{
	mhFile = ::CreateFile( szFileName, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
	if ( mhFile==NULL )
	{
		CWinError loError;
		throw CEXP( "CFile::Open(), failed! ErrCode(%d:%s)", loError.GetErrorCode(), loError.GetErrorInfo() );
	}
} // End of function Open(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Write
// Full name : CFile::Write
// Access    : private 
// Brief     : 
// Parameter : LPVOID pBuffer, DWORD dwBuffLen
// Return    : DWORD
// Notes     : 
DWORD CFile::Write(LPVOID pBuffer, DWORD dwBuffLen)
{
	DWORD ldwWrited;
	DWORD ldwRet = ::SetFilePointer( mhFile, 0, 0, FILE_END );
	

	BOOL lbRet = ::WriteFile( mhFile, pBuffer, dwBuffLen, &ldwWrited, NULL );
	if ( lbRet != TRUE )
	{
		CWinError loError;
		throw CEXP( "CFile::Write(), failed! ErrCode(%d:%s)", loError.GetErrorCode(), loError.GetErrorInfo() );
	}
	return ldwWrited;
} // End of function Write(...
/////////////////////////////////////////////////////////////////////////////////////////


} // End of namespace JL


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CFile.cpp...
/////////////////////////////////////////////////////////////////////////////////////////