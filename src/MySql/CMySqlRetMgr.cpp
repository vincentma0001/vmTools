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
// ������VC6һ�°汾��ʹ��STL��list,map�ȶ������C4786����
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
    // ͨ�ö���
    mRetMap.AddData( RET_CMYSQL_SUCCESS,                GCP_RET_CMYSQL_SUCCESS );
    mRetMap.AddData( RET_CMYSQL_FAILED,                 GCP_RET_CMYSQL_FAILED );
    mRetMap.AddData( RET_CMYSQL_EXCEPTION,              GCP_RET_CMYSQL_EXCEPTION );

    /////////////////////////////////////////////////////////////////////////////////////////
    // ��ʼ������ֵ
    mRetMap.AddData( RET_CMYSQL_INIT_FAILED,            GCP_RET_CMYSQL_INIT_FAILED );
    mRetMap.AddData( RET_CMYSQL_INIT_EXP,               GCP_RET_CMYSQL_INIT_EXP );
    mRetMap.AddData( RET_CMYSQL_INIT_LOGGER_FAILED,     GCP_RET_CMYSQL_INIT_LOGGER_FAILED );
    mRetMap.AddData( RET_CMYSQL_INIT_LOGGER_EXP,        GCP_RET_CMYSQL_INIT_LOGGER_EXP );

    /////////////////////////////////////////////////////////////////////////////////////////
    // �������ݿ����
    mRetMap.AddData( RET_CMYSQL_SELECTDB_FAILED,        GCP_RET_CMYSQL_SELECTDB_FAILED );
    mRetMap.AddData( RET_CMYSQL_SETCHAR_FAILED,         GCP_RET_CMYSQL_SETCHAR_FAILED );

    /////////////////////////////////////////////////////////////////////////////////////////
    // �������ݿ����
    mRetMap.AddData( RET_CMYSQL_PING_FAILED,            GCP_RET_CMYSQL_PING_FAILED );
    mRetMap.AddData( RET_CMYSQL_RECONNECT_FAILED,       GCP_RET_CMYSQL_RECONNECT_FAILED );
    mRetMap.AddData( RET_CMYSQL_CONNECT_FAILED,         GCP_RET_CMYSQL_CONNECT_FAILED );

    /////////////////////////////////////////////////////////////////////////////////////////
    // ���ݿ����
    mRetMap.AddData( RET_CMYSQL_QUERY_FAILED,           GCP_RET_CMYSQL_QUERY_FAILED );

    /////////////////////////////////////////////////////////////////////////////////////////
    // ���ݽ��������
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