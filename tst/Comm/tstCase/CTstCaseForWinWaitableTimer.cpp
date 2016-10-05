/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTstCaseForWinWaitableTimer.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 15/3/2016 11:01:19
// Modify time 	: 15/3/2016 11:01:19
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <Windows.h>
#include <iostream>
#include <CommInc.h>

#include "CTstCaseForWinWaitableTimer.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : OnExcute
// Full name : CTstCaseForWinWaitableTimer::OnExcute
// Access    : virtual public 
// Brief     : 
// Parameter : const stCmd& stuCmd
// Return    : void
// Notes     : 
void CTstCaseForWinWaitableTimer::OnExcute(const stCmd& stuCmd)
{
    std::cout << "this is a test for waitable timer!" << std::endl;

    CWinWaitableTimer loWTimer( "--- (A) Account 1", 1 );
    loWTimer.SetWaitableTimer( 5 );

    CWinWaitableTimer loWTimer2( "--- (B) (B) Account 2", 5 );
    loWTimer2.SetWaitableTimer( 5 );

    CWinWaitableTimer loWTimer3( "--- (C) (C) (C) Account 3", 10 );
    loWTimer3.SetWaitableTimer( 5 );

    CWinWaitForObjs loWaitForObjs( 100 );
    loWaitForObjs.AddObj( &loWTimer );
    loWaitForObjs.AddObj( &loWTimer2 );
    loWaitForObjs.AddObj( &loWTimer3 );
    
    while(1)  
    {   
        loWaitForObjs.WaitForObjs( false, INFINITE, true );
    }  

} // End of function OnExcute(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTstCaseForWinWaitableTimer.cpp
/////////////////////////////////////////////////////////////////////////////////////////