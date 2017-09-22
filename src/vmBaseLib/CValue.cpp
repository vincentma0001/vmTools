/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CValue.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 23/1/2016 9:46:18
// Modify time 	: 23/1/2016 9:46:18
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CValue.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CValue
// Full name : CValue::CValue
// Access    : public 
// Brief     : ���캯��
// Parameter : unsigned long ulValue                                    -- ��ת������ֵ
// Return    : 
// Notes     : 
CValue::CValue(unsigned long ulValue)
{
    memset( &munValue, 0, sizeof(munValue) );
    memset( mszBuf, 0, _MAX_VALUE_BUF_ );

    munValue.ulValue = ulValue;
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    sprintf( mszBuf, "%u", ulValue );
#else
    sprintf_s( mszBuf, _MAX_VALUE_BUF_, "%u", ulValue );
#endif

    mstLen= strlen(mszBuf);
} // End of function CValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CValue
// Full name : CValue::CValue
// Access    : public 
// Brief     : ���캯��
// Parameter : unsigned int uiValue                                    -- ��ת������ֵ
// Return    : 
// Notes     : 
CValue::CValue(unsigned int uiValue)
{
    memset( &munValue, 0, sizeof(munValue) );
    memset( mszBuf, 0, _MAX_VALUE_BUF_ );

    munValue.uiValue = uiValue;
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    sprintf( mszBuf, "%u", uiValue );
#else
    sprintf_s( mszBuf, _MAX_VALUE_BUF_, "%u", uiValue );
#endif

    mstLen= strlen(mszBuf);
} // End of function CValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CValue
// Full name : CValue::CValue
// Access    : public 
// Brief     : ���캯��
// Parameter : int iValue                                             -- ��ת������ֵ
// Return    : 
// Notes     : 
CValue::CValue(int iValue)
{
    memset( &munValue, 0, sizeof(munValue) );
    memset( mszBuf, 0, _MAX_VALUE_BUF_ );

    munValue.iValue = iValue;
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    sprintf( mszBuf, "%d", iValue );
#else
    sprintf_s( mszBuf, _MAX_VALUE_BUF_, "%d", iValue );
#endif

    mstLen= strlen(mszBuf);
} // End of function CValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CValue
// Full name : CValue::CValue
// Access    : public 
// Brief     : ���캯��
// Parameter : double dValue                                         -- ��ת������ֵ
// Return    : 
// Notes     : 
CValue::CValue(double dValue)
{
    memset( &munValue, 0, sizeof(munValue) );
    memset( mszBuf, 0, _MAX_VALUE_BUF_ );

    munValue.dValue = dValue;
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    sprintf( mszBuf, "%lf", dValue );
#else
    sprintf_s( mszBuf, _MAX_VALUE_BUF_, "%lf", dValue );
#endif

    mstLen= strlen(mszBuf);
} // End of function CValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CValue
// Full name : CValue::CValue
// Access    : public 
// Brief     : ���캯��
// Parameter : float fValue                                         -- ��ת������ֵ
// Return    : 
// Notes     : 
CValue::CValue(float fValue)
{
    memset( &munValue, 0, sizeof(munValue) );
    memset( mszBuf, 0, _MAX_VALUE_BUF_ );

    munValue.fValue = fValue;
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    sprintf( mszBuf, "%f", fValue );
#else
    sprintf_s( mszBuf, _MAX_VALUE_BUF_, "%f", fValue );
#endif

    mstLen= strlen(mszBuf);
} // End of function CValue(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Size
// Full name : CValue::Size
// Access    : public 
// Brief     : ��ȡ�ַ�������
// Parameter : 
// Return    : const size_t                                         -- �ַ�������
// Notes     : 
const size_t CValue::Size()
{
    return mstLen;
} // End of function Size(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CValue::ToString
// Access    : public 
// Brief     : ��ȡ��ֵ�ַ���
// Parameter : 
// Return    : const char*                                          -- ת������ַ���
// Notes     : 
const char* CValue::ToString()
{
    return mszBuf;
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ToBitStr
// Full name : CValue::ToBitStr
// Access    : public 
// Brief     : ��ȡ�������ַ���
// Parameter : 
// Return    : const char*                                          -- ת����Ķ������ַ���
// Notes     : 
const char* CValue::ToBitStr()
{
    memset( mszBuf, 0x00, _MAX_VALUE_BUF_);
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    itoa( munValue.ulValue, mszBufForBit, 2 );
#else
    _itoa_s( munValue.ulValue, mszBufForBit, _MAX_VALUE_BUF_, 2 );
#endif
    
    mstLen=strlen(mszBufForBit);
    return mszBufForBit;
} // End of function ToBitStr(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ToHexStr
// Full name : CValue::ToHexStr
// Access    : public 
// Brief     : ��ȡʮ�������ַ���
// Parameter : 
// Return    : const char*                                          -- ת�����ʮ�������ַ���
// Notes     : 
const char* CValue::ToHexStr()
{
    memset( mszBuf, 0x00, _MAX_VALUE_BUF_);
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    itoa( munValue.ulValue, mszBufForHex, 16 );
#else
    _itoa_s( munValue.ulValue, mszBufForHex, _MAX_VALUE_BUF_, 16 );
#endif

    mstLen= strlen(mszBufForHex);
    return mszBufForHex;
} // End of function ToHexStr(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CValue.cpp
/////////////////////////////////////////////////////////////////////////////////////////