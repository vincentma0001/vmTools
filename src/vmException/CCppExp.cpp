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
// Brief     : 构造函数
// Parameter : std::exception& ex,                              -- C++异常信息
//             const char* szFunc,                              -- 异常产生的函数
//             const unsigned long culLine /*= __LINE__*/,      -- 异常产生的行数
//             const char* szFile /*= __FILE__*/,               -- 异常产生的文件
//             const char* szTime /*= NULL */                   -- 异常产生的时间
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