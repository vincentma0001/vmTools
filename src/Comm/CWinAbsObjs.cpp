/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinAbsObjs.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 15/3/2016 15:14:08
// Modify time 	: 15/3/2016 15:14:08
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "CWinAbsObjs.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinAbsObj
// Full name : CWinAbsObj::CWinAbsObj
// Access    : public 
// Brief     : 
// Parameter : const char* cszNameOfObj
// Return    : 
// Notes     : 
CWinAbsObj::CWinAbsObj(const char* cszNameOfObj) :mpHandle(NULL)
{
    _VERIFY_( cszNameOfObj );
    mstrNameOfObj = cszNameOfObj;
} // End of function CWinAbsObj(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CWinAbsObj
// Full name : CWinAbsObj::~CWinAbsObj
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CWinAbsObj::~CWinAbsObj()
{

} // End of function ~CWinAbsObj(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetHandle
// Full name : CWinAbsObj::GetHandle
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : HANDLE&
// Notes     : 
HANDLE& CWinAbsObj::GetHandle()
{
    return mpHandle;
} // End of function GetHandle(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinAbsObjs.cpp
/////////////////////////////////////////////////////////////////////////////////////////