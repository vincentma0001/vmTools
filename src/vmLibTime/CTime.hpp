/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CTime.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/18 18:45:25
// Modify time  : 2020/01/18 18:45:25
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

#ifndef __CTIME_H__
#define __CTIME_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#ifndef   _INC_STDLIB
#    include <stdlib.h>
#endif // _INC_STDLIB

#ifndef   _USE_TIMEB_
#   define  _USE_TIMEB_
#   include <sys/timeb.h>
#endif // _USE_TIMEB_H_

#ifndef   _INC_TIME
#   include <time.h>
#endif // _INC_TIME

// Config files included
#include <vmCfg.h>
#include <vmCfg/vmCfgTime.h>

// Platform files included

// Used files included
#ifndef   __VM_UTIL_H__
#   include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

//#ifndef   __CMEMPTR_H__
//#   include <vmLibBase/CMemPtr.h>
//#endif // __CMEMPTR_H__

//#ifndef   __CSTRPTR_H__
//#   include <vmLibBase/CStrPtr.h>
//#endif // __CSTRPTR_H__

#ifndef   __CANY_HPP__
#   include <vmLibBase/CAny.hpp>
#endif // __CANY_HPP__

#ifndef   __CPARSER_H__
#    include <vmLibBase/CParser.h>
#endif // __CPARSER_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{


/////////////////////////////////////////////////////////////////////////////////////////
//
// class CTime : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template< size_t sztBufSize >
class CTime
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CTime():mszBuf{0x00}{ vMemZero(mstTimeb); };
    explicit CTime( tTimeb stTimeb ):mstTimeb(stTimeb),mszBuf{0x00}{};
    explicit CTime( tTimet stTimet ):mszBuf{0x00}
    { 
        vMemZero(mstTimeb);
        bool lbRet = CTime::ftime(mstTimeb);
        if (lbRet == false)
        {
            mulErrCode == GetLastError();
            return;
        }

        mstTimeb.time       =stTimet; 
        mstTimeb.millitm    =0;
    };
    explicit CTime( unsigned long long ullMillieSeconds ):mstTimeb(0),mszBuf{0x00}
    {
        vMemZero(mstTimeb);
        bool lbRet = CTime::ftime( mstTimeb );
        if( lbRet == false )
        {
            mulErrCode == GetLastError();
            return;
        }

        MstoTimeb( ullMillieSeconds, mstTimeb );
    };
    // Destruct define
    virtual ~CTime(){};
    
public:
    // Copy construct define 
    CTime(const CTime& obj)
    {
        *this = obj;
    };
    // Assignment define 
    CTime& operator = ( const CTime& obj )
    {
        mstTimeb = obj.mstTimeb;
    };

