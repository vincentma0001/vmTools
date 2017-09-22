/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmLogger.h
// Version 		: Version
// Brief 		: 
// Author 		: Author
// Create time 	: 23/6/2017 8:34:32
// Modify time 	: 23/6/2017 8:34:32
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __VMLOGGER_H__
#define __VMLOGGER_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#ifndef __VM_DLL__
#	define _DLL_API_ __declspec(dllimport)
#	pragma comment( lib,"vmLogger.lib" )
#else
#	define _DLL_API_ __declspec(dllexport)
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : vmLogger
//        Notes : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class _DLL_API_ vmLogger
{
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
	void*						mpCategory;
	static char					mszLastError[256];
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
	vmLogger(const char* const szLogName);			// Construct define
	~vmLogger();;									// Destruct define
private:
	vmLogger(const vmLogger& obj);;					// No Copy
	vmLogger& operator = (const vmLogger& obj);		// No Assignment

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
	static const char* GetErr();
	static bool Initialize(const char* const szCfgName);
public:
	void dbg(const char* const szFormat, ...);
	void inf(const char* const szFormat, ...);
	void wrn(const char* const szFormat, ...);
	void err(const char* const szFormat, ...);

	//"%X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | = [ %20S }"
//	void dbg_mem(const char* const szMemStr, const char ucFlag = ' ', unsigned int uiNumOfOneLen = 64, unsigned int uiNumOfL1Sp = 32, const char ucL1Flag = '|', unsigned int uiNumOfL2Sp = 4, const char ucL2Flag = '=');
//	void inf_mem(const char* const szMemStr, const char ucFlag = ' ', unsigned int uiNumOfOneLen = 64, unsigned int uiNumOfL1Sp = 32, const char ucL1Flag = '|', unsigned int uiNumOfL2Sp = 4, const char ucL2Flag = '=');
//	void wrn_mem(const char* const szMemStr, const char ucFlag = ' ', unsigned int uiNumOfOneLen = 64, unsigned int uiNumOfL1Sp = 32, const char ucL1Flag = '|', unsigned int uiNumOfL2Sp = 4, const char ucL2Flag = '=');
//	void err_mem(const char* const szMemStr, const char ucFlag = ' ', unsigned int uiNumOfOneLen = 64, unsigned int uiNumOfL1Sp = 32, const char ucL1Flag = '|', unsigned int uiNumOfL2Sp = 4, const char ucL2Flag = '=');

	void dbg_mem(const char* const szMemStr, const unsigned long ulMenStrLen, const char const szFormat = "%X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | = [ %S }" );
	void inf_mem(const char* const szMemStr, const unsigned long ulMenStrLen, const char const szFormat = "%X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | = [ %S }" );
	void wrn_mem(const char* const szMemStr, const unsigned long ulMenStrLen, const char const szFormat = "%X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | = [ %S }" );
	void err_mem(const char* const szMemStr, const unsigned long ulMenStrLen, const char const szFormat = "%X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | %X %X %X %X | = [ %S }" );

}; // End of class vmLogger
///////////////////////////////////////////////////////////////////////////////////////// 

} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VMLOGGER_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmLogger.h
/////////////////////////////////////////////////////////////////////////////////////////