/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CDateTime.hpp
// Version      : 1.0.0.0
// Brief        : 此类包含了一系列关于时间操作的函数
// Author       : v.m.
// Create time  : 2019/12/18 10:41:19
// Modify time  : 2019/12/18 10:41:19
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

#ifndef __CDATETIME_HPP__
#define __CDATETIME_HPP__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
#ifndef _USE_TIMEB_
#   define  _USE_TIMEB_
#   include <sys/timeb.h>
#endif // !_USE_TIMEB_H_

#ifndef _INC_TIME
#   error this file need #include <time.h>
#endif // ! _INC_TIME

#ifndef   __VM_UTIL_H__
#	error this file need #include <vmUtil.h>
#endif // __VM_UTIL_H__

#ifndef   __CMEMPTR_H__
#	error this file need #include <vmBaseLib/CMemPtr.h>
#endif // __CMEMPTR_H__

#ifndef   __CSTRPTR_H__
#	error this file need #include <vmBaseLib/CStrPtr.h>
#endif // __CSTRPTR_H__

#include <vmLibBase/CAny.hpp>
#include <vmLibBase/CParser.h>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#ifndef   _V_CDATETIME_MAX_BUF_
    #define _V_CDATETIME_MAX_BUF_ 128
#endif // _V_CDATETIME_MAX__BUF_

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CDateTime : 此类包含了一系列关于时间操作的函数
//
/////////////////////////////////////////////////////////////////////////////////////////
template< size_t sztBufSize = _V_CDATETIME_MAX_BUF_ >
class CDateTime
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CDateTime();
    explicit CDateTime(time_t tTime);
    explicit CDateTime(_timeb tTimeb);
    // Destruct define
    virtual ~CDateTime();

    // Copy construct define
    CDateTime(const CDateTime& obj);

