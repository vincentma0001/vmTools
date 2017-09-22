/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySqlValue.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 8/12/2015 13:37:01
// Modify time 	: 8/12/2015 13:37:01
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

#ifndef __CSTRINGTRAN_H__
#define __CSTRINGTRAN_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>
#include <vector>

#ifndef __VM_TOOLS_DLLMACRO_H__
#   error This file is need #include <DllMacro.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// macro 
EXPORT_STL_STRING( DLL_MACRO )

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CMySqlValue
//        Notes : ## add class brief here #
//
/////////////////////////////////////////////////////////////////////////////////////
class DLL_MACRO CMySqlValue
{
/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    const char* mpStr;

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
	CMySqlValue( const char* pStr );			    // Construct define
	virtual ~CMySqlValue();;			                    // Destruct define

private:
    CMySqlValue( const CMySqlValue& oVal );                 // no copy 
    CMySqlValue& operator = ( const CMySqlValue& oVal );    // no 
    
public:
    std::string     ToString    ( void );           // 转换为字符串
    int             ToInt       ( void )
    {
        __try
        {
            if( mpStr == 0 )
                return 0;

            int iTmp = atoi( mpStr );
            return iTmp;
        }
        __except( EXCEPTION_EXECUTE_HANDLER )
        {
            return 0xffffffff;
        }

    };           // 转换为int                
    long            ToLong      ( void );           // 转换为long
    double          ToDouble    ( void );           // 转换为double
    unsigned long   ToULong     ( int iRadix );     // 转换为unsigned long

}; // End of class CMySqlValue
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSTRINGTRAN_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CStringTran.h
/////////////////////////////////////////////////////////////////////////////////////////