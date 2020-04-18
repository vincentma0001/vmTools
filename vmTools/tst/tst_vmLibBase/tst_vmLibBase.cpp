/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : tst_vmLibBase.cpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/14 21:33:43
// Modify time  : 2020/01/14 21:33:43
// Note         :
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Disable warning
// Example : #pragma warning(disable:4996)
// #if defined (_MSC_VER)
// #   pragma warning(disable:4996)
// #endif

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included

// platform files include
#include <vmCfg.h>

// Declare file included
#include <vmTools/CUnitTestFrame.h>

// Unit test files include
//#include "ut_CBit8.h"
//#include "ut_CAny.h"
//#include "ut_CStdPars.h"
//#include "ut_CWinAtom.h"
//#include "ut_CList.h"
#include "tst_vmTools/ut_CString.h"

/////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, tchar** argv )
{
// --------------------------------------------------------------------------------------
// TODO : add main functions there
    // example : RUN_UNITTEST( ut_XXXX );
    //RUN_UNITTEST(ut_CBit8);
    //RUN_UNITTEST(ut_CAny);
    //RUN_UNITTEST(ut_CStdPars);
    //RUN_UNITTEST(ut_CWinAtom);
    //RUN_UNITTEST(ut_CList);
    RUN_UNITTEST(ut_CString);

// ------------------------------------------------------------------------------------
	::system("Pause");
	return 0;
} // End of main(...)

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file tst_vmLibBase.cpp
/////////////////////////////////////////////////////////////////////////////////////////