/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CCppExp.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 23/1/2016 11:09:24
// Modify time 	: 23/1/2016 11:09:24
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <Windows.h>
#include "CCppExp.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CException
// Full name : CException::CException
// Access    : public 
// Brief     : ���캯��
// Parameter : std::exception& ex,                              -- C++�쳣��Ϣ
//             const char* szFunc,                              -- �쳣�����ĺ���
//             const unsigned long culLine /*= __LINE__*/,      -- �쳣����������
//             const char* szFile /*= __FILE__*/,               -- �쳣�������ļ�
//             const char* szTime /*= NULL */                   -- �쳣������ʱ��
// Return    : 
// Notes     : 
CCppExp::CCppExp( std::exception& ex, 
                  const char* szFunc, 
                  const unsigned long culLine /*= __LINE__*/, 
                  const char* szFile /*= __FILE__*/, 
                  const char* szTime /*= NULL */)
                  :CException( ex.what(),
                               szFunc,
                               ET_CPP,
                               ET_CPP,
                               culLine,
                               szFile,
                               szTime )
{

} // End of function CException(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CCppExp.cpp
/////////////////////////////////////////////////////////////////////////////////////////