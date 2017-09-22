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
//        Notes : 此类包含了有关文件的操作，以及信息
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
C 文件操作
fflush ：清除读写缓冲区，需要立即把输出缓冲区的数据进行物理写入时
int fseek( FILE *stream, long offset, int origin );
第一个参数stream为文件指针
第二个参数offset为偏移量，正数表示正向偏移，负数表示负向偏移
第三个参数origin设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET
SEEK_SET： 文件开头
SEEK_CUR： 当前位置
SEEK_END： 文件结尾
其中SEEK_SET,SEEK_CUR和SEEK_END依次为0，1和2.
简言之：
fseek(fp,100L,0);把stream指针移动到离文件开头100字节处；
fseek(fp,100L,1);把stream指针移动到离文件当前位置100字节处；
fseek(fp,-100L,2);把stream指针退回到离文件结尾100字节处。

//*/
