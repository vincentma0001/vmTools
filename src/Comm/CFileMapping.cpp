/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CFileMapping.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 20/9/2016 14:03:35
// Modify time 	: 20/9/2016 14:03:35
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
#include "CFileMapping.h"
#include "CException.h"
#include "VerifyDef.h"
#include "CWinError.h"

/////////////////////////////////////////////////////////////////////////////////////////
// macro define

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace

/////////////////////////////////////////////////////////////////////////////////////////
// class release 

/////////////////////////////////////////////////////////////////////////////////////////
// Todo : add application


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CFileMapping
// Full name : CFileMapping::CFileMapping
// Access    : private 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CFileMapping::CFileMapping()
{
	m_hFileHandle = NULL;
	m_pViewOfFile = NULL;
	m_nFileSize = 0;
	m_nFileHeadOffset = 0;
} // End of function CFileMapping(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Initialize
// Full name : CFileMapping::Initialize
// Access    : public 
// Brief     : 
// Parameter : LPCTSTR pFileName, int pFileSize
// Return    : bool
// Notes     : 
bool CFileMapping::Initialize(LPCTSTR pFileName, int pFileSize)
{
	m_nFileSize = pFileSize;
	// creates as well as opens a file map.
	m_hFileHandle = OpenFileMapping( FILE_MAP_ALL_ACCESS, 0, pFileName);
	if ( m_hFileHandle==NULL )
	{
		m_hFileHandle = CreateFileMapping(	INVALID_HANDLE_VALUE,               // handle to file
			NULL,								// security
			PAGE_READWRITE,                     // protection
			0,						            // high-order DWORD of size
			m_nFileSize,			            // low-order DWORD of size
			pFileName	  	                    // object name
		);
	}

	
	if( !m_hFileHandle ) {
		throw CEXP("CFileMapping::Initialize(), Unable to create file mapping. Error is %d", GetLastError());
	}
	
	// Map the file into the current address space.
	m_pViewOfFile = MapViewOfFile(	m_hFileHandle,							// handle to file-mapping object
		FILE_MAP_ALL_ACCESS,					// access mode
		0,										// high-order DWORD of offset
		0,										// low-order DWORD of offset
		0										// number of bytes to map
		);
	if( m_pViewOfFile == NULL ) {
		throw CEXP("CFileMapping::Initialize(), Unable to map to the current address space. Error is %d", GetLastError());
		return false;
	}
	return true;
} // End of function Initialize(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Write
// Full name : CFileMapping::Write
// Access    : public 
// Brief     : 
// Parameter : char* pData
// Return    : void
// Notes     : 
void CFileMapping::Write(char* pData, unsigned int uiDataLen)
{
	unsigned int* lpDatelen = NULL;
	char* lpData			 = NULL;

	try
	{
		lpDatelen = new(m_pViewOfFile) unsigned int;
		lpData = (char*)m_pViewOfFile+sizeof(unsigned int)+(*lpDatelen);
	}
	catch ( ... )
	{
		throw CEXP( "CFileMapping::Write(), 1" );
	}
	
	try
	{
		memcpy( lpData, pData, uiDataLen );
	}
	catch ( ... )
	{
		CWinError loError;
		throw CEXP( "CFileMapping::Write(), 2 lpData(0x%X) m_pViewOfFile(0x%X) lpDatelen(0x%X:%d) Err(%d)", lpData, m_pViewOfFile, lpDatelen, *lpDatelen, loError.GetErrorCode() );
	}

	try
	{
		*lpDatelen += uiDataLen;
		m_ulDatelen = *lpDatelen;
	}
	catch ( ... )
	{
		throw CEXP( "CFileMapping::Write(), 3" );
	}

} // End of function Write(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Read
// Full name : CFileMapping::Read
// Access    : public 
// Brief     : 
// Parameter : char*& pBuffer
// Return    : void
// Notes     : 
unsigned long CFileMapping::Read(char* pBuffer, unsigned long uiBufLen, unsigned long ulOffset)
{
	char* lpData = (char*)m_pViewOfFile+sizeof(unsigned int) + ulOffset;
	
	unsigned long luiLenDiff = m_ulDatelen-ulOffset;
	unsigned long luiDatalen = luiLenDiff>uiBufLen?uiBufLen:luiLenDiff;

	memcpy( pBuffer, lpData, luiDatalen );
	return luiDatalen;
} // End of function Read(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetDataLen
// Full name : CFileMapping::GetDataLen
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : unsigned int
// Notes     : 
unsigned int CFileMapping::GetDataLen()
{
	unsigned int* lpLen = new(m_pViewOfFile) unsigned int;
	m_ulDatelen = *lpLen;
	return m_ulDatelen;
} // End of function GetDataLen(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Reset
// Full name : CFileMapping::Reset
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CFileMapping::Reset()
{
	unsigned long* lpLen = new(m_pViewOfFile) unsigned long;
	*lpLen=0;
	m_ulDatelen = *lpLen;
} // End of function Reset(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CFileMapping
// Full name : CFileMapping::~CFileMapping
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CFileMapping::~CFileMapping()
{
	if( m_pViewOfFile != NULL ){
		if( UnmapViewOfFile(m_pViewOfFile) == 0)
			throw CEXP("CFileMapping::~CFileMapping(), Unable to unmap view of file. Error is %d", GetLastError());
	}
	if( m_hFileHandle!= NULL)
		CloseHandle(m_hFileHandle);
} // End of function ~CFileMapping(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CFileMapping.cpp
/////////////////////////////////////////////////////////////////////////////////////////
