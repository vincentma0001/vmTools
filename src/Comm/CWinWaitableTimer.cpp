/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinWaitableTimer.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 15/3/2016 9:23:37
// Modify time 	: 15/3/2016 9:23:37
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "CTime.h"
#include "CWinWaitableTimer.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinWaitableTimer
// Full name : CWinWaitableTimer::CWinWaitableTimer
// Access    : public 
// Brief     : 
// Parameter : LPCSTR lpTimerName, LONG lNextTime, BOOL bManualReset /*= true */
// Return    : 
// Notes     : 
CWinWaitableTimer::CWinWaitableTimer(LPCSTR lpTimerName, LONG lInterval, BOOL bManualReset /*= true */) :CWinAbsObj( lpTimerName )
{
    mlInterval = lInterval;
    loTimeOfPrev = CTime::GetCurrTime();
    mpHandle = ::CreateWaitableTimer( NULL, bManualReset, NULL );
} // End of function CWinWaitableTimer(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CWinWaitableTimer
// Full name : CWinWaitableTimer::~CWinWaitableTimer
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CWinWaitableTimer::~CWinWaitableTimer()
{
    if( mpHandle != NULL )
        ::CloseHandle( mpHandle );

    mpHandle = NULL;
} // End of function ~CWinWaitableTimer(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetWaitableTimer
// Full name : CWinWaitableTimer::SetWaitableTimer
// Access    : public 
// Brief     : 
// Parameter : const long lFirstTime
// Return    : void
// Notes     : 
void CWinWaitableTimer::SetWaitableTimer(const long lFirstTime )
{
    LARGE_INTEGER li;
    li.QuadPart=lFirstTime*(-10000000);

    if( !::SetWaitableTimer( mpHandle, 
        &li, 
        0, 
        NULL,
        NULL, 
        false ) )
    {
        CWinError loWinErr;
        throw CEXP("SetWaitableTimer failed!(%d:%s)", loWinErr.GetErrorCode(), loWinErr.GetErrorInfo() );
    }

    return;
} // End of function SetWaitableTimer(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CancelWaitableTimer
// Full name : CWinWaitableTimer::CancelWaitableTimer
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : bool
// Notes     : 
bool CWinWaitableTimer::CancelWaitableTimer(void) const
{
    if( ::CancelWaitableTimer( mpHandle ) )
        return true;
    return false;
} // End of function CancelWaitableTimer(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinWaitableTimer.cpp
/////////////////////////////////////////////////////////////////////////////////////////