public:
    // 赋值操作
    inline CDateTime&  operator =  ( const CDateTime& obj );
    // 加法操作
    inline time_t      operator +  ( const time_t tTimeDiff );
    // 减法操作
    inline time_t      operator -  ( const time_t tTimeDiff);
    // == 操作
    inline bool        operator == ( const CDateTime& Obj );
    // != 操作
    inline bool        operator != ( const CDateTime& Obj );
    // > 操作
    inline bool        operator >  ( const CDateTime& Obj );
    // < 操作
    inline bool        operator <  ( const CDateTime& Obj );
   
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
	// 时间存储结构， 如果定义_USE_32BIT_TIME_T宏使用32bit版本，否则使用64bit版本
	_timeb  mstTime;
    // 数据缓存，用于存储时间字符串
    char    mszBuf[sztBufSize];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 获取当前时间
	inline static CDateTime GetCurrTime();
    // 获取当前对象的time_t时间结构
    inline time_t& timet();
    inline _timeb& timeb();
    // 获取当前对象的毫秒数
    inline unsigned short millitm();

    // 设置时间对象
    inline void SetTime( unsigned int   uiHour, unsigned int   uiMin,
                         unsigned int   uiSec,  unsigned short usMill = 0);
    // 设置时间对象
    inline void SetTime( unsigned int  uiYear,  unsigned int  uiMonth, unsigned int  uiDay,
                         unsigned int  uiHour,  unsigned int  uiMin,   unsigned int  uiSec, 
                         unsigned short usMill = 0 );

    // 根据格式化字符串（YYYY/MM/DD HH:MM:SS.MS）解析Time对象
    inline void SetTimeFmFull(const void* szFmtStr);

    // 获取时间字符串，格式"YYYY/MM/DD"
    inline const char* ToStrDay1();
    // 获取时间字符串，格式"YYMMDD"
    inline const char* ToStrDay2();
    // 获取时间字符串，格式"HH:MM:SS"
    inline const char* ToStrTime();
    // 获取时间字符串，格式"MS"
    inline const char* ToStrMillitm();
    // 获取时间字符串，格式""%Y/%m/%d %H:%M:%S:%Mill"
    inline const char* ToStrFull();

    // 格式化时间结构
    //     ==================================================================================
    //     specifier | Replaced by                               | Example
    //     ----------------------------------------------------------------------------------
    //     %a	     | Abbreviated weekday name *	             | Thu
    //     %A	     | Full weekday name *	                     | Thursday
    //     %b	     | Abbreviated month name *	                 | Aug
    //     %B	     | Full month name *                         | August
    //     %c	     | Date and time representation *	         | Thu Aug 23 14:55:02 2001
    //     %C	     | Year divided by 100 and truncated to      | 20
    //               | integer(00 - 99)                          |
    //     %d        | Day of the month, zero - padded(01 - 31)	 | 23
    //     %D        | Short MM/DD/YY date, equivalent to        | 08/23/01
    //               | %m/%d/%y	                                 |
    //     %e        | Day of the month, space - padded(1 - 31)	 | 23
    //     %F        | Short YYYY-MM-DD date, equivalent to      | 2001-08-23
    //               | %Y-%m-%d	                                 |
    //     %g        | Week - based year, last two digits(00-99) | 01
    //     %G        | Week - based year                         | 2001
    //     %h        | Abbreviated month name * (same as %b)     | Aug
    //     %H        | Hour in 24h format(00 - 23)               | 14
    //     %I        | Hour in 12h format(01 - 12)               | 02
    //     %j        | Day of the year(001 - 366)                | 235
    //     %m        | Month as a decimal number(01 - 12)        | 08
    //     %M        | Minute(00 - 59)                           | 55
    //     %n        | New - line character('\n')                |
    //     %p        | AM or PM designation	                     | PM
    //     %r        | 12 - hour clock time *                    | 02:55:02 pm
    //     %R        | 24 - hour HH:MM time, equivalent to %H:%M | 14:55
    //     %S        | Second(00 - 61)                           | 02
    //     %t        | Horizontal - tab character('\t')          | 
    //     %T        | ISO 8601 time format(HH:MM:SS),equivalent | 14:55:02
    //               | to %H:%M:%S                               |
    //     %u        | ISO 8601 weekday as number with Monday    | 4
    //               | as 1 (1-7)                                |
    //     %U        | Week number with the first Sunday as the  | 33
    //               | first day of week one(00-53)              |
    //     %V        | ISO 8601 week number(01-53)               | 34
    //     %w	     | Weekday as a decimal number with Sunday   | 4
    //               | as 0 (0-6)                                |
    //     %W        | Week number with the first Monday as the  | 34
    //               | first day of week one(00-53)              |
    //     %x        | Date representation *                     | 08/23/01
    //     %X        | Time representation *                     | 14:55:02
    //     %y	     | Year, last two digits(00-99)              | 01
    //     %Y        | Year                                      | 2001
    //     %z        | ISO 8601 offset from UTC in timezone(1    | + 100
    //               | minute = 1, 1 hour = 100) If timezone     |
    //               | cannot be determined, no characters       |
    //     %Z        | Timezone name or abbreviation * If        | CDT
    //               | timezone cannot be determined, no         |
    //               | characters                                |
    //     %%        | A % sign	                                 | %
    // --------------------------------------------------------------------------------------
    //     %k        | 毫秒值
    inline const char* Fmt(const char* const cpFmt);
    // 格式化时间结构中的毫秒值
    inline void  s_millisecond(char* const       pBuf,
                         const size_t      csztBufSize,
                         const char* const cpFmt);

}; // End of class CDateTime
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CDateTime()
// Brief     : 构建函数
// Return    : void
// Parameter : null
template < size_t sztBufSize>
CDateTime<sztBufSize>::CDateTime()
{
    vMemZero(mszBuf);
    vMemZero(mstTime);
};
// End of function CDateTime()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ~CDateTime()
// Brief     : 析构函数
// Return    : void
// Parameter : null
template < size_t sztBufSize>
CDateTime<sztBufSize>::~CDateTime()
{
    
};
// End of function ~CDateTime()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CDateTime()
// Brief     : 拷贝构造函数
// Return    : void
// Parameter : const CDateTime& obj     - 拷贝对象
template <size_t sztBufSize>
CDateTime<sztBufSize>::CDateTime(const CDateTime& obj)
{
   *this = obj;
};
// End of function CDateTime(const CDateTime& obj)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CDateTime(time_t tTime)
// Brief     : 构造函数
// Return    : void
// Parameter : time_t tTime             - 赋值time_t对象
template <size_t sztBufSize>
CDateTime<sztBufSize>::CDateTime(time_t tTime) 
{
    vMemZero(mszBuf);
    vMemZero(mstTime);

    mstTime.time = tTime;
};
// End of function CDateTime(time_t tTime)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CDateTime(_timeb tTimeb)
// Brief     : 构造函数
// Return    : void
// Parameter : _timeb tTimeb            - 赋值_timeb对象
template <size_t sztBufSize>
CDateTime<sztBufSize>::CDateTime(_timeb tTimeb)
{
    vMemZero(mszBuf);
    vMemZero(mstTime);

    mstTime = tTimeb;    
};
// End of function CDateTime(_timeb tTimeb)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator =
// Parameter : const CDateTime& obj     - 赋值的对象
// Return    : CDateTime&               - 当前CDateTime对象
// Notes     : 赋值函数
template < size_t sztBufSize>
CDateTime<sztBufSize>& CDateTime<sztBufSize>::operator = (const CDateTime& obj)
{
    vMemZero(mszBuf);
    vMemZero(mstTime);

    mstTime = obj.mstTime;
    return *this;
};
// End of function operator =()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator + (const time_t tTimeDiff)
// Brief     : 加法操作
// Return    : time_t                   - 当前time_t值
// Parameter : const time_t tTimeDiff   - 需要添加时间差（单位秒）
template <size_t sztBufSize>
time_t CDateTime<sztBufSize>::operator + (const time_t tTimeDiff)
{
    // TODO [Q] : 非验证
    mstTime.time += tTimeDiff;
    return mstTime.time;
}
// End of function operator + (const time_t tTimeDiff)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator - (const time_t tTimeDiff)
// Brief     : 减法操作
// Return    : time_t                   - 当前time_t值
// Parameter : const time_t tTimeDiff   - 需要添加时间差（单位秒）
template <size_t sztBufSize>
time_t CDateTime<sztBufSize>::operator - (const time_t tTimeDiff)
{
    mstTime.time -= tTimeDiff;
    if (mstTime.time < 0)
        mstTime.time = 0;
    return mstTime.time;
};
// End of function operator - (const time_t tTimeDiff)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator == (const CDateTime& Obj)
// Brief     : == 操作
// Return    : true                     - 相等
//             false                    - 不相等
// Parameter : const CDateTime& Obj     - 需要对比的对象
template <size_t sztBufSize>
bool CDateTime<sztBufSize>::operator == (const CDateTime& Obj)
{
    // TODO [Q] : 非验证
    if (mstTime.time != Obj.mstTime.time)
        return false;

    if (mstTime.millitm != Obj.mstTime.millitm)
        return false;

    return true;
};
// End of function operator == (const CDateTime& Obj)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : != operator != (const CDateTime& Obj)
// Brief     : == 操作
// Return    : true                     - 相等
//             false                    - 不相等
// Parameter : const CDateTime& Obj     - 需要对比的对象
template <size_t sztBufSize>
bool CDateTime<sztBufSize>::operator != (const CDateTime& Obj)
{
    // TODO [Q] : 非验证
    if (0 == memcmp(&mstTime, &Obj.mstTime, sizeof(_timeb)))
        return false;

    return true;
};
// End of function operator != (const CDateTime& Obj)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator > (const CDateTime& Obj)
// Brief     :  > 操作
// Return    : true                     - 相等
//             false                    - 不相等
// Parameter : const CDateTime& Obj     - 需要对比的对象
template <size_t sztBufSize>
bool CDateTime<sztBufSize>::operator > (const CDateTime& Obj)
{
    if (mstTime.time > Obj.mstTime.time)
        return true;

    if (mstTime.millitm > Obj.mstTime.millitm)
        return true;

    return false;
};
// End of function operator > (const CDateTime& Obj)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator < (const CDateTime& Obj)
// Brief     : < 操作
// Return    : true                     - 相等
//             false                    - 不相等
// Parameter : const CDateTime& Obj     - 需要对比的对象
template <size_t sztBufSize>
bool CDateTime<sztBufSize>::operator < (const CDateTime& Obj)
{
    if (mstTime.time < Obj.mstTime.time)
        return true;

    if (mstTime.millitm < Obj.mstTime.millitm)
        return true;

    return false;
};
// End of function operator < (const CDateTime& Obj)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetCurrTime
// Parameter : null
// Return    : null
// Notes     : 获取当前时间
template < size_t sztBufSize>
inline CDateTime<sztBufSize> CDateTime<sztBufSize>::GetCurrTime()
{
    vm::CDateTime<sztBufSize> loDateTime;

#if defined (_MSC_VER) && (_MSC_VER > 1300)
    // for new version vs
    errno_t loErr = _ftime_s(&loDateTime.mstTime);
#else
    _ftime(&loDateTime.mstTime);
#endif

    return loDateTime;
};
// End of function GetCurrTime()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : time_t()
// Brief     : 获取当前对象的time_t时间结构
// Return    : void
// Parameter : null
template <size_t sztBufSize>
inline time_t& CDateTime<sztBufSize>::timet() 
{ 
    return mstTime.time; 
}
// End of function 
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : timeb()
// Brief     : 获取当前对象的_timeb时间结构
// Return    : void
// Parameter : null
template <size_t sztBufSize>
inline _timeb& CDateTime<sztBufSize>::timeb() 
{ 
    return mstTime; 
};
// End of function timeb()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : millitm()
// Brief     : 获取当前对象的毫秒数
// Return    : void
// Parameter : null
template <size_t sztBufSize>
inline unsigned short CDateTime<sztBufSize>::millitm()
{ 
    return mstTime.millitm; 
};
// End of function millitm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : SetTimeFmFull(const char* szFmtStr)
// Brief     : 根据格式化字符串（YYYY/MM/DD HH:MM:SS.MS）解析Time对象
// Return    : void
// Parameter : const char* szFmtStr         - 格式化的字符串
template <size_t sztBufSize>
inline void CDateTime<sztBufSize>::SetTimeFmFull(const void* szFmtStr)
{
    unsigned int    luiYear     = 0;
    unsigned int    luiMonth    = 0;
    unsigned int    luiDay      = 0;
    unsigned int    luiHour     = 0;
    unsigned int    luiMin      = 0;
    unsigned int    luiSec      = 0;
    unsigned short  lusMill     = 0;


#if defined (_MSC_VER)&&(_MSC_VER>=1300)
    sscanf_s(szFmtStr, "%u/%u/%u %u:%u:%u.%u",
        &luiYear, &luiMonth, &luiDay,
        &luiHour, &luiMin, &luiSec, &lusMill);
#else
    sscanf(szFmtStr, "%u/%u/%u %u:%u:%u.%u",
        &luiYear, &luiMonth, &luiDay,
        &luiHour, &luiMin, &luiSec &lusMill);
#endif

    SetTime(luiYear, luiMonth, luiDay, luiHour, luiMin, luiSec);
};
// End of function SetTimeFmFull(const char* szFmtStr)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : SetTime( ... )
// Brief     : 设置时间对象
// Return    : void
// Parameter : unsigned int   uiHour        - 小时值
//             unsigned int   uiMin         - 分钟值
//             unsigned int   uiSec         - 秒值
//             unsigned short usMill        - 毫秒值
template <size_t sztBufSize>
inline void CDateTime<sztBufSize>::SetTime( unsigned int   uiHour, unsigned int   uiMin,
                                            unsigned int   uiSec,  unsigned short usMill )
{
    tm* lpTm = NULL;
#if defined (_MSC_VER)&&(_MSC_VER<=1300)
    lpTm = localtime(&mTime.time);
#else
    errno_t er = localtime_s(lpTm, &mstTime.time);
#endif
    lpTm->tm_hour = uiHour;
    lpTm->tm_min = uiMin;
    lpTm->tm_sec = uiSec;


    mstTime.time = mktime(lpTm);
    mstTime.millitm = usMill;

};
// End of function SetTime( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : SetTime( ... )
// Brief     : 设置时间对象
// Return    : void
// Parameter : unsigned int  uiYear            - 年（需大于1900）
//             unsigned int  uiMonth           - 月（需小于等于12）
//             unsigned int  uiDay             - 日（需小于等于31）
//             unsigned int  uiHour            - 时（需小于等于24）
//             unsigned int  uiMin             - 分（需小于等于60）
//             unsigned int  uiSec             - 秒（需小于等于60）
//             unsigned short usMill           - 毫秒（需小于等于999）
template <size_t sztBufSize>
inline void CDateTime<sztBufSize>::SetTime( unsigned int  uiYear, unsigned int  uiMonth, unsigned int  uiDay,
                                            unsigned int  uiHour, unsigned int  uiMin, unsigned int  uiSec,
                                            unsigned short usMill )
{
    tm* lpTm = NULL;
#if defined (_MSC_VER)&&(_MSC_VER<=1300)
    lpTm = localtime(&mTime.time);
#else
    errno_t er = localtime_s(lpTm, &mstTime.time);
#endif
    lpTm->tm_year = uiYear - 1900;
    lpTm->tm_mon = uiMonth - 1;
    lpTm->tm_mday = uiDay;
    lpTm->tm_hour = uiHour;
    lpTm->tm_min = uiMin;
    lpTm->tm_sec = uiSec;


    mstTime.time = mktime(lpTm);
    mstTime.millitm = usMill;

};
// End of function SetTime( ... )
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Fmt(...)
// Brief     : 格式化输出时间
// Return    : char*                            - 格式化后的字符串
// Parameter : const char* szFormat             - 字符串格式
// Note      :
//     ==================================================================================
//     specifier | Replaced by                               | Example
//     ----------------------------------------------------------------------------------
//     %a	     | Abbreviated weekday name *	             | Thu
//     %A	     | Full weekday name *	                     | Thursday
//     %b	     | Abbreviated month name *	                 | Aug
//     %B	     | Full month name *                         | August
//     %c	     | Date and time representation *	         | Thu Aug 23 14:55:02 2001
//     %C	     | Year divided by 100 and truncated to      | 20
//               | integer(00 - 99)                          |
//     %d        | Day of the month, zero - padded(01 - 31)	 | 23
//     %D        | Short MM/DD/YY date, equivalent to        | 08/23/01
//               | %m/%d/%y	                                 |
//     %e        | Day of the month, space - padded(1 - 31)	 | 23
//     %F        | Short YYYY-MM-DD date, equivalent to      | 2001-08-23
//               | %Y-%m-%d	                                 |
//     %g        | Week - based year, last two digits(00-99) | 01
//     %G        | Week - based year                         | 2001
//     %h        | Abbreviated month name * (same as %b)     | Aug
//     %H        | Hour in 24h format(00 - 23)               | 14
//     %I        | Hour in 12h format(01 - 12)               | 02
//     %j        | Day of the year(001 - 366)                | 235
//     %m        | Month as a decimal number(01 - 12)        | 08
//     %M        | Minute(00 - 59)                           | 55
//     %n        | New - line character('\n')                |
//     %p        | AM or PM designation	                     | PM
//     %r        | 12 - hour clock time *                    | 02:55:02 pm
//     %R        | 24 - hour HH:MM time, equivalent to %H:%M | 14:55
//     %S        | Second(00 - 61)                           | 02
//     %t        | Horizontal - tab character('\t')          | 
//     %T        | ISO 8601 time format(HH:MM:SS),equivalent | 14:55:02
//               | to %H:%M:%S                               |
//     %u        | ISO 8601 weekday as number with Monday    | 4
//               | as 1 (1-7)                                |
//     %U        | Week number with the first Sunday as the  | 33
//               | first day of week one(00-53)              |
//     %V        | ISO 8601 week number(01-53)               | 34
//     %w	     | Weekday as a decimal number with Sunday   | 4
//               | as 0 (0-6)                                |
//     %W        | Week number with the first Monday as the  | 34
//               | first day of week one(00-53)              |
//     %x        | Date representation *                     | 08/23/01
//     %X        | Time representation *                     | 14:55:02
//     %y	     | Year, last two digits(00-99)              | 01
//     %Y        | Year                                      | 2001
//     %z        | ISO 8601 offset from UTC in timezone(1    | + 100
//               | minute = 1, 1 hour = 100) If timezone     |
//               | cannot be determined, no characters       |
//     %Z        | Timezone name or abbreviation * If        | CDT
//               | timezone cannot be determined, no         |
//               | characters                                |
//     %%        | A % sign	                                 | %
// --------------------------------------------------------------------------------------
//     %k        | 毫秒值
template <size_t sztBufSize>
inline const char* CDateTime<sztBufSize>::Fmt(const char* const cpFmt)
{
    // 将格式化字符串中“%Mill”替换为毫秒值字符串
    char lszBuf[_V_CDATETIME_MAX_BUF_] = {0}; 
    s_millisecond( lszBuf, sizeof(lszBuf), cpFmt );


    // 格式化字符串中其他标识符
    memset(&mszBuf, 0x00, sztBufSize);
#if defined ( _MSC_VER ) && ( _MSC_VER >=1200 )
    struct tm loTm;
    errno_t loErr = localtime_s(&loTm, &mstTime.time);
    strftime(mszBuf, sztBufSize, lszBuf, &loTm);
#else
    struct tm* lpTm = localtime(&mstTime.time);
    strftime(mszBuf, sztBufSize, lszBuf, lpTm);
#endif

    return mszBuf;
};
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

