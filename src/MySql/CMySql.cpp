/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySql.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 7/12/2015 10:35:31
// Modify time 	: 7/12/2015 10:35:31
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <WinSock2.h>
#include <mysql.h>
#include <iostream>
#include <DllMacro.h>

#include "CMySqlErrDef.h"
#include "CMySqlErr.h"
#include "CMySqlRet.h"
#include "CMySql.h"

/////////////////////////////////////////////////////////////////////////////////////////

#pragma comment(lib,"libmysql.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// functions : 

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMySql
// Full name : CMySql::CMySql
// Access    : public 
// Brief     : 
// Parameter : const std::string strHostAdd/*="localhost"*/, 
//             const unsigned int uiHostPort/*=3306*/, 
//             const std::string strUser/*="root"*/, 
//             const std::string strPassword/*=""*/, 
//             unsigned int uiTimeOut/*=60*/, 
//             const std::string stdCharSet/*="utf8" */
// Return    : 
// Notes     : 
CMySql::CMySql( const std::string strHostAdd/*="localhost"*/, 
                const unsigned int uiHostPort/*=3306*/, 
                const std::string   strDefDB/*="test"*/,
                const std::string strUser/*="root"*/, 
                const std::string strPassword/*=""*/, 
                unsigned int uiTimeOut/*=60*/, 
                const std::string stdCharSet/*="utf8" */)
                :m_strHostAddr( strHostAdd ),
                m_uiHostPort( uiHostPort ),
                m_strCurDB( strDefDB ),
                m_strUser( strUser ),
                m_strPassword( strPassword ),
                m_uiTimeOut( uiTimeOut ),
                m_strCharSet( stdCharSet ),
                mcError(m_MySql)
{
    // 初始化MYSQL结构
    unsigned int luiRet = Init(  );
} // End of function CMySql(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Init
// Full name : CMySql::Init
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : RET_CMYSQL_INIT_FAILED
//             RET_CMYSQL_SUCCESS
// Notes     : 
unsigned int CMySql::Init(void)
{
    try
    {
        CMySqlExpUnit            lcEu;
        unsigned int luiRet = __mysql_init( lcEu );
        return luiRet;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::Init";
        cEu.mulLine    = __LINE__;
    
        mcExpTrack.AddExp( cEu );
        DumpExpInfo();
        return RET_CMYSQL_INIT_EXP;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit       lcEu;
    
        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Init";
        lcEu.mulLine        = __LINE__;
    
        mcExpTrack.AddExp( lcEu );
        DumpExpInfo();
        return RET_CMYSQL_INIT_EXP;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;
    
        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::Init时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Init";
        lcEu.mulLine        = __LINE__;
    
        mcExpTrack.AddExp( lcEu );
        DumpExpInfo();
        return RET_CMYSQL_INIT_EXP;
    } // End of catch( ... )

} // End of function Init(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Connect
// Full name : CMySql::Connect
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_INIT_FAILED
//             RET_CMYSQL_CONNECT_FAILED
//             RET_CMYSQL_SETCHAR_FAILED
// Notes     : 
unsigned int CMySql::Connect()
{
    try
    {
        // 清理异常跟踪信息
        mcExpTrack.Clear();

        // 重新初始化MYSQL数据
        Close();
        unsigned int luiRet = Init(  );
        if ( luiRet != RET_CMYSQL_SUCCESS )
        { return RET_CMYSQL_INIT_FAILED; }

	    // 连接到数据库
	    CMySqlExpUnit    lcEu;
	    unsigned int liRetForRealConnect = __mysql_real_connect( lcEu );
	    if ( liRetForRealConnect == RET_CMYSQL_FAILED )
	    { return RET_CMYSQL_CONNECT_FAILED; }
	
	
	    // 设置字符集
	    unsigned int liRetForSetCharacter = __mysql_set_character_set( lcEu );
	    if ( liRetForSetCharacter == RET_CMYSQL_FAILED )
	    {
	        return RET_CMYSQL_SETCHAR_FAILED;
	    }
	
	    // 返回成功
	    return RET_CMYSQL_SUCCESS;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::Connect";
        cEu.mulLine    = __LINE__;
        
        mcExpTrack.AddExp( cEu );
        
        // 记录异常信息
        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit       lcEu;
        
        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Connect";
        lcEu.mulLine        = __LINE__;
        
        mcExpTrack.AddExp( lcEu );
        
        // 记录异常信息
        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit       lcEu;
        
        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::Connect时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Connect";
        lcEu.mulLine        = __LINE__;
        
        mcExpTrack.AddExp( lcEu );

        // 记录异常信息
        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( ... )
} // End of function Connect(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : SelectDB
// Full name : CMySql::SelectDB
// Access    : public 
// Brief     : 选择数据库
// Parameter : const std::string& strDBName
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_RECONNECT_FAILED
//             RET_CMYSQL_SELECTDB_FAILED
// Notes     : 
unsigned int CMySql::SelectDB(const std::string& strDBName) 
{
    try
    {
        // 清理异常跟踪信息
        mcExpTrack.Clear();

	    // 在对MySQL进行操作之前对MySQL进行Ping操作，已确定数据库是否可用，若不可用
	    // 通过connect对数据库进行重连
	    unsigned int liRetForReconnect = CheckAndReconnect(  );
	    if ( liRetForReconnect != RET_CMYSQL_SUCCESS )
	    { return liRetForReconnect; }
	
	    // 更新当前数据库明
        std::string lstrTmp     = m_strCurDB;
	    m_strCurDB              = strDBName;

        // 进行更改当前数据库操作
        CMySqlExpUnit lcEu;
	    unsigned int iRetForSelectDB = __mysql_select_db( &m_MySql, m_strCurDB.c_str(), lcEu );
	    if ( iRetForSelectDB != RET_CMYSQL_SUCCESS )
	    { 
            m_strCurDB = lstrTmp;
            return iRetForSelectDB;
        }
	
	    return RET_CMYSQL_SUCCESS;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::SelectDB";
        cEu.mulLine    = __LINE__;
        
        mcExpTrack.AddExp( cEu );
                
        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit           lcEu;
        
        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::SelectDB";
        lcEu.mulLine        = __LINE__;
        
        mcExpTrack.AddExp( lcEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;
        
        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::SelectDB时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::SelectDB";
        lcEu.mulLine        = __LINE__;
        
        mcExpTrack.AddExp( lcEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( ... )
        
} // End of function SelectDB(...
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Name      : Close
// Full name : CMySql::Close
// Access    : public 
// Brief     : 关闭Mysql连接
// Parameter : 
// Return    : 无
// Notes     : 
void CMySql::Close()
{
	try
	{
        // 清理异常跟踪信息
        mcExpTrack.Clear();

        CMySqlExpUnit  lcEu;
	    __mysql_close( lcEu );
        return;
	} // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::Close";
        cEu.mulLine    = __LINE__;

        mcExpTrack.AddExp( cEu );

        DumpExpInfo();
        return;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Close";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );
        DumpExpInfo();
        return;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::Close时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Close";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );
        DumpExpInfo();
        return;
    } // End of catch( ... )

} // End of function Close(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Ping
// Full name : CMySql::Ping
// Access    : public 
// Brief     : 检验数据库时候连接
// Parameter : 
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_PING_FAILED
// Notes     : 
unsigned int CMySql::Ping(void)
{
    try
    {
        CMySqlExpUnit        lcEu;
        unsigned int iRet = 0 ;
        iRet = __mysql_ping( lcEu );
        return iRet;
    }
    catch( CMySqlExpUnit& cEu )
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::Ping";
        cEu.mulLine    = __LINE__;

        mcExpTrack.AddExp( cEu );
        throw cEu;
    }
    catch( std::exception& ex )
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Ping";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );
        throw lcEu;
    }
    catch( ... )
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::Ping时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Ping";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );
        throw lcEu;
    }
} // End of function Ping(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_ping
// Full name : CMySql::__mysql_ping
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_PING_FAILED
// Notes     : 
unsigned int CMySql::__mysql_ping(CMySqlExpUnit& lcEu)
{
    __try{
        int iRet = ::mysql_ping( &m_MySql );
        if ( iRet != 0 )
        {
            mcError.mdwErrorCode  = CMySqlErr::GetErrCode( m_MySql );
            mcError.mstrErrorDes  = CMySqlErr::GetErrDes( m_MySql );
            RecordErrInfo();
            return RET_CMYSQL_PING_FAILED;
        }
        return RET_CMYSQL_SUCCESS;

    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用错误产生
        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM;
        lcEu.mstrExpDes     = "在调用mysql_ping函数获得一个异常";
        lcEu.mulExpCode     = GetExceptionCode();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::__mysql_ping";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );
        throw lcEu;
    }

} // End of function __mysql_ping(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_close
// Full name : CMySql::__mysql_close
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 无
// Notes     : 
void CMySql::__mysql_close(CMySqlExpUnit& cEu)
{
    __try{
        ::mysql_close( &m_MySql );
        return;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType       = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode       = GetExceptionCode();
        cEu.mstrExpDes       = "在调用::mysql_close捕获一个系统异常!";
        cEu.mstrFile         = __FILE__;
        cEu.mstrFunc         = "CMySql::__mysql_close";
        cEu.mulLine          = __LINE__;

        throw cEu;

    }

} // End of function __mysql_close(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_real_connect
// Full name : CMySql::__mysql_real_connect
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : RET_CMYSQL_SUCCESS       ：执行成功
//             RET_CMYSQL_FAILED        ：执行失败，通过返回的CError获取失败信息
// Notes     : 
unsigned int CMySql::__mysql_real_connect( CMySqlExpUnit& cEu )
{
    __try
    {
        // 设置连接超时
        m_MySql.options.connect_timeout = m_uiTimeOut;

        // 调用MySQL函数进行数据连接
        const MYSQL* lpMySQL = ::mysql_real_connect( &m_MySql, 
                                                     m_strHostAddr.c_str(), 
                                                     m_strUser.c_str(), 
                                                     m_strPassword.c_str(), 
                                                     m_strCurDB.c_str(), 
                                                     m_uiHostPort, 
                                                     NULL, 
                                                     0 );

        if ( lpMySQL == NULL )
        {
            // 记录错误信息
            mcError.mdwErrorCode  = CMySqlErr::GetErrCode( m_MySql );
            mcError.mstrErrorDes  = CMySqlErr::GetErrDes( m_MySql );
            RecordErrInfo();
            return RET_CMYSQL_CONNECT_FAILED;    
        }
        
        // 返回调用成功
        return RET_CMYSQL_SUCCESS;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
       // 捕获异常，通常为Mysql函数调用顺序错误产生
       cEu.menExpType       = CMySqlExpUnit::ET_SYSTEM;
       cEu.mulExpCode       = GetExceptionCode();
       cEu.mstrExpDes       = "在调用::mysql_real_connent捕获一个系统异常!";
       cEu.mstrFile         = __FILE__;
       cEu.mstrFunc         = "CMySql::__mysql_real_connect";
       cEu.mulLine          = __LINE__;

       throw cEu;
    }
} // End of function __mysql_real_connect(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_init
// Full name : CMySql::__mysql_init
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : RET_CMYSQL_INIT_FAILED
//             RET_CMYSQL_SUCCESS
// Notes     : 
unsigned int CMySql::__mysql_init(CMySqlExpUnit& cEu)
{
    __try{
        // 初始化MYSQL结构
        const MYSQL* pMysql = ::mysql_init( &m_MySql );
        if ( pMysql == NULL )
        {
            mcError.mdwErrorCode  = CMySqlErr::GetErrCode( m_MySql );
            mcError.mstrErrorDes  = CMySqlErr::GetErrDes( m_MySql );
            RecordErrInfo();
            return RET_CMYSQL_INIT_FAILED;
        }
        return RET_CMYSQL_SUCCESS;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用::mysql_init捕获一个系统异常!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CMySql::__mysql_init";
        cEu.mulLine             = __LINE__;

        throw cEu;    
    }
} // End of function __mysql_init(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_select_db
// Full name : CMySql::__mysql_select_db
// Access    : private 
// Brief     : 
// Parameter : MYSQL* pMySql, const char* cDBName
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_SELECTDB_FAILED
// Notes     : 
unsigned int CMySql::__mysql_select_db(MYSQL* pMySql, const char* cDBName, CMySqlExpUnit& cEu)
{
    __try{
        int iRet = ::mysql_select_db( pMySql, cDBName );
        if ( iRet != 0 )
        {
            mcError.mdwErrorCode  = CMySqlErr::GetErrCode( m_MySql );
            mcError.mstrErrorDes  = CMySqlErr::GetErrDes( m_MySql );
            RecordErrInfo();
            return RET_CMYSQL_SELECTDB_FAILED;
        }
        return RET_CMYSQL_SUCCESS;

    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用::mysql_select_db捕获一个系统异常!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CMySql::__mysql_select_db";
        cEu.mulLine             = __LINE__;

        throw cEu;    
    }
} // End of function __mysql_select_db(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_set_character_set
// Full name : CMySql::__mysql_set_character_set
// Access    : private 
// Brief     : 
// Parameter : 
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_SETCHAR_FAILED
// Notes     : 
unsigned int CMySql::__mysql_set_character_set(CMySqlExpUnit& cEu)
{
    __try{
        int liRet = ::mysql_set_character_set( &m_MySql, m_strCharSet.c_str() );
        if ( liRet != 0 )
        {   
            mcError.mdwErrorCode  = CMySqlErr::GetErrCode( m_MySql );
            mcError.mstrErrorDes  = CMySqlErr::GetErrDes( m_MySql );
            RecordErrInfo();
            return RET_CMYSQL_SETCHAR_FAILED;
        }
        else 
            return RET_CMYSQL_SUCCESS;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用::mysql_set_character_set捕获一个系统异常!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CMySql::__mysql_set_character_set";
        cEu.mulLine             = __LINE__;

        throw cEu;
    }
} // End of function __mysql_set_character_set(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_query
// Full name : CMySql::__mysql_query
// Access    : private 
// Brief     : 
// Parameter : 
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_QUERY_FAILED
// Notes     : 
unsigned int CMySql::__mysql_query( const std::string& strSQL, CMySqlExpUnit& cEu )
{
    __try{
        int iRet = ::mysql_query( &m_MySql, strSQL.c_str() );
        if ( iRet != 0 )
        {
            mcError.mdwErrorCode  = CMySqlErr::GetErrCode( m_MySql );
            mcError.mstrErrorDes  = CMySqlErr::GetErrDes( m_MySql );
            RecordErrInfo();
            return RET_CMYSQL_QUERY_FAILED;
        }
        return RET_CMYSQL_SUCCESS;

    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用::mysql_query捕获一个系统异常!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CMySql::__mysql_query";
        cEu.mulLine             = __LINE__;

        throw cEu;
    }
} // End of function __mysql_query(...
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Name      : CheckAndReconnect
// Full name : CMySql::CheckAndReconnect
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : bool
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_RECONNECT_FAILED
// Notes     : 当客户端与MYSQL数据进行连接后，若再指定的时间内未对MYSQL进行操作则，
//             MYSQL会断开连接。默认时间为8小时
unsigned int CMySql::CheckAndReconnect(void)
{
    
    try
    {
        // 通过MySQL中的Ping操作对连接状态进行判断。
        unsigned int luiRetForPing = Ping();
	    if ( luiRetForPing == RET_CMYSQL_SUCCESS )
            return RET_CMYSQL_SUCCESS;
	

	    // 对MySql进行重新连接
	    unsigned int luiRetForConnect = Connect();
	    if ( luiRetForConnect == RET_CMYSQL_SUCCESS )
	    { return RET_CMYSQL_SUCCESS; }
	
        // 重连失败
	    return RET_CMYSQL_RECONNECT_FAILED;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::CheckAndReconnect";
        cEu.mulLine    = __LINE__;

        mcExpTrack.AddExp( cEu );
        throw cEu;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::CheckAndReconnect";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );
        throw lcEu;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::CheckAndReconnect时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::CheckAndReconnect";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );
        throw lcEu;
    } // End of catch( ... )

} // End of function CheckAndReconnect(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ExecutSQL
// Full name : CMySql::ExecutSQL
// Access    : private 
// Brief     : 
// Parameter : const std::string& strSQL
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_QUERY_FAILED
// Notes     : 
unsigned int CMySql::ExecutSQL(const std::string& strSQL)
{
    try
    {
        CMySqlExpUnit                    lcEu;
	    unsigned int luiRetForQuery = __mysql_query( strSQL.c_str(), lcEu );
	    if ( luiRetForQuery != RET_CMYSQL_SUCCESS )
	    {
	        return luiRetForQuery;
	    }
	
	    return RET_CMYSQL_SUCCESS;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::ExecutSQL";
        cEu.mulLine    = __LINE__;
    
        mcExpTrack.AddExp( cEu );
        throw cEu;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit           lcEu;
    
        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::ExecutSQL";
        lcEu.mulLine        = __LINE__;
    
        mcExpTrack.AddExp( lcEu );
        throw lcEu;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;
    
        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::ExecutSQL时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::ExecutSQL";
        lcEu.mulLine        = __LINE__;
    
        mcExpTrack.AddExp( lcEu );
        throw lcEu;
    } // End of catch( ... )
    
} // End of function ExecutSQL(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Select
// Full name : CMySql::Select
// Access    : public 
// Brief     : 
// Parameter : const std::string& strSQl, CMySqlRet& cRet
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_RECONNECT_FAILED
//             RET_CMYSQL_QUERY_FAILED
//             RET_CMYSQL_STORN_RESULT_FAILED
//             RET_CMYSQL_GETRET_DIFFNUM
// Notes     : 
unsigned int CMySql::Select(const std::string& strSQl, CMySqlRet& cRet)
{
    try
    {
        // 清理异常跟踪信息
        mcExpTrack.Clear();

	    // 状态测试与重连
	    unsigned int luiRetForCheckAndReconnect = CheckAndReconnect(  );
	    if ( luiRetForCheckAndReconnect != RET_CMYSQL_SUCCESS )
	    { return luiRetForCheckAndReconnect;}
	
	    // 执行Mysql语句
	    unsigned int luiRetForExcutSQL =  ExecutSQL( strSQl );
	    if( luiRetForExcutSQL != RET_CMYSQL_SUCCESS )
	    { return luiRetForExcutSQL; }
	
	    // 获取返回结果集
	    unsigned int luiRetForGetResult = cRet.GetResult( (*this) );

        // 返回处理结果
	    return luiRetForGetResult;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::Select";
        cEu.mulLine    = __LINE__;
    
        mcExpTrack.AddExp( cEu );
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit           lcEu;
    
        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Select";
        lcEu.mulLine        = __LINE__;
    
        mcExpTrack.AddExp( lcEu );
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;
    
        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::Select时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Select";
        lcEu.mulLine        = __LINE__;
    
        mcExpTrack.AddExp( lcEu );
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( ... )

} // End of function Select(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Updata
// Full name : CMySql::Updata
// Access    : public 
// Brief     : 
// Parameter : const std::string& strSQL
// Return    : 
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_RECONNECT_FAILED
//             RET_CMYSQL_QUERY_FAILED
// Notes     : 
unsigned int CMySql::Updata(const std::string& strSQL,unsigned long long& ullAffectRows)
{    
    try
    {
        // 清理异常跟踪信息
        mcExpTrack.Clear();

        // 状态测试与重连
        unsigned int luiRetForCheckAndReconnect = CheckAndReconnect(  );
        if ( luiRetForCheckAndReconnect != RET_CMYSQL_SUCCESS )
        { return luiRetForCheckAndReconnect;}

        // 执行Mysql语句
        unsigned int luiRetForExcutSQL =  ExecutSQL( strSQL );
        if( luiRetForExcutSQL != RET_CMYSQL_SUCCESS )
        { return luiRetForExcutSQL; }

        // 获取影响行数
        CMySqlExpUnit        lcEu;
        ullAffectRows   = __mysql_affected_rows( lcEu );

        // 返回结果
        return RET_CMYSQL_SUCCESS;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::Updata";
        cEu.mulLine    = __LINE__;

        mcExpTrack.AddExp( cEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Updata";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::Updata时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Updata";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( ... )

} // End of function Updata(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Insert
// Full name : CMySql::Insert
// Access    : public 
// Brief     : 
// Parameter : const std::string& strSQL, unsigned long long& ullAffectRows
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_RECONNECT_FAILED
//             RET_CMYSQL_QUERY_FAILED
// Notes     : 
unsigned int CMySql::Insert(const std::string& strSQL, unsigned long long& ullAffectRows)
{
    try
    {
        // 清理异常跟踪信息
        mcExpTrack.Clear();

        // 状态测试与重连
        unsigned int luiRetForCheckAndReconnect = CheckAndReconnect(  );
        if ( luiRetForCheckAndReconnect != RET_CMYSQL_SUCCESS )
        { return luiRetForCheckAndReconnect;}

        // 执行Mysql语句
        unsigned int luiRetForExcutSQL =  ExecutSQL( strSQL );
        if( luiRetForExcutSQL != RET_CMYSQL_SUCCESS )
        { return luiRetForExcutSQL; }

        // 获取影响行数
        CMySqlExpUnit        lcEu;
        ullAffectRows   = __mysql_affected_rows( lcEu );

        // 返回结果
        return RET_CMYSQL_SUCCESS;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::Insert";
        cEu.mulLine    = __LINE__;

        mcExpTrack.AddExp( cEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Insert";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::Insert时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Insert";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( ... )

} // End of function Insert(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Delete
// Full name : CMySql::Delete
// Access    : public 
// Brief     : 
// Parameter : const std::string& strSQL, unsigned long long& ullAffectRows
// Return    : unsigned int
// Notes     : 
unsigned int CMySql::Delete(const std::string& strSQL, unsigned long long& ullAffectRows)
{
    try
    {
        // 清理异常跟踪信息
        mcExpTrack.Clear();

        // 状态测试与重连
        unsigned int luiRetForCheckAndReconnect = CheckAndReconnect(  );
        if ( luiRetForCheckAndReconnect != RET_CMYSQL_SUCCESS )
        { return luiRetForCheckAndReconnect;}

        // 执行Mysql语句
        unsigned int luiRetForExcutSQL =  ExecutSQL( strSQL );
        if( luiRetForExcutSQL != RET_CMYSQL_SUCCESS )
        { return luiRetForExcutSQL; }

        // 获取影响行数
        CMySqlExpUnit        lcEu;
        ullAffectRows   = __mysql_affected_rows( lcEu );

        // 返回结果
        return RET_CMYSQL_SUCCESS;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySql::Delete";
        cEu.mulLine    = __LINE__;

        mcExpTrack.AddExp( cEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Delete";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit           lcEu;

        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySql::Delete时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySql::Delete";
        lcEu.mulLine        = __LINE__;

        mcExpTrack.AddExp( lcEu );

        DumpExpInfo();
        return RET_CMYSQL_EXCEPTION;
    } // End of catch( ... )
} // End of function Delete(...
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Name      : DumpExpInfo
// Full name : CMySql::DumpExpInfo
// Access    : private 
// Brief     : 
// Parameter : void
// Return    : void
// Notes     : 
void CMySql::DumpExpInfo(void)
{
    std::cout << "Dump exception info :" << std::endl;
    if ( mcExpTrack.GetSize() == 0 )
    {
        std::cout << "    无异常信息!" << std::endl;
        return;
    }

    CMySqlExpTrack::tItor liTor = mcExpTrack.GetFirstExp();
    for ( ; liTor != mcExpTrack.GetLastExp(); liTor++ )
    {
        std::cout << "    " << liTor->ToString().c_str() << std::endl;
    }
} // End of function DumpExpInfo(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : RecordErrInfo
// Full name : CMySql::RecordErrInfo
// Access    : private 
// Brief     : 
// Parameter : void
// Return    : void
// Notes     : 
void CMySql::RecordErrInfo(void)
{
    std::cout   << "Error Info( "<<mcError.mdwErrorCode<<" ) : " 
        << mcError.mstrErrorDes.c_str() << std::endl;
} // End of function RecordErrInfo(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_free_result
// Full name : CMySql::__mysql_free_result
// Access    : public 
// Brief     : 
// Parameter : MYSQL_RES* pRes, CExpUnit& cEu
// Return    : void
// Notes     : 
void CMySql::__mysql_free_result(MYSQL_RES* pRes, CMySqlExpUnit& cEu)
{
    __try{
        // 初始化MYSQL结构
        ::mysql_free_result( pRes );
        return;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用::mysql_num_rows捕获一个系统异常!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CMySql::__mysql_num_rows";
        cEu.mulLine             = __LINE__;

        throw cEu;    
    }
} // End of function __mysql_free_result(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_num_rows
// Full name : CMySql::__mysql_num_rows
// Access    : public 
// Brief     : 
// Parameter : MYSQL_RES* pRes, CExpUnit& cEu
// Return    : unsigned long long
// Notes     : 
unsigned long long CMySql::__mysql_num_rows(MYSQL_RES* pRes, CMySqlExpUnit& cEu)
{
    __try{
        // 初始化MYSQL结构
        unsigned long long ullRowNum = ::mysql_num_rows( pRes );
        return ullRowNum;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用::mysql_num_rows捕获一个系统异常!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CMySql::__mysql_num_rows";
        cEu.mulLine             = __LINE__;

        throw cEu;    
    }
} // End of function __mysql_num_rows(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_store_result
// Full name : CMySql::__mysql_store_result
// Access    : public 
// Brief     : 
// Parameter : CExpUnit& cEu
// Return    : MYSQL_RES*
// Notes     : 
MYSQL_RES* CMySql::__mysql_store_result(CMySqlExpUnit& cEu)
{
    __try{
        // 初始化MYSQL结构
        MYSQL_RES* pMysqlRes = ::mysql_store_result( &m_MySql );
        if ( pMysqlRes == NULL )
        {
            mcError.mdwErrorCode  = CMySqlErr::GetErrCode( m_MySql );
            mcError.mstrErrorDes  = CMySqlErr::GetErrDes( m_MySql );
            RecordErrInfo();
        }
        return pMysqlRes;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用::mysql_store_result捕获一个系统异常!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CMySql::__mysql_store_result";
        cEu.mulLine             = __LINE__;

        throw cEu;    
    }
} // End of function __mysql_store_result(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrorInfo
// Full name : CMySql::GetErrorInfo
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : CError&
// Notes     : 
CMySqlErr& CMySql::GetErrorInfo(void)
{
    return mcError;
} // End of function GetErrorInfo(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetExceptionInfo
// Full name : CMySql::GetExceptionInfo
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : CMyExpTrack&
// Notes     : 
CMySqlExpTrack& CMySql::GetExceptionInfo(void)
{
    return mcExpTrack;
} // End of function GetExceptionInfo(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : __mysql_affected_rows
// Full name : CMySql::__mysql_affected_rows
// Access    : public 
// Brief     : 
// Parameter : CExpUnit& cEu
// Return    : unsigned long long
// Notes     : 
unsigned long long CMySql::__mysql_affected_rows(CMySqlExpUnit& cEu)
{
    __try{
        unsigned long long lullRet = ::mysql_affected_rows( &m_MySql );
        return lullRet;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用::mysql_affected_rows捕获一个系统异常!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CMySql::__mysql_affected_rows";
        cEu.mulLine             = __LINE__;

        throw cEu;    
    }
} // End of function __mysql_affected_rows(...
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySql.cpp
/////////////////////////////////////////////////////////////////////////////////////////