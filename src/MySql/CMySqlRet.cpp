/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CMySqlRet.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 9/12/2015 12:12:43
// Modify time 	: 9/12/2015 12:12:43
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>

#include <WinSock2.h>
#include <mysql.h>
#include <DllMacro.h>

#include <DBase/CMySqlErrDef.h>
#include <DBase/CMySql.h>
#include <DBase/CMySqlRet.h>
#include <DBase/CAbsMySqlRow.h>

/////////////////////////////////////////////////////////////////////////////////////////

#pragma comment(lib,"libmysql.lib")

/////////////////////////////////////////////////////////////////////////////////////////
// functions : 

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CMySqlRet
// Full name : CMySqlRet::CMySqlRet
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CMySqlRet::CMySqlRet() :mpBaseRow(NULL)
{
    mlistpRows.clear();
} // End of function CMySqlRet(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CMySqlRet
// Full name : CMySqlRet::~CMySqlRet
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CMySqlRet::~CMySqlRet()
{
    // 清理行数据
    tVectorItor liTor = mlistpRows.begin();
    for ( ;liTor!=mlistpRows.end();liTor++ )
    {
        CAbsMySqlRow *lp = (*liTor);
        delete lp;
        (*liTor) = NULL;
    }

    // 回收结果行基类
    if ( mpBaseRow != NULL )
        delete mpBaseRow;

    // 清理结果行数据
    mlistpRows.clear();
} // End of function ~CMySqlRet(...
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetResult
// Full name : CMySqlRet::GetResult
// Access    : public 
// Brief     : 
// Parameter : MYSQL* pMySQL
// Return    : RET_CMYSQL_SUCCESS
//             RET_CMYSQL_STORN_RESULT_FAILED
//             RET_CMYSQL_GETRET_DIFFNUM
// Notes     : 
unsigned int CMySqlRet::GetResult( CMySql& cMySQL )
{
    try
    {
	    // 获取查询结果
        CMySqlExpUnit lcEu;
	    MYSQL_RES* pRes                     = cMySQL.__mysql_store_result( lcEu );
        if ( pRes == NULL )
        { return RET_CMYSQL_GETRET_STORN_FAILED; }

	    // 获取查询结果中返回的行数
	    unsigned long long ullRows          = cMySQL.__mysql_num_rows( pRes, lcEu );
	
	    // 提取结果集中的每一个行中的数据
	    for ( int i=0; i<ullRows; i++ )
	    {
	        CAbsMySqlRow* lpRow = mpBaseRow->clone();
	        lpRow->AnalysisRowData( pRes, lcEu );
	        mlistpRows.push_back( lpRow );
	    }
	
	    // 效验提取的结果数
	    if( ullRows != mlistpRows.size() )
	    {
	        return RET_CMYSQL_GETRET_DIFFNUM;
	    }
	
	    // 释放结果集
	    cMySQL.__mysql_free_result( pRes, lcEu );
	    return RET_CMYSQL_SUCCESS;
    } // End of try {   
    catch( CMySqlExpUnit& cEu )              // 捕获上层调用中产生异常
    {   
        cEu.mstrFile   = __FILE__;
        cEu.mstrFunc   = "CMySqlRet::GetResult";
        cEu.mulLine    = __LINE__;
    
        cMySQL.GetExceptionInfo().AddExp( cEu );
        throw cEu;
    } // End of catch( CExpUnit& cEu )
    catch( std::exception& ex )         // 捕获CPP异常
    {
        CMySqlExpUnit       lcEu;
    
        lcEu.menExpType     = CMySqlExpUnit::ET_CPP ;
        lcEu.mulExpCode     = EXP_CMYSQL_CPP;
        lcEu.mstrExpDes     = ex.what();
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySqlRet::GetResult";
        lcEu.mulLine        = __LINE__;
    
        cMySQL.GetExceptionInfo().AddExp( lcEu );
        throw lcEu;
    } // End of catch( std::exception& ex )
    catch( ... )                        // 捕获其他系统异常
    {
        CMySqlExpUnit       lcEu;
    
        lcEu.menExpType     = CMySqlExpUnit::ET_SYSTEM ;
        lcEu.mulExpCode     = EXP_CMYSQL_UNKNOWN;
        lcEu.mstrExpDes     = "调用CMySqlRet::GetResult时捕获一个未知异常";
        lcEu.mstrFile       = __FILE__;
        lcEu.mstrFunc       = "CMySqlRet::GetResult";
        lcEu.mulLine        = __LINE__;
    
        cMySQL.GetExceptionInfo().AddExp( lcEu );
        throw lcEu;
    } // End of catch( ... )
    
} // End of function GetResult(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetBeginRow
// Full name : CMySqlRet::GetBeginRow
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : CMySqlRet::Itor
// Notes     : 
CMySqlRet::tVectorItor CMySqlRet::GetBeginRow(void)
{
    return mlistpRows.begin();
} // End of function GetBeginRow(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetEndRow
// Full name : CMySqlRet::GetEndRow
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : CMySqlRet::Itor
// Notes     : 
CMySqlRet::tVectorItor CMySqlRet::GetEndRow(void)
{
    return mlistpRows.end();
} // End of function GetEndRow(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : Clear
// Full name : CMySqlRet::Clear
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : void
// Notes     : 
void CMySqlRet::Clear(void)
{
    tVectorItor liTor = mlistpRows.begin();
    for ( ;liTor!=mlistpRows.end();liTor++ )
    {
        CAbsMySqlRow* lp= (*liTor);
        if ( lp != NULL )
            delete lp;
        (*liTor) = NULL;
    }
} // End of function Clear(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : GetRowsNum
// Full name : CMySqlRet::GetRowsNum
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : unsigned int
// Notes     : 
unsigned int CMySqlRet::GetRowsNum(void)
{
    return mlistpRows.size();
} // End of function GetRowsNum(...
/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////
// End of file CMySqlRet.cpp
/////////////////////////////////////////////////////////////////////////////////////////