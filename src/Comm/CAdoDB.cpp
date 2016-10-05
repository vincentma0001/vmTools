/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CAdoDB.cpp
// Version 		: Version
// Brief 		: 
// Author 		: Auther
// Create time 	: 29/6/2016 8:20:59
// Modify time 	: 29/6/2016 8:20:59
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <windows.h>
#include <iostream>

#include "VerifyDef.h"

#include "CException.h"
#include "CCppExp.h"
#include "CWinSehExp.h"
#include "CExpTrack.h"

#include "../Log.h"
//#include <../../prj/Release/msado15.tlh>

#include "CAdoDB.h"
/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CAdoDB
// Full name : CAdoDB::CAdoDB
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CAdoDB::CAdoDB()
{
    mbIsSetTrans = false;
} // End of function CAdoDB(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CAdoDB
// Full name : CAdoDB::~CAdoDB
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CAdoDB::~CAdoDB()
{
    if ( mpConnection != NULL || mpRecords!= NULL)
    {
        Close();
    }
} // End of function ~CAdoDB(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Open
// Full name : CAdoDB::Open
// Access    : public 
// Brief     : 
// Parameter : const char* szServerAddr, const char* szDB, const char* szUserName, const char* szUserPwd
// Return    : void
// Notes     : 
void CAdoDB::Open(const char* szServerAddr, const char* szDB, const char* szUserName, const char* szUserPwd)
{
    _VERIFY_4_(szServerAddr, szDB, szUserName, szUserPwd);

    mstrServerAddr  = szServerAddr;
    mstrDB = szDB;
    mstrUserName = szUserName;
    mstrUserPwd = szUserPwd;

    LOG("Configure info[Server:%s DB:%s User:%s Pwd:%s]", mstrServerAddr.c_str(), mstrDB.c_str(), mstrUserName.c_str(), mstrUserPwd.c_str());
    try
    {

        Connect();

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }

} // End of function Open(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Connect
// Full name : CAdoDB::Connect
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::Connect()
{
    HRESULT hr;
    try
    {
        LOG("CAdoDB::Connect(), Step 1");
        if (mpConnection != NULL)
        {
            this->Close();
        }
        LOG("CAdoDB::Connect(), Step 2");
        hr = mpConnection.CreateInstance(__uuidof(Connection));
        if (SUCCEEDED(hr))
        {
            LOG("CAdoDB::Connect(), Step 2.1");
            LOG("CAdoDB::Connect(), Step 2.1.1");
            mpConnection->CommandTimeout = 10;
            char lszBuf[1024] = { 0 };
            sprintf_s(lszBuf, sizeof(lszBuf), "Provider=SQLOLEDB;Data Source=%s;Initial Catalog=%s;User ID=%s;Password=%s", mstrServerAddr.c_str(), mstrDB.c_str(), mstrUserName.c_str(), mstrUserPwd.c_str());
            mpConnection->Open(lszBuf, "", "", adModeUnknown);
            LOG("CAdoDB::Connect(), Step 2.1.2");
        }
        else
        {
            LOG("CAdoDB::Connect(), Step 2.2");
            LOG("CAdoDB::Connect(), Step 2.2.1");
            _com_error e(hr);
            throw  CEXP("CAdoDB::Connect(), Create Instance failed(%s)!", (char*)e.ErrorMessage());
            LOG("CAdoDB::Connect(), Step 2.2.2");
        }

        LOG("CAdoDB::Connect(), Step 3");
        return;

    } catch (_com_error &e){
            throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }catch( JL::CException& ex ){
        EXP_TRACK_ADD( ex );
        throw CEXP_E( ex );
    }catch( std::exception& ex ){
        throw CEXP_CPP(ex);
    }catch( CWinSeh& seh ){
        throw CEXP_SEH(seh);
    }catch( ... ){
        throw CEXP("Get an unknown exception!");
    }
} // End of function Connect(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Excute
// Full name : CAdoDB::Excute
// Access    : public 
// Brief     : 
// Parameter : char* szCmdStr
// Return    : _RecordsetPtr&
// Notes     : 
long CAdoDB::Excute(const char* szCmdStr)
{
    try
    {
        if (NULL == mpConnection || ObjectStateEnum::adStateClosed == mpConnection->State)
        {
            Connect();
        }
        
        if ( mpRecords!=NULL )
        {
            mpRecords.Release();
        }

        _variant_t lvAffected;;

        LOG("CAdoDB::Excute(), SQL:%s", szCmdStr);
        mpRecords = mpConnection->Execute(_bstr_t(szCmdStr), &lvAffected, adCmdText);
        //mpConnection->Execute(_bstr_t(szCmdStr), &lvAffected, adCmdText);
        return lvAffected.lVal;

    }catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function Excute(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Call
// Full name : CAdoDB::Call
// Access    : public 
// Brief     : 
// Parameter : char* szCmdStr
// Return    : long
// Notes     : 
void CAdoDB::Call_Begin(char* szCmdStr)
{
    try
    {
        if (mpCommand != NULL)
        {
            mpCommand.Release();
        }

        // 创建调用实例
        HRESULT hr = mpCommand.CreateInstance(__uuidof(Command));
        if (FAILED(hr))
        {
            throw CEXP("CAdoDB::Call_Begin(), CreateInstance failed!");
        }

        // 设置存储过程名称
        mpCommand->CommandText = _bstr_t(szCmdStr);
        
        // 设置返回值
        _ParameterPtr loParam;
        loParam = mpCommand->CreateParameter(_bstr_t("return"), adInteger, adParamReturnValue, sizeof(int));
        HRESULT lhr = mpCommand->Parameters->Append(loParam);
        if (FAILED(lhr))
            throw CEXP("CAdoDB::Call_Begin(), Set return parameter failed!");

        return;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }

} // End of function Call(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetParam
// Full name : CAdoDB::SetParam
// Access    : public 
// Brief     : 
// Parameter : const char* szParamName, bool IsInput, int iValue
// Return    : void
// Notes     : 
void CAdoDB::SetParamI(const char* szParamName, bool IsInput, int iValue)
{
    try
    {
        _ParameterPtr param;
        param.CreateInstance(__uuidof(Parameter));

        param = mpCommand->CreateParameter(_bstr_t(szParamName), DataTypeEnum::adInteger, IsInput==true?adParamInput:adParamOutput, -1, _variant_t(iValue));
        mpCommand->Parameters->Append(param);

        return;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }

} // End of function SetParam(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetParamD
// Full name : CAdoDB::SetParamD
// Access    : public 
// Brief     : 
// Parameter : const char* szParamName, bool IsInput, double dValue
// Return    : void
// Notes     : 
void CAdoDB::SetParamD(const char* szParamName, bool IsInput, double dValue)
{
    try
    {
        _ParameterPtr param;
        param = mpCommand->CreateParameter(_bstr_t(szParamName), DataTypeEnum::adDouble, IsInput == true ? adParamInput : adParamOutput, sizeof(double), _variant_t(dValue));
        mpCommand->Parameters->Append(param);

        return;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function SetParamF(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetParamS
// Full name : CAdoDB::SetParamS
// Access    : public 
// Brief     : 
// Parameter : const char* szParamName, bool IsInput, std::string strValue
// Return    : void
// Notes     : 
void CAdoDB::SetParamS(const char* szParamName, bool IsInput, std::string strValue, long lSize )
{
    try
    {
        _ParameterPtr param;
        param = mpCommand->CreateParameter(_bstr_t(szParamName), DataTypeEnum::adChar, IsInput == true ? adParamInput : adParamOutput, lSize, _variant_t(strValue.c_str()));
        mpCommand->Parameters->Append(param);

        return;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function SetParamS(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Call_End
// Full name : CAdoDB::Call_End
// Access    : public 
// Brief     : 
// Parameter : char* szCmdStr
// Return    : long
// Notes     : 
long CAdoDB::Call_End(void)
{
    try
    {
        if (NULL == mpConnection || ObjectStateEnum::adStateClosed == mpConnection->State)
        {
            Connect();
        }

        if (mpRecords != NULL)
        {
            mpRecords.Release();
        }

        mpCommand->ActiveConnection = mpConnection;

        std::cout << "Command str = " << (char*)mpCommand->GetCommandText() << std::endl;

        //mpCommand->Parameters->Refresh();

        _variant_t lvAffected;
        mpRecords = mpCommand->Execute(&lvAffected, NULL, adCmdStoredProc);
        //mpCommand->Execute(&lvAffected, NULL, adCmdStoredProc);
        return lvAffected.lVal;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function Call_End(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetReturn
// Full name : CAdoDB::GetReturn
// Access    : public 
// Brief     : 
// Parameter : int& iValue
// Return    : void
// Notes     : 
int CAdoDB::GetReturn( )
{
    try
    {
        _variant_t lvReturn = mpCommand->Parameters->GetItem(_bstr_t("return"))->GetValue();
        if (lvReturn.vt != VT_I4)
        {
            throw CEXP("CAdoDB::GetReturn(), the param(return)'s type is't intger!");
        }
        return lvReturn.intVal;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function GetReturn(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetParamI
// Full name : CAdoDB::GetParamI
// Access    : public 
// Brief     : 
// Parameter : const char* szParamName, int& iValue
// Return    : void
// Notes     : 
void CAdoDB::GetParamI(const char* szParamName, int& iValue)
{
    try
    {
        
        _variant_t lvReturn = mpCommand->Parameters->GetItem(_bstr_t(szParamName))->Value;
        if (  lvReturn.vt != VT_I4 )
        {
            throw CEXP("CAdoDB::GetParamI(), the param(%s)'s type is't intger!", szParamName);
        }
        iValue = lvReturn.intVal;
        return;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function GetParamI(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetParamD
// Full name : CAdoDB::GetParamD
// Access    : public 
// Brief     : 
// Parameter : const char* szParamName, double& dValue
// Return    : void
// Notes     : 
void CAdoDB::GetParamD(const char* szParamName, double& dValue)
{
    try
    {

        _variant_t lvReturn = mpCommand->Parameters->GetItem(_bstr_t(szParamName))->Value;
        if (lvReturn.vt != VT_I4)
        {
            throw CEXP("CAdoDB::GetParamD(), the param(%s)'s type is't double!");
        }
        dValue = lvReturn.dblVal;
        return;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function GetParamD(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetParamS
// Full name : CAdoDB::GetParamS
// Access    : public 
// Brief     : 
// Parameter : const char* szParamName, std::string& strValue
// Return    : void
// Notes     : 
void CAdoDB::GetParamS(const char* szParamName, std::string& strValue)
{
    try
    {

        _variant_t lvReturn = mpCommand->Parameters->GetItem(_bstr_t(szParamName))->Value;
        if (lvReturn.vt != VT_BSTR)
        {
            throw CEXP("CAdoDB::GetParamS(), the param(%s)'s type is't bstr!");
        }
        strValue = Convert(_bstr_t(lvReturn));
        return;
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function GetParamS(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Close
// Full name : CAdoDB::Close
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::Close()
{
    try
    {
        if (mpRecords!=NULL)
        {
            mpRecords.Release();
        }

        //close connection, if not yet closed
        if (mpConnection != NULL || mpConnection->State == ObjectStateEnum::adStateConnecting)
        {
            mpConnection->Close();
            mpConnection.Release();
        }
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function Close(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : BeginTrans
// Full name : CAdoDB::BeginTrans
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::BeginTrans()
{
    try
    {
        if (NULL == mpConnection || ObjectStateEnum::adStateClosed == mpConnection->State)
        {
            Connect();
        }

        mpConnection->BeginTrans();
        mbIsSetTrans = true;

        LOG("CAdoDB::BeginTrans(), done!");
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function BeginTrans(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CommitTrans
// Full name : CAdoDB::CommitTrans
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::CommitTrans()
{
    try{
        if (mbIsSetTrans == false)
        {
            return;
        }

        if (NULL == mpConnection || ObjectStateEnum::adStateClosed == mpConnection->State)
        {
            Connect();
        }

        HRESULT lhr = mpConnection->CommitTrans();
        if (FAILED(lhr))
        {
            throw CEXP("CommitTrans failed!");
        }
        mbIsSetTrans = false;

        LOG("CAdoDB::CommitTrans(), done!");
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function CommitTrans(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RollbackTrans
// Full name : CAdoDB::RollbackTrans
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::RollbackTrans()
{
    try{
        if (mbIsSetTrans == false)
        {
            return;
        }

        if (NULL == mpConnection || ObjectStateEnum::adStateClosed == mpConnection->State)
        {
            Connect();
        }

        HRESULT lhr = mpConnection->RollbackTrans();
        if (FAILED(lhr))
        {
            throw CEXP("CommitTrans failed!");
        }

        mbIsSetTrans = false;

        LOG("CAdoDB::RollbackTrans(), done!");
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function RollbackTrans(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CloseRecord
// Full name : CAdoDB::CloseRecord
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::CloseRecord()
{
    try{
        if (NULL != mpRecords )
        {
            mpRecords->Close();
            mpRecords = NULL;

        }
    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function CloseRecord(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : IsRecordEOF
// Full name : CAdoDB::IsRecordEOF
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : bool
// Notes     : 
bool CAdoDB::IsRecordEOF()
{
    bool bResult = true;

    if (NULL != mpRecords)
    {
        if (!mpRecords->adoEOF)
            bResult = false;
    }
    return bResult;
} // End of function IsRecordEOF(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RecordMoveNext
// Full name : CAdoDB::RecordMoveNext
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::RecordMoveNext()
{
    try
    {

        if (NULL != mpRecords )
        {
            mpRecords->MoveNext();
        }


    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function RecordMoveNext(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RecordMoveLast
// Full name : CAdoDB::RecordMoveLast
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::RecordMovePrev()
{
    try
    {

        if (NULL != mpRecords)
        {
            mpRecords->MovePrevious();
        }

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function RecordMoveLast(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RecordMoveLast
// Full name : CAdoDB::RecordMoveLast
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::RecordMoveLast()
{
    try
    {

        if (NULL != mpRecords && mpRecords->adoEOF != VARIANT_FALSE)
        {
            mpRecords->MoveLast();
        }

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function RecordMoveLast(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ColumnValue
// Full name : CAdoDB::ColumnValue
// Access    : public 
// Brief     : 
// Parameter : long lIndex, char *szBuff, int nBuffSize
// Return    : bool
// Notes     : 
bool CAdoDB::ColumnValueIB(long lIndex, char *szBuff, int nBuffSize)
{
    try
    {

        bool bResult = false;

        if (adStateClosed != mpRecords->State)
        {
            _variant_t lvColumn(lIndex);
            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;

            WideCharToMultiByte(CP_ACP, 0, lvResult.bstrVal, -1, szBuff, nBuffSize, NULL, NULL);
            bResult = true;
        }
        return bResult;

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ColumnValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ColumnValue
// Full name : CAdoDB::ColumnValue
// Access    : public 
// Brief     : 
// Parameter : const char* szColumnName, char *szBuff, int nBuffSize
// Return    : bool
// Notes     : 
bool CAdoDB::ColumnValueNB(const char* szColumnName, char *szBuff, int nBuffSize)
{
    try
    {

        _VERIFY_(szColumnName);

        bool bResult = false;
        if (adStateClosed != mpRecords->State)
        {
            _variant_t lvColumn(szColumnName);
            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;

            WideCharToMultiByte(CP_ACP, 0, lvResult.bstrVal, -1, szBuff, nBuffSize, NULL, NULL);
            bResult = true;
        }
        return bResult;

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ColumnValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ColumnValue
// Full name : CAdoDB::ColumnValue
// Access    : public 
// Brief     : 
// Parameter : long lIndex, std::string& strValue
// Return    : bool
// Notes     : 
bool CAdoDB::ColumnValueIS(long lIndex, std::string& strValue)
{
    try
    {

        bool bResult = false;

        if (adStateClosed != mpRecords->State)
        {
            _variant_t lvColumn(lIndex);
            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;

            strValue = _com_util::ConvertBSTRToString(_bstr_t(lvResult));
            bResult = true;
        }
        return bResult;

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ColumnValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ColumnValue
// Full name : CAdoDB::ColumnValue
// Access    : public 
// Brief     : 
// Parameter : const char* szColumnName, std::string& strValue
// Return    : bool
// Notes     : 
bool CAdoDB::ColumnValueNS(const char* szColumnName, std::string& strValue)
{
    try
    {

        _VERIFY_(szColumnName);

        bool bResult = false;
        if (adStateClosed != mpRecords->State)
        {
            _variant_t lvColumn(szColumnName);
            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;

            strValue = _com_util::ConvertBSTRToString(_bstr_t(lvResult));;
            bResult = true;
        }
        return bResult;

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ColumnValue(...
/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
//// Name      : ColumnValue
//// Full name : CAdoDB::ColumnValue
//// Access    : public 
//// Brief     : 
//// Parameter : long lIndex, double& dValue
//// Return    : bool
//// Notes     : 
//bool CAdoDB::ColumnValueIF(long lIndex, float& fValue)
//{
//    try
//    {
//
//        bool bResult = false;
//
//        if (adStateClosed != mpRecords->State)
//        {
//            _variant_t lvColumn(lIndex);
//            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;
//
//            fValue = lvResult.fltVal;
//            bResult = true;
//        }
//        return bResult;
//
//    }
//    catch (_com_error &e){
//        throw CEXP("Get an exception(%s)", Convert(e.Description()));
//    }
//    catch (CException& ex){
//        EXP_TRACK_ADD(ex);
//        throw CEXP_E(ex);
//    }
//    catch (std::exception& ex){
//        throw CEXP_CPP(ex);
//    }
//    catch (CWinSeh& seh){
//        throw CEXP_SEH(seh);
//    }
//    catch (...){
//        throw CEXP("Get an unknown exception!");
//    }
//} // End of function ColumnValue(...
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ColumnValue
// Full name : CAdoDB::ColumnValue
// Access    : public 
// Brief     : 
// Parameter : long lIndex, float& fValue
// Return    : bool
// Notes     : 
bool CAdoDB::ColumnValueID(long lIndex, double& dValue)
{
    try
    {

        bool bResult = false;

        if (adStateClosed != mpRecords->State)
        {
            _variant_t lvColumn(lIndex);
            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;

            dValue = lvResult.dblVal;
            bResult = true;
        }
        return bResult;

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ColumnValue(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ColumnValue
// Full name : CAdoDB::ColumnValue
// Access    : public 
// Brief     : 
// Parameter : const char* szColumnName, double& dValue
// Return    : bool
// Notes     : 
bool CAdoDB::ColumnValueND(const char* szColumnName, double& dValue)
{
    try
    {

        _VERIFY_(szColumnName);

        bool bResult = false;
        if (adStateClosed != mpRecords->State)
        {
            _variant_t lvColumn(szColumnName);
            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;

            dValue = lvResult.dblVal;
            bResult = true;
        }
        return bResult;

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ColumnValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ColumnValue
// Full name : CAdoDB::ColumnValue
// Access    : public 
// Brief     : 
// Parameter : long lIndex, int& iValue
// Return    : bool
// Notes     : 
bool CAdoDB::ColumnValueII(long lIndex, int& iValue)
{
    try
    {

        bool bResult = false;

        if (adStateClosed != mpRecords->State)
        {
            _variant_t lvColumn(lIndex);
            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;

            iValue = lvResult.intVal;
            bResult = true;
        }
        return bResult;

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ColumnValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ColumnValue
// Full name : CAdoDB::ColumnValue
// Access    : public 
// Brief     : 
// Parameter : const char* szColumnName, int& iValue
// Return    : bool
// Notes     : 
bool CAdoDB::ColumnValueNI(const char* szColumnName, int& iValue)
{
    try
    {

        _VERIFY_(szColumnName);

        bool bResult = false;
        if (adStateClosed != mpRecords->State)
        {
            _variant_t lvColumn(szColumnName);
            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;

            iValue = lvResult.intVal;
            bResult = true;
        }
        return bResult;

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function ColumnValue(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Convert
// Full name : CAdoDB::Convert
// Access    : private 
// Brief     : 
// Parameter : _bstr_t& bStr
// Return    : const char*
// Notes     : 
const char* CAdoDB::Convert(_bstr_t& bStr)
{
    try
    {

        return _com_util::ConvertBSTRToString(bStr);

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function Convert(...
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Rtrim
// Full name : CAdoDB::Rtrim
// Access    : private 
// Brief     : 
// Parameter : std::string &str
// Return    : std::string
// Notes     : 
std::string CAdoDB::Rtrim(std::string &str)
{
    //std::string::size_type lstPos = str.find_first_of(::isspace, str.rbegin(), );
    //str.erase( lstPos,  );
    //return str;
    return "";
} // End of function Rtrim(...
/////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
//// Name      : Convert
//// Full name : CAdoDB::Convert
//// Access    : private 
//// Brief     : 
//// Parameter : const char* pStr
//// Return    : BSTR
//// Notes     : 
//BSTR CAdoDB::Convert(const char* pStr)
//{
//    try
//    {
//
//        return _com_util::ConvertStringToBSTR(pStr);
//
//    }
//    catch (_com_error &e){
//        throw CEXP("Get an exception(%s)", Convert(e.Description()));
//    }
//    catch (CException& ex){
//        EXP_TRACK_ADD(ex);
//        throw CEXP_E(ex);
//    }
//    catch (std::exception& ex){
//        throw CEXP_CPP(ex);
//    }
//    catch (CWinSeh& seh){
//        throw CEXP_SEH(seh);
//    }
//    catch (...){
//        throw CEXP("Get an unknown exception!");
//    }
//} // End of function Convert(...
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : RecordMoveFirst
// Full name : CAdoDB::RecordMoveFirst
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : void
// Notes     : 
void CAdoDB::RecordMoveFirst()
{
    try
    {

        if (NULL != mpRecords && mpRecords->adoEOF != VARIANT_FALSE)
        {
            mpRecords->MoveFirst();
        }

    }
    catch (_com_error &e){
        throw CEXP("Get an exception(%s)", Convert(e.Description()));
    }
    catch (JL::CException& ex){
        EXP_TRACK_ADD(ex);
        throw CEXP_E(ex);
    }
    catch (std::exception& ex){
        throw CEXP_CPP(ex);
    }
    catch (CWinSeh& seh){
        throw CEXP_SEH(seh);
    }
    catch (...){
        throw CEXP("Get an unknown exception!");
    }
} // End of function RecordMoveFirst(...
/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
//// Name      : ColumnValue
//// Full name : CAdoDB::ColumnValue
//// Access    : public 
//// Brief     : 
//// Parameter : const char* szColumnName, double& dValue
//// Return    : bool
//// Notes     : 
//bool CAdoDB::ColumnValueNF(const char* szColumnName, float& fValue)
//{
//    try
//    {
//
//        _VERIFY_(szColumnName);
//
//        bool bResult = false;
//        if (adStateClosed != mpRecords->State)
//        {
//            _variant_t lvColumn(szColumnName);
//            _variant_t lvResult = mpRecords->Fields->GetItem(lvColumn)->Value;
//
//            fValue = lvResult.fltVal;
//            bResult = true;
//        }
//        return bResult;
//
//    }
//    catch (_com_error &e){
//        throw CEXP("Get an exception(%s)", Convert(e.Description()));
//    }
//    catch (CException& ex){
//        EXP_TRACK_ADD(ex);
//        throw CEXP_E(ex);
//    }
//    catch (std::exception& ex){
//        throw CEXP_CPP(ex);
//    }
//    catch (CWinSeh& seh){
//        throw CEXP_SEH(seh);
//    }
//    catch (...){
//        throw CEXP("Get an unknown exception!");
//    }
//} // End of function ColumnValue(...
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CAdoDB.cpp
/////////////////////////////////////////////////////////////////////////////////////////