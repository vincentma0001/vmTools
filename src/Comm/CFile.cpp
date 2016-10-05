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
// Brief     : ���캯��
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
// Brief     : ���캯��
// Parameter : const char* szFileName                          -- �ļ���
// Return    : 
// Notes     : 
CFile::CFile(const char* szFileName): mhFile(NULL)
{
    try{
        // ��֤����
        _VERIFY_(szFileName);

        // ��ȡȫ�ļ���
        mstrFileName = szFileName;

        // ��ȡ�ļ���
        char szBuf[MAX_PATH] = { 0 };
        GetFileBase(szFileName, szBuf, MAX_PATH);
        mstrFileBase = szBuf;

        // ��ȡ�ļ�·��
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
// Brief     : ��ȡ�ļ���������·����
// Parameter : const char* cszFileName,                     -- [in]  �ļ���
//             char* szBuf,                                 -- [out] �ļ�������
//             const unsigned long culMaxBuf                -- [in]  �ļ������泤��
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
// Brief     : ��ȡ�ļ�·��
// Parameter : const char* cszFileName,                         -- [in]  �ļ���
//             char* szBuf,                                     -- [out] �ļ�·������
//             const unsigned long culMaxBuf                    -- [in]  �ļ�·�������С
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
// Brief     : ��ȡ��ǰִ���ļ��ļ���
// Parameter : 
// Return    : const char*                                      -- �ļ���
// Notes     : 
const char* CFile::GetCurrFile()
{
    try{
        // ��ȡ��ǰģ���ļ���
        char szBuf[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, szBuf, MAX_PATH);
        mstrFileName = szBuf;

        // ��ȡ��ǰ�ļ���
        memset(szBuf, 0, MAX_PATH);
        GetFileBase(mstrFileName.c_str(), szBuf, MAX_PATH);
        mstrFileBase = szBuf;

        //��ȡ�ļ�·��
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
// Brief     : ��ȡ��ǰ��ִ���ļ����ڵ�·��
// Parameter : 
// Return    : const char*                                          -- �ļ�·��
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