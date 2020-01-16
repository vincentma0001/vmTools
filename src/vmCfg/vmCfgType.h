/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmCfgType.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/08 12:16:33
// Modify time 	: 2020/01/08 12:16:33
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

#ifndef __VM_CFG_TYPE_H__
#define __VM_CFG_TYPE_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <string>
#ifndef   _STRING_
#	error this file need #include <string>
#endif // _STRING_

// Config files included
#ifndef   __VM_CFG_PLATFORM_H__
#	error this file need #include <vmCfg/vmCfgPlatform.h>
#endif // __VM_CFG_PLATFORM_H__

// Platform files included
#ifndef   _WINDOWS_
#	error this file need #include <windows.h>
#endif // _WINDOWS_

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
#if defined( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// Handle redefine :
#define tHandle       HANDLE
#define tModule       HMODULE

#define ctHandle      const HANDLE 
#define ctModule      const HMODULE

#define cctHandle     const HANDLE const
#define cctModule     const HMODULE const

/////////////////////////////////////////////////////////////////////////////////////////
// File macros redefine :
// max. length of full pathname
#define _V_FILE_MAX_PATH_    _MAX_PATH
// max. length of drive component
#define _V_FILE_MAX_DRIVE_   _MAX_DRIVE
// max. length of path component
#define _V_FILE_MAX_DIR_     _MAX_DIR
// max. length of file name component
#define _V_FILE_MAX_FNAME_   _MAX_FNAME
// max. length of extension component
#define _V_FILE_MAX_EXT_     _MAX_EXT

// --------------------------------------------------------------------------------------
#else  // ! #if defined(_V_PLATFORM_) ...
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// Handle redefine :
#define tHandle       void*
#define tModule       void*

#define ctHandle      const void*
#define ctModule      const void*

#define cctHandle     const void* const
#define cctModule     const void* const

/////////////////////////////////////////////////////////////////////////////////////////
// File macros redefine :
// max. length of full pathname
#define _V_FILE_MAX_PATH_   260 
// max. length of drive component
#define _V_FILE_MAX_DRIVE_  3
// max. length of path component
#define _V_FILE_MAX_DIR_    256
// max. length of file name component
#define _V_FILE_MAX_FNAME_  256
// max. length of extension component
#define _V_FILE_MAX_EXT_    256

// --------------------------------------------------------------------------------------
#endif //   #if defined(_V_PLATFORM_) 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// In/Out macro define :
#define _vIn_
#define _vOt_

/////////////////////////////////////////////////////////////////////////////////////////
// Max/Min macro dfine
#ifndef vMax
#define vMax(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef vMin
#define vMin(a,b)            (((a) < (b)) ? (a) : (b))
#endif



/////////////////////////////////////////////////////////////////////////////////////////
// Type redefines :

typedef unsigned char tByte;

#define tVoid         void
#define tBool         bool
#define tShort        short
#define tuShort       unsigned short
#define tInt          int
#define tuInt         unsigned int
#define tLong         long
#define tuLong        unsigned long
#define tLLong        long long
#define tuLLong       unsigned long long
#define tFloat        float
#define tDouble       double
#define tLDouble      long double

#define ctBool        const bool
#define ctShort       const short
#define ctuShort      const unsigned short
#define ctInt         const int
#define ctuInt        const unsigned int
#define ctLong        const long
#define ctuLong       const unsigned long
#define ctLLong       const long long
#define ctuLLong      const unsigned long long
#define ctFloat       const float
#define ctDouble      const double
#define ctLDouble     const long double

#define ptVoid        void*
#define ptShort       short*
#define ptuShort      unsigned short*
#define ptInt         int*
#define ptuInt        unsigned int*
#define ptLong        long*
#define ptuLong       unsigned long*
#define ptLLong       long long*
#define ptuLLong      unsigned long long*
#define ptFloat       float*
#define ptDouble      double*
#define ptLDouble     long double*

#define cptVoid       const void*
#define cptShort      const short*
#define cptuShort     const unsigned short*
#define cptInt        const int*
#define cptuInt       const unsigned int*
#define cptLong       const long*
#define cptuLong      const unsigned long*
#define cptLLong      const long long*
#define cptuLLong     const unsigned long long*
#define cptFloat      const float*
#define cptDouble     const double*
#define cptLDouble    const long double*

#define pctVoid       void* const
#define pctShort      short* const
#define pctuShort     unsigned short* const
#define pctInt        int* const
#define pctuInt       unsigned int* const
#define pctLong       long* const
#define pctuLong      unsigned long* const
#define pctLLong      long long* const
#define pctuLLong     unsigned long long* const
#define pctFloat      float* const
#define pctDouble     double* const
#define pctLDouble    long double* const

