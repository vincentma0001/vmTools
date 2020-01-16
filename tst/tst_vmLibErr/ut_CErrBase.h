/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CErrBase.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/14 15:59:58
// Modify time  : 2020/01/14 15:59:58
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

#ifndef __UT_CERRBASE_H__
#define __UT_CERRBASE_H__

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
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included
#include <vmLibBase/vmUtil.h>
#include <vmLibBase/CUnitTestFrame.h>

#include <vmLibErr/CErrBase.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CErrBase_t1 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    vm::CErrBase loError;
    vm::utLogLine( "CError : %d%s" , loError.toErrCode(), loError.toErrStr() );

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CErrBase_t2 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    vm::CErrBase loError(10);
    vm::v_strcpy( loError.mszBuf, sizeof(loError.mszBuf), vT("this is a Err test") );
    vm::utLogLine("CError : %d - %s", loError.toErrCode(), loError.toErrStr());

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CErrBase_t3 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    vm::CErrBase loError(10);
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
UNIT_TEST_BEGIN( ut_CErrBase )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST( ut_CErrBase_t1 );
    UNIT_TEST_REGIST( ut_CErrBase_t2 );
    UNIT_TEST_REGIST( ut_CErrBase_t3 );
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CERRBASE_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CErrBase.h
/////////////////////////////////////////////////////////////////////////////////////////