/////////////////////////////////////////////////////////////////////////////////////////
public:
    // 加法操作
    inline CTime&      operator +  (const CTime& coTime)
    {
        long long lllMillieSeconds = toMillieSecondes() + coTime.toMillieSecondes();
        CTime::MstoTimeb(lllMillieSeconds, mstTimeb);
        return *this;
    };
    inline CTime&      operator +  (const unsigned short cusMillitm)
    {
        long long lllMillieSeconds = toMillieSecondes()+cusMillitm;
        CTime::MstoTimeb( lllMillieSeconds, mstTimeb );
        return *this;
    };
    inline CTime&      operator +  (const time_t ctTimeDiff)
    {
        mstTimeb.time += ctTimeDiff;
        return *this;
    };
    inline CTime&      operator +  (const vTime::CMinutes coMinutes)
    {
        mstTimeb.time += coMinutes.toSeconds();
        return *this;
    };
    inline CTime&      operator +  (const vTime::CHours coHours)
    {
        mstTimeb.time += coHours.toSeconds();
        return *this;
    };
    inline CTime&      operator +  (const vTime::CDays coDays)
    {
        mstTimeb.time += coDays.toSeconds();
        return *this;
    };
    // += 操作
    inline CTime&      operator +=  (const CTime& coTime)
    {
        long long lllMillieSeconds = toMillieSecondes() + coTime.toMillieSecondes();
        CTime::MstoTimeb(lllMillieSeconds, mstTimeb);
        return *this;
    };

    inline CTime&      operator +=  (const unsigned short cusMillitm)
    {
        long long lllMillieSeconds = toMillieSecondes() + cusMillitm;
        CTime::MstoTimeb(lllMillieSeconds, mstTimeb);
        return *this;
    };
    ;
    inline CTime&      operator +=  (const time_t ctTimeDiff)
    {
        mstTimeb.time += ctTimeDiff;
        return *this;
    };
    inline CTime&      operator +=  (const vTime::CMinutes coMinutes)
    {
        mstTimeb.time += coMinutes.toSeconds();
        return *this;
    };
    inline CTime&      operator +=  (const vTime::CHours coHours)
    {
        mstTimeb.time += coHours.toSeconds();
        return *this;
    };
    inline CTime&      operator +=  (const vTime::CDays coDays)
    {
        mstTimeb.time += coDays.toSeconds();
        return *this;
    };

    // 减法操作
    inline CTime&      operator -  (const CTime& coTime)
    {
        long long lllMillieSeconds = toMillieSecondes() - coTime.toMillieSecondes();
        CTime::MstoTimeb(lllMillieSeconds, mstTimeb);
        return *this;
    };

    inline CTime&      operator -  (const unsigned short cusMillitm)
    {
        long long lllMillieSeconds = toMillieSecondes() - cusMillitm;
        CTime::MstoTimeb(lllMillieSeconds, mstTimeb);
        return *this;
    };
    inline CTime&      operator -  (const time_t ctTimeDiff)
    {
        mstTimeb.time -= ctTimeDiff;
        return *this;
    };
    inline CTime&      operator -  (const vTime::CMinutes coMinutes)
    {
        mstTimeb.time -= coMinutes.toSeconds();
        return *this;
    };
    inline CTime&      operator -  (const vTime::CHours coHours)
    {
        mstTimeb.time -= coHours.toSeconds();
        return *this;
    };
    inline CTime&      operator -  (const vTime::CDays coDays)
    {
        mstTimeb.time -= coDays.toSeconds();
        return *this;
    };
    // -= 操作
    inline CTime&      operator -=  (const CTime& coTime)
    {
        long long lllMillieSeconds = toMillieSecondes() - coTime.toMillieSecondes();
        CTime::MstoTimeb(lllMillieSeconds, mstTimeb);
        return *this;
    };

    inline CTime&      operator -=  (const unsigned short cusMillitm)
    {
        long long lllMillieSeconds = toMillieSecondes() - cusMillitm;
        CTime::MstoTimeb(lllMillieSeconds, mstTimeb);
        return *this;
    };
    inline CTime&      operator -=  (const time_t ctTimeDiff)
    {
        mstTimeb.time -= ctTimeDiff;
        return *this;
    };
    inline CTime&      operator -=  (const vTime::CMinutes coMinutes)
    {
        mstTimeb.time -= coMinutes.toSeconds();
        return *this;
    };
    inline CTime&      operator -=  (const vTime::CHours coHours)
    {
        mstTimeb.time -= coHours.toSeconds();
        return *this;
    };
    inline CTime&      operator -=  (const vTime::CDays coDays)
    {
        mstTimeb.time -= coDays.toSeconds();
        return *this;
    };

    // == 操作
    inline bool        operator == (const CTime& Obj)
    {
        long long lllTimeMillieSecondes1 =     toMillieSecondes();
        long long lllTimeMillieSecondes2 = Obj.toMillieSecondes();

        return lllTimeMillieSecondes1==lllTimeMillieSecondes2?true:false;
    };
    // != 操作
    inline bool        operator != (const CTime& Obj)
    {
        long long lllTimeMillieSecondes1 =     toMillieSecondes();
        long long lllTimeMillieSecondes2 = Obj.toMillieSecondes();

        return lllTimeMillieSecondes1 != lllTimeMillieSecondes2 ? true : false;
    };
    // > 操作
    inline bool        operator >  (const CTime& Obj)
    {
        long long lllTimeMillieSecondes1 =     toMillieSecondes();
        long long lllTimeMillieSecondes2 = Obj.toMillieSecondes();

        return lllTimeMillieSecondes1 > lllTimeMillieSecondes2 ? true : false;
    };

    // < 操作
    inline bool        operator <  (const CTime& Obj)
    {
        long long lllTimeMillieSecondes1 =     toMillieSecondes();
        long long lllTimeMillieSecondes2 = Obj.toMillieSecondes();

        return lllTimeMillieSecondes1 < lllTimeMillieSecondes2 ? true : false;
    };
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    // 时间存储结构， 如果定义_USE_32BIT_TIME_T宏使用32bit版本，否则使用64bit版本
    tTimeb  mstTimeb;
    // 数据缓存，用于存储时间字符串
    tchar   mszBuf[ sztBufSize ];

