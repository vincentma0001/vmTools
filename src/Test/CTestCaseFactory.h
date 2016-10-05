/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTestCaseFactory.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 30/11/2015 19:03:26
// Modify time 	: 1/12/2015 12:11:33
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

#ifndef __VM_TOOLS_CTESTCASEFACTORY_H__
#define __VM_TOOLS_CTESTCASEFACTORY_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file

#include <string>
#include <CommInc.h>
#include "CAbsTestCase.h"

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CTestCaseFactory
//        Notes : 测试事件工厂类，管理注册的测试事件
//
/////////////////////////////////////////////////////////////////////////////////////////
class CTestCaseFactory
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    typedef CSimpleMap<std::string, CAbsTestCase*>                 tSimpleMap;
    typedef CSimpleMap<std::string, CAbsTestCase*>::tMapItor       tItor;
    typedef CSimpleMap<std::string, CAbsTestCase*>::tMapValue      tValueType;

/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    tSimpleMap                         mmapEvents;      // 事件列表，用于存储事件对象

/////////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CTestCaseFactory(){};                                       // 构造函数
    virtual ~CTestCaseFactory();;                                       // 析构函数
public:
    CAbsTestCase* GetCase( const std::string& strCaseName );    // 获取一个测试事件
    bool RegCase( const CAbsTestCase* const pCase );            // 注册一个测试事件
    tItor GetFirstCase( void );                                 // 获取第一个注册的事件
    tItor GetLastCase( void );                                  // 获取最后一个注册的事件

}; // End of class CTestEventFactory
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_CTESTCASEFACTORY_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTestCaseFactory.h
/////////////////////////////////////////////////////////////////////////////////////////