/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinAtom.h
// Version      : 1.0.0.0
// Brief        : this class package windows atomic operation
// Author       : v.m.
// Create time  : 2019/12/19 08:54:07
// Modify time  : 2019/12/19 08:54:07
// Note         :
//
// Test         :
//      CWinAtom<bool>
//              [F] bool operator = ( const bool obj )
//              [F] operator bool ( )
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
#   include <windows.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinAtom : this class package windows atomic operation
//
/////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
class DLL_API CWinAtom
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinAtom( T obj ):mT(obj){};
    // Destruct define
    virtual ~CWinAtom(){};
    
private:
    // No Copy
    CWinAtom(const CWinAtom& obj){};
    // No Assignment
    CWinAtom& operator = ( const CWinAtom& obj ){};

public:
    // Assignment operator
    T operator = ( const T& obj )
    { return ::InterlockedExchange((unsigned long long*)&mT, (unsigned long long)obj); };

    // == operator
    bool operator == ( const T obj )
    { return ::InterlockedCompareExchange((unsigned long long*)&mT, (unsigned long long)mT, (unsigned long long)obj) == (unsigned long long)obj ? true : false; };
    // != operator
    inline bool operator != ( const T obj )
    { return ::InterlockedCompareExchange((unsigned long long*)&mT, (unsigned long long)mT, (unsigned long long)obj) != (unsigned long long)obj ? true : false; };

    // + operator
    T operator + ( const T obj )
    { return ::InterlockedAdd( (unsigned long long*)&mT, (unsigned long long)obj ); };
    
    // ++ operator
    T operator ++ ( const T obj )
    { return ::InterlockedIncrement((unsigned long long*)&mT); };
    // -- operator
    T operator -- ( const T obj )
    { return ::InterlockedDecrement((unsigned long long*)&mT); };

    // operator T
    operator T (){ return mT; }
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    T       mT;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    void Enter(){};
    void Leave(){};

public:
    void Increment(){}
    void Decrement(){}

    void Add(){};
    void Exchange(){};
    void CompareExchange(){};

}; // End of class CWinAtom
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinAtom : this class package windows atomic operation with bool type
//
/////////////////////////////////////////////////////////////////////////////////////////
template<>
class DLL_API CWinAtom<bool>
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CWinAtom(bool obj) :mT(obj) {};
    // Destruct define
    inline virtual ~CWinAtom() {};

private:
    // No Copy
    inline CWinAtom(const CWinAtom& obj) {};
    // No Assignment
    inline CWinAtom& operator = (const CWinAtom& obj) { return *this; };

public:
    // Assignment operation
    inline bool operator = (const bool& obj) 
    { return ::InterlockedExchange( (unsigned long long*)&mT, (unsigned long long)obj ); };
    
    // == operation
    inline bool operator == (const bool obj) 
    { 
        unsigned long long lumt = (unsigned long long)mT;
        unsigned long long lumt2 = (unsigned long long)obj;
        long long lbRet = ::InterlockedExchange64((long long*)&mT, (long long)obj);
       // #  TODO : Add condition brief here ##
       if (lbRet==(unsigned long long)obj)
       {
            return true;
       } 

        return false;
       // End of if (lbRet==(unsigned long long)obj) ...
    }
    // != operation
    inline bool operator != (const bool obj) 
    { return ::InterlockedCompareExchange((unsigned long long*)&mT, (unsigned long long)mT, (unsigned long long)obj) != (unsigned long long)obj ? true : false; };

    //T operator + (const T obj) { ::InterlockedAdd(mT, obj); };

    //T operator ++ (const T obj) { ::InterlockedIncrement(mT); };
    //T operator -- (const T obj) { ::InterlockedDecrement(mT); };

    // bool() opearation
    inline operator bool() { return mT; }

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    bool       mT;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    inline void Enter() 
    {   while( *this == true ) {::Sleep(0);}    };
    inline void Leave() 
    {   *this = false;  };

