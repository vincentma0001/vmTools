/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CStdLog.h
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 10/1/2016 13:38:59
// Modify time 	: 10/1/2016 13:38:59
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

#ifndef __VM_TOOLS_CSTDLOG_H__
#define __VM_TOOLS_CSTDLOG_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "CAbsLogImp.h"

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CStdLog
//        Notes : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CStdLog : public CAbsLogImp
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
	CStdLog(){};											// Construct define
	virtual ~CStdLog(){};									// Destruct define
private:
	CStdLog( const CStdLog& obj ){};					// No Copy
	CStdLog& operator = ( const CStdLog& obj ){}		// No Evaluation

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    virtual void Output(const char* szOutput);
    virtual CAbsLogImp* clone();

}; // End of class CStdLog
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

#endif // __VM_TOOLS_CSTDLOG_H__

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CStdLog.h
/////////////////////////////////////////////////////////////////////////////////////////