/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CException.h
// Version      : 2.0.0.0
// Brief        : 
// Auther       : v.m.
// Create time  : 9/1/2016 20:26:26
// Modify time  : 5/3/2017 20:26:26
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

#ifndef __VM_TOOLS_CEXCEPTION_H__
#define __VM_TOOLS_CEXCEPTION_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>
#include <sstream>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define

// 异常创建宏
#   define vExp                                                                vm::CException( __FUNCTION__ )

/////////////////////////////////////////////////////////////////////////////////////////
// namespace
namespace vm {

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CException
//        Notes : 自定义异常记录异常信息
//
/////////////////////////////////////////////////////////////////////////////////////////
class CException
{
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
public:
    // Where
    unsigned long       mulLine;                // 异常产生的文件行数
    std::string         mstrFile;               // 异常产生的文件名
	std::string			mstrFuncName;			// 异常产生时的函数名

    // When
    std::string         mstrTime;               // 异常产生的时间

    // What
    std::string         mstrMsg;                // 异常信息

    // Buffer
    std::stringstream    mstBuf;                // 缓存

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
	CException(	const char* const szFunc=NULL, 
		const unsigned long culLine = __LINE__,
		const char* szFile = __FILE__ )
	{
		_VERIFY_(szFile);

		mulLine = culLine;
		mstrFile = vm::CFile::GetFileBase(szFile);

		mstrTime = vm::CTime::GetCurrTime().ToStringFull();

		mstrMsg = "";
		mstBuf.clear();
	}
	// Destruct define
    virtual ~CException(){};
    CException( const CException& ex );
    // Evaluation
	CException& operator=(const CException& ex)
	{
		mulLine = ex.mulLine;
		mstrFile = ex.mstrFile;
		mstrTime = ex.mstrTime;
		mstrMsg = ex.mstrMsg;
		mstBuf.clear();
	}


public:
	CException& operator()(const char* szFormat, ...);
	CException& operator()(const CException& ex)
	{
		mstrMsg = ex.mstrMsg;
	}
	CException& operator()(const std::exception& ex)
	{
		mstrMsg = ex.what();
	}
	CException& operator()(const CWinSeh& seh)
	{
		mstrMsg = seh.what();
	}

public:
	const char* what()
	{
		return mstrMsg.c_str();
	}

	const char* when()
	{
		return mstrTime.c_str();
	}

	const char* where()
	{
		mstBuf.clear();
		mstBuf << mulLine << ":" << mstrFile.c_str() << std::ends;
		return mstBuf.str().c_str();
	}
/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 输出格式化信息
    // 异常格式替换字符定义：
    //             %M                -- 异常产生的函数名
    //             %L                -- 异常产生的行数
    //             %F                -- 异常产生的文件名
    //             %T                -- 异常类型
    //             %C                -- 异常代码
    //             %I                -- 异常信息
    //             %D                -- 异常产生的时间
    virtual const char* Format( const char* szFormat="[%D][%M:%L][%T:%C] %I [%F]" );

}; // End of class CException
/////////////////////////////////////////////////////////////////////////////////////////

}; // End of namespace JL

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_CEXCEPTION_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CException.h
/////////////////////////////////////////////////////////////////////////////////////////
