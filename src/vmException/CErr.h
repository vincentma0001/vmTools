/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CError.h
// Version 		: 0.0.0.1
// Brief 		: 此文件定义了关于windows系统中关于Error中的操作
// Auther 		: v.m.
// Create time 	: 1/12/2015 12:57:59
// Modify time 	: 1/12/2015 12:57:59
// Note 		:
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition

#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CERROR_H__
#define __CERROR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CError
//        Notes : 这个类封装了在windows中关于错误代码的操作
/////////////////////////////////////////////////////////////////////////////////////////
class CErr
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :
#define _CERR_MAX_FMT_DES_ 2048

/////////////////////////////////////////////////////////////////////////////////////////
// data members :
public:
    unsigned long       mdwErrCode;          // 错误代码
    std::string         mstrErrDes;          // 错误代码描述

/////////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CErr    ( void );                                 // construct define
	CErr    ( const unsigned long dwErrCode ); 	            // construct define
	
    CErr( const CErr& cErr )
    {
        mdwErrCode = cErr.mdwErrCode;
        mstrErrDes = cErr.mstrErrDes;
    }
    ~CErr   ( void );	                                // destruct define
    CErr& operator=( const CErr& cErr )
    {
        mdwErrCode = cErr.mdwErrCode;
        mstrErrDes = cErr.mstrErrDes;
    }

public:
    virtual std::string ToString( const std::string& cstrFormat );           // 对错误码格式化输出
    virtual std::string ToString( void );                                    // 对错误码格式化输出

protected:

}; // End of class CError
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CERROR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CError.h
/////////////////////////////////////////////////////////////////////////////////////////