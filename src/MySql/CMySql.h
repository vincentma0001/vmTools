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
//        Notes : �����װMySql�ĳ���API����,Ϊ�û��ṩ���ýӿ��뷽��
//
/////////////////////////////////////////////////////////////////////////////////////
class DLL_MACRO CMySql 
{
/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    MYSQL               m_MySql;                                // MYSQL���ݽṹ
    unsigned int        m_uiHostPort;                           // MYSQL���ݿ������˿�
    unsigned int        m_uiTimeOut;                            // ���ӳ�ʱʱ��
    unsigned int        m_uiClientFlags;                        // ��ʶ(��δʹ��)
    std::string         m_strHostAddr;                          // MYSQL���ݿ�������ַ
    std::string         m_strCurDB;                             // ��ǰ���������ݿ�����
    std::string         m_strUser;                              // �û���
    std::string         m_strPassword;                          // ����
    std::string         m_strCharSet;                           // �ַ���
    std::string         m_strUnixSocket;                        // Socket���÷���(��δʹ��)

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
    unsigned int Init(  void );                                     // MYSQL�ṹ��ʼ��
    unsigned int Connect( void );                                   // ����MYSQL���ݿ�
    void Close( void );;                                            // �Ͽ�MYSQL���ݿ�

    unsigned int SelectDB( const std::string& strDBName );               // ѡ����Ҫ���������ݿ�;

    unsigned int Select( const std::string& strSQl, CMySqlRet& cRet );   // ���ݿ�Select����
    unsigned int Updata( const std::string& strSQL, 
                         unsigned long long& ullAffectRows );            // ���ݿ�UpData����
    unsigned int Insert( const std::string& strSQL,  
                         unsigned long long& ullAffectRows );            // ���ݿ�Insert����
    unsigned int Delete( const std::string& strSQL,  
                         unsigned long long& ullAffectRows );            // ���ݿ�Delete����

private:
    unsigned int ExecutSQL( const std::string& strSQL );                 // ִ��SQL���

    // Note �����ͻ�����MYSQL���ݽ������Ӻ�����ָ����ʱ����δ��MYSQL���в�����MYSQL��
    //        �Ͽ����ӡ�Ĭ��ʱ��Ϊ8Сʱ
    unsigned int CheckAndReconnect( void );                             // ����״̬��⣬������״̬�����ý��д���������
    unsigned int Ping( void );                                          // ȷ��MySqlһֱ��������״̬

    void DumpExpInfo( void );                                           // ����쳣��Ϣ
    void RecordErrInfo( void );                                         // ��¼������Ϣ


private:

    unsigned int __mysql_init ( CMySqlExpUnit& cEu );                        // ʹ��SEH��װmysql_init����������MySql�������е�ϵͳ�쳣
    void __mysql_close ( CMySqlExpUnit& cEu );                               // ʹ��SEH��װmysql_close����������MySql�������е�ϵͳ�쳣

    unsigned int __mysql_select_db( MYSQL* pMySql, 
                                    const char* cDBName, 
                                    CMySqlExpUnit& cEu );                    // ʹ��SEH��װmysql_select_db����������MySql�������е�ϵͳ�쳣
    
    unsigned int __mysql_real_connect( CMySqlExpUnit& cEu );                 // ʹ��SEH��װmysql_real_connect����������MySql�������е�ϵͳ�쳣
    unsigned int __mysql_set_character_set( CMySqlExpUnit& cEu );            // ʹ��SEH��װmysql_set_character_set����������MySql�������е�ϵͳ�쳣
    unsigned int __mysql_query( const std::string& strSQL, CMySqlExpUnit& cEu );     // ʹ��SEH��װmysql_query����������MySql�������е�ϵͳ�쳣
    unsigned int __mysql_ping( CMySqlExpUnit& lcEu );                                // ʹ��SEH��װmysql_ping����������MySql�������е�ϵͳ�쳣
public:
    void __mysql_free_result( MYSQL_RES* pRes, CMySqlExpUnit& cEu );                 // ʹ��SEH��װmysql_free_result����������MySql�������е�ϵͳ�쳣
    unsigned long long __mysql_num_rows( MYSQL_RES* pRes, CMySqlExpUnit& cEu );      // ʹ��SEH��װmysql_num_rows����������MySql�������е�ϵͳ�쳣
    MYSQL_RES* __mysql_store_result( CMySqlExpUnit& cEu );                           // ʹ��SEH��װmysql_store_result����������MySql�������е�ϵͳ�쳣
    unsigned long long __mysql_affected_rows( CMySqlExpUnit& cEu );                  // ʹ��SEH��װmysql_affected_rows����������MySql�������е�ϵͳ�쳣

    
/////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    CMySqlErr                  mcError;            // ����ִ�в���ʧ��ʱ�Ĵ�����Ϣ
    CMySqlExpTrack             mcExpTrack;         // ����ִ�в����쳣ʱ�������쳣��Ϣ������ù���

public:
    CMySqlErr&      GetErrorInfo( void );          // ��ȡ������Ϣ
    CMySqlExpTrack& GetExceptionInfo( void );         // ��ȡ�쳣��Ϣ

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