/////////////////////////////////////////////////////////////////////////////////////////
// Error infomation :
private:
    // 错误信息
    unsigned long  mulErrCode;

public:
    // 判断是否有错误发生
    bool HasError(){ return mulErrCode==0?false:true; }
    // 返回错误代码
    unsigned long toErrCode(){ return mulErrCode; };

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    inline CTime&               Now()
    {
#if defined (_MSC_VER) && (_MSC_VER > 1300)
        // for new version vs
        errno_t loErr = _ftime_s(&mstTimeb);
        // #  TODO : Add condition brief here ##
        if ( loErr != 0 )
        {
        	mulErrCode = loErr;
        } 
        // End of if ( loErr == o ) ...
#else
        _ftime(&mstTimeb);
#endif
        return *this;

    };
    // 获取当前对象的time_t时间结构
    inline tTimeb&              toTimeb()   { return mstTimeb;         };
    inline tTimet&              toTimet()   { return mstTimeb.time;    };
    inline unsigned short&      toMillitm() { return mstTimeb.millitm; };

    // 获取从1970-1-1 08:00:00开始的时间
    inline long long  toDays()           { return (long long)(toSecondes()/vSecondOfaDay);              };
    inline long long  toHours()          { return (long long)(toSecondes()/vSecondOfaHour);             };
    inline long long  toMinutes()        { return (long long)(toSecondes()/vSecondOfaMinutes);          };
    inline long long  toSecondes()       { return (long long)(mstTimeb.time);                           };
    inline long long  toMillieSecondes() { return (long long)((mstTimeb.time*1000) + mstTimeb.millitm); };

    // After/before
    bool isAfter ( const CTime& oTime ){ return oTime<(*this); }
    bool isBefore( const CTime& oTime ){ return oTime>(*this); }

    inline bool GetTimeForStr_Y4_MM_DD_hh$mm$ss$ms( const tchar* const cpTimeStr )
    {}

    // 设置时间对象
    inline bool SetTime(unsigned int   uiHour, unsigned int   uiMin,
                        unsigned int    uiSec, unsigned short usMill = 0)
    {
    };
    // 设置时间对象
    inline bool SetTime(unsigned int   uiYear, unsigned int uiMonth, unsigned int  uiDay,
                        unsigned int   uiHour, unsigned int   uiMin, unsigned int  uiSec,
                        unsigned short usMill = 0)
    {
    };

public:
    inline static CTime GetNow()
    {
        tTimeb  lstTime;
#if defined (_MSC_VER) && (_MSC_VER > 1300)
        // for new version vs
        errno_t loErr = _ftime_s(&lstTime);
#else
        _ftime(&lstTime);
#endif
        return CTime(lstTime);
    }

    inline static unsigned long TimetToTm( const tTimet& stTime, tm& stTm )
    {
#if defined (_MSC_VER) && (_MSC_VER > 1300)
            // for new version vs
            errno_t loErr = localtime_s( &stTm, &lstTime);
            if ( loErr != 0)
                return loErr;
#else
            _ftime(&lstTime);
#endif

            return emRet::emSucceed;
    }
    inline static bool TmToTimet( const tm& stTm, tTimet& stTimet )
    {
        stTimet = mktime( &stTm );
        // #  TODO : Add condition brief here ##
        if (stTimet == -1)
        {
        	return false;
        } 
        // End of if (stTimet == -1) ...

        return true;

    }

    inline static bool GetCurrYear( tchar* const pYearBuf, const size_t csztYearBufSize, const size_t csztYearLen=4 )
    {
        tTimeb  lstTime;
#if defined (_MSC_VER) && (_MSC_VER > 1300)
        // for new version vs
        errno_t loErr = _ftime_s(&lstTime);
        if ( loErr != 0 )
            return false;
#else
        _ftime(&lstTime);
#endif
        v_strncpy( mszBuf, sizeof(mszBuf), CTime(lstTime).toTimeStr( vT("%Y") ), csztYearLen );
        return true;
    }


    static void SleepSeconds( long long llSecondes ){ ::Sleep( llSecondes*1000 ); }
    static void SleepMillieSeconds( long long llMillieSeconds ){ ::Sleep( llMillieSeconds ); }

