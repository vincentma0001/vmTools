/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmConsoleCaseFactory.cpp
// Version 		: 0.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 5/5/2017 8:09:46
// Modify time 	: 5/5/2017 8:09:46
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "vmConsoleCaseFactory.h"

/////////////////////////////////////////////////////////////////////////////////////////
// 
vm::vmConsoleCaseFactory gCaseFactory;

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCase
// Full name : vmConsoleCaseFactory::GetCase
// Access    : public 
// Brief     : 
// Parameter : const std::string szCaseName
// Return    : vm::vmConsole::PACTFUNC
// Notes     : 
vm::vmConsole::PACTFUNC vmConsoleCaseFactory::GetCase(const std::string szCaseName)
{
	PS_CASE pCase = mmapEvents.GetData(szCaseName);
	if (pCase == NULL)
	{
		return NULL;
	} // End of if
	vmConsole::PACTFUNC lpCaseFunc = pCase->mpCaseAction;
	return lpCaseFunc;
} // End of function GetCase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RegCase
// Full name : vmConsoleCaseFactory::RegCase
// Access    : public 
// Brief     : 
// Parameter : const S_CASE& oCase
// Return    : bool
// Notes     : 
bool vmConsoleCaseFactory::RegCase(const S_CASE& oCase)
{
	return mmapEvents.AddData(oCase.mstrCaseName, oCase);
} // End of function RegCase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetFirstCase
// Full name : vmConsoleCaseFactory::GetFirstCase
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : vm::vmConsoleCaseFactory::tItor
// Notes     : 
vm::vmConsoleCaseFactory::tItor vmConsoleCaseFactory::GetFirstCase(void)
{
	return mmapEvents.GetFirst();
} // End of function GetFirstCase(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetLastCase
// Full name : vmConsoleCaseFactory::GetLastCase
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : vm::vmConsoleCaseFactory::tItor
// Notes     : 
vm::vmConsoleCaseFactory::tItor vmConsoleCaseFactory::GetLastCase(void)
{
	return mmapEvents.GetLast();
} // End of function GetLastCase(...
/////////////////////////////////////////////////////////////////////////////////////////


} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmConsoleCaseFactory.cpp
/////////////////////////////////////////////////////////////////////////////////////////