/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : ut_CList.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/03/29 17:10:34
// Modify time  : 2020/03/29 17:10:34
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

#ifndef __UT_CLIST_H__
#define __UT_CLIST_H__

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
#include <vmLibBase/CList.h>

/////////////////////////////////////////////////////////////////////////////////////////
// Extern functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test functions :
// TODO : Add unit test function here

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CList_T1 )
{
    bool lbRet = true;
    // #Add test content here#

    vm::CList lList;
    tchar lStr1[ 256 ] = { vT("T1") };
    lList.AddHead( (void*)lStr1 );
    tchar lStr2[ 256 ] = { vT("T2") };
    lList.AddHead( (void*)lStr2 );
    tchar lStr3[ 256 ] = { vT("T3") };
    lList.AddHead( (void*)lStr3 );

    vm::CList* lpList = &lList;
    int liCount = 0;
    while (lpList!=nullptr)
    {
        vm::utLogLine("List #%d - %s", ++liCount, (tchar*)lpList->Get());
        lpList = lpList->Next();        
    }

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CList_T2 )
{
    bool lbRet = true;
    // #Add test content here#

    vm::CList lList;
    tchar lStr1[ 256 ] = { vT("T1") };
    lList.AddTail((void*)lStr1);
    tchar lStr2[ 256 ] = { vT("T2") };
    lList.AddTail((void*)lStr2);
    tchar lStr3[ 256 ] = { vT("T3") };
    lList.AddTail((void*)lStr3);

    vm::CList* lpList = &lList;
    int liCount = 0;
    while (lpList != nullptr)
    {
        vm::utLogLine("List #%d - %s", ++liCount, (tchar*)lpList->Get());
        lpList = lpList->Next();
    }

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CList_T3 )
{
    bool lbRet = true;
    // #Add test content here#

    vm::CList lList;
    tchar lStr1[ 256 ] = { vT("T1") };
    lList.AddTail((void*)lStr1);
    tchar lStr2[ 256 ] = { vT("T2") };
    lList.AddTail((void*)lStr2);
    tchar lStr3[ 256 ] = { vT("T3") };
    lList.AddTail((void*)lStr3);
    tchar lStr4[ 256 ] = { vT("New T1") };
    lList.AddHead((void*)lStr4);

    vm::CList* lpList = &lList;
    int liCount = 0;
    while (lpList != nullptr)
    {
        vm::utLogLine("List #%d - %s", ++liCount, (tchar*)lpList->Get());
        lpList = lpList->Next();
    }

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
TEST_FUNC_BEGIN( ut_CList_T4 )
{
    bool lbRet = true;
    // #Add test content here#

    vm::CList lList;
    tchar lStr1[ 256 ] = { vT("T1") };
    lList.AddHead((void*)lStr1);
    tchar lStr2[ 256 ] = { vT("T2") };
    lList.AddHead((void*)lStr2);
    tchar lStr3[ 256 ] = { vT("T3") };
    lList.AddHead((void*)lStr3);
    tchar lStr4[ 256 ] = { vT("New T3") };
    lList.AddTail((void*)lStr4);

    vm::CList* lpList = &lList;
    int liCount = 0;
    while (lpList != nullptr)
    {
        vm::utLogLine("List #%d - %s", ++liCount, (tchar*)lpList->Get());
        lpList = lpList->Next();
    }

    return lbRet;

    return lbRet;
}
TEST_FUNC_ENDED
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Unit test frame define :
// TODO : Regis unit test function here
UNIT_TEST_BEGIN( ut_CList )
    // example : UNIT_TEST_REGIST(Func1)
    UNIT_TEST_REGIST(ut_CList_T1);
    UNIT_TEST_REGIST(ut_CList_T2);
    UNIT_TEST_REGIST(ut_CList_T3);
    UNIT_TEST_REGIST(ut_CList_T4);
UNIT_TEST_ENDED

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __UT_CLIST_H__
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file ut_CList.h
/////////////////////////////////////////////////////////////////////////////////////////