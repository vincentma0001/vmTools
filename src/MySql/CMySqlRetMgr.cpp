/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySqlErrMgr.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 14/12/2015 14:28:25
// Modify time 	: 14/12/2015 14:28:25
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition

#if( _MSC_VER <= 1200 )
// 忽略在VC6一下版本中使用STL的list,map等对象产生C4786警告
#pragma warning( disable:4786 )
#endif 

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <DBase/CMySqlRetMgr.h>

/////////////////////////////////////////////////////////////////////////////////////////
// functions : 

/////////////////////////////////////////////////////////////////////////////////////
// Name      : RegErrCode
// Full name : CMySqlErrMgr::RegErrCode
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : void
// Notes     : 
void CMySqlRetMgr::RegRetCode(void)
{
    /////////////////////////////////////////////////////////////////////////////////////////
    // 通用定义
    mRetMap.AddData( RET_CMYSQL_SUCCESS,                GCP_RET_CMYSQL_SUCCESS );
    mRetMap.AddData( RET_CMYSQL_FAILED,                 GCP_RET_CMYSQL_FAILED );
    mRetMap.AddData( RET_CMYSQL_EXCEPTION,              GCP_RET_CMYSQL_EXCEPTION );

    /////////////////////////////////////////////////////////////////////////////////////////
    // 初始化返回值
    mRetMap.AddData( RET_CMYSQL_INIT_FAILED,            GCP_RET_CMYSQL_INIT_FAILED );
    mRetMap.AddData( RET_CMYSQL_INIT_EXP,               GCP_RET_CMYSQL_INIT_EXP );
    mRetMap.AddData( RET_CMYSQL_INIT_LOGGER_FAILED,     GCP_RET_CMYSQL_INIT_LOGGER_FAILED );
    mRetMap.AddData( RET_CMYSQL_INIT_LOGGER_EXP,        GCP_RET_CMYSQL_INIT_LOGGER_EXP );

    /////////////////////////////////////////////////////////////////////////////////////////
    // 更改数据库操作
    mRetMap.AddData( RET_CMYSQL_SELECTDB_FAILED,        GCP_RET_CMYSQL_SELECTDB_FAILED );
    mRetMap.AddData( RET_CMYSQL_SETCHAR_FAILED,         GCP_RET_CMYSQL_SETCHAR_FAILED );

    /////////////////////////////////////////////////////////////////////////////////////////
    // 连接数据库操作
    mRetMap.AddData( RET_CMYSQL_PING_FAILED,            GCP_RET_CMYSQL_PING_FAILED );
    mRetMap.AddData( RET_CMYSQL_RECONNECT_FAILED,       GCP_RET_CMYSQL_RECONNECT_FAILED );
    mRetMap.AddData( RET_CMYSQL_CONNECT_FAILED,         GCP_RET_CMYSQL_CONNECT_FAILED );

    /////////////////////////////////////////////////////////////////////////////////////////
    // 数据库操作
    mRetMap.AddData( RET_CMYSQL_QUERY_FAILED,           GCP_RET_CMYSQL_QUERY_FAILED );

    /////////////////////////////////////////////////////////////////////////////////////////
    // 数据结果集操作
    mRetMap.AddData( RET_CMYSQL_GETRET_STORN_FAILED,    GCP_RET_CMYSQL_GETRET_STORN_FAILED );
    mRetMap.AddData( RET_CMYSQL_GETRET_DIFFNUM,         GCP_RET_CMYSQL_GETRET_DIFFNUM );
} // End of function RegErrCode(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetRetDes
// Full name : CMySqlErrMgr::GetRetDes
// Access    : public 
// Brief     : 
// Parameter : unsigned int uiRetVal
// Return    : std::string
// Notes     : 
std::string CMySqlRetMgr::GetRetDes(unsigned int uiRetVal)
{
    if( mRetMap.IsEmpty() )
        return std::string ("the Err map is empty, please initialize return valuse map first!");

    std::string* lpStrVal = mRetMap.GetData( uiRetVal );
    if ( lpStrVal == NULL )
        return std::string("Can not find return value, please check return value map!");

    return (*lpStrVal);
} // End of function GetRetDes(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlErrMgr.cpp
/////////////////////////////////////////////////////////////////////////////////////////