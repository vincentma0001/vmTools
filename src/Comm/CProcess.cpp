/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CProcess.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 20/9/2016 8:48:00
// Modify time 	: 20/9/2016 8:48:00
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <windows.h>
#include <CWinError.H>
#include <CException.h>
#include "CProcess.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Start
// Full name : CProcess::Start
// Access    : public 
// Brief     : 
// Parameter : const char* pAppName, const char* pCmdLine,
// Return    : void
// Notes     : 
void CProcess::Start(const char* pAppName, char* pCmdLine)
{
	ZeroMemory( &mProcessInfo, sizeof(mProcessInfo) );
	ZeroMemory( &mStartupInfo, sizeof(mStartupInfo) );
	mStartupInfo.cb = sizeof(mStartupInfo);
	BOOL lbRet = CreateProcess( pAppName, pCmdLine, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &mStartupInfo, &mProcessInfo );
	if ( lbRet == FALSE )
	{
		CWinError loWinErr;
		throw CEXP( "CProcess::Start(), CreateProcess failed(%d:%s)!", loWinErr.GetErrorCode(), loWinErr.GetErrorInfo());
	}

// 	::CloseHandle( mProcessInfo.hProcess );
// 	::CloseHandle( mProcessInfo.hThread);
} // End of function Start(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetProcessHandle
// Full name : CProcess::GetProcessHandle
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : HANDLE
// Notes     : 
HANDLE CProcess::GetProcessHandle()
{
	return mProcessInfo.hProcess;
} // End of function GetProcessHandle(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetThreadHandle
// Full name : CProcess::GetThreadHandle
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : HANDLE
// Notes     : 
HANDLE CProcess::GetThreadHandle()
{
	return mProcessInfo.hThread;
} // End of function GetThreadHandle(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetThreadHandle
// Full name : CProcess::GetThreadHandle
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : DWORD
// Notes     : 
DWORD CProcess::GetThreadID()
{
	return mProcessInfo.dwThreadId;
} // End of function GetThreadHandle(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Wait
// Full name : CProcess::Wait
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CProcess::Wait() const
{
	if ( !Wait(INFINITE) )
	{
		throw CEXP( "CProcess::Wait(), Unexpected timeout on infinite wait" );
	} // end of if
} // End of function Wait(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Wait
// Full name : CProcess::Wait
// Access    : public 
// Brief     : 
// Parameter : DWORD timeoutMillis
// Return    : bool
// Notes     : 
bool CProcess::Wait(DWORD timeoutMillis) const
{
	bool ok;
	
	DWORD result = ::WaitForSingleObject(mProcessInfo.hProcess, timeoutMillis);
	
	if (result == WAIT_TIMEOUT)
	{
		ok = false;
	}
	else if ( result == WAIT_OBJECT_0 )
	{
		ok = true;
	} // end of else if
	else
	{
		CWinError loWinErr;
		throw CEXP( "CProcess::Wait(), WaitForSingleObject failed(%d:%s)!", loWinErr.GetErrorCode(), loWinErr.GetErrorInfo());
	} // end of if
	
	return ok;
} // End of function Wait(...
///////////////////////////////////////////////////////////////////////////////////////// 

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Close
// Full name : CProcess::Close
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CProcess::Close()
{
	CloseHandle( mProcessInfo.hProcess );
	CloseHandle( mProcessInfo.hThread );
} // End of function Close(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetProcessID
// Full name : CProcess::GetProcessID
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : DWORD
// Notes     : 
DWORD CProcess::GetProcessID()
{
	return mProcessInfo.dwProcessId;
} // End of function GetProcessID(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CProcess.cpp
/////////////////////////////////////////////////////////////////////////////////////////
