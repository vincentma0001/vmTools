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

// �쳣������
#   define vExp                                                                vm::CException( __FUNCTION__ )

/////////////////////////////////////////////////////////////////////////////////////////
// namespace
namespace vm {

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CException
//        Notes : �Զ����쳣��¼�쳣��Ϣ
//
/////////////////////////////////////////////////////////////////////////////////////////
class CException
{
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
public:
    // Where
    unsigned long       mulLine;                // �쳣�������ļ�����
    std::string         mstrFile;               // �쳣�������ļ���
	std::string			mstrFuncName;			// �쳣����ʱ�ĺ�����

    // When
    std::string         mstrTime;               // �쳣������ʱ��

    // What
    std::string         mstrMsg;                // �쳣��Ϣ

    // Buffer
    std::stringstream    mstBuf;                // ����

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
    // �����ʽ����Ϣ
    // �쳣��ʽ�滻�ַ����壺
    //             %M                -- �쳣�����ĺ�����
    //             %L                -- �쳣����������
    //             %F                -- �쳣�������ļ���
    //             %T                -- �쳣����
    //             %C                -- �쳣����
    //             %I                -- �쳣��Ϣ
    //             %D                -- �쳣������ʱ��
    virtual const char* Format( const char* szFormat="[%D][%M:%L][%T:%C] %I [%F]" );

}; // End of class CException
/////////////////////////////////////////////////////////////////////////////////////////

}; // End of namespace JL

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_CEXCEPTION_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CException.h
/////////////////////////////////////////////////////////////////////////////////////////
