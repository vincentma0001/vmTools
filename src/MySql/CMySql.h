/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySql.h
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 4/12/2015 20:30:11
// Modify time 	: 4/12/2015 20:30:11
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

#ifndef __CMYSQL_H__
#define __CMYSQL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#ifndef _mysql_h
#   error This file is need #include <winsock2.h>
#   error This file is need #include <mysql.h>
#endif

#include <string>
#include <list>
#include <map>

#include <DBase/CMySqlErr.h>
#include <DBase/CMySqlExpTrack.h>

/////////////////////////////////////////////////////////////////////////////////////////
// class release 
class CMySqlRet;

/////////////////////////////////////////////////////////////////////////////////////////
EXPORT_STL_STRING( DLL_MACRO )
EXPORT_STL_LIST( DLL_MACRO, int )

/////////////////////////////////////////////////////////////////////////////////////
//
// class define : CMySql
//        Notes : 此类封装MySql的常用API函数,为用户提供调用接口与方法
//
/////////////////////////////////////////////////////////////////////////////////////
class DLL_MACRO CMySql 
{
/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    MYSQL               m_MySql;                                // MYSQL数据结构
    unsigned int        m_uiHostPort;                           // MYSQL数据库主机端口
    unsigned int        m_uiTimeOut;                            // 连接超时时长
    unsigned int        m_uiClientFlags;                        // 标识(暂未使用)
    std::string         m_strHostAddr;                          // MYSQL数据库主机地址
    std::string         m_strCurDB;                             // 当前操作的数据库名称
    std::string         m_strUser;                              // 用户名
    std::string         m_strPassword;                          // 密码
    std::string         m_strCharSet;                           // 字符集
    std::string         m_strUnixSocket;                        // Socket调用方法(暂未使用)

public:
    const MYSQL* GetHander()        { return &m_MySql; };                   // Get &m_MySql

    unsigned int HostPort() const   { return m_uiHostPort; }			    // Get m_uiHostPort
    void HostPort(unsigned int val) { m_uiHostPort = val; }					// Set m_uiHostPort

    unsigned int TimeOut() const    { return m_uiTimeOut; }			        // Get m_uiTimeOut
    void TimeOut(unsigned int val)  { m_uiTimeOut = val; }					// Set m_uiTimeOut

    unsigned int ClientFlags() const    { return m_uiClientFlags; }			// Get m_uiClientFlags
    void ClientFlags(unsigned int val)  { m_uiClientFlags = val; }			// Set m_uiClientFlags

    std::string HostAddr() const    { return m_strHostAddr; }			    // Get m_strHostAddr
    void HostAddr(std::string val)  { m_strHostAddr = val; }				// Set m_strHostAddr

    std::string CurDB() const       { return m_strCurDB; }			        // Get m_strCurDB
    void CurDB(std::string val)     { m_strCurDB = val; }					// Set m_strCurDB

    std::string User() const            { return m_strUser; }			    // Get m_strUser
    void User(const std::string& val)   { m_strUser = val; }				// Set m_strUser

    std::string Password() const            { return m_strPassword; }		// Get m_strPassword
    void Password(const std::string& val)   { m_strPassword = val; }		// Set m_strPassword

    std::string CharSet() const             { return m_strCharSet; }		// Get m_strCharSet
    void CharSet(const std::string& val)    { m_strCharSet = val; }			// Set m_strCharSet

    std::string UnixSocket() const          { return m_strUnixSocket; }		// Get m_strUnixSocket
    void UnixSocket(const std::string& val) { m_strUnixSocket = val; }		// Set m_strUnixSocket

/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
	CMySql( const std::string   strHostAdd="localhost",
            const unsigned int  uiHostPort=3306,
            const std::string   strDefDB="test",
            const std::string   strUser="root", 
            const std::string   strPassword="123456",
            unsigned int        uiTimeOut=10,
            const std::string   stdCharSet="gbk" );			        // Construct define
	virtual ~CMySql(){};			                                        // Destruct define
public:
    unsigned int Init(  void );                                     // MYSQL结构初始化
    unsigned int Connect( void );                                   // 连接MYSQL数据库
    void Close( void );;                                            // 断开MYSQL数据库

