/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CWinConsole.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/14 22:09:43
// Modify time  : 2020/01/14 22:09:43
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

#ifndef __UT_CWINCONSOLE_H__
#define __UT_CWINCONSOLE_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Disable warning
// Example : #pragma warning(disable:4996)
// #if defined (_MSC_VER)
// #   pragma warning(disable:4996)
// #endif

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included
#include <vmLibBase/vmUtil.h>
#include <vmLibBase/CUnitTestFrame.h>
#include <vmLibErr.h>

// test function's files
#include <vmLibIPC/CWinConsole.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CWinConsole_t1 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vm::CWinConsole loWinConsole;

    loWinConsole.SetTitile(vT("Console!"));
    //loWinConsole.SetWinCentrePos(800, 600);
    //loWinConsole.SetWinSize( 0,768, 0, 1024 );
    loWinConsole.Write( 0x01, "0x01 this is a test!\n" );
    loWinConsole.Write( 0x02, "0x02 this is a test!\n" );
    loWinConsole.Write( 0x03, "0x03 this is a test!\n" );
    loWinConsole.Write( 0x04, "0x04 this is a test!\n" );
    loWinConsole.Write( 0x05, "0x05 this is a test!\n" );
    loWinConsole.Write( 0x06, "0x06 this is a test!\n" );
    loWinConsole.Write( 0x07, "0x07 this is a test!\n" );
    loWinConsole.Write( 0x08, "0x08 this is a test!\n" );
    loWinConsole.Write( 0x09, "0x09 this is a test!\n" );
    loWinConsole.Write( 0x0a, "0x0a this is a test!\n" );
    loWinConsole.Write( 0x0b, "0x0b this is a test!\n" );
    loWinConsole.Write( 0x0c, "0x0c this is a test!\n" );
    loWinConsole.Write( 0x0d, "0x0d this is a test!\n" );
    loWinConsole.Write( 0x0e, "0x0e this is a test!\n" );
    loWinConsole.Write( 0x0f, "0x0f this is a test!\n" );
    loWinConsole.Write( 0x10, "0x0f this is a test!\n" );
    if (loWinConsole.HasError())
    {
       vm::utLogLine( "Error : %d - %s", loWinConsole.toErrCode(), vm::CErrno::MsgErrno(loWinConsole.toErrCode()) );
    }


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CWinConsole )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CWinConsole_t1);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CWINCONSOLE_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CWinConsole.h
/////////////////////////////////////////////////////////////////////////////////////////