/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinAtom.h
// Version      : 1.0.0.0
// Brief        : �����װ��windowԭ�Ӳ���
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
// class CWinAtom : �����װ��windowԭ�Ӳ���
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
    // ��ֵ����
    inline CWinAtom& operator = (const CWinAtom& obj)
    {::InterlockedExchange(&mlValue, obj.mlValue); return *this;};
    inline CWinAtom& operator = (long lVal)
    {::InterlockedExchange(&mlValue, lVal);return *this;};
    // �ӷ�����
    inline CWinAtom& operator + (const CWinAtom& obj)
    {::InterlockedExchangeAdd(&mlValue, obj.mlValue); return *this;};
    inline CWinAtom& operator + (long lVal)
    {::InterlockedAdd(&mlValue, lVal);return *this;};

    // ����
    inline CWinAtom& operator ++ (void)
    {::InterlockedIncrement(&mlValue);return *this;};
    inline CWinAtom operator ++ (int)
    {CWinAtom loTmp = *this; ::InterlockedIncrement(&mlValue); return loTmp;};
    // �Լ�
    inline CWinAtom& operator -- (void)
    {::InterlockedDecrement(&mlValue);return *this;};
    inline CWinAtom operator -- (int)
    {CWinAtom loTmp = *this;::InterlockedDecrement(&mlValue);return loTmp;};

    // ���ж�
    inline bool operator == (const CWinAtom& obj)
    {return mlValue == obj.mlValue ? true : false;};
    inline bool operator == (long lVal)
    {return mlValue == lVal ? true : false;};

    // ���ж�
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
    // ԭ�ӼӲ�����
    inline long Add(const long clVal)
    {::InterlockedExchangeAdd(&mlValue, clVal);return mlValue;};
    // ԭ�ӱ������
    inline long Change(const long clVal)
    {::InterlockedExchange(&mlValue, clVal);return mlValue;};
    // ԭ�Ӽ�һ����
    inline long Increment(void)
    {::InterlockedIncrement(&mlValue);return mlValue;};
    // ԭ�Ӽ�һ����
    inline long Decrement(void)
    {::InterlockedDecrement(&mlValue);return mlValue;};
    // �Ƚϱ�����������洢ֵ���ڱȽ�ֵ,�����洢ֵ��
    inline long CompareExchange(long clCompareVal, long clChangeVal)
    {::InterlockedCompareExchange(&mlValue, clChangeVal, clCompareVal);return mlValue;};

public:
    // ��ȡ�洢ֵ
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