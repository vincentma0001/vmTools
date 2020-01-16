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
// include file
#ifndef   _EXCEPTION_
#   error this file need #include <exception>
#endif // _EXCEPTION_

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define :

/////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DEBUG
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// Verify macro define :
#define _VERIFY_(pHandle)
#define _VERIFY_2_(pHandle1,pHandle2)
#define _VERIFY_3_(pHandle1,pHandle2,pHandle3)
#define _VERIFY_4_(pHandle1,pHandle2,pHandle3,pHandle4)
#define _VERIFY_5_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5)
#define _VERIFY_6_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6)
#define _VERIFY_7_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7)
#define _VERIFY_8_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7,pHandle8)
#define _VERIFY_9_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7,pHandle8,pHandle9)

/////////////////////////////////////////////////////////////////////////////////////////
// Assert macro define : 
#define _V_ASSERT_(X)

// --------------------------------------------------------------------------------------
#else // else for #ifndef _DEBUG
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// Verify macro define :
#ifndef CEXP
#   define THROW_INVAILED_HANDLE(pHandle)  std::exception( "Get an Invailed Handle ("#pHandle")!" );
#else
#   define THROW_INVAILED_HANDLE(pHandle)  CEXP( __FUNCTION__, "Get an Invailed Handle(%s)", #pHandle );
#endif

// --------------------------------------------------------------------------------------

#define _VERIFY_(pHandle) if(pHandle==NULL){ throw THROW_INVAILED_HANDLE(pHandle); }
#define _VERIFY_2_(pHandle1,pHandle2) \
                _VERIFY_(pHandle1);_VERIFY_(pHandle2)
#define _VERIFY_3_(pHandle1,pHandle2,pHandle3) \
                _VERIFY_(pHandle1);_VERIFY_(pHandle2);_VERIFY_(pHandle3)
#define _VERIFY_4_(pHandle1,pHandle2,pHandle3,pHandle4) \
                _VERIFY_(pHandle1);_VERIFY_(pHandle2);_VERIFY_(pHandle3);_VERIFY_(pHandle4)
#define _VERIFY_5_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5) \
                _VERIFY_(pHandle1);_VERIFY_(pHandle2);_VERIFY_(pHandle3);_VERIFY_(pHandle4);\
                _VERIFY_(pHandle5)
#define _VERIFY_6_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6) \
                _VERIFY_(pHandle1);_VERIFY_(pHandle2);_VERIFY_(pHandle3);_VERIFY_(pHandle4);\
                _VERIFY_(pHandle5);_VERIFY_(pHandle6)
#define _VERIFY_7_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7) \
                _VERIFY_(pHandle1);_VERIFY_(pHandle2);_VERIFY_(pHandle3);_VERIFY_(pHandle4);\
                _VERIFY_(pHandle5);_VERIFY_(pHandle6);_VERIFY_(pHandle7)
#define _VERIFY_8_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7,pHandle8)\
                _VERIFY_(pHandle1);_VERIFY_(pHandle2);_VERIFY_(pHandle3);_VERIFY_(pHandle4);\
                _VERIFY_(pHandle5);_VERIFY_(pHandle6);_VERIFY_(pHandle7);_VERIFY_(pHandle8)
#define _VERIFY_9_(pHandle1,pHandle2,pHandle3,pHandle4,pHandle5,pHandle6,pHandle7,pHandle8,pHandle9) \
                _VERIFY_(pHandle1);_VERIFY_(pHandle2);_VERIFY_(pHandle3);_VERIFY_(pHandle4);\
                _VERIFY_(pHandle5);_VERIFY_(pHandle6);_VERIFY_(pHandle7);_VERIFY_(pHandle8);\
                _VERIFY_(pHandle9)

/////////////////////////////////////////////////////////////////////////////////////////
// Assert macro define :
#ifndef CEXP
#   define THROW_ASSERT_FAILED(pHandle)  std::exception( "Get an Invailed Handle ("#pHandle")!" );
#else
#   define THROW_ASSERT_FAILED(pHandle)  CEXP( __FUNCTION__, "Get anInvailed Handle(%s)", #pHandle );
#endif

// --------------------------------------------------------------------------------------

#define _V_ASSERT_( X ) if ( !(X) ) { throw THROW_ASSERT_FAILED(X); }

// --------------------------------------------------------------------------------------
#endif // end of #ifndef _DEBUG
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

#endif // __VM_VERIFY_H__

/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmVerify.h
/////////////////////////////////////////////////////////////////////////////////////////
