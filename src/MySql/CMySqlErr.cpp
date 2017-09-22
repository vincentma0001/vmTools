/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySqlErr.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 10/12/2015 12:46:01
// Modify time 	: 10/12/2015 12:46:01
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <winsock2.h>
#include <mysql.h>
#include <DllMacro.h>

#include <DBase/CMySqlErrDef.h>
#include <DBase/CMySqlErr.h>

/////////////////////////////////////////////////////////////////////////////////////////

#pragma comment(lib,"libmysql.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// functions : 

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetMySqlErrCode
// Full name : CMySqlErr::GetMySqlErrCode
// Access    : public static 
// Brief     : 
// Parameter : const MYSQL& obj
// Return    : unsigned long
// Notes     : 
unsigned long CMySqlErr::GetErrCode(const MYSQL& obj)
{
    __try
    {
        return ::mysql_errno( const_cast<MYSQL*>(&obj) );
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        return RET_CMYSQL_EXCEPTION;
    }
} // End of function GetMySqlErrCode(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrCode
// Full name : CMySqlErr::GetErrCode
// Access    : public static 
// Brief     : 
// Parameter : void
// Return    : unsigned long
// Notes     : 
//unsigned long CMySqlErr::GetErrCode(void)
//{
//    __try
//    {
//        return ::mysql_errno( const_cast<MYSQL*>(&m_MySQL) );
//    }
//    __except( EXCEPTION_EXECUTE_HANDLER )
//    {
//        return RET_CMYSQL_EXCEPTION;
//    }
//
//} // End of function GetErrCode(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetMySqlErrDes
// Full name : CMySqlErr::GetMySqlErrDes
// Access    : public static 
// Brief     : 
// Parameter : const MYSQL& obj
// Return    : const char*
// Notes     : 
const char* CMySqlErr::GetErrDes( const MYSQL& obj )
{
    __try
    {
        return ::mysql_error( const_cast<MYSQL*>(&obj) );
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        return NULL;
    }
} // End of function GetMySqlErrDes(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrDes
// Full name : CMySqlErr::GetErrDes
// Access    : public static 
// Brief     : 
// Parameter : void
// Return    : const char*
// Notes     : 
//const char* CMySqlErr::GetErrDes(void)
//{
//    __try
//    {
//        return ::mysql_error( const_cast<MYSQL*>(&m_MySQL) );
//    }
//    __except( EXCEPTION_EXECUTE_HANDLER )
//    {
//        return NULL;
//    }
//} // End of function GetErrDes(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMySqlErr
// Full name : CMySqlErr::CMySqlErr
// Access    : public 
// Brief     : 
// Parameter : const MYSQL& objMySql
// Return    : 
// Notes     : 
CMySqlErr::CMySqlErr(const MYSQL& objMySql) 
    :mstMySQL(objMySql),
    mdwErrorCode(0),
    mstrErrorDes("")
{
    //mdwErrorCode = CMySqlErr::GetErrCode( mstMySQL );
} // End of function CMySqlErr(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CMySqlErr::ToString
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : std::string&
// Notes     : 
std::string& CMySqlErr::ToString( void )
{
    mstrErrorDes = CMySqlErr::GetErrDes( mstMySQL );
    return mstrErrorDes;
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlErr.cpp
/////////////////////////////////////////////////////////////////////////////////////////