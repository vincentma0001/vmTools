/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CFile.h
// Version 		: 0.0.1.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 10/1/2016 16:42:37
// Modify time 	: 10/1/2016 16:42:37
// Note 		:
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

#ifndef __VM_TOOLS_CFILE_H__
#define __VM_TOOLS_CFILE_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#ifndef _WINDOWS_
#	error this file need #include <windows.h>
#endif

#include <string>

/////////////////////////////////////////////////////////////////////////////////////////
// namespace JL
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CFile
//        Notes : ����������й��ļ��Ĳ������Լ���Ϣ
//
/////////////////////////////////////////////////////////////////////////////////////////
class CFile
{
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
public:
private:
	HANDLE				mpFile;
	static char			mszBuf[MAX_PATH];

	std::string			mstrFileName;
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Default Construct
    CFile();
    // Construct define
    CFile(const char* szFileName);
    // Destruct define
    virtual ~CFile();
private:
    // No Copy
    CFile(const CFile& obj){};
    // No Evaluation
    CFile& operator = (const CFile& obj){}

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :

public:
	VOID Open( LPCSTR szFileName, DWORD dwOpenType=OPEN_ALWAYS);
	VOID Close( );

	DWORD Write( LPVOID pBuffer, DWORD dwBuffLen );
	
    void Seek( LONG lDistanceToMove=0, DWORD dwMoveMode=FILE_END );
	void SetEnd();

public:
	static const char* GetCurrFileName();
	static const char* GetCurrDir();

	static const char* GetFileVersion	( const char* pFullFileName=NULL );
	static const char* GetFileBase		( const char* pFullFileName=NULL );
	static const char* GetFileDir		( const char* pFullFileName=NULL );
	static const BOOL  MakeSureDir		( const char* pFullFileName );

}; // End of class CFile
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace JL
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_CFILE_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CFile.h
/////////////////////////////////////////////////////////////////////////////////////////

/*
C �ļ�����
fflush �������д����������Ҫ��������������������ݽ�������д��ʱ
int fseek( FILE *stream, long offset, int origin );
��һ������streamΪ�ļ�ָ��
�ڶ�������offsetΪƫ������������ʾ����ƫ�ƣ�������ʾ����ƫ��
����������origin�趨���ļ������￪ʼƫ��,����ȡֵΪ��SEEK_CUR�� SEEK_END �� SEEK_SET
SEEK_SET�� �ļ���ͷ
SEEK_CUR�� ��ǰλ��
SEEK_END�� �ļ���β
����SEEK_SET,SEEK_CUR��SEEK_END����Ϊ0��1��2.
����֮��
fseek(fp,100L,0);��streamָ���ƶ������ļ���ͷ100�ֽڴ���
fseek(fp,100L,1);��streamָ���ƶ������ļ���ǰλ��100�ֽڴ���
fseek(fp,-100L,2);��streamָ���˻ص����ļ���β100�ֽڴ���

//*/
