/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CTimeStr.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/19 19:37:43
// Modify time  : 2020/01/19 19:37:43
// Note         :
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

#ifndef __CTIMESTR_H__
#define __CTIMESTR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <time.h>

// Config files included
#include <vmCfg.h>
#include <vmLibTime/vmCfgTime.h>

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CTimeStr : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CTimeStr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
typedef enum emRet
{
    emSucceed = 0,
    emErrYear = -1,
    emErrDay  = -2,

    emError   = vMinsLong
}*PEMRET;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CTimeStr():mulYear(0),mulMonth(0),mulDay(0),mulHour(0),mulMinute(0),mulSeconde(0),mulMSeconde(0),mulErrCode(0){};
    // Destruct define
    virtual ~CTimeStr(){};
    
private:
    // No Copy
    CTimeStr(const CTimeStr& obj){};
    // No Assignment
    CTimeStr& operator = ( const CTimeStr& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :

protected:
    unsigned long mulYear;
    unsigned long mulMonth;
    unsigned long mulDay;
    unsigned long mulHour;
    unsigned long mulMinute;
    unsigned long mulSeconde;
    unsigned long mulMSeconde;

/////////////////////////////////////////////////////////////////////////////////////////
// Error infomation :
private:
    // 错误信息
    unsigned long  mulErrCode;

public:
    // 判断是否有错误发生
    bool HasError() { return mulErrCode == 0 ? false : true; }
    // 返回错误代码
    unsigned long toErrCode() { return mulErrCode; };

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    bool toTimet( tTimet& stTimet )
    {
        tm* lpTm = NULL;
#if defined (_MSC_VER)&&(_MSC_VER<=1300)
        lpTm = localtime(&mTime.time);
        // #  TODO : Add condition brief here ##
        if (lpTm == nullptr)
        {
        	mulErrCode = GetLastError();
            return false;
        } 
        // End of if (lpTm == nullptr) ...
#else
        errno_t leRet = localtime_s(lpTm, &stTimet);
        // #  TODO : Add condition brief here ##
        if (leRet!=0)
        {
            mulErrCode = leRet;
            return false;        	
        } 
        // End of if (leRet!=0) ... 
#endif
        lpTm->tm_year = mulYear;
        lpTm->tm_mon  = mulMonth;
        lpTm->tm_mday = mulDay;
        lpTm->tm_hour = mulHour;
        lpTm->tm_min  = mulMinute;
        lpTm->tm_sec  = mulSeconde;


        stTimet = mktime(lpTm);

        return true;
    }
    
    virtual bool CheckYear()
    {
        // #  TODO : Add condition brief here ##
        if ( mulYear >= 1970 )
        {
        	mulYear = mulYear-1970;
        } 
        // End of if ( mulYear < 1970 ) ... 

        return true;
    }

}; // End of class CTimeStr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CTIMESTR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTimeStr.h
/////////////////////////////////////////////////////////////////////////////////////////