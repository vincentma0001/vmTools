/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinCounter.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/10 09:43:01
// Modify time  : 2020/01/10 09:43:01
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

#ifndef __CWINCOUNTER_H__
#define __CWINCOUNTER_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#ifndef   _INC_STRING
#   include <string.h>
#endif // _INC_STRING

// Config files included

// Platform files included
#ifndef   _WINDOWS_
#   include <windows.h>
#endif // _WINDOWS_

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinCounter : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinCounter
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CWinCounter(){ Reset(); };
    // Destruct define
    inline virtual ~CWinCounter(){};
    
private:
    // No Copy
    inline CWinCounter(const CWinCounter& obj){};
    // No Assignment
    inline CWinCounter& operator = ( const CWinCounter& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    LARGE_INTEGER	mliFrequency;
    LARGE_INTEGER	mliStart;
    LARGE_INTEGER	mliStop;
    long long       mllTimeDiff;

private:
    unsigned long   mulErrCode;

public:
    bool HasError() { return mulErrCode == 0 ? true : false; };
    unsigned long toErrCode(){ return mulErrCode; }

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    inline void Reset()
    {
        mllTimeDiff = 0;
        memset( &mliFrequency, 0x00, sizeof(mliFrequency) );
        memset( &mliStart,     0x00, sizeof(mliStart)     );
        memset( &mliStop,      0x00, sizeof(mliStop)      );
    }

    // 开始计数
    inline bool       Begin()
    {
        Reset();

        bool lbRetForFrequency = ::QueryPerformanceFrequency(&mliFrequency);
        // #  TODO : Add condition brief here ##
        if (lbRetForFrequency==false)
        {
        	mulErrCode = GetLastError();
            return false;
        } 
        // End of if (lbRetForFrequency==false) ...

        bool lbRetForCounter   = ::QueryPerformanceCounter(&mliStart);
        // #  TODO : Add condition brief here ##
        if (lbRetForCounter==false)
        {
        	mulErrCode = GetLastError();
            return false;
        } 
        // End of if (lbRetForCounter==false) ...

        return true;
    }

    // 结束计数
    inline long long  Ended()
    {
        bool lbRetForCounter = ::QueryPerformanceCounter(&mliStop);
        // #  TODO : Add condition brief here ##
        if (lbRetForCounter==false)
        {
        	mulErrCode = GetLastError();
            return vMinsLLong;
        } 
        // End of if (lbRetForCounter==false) ...
        mllTimeDiff = (mliStop.QuadPart - mliStart.QuadPart);
        return mllTimeDiff;
    };

    inline long long toSecond()
    {
        return (long long)(mllTimeDiff / (long double)(mliFrequency.QuadPart));
    }
    inline long long toMilliSecond()
    {
        return (long long)( mllTimeDiff*1000 / (long double)mliFrequency.QuadPart );
    }

    inline long long toMicroSecond()
    {
        return (long long)(mllTimeDiff*1000*1000 / (long double)(mliFrequency.QuadPart));
    }

    inline long long toNanoSecond()
    {
        return (long long)(mllTimeDiff*1000*1000*1000 / (long double)(mliFrequency.QuadPart));
    }

}; // End of class CWinCounter
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINCOUNTER_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinCounter.h
/////////////////////////////////////////////////////////////////////////////////////////