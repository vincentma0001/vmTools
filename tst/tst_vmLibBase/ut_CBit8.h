/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CBit8.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/15 09:18:24
// Modify time  : 2020/01/15 09:18:24
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

#ifndef __UT_CBIT8_H__
#define __UT_CBIT8_H__

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
#include <string>

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included
#include <vmLibBase/CUnitTestFrame.h>

// test function's files
#include <vmLibBase/vmUtil.h>
#include <vmLibBase/CString.hpp>
#include <vmLibBase/CBit8.h>


/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :
void  print(vm::CBit8& oBit)
{
    vm::CString<128> lstrBitBin = oBit.toBin();
    vm::CString<128> lstrBitOct = oBit.toOct();
    vm::CString<128> lstrBitDec = oBit.toDec();
    vm::CString<128> lstrBitHex = oBit.toHex();
    vm::utLogLine(vT("Val [%s] : Bin(%s), Hex(%s), Oct(%s)"), *lstrBitDec, *lstrBitBin, *lstrBitHex, *lstrBitOct);
}

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CBit8_t1 )
{
    bool lbRet = true;

    // #Add test content here#
    tchar liVal = CHAR_MIN;
    vm::CBit8 loBit(liVal);
    print(loBit);


    liVal = CHAR_MAX;
    vm::CBit8 loBit2(liVal);
    print(loBit2);

    unsigned char liVal2 = 0;
    vm::CBit8 loBit3(liVal2);
    print(loBit3);

    liVal2 = UCHAR_MAX;
    vm::CBit8 loBit4(liVal2);
    print(loBit4);

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CBit8_t2 )
{
    bool lbRet = true;

    // #Add test content here#
    vm::CBit8 loBit5((tchar)0);
    print(loBit5);

    loBit5.Set01();
    vm::utLogLine(vT("Set Pos1 : %s"), loBit5.isSet01() ? "Pos1 is setting!" : "Pos1 isn't setting!");
    print(loBit5);

    loBit5.clear();
    loBit5.Set02();
    vm::utLogLine(vT("Set Pos2 : %s"), loBit5.isSet02() ? "Pos2 is setting!" : "Pos2 isn't setting!");
    print(loBit5);

    loBit5.clear();
    loBit5.Set03();
    vm::utLogLine(vT("Set Pos3 : %s"), loBit5.isSet03() ? "Pos3 is setting!" : "Pos3 isn't setting!");
    print(loBit5);

    loBit5.clear();
    loBit5.Set04();
    vm::utLogLine(vT("Set Pos4 : %s"), loBit5.isSet04() ? "Pos3 is setting!" : "Pos4 isn't setting!");
    print(loBit5);

    loBit5.clear();
    loBit5.Set05();
    vm::utLogLine(vT("Set Pos5 : %s"), loBit5.isSet05() ? "Pos5 is setting!" : "Pos5 isn't setting!");
    print(loBit5);

    loBit5.clear();
    loBit5.Set06();
    vm::utLogLine(vT("Set Pos6 : %s"), loBit5.isSet06() ? "Pos6 is setting!" : "Pos6 isn't setting!");
    print(loBit5);

    loBit5.clear();
    loBit5.Set07();
    vm::utLogLine(vT("Set Pos7 : %s"), loBit5.isSet07() ? "Pos7 is setting!" : "Pos7 isn't setting!");
    print(loBit5);

    loBit5.clear();
    loBit5.Set08();
    vm::utLogLine(vT("Set Pos8 : %s"), loBit5.isSet08() ? "Pos8 is setting!" : "Pos8 isn't setting!");
    print(loBit5);

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CBit8_t3 )
{
    bool lbRet = true;

    // #Add test content here#
    vm::CBit8 loBit6((tchar)0);

    loBit6.Set01();
    print(loBit6);

    loBit6.Set02();
    print(loBit6);

    loBit6.Set03();
    print(loBit6);

    loBit6.Set04();
    print(loBit6);

    loBit6.Set05();
    print(loBit6);

    loBit6.Set06();
    print(loBit6);

    loBit6.Set07();
    print(loBit6);

    loBit6.Set08();
    print(loBit6);

    loBit6.unSet01();
    print(loBit6);

    loBit6.unSet02();
    print(loBit6);

    loBit6.unSet03();
    print(loBit6);

    loBit6.unSet04();
    print(loBit6);

    loBit6.unSet05();
    print(loBit6);

    loBit6.unSet06();
    print(loBit6);

    loBit6.unSet07();
    print(loBit6);

    loBit6.unSet08();
    print(loBit6);

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CBit8 )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CBit8_t1);
    UNIT_TEST_REGIST(ut_CBit8_t2);
    UNIT_TEST_REGIST(ut_CBit8_t3);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CBIT8_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CBit8.h
/////////////////////////////////////////////////////////////////////////////////////////