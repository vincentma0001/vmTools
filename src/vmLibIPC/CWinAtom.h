/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinAtom.h
// Version      : 1.0.0.0
// Brief        : 此类封装了window原子操作
// Author       : v.m.
// Create time  : 2019/12/19 08:54:07
// Modify time  : 2019/12/19 08:54:07
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

#ifndef __CWINATOM_H__
#define __CWINATOM_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#ifndef _WINDOWS_
#   error this file need #include <windows.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinAtom : 此类封装了window原子操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinAtom
{
/////////////////////////////////////////////////////////////////////////////////////////
// type define :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinAtom():mlValue(0){};
    // Construct define
    explicit CWinAtom(const long clVal):mlValue(clVal) {};
    // Copy Construct
    CWinAtom(const CWinAtom& obj):mlValue(obj.mlValue){};
    // Destruct define
    virtual ~CWinAtom(){};

public:
    // 赋值操作
    inline CWinAtom& operator = (const CWinAtom& obj)
    {::InterlockedExchange(&mlValue, obj.mlValue); return *this;};
    inline CWinAtom& operator = (long lVal)
    {::InterlockedExchange(&mlValue, lVal);return *this;};
    // 加法操作
    inline CWinAtom& operator + (const CWinAtom& obj)
    {::InterlockedExchangeAdd(&mlValue, obj.mlValue); return *this;};
    inline CWinAtom& operator + (long lVal)
    {::InterlockedAdd(&mlValue, lVal);return *this;};

    // 自增
    inline CWinAtom& operator ++ (void)
    {::InterlockedIncrement(&mlValue);return *this;};
    inline CWinAtom operator ++ (int)
    {CWinAtom loTmp = *this; ::InterlockedIncrement(&mlValue); return loTmp;};
    // 自减
    inline CWinAtom& operator -- (void)
    {::InterlockedDecrement(&mlValue);return *this;};
    inline CWinAtom operator -- (int)
    {CWinAtom loTmp = *this;::InterlockedDecrement(&mlValue);return loTmp;};

    // 是判断
    inline bool operator == (const CWinAtom& obj)
    {return mlValue == obj.mlValue ? true : false;};
    inline bool operator == (long lVal)
    {return mlValue == lVal ? true : false;};

    // 否判断
    inline bool operator != (const CWinAtom& obj)
    {return mlValue != obj.mlValue ? true : false;};
    inline bool operator != (long lVal)
    {return mlValue != lVal;};
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:
    long               mlValue;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 原子加操作，
    inline long Add(const long clVal)
    {::InterlockedExchangeAdd(&mlValue, clVal);return mlValue;};
    // 原子变更操作
    inline long Change(const long clVal)
    {::InterlockedExchange(&mlValue, clVal);return mlValue;};
    // 原子加一操作
    inline long Increment(void)
    {::InterlockedIncrement(&mlValue);return mlValue;};
    // 原子减一操作
    inline long Decrement(void)
    {::InterlockedDecrement(&mlValue);return mlValue;};
    // 比较变更操作，若存储值等于比较值,则变更存储值。
    inline long CompareExchange(long clCompareVal, long clChangeVal)
    {::InterlockedCompareExchange(&mlValue, clChangeVal, clCompareVal);return mlValue;};

public:
    // 获取存储值
    inline operator long()
    {return mlValue;};


}; // End of class CWinAtom
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CATOM_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinAtom.h
/////////////////////////////////////////////////////////////////////////////////////////