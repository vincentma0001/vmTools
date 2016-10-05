/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTestEventFactory.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 30/11/2015 19:08:32
// Modify time 	: 1/12/2015 12:11:53
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
#include <string>
#include "CAbsTestCase.h"
#include "CTestCaseFactory.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////
// Name      : RegEvent
// Full name : CTestEventFactory::RegEvent
// Access    : public 
// Brief     : 
// Parameter : const std::string& strEventName, CAbsTestEvent& cEvent
// Return    : bool
// Notes     : 
bool CTestCaseFactory::RegCase( const CAbsTestCase* const pCase )
{
    return mmapEvents.AddData( const_cast<CAbsTestCase*>(pCase)->GetCaseName(), 
                                const_cast<CAbsTestCase*>(pCase) );
}  // End of function 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetEvent
// Full name : CTestEventFactory::GetEvent
// Access    : public 
// Brief     : 
// Parameter : const std::string& strEventName
// Return    : CAbsTestEvent*
// Notes     : 
CAbsTestCase* CTestCaseFactory::GetCase(const std::string& strCaseName)
{
    CAbsTestCase** ppEvent = mmapEvents.GetData( strCaseName );
    if ( ppEvent == NULL )
    { return NULL;} // End of if
    CAbsTestCase* pEvent = (*ppEvent);
    return pEvent;
}  // End of function GetEvent(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFirstEvent
// Full name : CTestEventFactory::GetFirstEvent
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : CTestEventFactory::meItor
// Notes     : 
CTestCaseFactory::tItor CTestCaseFactory::GetFirstCase(void)
{
    return mmapEvents.GetFirst();
} // End of function GetFirstEvent(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetLastEvent
// Full name : CTestEventFactory::GetLastEvent
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : CTestEventFactory::meItor
// Notes     : 
CTestCaseFactory::tItor CTestCaseFactory::GetLastCase(void)
{
    return mmapEvents.GetLast();
} // End of function GetLastEvent(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CTestEventFactory
// Full name : CTestEventFactory::~CTestEventFactory
// Access    : public 
// Brief     : 析构函数
// Parameter : 无
// Return    : 无
// Notes     : 
CTestCaseFactory::~CTestCaseFactory()
{
    tItor iTmp = mmapEvents.GetFirst();
    for ( ;iTmp!=mmapEvents.GetLast();iTmp++ )
    {
        CAbsTestCase* pEvent =(*iTmp).second;
        delete pEvent;
    } // End of for
} // End of function ~CTestEventFactory(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTestEventFactory.cpp...
/////////////////////////////////////////////////////////////////////////////////////////
