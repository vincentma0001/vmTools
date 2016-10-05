/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTestFrame.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 30/11/2015 14:43:14
// Modify time 	: 1/12/2015 12:13:42
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

#ifndef __VM_TOOLS_CTESTFRAME_H__
#define __VM_TOOLS_CTESTFRAME_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file

/////////////////////////////////////////////////////////////////////////////////////////
// class release : 
struct stCmd;
class CAbsTestCase;
class CTestCaseFactory;

/////////////////////////////////////////////////////////////////////////////////////////
// macro definition  : for OnInit function
#ifndef TEST_CASE_B
#define TEST_CASE_B bool bRet = false;
#endif // End of TEST_CASE_B

#ifndef TEST_CASE
#define TEST_CASE( CLASS, NAME ) CLASS* p##CLASS = new CLASS( NAME );\
    bRet = RegCase( p##CLASS ); if( bRet == false ) return false;
#endif // End of TEST_CASE

#ifndef TEST_CASE_E
#define TEST_CASE_E return bRet;
#endif  // End of TEST_CASE_E

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CAbsTestFrame
//        Notes : 抽象测试框渐类，为创建测试行为提供公用行为与接口
//
/////////////////////////////////////////////////////////////////////////////////////
class CAbsTestFrame
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :

/////////////////////////////////////////////////////////////////////////////////////
// data members :
protected:
    bool                    mbIsExit;                  // 用于判断测试框架运行是否终止
    CTestCaseFactory*       mpTestCaseFactory;         // 测试事件工厂，用于对事件进行解析
    int                     miCmdNumForLine;           // 每一行显示的命令数（默认为8）
    int                     miMaxCmdLen;               // 每一条命令的最大字符串长度（默认为20个字符）


/////////////////////////////////////////////////////////////////////////////////////
// interface define :
protected:
    virtual bool OnInit( void )            { return true; }      // 为子类提供框架构建时初始化接口
    virtual void OnRelease( void )         {  };                 // 为子类提供框架结束时清理数据接口
    virtual bool OnBegin( void )           { return true; };     // 为子类提供提供命令开始时显示提示接口
    // virtual void OnBeginFailed( void )  {  };
    virtual bool OnFinish( void )          { return true; };     // 为子类提供提供命令结束时显示提示接口
    // virtual bool OnFinishFailed( void ) { return true; };

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CAbsTestFrame( const int& ciMaxCmdLen=20, 
        const int& ciCmdNumForLine=3 );         // 构造函数
    virtual ~CAbsTestFrame();                   // 析构函数
public:
    bool Run( void );                           // 主运行函数
    bool RegCase( const CAbsTestCase* const cpcEvent );     // 注册测试事件，主要在子类中的OnInit函数中使用
private:
    bool AnalyzeInput( stCmd& stuCmd );         // 对用户输入命令行进行解析
    bool Initialize( void );                    // 用于测试框架初始化操作
    bool Begin( void );                         // 用于命令开始时显示
    bool Finish( void );                        // 用于命令结束时显示
    void Release( void );                       // 用于测试框架结束时清理操作

}; // End of class CAbsTestFrame
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // end of define __VM_TOOLS_CTESTFRAME_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTestFrame.h...
/////////////////////////////////////////////////////////////////////////////////////////
