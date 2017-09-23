/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CAtom.h
// Version 		: 1.0.0.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 16/2/2016 9:11:54
// Modify time 	: 16/2/2016 9:11:54
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef _WINDOWS_
#   include <Windows.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CAtom
//        Notes : 此类封装了windows中相关的原子操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CAtom
{
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
private:
    long               mlValue;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
    CAtom( ):mlValue(0){};                              // Construct define
    CAtom( const long clVal ):mlValue(clVal){};         // Construct define
    CAtom( const CAtom& obj ):mlValue(obj.mlValue){};   // Copy Construct
    virtual ~CAtom(){};                                   // Destruct define

public:
    CAtom& operator = ( const CAtom& obj )
    {InterlockedExchange( &mlValue, obj.mlValue );return *this;};          // 赋值操作
    CAtom& operator + ( const CAtom& obj )
    {InterlockedExchangeAdd( &mlValue, obj.mlValue );return *this;};       // 加法操作


/////////////////////////////////////////////////////////////////////////////////////////
// functions : 
public:
    long Add        ( const long clVal )
    {return InterlockedExchangeAdd( &mlValue, clVal );};                          // 原子加操作，
    long Change     ( const long clVal )
    {return InterlockedExchange( &mlValue, clVal );};                             // 原子变更操作
    long Increment  ( void )
    {return InterlockedIncrement( &mlValue );};                                   // 原子加一操作
    long Decrement  ( void )
    {return InterlockedDecrement( &mlValue );};                                   // 原子减一操作
    long CompareExchange( long clCompareVal, long clChangeVal )
    {return (long)InterlockedCompareExchange( (unsigned long long*)&mlValue, (unsigned long long)clChangeVal, (unsigned long long)clCompareVal );};  // 比较变更操作，若存储值等于比较值,则变更存储值。

public:
    operator long(){return mlValue;};                                    // 获取存储值

}; // End of class CAtom
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CAtom.h
/////////////////////////////////////////////////////////////////////////////////////////