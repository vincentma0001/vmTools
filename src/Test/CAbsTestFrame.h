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
//        Notes : ������Կ��࣬Ϊ����������Ϊ�ṩ������Ϊ��ӿ�
//
/////////////////////////////////////////////////////////////////////////////////////
class CAbsTestFrame
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :

/////////////////////////////////////////////////////////////////////////////////////
// data members :
protected:
    bool                    mbIsExit;                  // �����жϲ��Կ�������Ƿ���ֹ
    CTestCaseFactory*       mpTestCaseFactory;         // �����¼����������ڶ��¼����н���
    int                     miCmdNumForLine;           // ÿһ����ʾ����������Ĭ��Ϊ8��
    int                     miMaxCmdLen;               // ÿһ�����������ַ������ȣ�Ĭ��Ϊ20���ַ���


/////////////////////////////////////////////////////////////////////////////////////
// interface define :
protected:
    virtual bool OnInit( void )            { return true; }      // Ϊ�����ṩ��ܹ���ʱ��ʼ���ӿ�
    virtual void OnRelease( void )         {  };                 // Ϊ�����ṩ��ܽ���ʱ�������ݽӿ�
    virtual bool OnBegin( void )           { return true; };     // Ϊ�����ṩ�ṩ���ʼʱ��ʾ��ʾ�ӿ�
    // virtual void OnBeginFailed( void )  {  };
    virtual bool OnFinish( void )          { return true; };     // Ϊ�����ṩ�ṩ�������ʱ��ʾ��ʾ�ӿ�
    // virtual bool OnFinishFailed( void ) { return true; };

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CAbsTestFrame( const int& ciMaxCmdLen=20, 
        const int& ciCmdNumForLine=3 );         // ���캯��
    virtual ~CAbsTestFrame();                   // ��������
public:
    bool Run( void );                           // �����к���
    bool RegCase( const CAbsTestCase* const cpcEvent );     // ע������¼�����Ҫ�������е�OnInit������ʹ��
private:
    bool AnalyzeInput( stCmd& stuCmd );         // ���û����������н��н���
    bool Initialize( void );                    // ���ڲ��Կ�ܳ�ʼ������
    bool Begin( void );                         // �������ʼʱ��ʾ
    bool Finish( void );                        // �����������ʱ��ʾ
    void Release( void );                       // ���ڲ��Կ�ܽ���ʱ�������

}; // End of class CAbsTestFrame
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // end of define __VM_TOOLS_CTESTFRAME_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTestFrame.h...
/////////////////////////////////////////////////////////////////////////////////////////
