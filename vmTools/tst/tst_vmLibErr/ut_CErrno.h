/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CErrno.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/14 20:25:41
// Modify time  : 2020/01/14 20:25:41
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

#ifndef __UT_CERRNO_H__
#define __UT_CERRNO_H__

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

// Platform files included

// Used files included
#include <vmLibBase/CUnitTestFrame.h>

#include <vmLibErr/CErrno.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CErrno_t1 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    errno = 10;

    bool lbHasErr = vm::CErrno::HasErrno();
    // #  TODO : Add condition brief here ##
    if (lbHasErr == true)
    {
        vm::utLogLine(vT("Errno(%d) is %s!"), errno, vm::CErrno::MsgErrno(errno) );
    } 
    else
    {
        vm::utLogLine(vT("there hasn't an error!"));
    } // End of if () ...

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CErrno_t2 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    bool lbHasErr = vm::CErrno::isError( 11 );
    // #  TODO : Add condition brief here ##
    if (lbHasErr == true)
    {
        vm::utLogLine(vT("Errno(%d) is %s!"), vm::CErrno::toErrCode(), vm::CErrno::MsgErrno());
    }
    else
    {
        vm::utLogLine(vT("there hasn't an error!"));
    } // End of if () ...


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CErrno )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST( ut_CErrno_t1 );
    UNIT_TEST_REGIST( ut_CErrno_t2 );
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CERRNO_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CErrno.h
/////////////////////////////////////////////////////////////////////////////////////////