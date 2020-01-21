/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CDateTime.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/15 09:43:26
// Modify time  : 2020/01/15 09:43:26
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

#ifndef __UT_CDATETIME_H__
#define __UT_CDATETIME_H__

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
#include <time.h>

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included
#include <vmLibBase/CUnitTestFrame.h>

// test function's files
#include <vmLibBase/vmUtil.h>
#include <vmLibBase/CMemPtr.h>
#include <vmLibBase/CStringPtr.h>
#include <vmLibBase/CString.hpp>
#include <vmLibBase/CDateTime.hpp>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CDateTime_t1 )
{
    bool lbRet = false;
    vm::utLogLine(vT("======================================================================================"));
    vm::utLogLine(vT(""));

    // #Add test content here#
    vm::CDateTime<128> loDateTime = vm::CDateTime<128>::GetCurrTime();
    vm::CString<256> lstrDateTime = loDateTime.ToStrFull();
    vm::utLogLine(vT("Current Time is %s"), *lstrDateTime);

    vm::utLogLine(vT(""));
    vm::utLogLine(vT("======================================================================================"));
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CDateTime_t2 )
{
    bool lbRet = true;
    vm::utLogLine(vT("======================================================================================"));
    vm::utLogLine(vT(""));

    // #Add test content here#
    vm::CDateTime<256> loDateTime = vm::CDateTime<256>::GetCurrTime();
    vm::utLogLine(vT("Time($Y4-$MM-$DD)                         : %s"),loDateTime.Fmt(vT("%Y4-%MM-%DD")) );
    vm::utLogLine(vT("Time($Y2/$MM/$DD $hh:$mm:$ss.$ms)         : %s"),loDateTime.Fmt(vT("%Y2-%MM-%DD %hh:%mm:%ss.%ms")) );
    vm::utLogLine(vT("Time($Y2/$MM/$DD $AP $II:$mm:$ss.$ms)     : %s"),loDateTime.Fmt(vT("%Y2-%MM-%DD %AP %ii:%mm:%ss.%ms")) );
    //      %CD  (date and time representation   e.g. Thu Aug 23 14:55:02 2001)  = %c
    vm::utLogLine(vT("Date and time representation              : %s"),loDateTime.Fmt(vT("%CD %ms")) );
    //      %SD  (Short MM/DD/YY date            e.g.                 08/23/01)  = %D
    vm::utLogLine(vT("Short MM/DD/YY date                       : %s"),loDateTime.Fmt(vT("%SD")) );
    //      %sd  (Short YY/MM/DD date            e.g.                 01/08/23)  = %y/%m/%d
    vm::utLogLine(vT("Short YY/MM/DD date                       : %s"),loDateTime.Fmt(vT("%sd")) );
    //      %FD  (Short YYYY-MM-DD date          e.g.               2001-08-23)  = %F
    vm::utLogLine(vT("Short YYYY-MM-DD date                     : %s"),loDateTime.Fmt(vT("%FD")) );
    //      %fd  (Short MM-DD-YYYY date          e.g.               08-23-2001)  = %m-%d-%Y
    vm::utLogLine(vT("Short MM-DD-YYYY date                     : %s"),loDateTime.Fmt(vT("%fd")) );
    //      %RT  (24 - hour HH:MM time           e.g.                    14:55)  = %R
    vm::utLogLine(vT("24 - hour HH:MM time                      : %s"),loDateTime.Fmt(vT("%RT")) );
    //      %rt  (12 - hour clock time           e.g.              02:55:02 pm)  = %r
    vm::utLogLine(vT("12 - hour clock time                      : %s"),loDateTime.Fmt(vT("%rt")) );
    //      %TT  (ISO 8601 time format           e.g.                 14:55:02)  = %T
    vm::utLogLine(vT("ISO 8601 time format                      : %s"),loDateTime.Fmt(vT("%TT")) );
    //      %tt  (ISO 8601 time format 12 hour   e.g.                 02:55:02)  = %I:%M:%S
    vm::utLogLine(vT("ISO 8601 time format 12 hour              : %s"),loDateTime.Fmt(vT("%tt")) );
    //      %AM  (Abbreviated month              e.g.                   August)  = %B
    //      %am  (Abbreviated month              e.g.                      Aug)  = %b
    vm::utLogLine(vT("Month and short Month                     : %s"),loDateTime.Fmt(vT("%AM %am")) );
    //      %AW  (Abbreviated weekday            e.g.                   Friday)  = %A
    //      %aw  (Abbreviated weekday            e.g.                      Fri)  = %a
    vm::utLogLine(vT("Weekday and short Weekday                 : %s"),loDateTime.Fmt(vT("%AW %aw")) );
    //      %WY  (Week based year                e.g.                    00-99)  = %g
    vm::utLogLine(vT("Week based year                           : %s"),loDateTime.Fmt(vT("%WY")) );
    //      %WW  (ISO 8601 weekday as number with Monday          e.g.     1-7)  = %u
    vm::utLogLine(vT("ISO 8601 weekday as number with Monday    : %s"),loDateTime.Fmt(vT("%WW")) );
    //      %ww  (Weekday as a decimal number with Sunday as 0    e.g.     0-6)  = %w
    vm::utLogLine(vT("Weekday as a decimal number with Sunday   : %s"),loDateTime.Fmt(vT("%ww")) );
    //      %WN  (ISO 8601 week number           e.g.                    00-53)  = %V
    vm::utLogLine(vT("ISO 8601 week number                      : %s"),loDateTime.Fmt(vT("%WN")) );
    //      %WS  (Week number with the first Sunday as the first day of week one  e.g. 00-53 ) = %U
    vm::utLogLine(vT("Week number with the first Sunday         : %s"),loDateTime.Fmt(vT("%WS")) );
    //      %WM  (Week number with the first Monday as the first day of week one  e.g. 00-53 ) = %W
    vm::utLogLine(vT("Week number with the first Monday         : %s"),loDateTime.Fmt(vT("%WM")) );
    //      %DY  (Day of the year                e.g.                  001-366)  = %j
    vm::utLogLine(vT("Day of the year                           : %s"),loDateTime.Fmt(vT("%DY")) );
    //      %TZ  (Timezone name                  e.g.                      CDT)  = %Z
    vm::utLogLine(vT("Timezone name                             : %s"),loDateTime.Fmt(vT("%TZ")) );
    //      %ZZ  (ISO 8601 offset from UTC in timezone(1 minute = 1,             = %z
    //            1 hour = 100) If timezone cannot be determined, 
    //            no characters)
    vm::utLogLine(vT("ISO 8601 offset from UTC in timezone      : %s"),loDateTime.Fmt(vT("%ZZ")) );
    //      %n   (New        - line character('\n')  
    vm::utLogLine(vT("$n is %s"),loDateTime.Fmt(vT("AA%nAA")) );
    //      %t   (Horizontal - tab  character('\t')  
    vm::utLogLine(vT("$t is %s"),loDateTime.Fmt(vT("AA%tAA")) );
    //      %%   ( A % sign	- %
    vm::utLogLine(vT("$$ is %s"),loDateTime.Fmt(vT("AA%%AA")) );
    

    vm::utLogLine(vT(""));
    vm::utLogLine(vT("======================================================================================"));
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CDateTime_t3 )
{
    bool lbRet = false;
    vm::utLogLine(vT("======================================================================================"));
    vm::utLogLine(vT(""));

    // #Add test content here#


    vm::utLogLine(vT(""));
    vm::utLogLine(vT("======================================================================================"));
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CDateTime )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CDateTime_t1);
    UNIT_TEST_REGIST(ut_CDateTime_t2);
    UNIT_TEST_REGIST(ut_CDateTime_t3);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CDATETIME_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CDateTime.h
/////////////////////////////////////////////////////////////////////////////////////////