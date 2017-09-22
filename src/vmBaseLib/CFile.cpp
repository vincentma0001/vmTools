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
#include <IMAGEHLP.H>

#pragma comment(lib, "version.lib") 
#pragma comment(lib, "imagehlp.lib")

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

char vm::CFile::mszBuf[MAX_PATH] = {0};

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CFile
// Full name : CFile::CFile
// Access    : private 
// Brief     : ????
// Parameter : 
// Return    : 
// Notes     : 
CFile::CFile() :mpFile(NULL)
{

} // End of function CFile(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CFile
// Full name : CFile::CFile
// Access    : private 
// Brief     : ????
// Parameter : const char* szFileName                          -- ???
// Return    : 
// Notes     : 
CFile::CFile(const char* szFileName): mpFile(NULL)
{
    try{
        // ????
        _VERIFY_(szFileName);

         // ??????
         mstrFileName = szFileName;
// 
//         // ?????
//         char szBuf[MAX_PATH] = { 0 };
//         GetFileBase(szFileName, szBuf, MAX_PATH);
//         mstrFileBase = szBuf;
// 
//         // ??????
//         memset(szBuf, 0, MAX_PATH);
//         GetFileDir(szFileName, szBuf, MAX_PATH);
//         mstrFileDir = szBuf;

    }catch (vm::CException& ex){
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
// Name      : ~CFile
// Full name : CFile::~CFile
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CFile::~CFile()
{
	if (  mpFile!=NULL)
	{
		::CloseHandle( mpFile );
	}
} // End of function ~CFile(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileBase
// Full name : CFile::GetFileBase
// Access    : public 
// Brief     : ?????(????)
// Parameter : const char* cszFileName,                     -- [in]  ???
//             char* szBuf,                                 -- [out] ?????
//             const unsigned long culMaxBuf                -- [in]  ???????
// Return    : void
// Notes     : 
// void CFile::GetFileBase(const char* cszFileName, char* szBuf, const unsigned long culMaxBuf)
// {
//     try{
//         _VERIFY_2_(cszFileName, szBuf);
// 
//         const char *lp = strrchr(cszFileName, int('\\'));
//         _VERIFY_(lp);
// #if defined (_MSC_VER) && (_MSC_VER<=1300)
//         strcpy( szBuf, lp+1 );
// #else
//         strcpy_s(szBuf, culMaxBuf, lp+1);
// #endif
// 
//     }catch (JL::CException& ex){
//         throw ex;
//     }catch (std::exception& ex){
//         throw CEXP_CPP(ex);
//     }catch (CWinSeh& seh){
//         throw CEXP_SEH(seh);
//     }catch (...){
//         throw CEXP("Get an unknown exception!");
//     }
// } // End of function GetFileBase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileDir
// Full name : CFile::GetFileDir
// Access    : public 
// Brief     : ??????
// Parameter : const char* cszFileName,                         -- [in]  ???
//             char* szBuf,                                     -- [out] ??????
//             const unsigned long culMaxBuf                    -- [in]  ????????
// Return    : void
// Notes     : 
// void CFile::GetFileDir(const char* cszFileName, char* szBuf, const unsigned long culMaxBuf)
// {
//     try{
//         _VERIFY_2_(cszFileName, szBuf);
// 
//         const char *lp = strrchr(cszFileName, int('\\'));
//         _VERIFY_(lp);
// 
//         memcpy(szBuf, cszFileName, (lp - cszFileName));
//     }catch (JL::CException& ex){
//         throw ex;
//     }catch (std::exception& ex){
//         throw CEXP_CPP(ex);
//     }catch (CWinSeh& seh){
//         throw CEXP_SEH(seh);
//     }catch (...){
//         throw CEXP("Get an unknown exception!");
//     }
// } // End of function GetFileDir(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrFile
// Full name : CFile::GetCurrFile
// Access    : public 
// Brief     : ???????????
// Parameter : 
// Return    : const char*                                      -- ???
// Notes     : 
// const char* CFile::GetCurrFile()
// {
//     try{
//         // ?????????
//         char szBuf[MAX_PATH] = { 0 };
//         GetModuleFileName(NULL, szBuf, MAX_PATH);
//         mstrFileName = szBuf;
// 
//         // ???????
//         memset(szBuf, 0, MAX_PATH);
//         GetFileBase(mstrFileName.c_str(), szBuf, MAX_PATH);
//         mstrFileBase = szBuf;
// 
//         //??????
//         memset(szBuf, 0, MAX_PATH);
//         GetFileDir(mstrFileName.c_str(), szBuf, MAX_PATH);
//         mstrFileDir = szBuf;
// 
//         return mstrFileName.c_str();
//     }catch (JL::CException& ex){
//         throw ex;
//     }catch (std::exception& ex){
//         throw CEXP_CPP(ex);
//     }catch (CWinSeh& seh){
//         throw CEXP_SEH(seh);
//     }catch (...){
//         throw CEXP("Get an unknown exception!");
//     }
// } // End of function GetCurrFile(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrDir
// Full name : CFile::GetCurrDir
// Access    : public 
// Brief     : ??????????????
// Parameter : 
// Return    : const char*                                          -- ????
// Notes     : 
// const char* CFile::GetCurrDir()
// {
//     try{
//         GetCurrFile();
// 
//         return mstrFileDir.c_str();
//     }catch( JL::CException& ex ){
//         throw ex;
//     }catch( std::exception& ex ){
//         throw CEXP_CPP(ex);
//     }catch( CWinSeh& seh ){
//         throw CEXP_SEH(seh);
//     }catch( ... ){
//         throw CEXP("Get an unknown exception!");
//     }
// } // End of function GetCurrDir(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrDir
// Full name : CFile::GetCurrDir
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : const char*
// Notes     : 
const char* CFile::GetCurrDir()
{
	// ????
	memset( mszBuf, 0x00, sizeof(mszBuf) );
	
	// ?????????
	char szBuf[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szBuf, MAX_PATH);
	
	// ???????
	const char *lp = strrchr(szBuf, int('\\'));
	_VERIFY_(lp);
	memcpy(mszBuf, szBuf, (lp - szBuf));
	
	return mszBuf;
} // End of function GetCurrDir(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileVersion
// Full name : CFile::GetFileVersion
// Access    : public static 
// Brief     : 
// Parameter : const char* szFileName
// Return    : const char*
// Notes     : 
const char* CFile::GetFileVersion(const char* pFullFileName)
{
	// ???????????,???????????????
	char * lpFileName = NULL;
	char szBuf[MAX_PATH] = { 0 };
	if ( pFullFileName==NULL )
	{
		GetModuleFileName(NULL, szBuf, MAX_PATH);
		lpFileName = szBuf;
	}else
	{
		lpFileName= (char*)pFullFileName;
	}

	//?????
	memset( mszBuf, 0x00, sizeof(mszBuf) );
	
	// ?????  
	DWORD   dwVerHnd =   0;  
	DWORD   dwVerInfoSize   =   ::GetFileVersionInfoSize((char*)lpFileName,   &dwVerHnd);  
	if(dwVerInfoSize)  
	{  
		//   If   we   were   able   to   get   the   information,   process   it:  
		HANDLE     hMem;  
		LPVOID     lpvMem;  
		unsigned   int			uInfoSize   =   0;  
		VS_FIXEDFILEINFO   *	pFileInfo;  
		
		hMem =   ::GlobalAlloc(GMEM_MOVEABLE,   dwVerInfoSize);  
		lpvMem =   ::GlobalLock(hMem);  
		::GetFileVersionInfo((char*)lpFileName,   dwVerHnd,   dwVerInfoSize,   lpvMem);  
		::VerQueryValue(lpvMem,   (LPTSTR)("\\"),   (void**)&pFileInfo,   &uInfoSize);  
		
		WORD   nVer[4];  
		nVer[0]   =   HIWORD(pFileInfo->dwProductVersionMS);    
		nVer[1]   =   LOWORD(pFileInfo->dwProductVersionMS);  
		nVer[2]   =   HIWORD(pFileInfo->dwProductVersionLS);  
		nVer[3]   =   LOWORD(pFileInfo->dwProductVersionLS);   
		
		sprintf( mszBuf, "%d.%d.%d.%d", nVer[0], nVer[1], nVer[2], nVer[3] );
		
		::GlobalUnlock(hMem);  
		::GlobalFree(hMem);  
	}  
	
	return   mszBuf;
} // End of function GetFileVersion(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Open
// Full name : JL::CFile::Open
// Access    : public 
// Brief     : 
// Parameter : LPCSTR szFileName  - ???????? 
//           : DWORD dwOpenType   - ???????
// Return    : void
// Notes     : 
void CFile::Open(LPCSTR szFileName, DWORD dwOpenType)
{
	Close();

	mpFile = ::CreateFile( szFileName, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
	if ( mpFile==INVALID_HANDLE_VALUE )
	{
		CWinErr loError;
		throw CEXP( "CFile::Open(), open file(%s) failed! ErrCode(%d:%s)", szFileName, loError.GetErrCode(), loError.GetErrMsg() );
	}
} // End of function Open(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Close
// Full name : CFile::Close
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CFile::Close()
{
	if ( mpFile!=NULL )
	{
		::CloseHandle(mpFile);
		mpFile=NULL;
	}
} // End of function Close(...
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
	DWORD ldwWrited = 0;
	BOOL lbRet = ::WriteFile( mpFile, pBuffer, dwBuffLen, &ldwWrited, NULL );
	if ( lbRet != TRUE )
	{
		CWinErr loError;
		throw CEXP( "CFile::Write(), write file failed! ErrCode(%d:%s)", loError.GetErrCode(), loError.GetErrMsg() );
	}

	return ldwWrited;
} // End of function Write(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Seek
// Full name : CFile::Seek
// Access    : public 
// Brief     : 
// Parameter : LONG lDistanceToMove/*=0*/, DWORD dwMoveMode/*=FILE_END */
// Return    : void
// Notes     : 
void CFile::Seek(LONG lDistanceToMove/*=0*/, DWORD dwMoveMode/*=FILE_END */)
{
    DWORD ldwRet = ::SetFilePointer( mpFile, lDistanceToMove, 0, dwMoveMode );
} // End of function Seek(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetEnd
// Full name : CFile::SetEnd
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CFile::SetEnd()
{
	BOOL lbRetForSetFileEnd = ::SetEndOfFile( mpFile );
	if ( lbRetForSetFileEnd != TRUE )
	{
		CWinErr loError;
		throw CEXP( "CFile::SetEnd(), set end of file failed! ErrCode(%d:%s)", loError.GetErrCode(), loError.GetErrMsg() );
	}
} // End of function SetEnd(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrFileName
// Full name : CFile::GetCurrFileName
// Access    : public static 
// Brief     : 
// Parameter : 
// Return    : const char*
// Notes     : 
const char* CFile::GetCurrFileName()
{
	// ????
	memset( mszBuf, 0x00, sizeof(mszBuf) );

	// ?????????
	::GetModuleFileName(NULL, mszBuf, MAX_PATH);

	return mszBuf;
} // End of function GetCurrFileName(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrFileBase
// Full name : CFile::GetCurrFileBase
// Access    : public static 
// Brief     : 
// Parameter : const char* pFullFileName
// Return    : const char*
// Notes     : 
const char* CFile::GetFileBase(const char* pFullFileName)
{
	// ???????????,???????????????
	char * lpFileName = NULL;
	char szBuf[MAX_PATH] = { 0 };
	if ( pFullFileName==NULL )
	{
		GetModuleFileName(NULL, szBuf, MAX_PATH);
		lpFileName = szBuf;
	}else
	{
		lpFileName = (char*)pFullFileName;
	}

	// ????
	memset( mszBuf, 0x00, sizeof(mszBuf) );
	
	// ?????
	const char *lp = strrchr(lpFileName, int('\\'));
	_VERIFY_(lp);
#if defined (_MSC_VER) && (_MSC_VER<=1300)
	strcpy( mszBuf, lp+1 );
#else
	strcpy_s(mszBuf, lpFileName, lp+1);
#endif

	return mszBuf;
} // End of function GetCurrFileBase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFileDir
// Full name : CFile::GetFileDir
// Access    : public static 
// Brief     : 
// Parameter : const char* pFullFileName
// Return    : const char*
// Notes     : 
const char* CFile::GetFileDir(const char* pFullFileName)
{
	// ???????????,???????????????
	char * lpFileName = NULL;
	char szBuf[MAX_PATH] = { 0 };
	if ( pFullFileName==NULL )
	{
		GetModuleFileName(NULL, szBuf, MAX_PATH);
		lpFileName = szBuf;
	}else
	{
		lpFileName = (char*)pFullFileName;
	}

	// ????
	memset( mszBuf, 0x00, sizeof(mszBuf) );
	
	// ???????
	const char *lp = strrchr(lpFileName, int('\\'));
	_VERIFY_(lp);
	memcpy(mszBuf, lpFileName, (lp - lpFileName));
	
	return mszBuf;
} // End of function GetFileDir(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : MakeSureDir
// Full name : CFile::MakeSureDir
// Access    : public static 
// Brief     : 
// Parameter : const char* pFullFileName
// Return    : const bool
// Notes     : 
const BOOL CFile::MakeSureDir(const char* pFullFileName)
{
	return MakeSureDirectoryPathExists( pFullFileName );
} // End of function MakeSureDir(...
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace JL
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CFile.cpp...
/////////////////////////////////////////////////////////////////////////////////////////