    unsigned int SelectDB( const std::string& strDBName );               // 选择需要操作的数据库;

    unsigned int Select( const std::string& strSQl, CMySqlRet& cRet );   // 数据库Select操作
    unsigned int Updata( const std::string& strSQL, 
                         unsigned long long& ullAffectRows );            // 数据库UpData操作
    unsigned int Insert( const std::string& strSQL,  
                         unsigned long long& ullAffectRows );            // 数据库Insert操作
    unsigned int Delete( const std::string& strSQL,  
                         unsigned long long& ullAffectRows );            // 数据库Delete操作

private:
    unsigned int ExecutSQL( const std::string& strSQL );                 // 执行SQL语句

    // Note ：当客户端与MYSQL数据进行连接后，若再指定的时间内未对MYSQL进行操作则，MYSQL会
    //        断开连接。默认时间为8小时
    unsigned int CheckAndReconnect( void );                             // 连接状态检测，若连接状态不可用进行从连操作，
    unsigned int Ping( void );                                          // 确保MySql一直处于链接状态

    void DumpExpInfo( void );                                           // 输出异常信息
    void RecordErrInfo( void );                                         // 记录错误信息


private:

    unsigned int __mysql_init ( CMySqlExpUnit& cEu );                        // 使用SEH封装mysql_init函数，处理MySql函数库中的系统异常
    void __mysql_close ( CMySqlExpUnit& cEu );                               // 使用SEH封装mysql_close函数，处理MySql函数库中的系统异常

    unsigned int __mysql_select_db( MYSQL* pMySql, 
                                    const char* cDBName, 
                                    CMySqlExpUnit& cEu );                    // 使用SEH封装mysql_select_db函数，处理MySql函数库中的系统异常
    
    unsigned int __mysql_real_connect( CMySqlExpUnit& cEu );                 // 使用SEH封装mysql_real_connect函数，处理MySql函数库中的系统异常
    unsigned int __mysql_set_character_set( CMySqlExpUnit& cEu );            // 使用SEH封装mysql_set_character_set函数，处理MySql函数库中的系统异常
    unsigned int __mysql_query( const std::string& strSQL, CMySqlExpUnit& cEu );     // 使用SEH封装mysql_query函数，处理MySql函数库中的系统异常
    unsigned int __mysql_ping( CMySqlExpUnit& lcEu );                                // 使用SEH封装mysql_ping函数，处理MySql函数库中的系统异常
public:
    void __mysql_free_result( MYSQL_RES* pRes, CMySqlExpUnit& cEu );                 // 使用SEH封装mysql_free_result函数，处理MySql函数库中的系统异常
    unsigned long long __mysql_num_rows( MYSQL_RES* pRes, CMySqlExpUnit& cEu );      // 使用SEH封装mysql_num_rows函数，处理MySql函数库中的系统异常
    MYSQL_RES* __mysql_store_result( CMySqlExpUnit& cEu );                           // 使用SEH封装mysql_store_result函数，处理MySql函数库中的系统异常
    unsigned long long __mysql_affected_rows( CMySqlExpUnit& cEu );                  // 使用SEH封装mysql_affected_rows函数，处理MySql函数库中的系统异常

    
/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    CMySqlErr                  mcError;            // 保存执行操作失败时的错误信息
    CMySqlExpTrack             mcExpTrack;         // 保存执行操作异常时产生的异常信息及其调用过程

public:
    CMySqlErr&      GetErrorInfo( void );          // 获取错误信息
    CMySqlExpTrack& GetExceptionInfo( void );         // 获取异常信息

/////////////////////////////////////////////////////////////////////////////////////////
    std::list<int>          mlistAmp;
    //std::vector<int>        mVectorAmp;

    //std::map<int,int>          mMapAmp;
};// End of class CMySql
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CMYSQL_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySql.h
/////////////////////////////////////////////////////////////////////////////////////////