public:
    //void Increment() {}
    //void Decrement() {}

    //void Add() {};
    inline bool Exchange       ( const bool obj ) 
    { return ::InterlockedExchange       ((unsigned long long*)&mT, (unsigned long long)obj);                           };
    inline bool CompareExchange( const bool obj ) 
    { return ::InterlockedCompareExchange((unsigned long long*)&mT, (unsigned long long)obj, (unsigned long long)obj ); };

}; // End of class CWinAtom
/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
////
//// class CWinAtom : 此类封装了window原子操作
////
///////////////////////////////////////////////////////////////////////////////////////////
//class CWinAtom
//{
///////////////////////////////////////////////////////////////////////////////////////////
//// type define :
//
///////////////////////////////////////////////////////////////////////////////////////////
//// Construct && Destruct
//public:
//    // Construct define
//    explicit CWinAtom():mlValue(0){};
//    // Construct define
//    explicit CWinAtom(const long clVal):mlValue(clVal) {};
//    // Copy Construct
//    CWinAtom(const CWinAtom& obj):mlValue(obj.mlValue){};
//    // Destruct define
//    virtual ~CWinAtom(){};
//
//public:
//    // 赋值操作
//    inline CWinAtom& operator = (const CWinAtom& obj)
//    {::InterlockedExchange(&mlValue, obj.mlValue); return *this;};
//    inline CWinAtom& operator = (long lVal)
//    {::InterlockedExchange(&mlValue, lVal);return *this;};
//    // 加法操作
//    inline CWinAtom& operator + (const CWinAtom& obj)
//    {::InterlockedExchangeAdd(&mlValue, obj.mlValue); return *this;};
//    inline CWinAtom& operator + (long lVal)
//    {::InterlockedAdd(&mlValue, lVal);return *this;};
//
//    // 自增
//    inline CWinAtom& operator ++ (void)
//    {::InterlockedIncrement(&mlValue);return *this;};
//    inline CWinAtom operator ++ (int)
//    {CWinAtom loTmp = *this; ::InterlockedIncrement(&mlValue); return loTmp;};
//    // 自减
//    inline CWinAtom& operator -- (void)
//    {::InterlockedDecrement(&mlValue);return *this;};
//    inline CWinAtom operator -- (int)
//    {CWinAtom loTmp = *this;::InterlockedDecrement(&mlValue);return loTmp;};
//
//    // 是判断
//    inline bool operator == (const CWinAtom& obj)
//    {return mlValue == obj.mlValue ? true : false;};
//    inline bool operator == (long lVal)
//    {return mlValue == lVal ? true : false;};
//
//    // 否判断
//    inline bool operator != (const CWinAtom& obj)
//    {return mlValue != obj.mlValue ? true : false;};
//    inline bool operator != (long lVal)
//    {return mlValue != lVal;};
//    
///////////////////////////////////////////////////////////////////////////////////////////
//// members
//private:
//    long               mlValue;
//
///////////////////////////////////////////////////////////////////////////////////////////
//// Functions :
//public:
//    // 原子加操作，
//    inline long Add(const long clVal)
//    {::InterlockedExchangeAdd(&mlValue, clVal);return mlValue;};
//    // 原子变更操作
//    inline long Change(const long clVal)
//    {::InterlockedExchange(&mlValue, clVal);return mlValue;};
//    // 原子加一操作
//    inline long Increment(void)
//    {::InterlockedIncrement(&mlValue);return mlValue;};
//    // 原子减一操作
//    inline long Decrement(void)
//    {::InterlockedDecrement(&mlValue);return mlValue;};
//    // 比较变更操作，若存储值等于比较值,则变更存储值。
//    inline long CompareExchange(long clCompareVal, long clChangeVal)
//    {::InterlockedCompareExchange(&mlValue, clChangeVal, clCompareVal);return mlValue;};
//
//public:
//    // 获取存储值
//    inline operator long()
//    {return mlValue;};
//
//
//}; // End of class CWinAtom
///////////////////////////////////////////////////////////////////////////////////////////

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