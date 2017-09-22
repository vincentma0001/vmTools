/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinWaitableTimer.h
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 15/3/2016 9:23:53
// Modify time 	: 15/3/2016 9:23:53
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CWINWAITABLETIMER_H__
#define __CWINWAITABLETIMER_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#ifndef _WINDOWS_
#   include <Windows.h>
#endif

#include <iostream>
#include "CWinAbsObjs.h"
#include "VerifyDef.h"
#include "CWinError.h"
#include "CException.h"

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CWinWaitableTimer
//        Notes : ## add class brief here #
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinWaitableTimer : public CWinAbsObj
{
/////////////////////////////////////////////////////////////////////////////////////////
private:
    LONG    mlInterval;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
    CWinWaitableTimer( LPCSTR lpTimerName,
                       LONG lInterval,
                       BOOL bManualReset = true );		            // Construct define
	virtual ~CWinWaitableTimer();                                   // Destruct define

public:
    void SetWaitableTimer( const long clFirstTime );
    bool CancelWaitableTimer( void ) const;

public:
    CTime  loTimeOfPrev;
    virtual bool ToDo( void )
    {
        CTime loTime = CTime::GetCurrTime();

        std::cout << "(" << loTimeOfPrev.ToString("%H:%M:%S") << "-" << loTime.ToString("%H:%M:%S") << ") " << mstrNameOfObj.c_str() << " ToDo() " << std::endl;

        loTimeOfPrev = loTime;
        SetWaitableTimer( mlInterval );
        return true;
    }

}; // End of class CWinWaitableTimer
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINWAITABLETIMER_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinWaitableTimer.h
/////////////////////////////////////////////////////////////////////////////////////////
