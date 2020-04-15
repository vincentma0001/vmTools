/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CError.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/14 19:57:33
// Modify time  : 2020/01/14 19:57:33
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

#ifndef __UT_CERROR_H__
#define __UT_CERROR_H__

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

#include <tst_vmLibErr/ut_CErrBase.h>
#include <tst_vmLibErr/ut_CWinErr.h>
#include <tst_vmLibErr/ut_CError.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CError_t1 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    vm::CError loError;
    vm::utLogLine("CError : %d%s", loError.toErrCode(), loError.toErrStr());

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CError_t2 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    vm::CError loError(10);
    vm::v_strcpy(loError.mszBuf, sizeof(loError.mszBuf), vT("this is a Err test"));
    vm::utLogLine("CError : %d - %s", loError.toErrCode(), loError.toErrStr());

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CError_t3 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    vm::CError loError(10);
    vm::utLogLine("CError : %s", loError.Fmt("this is a Error(%EC:%EM)!"));

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CError )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CError_t1);
    UNIT_TEST_REGIST(ut_CError_t2);
    UNIT_TEST_REGIST(ut_CError_t3);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CERROR_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CError.h
/////////////////////////////////////////////////////////////////////////////////////////