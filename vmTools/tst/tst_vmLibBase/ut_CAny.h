/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CAny.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/20 23:21:31
// Modify time  : 2020/01/20 23:21:31
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

#ifndef __UT_CANY_H__
#define __UT_CANY_H__

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

// test function's files
#include <vmLibBase/CAny.hpp>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CAny_t1 )
{
    bool lbRet = true;
    // #Add test content here#
    
    vm::CAny<128> loBool( true );
    vm::utLogLine(vT("loBool  is %s type(%s)"),  loBool.s_bool(),  loBool.cs_type());
    vm::CAny<128> loBool2( false );
    vm::utLogLine(vT("loBool2 is %s type(%s)"), loBool2.s_bool(), loBool2.cs_type());

    vm::CAny<128> loChar1(vT('A'));
    vm::utLogLine(vT("loChar1 is %s type(%s)"), loChar1.s_char(), loChar1.cs_type());
    vm::CAny<128> loChar2(char(101));
    vm::utLogLine(vT("loChar2 is %s type(%s)"), loChar2.s_char(), loChar2.cs_type());

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CAny )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CAny_t1);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CANY_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CAny.h
/////////////////////////////////////////////////////////////////////////////////////////