/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CAbsMySqlRow.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 10/12/2015 13:04:11
// Modify time 	: 10/12/2015 13:04:11
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
#include <DllMacro.h>

#include <DBase/CAbsMySqlRow.h>
#include <DBase/CMySqlExpTrack.h>

/////////////////////////////////////////////////////////////////////////////////////////

#pragma comment(lib,"libmysql.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// functions : 

/////////////////////////////////////////////////////////////////////////////////////
// Name      : AnalysisRowData
// Full name : CAbsMySqlRow::AnalysisRowData
// Access    : public 
// Brief     : 
// Parameter : MYSQL_RES* pMySqlRes, CExpUnit& cEu
// Return    : bool
// Notes     : 
bool CAbsMySqlRow::AnalysisRowData(void* pMySqlRes, CMySqlExpUnit& cEu)
{
    __try{
        // ת��MYSQL_RES�ṹ
        MYSQL_RES* lpRet = (MYSQL_RES*)pMySqlRes;

        // ��ȡ����Ϣ
        MYSQL_ROW lRow      = ::mysql_fetch_row( lpRet );

        // ��������Ϣ
        bool lbRet = OnAnalysisRow( lRow );
        if ( lbRet == false )
        {
            return false;
        }

        // ����
        return true;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // �����쳣��ͨ��ΪMysql��������˳��������
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "�ڵ���CAbsMySqlRow::AnalysisRowData����һ��ϵͳ�쳣!";
        cEu.mstrFile            = __FILE__;
        cEu.mstrFunc            = "CAbsMySqlRow::AnalysisRowData";
        cEu.mulLine             = __LINE__;

        throw cEu;    
    }
} // End of function AnalysisRowData(...
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////
// End of file CAbsMySqlRow.cpp
/////////////////////////////////////////////////////////////////////////////////////////