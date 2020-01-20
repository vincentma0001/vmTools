/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CUnitTestFrame.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/14 08:21:05
// Modify time  : 2020/01/14 08:21:05
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

#ifndef __CUNITTESTFRAME_H__
#define __CUNITTESTFRAME_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Disable warnings :
// Example : #pragma warning(disable:4996)
#if defined (_MSC_VER)
#   pragma warning(disable:4996)
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdio.h>
#include <stdarg.h>
#include <list>

// Config files included
// #include <vmcfg.h>

// Platform files included

// Used files included
//#include <vmLibBase/vmUtil.h>
//#include <vmLibBase/CString.hpp>
#include <vmLibIPC/CWinConsole.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Output function :
// TODO : the functions of here will be in other files.
void utLog(const tchar* const cpFmt, ...)
{
    vm::CWinConsole loConsole;

    va_list vList;
    va_start(vList, cpFmt);
    loConsole.Write( vm::CWinConsole::emColor::vfLightWhite, cpFmt, vList );
    va_end(vList);
}

void utLog( const short csTxtColor,  const tchar* const cpFmt, ...)
{
    vm::CWinConsole loConsole;
    
    va_list vList;
    va_start(vList, cpFmt);
    loConsole.Write( csTxtColor, cpFmt, vList );
    va_end(vList);
    
}

void utLogLine(const tchar* const cpFmt, ...)
{
    vm::CWinConsole loConsole;

    loConsole.Write( vm::CWinConsole::emColor::vfDarkYellow, vT("// ") );
    va_list vList;
    va_start(vList, cpFmt);
    loConsole.Write(vm::CWinConsole::emColor::vfLightWhite, cpFmt, vList);
    va_end(vList);
    loConsole.Write( vm::CWinConsole::emColor::vfDarkYellow, vT("\n") );
}


/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines : 
#ifndef   __V_UNIT_TEST_MACRO__
#define   __V_UNIT_TEST_MACRO__

#define TEST_FUNC_BEGIN(func) class func : public vm::CUnit { public: func():CUnit(vT(#func)){}; ~func(){}; public: virtual bool toDo(void)
#define TEST_FUNC_ENDED };
#define UNIT_TEST_BEGIN( unFrame ) class unFrame : public vm::CUnitTestFrame{ virtual void Regist() {
#define UNIT_TEST_REGIST(func)  {func* lp##func = new func ; mListUnits.push_back( lp##func );}
#define UNIT_TEST_ENDED } };
#define RUN_UNITTEST( utFrame ) utFrame lo##utFrame; lo##utFrame.Run()

#endif // __V_UNIT_TEST_MACRO__

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CUnit : this is a test unit for unit test frame
//
/////////////////////////////////////////////////////////////////////////////////////////
class CUnit
{
/////////////////////////////////////////////////////////////////////////////////////////
// Friend define :
friend class CUnitTestFrame;

////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline CUnit( const tchar* const cpName ) { vStrcpy( mszName, cpName ); };
    // Destruct define
    inline virtual ~CUnit(){};

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
public:
    tchar mszName[256];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // This function defined what will be done in test unit
    inline virtual bool toDo(void) = 0;
    
}; // End of class CUnit
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CUnitTestFrame : this is a unit test frame class
//
/////////////////////////////////////////////////////////////////////////////////////////
class CUnitTestFrame
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
public:
    typedef typename std::list<CUnit*>               tList;
    typedef typename std::list<CUnit*>::iterator     tListItor;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CUnitTestFrame(){};
    // Destruct define
    inline virtual ~CUnitTestFrame()
    {
        tListItor loIter = mListUnits.begin();
        for (; loIter != mListUnits.end(); loIter++)
        {
            CUnit* lpFunc = (*loIter);
            delete lpFunc;
            (*loIter) = nullptr;
        }

    };
    
private:
    // No Copy
    inline CUnitTestFrame(const CUnitTestFrame& obj){};
    // No Assignment
    inline CUnitTestFrame& operator = ( const CUnitTestFrame& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
protected:
    tList  mListUnits;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:

    // Run all unit test
    void Run( void )
    {
        Regist();

        tListItor loIter = mListUnits.begin();
        for ( ; loIter!=mListUnits.end(); loIter++  )
        {
            CUnit* lpFunc = (*loIter);
            utLog( vT("\n") );
            utLog( vm::CWinConsole::emColor::vfDarkYellow, vT("/////////////////////////////////////////////////////////////////////////////////////////\n") );
            utLog( vm::CWinConsole::emColor::vfDarkYellow, vT("// "));
            utLog( vm::CWinConsole::emColor::vfLightYellow,vT("%s is running ... \n"), lpFunc->mszName );
            utLog(vm::CWinConsole::emColor::vfDarkYellow, vT("// "));
            utLog( vm::CWinConsole::emColor::vfLightWhite, vT("======================================================================================\n"));
            utLog(vm::CWinConsole::emColor::vfDarkYellow, vT("// "));
            utLog(vm::CWinConsole::emColor::vfLightWhite, vT("\n"));
            bool lbRet = lpFunc->toDo();
            utLog(vm::CWinConsole::emColor::vfDarkYellow, vT("// "));
            utLog( vm::CWinConsole::emColor::vfLightWhite, vT("\n"));
            utLog(vm::CWinConsole::emColor::vfDarkYellow, vT("// "));
            utLog( vm::CWinConsole::emColor::vfLightWhite, vT("======================================================================================\n"));
            utLog( vm::CWinConsole::emColor::vfDarkYellow, vT("// "));
            // #  TODO : Add condition brife here ##
            if  ( lbRet == TRUE )
            { utLog(vm::CWinConsole::emColor::vfLightGreen, vT("%s is %s\n"), lpFunc->mszName, vT("Succeed") ); }
            else
            { utLog(vm::CWinConsole::emColor::vfLightRed,   vT("%s is %s\n"), lpFunc->mszName, vT("Failed")); }
             // End of if () ...
            utLog( vm::CWinConsole::emColor::vfDarkYellow,  vT("/////////////////////////////////////////////////////////////////////////////////////////\n") );
            utLog( vm::CWinConsole::emColor::vfDarkYellow,  vT("\n") );
            
        }

    }

    // Regist a unit test function class to frame
    virtual void Regist( void ) = 0;

}; // End of class CUnitTestFrame
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CUNITTESTFRAME_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CUnitTestFrame.h
/////////////////////////////////////////////////////////////////////////////////////////