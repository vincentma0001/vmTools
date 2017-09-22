/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CValue.h
// Version 		: 0.0.1.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 23/1/2016 9:46:35
// Modify time 	: 23/1/2016 9:46:35
// Note 		:
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

#ifndef __CVALUE_H__
#define __CVALUE_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <sstream>

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#define _MAX_VALUE_BUF_ 128

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CValue
//        Notes : ����������й�����ת����һЩ����
//
/////////////////////////////////////////////////////////////////////////////////////////
class CValue
{
/////////////////////////////////////////////////////////////////////////////////////////
// data members :
public:
    union unValue
    {
        char            cValue;
        int             iValue;
        float           fValue;
        double          dValue;
        long            lValue;
        unsigned int    uiValue;
        unsigned long   ulValue;
    } munValue;                                     // ��ֵ
    char mszBuf[_MAX_VALUE_BUF_];                   // �ַ�������
    size_t mstLen;                                  // �ַ�������
    char mszBufForBit[_MAX_VALUE_BUF_];             // ��ֵ�������ַ�������
    size_t mstLenForBit;                            // ��ֵ�������ַ�������
    char mszBufForHex[_MAX_VALUE_BUF_];             // ��ֵʮ�������ַ�������
    size_t mstLenForHex;                            // ��ֵʮ�������ַ�������

/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
    // Construct define
    CValue( unsigned long ulValue );     
    // Construct define
    CValue( unsigned int uiValue );      
    // Construct define
    CValue( int iValue );                
    // Construct define
    CValue( double dValue );             
    // Construct define
    CValue( float fValue );              
    // Destruct define
	virtual ~CValue(){};                 

/////////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    // ת�����ַ���
    const char* ToString();             
    // ת���ɶ������ַ���
    const char* ToBitStr();             
    // ת����ʮ�������ַ���
    const char* ToHexStr();             

    // ��ȡ�ַ�������
    const size_t Size(); 
    // ��ȡ�������ַ�������
    const size_t SizeForBit();
    // ��ȡʮ�������ַ�������
    const size_t SizeForHex();


}; // End of class CValue
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CVALUE_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CValue.h
/////////////////////////////////////////////////////////////////////////////////////////