template <size_t sztBufSize>
inline void  CDateTime<sztBufSize>::s_millisecond( char* const       pBuf,
                                                   const size_t      csztBufSize, 
                                                   const char* const cpFmt )
{
    CMemPtr loBuf(pBuf, csztBufSize);
    size_t  lsztBufOffset = 0;
    CStrPtr loFmt(const_cast<char*>(cpFmt), strlen(cpFmt));
    size_t  lsztFmtOffset = 0;
    
    // 将cpFmt指向字符串中的“%K”字符串替换为时间毫秒值
    const tChar* lpFlags = vT("%K");
    vm::CAny<128> loMillim(mstTime.millitm);
    vm::CParser::CPattern   loPattern( lpFlags, vStrLen(lpFlags), loMillim.s_ushort(), loMillim.len() );

    vm::CParser             loParser('%', cpFmt, vStrLen(cpFmt));
    loParser.Regist( loPattern );
    loParser.Parse(pBuf,csztBufSize);
}

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrDay1()
// Brief     : 获取时间字符串，格式"YYYY/MM/DD"
// Return    : char*                            - 格式化后的字符串
// Parameter : null
template <size_t sztBufSize>
const char* CDateTime<sztBufSize>::ToStrDay1()
{
    return Fmt("%Y/%m/%d");
}
// End of function ToStrDay1()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrDay2()
// Brief     : 获取时间字符串，格式"YYMMDD"
// Return    : char*                            - 格式化后的字符串
// Parameter : null
template <size_t sztBufSize>
inline const char* CDateTime<sztBufSize>::ToStrDay2()
{
    return Fmt("%y%m%d");
}
// End of function ToStrDay2()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrTime()
// Brief     : 获取时间字符串，格式"HH:MM:SS"
// Return    : char*                            - 格式化后的字符串
// Parameter : null
template <size_t sztBufSize>
inline const char* CDateTime<sztBufSize>::ToStrTime()
{
    return Fmt("%H:%M:%S");
}
// End of function ToStrTime()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrMillitm()
// Brief     : 获取时间字符串，格式"%Mill"
// Return    : char*                            - 格式化后的字符串
// Parameter : null
template <size_t sztBufSize>
inline const char* CDateTime<sztBufSize>::ToStrMillitm()
{
    memset(&mszBuf, 0x00, sztBufSize);
    v_sprintf( mszBuf, sztBufSize, "%03d", mstTime.millitm );
    return mszBuf;
}
// End of function ToStrMillitm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrFull()
// Brief     : 获取时间字符串，格式""%Y/%m/%d %H:%M:%S:%Mill"
// Return    : char*                            - 格式化后的字符串
// Parameter : null
template <size_t sztBufSize>
inline const char* CDateTime<sztBufSize>::ToStrFull()
{
    memset(&mszBuf, 0x00, sztBufSize);
    char lszBuf[sztBufSize] = { 0 };

#if defined ( _MSC_VER ) && ( _MSC_VER >=1200 )
    struct tm loTm;
    errno_t er = localtime_s(&loTm, &mstTime.time);
    strftime(lszBuf, sztBufSize, "%Y-%m-%d %H:%M:%S", &loTm);
    sprintf_s(mszBuf, sztBufSize, "%s.%03d", lszBuf, mstTime.millitm);
#else
    struct tm* lpTm = NULL;
    lpTm = localtime(&mstTime.time);
    strftime(lszBuf, sztBufSize, "%Y-%m-%d %H:%M:%S", lpTm);
    sprintf(mszBuf, "%s.%03d", lszBuf, mstTime.millitm);
#endif

    return mszBuf;
}
// End of function ToStrFull()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CDATETIME_HPP__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CDateTime.h
/////////////////////////////////////////////////////////////////////////////////////////
