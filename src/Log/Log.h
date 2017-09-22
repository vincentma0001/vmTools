/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: Log.h
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 10/1/2016 12:56:09
// Modify time 	: 10/1/2016 12:56:09
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

#ifndef __VM_TOOLS_LOG_H__
#define __VM_TOOLS_LOG_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file

/////////////////////////////////////////////////////////////////////////////////////////
// globe value extern
extern unsigned long gulLogFlag;

/////////////////////////////////////////////////////////////////////////////////////////
// macro define 

// 日志标志
#define LOGFLAG_ALL 0x11111111
#define LOGFLAG_NUL 0x00000000

#define LOGFLAG_INF 0x00000001
#define LOGFLAG_WAN 0x00000100
#define LOGFLAG_ERR 0x00010000

#define LOGFLAG_IW  0x00000101
#define LOGFLAG_IE  0x00010001
#define LOGFLAG_WE  0x00010100

#define LOGFLAG_IWE 0x00010101

// 日志输出宏
#define LOG_ALL( cszFormat,... ) if( gulLogFlag&LOGFLAG_ALL ) Log( cszFormat,__FUNCTION__,__LINE__,__FILE__,__VA_ARGS__ )
#define LOG_INF( cszFormat,... ) if( gulLogFlag&LOGFLAG_INF ) Log( cszFormat,__FUNCTION__,__LINE__,__FILE__,__VA_ARGS__ )
#define LOG_WAN( cszFormat,... ) if( gulLogFlag&LOGFLAG_WAN ) Log( cszFormat,__FUNCTION__,__LINE__,__FILE__,__VA_ARGS__ )
#define LOG_ERR( cszFormat,... ) if( gulLogFlag&LOGFLAG_ERR ) Log( cszFormat,__FUNCTION__,__LINE__,__FILE__,__VA_ARGS__ )

#define LOG_ALL_F( cszFormat,cszFunc,... ) if( gulLogFlag&LOGFLAG_ALL ) Log( cszFormat,cszFunc,__LINE__,__FILE__,__VA_ARGS__ )
#define LOG_INF_F( cszFormat,cszFunc,... ) if( gulLogFlag&LOGFLAG_INF ) Log( cszFormat,cszFunc,__LINE__,__FILE__,__VA_ARGS__ )
#define LOG_WAN_F( cszFormat,cszFunc,... ) if( gulLogFlag&LOGFLAG_WAN ) Log( cszFormat,cszFunc,__LINE__,__FILE__,__VA_ARGS__ )
#define LOG_ERR_F( cszFormat,cszFunc,... ) if( gulLogFlag&LOGFLAG_ERR ) Log( cszFormat,cszFunc,__LINE__,__FILE__,__VA_ARGS__ )

#define LOG_SHW( cszFormat,... ) if( gulLogFlag&LOGFLAG_ALL ) Log_show( cszFormat,__VA_ARGS__ )

/////////////////////////////////////////////////////////////////////////////////////////
// class release
class CAbsLogImp;

/////////////////////////////////////////////////////////////////////////////////////////
// functions :

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : 
// full name : 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
void Log(   const char* cszFormat,
            const char* cszFunc, 
            const unsigned long culLine, 
            const char* cszFile, 
            ...);
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : 
// full name : 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
void Log_show(const char* cszFormat, ...);
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : 
// full name : 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
void SetLogFlag(const unsigned long culLogFlag); 
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : 
// full name : 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
void SetLogBase(CAbsLogImp& oLogImp);  
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_LOG_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file Log.h
/////////////////////////////////////////////////////////////////////////////////////////