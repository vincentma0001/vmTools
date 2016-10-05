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
        // 转换MYSQL_RES结构
        MYSQL_RES* lpRet = (MYSQL_RES*)pMySqlRes;

        // 获取行信息
        MYSQL_ROW lRow      = ::mysql_fetch_row( lpRet );

        // 分析行信息
        bool lbRet = OnAnalysisRow( lRow );
        if ( lbRet == false )
        {
            return false;
        }

        // 返回
        return true;
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {
        // 捕获异常，通常为Mysql函数调用顺序错误产生
        cEu.menExpType          = CMySqlExpUnit::ET_SYSTEM;
        cEu.mulExpCode          = GetExceptionCode();
        cEu.mstrExpDes          = "在调用CAbsMySqlRow::AnalysisRowData捕获一个系统异常!";
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