#define cpctVoid      const void* const
#define cpctShort     const short* const
#define cpctuShort    const unsigned short* const
#define cpctInt       const int* const
#define cpctuInt      const unsigned int* const
#define cpctLong      const long* const
#define cpctuLong     const unsigned long* const
#define cpctLLong     const long long* const
#define cpctuLLong    const unsigned long long* const
#define cpctFloat     const float* const
#define cpctDouble    const double* const
#define cpctLDouble   const long double* const

/////////////////////////////////////////////////////////////////////////////////////////
// size_t types redefine : 
#define tSize          size_t
#define ctSize         const size_t
#define ptSize         size_t*
#define cptSize        const size_t*
#define cpctSize       const size_t* const

/////////////////////////////////////////////////////////////////////////////////////////
// div types redefine :
#define tDiv           div_t
#define tlDiv          ldiv_t
#define tllDiv         lldiv_t

/////////////////////////////////////////////////////////////////////////////////////////
// Make type defines : 
#define vMakeShort( low, high )  ((short)(((tByte)(((short)(low)) & 0xff)) | ((short)((tByte)(((short)(high)) & 0xff))) << 8))
#define vLowShort ( val )        ((tByte)((  (short)(w))       & 0xff ))
#define vHighShort( val )        ((tByte)(( ((short)(w)) >> 8) & 0xff ))

#define vMakeInt( low, high )    ((int)(((short)(((unsigned short)(low)) & 0xffff)) | ((int)((short)(((unsigned short)(high)) & 0xffff))) << 16))
#define vLowInt ( val )          ((short)((  (unsigned int)(w))       & 0xffff ))
#define vHighInt( val )          ((short)(( ((unsigned int)(w)) >> 8) & 0xffff ))

#define vMakeLong( low, high )   ((long)(((short)(((unsigned short)(low)) & 0xffff)) | ((long)((short)(((unsigned short)(high)) & 0xffff))) << 16))
#define vLowLong ( val )         ((short)((  (unsigned long)(w))       & 0xffff ))
#define vHighLong( val )         ((short)(( ((unsigned long)(w)) >> 8) & 0xffff ))

#define vMakeLLong( low, high )  ((long long)(((long)(((unsigned long)(low)) & 0xffffffff)) | ((long long)((long)(((unsigned long)(high)) & 0xffffffff))) << 32))
#define vLowLLong ( val )        ((long)((  (unsigned long long)(w))       & 0xffffffff ))
#define vHighLLong( val )        ((long)(( ((unsigned long long)(w)) >> 8) & 0xffffffff ))

#define vMakeuShort( low, high ) ((unsigned short)(((tByte)(((unsigned short)(low)) & 0xff)) | ((unsigned short)((tByte)(((unsigned short)(high)) & 0xff))) << 8))
#define vLowuShort ( val )       ((tByte)((  (unsigned short)(w))       & 0xff ))
#define vHighuShort( val )       ((tByte)(( ((unsigned short)(w)) >> 8) & 0xff ))

#define vMakeuInt( low, high )   ((unsigned int)(((unsigned short)(((unsigned short)(low)) & 0xffff)) | ((unsigned int)((unsigned short)(((unsigned short)(high)) & 0xffff))) << 16))
#define vLowuInt ( val )         ((unsigned short)((  (unsigned int)(w))       & 0xffff ))
#define vHighuInt( val )         ((unsigned short)(( ((unsigned int)(w)) >> 8) & 0xffff ))

#define vMakeuLong( low, high )  ((unsigned long)(((unsigned short)(((unsigned short)(low)) & 0xffff)) | ((unsigned long)((unsigned short)(((unsigned short)(high)) & 0xffff))) << 16))
#define vLowuLong ( val )        ((unsigned short)((  (unsigned long)(w))       & 0xffff ))
#define vHighuLong( val )        ((unsigned short)(( ((unsigned long)(w)) >> 8) & 0xffff ))

#define vMakeullong( low, high ) ((unsigned long long)(((long)(((unsigned long)(low)) & 0xffffffff)) | ((long long)((long)(((unsigned long)(high)) & 0xffffffff))) << 32))
#define vLowullong ( val )       ((unsigned long)((  (unsigned long long)(w))       & 0xffffffff ))
#define vHighullong( val )       ((unsigned long)(( ((unsigned long long)(w)) >> 8) & 0xffffffff ))


