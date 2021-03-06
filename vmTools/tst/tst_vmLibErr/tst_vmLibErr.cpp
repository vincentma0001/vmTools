/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : tst_vmLibErr.cpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/14 16:08:10
// Modify time  : 2020/01/14 16:08:10
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
// Include libs  :
#pragma comment (lib,"vmLibErr.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

// platform files included

// Declare file included
#include <vmLibBase/CUnitTestFrame.h>

// Unit test files included
#include <tst_vmLibErr/ut_CErrBase.h>
#include <tst_vmLibErr/ut_CWinErr.h>
#include <tst_vmLibErr/ut_CError.h>
#include <tst_vmLibErr/ut_CErrno.h>

/////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, tchar** argv )
{
// --------------------------------------------------------------------------------------
// TODO : add Unit test frame functions there

    RUN_UNITTEST( ut_CErrBase  );
    RUN_UNITTEST( ut_CWinErr );
    RUN_UNITTEST( ut_CError );
    RUN_UNITTEST( ut_CErrno );

// ------------------------------------------------------------------------------------
	::system("Pause");
	return 0;
} // End of main(...)

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file tst_vmLibErr.cpp
/////////////////////////////////////////////////////////////////////////////////////////