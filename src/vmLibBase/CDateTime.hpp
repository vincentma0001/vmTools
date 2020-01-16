/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CDateTime.hpp
// Version      : 1.0.0.0
// Brief        : ���������һϵ�й���ʱ������ĺ���
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
// class CDateTime : ���������һϵ�й���ʱ������ĺ���
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
    // ��ֵ����
    inline CDateTime&  operator =  ( const CDateTime& obj );
    // �ӷ�����
    inline time_t      operator +  ( const time_t tTimeDiff );
    // ��������
    inline time_t      operator -  ( const time_t tTimeDiff);
    // == ����
    inline bool        operator == ( const CDateTime& Obj );
    // != ����
    inline bool        operator != ( const CDateTime& Obj );
    // > ����
    inline bool        operator >  ( const CDateTime& Obj );
    // < ����
    inline bool        operator <  ( const CDateTime& Obj );
   
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
	// ʱ��洢�ṹ�� �������_USE_32BIT_TIME_T��ʹ��32bit�汾������ʹ��64bit�汾
	_timeb  mstTime;
    // ���ݻ��棬���ڴ洢ʱ���ַ���
    tChar    mszBuf[sztBufSize];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // ��ȡ��ǰʱ��
	inline static CDateTime GetCurrTime();
    // ��ȡ��ǰ�����time_tʱ��ṹ
    inline time_t& timet();
    inline _timeb& timeb();
    // ��ȡ��ǰ����ĺ�����
    inline unsigned short millitm();

    // ����ʱ�����
    inline void SetTime( unsigned int   uiHour,  unsigned int   uiMin,
                         unsigned int    uiSec,  unsigned short usMill = 0);
    // ����ʱ�����
    inline void SetTime( unsigned int   uiYear,  unsigned int uiMonth, unsigned int  uiDay,
                         unsigned int   uiHour,  unsigned int uiMin,   unsigned int  uiSec, 
                         unsigned short usMill = 0 );

    // ���ݸ�ʽ���ַ�����YYYY/MM/DD HH:MM:SS.MS������Time����
    inline void SetTimeFmFull(const void* szFmtStr);

    // ��ȡʱ���ַ�������ʽ"YYYY/MM/DD"
    inline const tChar* ToStrDay1();
    // ��ȡʱ���ַ�������ʽ"YYMMDD"
    inline const tChar* ToStrDay2();
    // ��ȡʱ���ַ�������ʽ"HH:MM:SS"
    inline const tChar* ToStrTime();
    // ��ȡʱ���ַ�������ʽ"MS"
    inline const tChar* ToStrMillitm();
    // ��ȡʱ���ַ�������ʽ""%Y/%m/%d %H:%M:%S:%Mill"
    inline const tChar* ToStrFull();

    // ��ʽ���ṹ
    // FMT : 
    //      %Y4  (Year                           e.g.                     2009)  = %Y
    //      %Y2  (Year, last two digits          e.g.                    00-99)  = %y
    //      %MM  (Month as a decimal number      e.g.                    01-12)  = %m
    //      %DD  (Day of month, zero padded      e.g,                    01-31)  = %d
    //      %dd  (Day of month, space padded     e.g,                     1-31)  = %e
    //      %hh  (Hour in 24h                    e.g.                    01-24)  = %H
    //      %II  (Hour in 12h                    e.g.                    01-12)  = %I
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
    //      %fd  (Short YYYY-MM-DD date          e.g.               08-23-2001)  = %m-%d-%Y
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
    inline tChar* Fmt( const tChar* const pFmt )
    {
        // ��ʼ������������
        vm::CParser loParser(vT('%'), cpFmt);
        //      %Y4  (Year                           e.g.                     2009)  = %Y
        vm::CParser::CPattern loPatternDTForY4( vT("%Y4"), vT("%Y") );
        loParser.Regist(loPatternDTForY4);
        //      %Y2  (Year, last two digits          e.g.                    00-99)  = %y
        vm::CParser::CPattern loPatternDTForY2( vT("%Y2"), vT("%y") );
        loParser.Regist(loPatternDTForY2);
        //      %MM  (Month as a decimal number      e.g.                    01-12)  = %m
        vm::CParser::CPattern loPatternDTForMM( vT("%MM"), vT("%m") );
        loParser.Regist(loPatternDTForMM);
        //      %DD  (Day of month, zero padded      e.g,                    01-31)  = %d
        vm::CParser::CPattern loPatternDTForDD( vT("%DD"), vT("%d") );
        loParser.Regist(loPatternDTForDD);
        //      %dd  (Day of month, space padded     e.g,                     1-31)  = %e
        vm::CParser::CPattern loPatternDTFordd( vT("%dd"), vT("%e") );
        loParser.Regist(loPatternDTFordd);
        //      %hh  (Hour in 24h                    e.g.                    01-24)  = %H
        vm::CParser::CPattern loPatternDTForhh( vT("%hh"), vT("%H") );
        loParser.Regist(loPatternDTForhh);
        //      %II  (Hour in 12h                    e.g.                    01-12)  = %I
        vm::CParser::CPattern loPatternDTForII( vT("%II"), vT("%I") );
        loParser.Regist(loPatternDTForII);
        //      %mm  (Minute                         e.g.                    00-59)  = %M
        vm::CParser::CPattern loPatternDTFormm( vT("%mm"), vT("%M") );
        loParser.Regist(loPatternDTFormm);
        //      %ss  (Second                         e.g.                    00-61)  = %S
        vm::CParser::CPattern loPatternDTForss( vT("%ss"), vT("%S") );
        loParser.Regist(loPatternDTForss);
        //      %ms  (millisecond                    e.g.                  000-999)
        vm::CParser::CPattern loPatternDTForms( vT("%ms"), vm::CAny<128>(mstTime.millitm).s_ushort() );
        loParser.Regist(loPatternDTForms);
        //      %WY  (Week based year                e.g.                    00-99)  = %g
        vm::CParser::CPattern loPatternDTForWY( vT("%WY"), vT("%g") );
        loParser.Regist(loPatternDTForWY);
        //      %WW  (ISO 8601 weekday as number with Monday          e.g.     1-7)  = %u
        vm::CParser::CPattern loPatternDTForWW( vT("%WW"), vT("%u") );
        loParser.Regist(loPatternDTForWW);
        //      %ww  (Weekday as a decimal number with Sunday as 0    e.g.     0-6)  = %w
        vm::CParser::CPattern loPatternDTForww( vT("%ww"), vT("%w") );
        loParser.Regist(loPatternDTForww);
        //      %WN  (ISO 8601 week number           e.g.                    00-53)  = %V
        vm::CParser::CPattern loPatternDTForWN( vT("%WN"), vT("%V") );
        loParser.Regist(loPatternDTForWN);
        //      %WS  (Week number with the first Sunday as the first day of week one  e.g. 00-53 ) = %U
        vm::CParser::CPattern loPatternDTForWS( vT("%WS"), vT("%U") );
        loParser.Regist(loPatternDTForWS);
        //      %WM  (Week number with the first Monday as the first day of week one  e.g. 00-53 ) = %W
        vm::CParser::CPattern loPatternDTForWM( vT("%WM"), vT("%W") );
        loParser.Regist(loPatternDTForWM);
        //      %DY  (Day of the year                e.g.                  001-366)  = %j
        vm::CParser::CPattern loPatternDTForDY( vT("%DY"), vT("%j") );
        loParser.Regist(loPatternDTForDY);
        //      %AP  (AM or PM designation           e.g.                 AM or PM)  = %p
        vm::CParser::CPattern loPatternDTForAP( vT("%AP"), vT("%p") );
        loParser.Regist(loPatternDTForAP);
        //      %AM  (Abbreviated month              e.g.                   August)  = %B
        vm::CParser::CPattern loPatternDTForAM( vT("%AM"), vT("%b") );
        loParser.Regist(loPatternDTForAM);
        //      %am  (Abbreviated month              e.g.                      Aug)  = %b
        vm::CParser::CPattern loPatternDTForam( vT("%am"), vT("%b") );
        loParser.Regist(loPatternDTForam);
        //      %AW  (Abbreviated weekday            e.g.                   Friday)  = %A
        vm::CParser::CPattern loPatternDTForAW( vT("%AW"), vT("%A") );
        loParser.Regist(loPatternDTForAW);
        //      %aw  (Abbreviated weekday            e.g.                      Fri)  = %a
        vm::CParser::CPattern loPatternDTForaw( vT("%aw"), vT("%a") );
        loParser.Regist(loPatternDTForaw);
        //      %CD  (date and time representation   e.g. Thu Aug 23 14:55:02 2001)  = %c
        vm::CParser::CPattern loPatternDTForCD( vT("%CD"), vT("%c") );
        loParser.Regist(loPatternDTForCD);
        //      %SD  (Short MM/DD/YY date            e.g.                 08/23/01)  = %D
        vm::CParser::CPattern loPatternDTForSD( vT("%SD"), vT("%D") );
        loParser.Regist(loPatternDTForSD);
        //      %sd  (Short YY/MM/DD date            e.g.                 01/08/23)  = %y/%m/%d
        vm::CParser::CPattern loPatternDTForsd( vT("%sd"), vT("%y/%m/%d") );
        loParser.Regist(loPatternDTForsd);
        //      %FD  (Short YYYY-MM-DD date          e.g.               2001-08-23)  = %F
        vm::CParser::CPattern loPatternDTForFD( vT("%FD"), vT("%F") );
        loParser.Regist(loPatternDTForFD);
        //      %fd  (Short YYYY-MM-DD date          e.g.               08-23-2001)  = %m-%d-%Y
        vm::CParser::CPattern loPatternDTForfd( vT("%fd"), vT("%m-%d-%Y") );
        loParser.Regist(loPatternDTForfd);
        //      %RT  (24 - hour HH:MM time           e.g.                    14:55)  = %R
        vm::CParser::CPattern loPatternDTForRT( vT("%RT"), vT("%R") );
        loParser.Regist(loPatternDTForRT);
        //      %rt  (12 - hour clock time           e.g.              02:55:02 pm)  = %r
        vm::CParser::CPattern loPatternDTForrt( vT("%rt"), vT("%r") );
        loParser.Regist(loPatternDTForrt);
        //      %TT  (ISO 8601 time format           e.g.                 14:55:02)  = %T
        vm::CParser::CPattern loPatternDTForTT( vT("%TT"), vT("%T") );
        loParser.Regist(loPatternDTForTT);
        //      %tt  (ISO 8601 time format 12 hour   e.g.                 02:55:02)  = %I:%M:%S
        vm::CParser::CPattern loPatternDTFortt( vT("%tt"), vT("%I:%M:%S") );
        loParser.Regist(loPatternDTFortt);
        //      %TZ  (Timezone name                  e.g.                      CDT)  = %Z
        vm::CParser::CPattern loPatternDTForTZ( vT("%TZ"), vT("%Z") );
        loParser.Regist(loPatternDTForTZ);
        //      %ZZ  (ISO 8601 offset from UTC in timezone(1 minute = 1,             = %z
        //            1 hour = 100) If timezone cannot be determined, 
        //            no characters)
        vm::CParser::CPattern loPatternDTForZZ( vT("%ZZ"), vT("%z") );
        loParser.Regist(loPatternDTForZZ);
        //      %n   (New        - line character('\n')  
        //vm::CParser::CPattern loPatternDTForNL( vT("%n"), vT("%n") );
        //loParser.Regist(loPatternErrCode);
        //      %t   (Horizontal - tab  character('\t')  
        //vm::CParser::CPattern loPatternDTForTC( vT("%t"), vT("%t") );
        //loParser.Regist(loPatternErrCode);
        //      %%   ( A % sign	- %
        //vm::CParser::CPattern loPatternDTForY4( vT("%Y4"), vT("%%") );
        //loParser.Regist(loPatternErrCode);

        tChar lszNewFmt[_V_CDATETIME_MAX_BUF_] = {0x00};
        loParser.Parse(lszNewFmt, sizeof(lszNewFmt));


        tChar lpTimeStr = toTimeStr( lszNewFmt );
        return lpTimeStr;
    };

    // ��ʽ��ʱ��ṹ
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
    //     %k        | ����ֵ
    inline const tChar* toTimeStr(const tChar* const cpFmt);
    // ��ʽ��ʱ��ṹ�еĺ���ֵ
    inline void  s_millisecond(tChar* const       pBuf,
                         const size_t      csztBufSize,
                         const tChar* const cpFmt);

}; // End of class CDateTime
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CDateTime()
// Brief     : ��������
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
// Brief     : ��������
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
// Brief     : �������캯��
// Return    : void
// Parameter : const CDateTime& obj     - ��������
template <size_t sztBufSize>
CDateTime<sztBufSize>::CDateTime(const CDateTime& obj)
{
   *this = obj;
};
// End of function CDateTime(const CDateTime& obj)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CDateTime(time_t tTime)
// Brief     : ���캯��
// Return    : void
// Parameter : time_t tTime             - ��ֵtime_t����
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
// Brief     : ���캯��
// Return    : void
// Parameter : _timeb tTimeb            - ��ֵ_timeb����
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
// Parameter : const CDateTime& obj     - ��ֵ�Ķ���
// Return    : CDateTime&               - ��ǰCDateTime����
// Notes     : ��ֵ����
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
// Brief     : �ӷ�����
// Return    : time_t                   - ��ǰtime_tֵ
// Parameter : const time_t tTimeDiff   - ��Ҫ���ʱ����λ�룩
template <size_t sztBufSize>
time_t CDateTime<sztBufSize>::operator + (const time_t tTimeDiff)
{
    // TODO [Q] : ����֤
    mstTime.time += tTimeDiff;
    return mstTime.time;
}
// End of function operator + (const time_t tTimeDiff)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator - (const time_t tTimeDiff)
// Brief     : ��������
// Return    : time_t                   - ��ǰtime_tֵ
// Parameter : const time_t tTimeDiff   - ��Ҫ���ʱ����λ�룩
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
// Brief     : == ����
// Return    : true                     - ���
//             false                    - �����
// Parameter : const CDateTime& Obj     - ��Ҫ�ԱȵĶ���
template <size_t sztBufSize>
bool CDateTime<sztBufSize>::operator == (const CDateTime& Obj)
{
    // TODO [Q] : ����֤
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
// Brief     : == ����
// Return    : true                     - ���
//             false                    - �����
// Parameter : const CDateTime& Obj     - ��Ҫ�ԱȵĶ���
template <size_t sztBufSize>
bool CDateTime<sztBufSize>::operator != (const CDateTime& Obj)
{
    // TODO [Q] : ����֤
    if (0 == memcmp(&mstTime, &Obj.mstTime, sizeof(_timeb)))
        return false;

    return true;
};
// End of function operator != (const CDateTime& Obj)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : operator > (const CDateTime& Obj)
// Brief     :  > ����
// Return    : true                     - ���
//             false                    - �����
// Parameter : const CDateTime& Obj     - ��Ҫ�ԱȵĶ���
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
// Brief     : < ����
// Return    : true                     - ���
//             false                    - �����
// Parameter : const CDateTime& Obj     - ��Ҫ�ԱȵĶ���
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
// Notes     : ��ȡ��ǰʱ��
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
// Brief     : ��ȡ��ǰ�����time_tʱ��ṹ
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
// Brief     : ��ȡ��ǰ�����_timebʱ��ṹ
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
// Brief     : ��ȡ��ǰ����ĺ�����
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
// Method    : SetTimeFmFull(const tChar* szFmtStr)
// Brief     : ���ݸ�ʽ���ַ�����YYYY/MM/DD HH:MM:SS.MS������Time����
// Return    : void
// Parameter : const tChar* szFmtStr         - ��ʽ�����ַ���
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
// End of function SetTimeFmFull(const tChar* szFmtStr)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : SetTime( ... )
// Brief     : ����ʱ�����
// Return    : void
// Parameter : unsigned int   uiHour        - Сʱֵ
//             unsigned int   uiMin         - ����ֵ
//             unsigned int   uiSec         - ��ֵ
//             unsigned short usMill        - ����ֵ
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
// Brief     : ����ʱ�����
// Return    : void
// Parameter : unsigned int  uiYear            - �꣨�����1900��
//             unsigned int  uiMonth           - �£���С�ڵ���12��
//             unsigned int  uiDay             - �գ���С�ڵ���31��
//             unsigned int  uiHour            - ʱ����С�ڵ���24��
//             unsigned int  uiMin             - �֣���С�ڵ���60��
//             unsigned int  uiSec             - �루��С�ڵ���60��
//             unsigned short usMill           - ���루��С�ڵ���999��
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
// Brief     : ��ʽ�����ʱ��
// Return    : tChar*                            - ��ʽ������ַ���
// Parameter : const tChar* szFormat             - �ַ�����ʽ
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
//     %k        | ����ֵ
template <size_t sztBufSize>
inline const tChar* CDateTime<sztBufSize>::toTimeStr(const tChar* const cpFmt)
{
    // ��ʽ���ַ�����������ʶ��
    memset(&mszBuf, 0x00, sztBufSize);
#if defined ( _MSC_VER ) && ( _MSC_VER >=1200 )
    struct tm loTm;
    errno_t loErr = localtime_s(&loTm, &mstTime.time);
    strftime(mszBuf, sztBufSize, cpFmt, &loTm);
#else
    struct tm* lpTm = localtime(&mstTime.time);
    strftime(mszBuf, sztBufSize, cpFmt, lpTm);
#endif

    return mszBuf;
};
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

template <size_t sztBufSize>
inline void  CDateTime<sztBufSize>::s_millisecond( tChar* const       pBuf,
                                                   const size_t      csztBufSize, 
                                                   const tChar* const cpFmt )
{
    CMemPtr loBuf(pBuf, csztBufSize);
    size_t  lsztBufOffset = 0;
    CStrPtr loFmt(const_cast<tChar*>(cpFmt), strlen(cpFmt));
    size_t  lsztFmtOffset = 0;
    
    // ��cpFmtָ���ַ����еġ�%K���ַ����滻Ϊʱ�����ֵ
    const tChar* lpFlags = vT("%K");
    vm::CAny<128> loMillim(mstTime.millitm);
    vm::CParser::CPattern   loPattern( lpFlags, vStrLen(lpFlags), loMillim.s_ushort(), loMillim.len() );

    vm::CParser             loParser('%', cpFmt, vStrLen(cpFmt));
    loParser.Regist( loPattern );
    loParser.Parse(pBuf,csztBufSize);
}

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrDay1()
// Brief     : ��ȡʱ���ַ�������ʽ"YYYY/MM/DD"
// Return    : tChar*                            - ��ʽ������ַ���
// Parameter : null
template <size_t sztBufSize>
const tChar* CDateTime<sztBufSize>::ToStrDay1()
{
    return toTimeStr("%Y/%m/%d");
}
// End of function ToStrDay1()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrDay2()
// Brief     : ��ȡʱ���ַ�������ʽ"YYMMDD"
// Return    : tChar*                            - ��ʽ������ַ���
// Parameter : null
template <size_t sztBufSize>
inline const tChar* CDateTime<sztBufSize>::ToStrDay2()
{
    return toTimeStr("%y%m%d");
}
// End of function ToStrDay2()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrTime()
// Brief     : ��ȡʱ���ַ�������ʽ"HH:MM:SS"
// Return    : tChar*                            - ��ʽ������ַ���
// Parameter : null
template <size_t sztBufSize>
inline const tChar* CDateTime<sztBufSize>::ToStrTime()
{
    return toTimeStr("%H:%M:%S");
}
// End of function ToStrTime()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrMillitm()
// Brief     : ��ȡʱ���ַ�������ʽ"%Mill"
// Return    : tChar*                            - ��ʽ������ַ���
// Parameter : null
template <size_t sztBufSize>
inline const tChar* CDateTime<sztBufSize>::ToStrMillitm()
{
    memset(&mszBuf, 0x00, sztBufSize);
    v_sprintf( mszBuf, sztBufSize, "%03d", mstTime.millitm );
    return mszBuf;
}
// End of function ToStrMillitm()
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ToStrFull()
// Brief     : ��ȡʱ���ַ�������ʽ""%Y/%m/%d %H:%M:%S:%Mill"
// Return    : tChar*                            - ��ʽ������ַ���
// Parameter : null
template <size_t sztBufSize>
inline const tChar* CDateTime<sztBufSize>::ToStrFull()
{
    memset(&mszBuf, 0x00, sztBufSize);
    tChar lszBuf[sztBufSize] = { 0 };

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