private:
    static void MstoTimeb( const long long llMillieSeconds, tTimeb& stTimeb )
    {
        tTimeDiv_t lDiv = vTimeDiv(llMillieSeconds, 1000);
        stTimeb.time    = lDiv.quot;
        stTimeb.millitm = lDiv.rem;
    }
    static bool ftime( tTimeb stTimeb )
    {
#if defined(_MSC_VER) && (_MSC_VER>1200)
        errno_t loRet = _ftime_s( &stTimeb);
        if ( loRet !=0 )
            return false;        	
#else
        _ftime( &stTimeb);
#endif
        return true;
    };

public:
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
    inline const tchar* toTimeStr(const tchar* const cpFmt)
    {
        // 格式化字符串中其他标识符
        memset(&mszBuf, 0x00, sztBufSize);
#if defined ( _MSC_VER ) && ( _MSC_VER >=1200 )
        struct tm loTm;
        errno_t loErr = localtime_s(&loTm, &mstTimeb.time);
        if(loErr != 0)
        {
            mulErrCode = loErr;
            return nullptr;
        }

        vStrftime((tchar*)mszBuf, sztBufSize, cpFmt, &loTm);
#else
        struct tm* lpTm = localtime(&mstTime.time);
        vStrftime(mszBuf, sztBufSize, cpFmt, lpTm);
#endif

        return (tchar*)mszBuf;
    };

    // 格式化格式化结构
    // FMT : 
    //      %Y4  (Year                           e.g.                     2009)  = %Y
    //      %Y2  (Year, last two digits          e.g.                    00-99)  = %y
    //      %MM  (Month as a decimal number      e.g.                    01-12)  = %m
    //      %DD  (Day of month, zero padded      e.g,                    01-31)  = %d
    //      %dd  (Day of month, space padded     e.g,                     1-31)  = %e
    //      %hh  (Hour in 24h                    e.g.                    01-24)  = %H
    //      %ii  (Hour in 12h                    e.g.                    01-12)  = %I
    //      %mm  (Minute                         e.g.                    00-59)  = %M
    //      %ss  (Second                         e.g.                    00-61)  = %S
    //      %ms  (millisecond                    e.g.                  000-999)
    //      %WY  (Week based year                e.g.                    00-99)  = %g
    //      %WW  (ISO 8601 weekday as number with Monday          e.g.     1-7)  = %u
    //      %ww  (Weekday as a decimal number with Sunday as 0    e.g.     0-6)  = %w
    //      %WN  (ISO 8601 week number           e.g.                    00-53)  = %V
    //      %WS  (Week number with the first Sunday as the first day of week one  e.g. 00-53 ) = %U
    //      %WM  (Week number with the first Monday as the first day of week one  e.g. 00-53 ) = %W
    //      %DY  (Day of the year                e.g.                  001-366)  = %j
    //      %AP  (AM or PM designation           e.g.                 AM or PM)  = %p
    //      %AM  (Abbreviated month              e.g.                   August)  = %B
    //      %am  (Abbreviated month              e.g.                      Aug)  = %b
    //      %AW  (Abbreviated weekday            e.g.                   Friday)  = %A
    //      %aw  (Abbreviated weekday            e.g.                      Fri)  = %a
    //      %CD  (date and time representation   e.g. Thu Aug 23 14:55:02 2001)  = %c
    //      %SD  (Short MM/DD/YY date            e.g.                 08/23/01)  = %D
    //      %sd  (Short YY/MM/DD date            e.g.                 01/08/23)  = %y/%m/%d
    //      %FD  (Short YYYY-MM-DD date          e.g.               2001-08-23)  = %F
    //      %fd  (Short MM-DD-YYYY date          e.g.               08-23-2001)  = %m-%d-%Y
    //      %RT  (24 - hour HH:MM time           e.g.                    14:55)  = %R
    //      %rt  (12 - hour clock time           e.g.              02:55:02 pm)  = %r
    //      %TT  (ISO 8601 time format           e.g.                 14:55:02)  = %T
    //      %tt  (ISO 8601 time format 12 hour   e.g.                 02:55:02)  = %I:%M:%S
    //      %TZ  (Timezone name                  e.g.                      CDT)  = %Z
    //      %ZZ  (ISO 8601 offset from UTC in timezone(1 minute = 1,             = %z
    //            1 hour = 100) If timezone cannot be determined, 
    //            no characters)
    //      %n   (New        - line character('\n')  
    //      %t   (Horizontal - tab  character('\t')  
    //      %%   ( A % sign	- %
    inline const tchar* Fmt(const tchar* const cpFmt)
    {
        // 初始化缓存区数据
        vm::CParser loParser(vT('%'), cpFmt);
        //      %Y4  (Year                           e.g.                     2009)  = %Y
        vm::CParser::CPattern loPatternDTForY4(vT("%Y4"), vT("%Y"));
        loParser.Regist(loPatternDTForY4);
        //      %Y2  (Year, last two digits          e.g.                    00-99)  = %y
        vm::CParser::CPattern loPatternDTForY2(vT("%Y2"), vT("%y"));
        loParser.Regist(loPatternDTForY2);
        //      %MM  (Month as a decimal number      e.g.                    01-12)  = %m
        vm::CParser::CPattern loPatternDTForMM(vT("%MM"), vT("%m"));
        loParser.Regist(loPatternDTForMM);
        //      %DD  (Day of month, zero padded      e.g,                    01-31)  = %d
        vm::CParser::CPattern loPatternDTForDD(vT("%DD"), vT("%d"));
        loParser.Regist(loPatternDTForDD);
        //      %dd  (Day of month, space padded     e.g,                     1-31)  = %e
        vm::CParser::CPattern loPatternDTFordd(vT("%dd"), vT("%e"));
        loParser.Regist(loPatternDTFordd);
        //      %hh  (Hour in 24h                    e.g.                    01-24)  = %H
        vm::CParser::CPattern loPatternDTForhh(vT("%hh"), vT("%H"));
        loParser.Regist(loPatternDTForhh);
        //      %II  (Hour in 12h                    e.g.                    01-12)  = %I
        vm::CParser::CPattern loPatternDTForII(vT("%ii"), vT("%I"));
        loParser.Regist(loPatternDTForII);
        //      %mm  (Minute                         e.g.                    00-59)  = %M
        vm::CParser::CPattern loPatternDTFormm(vT("%mm"), vT("%M"));
        loParser.Regist(loPatternDTFormm);
        //      %ss  (Second                         e.g.                    00-61)  = %S
        vm::CParser::CPattern loPatternDTForss(vT("%ss"), vT("%S"));
        loParser.Regist(loPatternDTForss);
        //      %ms  (millisecond                    e.g.                  000-999)
        unsigned short lusMillitm = mstTimeb.millitm;
        vm::CAny<128> loMillitm(lusMillitm);
        vm::CParser::CPattern loPatternDTForms(vT("%ms"), loMillitm.s_ushort());
        loParser.Regist(loPatternDTForms);
        //      %WY  (Week based year                e.g.                    00-99)  = %g
        vm::CParser::CPattern loPatternDTForWY(vT("%WY"), vT("%g"));
        loParser.Regist(loPatternDTForWY);
        //      %WW  (ISO 8601 weekday as number with Monday          e.g.     1-7)  = %u
        vm::CParser::CPattern loPatternDTForWW(vT("%WW"), vT("%u"));
        loParser.Regist(loPatternDTForWW);
        //      %ww  (Weekday as a decimal number with Sunday as 0    e.g.     0-6)  = %w
        vm::CParser::CPattern loPatternDTForww(vT("%ww"), vT("%w"));
        loParser.Regist(loPatternDTForww);
        //      %WN  (ISO 8601 week number           e.g.                    00-53)  = %V
        vm::CParser::CPattern loPatternDTForWN(vT("%WN"), vT("%V"));
        loParser.Regist(loPatternDTForWN);
        //      %WS  (Week number with the first Sunday as the first day of week one  e.g. 00-53 ) = %U
        vm::CParser::CPattern loPatternDTForWS(vT("%WS"), vT("%U"));
        loParser.Regist(loPatternDTForWS);
        //      %WM  (Week number with the first Monday as the first day of week one  e.g. 00-53 ) = %W
        vm::CParser::CPattern loPatternDTForWM(vT("%WM"), vT("%W"));
        loParser.Regist(loPatternDTForWM);
        //      %DY  (Day of the year                e.g.                  001-366)  = %j
        vm::CParser::CPattern loPatternDTForDY(vT("%DY"), vT("%j"));
        loParser.Regist(loPatternDTForDY);
        //      %AP  (AM or PM designation           e.g.                 AM or PM)  = %p
        vm::CParser::CPattern loPatternDTForAP(vT("%AP"), vT("%p"));
        loParser.Regist(loPatternDTForAP);
        //      %AM  (Abbreviated month              e.g.                   August)  = %B
        vm::CParser::CPattern loPatternDTForAM(vT("%AM"), vT("%B"));
        loParser.Regist(loPatternDTForAM);
        //      %am  (Abbreviated month              e.g.                      Aug)  = %b
        vm::CParser::CPattern loPatternDTForam(vT("%am"), vT("%b"));
        loParser.Regist(loPatternDTForam);
        //      %AW  (Abbreviated weekday            e.g.                   Friday)  = %A
        vm::CParser::CPattern loPatternDTForAW(vT("%AW"), vT("%A"));
        loParser.Regist(loPatternDTForAW);
        //      %aw  (Abbreviated weekday            e.g.                      Fri)  = %a
        vm::CParser::CPattern loPatternDTForaw(vT("%aw"), vT("%a"));
        loParser.Regist(loPatternDTForaw);
        //      %CD  (date and time representation   e.g. Thu Aug 23 14:55:02 2001)  = %c
        vm::CParser::CPattern loPatternDTForCD(vT("%CD"), vT("%c"));
        loParser.Regist(loPatternDTForCD);
        //      %SD  (Short MM/DD/YY date            e.g.                 08/23/01)  = %D
        vm::CParser::CPattern loPatternDTForSD(vT("%SD"), vT("%D"));
        loParser.Regist(loPatternDTForSD);
        //      %sd  (Short YY/MM/DD date            e.g.                 01/08/23)  = %y/%m/%d
        vm::CParser::CPattern loPatternDTForsd(vT("%sd"), vT("%y/%m/%d"));
        loParser.Regist(loPatternDTForsd);
        //      %FD  (Short YYYY-MM-DD date          e.g.               2001-08-23)  = %F
        vm::CParser::CPattern loPatternDTForFD(vT("%FD"), vT("%F"));
        loParser.Regist(loPatternDTForFD);
        //      %fd  (Short YYYY-MM-DD date          e.g.               08-23-2001)  = %m-%d-%Y
        vm::CParser::CPattern loPatternDTForfd(vT("%fd"), vT("%m-%d-%Y"));
        loParser.Regist(loPatternDTForfd);
        //      %RT  (24 - hour HH:MM time           e.g.                    14:55)  = %R
        vm::CParser::CPattern loPatternDTForRT(vT("%RT"), vT("%R"));
        loParser.Regist(loPatternDTForRT);
        //      %rt  (12 - hour clock time           e.g.              02:55:02 pm)  = %r
        vm::CParser::CPattern loPatternDTForrt(vT("%rt"), vT("%r"));
        loParser.Regist(loPatternDTForrt);
        //      %TT  (ISO 8601 time format           e.g.                 14:55:02)  = %T
        vm::CParser::CPattern loPatternDTForTT(vT("%TT"), vT("%T"));
        loParser.Regist(loPatternDTForTT);
        //      %tt  (ISO 8601 time format 12 hour   e.g.                 02:55:02)  = %I:%M:%S
        vm::CParser::CPattern loPatternDTFortt(vT("%tt"), vT("%I:%M:%S"));
        loParser.Regist(loPatternDTFortt);
        //      %TZ  (Timezone name                  e.g.                      CDT)  = %Z
        vm::CParser::CPattern loPatternDTForTZ(vT("%TZ"), vT("%Z"));
        loParser.Regist(loPatternDTForTZ);
        //      %ZZ  (ISO 8601 offset from UTC in timezone(1 minute = 1,             = %z
        //            1 hour = 100) If timezone cannot be determined, 
        //            no characters)
        vm::CParser::CPattern loPatternDTForZZ(vT("%ZZ"), vT("%z"));
        loParser.Regist(loPatternDTForZZ);

        tchar lszNewFmt[sztBufSize] = { 0x00 };
        loParser.Parse(lszNewFmt, sizeof(lszNewFmt));

        const tchar* lpTimeStr = toTimeStr(lszNewFmt);
        return lpTimeStr;
    };


}; // End of class CTime
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CTIME_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTime.h
/////////////////////////////////////////////////////////////////////////////////////////