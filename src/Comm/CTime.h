/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTime.h
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 15/1/2016 15:36:56
// Modify time 	: 15/1/2016 15:36:56
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <TIME.H>
#include "CException.h"
#include "VerifyDef.h"

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#define _MAX_TIME_BUF_ 128
#define _TIME_SEC_OF_ONE_DAY_ (60*60*24)

namespace JL {

//////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CTime
//        Notes : 获取时间字符串
//
//////////////////////////////////////////////////////////////////////////////////////////
class CTime
{
//////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    time_t          mTime;
    char            mszBuf[_MAX_TIME_BUF_];

//////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
    CTime();                                                    // Construct define
    CTime( const char* szTime );                                // Construct define
    CTime( time_t tTime );
    virtual ~CTime();;                                          // Destruct define
    CTime( const CTime& Obj );                                  // Copy Construct
    CTime& operator = ( const CTime& Obj );                     // Assignment
    bool operator > ( const CTime& Obj );
    bool operator < ( const CTime* Obj );
    double operator - ( const CTime& Obj );

public:
    const char* ToString( const char* szFormat );
    const char* ToStringShort();                                // 获取时间字符串，格式"%Y-%m-%d"
    const char* ToStringLong();                                 // 获取时间字符串，格式"%Y-%m-%d %H:%M:%S"
    static CTime GetCurrTime( );                                // 获取当前时间
    time_t GetTime( void );
    void SetTime( const char* szFormat);
    void SetTime( unsigned int uiHour, unsigned int uiMin, unsigned int uiSec );
    void AddTime( double tTimeDiff );
}; // End of class CTime
//////////////////////////////////////////////////////////////////////////////////////////

} // End of namesapce JL

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTime.h
/////////////////////////////////////////////////////////////////////////////////////////