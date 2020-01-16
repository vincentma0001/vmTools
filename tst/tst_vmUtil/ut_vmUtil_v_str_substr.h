/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_vmUtil_v_str_substr.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/15 12:06:49
// Modify time  : 2020/01/15 12:06:49
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

#ifndef __UT_VMUTIL_V_STR_SUBSTR_H__
#define __UT_VMUTIL_V_STR_SUBSTR_H__

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
#include <vmLibBase/CUnitTestFrame.h>

// test function's files
#include <vmLibBase/vmUtil.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_vmUtil_v_str_substr_t1 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lszpSrc  = vT( "this is a test str! substr is {A1234567890A}!" );
    vm::utLogLine("Src string    : %s", lszpSrc);

    tChar lszBuf[1024] = {0x00};
    vm::v_str_substr( lszBuf, sizeof(lszBuf), lszpSrc, strlen(lszpSrc), vT('{'), vT('}') );
    vm::utLogLine("Substr string : %s", lszBuf);

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_vmUtil_v_str_substr_t2 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    // #Add test content here#
    const tChar* lszpSrc = vT("{A1234567890A}!");
    vm::utLogLine("Src string    : %s", lszpSrc);

    tChar lszBuf[ 1024 ] = { 0x00 };
    vm::v_str_substr(lszBuf, sizeof(lszBuf), lszpSrc, strlen(lszpSrc), vT('{'), vT('}'));
    vm::utLogLine("Substr string : %s", lszBuf);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_vmUtil_v_str_substr_t3 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lszpSrc = vT("A{A1234567890A}A");
    vm::utLogLine("Src string    : %s", lszpSrc);

    tChar lszBuf[ 1024 ] = { 0x00 };
    vm::v_str_substr(lszBuf, sizeof(lszBuf), lszpSrc, strlen(lszpSrc), vMinsInt, vT('}'));
    vm::utLogLine("Substr string : %s", lszBuf);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_vmUtil_v_str_substr_t4 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lszpSrc = vT("A{A1234567890A}A");
    vm::utLogLine("Src string    : %s", lszpSrc);

    tChar lszBuf[ 1024 ] = { 0x00 };
    vm::v_str_substr(lszBuf, sizeof(lszBuf), lszpSrc, strlen(lszpSrc), vT('{'), vMinsInt);
    vm::utLogLine("Substr string : %s", lszBuf);


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_vmUtil_v_str_substr_t5 )
{
    bool lbRet = true;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    const tChar* lszpSrc = vT("A{A123{456}7890A}A");
    vm::utLogLine("Src string    : %s", lszpSrc);

    tChar lszBuf[ 1024 ] = { 0x00 };
    vm::v_str_substr(lszBuf, sizeof(lszBuf), lszpSrc, strlen(lszpSrc), vT('{'), vT('}'));
    vm::utLogLine("Substr string : %s", lszBuf);

    vm::v_str_substr(lszBuf, sizeof(lszBuf), vT('{'), vT('}') );
    vm::utLogLine("SubSub string : %s", lszBuf);

    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_vmUtil_v_str_substr )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_vmUtil_v_str_substr_t1);
    UNIT_TEST_REGIST(ut_vmUtil_v_str_substr_t2);
    UNIT_TEST_REGIST(ut_vmUtil_v_str_substr_t3);
    UNIT_TEST_REGIST(ut_vmUtil_v_str_substr_t4);
    UNIT_TEST_REGIST(ut_vmUtil_v_str_substr_t5);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_VMUTIL_V_STR_SUBSTR_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_vmUtil_v_str_substr.h
/////////////////////////////////////////////////////////////////////////////////////////