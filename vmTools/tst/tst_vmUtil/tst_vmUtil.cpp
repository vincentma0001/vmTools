/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : tst_vmUtil.cpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/15 12:06:08
// Modify time  : 2020/01/15 12:06:08
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

// platform files included

// Declare file included
#include <vmLibBase/CUnitTestFrame.h>

// Unit test files include
#include "ut_vmUtil_v_str_substr.h"

/////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, tchar** argv )
{
// --------------------------------------------------------------------------------------
// TODO : add main functions there
    // example : RUN_UNITTEST( ut_XXXX );
    RUN_UNITTEST(ut_vmUtil_v_str_substr);


// ------------------------------------------------------------------------------------
	::system("Pause");
	return 0;
} // End of main(...)

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file tst_vmUtil.cpp
/////////////////////////////////////////////////////////////////////////////////////////