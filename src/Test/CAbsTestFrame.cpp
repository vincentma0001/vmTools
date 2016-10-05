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
        // ǰ�ò�����׼����������
        if( Begin() == false )
            break;
        //{   m_bIsExit = false; OnBeginFailed(); break;}

            // ���û�����������н��н���
            stCmd strCmdTmp;
            bool bRtForAI = AnalyzeInput( strCmdTmp );
            if ( bRtForAI == false )
                break;

            // ��ȡ�����¼�
            CAbsTestCase* pEvent = mpTestCaseFactory->GetCase( strCmdTmp.mstrCmdName );
            if( pEvent != NULL )
            {
                // ִ�в����¼�����
                pEvent->OnExcute( strCmdTmp );
            }else
            {
                // �Ի�ȡ�����¼�ʧ��������д���
                std::cout << "Can not fine command ( " << strCmdTmp.mstrCmdName << " )" << std::endl; 
            } // End of # if( pEvent ... #

        // ���ò���������/���ò�������
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
// Brief     : ���û����������н��н���
// Parameter : StuCmd& stuCmd ���ڴ洢�������
// Return    : true     �����ɹ�
//             false    ����ʧ��
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
// Brief     : �������ʼʱ��ʾ
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
// Brief     : ���ڲ��Կ�ܽ���ʱ�������
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
// Brief     : �����������ʱ��ʾ
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