/////////////////////////////////////////////////////////////////////////////////////////
// Type's min & max value redefines :
// Number of bits in a char object (byte),                              8 or greater*
#define vBitChar       CHAR_BIT
// Maximum number of bytes in a multibyte character, for any locale,    1 or greater *
#define vMaxMBLen      MB_LEN_MAX
// Minimum value for an object of type char,	                        either SCHAR_MIN or 0
#define vMinChar       CHAR_MIN
// Maximum value for an object of type char,	                        either SCHAR_MAX or UCHAR_MAX
#define vMaxChar       CHAR_MAX
// Minimum value for an object of type signed char,                     -127 (-27+1) or less*
#define vMinsChar      SCHAR_MIN
// Maximum value for an object of type signed char,                     127 (27-1) or greater*
#define vMaxsChar      SCHAR_MAX
// Maximum value for an object of type unsigned char,                   255 (28-1) or greater*
#define vMaxuChar      UCHAR_MAX
// Minimum value for an object of type short int,                       -32767 (-215 + 1) or less *
#define vMinsShort     SHRT_MIN
// Maximum value for an object of type short int,                       32767 (215-1) or greater*
#define vMaxsShort     SHRT_MAX
// Maximum value for an object of type unsigned short int,	            65535 (216-1) or greater*
#define vMaxuShort     USHRT_MAX
// Minimum value for an object of type int,	                            -32767 (-215+1) or less*
#define vMinsInt       INT_MIN
// Maximum value for an object of type int,	                            32767 (215-1) or greater*
#define vMaxsInt       INT_MAX
// Maximum value for an object of type unsigned int,	                65535 (216-1) or greater*
#define vMaxuInt       UINT_MAX
// Minimum value for an object of type long int,	                    -2147483647 (-231+1) or less*
#define vMinsLong      LONG_MIN
// Maximum value for an object of type long int,	                    2147483647 (231-1) or greater*
#define vMaxsLong      LONG_MAX
// Maximum value for an object of type unsigned long int,	            4294967295 (232-1) or greater*
#define vMaxuLong      ULONG_MAX
// Minimum value for an object of type long long int,	                -9223372036854775807 (-263+1) or less*
#define vMinsLLong     LLONG_MIN
// Maximum value for an object of type long long int,	                9223372036854775807 (263-1) or greater*
#define vMaxsLLong     LLONG_MAX
// Maximum value for an object of type unsigned long long int,	        18446744073709551615 (264-1) or greater*
#define vMaxuLLong     ULLONG_MAX

/////////////////////////////////////////////////////////////////////////////////////////
#if         defined( _V_USE_WCHAR_ ) && ( _V_USE_WCHAR_ == 0 )
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// String redefines :
#define tChar         char
#define tsChar        signed char
#define tuChar        unsigned char

#define ctChar        const char
#define ctsChar       const signed char
#define ctuChar       const unsigned char

#define ptChar        char*
#define ptsChar       signed char*
#define ptuChar       unsigned char*

#define cptChar       const char* 
#define cptsChar      const signed char*
#define cptuChar      const unsigned char*

#define pctChar       char* const
#define pctsChar      signed char* const
#define pctuChar      unsigned char* const

#define cpctChar      const char* const
#define cpctsChar     const signed char* const
#define cpctuChar     const unsigned char* const

#define vT(x) x
namespace vStd {
#define vString         std::string
}

/////////////////////////////////////////////////////////////////////////////////////////
// String functions redefines :
#define vStrLen(x)      strlen(x)
#define vmemset         memset
#define vmemchr         memchr
#define vmemcmp         memcmp
#define vmemcpy         memcpy
#define vmemcpy_s       memcpy_s

// --------------------------------------------------------------------------------------
#else   // !defined( _V_USE_WCHAR_ ) && ( _V_USE_WCHAR_ == 0 )
// --------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////
// String redefine :
#define tChar         wchar_t
#define tsChar        signed wchar_t
#define tuChar        unsigned wchar_t

#define ctChar        const wchar_t
#define ctsChar       const signed wchar_t
#define ctuChar       const unsigned wchar_t

#define ptChar        wchar_t*
#define ptsChar       signed wchar_t*
#define ptuChar       unsigned wchar_t*

#define cptChar       const wchar_t* 
#define cptsChar      const signed wchar_t*
#define cptuChar      const unsigned wchar_t*

#define pctChar       wchar_t* const
#define pctsChar      signed wchar_t* const
#define pctuChar      unsigned wchar_t* const

#define cpctChar      const wchar_t* const
#define cpctsChar     const signed wchar_t* const
#define cpctuChar     const unsigned wchar_t* const

#define vT(x) L##x
namespace vStd {
#define vString         std::wstring
}

/////////////////////////////////////////////////////////////////////////////////////////
// String functions redefine :
#define vStrLen(x)      wcslen(x)
#define vmemset         wmemset
#define vmemchr         wmemchr
#define vmemcmp         wmemcmp
#define vmemcpy         wmemcpy
#define vmemcpy_s       wmemcpy_s

// --------------------------------------------------------------------------------------
#endif  // !defined( _V_USE_WCHAR_ ) && ( _V_USE_WCHAR_ == 0 )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_CFG_TYPE_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmCfgType.h
/////////////////////////////////////////////////////////////////////////////////////////