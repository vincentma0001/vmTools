/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmLogger.cpp
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 3/7/2017 8:01:29
// Modify time 	: 3/7/2017 8:01:29
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

#pragma comment( lib,"log4cppD.lib" )
#pragma comment( lib,"WS2_32.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "vmLogger.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#ifndef VM_MAX_BUF
#define VM_MAX_BUF 10240
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// class release 
char vm::vmLogger::mszLastError[256] = { 0 };

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : vmLogger
// Full name : vm::vmLogger::vmLogger
// Access    : private 
// Brief     : 
// Parameter : const char* const szLogName, const char* const szCfgName
// Return    : 
// Notes     : 
vm::vmLogger::vmLogger(const char* const szLogName) :mpCategory(0)
{
	this->mpCategory = (void*)(&log4cpp::Category::getInstance(szLogName));
} // End of function vmLogger(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetLastErr
// Full name : vm::vmLogger::GetLastErr
// Access    : public static 
// Brief     : 
// Parameter : 
// Return    : const char*
// Notes     : 
const char* vm::vmLogger::GetErr()
{
	return mszLastError;
} // End of function GetLastErr(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Initialize
// Full name : vm::vmLogger::Initialize
// Access    : public static 
// Brief     : 
// Parameter : const char* const szCfgName
// Return    : bool
// Notes     : 
bool vm::vmLogger::Initialize(const char* const szCfgName)
{
	try
	{
		log4cpp::PropertyConfigurator::configure(szCfgName);
	}
	catch (log4cpp::ConfigureFailure& f)
	{
		memset(mszLastError, 0x00, sizeof(mszLastError));
		memcpy(mszLastError, f.what(), strlen(f.what()));
		return false;
	}

	return true;
} // End of function Initialize(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : debug
// Full name : vm::vmLogger::debug
// Access    : public 
// Brief     : 
// Parameter : const char* const szFormat, ...
// Return    : void
// Notes     : 
void vm::vmLogger::dbg(const char* const szFormat, ...)
{
	char szBuf[VM_MAX_BUF] = { 0 };
	va_list vp;
	va_start(vp, szFormat);
	vsprintf_s(szBuf, sizeof(szBuf), szFormat, vp);
	va_end(vp);

	((log4cpp::Category*)mpCategory)->debug(szBuf);
} // End of function debug(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : info
// Full name : vm::vmLogger::info
// Access    : public 
// Brief     : 
// Parameter : const char* const szFormat, ...
// Return    : void
// Notes     : 
void vm::vmLogger::inf(const char* const szFormat, ...)
{
	char szBuf[VM_MAX_BUF] = { 0 };
	va_list vp;
	va_start(vp, szFormat);
	vsprintf_s(szBuf, sizeof(szBuf), szFormat, vp);
	va_end(vp);

	((log4cpp::Category*)mpCategory)->info(szBuf);
} // End of function info(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : warn
// Full name : vm::vmLogger::warn
// Access    : public 
// Brief     : 
// Parameter : const char* const szFormat, ...
// Return    : void
// Notes     : 
void vm::vmLogger::wrn(const char* const szFormat, ...)
{
	char szBuf[VM_MAX_BUF] = { 0 };
	va_list vp;
	va_start(vp, szFormat);
	vsprintf_s(szBuf, sizeof(szBuf), szFormat, vp);
	va_end(vp);

	((log4cpp::Category*)mpCategory)->warn(szBuf);
} // End of function warn(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : error
// Full name : vm::vmLogger::error
// Access    : public 
// Brief     : 
// Parameter : const char* const szFormat, ...
// Return    : void
// Notes     : 
void vm::vmLogger::err(const char* const szFormat, ...)
{
	char szBuf[VM_MAX_BUF] = { 0 };
	va_list vp;
	va_start(vp, szFormat);
	vsprintf_s(szBuf, sizeof(szBuf), szFormat, vp);
	va_end(vp);

	((log4cpp::Category*)mpCategory)->error(szBuf);
} // End of function error(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=
// Full name : vm::vmLogger::operator=
// Access    : private 
// Brief     : 
// Parameter : const vmLogger& obj
// Return    : vm::vmLogger&
// Notes     : 
vm::vmLogger& vm::vmLogger::operator=(const vmLogger& obj)
{
	return *this;
} // End of function operator=(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~vmLogger
// Full name : vm::vmLogger::~vmLogger
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
vm::vmLogger::~vmLogger()
{
	if ( mpCategory != 0 )
	{
		((log4cpp::Category*)mpCategory)->shutdown();
		mpCategory = 0;
	}
} // End of function ~vmLogger(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : vmLogger
// Full name : vm::vmLogger::vmLogger
// Access    : private 
// Brief     : 
// Parameter : const vmLogger& obj
// Return    : 
// Notes     : 
vm::vmLogger::vmLogger(const vmLogger& obj)
{

} // End of function vmLogger(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmLogger.cpp
/////////////////////////////////////////////////////////////////////////////////////////