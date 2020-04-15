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

#ifndef __VM_CFG_PLATFORM_H__
#define __VM_CFG_PLATFORM_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define

// Platform macro define :
#define _V_PF_WIN_              1100000
#define _V_PF_TARGET_WIN32_     1100001
#define _V_PF_TARGET_WIN64_     1100002

#define _V_PF_LUX_              1200000
#define _V_PF_TARGET_LUN32_     1200001
#define _V_PF_TARGET_LUN64_     1200002

#define _V_USE_WCHAR_                 0

/////////////////////////////////////////////////////////////////////////////////////////
// Window platform macro define
#ifdef _WIN32
// --------------------------------------------------------------------------------------

// Platform define :
#ifdef    _V_PLATFORM_
#   error Macro _V_PLATFORM has defined!
#else  // _V_PLATFORM
#   define _V_PLATFORM_  _V_PF_WIN_
#endif // _V_PLATFORM

// --------------------------------------------------------------------------------------

// Platform target define :
#ifdef    _WIN64
#   define _V_PLATFORM_TARGET_ _V_PF_TARGET_WIN64_
#else  // _WIN64
#   define _V_PLATFORM_TARGET_ _V_PF_TARGET_WIN32_
#endif // _WIN64

// --------------------------------------------------------------------------------------


// Redefine _V_USE_WCHAR_
#ifdef    UNICODE
#   undef  _V_USE_WCHAR_
#   define _V_USE_WCHAR_ 1
#endif // _V_USE_WCHAR_

/////////////////////////////////////////////////////////////////////////////////////////
// include files :
#ifndef   _WINDOWS_
#   include <windows.h>
#endif // _WINDOWS_

// --------------------------------------------------------------------------------------
#endif // _WIN32
/////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_CFG_PLATFORM_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmCfgPlatform.h
/////////////////////////////////////////////////////////////////////////////////////////
