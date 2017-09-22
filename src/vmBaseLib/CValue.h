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
//        Notes : 此类包含了有关类型转换的一些操作
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
    } munValue;                                     // 数值
    char mszBuf[_MAX_VALUE_BUF_];                   // 字符串缓存
    size_t mstLen;                                  // 字符串长度
    char mszBufForBit[_MAX_VALUE_BUF_];             // 数值二进制字符串缓存
    size_t mstLenForBit;                            // 数值二进制字符串长度
    char mszBufForHex[_MAX_VALUE_BUF_];             // 数值十六进制字符串缓存
    size_t mstLenForHex;                            // 数值十六进制字符串长度

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
    // 转换成字符串
    const char* ToString();             
    // 转换成二进制字符串
    const char* ToBitStr();             
    // 转换成十六进制字符串
    const char* ToHexStr();             

    // 获取字符串长度
    const size_t Size(); 
    // 获取二进制字符串长度
    const size_t SizeForBit();
    // 获取十六进制字符串长度
    const size_t SizeForHex();


}; // End of class CValue
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CVALUE_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CValue.h
/////////////////////////////////////////////////////////////////////////////////////////
