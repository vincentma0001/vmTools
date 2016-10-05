/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CExpTrack.h
// Version 		: 0.0.1.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 27/12/2015 15:18:53
// Modify time 	: 27/12/2015 15:18:53
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

#ifndef __VM_TOOLS_CEXPTRACK_H__
#define __VM_TOOLS_CEXPTRACK_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <list>

#include "CSingleTon.h"
#include "CWinCS.h"
#include "CException.h"

/////////////////////////////////////////////////////////////////////////////////////
// macro define

#define EXP_TRACK_ADD( Exp )            CSingleton<class CExpTrack,class CWinCS>::Instance()->Add( Exp );
#define EXP_TRACK_CLEAR()               CSingleton<class CExpTrack,class CWinCS>::Instance()->Clear();
#define EXP_TRACK_SETDUMP( DumpImp )    CSingleton<class CExpTrack,class CWinCS>::Instance()->SetDump( DumpImp );
#define EXP_TRACK_DUMP()                CSingleton<class CExpTrack,class CWinCS>::Instance()->Dump();
#define EXP_TRACK_BEGIN()               CSingleton<class CExpTrack,class CWinCS>::Instance()->Begin()
#define EXP_TRACK_END()                 CSingleton<class CExpTrack,class CWinCS>::Instance()->End()

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CAbsDumpImp
//        Notes : ## add class brief here #
//
/////////////////////////////////////////////////////////////////////////////////////////
class CAbsDumpImp
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
	CAbsDumpImp(){};		            // Construct define
	virtual ~CAbsDumpImp(){};          // Destruct define

/////////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    virtual void Dump() = 0;

}; // End of class CAbsDumpImp
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CExpTrack
//        Notes : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////
class CExpTrack : CSingleton< CExpTrack, CWinCS >
{
/////////////////////////////////////////////////////////////////////////////////////
// type define :
public:
    typedef std::list<JL::CException>                  tlist;
    typedef std::list<JL::CException>::iterator        tItor;
    typedef std::list<JL::CException>::const_iterator  ctItor;
/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    tlist           mlistExp;                   // 异常列表
    CAbsDumpImp*    mpDump;                     // 异常输出实现

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
	CExpTrack();                                // Construct define
    CExpTrack( CAbsDumpImp* pDump );            // Construct define
	virtual ~CExpTrack();                       // Destruct define

public:
    void Dump( void );                          // 输出异常信息
    void SetDump( CAbsDumpImp* pDumpImp );      // 设置异常信息输出

public:
    void Add( const JL::CException& exp );          // 添加一个异常对象
    void Clear( void );                         // 清理跟踪的异常对象

public:
    tItor Begin();                              // 获取异常信息列表中的第一个元素
    tItor End();                                // 获取异常信息列表中的最后一个元素

}; // End of class CExpTrack
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __VM_TOOLS_CEXPTRACK_H__

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CExpTrack.h
/////////////////////////////////////////////////////////////////////////////////////////