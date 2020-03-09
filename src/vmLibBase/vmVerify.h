/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmVerify.h
// Version 		: 0.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 10/1/2016 15:33:10
// Modify time 	: 10/1/2016 15:33:10
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

#ifndef __VM_VERIFY_H__
#define __VM_VERIFY_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :

#ifndef   __VM_CFG_TSTRING_H__
#   include <vmCfg/vmCfgtString.h>
#endif // __VM_CFG_TSTRING_H__

/////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DEBUG
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// Verify macro define :
#define _VERIFY_(func, pHandle)
#define _VERIFY_2_(func, pHandle1, pHandle2)
#define _VERIFY_3_(func, pHandle1, pHandle2, pHandle3)
#define _VERIFY_4_(func, pHandle1, pHandle2, pHandle3, pHandle4)
#define _VERIFY_5_(func, pHandle1, pHandle2, pHandle3, pHandle4, pHandle5)
#define _VERIFY_6_(func, pHandle1, pHandle2, pHandle3, pHandle4, pHandle5, pHandle6)
#define _VERIFY_7_(func, pHandle1, pHandle2, pHandle3, pHandle4, pHandle5, pHandle6, pHandle7)
#define _VERIFY_8_(func, pHandle1, pHandle2, pHandle3, pHandle4, pHandle5, pHandle6, pHandle7, pHandle8)
#define _VERIFY_9_(func, pHandle1, pHandle2, pHandle3, pHandle4, pHandle5, pHandle6, pHandle7, pHandle8, pHandle9)

/////////////////////////////////////////////////////////////////////////////////////////
// Assert macro define : 
#define _V_ASSERT_(X)

// --------------------------------------------------------------------------------------
#else // else for #ifndef _DEBUG
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// Verify macro define :
#ifndef    THROW_INVAILED_HANDLE
#   define THROW_INVAILED_HANDLE(func, pHandle)  vT(#func" - Get an Invailed Handle ("#pHandle")!")
#endif //  THROW_INVAILED_HANDLE

// --------------------------------------------------------------------------------------

#define _VERIFY_(func, pHandle)   if(pHandle==NULL){ throw THROW_INVAILED_HANDLE(func, pHandle); }
#define _VERIFY_2_(func, pHandle1,pHandle2) \
                _VERIFY_(func, pHandle1);_VERIFY_(func, pHandle2)
#define _VERIFY_3_(func, pHandle1,pHandle2,pHandle3) \
                _VERIFY_(func, pHandle1);_VERIFY_(func, pHandle2);_VERIFY_(func, pHandle3)
#define _VERIFY_4_(func, pHandle1,pHandle2,pHandle3,pHandle4) \
                _VERIFY_(func, pHandle1);_VERIFY_(func, pHandle2);_VERIFY_(func, pHandle3);_VERIFY_(func, pHandle4)
#define _VERIFY_5_(func, pHandle1,pHandle2,pHandle3,pHandle4,pHandle5) \
                _VERIFY_(func, pHandle1);_VERIFY_(func, pHandle2);_VERIFY_(func, pHandle3);_VERIFY_(func, pHandle4);\
                _VERIFY_(func, pHandle5)
#define _VERIFY_6_(func, pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6) \
                _VERIFY_(func, pHandle1);_VERIFY_(func, pHandle2);_VERIFY_(func, pHandle3);_VERIFY_(func, pHandle4);\
                _VERIFY_(func, pHandle5);_VERIFY_(func, pHandle6)
#define _VERIFY_7_(func, pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7) \
                _VERIFY_(func, pHandle1);_VERIFY_(func, pHandle2);_VERIFY_(func, pHandle3);_VERIFY_(func, pHandle4);\
                _VERIFY_(func, pHandle5);_VERIFY_(func, pHandle6);_VERIFY_(func, pHandle7)
#define _VERIFY_8_(func, pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7,pHandle8)\
                _VERIFY_(func, pHandle1);_VERIFY_(func, pHandle2);_VERIFY_(func, pHandle3);_VERIFY_(func, pHandle4);\
                _VERIFY_(func, pHandle5);_VERIFY_(func, pHandle6);_VERIFY_(func, pHandle7);_VERIFY_(func, pHandle8)
#define _VERIFY_9_(func, pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7,pHandle8,pHandle9) \
                _VERIFY_(func, pHandle1);_VERIFY_(func, pHandle2);_VERIFY_(func, pHandle3);_VERIFY_(func, pHandle4);\
                _VERIFY_(func, pHandle5);_VERIFY_(func, pHandle6);_VERIFY_(func, pHandle7);_VERIFY_(func, pHandle8);\
                _VERIFY_(func, pHandle9)

/////////////////////////////////////////////////////////////////////////////////////////
// Assert macro define :
#ifndef    THROW_ASSERT_FAILED
#   define THROW_ASSERT_FAILED(func, pHandle) vT(""#func"Get an Invailed Handle ("#pHandle")!" )
#endif  // THROW_ASSERT_FAILED

// --------------------------------------------------------------------------------------

#define _ASSERT_( func, X ) if ( !(X) ) { throw THROW_ASSERT_FAILED(func, X); }

// --------------------------------------------------------------------------------------
#endif // end of #ifndef _DEBUG
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

#endif // __VM_VERIFY_H__

/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmVerify.h
/////////////////////////////////////////////////////////////////////////////////////////
