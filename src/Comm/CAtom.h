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
//        Notes : �����װ��windows����ص�ԭ�Ӳ���
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
    {InterlockedExchange( &mlValue, obj.mlValue );return *this;};          // ��ֵ����
    CAtom& operator + ( const CAtom& obj )
    {InterlockedExchangeAdd( &mlValue, obj.mlValue );return *this;};       // �ӷ�����


/////////////////////////////////////////////////////////////////////////////////////////
// functions : 
public:
    long Add        ( const long clVal )
    {return InterlockedExchangeAdd( &mlValue, clVal );};                          // ԭ�ӼӲ�����
    long Change     ( const long clVal )
    {return InterlockedExchange( &mlValue, clVal );};                             // ԭ�ӱ������
    long Increment  ( void )
    {return InterlockedIncrement( &mlValue );};                                   // ԭ�Ӽ�һ����
    long Decrement  ( void )
    {return InterlockedDecrement( &mlValue );};                                   // ԭ�Ӽ�һ����
    long CompareExchange( long clCompareVal, long clChangeVal )
    {return (long)InterlockedCompareExchange( (unsigned long long*)&mlValue, (unsigned long long)clChangeVal, (unsigned long long)clCompareVal );};  // �Ƚϱ�����������洢ֵ���ڱȽ�ֵ,�����洢ֵ��

public:
    operator long(){return mlValue;};                                    // ��ȡ�洢ֵ

}; // End of class CAtom
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CAtom.h
/////////////////////////////////////////////////////////////////////////////////////////