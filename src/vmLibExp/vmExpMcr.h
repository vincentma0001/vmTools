/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmExpMcr.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/03 13:21:38
// Modify time 	: 2020/01/03 13:21:38
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

#ifndef __VM_EXP_MCR_H__
#define __VM_EXP_MCR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :

#ifndef   _EXCEPTION_
#	error this file need #include <exception>
#endif // _EXCEPTION_

#ifndef   __CEXP_H__
#	error this file need #include <vmLibExp/CExp.h>
#endif // __CEXP_H__

#ifndef   __CSTDEXP_H__
#	error this file need #include <vmLibExp/CStdExp.h>
#endif // __CSTDEXP_H__

#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ ) && !defined(__CWINSEHEXP_H__)
#	error this file need #include <vmLibExp/CWinSeh.h>
#endif // __CWINSEH_H__

#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ ) && !defined(__CWINSEHEXP_H__)
#	error this file need #include <vmLibExp/CWinSehExp.h>
#endif // __CWINSEHEXP_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
// --------------------------------------------------------------------------------------

#   define CEXP  ( szFunc, szFmt, ...)         vm::CExp      (       __FILE__, __LINE__, _VM_CEXP_TIMEFMT_ )( szFunc, szFmt, __VA_ARGS__)
#   define CEXP_E( oExp, szFunc, szFmt, ... )  vm::CExp      ( oExp, __FILE__, __LINE__, _VM_CEXP_TIMEFMT_ )( szFunc, szFmt, __VA_ARGS__)

#   define CSEHEXP( oSeh, szFunc, szFmt, ... ) vm::CWinSehExp( oSeh, __FILE__, __LINE__, _VM_CEXP_TIMEFMT_ )( szFunc, szFmt, __VA_ARGS__)
#   define CSTDEXP( oSeh, szFunc, szFmt, ... ) vm::CStdExp   ( oSeh, __FILE__, __LINE__, _VM_CEXP_TIMEFMT_ )( szFunc, szFmt, __VA_ARGS__)

// --------------------------------------------------------------------------------------
#   define  vTry try{

#   define  vCatch_Str( szFunc, szFmt, ... ) }catch(const char* const pExp){throw CEXP(szFunc, "%s", pExp);
#   define  vCatch_Seh( szFunc, szFmt, ... ) }catch(CWinSeh& eSeh){throw CSEHEXP(eSeh, szFunc, szFmt, __VA_ARGS__);
#   define  vCatch_Std( szFunc, szFmt, ... ) }catch(std::exception& eStdExp){throw CSTDEXP(oSeh,szFunc,szFmt,__VA_ARGS__);
#   define  vCatch_Exp( szFunc, szFmt, ... ) }catch(CExp& eExp){ if ( eExp.mExpLevel==emExp ){throw CEXP_E(oExp, szFunc, szFmt, __VA_ARGS__);}else{ /* TODO vm::CWRN( eExp, szExpFmt ).Out() */ };
#   define  vCatch_Oth( szFunc, szFmt, ... ) }catch(...){ throw CEXP( szFunc,"Get an unknown exception!" );

#   define  vCatch( szFunc, szFmt, ... )  vCatch_Str(szFunc,szFmt,__VA_ARGS__)\
                                          vCatch_Seh(szFunc,szFmt,__VA_ARGS__)\
                                          vCatch_Std(szFunc,szFmt,__VA_ARGS__)\
                                          vCatch_Exp(szFunc,szFmt,__VA_ARGS__)\
                                          vCatch_Oth(szFunc,szFmt,__VA_ARGS__)

#   define  vEnd };

// --------------------------------------------------------------------------------------
#else  // _V_PLATFORM_ != _V_PLATFORM_WIN_
// --------------------------------------------------------------------------------------

#   define CEXP( szFunc, szFmt, ...)           vm::CExp   (       szFunc, __FILE__, __LINE__,_VM_CEXP_TIMEFMT_ )(szFmt, __VA_ARGS__)
#   define CEXP( oExp, szFunc, szFmt, ... )    vm::CExp   ( oExp, szFunc, __FILE__, __LINE__,_VM_CEXP_TIMEFMT_ )(szFmt, __VA_ARGS__)

#   define CSTDEXP( oSeh, szFunc, szFmt, ... ) vm::CStdExp( oSeh, szFunc,__FILE__, __LINE__, _VM_CEXP_TIMEFMT_ )(szFmt, __VA_ARGS__)

// --------------------------------------------------------------------------------------
#   define  vTry try{

#   define  vCatch_Str( szFunc, szFmt, ... ) }catch(const char* const pExp){throw CEXP(szFunc, "%s", pExp);
#   define  vCatch_Std( szFunc, szFmt, ... ) }catch(std::exception& eStdExp){throw CSTDEXP(oSeh,szFunc,szFmt,__VA_ARGS__);
#   define  vCatch_Exp( szFunc, szFmt, ... ) }catch(CExp& eExp){ if ( eExp.mExpLevel==emExp ){throw CEXP_E(oExp, szFunc, szFmt, __VA_ARGS__);}else{ /* TODO vm::CWRN( eExp, szExpFmt ).Out() */ };
#   define  vCatch_Oth( szFunc, szFmt, ... ) }catch(...){ throw CEXP( szFunc,"Get an unknown exception!" );

#   define  vCatch( szFunc, szFmt, ... )  vCatch_Str(szFunc,szFmt,__VA_ARGS__)\
                                          vCatch_Std(szFunc,szFmt,__VA_ARGS__)\
                                          vCatch_Exp(szFunc,szFmt,__VA_ARGS__)\
                                          vCatch_Oth(szFunc,szFmt,__VA_ARGS__)

#   define  vEnd };

// --------------------------------------------------------------------------------------
#endif // #if defined ( _V_PLATFORM_ ) ...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_EXPMCR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmExpMcr.h
/////////////////////////////////////////////////////////////////////////////////////////