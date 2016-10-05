/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTestFrame.cpp
// Version 		: 1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 30/11/2015 13:25:48
// Modify time 	: 30/11/2015 15:19:28
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
#include <string>
#include <sstream>
#include "stCmd.h"
#include "CAbsTestFrame.h"
#include "CTestCaseFactory.h"
#include "CComCase.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Run
// Full name : CAbsTestFrame::Run
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : bool
// Notes     : 
bool CAbsTestFrame::Run()
{
    if( !Initialize() )
        return false;

    while( mbIsExit == true )
    {
        // 前置操作，准备操作环境
        if( Begin() == false )
            break;
        //{   m_bIsExit = false; OnBeginFailed(); break;}

            // 对用户输入的命令行进行解析
            stCmd strCmdTmp;
            bool bRtForAI = AnalyzeInput( strCmdTmp );
            if ( bRtForAI == false )
                break;

            // 获取测试事件
            CAbsTestCase* pEvent = mpTestCaseFactory->GetCase( strCmdTmp.mstrCmdName );
            if( pEvent != NULL )
            {
                // 执行测试事件操作
                pEvent->OnExcute( strCmdTmp );
            }else
            {
                // 对获取测试事件失败情况进行处理
                std::cout << "Can not fine command ( " << strCmdTmp.mstrCmdName << " )" << std::endl; 
            } // End of # if( pEvent ... #

        // 后置操作，清理/重置操作环境
        if( Finish() == false )
            break;
        //{   m_bIsExit = false; OnFinishFailed(); break; }
    } // End of ## while( ... ##

    Release();

    return true;
} // End of function Run() 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AnalyzeInput
// Full name : CAbsTestFrame::AnalyzeInput
// Access    : private 
// Brief     : 对用户输入命令行进行解析
// Parameter : StuCmd& stuCmd 用于存储解析结果
// Return    : true     解析成功
//             false    解析失败
// Notes     : 
bool CAbsTestFrame::AnalyzeInput(stCmd& stuCmd)
{
    char cTmpBuf[1024];
    memset( cTmpBuf,0,sizeof(cTmpBuf) );
    std::cin.getline( cTmpBuf,1024 );
    std::stringstream  ssBuf( cTmpBuf );
    if ( ssBuf.eof() )
    { return false; }
    else
    { ssBuf >> stuCmd.mstrCmdName; }

    while( !ssBuf.eof() )
    {
        //char cTmp = ssBuf.();
        std::string strTmp;
        //if ( cTmp == '"' )
        //{
        //    strTmp = ssBuf.str(); 
        //    stuCmd.m_listCmdParams.push_back( strTmp );
        //    ssBuf.clear();
        //} // End of if
        //else
        //{
            ssBuf >> strTmp ;
            stuCmd.mlistCmdParams.push_back( strTmp );
        //} // end of if () else
        
    } // end of while( !ssBuf...

    return true;
}  // End of function AnalyzeInput(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : RegEvent
// Full name : CAbsTestFrame::RegEvent
// Access    : public 
// Brief     : 
// Parameter : CAbsTestEvent& testEvent
// Return    : bool
// Notes     : 
bool CAbsTestFrame::RegCase(const CAbsTestCase* const pEvent)
{
    int iEventNamelen = const_cast<CAbsTestCase*>(pEvent)->GetCaseName().length();
    if (  iEventNamelen > miMaxCmdLen )
        return false;
    return mpTestCaseFactory->RegCase( pEvent );
} // End of function RegEvent(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Initialize
// Full name : CAbsTestFrame::Initialize
// Access    : private 
// Brief     : 
// Parameter : void
// Return    : bool
// Notes     : 
bool CAbsTestFrame::Initialize(void)
{
    CStopCase* pStop = new CStopCase( "Stop", mbIsExit );
    mpTestCaseFactory->RegCase( pStop );
    CHelpCase* pHelp = new CHelpCase( "Help", *mpTestCaseFactory, miCmdNumForLine, miMaxCmdLen );
    mpTestCaseFactory->RegCase( pHelp );

    bool bRetForInit = OnInit();
    
    return bRetForInit;
} // End of function Initialize(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Begin
// Full name : CAbsTestFrame::Begin
// Access    : private 
// Brief     : 用于命令开始时显示
// Parameter : void
// Return    : bool
// Notes     : 
bool CAbsTestFrame::Begin(void)
{
    std::cout << "[ cmd ]# ";

    return OnBegin();
} // End of function Begin(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Release
// Full name : CAbsTestFrame::Release
// Access    : private 
// Brief     : 用于测试框架结束时清理操作
// Parameter : void
// Return    : void
// Notes     : 
void CAbsTestFrame::Release(void)
{
    OnRelease();
} // End of function Release(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Finish
// Full name : CAbsTestFrame::Finish
// Access    : private 
// Brief     : 用于命令结束时显示
// Parameter : void
// Return    : bool
// Notes     : 
bool CAbsTestFrame::Finish(void)
{
    return OnFinish();
} // End of function Finish(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CAbsTestFrame
// Full name : CAbsTestFrame::CAbsTestFrame
// Access    : public 
// Brief     : 
// Parameter : const int& ciMaxCmdLen/*=20*/, const int& ciCmdNumForLine/*=3 */
// Return    : 
// Notes     : 
CAbsTestFrame::CAbsTestFrame(const int& ciMaxCmdLen/*=20*/, 
    const int& ciCmdNumForLine/*=3 */) 
    :mbIsExit(true),
    miMaxCmdLen(ciMaxCmdLen),
    miCmdNumForLine(ciCmdNumForLine)
{
    mpTestCaseFactory = new CTestCaseFactory;
} // End of function CAbsTestFrame(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CAbsTestFrame
// Full name : CAbsTestFrame::~CAbsTestFrame
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CAbsTestFrame::~CAbsTestFrame()
{
    if ( mpTestCaseFactory != NULL )
    {
        delete mpTestCaseFactory;
    }
    
} // End of function ~CAbsTestFrame(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ctestframe.cpp...
/////////////////////////////////////////////////////////////////////////////////////////
