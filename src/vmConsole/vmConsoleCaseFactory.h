/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: vmConsoleCaseFactory.h
// Version 		: 0.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 4/5/2017 13:37:34
// Modify time 	: 4/5/2017 13:37:34
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

#ifndef __VMCONSOLECASEFACTORY_H__
#define __VMCONSOLECASEFACTORY_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "vmConsole.h"
#include <vmBaseLib\CSimpleMap.hpp>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : vmConsoleCaseFactory
//        Notes : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class vmConsoleCaseFactory 
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
	typedef struct tgCase
	{
		std::string				mstrCaseName;
		std::string				mstrCaseNote;
		vmConsole::PACTFUNC		mpCaseAction;
	} S_CASE, *PS_CASE;

	typedef CSimpleMap<std::string, S_CASE>                 tSimpleMap;
	typedef CSimpleMap<std::string, S_CASE>::tMapItor       tItor;
	typedef CSimpleMap<std::string, S_CASE>::tMapValue      tValueType;

/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
	tSimpleMap                   mmapEvents;      // �¼��б������ڴ洢�¼�����

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
	vmConsoleCaseFactory(){};											// Construct define
	~vmConsoleCaseFactory(){};											// Destruct define
private:
	vmConsoleCaseFactory( const vmConsoleCaseFactory& obj ){};					// No Copy
	vmConsoleCaseFactory& operator = ( const vmConsoleCaseFactory& obj ){}		// No Assignment

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:

public:
	vmConsole::PACTFUNC GetCase(const std::string szCaseName);;    // ��ȡһ�������¼�
	bool RegCase(const S_CASE& oCase);;								// ע��һ�������¼�
	tItor GetFirstCase(void);;										// ��ȡ��һ��ע����¼�
	tItor GetLastCase(void);;										// ��ȡ���һ��ע����¼�
private:
protected:

}; // End of class vmConsoleCaseFactory
/////////////////////////////////////////////////////////////////////////////////////////

} // End of namespace vm

extern vm::vmConsoleCaseFactory gCaseFactory;

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VMCONSOLECASEFACTORY_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file vmConsoleCaseFactory.h
/////////////////////////////////////////////////////////////////////////////////////////