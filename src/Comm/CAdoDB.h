/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CAdoDB.h
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 29/6/2016 8:21:08
// Modify time 	: 29/6/2016 8:21:08
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CADODB_H__
#define __CADODB_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <string>

#import "C:/Program Files/Common Files/System/ado/msado15.dll" no_namespace rename("EOF", "adoEOF") rename("BOF", "FirstOfFile")  


typedef _RecordsetPtr  AdoRecPtr;
typedef _ConnectionPtr AdoCnnPtr;
typedef _CommandPtr    AdoComPtr;

#define P_IS_SUCCESS 0;

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CAdoDB
//        Notes : ## add class brief here #
//
/////////////////////////////////////////////////////////////////////////////////////////
class CAdoDB
{
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    AdoCnnPtr           mpConnection;
    AdoRecPtr           mpRecords;
    AdoComPtr           mpCommand;
    bool                mbIsSetTrans;

private:
    std::string         mstrUserName;
    std::string         mstrUserPwd;
    std::string         mstrServerAddr;
    std::string         mstrDB;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
	CAdoDB();		            // Construct define
	virtual ~CAdoDB();          // Destruct define

/////////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    void Open(const char* szServerAddr, const char* szDB, const char* szUserName, const char* szUserPwd);
    void Close();
    void Connect();

    long Excute(const char* szCmdStr);
    
    void Call_Begin(char* szPropName);
    long Call_End(void);
    int GetReturn(void);

    void SetParamI(const char* szParamName, bool IsInput, int    iValue);
    void SetParamD(const char* szParamName, bool IsInput, double dValue);
    void SetParamS(const char* szParamName, bool IsInput, std::string strValue, long lSize);
    void GetParamI(const char* szParamName, int&    iValue);
    void GetParamD(const char* szParamName, double& dValue);
    void GetParamS(const char* szParamName, std::string& strValue);

    void BeginTrans();
    void CommitTrans();
    void RollbackTrans();

    void CloseRecord();

    bool IsRecordEOF();

    void RecordMoveNext();
    void RecordMovePrev();
    void RecordMoveFirst();
    void RecordMoveLast();

    bool ColumnValueIB(long lIndex, char *szBuff, int nBuffSize);
    bool ColumnValueIS(long lIndex, std::string& strValue);
    bool ColumnValueID(long lIndex, double& dValue);
    bool ColumnValueII(long lIndex, int& iValue);

    bool ColumnValueNB(const char* szColumnName, char *szBuff, int nBuffSize);
    bool ColumnValueNS(const char* szColumnName, std::string& strValue);
    bool ColumnValueND(const char* szColumnName, double& dValue);
    bool ColumnValueNI(const char* szColumnName, int& iValue);

private:
    const char* Convert(_bstr_t& bStr);
    std::string Rtrim(std::string &str);

    //BSTR Convert( const char* pStr);
}; // End of class CAdoDB
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CADODB_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CAdoDB.h
/////////////////////////////////////////////////////////////////////////////////////////
