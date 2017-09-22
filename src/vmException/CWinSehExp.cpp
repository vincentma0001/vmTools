/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinSehExp.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 23/1/2016 10:46:38
// Modify time 	: 23/1/2016 10:46:38
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

#include "VerifyDef.h"
#include "CWinSehExp.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinSehExp
// Full name : CWinSehExp::CWinSehExp
// Access    : public 
// Brief     : 将SEH对象转换为自定义异常。
// Parameter :  CWinSeh& seh,                                   -- SEH对象
//              const char* szFunc,                             -- 产生异常的函数名
//              const unsigned long culLine /*= __LINE__*/,     -- 产生异常的文件行数
//              const char* szFile /*= __FILE__*/,              -- 产生异常的文件名
//              const char* szTime /*= NULL */                  -- 异常产生的时间
// Return    : 
// Notes     : 
CWinSehExp::CWinSehExp( CWinSeh& seh, 
                        const char* szFunc, 
                        const unsigned long culLine /*= __LINE__*/, 
                        const char* szFile /*= __FILE__*/, 
                        const char* szTime /*= NULL */) 
                        : CException( seh.GetExpDes(), 
                                      szFunc,
                                      ET_SYSTEM, 
                                      seh.GetExpCode(), 
                                      culLine, 
                                      szFile,
                                      szTime )
{
} // End of function CException(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinSehExp.cpp
/////////////////////////////////////////////////////////////////////////////////////////