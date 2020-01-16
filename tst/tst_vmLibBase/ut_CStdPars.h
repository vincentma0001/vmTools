/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CStdPars.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/15 10:00:31
// Modify time  : 2020/01/15 10:00:31
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

#ifndef __UT_CSTDPARS_H__
#define __UT_CSTDPARS_H__

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
#include <vmLibBase/CStdPars.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CStdPars_t1 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vString lstrString = vT("this is a tst [%F:%L] - %M");
    vm::utLogLine("Pattern string : %s", lstrString.c_str());

    vm::vStd::CStdPars::CPattern loPatternFile(vT("%F"), vT("main.cpp"));
    vm::vStd::CStdPars::CPattern loPatternLine(vT("%L"), vT("1024"));
    vm::vStd::CStdPars::CPattern loPatternMsg(vT("%M"), vT("This is a test!"));

    vm::vStd::CStdPars loParser(lstrString, '%');
    loParser.Regist(loPatternFile);
    loParser.Regist(loPatternLine);
    loParser.Regist(loPatternMsg);

    std::string lstrOut;
    loParser.Parse(lstrOut);

    vm::utLogLine("Parered string : %s", lstrOut.c_str());


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CStdPars_t2 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vString lstrString = vT("this is a tst [%F:%L] - %M Flag");
    vm::utLogLine("Pattern string : %s", lstrString.c_str());

    vm::vStd::CStdPars::CPattern loPatternFile(vT("%F"), vT("main.cpp"));
    vm::vStd::CStdPars::CPattern loPatternLine(vT("%L"), vT("1024"));
    vm::vStd::CStdPars::CPattern loPatternMsg(vT("%M"), vT("This is a test!"));

    vm::vStd::CStdPars loParser(lstrString, '%');
    loParser.Regist(loPatternFile);
    loParser.Regist(loPatternLine);
    loParser.Regist(loPatternMsg);

    std::string lstrOut;
    loParser.Parse(lstrOut);

    vm::utLogLine("Parered string : %s", lstrOut.c_str());


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CStdPars_t3 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vString lstrString = vT("this is a tst [%%L] - %M Flag");
    vm::utLogLine("Pattern string : %s", lstrString.c_str());

    vm::vStd::CStdPars::CPattern loPatternFile(vT("%F"), vT("main.cpp"));
    vm::vStd::CStdPars::CPattern loPatternLine(vT("%L"), vT("1024"));
    vm::vStd::CStdPars::CPattern loPatternMsg(vT("%M"), vT("This is a test!"));

    vm::vStd::CStdPars loParser(lstrString, '%');
    loParser.Regist(loPatternFile);
    loParser.Regist(loPatternLine);
    loParser.Regist(loPatternMsg);

    std::string lstrOut;
    loParser.Parse(lstrOut);

    vm::utLogLine("Parered string : %s", lstrOut.c_str());


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CStdPars_t4 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vString lstrString = vT("this is a tst [%F:%L] - %M Flag %");
    vm::utLogLine("Pattern string : %s", lstrString.c_str());

    vm::vStd::CStdPars::CPattern loPatternFile(vT("%F"), vT("main.cpp"));
    vm::vStd::CStdPars::CPattern loPatternLine(vT("%L"), vT("1024"));
    vm::vStd::CStdPars::CPattern loPatternMsg(vT("%M"), vT("This is a test!"));

    vm::vStd::CStdPars loParser(lstrString, '%');
    loParser.Regist(loPatternFile);
    loParser.Regist(loPatternLine);
    loParser.Regist(loPatternMsg);

    std::string lstrOut;
    loParser.Parse(lstrOut);

    vm::utLogLine("Parered string : %s", lstrOut.c_str());


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CStdPars_t5 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vString lstrString = vT("%this is a tst [%F:%L] - %M Flag %");
    vm::utLogLine("Pattern string : %s", lstrString.c_str());

    vm::vStd::CStdPars::CPattern loPatternFile(vT("%F"), vT("main.cpp"));
    vm::vStd::CStdPars::CPattern loPatternLine(vT("%L"), vT("1024"));
    vm::vStd::CStdPars::CPattern loPatternMsg(vT("%M"), vT("This is a test!"));

    vm::vStd::CStdPars loParser(lstrString, '%');
    loParser.Regist(loPatternFile);
    loParser.Regist(loPatternLine);
    loParser.Regist(loPatternMsg);

    std::string lstrOut;
    loParser.Parse(lstrOut);

    vm::utLogLine("Parered string : %s", lstrOut.c_str());


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CStdPars_t6 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vString lstrString = vT("");
    vm::utLogLine("Pattern string : %s", lstrString.c_str());

    vm::vStd::CStdPars::CPattern loPatternFile(vT("%F"), vT("main.cpp"));
    vm::vStd::CStdPars::CPattern loPatternLine(vT("%L"), vT("1024"));
    vm::vStd::CStdPars::CPattern loPatternMsg(vT("%M"), vT("This is a test!"));

    vm::vStd::CStdPars loParser(lstrString, '%');
    loParser.Regist(loPatternFile);
    loParser.Regist(loPatternLine);
    loParser.Regist(loPatternMsg);

    std::string lstrOut;
    loParser.Parse(lstrOut);

    vm::utLogLine("Parered string : %s", lstrOut.c_str());


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CStdPars_t7 )
{
    bool lbRet = false;
    vm::utLogLine("======================================================================================");
    vm::utLogLine("");

    // #Add test content here#
    vString lstrString = vT("%");
    vm::utLogLine("Pattern string : %s", lstrString.c_str());

    vm::vStd::CStdPars::CPattern loPatternFile(vT("%F"), vT("main.cpp"));
    vm::vStd::CStdPars::CPattern loPatternLine(vT("%L"), vT("1024"));
    vm::vStd::CStdPars::CPattern loPatternMsg(vT("%M"), vT("This is a test!"));

    vm::vStd::CStdPars loParser(lstrString, '%');
    loParser.Regist(loPatternFile);
    loParser.Regist(loPatternLine);
    loParser.Regist(loPatternMsg);

    std::string lstrOut;
    loParser.Parse(lstrOut);

    vm::utLogLine("Parered string : %s", lstrOut.c_str());


    vm::utLogLine("");
    vm::utLogLine("======================================================================================");
    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CStdPars )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CStdPars_t1);
    UNIT_TEST_REGIST(ut_CStdPars_t2);
    UNIT_TEST_REGIST(ut_CStdPars_t3);
    UNIT_TEST_REGIST(ut_CStdPars_t4);
    UNIT_TEST_REGIST(ut_CStdPars_t5);
    UNIT_TEST_REGIST(ut_CStdPars_t6);
    UNIT_TEST_REGIST(ut_CStdPars_t7);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CSTDPARS_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CStdPars.h
/////////////////////////////////////////////////////////////////////////////////////////