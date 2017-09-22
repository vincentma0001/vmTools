/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CComEvent.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 1/12/2015 8:06:33
// Modify time 	: 1/12/2015 12:12:16
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
#include <iostream>
#include <iomanip>
#include "CComCase.h"
#include "CTestCaseFactory.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////
// Name      : OnExcute
// Full name : CStopEvent::OnExcute
// Access    : virtual public 
// Brief     : 
// Parameter : const StuCmd& stuCmd
// Return    : void
// Notes     : 
void CStopCase::OnExcute(const stCmd& stuCmd)
{
    m_bIsExit = false;
} // End of function OnExcute(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CStopCase
// Full name : CStopCase::CStopCase
// Access    : public 
// Brief     : 
// Parameter : const std::string& strEventName, bool& bIsExit
// Return    : 
// Notes     : 
CStopCase::CStopCase(const std::string& strEventName, bool& bIsExit) 
    :CAbsTestCase(strEventName),
    m_bIsExit(bIsExit)
{

} // End of function CStopCase(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CStopCase
// Full name : CStopCase::~CStopCase
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CStopCase::~CStopCase()
{

} // End of function ~CStopCase(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : OnExcute
// Full name : CHelpEvent::OnExcute
// Access    : virtual public 
// Brief     : 
// Parameter : const StuCmd& stuCmd
// Return    : void
// Notes     : 
void CHelpCase::OnExcute(const stCmd& stuCmd)
{
    int iCmdNumForOneLine = 1; // 已显示命令名的计数
    CTestCaseFactory::tItor itTmp = mTestCaseFactory.GetFirstCase();
    
    for ( ;itTmp!=mTestCaseFactory.GetLastCase();itTmp++,iCmdNumForOneLine++ )
    {
        // 输出以注册的命令名
        std::cout << std::setw( mciCmdMaxLen ) << std::setiosflags( std::ios::left ) << itTmp->second->GetCaseName().c_str() ;

        // 命令名分行显示
        if ( iCmdNumForOneLine >= mciCmdNumForLine )
        {
            std::cout << std::endl; // 分行操作
            iCmdNumForOneLine = 0;  // 重置已显示的命令计数
        } // End of if
    } // End of for

    std::cout << std::endl;
} // End of function OnExcute(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CHelpCase
// Full name : CHelpCase::CHelpCase
// Access    : public 
// Brief     : 
// Parameter : const std::string& strEventName, CTestCaseFactory& teFactory, const int& iCmdNumForLine, const int& iCmdMaxLen
// Return    : 
// Notes     : 
CHelpCase::CHelpCase(const std::string& strEventName, 
    CTestCaseFactory& teFactory, 
    const int& iCmdNumForLine, 
    const int& iCmdMaxLen) 
    :CAbsTestCase(strEventName),
    mTestCaseFactory(teFactory),
    mciCmdNumForLine(iCmdNumForLine),
    mciCmdMaxLen(iCmdMaxLen)
{

} // End of function CHelpCase(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CHelpCase
// Full name : CHelpCase::~CHelpCase
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CHelpCase::~CHelpCase()
{

} // End of function ~CHelpCase(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CComEvent.cpp...
/////////////////////////////////////////////////////////////////////////////////////////
