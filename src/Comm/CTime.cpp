/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CTime.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 15/1/2016 15:35:22
// Modify time 	: 15/1/2016 15:35:22
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "CTime.h"

namespace JL{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CTime
// Full name : CTime::CTime
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CTime::CTime() :mTime(0)
{

} // End of function CTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CTime
// Full name : CTime::CTime
// Access    : public 
// Brief     : 
// Parameter : const char* szTime
// Return    : 
// Notes     : 
CTime::CTime(const char* szTime) : mTime(0)
{
    if ( szTime == NULL )
        throw std::logic_error( "Get an invalied handle!" );

    struct tm lTm = {0};
#if defined (_MSC_VER)&&( _MSC_VER<=1200 )
    sscanf( szTime, "%d-%d-%d %d:%d:%d", &lTm.tm_year, &lTm.tm_mon, &lTm.tm_mday, &lTm.tm_hour, &lTm.tm_min, &lTm.tm_sec );
#else
    sscanf_s( szTime, "%d-%d-%d %d:%d:%d", &lTm.tm_year, &lTm.tm_mon, &lTm.tm_mday, &lTm.tm_hour, &lTm.tm_min, &lTm.tm_sec  );
#endif

     lTm.tm_year -= 1900;
     lTm.tm_mon  -= 1;
     lTm.tm_isdst = -1;

    mTime = mktime( &lTm );
} // End of function CTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CTime
// Full name : CTime::CTime
// Access    : public 
// Brief     : 
// Parameter : const CTime& Obj
// Return    : 
// Notes     : 
CTime::CTime(const CTime& Obj)
{
    mTime = Obj.mTime;
} // End of function CTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=
// Full name : CTime::operator=
// Access    : public 
// Brief     : 
// Parameter : const CTime& Obj
// Return    : CTime&
// Notes     : 
CTime& CTime::operator=(const CTime& Obj)
{
    mTime = Obj.mTime;

    return *this;
} // End of function operator=(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CTime
// Full name : CTime::~CTime
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CTime::~CTime()
{

} // End of function ~CTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ToStringShort
// Full name : CTime::ToStringShort
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : std::string
// Notes     : 
const char* CTime::ToStringShort()
{
    struct tm* lpTm = NULL;
#if defined ( _MSC_VER ) && ( _MSC_VER <=1200 )
    lpTm = localtime( &mTime );
#else
    errno_t er = localtime_s( lpTm, &mTime );
#endif
    strftime( mszBuf, _MAX_TIME_BUF_, "%Y-%m-%d", lpTm);

    return mszBuf;
} // End of function ToStringShort(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ToStringLong
// Full name : CTime::ToStringLong
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : std::string
// Notes     : 
const char* CTime::ToStringLong()
{
    
#if defined ( _MSC_VER ) && ( _MSC_VER <=1200 )
    struct tm* lpTm = NULL;
    lpTm = localtime( &mTime );
    strftime( mszBuf, _MAX_TIME_BUF_, "%Y-%m-%d %H:%M:%S", lpTm);
    return mszBuf;
#else
    struct tm loTm ;
    errno_t er = localtime_s( &loTm, &mTime );
    strftime( mszBuf, _MAX_TIME_BUF_, "%Y-%m-%d %H:%M:%S", &loTm);
    return mszBuf;

#endif


} // End of function ToStringLong(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrTime
// Full name : CTime::GetCurrTime
// Access    : public static 
// Brief     : 
// Parameter : 
// Return    : CTime
// Notes     : 
CTime CTime::GetCurrTime()
{
    CTime lTime;
    time( &lTime.mTime );
    return lTime;
} // End of function GetCurrTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CTime::ToString
// Access    : public 
// Brief     : 
// Parameter : const char* szFormat
// Return    : const char*
// Notes     : 
const char* CTime::ToString(const char* szFormat)
{
#if defined ( _MSC_VER ) && ( _MSC_VER <=1200 )
    struct tm* lpTm = localtime( &mTime );
    strftime( mszBuf, _MAX_TIME_BUF_, szFormat, lpTm);
    return mszBuf;
#else
    struct tm loTm;
    errno_t er = localtime_s( &loTm, &mTime );
    strftime( mszBuf, _MAX_TIME_BUF_, szFormat, &loTm );
    return mszBuf;

#endif
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetTime
// Full name : JL::CTime::SetTime
// Access    : public 
// Brief     : 
// Parameter : const char* szFormat
// Return    : void
// Notes     : 
void JL::CTime::SetTime(const char* szFormat)
{
    _VERIFY_( szFormat );

    unsigned int luiHour    = 0;
    unsigned int luiMin     = 0;
    unsigned int luiSec     = 0;

#if defined (_MSC_VER)&&(_MSC_VER<=1300)
    sscanf( szFormat, "%u:%u:%u", &luiHour, &luiMin, &luiSec );
#else
    sscanf_s( szFormat,"%u:%u:%u", &luiHour, &luiMin, &luiSec );
#endif

    if ( ( luiHour>=24 ) || (luiMin>=60) || ( luiSec>=60 ) )
    {
        throw CEXP( "Set Error time H(%d) M(%d) S(%d)", "CTime::SetTime", luiHour, luiMin,luiSec );
    }

    tm* lpTm = NULL;
#if defined (_MSC_VER)&&(_MSC_VER<=1300)
    lpTm = localtime( &mTime );
#else
    errno_t er = localtime_s( lpTm, &mTime );
#endif
    lpTm->tm_hour = luiHour;
    lpTm->tm_min = luiMin;
    lpTm->tm_sec = luiSec;

    mTime = mktime( lpTm );
} // End of function SetTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : SetTime
// Full name : JL::CTime::SetTime
// Access    : public 
// Brief     : 
// Parameter : unsigned int uiHour, unsigned int uiMin, unsigned int uiSec
// Return    : void
// Notes     : 
void JL::CTime::SetTime(unsigned int uiHour, unsigned int uiMin, unsigned int uiSec)
{
    if ( ( uiHour>=24 ) || (uiMin>=60) || ( uiSec>=60 ) )
    {
        throw CEXP( "Set Error time H(%d) M(%d) S(%d)", "CTime::SetTime", uiHour, uiMin,uiSec );
    }

    tm* lpTm = NULL;
#if defined (_MSC_VER)&&(_MSC_VER<=1300)
    lpTm = localtime( &mTime );
#else
    errno_t er = localtime_s( lpTm, &mTime );
#endif
    lpTm->tm_hour = uiHour;
    lpTm->tm_min = uiMin;
    lpTm->tm_sec = uiSec;

    mTime = mktime( lpTm );
} // End of function SetTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : AddTime
// Full name : JL::CTime::AddTime
// Access    : public 
// Brief     : 
// Parameter : double tTimeDiff
// Return    : void
// Notes     : 
void JL::CTime::AddTime(double tTimeDiff)
{
    mTime += (time_t)tTimeDiff;
} // End of function AddTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetTime
// Full name : JL::CTime::GetTime
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : time_t
// Notes     : 
time_t JL::CTime::GetTime(void)
{
    return mTime;
} // End of function GetTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CTime
// Full name : JL::CTime::CTime
// Access    : public 
// Brief     : 
// Parameter : time_t tTime
// Return    : 
// Notes     : 
JL::CTime::CTime(time_t tTime) :mTime(tTime)
{
    memset( mszBuf, 0x00, sizeof(mszBuf)  );
} // End of function CTime(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator>
// Full name : JL::CTime::operator>
// Access    : public 
// Brief     : 
// Parameter : const CTime& Obj
// Return    : bool
// Notes     : 
bool JL::CTime::operator>(const CTime& Obj)
{
    if ( mTime > Obj.mTime )
        return true;

    return false;
} // End of function operator>(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator<
// Full name : JL::CTime::operator<
// Access    : public 
// Brief     : 
// Parameter : const CTime* Obj
// Return    : bool
// Notes     : 
bool JL::CTime::operator<(const CTime* Obj)
{
    if ( mTime < Obj->mTime )
        return true;

    return false;
} // End of function operator<(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator-
// Full name : JL::CTime::operator-
// Access    : public 
// Brief     : 
// Parameter : const CTime& Obj
// Return    : double
// Notes     : 
double JL::CTime::operator-(const CTime& Obj)
{
    double ldDiff = difftime( mTime, Obj.mTime );
    return ldDiff;
} // End of function operator-(...
/////////////////////////////////////////////////////////////////////////////////////////

} // End of namespace JL

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTime.cpp
/////////////////////////////////////////////////////////////////////////////////////////