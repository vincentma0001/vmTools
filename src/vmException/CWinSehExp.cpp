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
// Brief     : ��SEH����ת��Ϊ�Զ����쳣��
// Parameter :  CWinSeh& seh,                                   -- SEH����
//              const char* szFunc,                             -- �����쳣�ĺ�����
//              const unsigned long culLine /*= __LINE__*/,     -- �����쳣���ļ�����
//              const char* szFile /*= __FILE__*/,              -- �����쳣���ļ���
//              const char* szTime /*= NULL */                  -- �쳣������ʱ��
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