/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: VerifyDef.h
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
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

#ifndef __VM_TOOLS_VERIFYDEF_H__
#define __VM_TOOLS_VERIFYDEF_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include 
#include <eh.h>
#include "CFile.h"

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#ifdef CEXP
#   if defined (_MSC_VER) && (_MSC_VER<=1300)
//#       define THROW_INVAILED_HANDLE(pHandle, szFunc)  CEXP_F( "Get anInvailed Handle(%s)", szFunc, #pHandle );
#       define THROW_INVAILED_HANDLE(pHandle)  CEXP( "Get anInvailed Handle(%s)", #pHandle );
#       define THROW_ASSERT_FAILED(Expression) CEXP( "Assert failed Expression(%s)", #Expression )
#   else
#       define THROW_INVAILED_HANDLE(pHandle)  CEXP( "Get anInvailed Handle(%s)", #pHandle );
#       define THROW_ASSERT_FAILED(Expression) CEXP( "Assert failed Expression(%s)", #Expression )
#   endif // End of #if defined (_MSC_VER ... 
#else
#   define THROW_INVAILED_HANDLE(pHandle)  std::exception( "Get an Invailed Handle ("#pHandle")!" );
#   define THROW_ASSERT_FAILED(Expression) std::exception( "Assert failed Expression("#Expression")!" )
#endif  // End of #ifdef CEXP

/////////////////////////////////////////////////////////////////////////////////////////
// verify macro define

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
// assert macro define

#if defined (_MSC_VER) && (_MSC_VER<=1300)
#   define _ASSERT_( X ) if ( !(X) ) { throw THROW_ASSERT_FAILED(X); }
#else
#   define _ASSERT_( X ) if ( !(X) ) { throw THROW_ASSERT_FAILED(X); }
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// arithmetic macro define

#define _MAX_( A, B ) A>B?A:B
#define _MIN_( A, B ) A<B?A:B

/////////////////////////////////////////////////////////////////////////////////////////
// file macro define


/////////////////////////////////////////////////////////////////////////////////////////
// string macro define

/////////////////////////////////////////////////////////////////////////////////////////

#endif // __VM_TOOLS_VERIFYDEF_H__

/////////////////////////////////////////////////////////////////////////////////////////
// End of file VerifyDef.h
/////////////////////////////////////////////////////////////////////////////////////////