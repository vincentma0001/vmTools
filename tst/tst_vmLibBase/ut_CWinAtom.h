/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CWinAtom.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/15 10:04:32
// Modify time  : 2020/01/15 10:04:32
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

#ifndef __UT_CWINATOM_H__
#define __UT_CWINATOM_H__

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
#include <windows.h>

// Used files included
#include <vmLibBase/CUnitTestFrame.h>

// test function's files
#include <vmLibIPC/CWinAtom.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CWinAtom_t1 )
{
    bool lbRet = false;
    // #Add test content here#
    vm::CWinAtom lAtom1;
    vm::CWinAtom lAtom2(10);
    vm::CWinAtom lAtom3(lAtom2);

    vm::utLogLine(vT("lAtom1 ( CAtom lAtom1;         ) : %d"), long(lAtom1));
    vm::utLogLine(vT("lAtom2 ( CAtom lAtom2(10);     ) : %d"), long(lAtom2));
    vm::utLogLine(vT("lAtom3 ( CAtom lAtom3(lAtom2); ) : %d"), long(lAtom3));

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CWinAtom_t2 )
{
    bool lbRet = false;

    // #Add test content here#
    vm::CWinAtom lAtom4(1);
    vm::utLogLine(vT("lAtom4 ( CAtom lAtom4(1);       ) : %d"), long(lAtom4));
    vm::CWinAtom lAtom5(2);
    vm::utLogLine(vT("lAtom5 ( CAtom lAtom5(2);       ) : %d"), long(lAtom5));
    lAtom4 = lAtom5;
    vm::utLogLine(vT("lAtom4 ( lAtom4(1) = lAtom5(2); ) : %d"), long(lAtom4));
    lAtom4 = 10;
    vm::utLogLine(vT("lAtom4 ( lAtom4 = 10;           ) : %d"), long(lAtom4));

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CWinAtom_t3 )
{
    bool lbRet = false;

    // #Add test content here#
    vm::CWinAtom lAtom6(1);
    vm::utLogLine(vT("lAtom6 ( CAtom lAtom6(1);          ) : %d"), long(lAtom6));
    vm::CWinAtom lAtom7(2);
    vm::utLogLine(vT("lAtom7 ( CAtom lAtom7(2);          ) : %d"), long(lAtom7));
    vm::CWinAtom lAtom8;
    vm::utLogLine(vT("lAtom8 ( CAtom lAtom8);            ) : %d"), long(lAtom8));
    lAtom8 = lAtom6 + lAtom7;
    vm::utLogLine(vT("lAtom8 ( lAtom8 = lAtom6 + lAtom7; ) : %d"), long(lAtom8));
    lAtom8 = lAtom8 + (long)10;
    vm::utLogLine(vT("lAtom8 ( lAtom8 = lAtom8 + (long)10; ) %d"), long(lAtom8));

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CWinAtom_t4 )
{
    bool lbRet = false;

    // #Add test content here#
    vm::CWinAtom lAtom9(1);
    vm::utLogLine(vT("lAtom9 ( CAtom lAtom9(1);          ) : %d"), long(lAtom9));
    ++lAtom9;
    vm::utLogLine(vT("lAtom9 ( ++lAtom9;                 ) : %d"), long(lAtom9));
    ++lAtom9;
    vm::utLogLine(vT("lAtom9 ( ++lAtom9;                 ) : %d"), long(lAtom9));
    --lAtom9;
    vm::utLogLine(vT("lAtom9 ( --lAtom9;                 ) : %d"), long(lAtom9));
    --lAtom9;
    vm::utLogLine(vT("lAtom9 ( --lAtom9;                 ) : %d"), long(lAtom9));

    vm::CWinAtom lAtom10(1);
    vm::utLogLine(vT("lAtom10 ( CAtom lAtom10(1);          ) : %d"), long(lAtom10));
    lAtom10++;
    vm::utLogLine(vT("lAtom10 ( lAtom10++;                 ) : %d"), long(lAtom10));
    lAtom10++;
    vm::utLogLine(vT("lAtom10 ( lAtom10++;                 ) : %d"), long(lAtom10));
    lAtom10--;
    vm::utLogLine(vT("lAtom10 ( lAtom10--;                 ) : %d"), long(lAtom10));
    lAtom10--;
    vm::utLogLine(vT("lAtom10 ( lAtom10--;                 ) : %d"), long(lAtom10));

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CWinAtom_t5 )
{
    bool lbRet = false;

    // #Add test content here#
    vm::CWinAtom lAtom11(1);
    vm::utLogLine(vT("lAtom11 ( CAtom lAtom11(1);          ) : %d"), long(lAtom11));
    vm::CWinAtom lAtom12(2);
    vm::utLogLine(vT("lAtom12 ( CAtom lAtom12(2);          ) : %d"), long(lAtom12));
    vm::CWinAtom lAtom13(1);
    vm::utLogLine(vT("lAtom13 ( CAtom lAtom13(1);          ) : %d"), long(lAtom13));

    vm::utLogLine(vT("lAtom11 == lAtom12 is %s"), lAtom11 == lAtom12 ? "true" : "false");
    vm::utLogLine(vT("lAtom11 == lAtom13 is %s"), lAtom11 == lAtom13 ? "true" : "false");
    vm::utLogLine(vT("lAtom11 != lAtom12 is %s"), lAtom11 != lAtom12 ? "true" : "false");
    vm::utLogLine(vT("lAtom11 != lAtom13 is %s"), lAtom11 != lAtom13 ? "true" : "false");
    vm::utLogLine(vT("lAtom11 == long(1) is %s"), lAtom11 == long(1) ? "true" : "false");
    vm::utLogLine(vT("lAtom11 == long(2) is %s"), lAtom11 == long(2) ? "true" : "false");
    vm::utLogLine(vT("lAtom11 != long(1) is %s"), lAtom11 != long(1) ? "true" : "false");
    vm::utLogLine(vT("lAtom11 != long(2) is %s"), lAtom11 != long(2) ? "true" : "false");

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CWinAtom_t6 )
{
    bool lbRet = false;

    // #Add test content here#
    vm::CWinAtom lAtom14(1);
    vm::utLogLine(vT("lAtom14 ( CAtom lAtom14(1);          ) : %d"), long(lAtom14));
    lAtom14.Add(10);
    vm::utLogLine(vT("lAtom14.Add(10)                        = %d"), long(lAtom14));
    vm::utLogLine(vT("lAtom14.Add(10)                        = %d"), long(lAtom14.Add(10)));
    lAtom14.Change(2);
    vm::utLogLine(vT("lAtom14.Change(2)                      = %d"), long(lAtom14));
    lAtom14.Increment();
    vm::utLogLine(vT("lAtom14.Increment()                    = %d"), long(lAtom14));
    lAtom14.Decrement();
    vm::utLogLine(vT("lAtom14.Decrement()                    = %d"), long(lAtom14));
    lAtom14.CompareExchange(3, 10);
    vm::utLogLine(vT("lAtom14.CompareExchange(2, 10)         = %d"), long(lAtom14));
    lAtom14.CompareExchange(2, 10);
    vm::utLogLine(vT("lAtom14.CompareExchange(3, 10)         = %d"), long(lAtom14));

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CWinAtom )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CWinAtom_t1);
    UNIT_TEST_REGIST(ut_CWinAtom_t2);
    UNIT_TEST_REGIST(ut_CWinAtom_t3);
    UNIT_TEST_REGIST(ut_CWinAtom_t4);
    UNIT_TEST_REGIST(ut_CWinAtom_t5);
    UNIT_TEST_REGIST(ut_CWinAtom_t6);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CWINATOM_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CWinAtom.h
/////////////////////////////////////////////////////////////////////////////////////////