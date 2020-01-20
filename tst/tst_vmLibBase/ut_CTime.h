/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CTime.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/19 16:25:35
// Modify time  : 2020/01/19 16:25:35
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

#ifndef __UT_CTIME_H__
#define __UT_CTIME_H__

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
#include <vmLibBase/CTime.hpp>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CTime_t1 )
{
    bool lbRet = true;
    // #Add test content here#
    vm::CTime<256> loTime;
    loTime.Now();
    vm::utLogLine("Now1 : %s", loTime.Fmt( vm::vTime::Y2_MM_DD_hh$mm$ss$ms ));
    vm::utLogLine("Now2 : %s", vm::CTime<256>::GetNow().Fmt( vm::vTime::Y2_MM_DD_hh$mm$ss$ms ));
    vm::utLogLine("Now3 : %s", vm::CTime<256>().Now().Fmt( vm::vTime::Y2_MM_DD_hh$mm$ss$ms ));

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CTime_t2 )
{
    bool lbRet = true;
    // #Add test content here#
    vm::CTime<236> loTime;
    vm::utLogLine("Time1           : %s", loTime.Fmt(vm::vTime::Y4_MM_DD_hh$mm$ss$ms));

    loTime += vm::vTime::CDays(1);
    vm::utLogLine("Time2 time+1day : %s", loTime.Fmt(vm::vTime::Y4_MM_DD_hh$mm$ss$ms));

    loTime -= vm::vTime::CDays(1);
    vm::utLogLine("Time3 time-1day : %s", loTime.Fmt(vm::vTime::Y4_MM_DD_hh$mm$ss$ms));

    loTime += vm::vTime::CDays(50);
    vm::utLogLine("Time4 time+50day : %s", loTime.Fmt(vm::vTime::Y4_MM_DD_hh$mm$ss$ms));

    //loTime += vm::vTime::CDays(50);
    vm::utLogLine("Time5 toDays : %d", loTime.toDays());

    loTime -= vm::vTime::CDays(50);
    vm::utLogLine("Time6 time-50day : %s", loTime.Fmt(vm::vTime::Y4_MM_DD_hh$mm$ss$ms));

    //loTime += vm::vTime::CDays(50);
    vm::utLogLine("Time7 toDays : %d", loTime.toDays());

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CTime_t3 )
{
    bool lbRet = false;
    // #Add test content here#
    vm::CTime<256> loTime;
    vm::utLogLine("Time1           : %s", loTime.Fmt(vm::vTime::Y4_MM_DD_hh$mm$ss$ms));

    loTime -= vDays(1);
    vm::utLogLine("Time2           : %s", loTime.Fmt(vm::vTime::Y4_MM_DD_hh$mm$ss$ms));

    // #  TODO : Add condition brief here ##
    if ( loTime.HasError() )
    {
        vm::utLogLine("Error %d:%s", loTime.toErrCode(), strerror(loTime.toErrCode()));
    } 
    // End of if ( loTime.HasError() ) ...

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CTime )
    // example : UNIT_TEST_REGIST(Func1)o
    UNIT_TEST_REGIST(ut_CTime_t1);
    UNIT_TEST_REGIST(ut_CTime_t2);
    UNIT_TEST_REGIST(ut_CTime_t3);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CTIME_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CTime.h
/////////////////////////////////////////////////////////////////////////////////////////