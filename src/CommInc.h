/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CommInc.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 20/12/2015 10:52:32
// Modify time 	: 20/12/2015 10:52:32
// Note 		:
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

#ifndef __VM_TOOLS_COMMINC_H__
#define __VM_TOOLS_COMMINC_H__

/////////////////////////////////////////////////////////////////////////////////////////
// lib file :
#pragma comment(lib,"LibComm.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// include file

#include <Comm/DllMacro.h>

#include <Comm/CAtom.h>
#include <Comm/CWinCS.h>

#include <Comm/CSimpleMap.h>
#include <Comm/CSingleTon.h>

#include <Comm/CWinSeh.h>

#include <Comm/CException.h>
#include <Comm/CCppExp.h>
#include <Comm/CWinSehExp.h>

#include <Comm/CError.h>
#include <Comm/CWinError.h>
#include <Comm/CWinSeh.h>

#include <Comm/CBit.h>
#include <Comm/CTime.h>

#include <Comm/CWinAbsObjs.h>
#include <Comm/CWinWaitForObjs.h>
#include <Comm/CWinWaitableTimer.h>

#include <Comm/CRand.h>
#include <Comm/CThread.h>

/////////////////////////////////////////////////////////////////////////////////////////

#endif // __VM_TOOLS_COMMINC_H__

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CommInc.h
/////////////////////////////////////////////////////////////////////////////////////////