/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmCfgPlatform.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/05 11:31:59
// Modify time 	: 2020/01/05 11:31:59
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

#ifndef __VM_CFGPLATFORM_H__
#define __VM_CFGPLATFORM_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define

// Platform macro define :
#define __V_PLATFORM_WIN__              1100000
#define __V_PLATFORM_TARGET_WIN32__     1100001
#define __V_PLATFORM_TARGET_WIN64__     1100002

#define __V_PLATFORM_LUX__              1200000
#define __V_PLATFORM_TARGET_LUN32__     1200001
#define __V_PLATFORM_TARGET_LUN64__     1200002

#define __V_USE_WCHAR__                 0

/////////////////////////////////////////////////////////////////////////////////////////
// Window platform macro define
#ifdef _WIN32
// --------------------------------------------------------------------------------------

// Platform define :
#ifdef    _V_PLATFORM
#   error Macro _V_PLATFORM has defined!
#else  // _V_PLATFORM
#   define _V_PLATFORM  __V_PLATFORM_WIN__
#endif // _V_PLATFORM

// --------------------------------------------------------------------------------------

// Platform target define :
#ifdef    _WIN64
#   define _V_PLATFORM_TARGET __V_PLATFORM_TARGET_WIN64__
#else  // _WIN64
#   define _V_PLATFORM_TARGET __V_PLATFORM_TARGET_WIN32__
#endif // _WIN64

// --------------------------------------------------------------------------------------


// Redefine __V_USE_WCHAR__
#ifdef    UNICODE
#   undef  __V_USE_WCHAR__
#   define __V_USE_WCHAR__ 1
#endif // UNICODE

// --------------------------------------------------------------------------------------
#endif // _WIN32
/////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_CFGPLATFORM_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmCfgPlatform.h
/////////////////////////////////////////////////////////////////////////////////////////
