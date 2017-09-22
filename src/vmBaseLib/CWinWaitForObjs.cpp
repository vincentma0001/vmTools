/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinWaitForObjs.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 15/3/2016 14:23:54
// Modify time 	: 15/3/2016 14:23:54
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "CWinWaitForObjs.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CWinWaitForObjs
// Full name : CWinWaitForObjs::CWinWaitForObjs
// Access    : public 
// Brief     : 
// Parameter : const unsigned long culMaxHandls
// Return    : 
// Notes     : 
CWinWaitForObjs::CWinWaitForObjs(const unsigned long culMaxHandls) :mulMaxCountsOfHandles(culMaxHandls)
{
    mpHandles = new HANDLE[mulMaxCountsOfHandles];
} // End of function CWinWaitForObjs(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CWinWaitForObjs
// Full name : CWinWaitForObjs::~CWinWaitForObjs
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CWinWaitForObjs::~CWinWaitForObjs()
{
    if ( mpHandles != NULL )
    {
        for ( unsigned long i=0; i<mulMaxCountsOfHandles; i++ )
        {
            mpHandles[i] = NULL;
        } // End of for( ...

        mVecForObjs.clear();
    }
} // End of function ~CWinWaitForObjs(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : AddObj
// Full name : CWinWaitForObjs::AddObj
// Access    : public 
// Brief     : 
// Parameter : CWinAbsObj* chObj
// Return    : void
// Notes     : 
void CWinWaitForObjs::AddObj(CWinAbsObj* chObj)
{
    long llCountsOfObjs = mVecForObjs.size();

    mpHandles[llCountsOfObjs] = chObj->GetHandle();
    mVecForObjs.push_back( chObj );
} // End of function AddObj(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : WaitForObjs
// Full name : CWinWaitForObjs::WaitForObjs
// Access    : public 
// Brief     : 
// Parameter : BOOL bWaitAll, DWORD dwMillSeconds, bool bAlertable
// Return    : bool
// Notes     : 
bool CWinWaitForObjs::WaitForObjs(BOOL bWaitAll, DWORD dwMillSeconds, bool bAlertable)
{
    DWORD ldwCountOfObjs = (DWORD)mVecForObjs.size();
    DWORD ldwRet = WaitForMultipleObjectsEx( ldwCountOfObjs, mpHandles,bWaitAll, dwMillSeconds, bAlertable );
    if ( ldwRet == WAIT_TIMEOUT )
    {
        return false;
    }
    if ( ldwRet == WAIT_FAILED )
    {
        throw CEXP( "wait failed!" );
    }
    for( DWORD i=0; i<ldwCountOfObjs; i++ )
    {
        if ( (WAIT_OBJECT_0+i) == ldwRet )
        {
            CWinAbsObj* lpObj = mVecForObjs[ldwRet];
            _VERIFY_( lpObj );
            lpObj->ToDo();
            return true;
        }
    }

    throw CEXP( "Can't Get an Handle Obj!" );
    return false;
} // End of function WaitForObjs(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinWaitForObjs.cpp
/////////////////////////////////////////////////////////////////////////////////////////