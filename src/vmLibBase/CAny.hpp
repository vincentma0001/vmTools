/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CAny.hpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/05 08:24:26
// Modify time  : 2020/01/05 08:24:26
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

#ifndef __CANY_HPP__
#define __CANY_HPP__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :

#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>
#endif // __VM_CFG_H__

#ifndef   __VM_UTIL_H__
#	error this file need #include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :

#define vSizeOfBool    vm::CAny<0>()::size_bool()
#define vSizeOfChar    vm::CAny<0>()::size_char()
#define vSizeOfUChar   vm::CAny<0>()::size_uchar()
#define vSizeOfShort   vm::CAny<0>()::size_short()
#define vSizeOfUShort  vm::CAny<0>()::size_ushort()
#define vSizeOfInt     vm::CAny<0>()::size_int()
#define vSizeOfUInt    vm::CAny<0>()::size_uint()
#define vSizeOfLong    vm::CAny<0>()::size_long()
#define vSizeOfULong   vm::CAny<0>()::size_ulong()
#define vSizeOfLLong   vm::CAny<0>()::size_llong()
#define vSizeOfULLong  vm::CAny<0>()::size_ullong()
#define vSizeOfFloat   vm::CAny<0>()::size_float()
#define vSizeOfDouble  vm::CAny<0>()::size_double()
#define vSizeOfLDouble vm::CAny<0>()::size_ldouble()

#define vCAnyFmChar   ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_char()
#define vCAnyFmShort  ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_short()
#define vCAnyFmUShort ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_ushort()
#define vCAnyFmInt    ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_int()
#define vCAnyFmUInt   ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_uint()
#define vCAnyFmLong   ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_long()
#define vCAnyFmULong  ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_ulong()
#define vCAnyFmLLong  ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_llong()
#define vCAnyFmULLong ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_ullong()
#define vCAnyFmFloat  ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_float()
#define vCAnyFmDouble ( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_double()
#define vCAnyFmLDouble( sztBufSize, Value ) vm::CAny<sztBufSize>( Value ).s_ldouble()

#define vCAnyToInt    ( sztBufSize, szValue ) vm::CAny<sztBufSize>( szValue ).toInt()
#define vCAnyToFloat  ( sztBufSize, szValue ) vm::CAny<sztBufSize>( szValue ).toFloat()
#define vCAnyToLong   ( sztBufSize, szValue ) vm::CAny<sztBufSize>( szValue ).toLong()
#define vCAnyToULong  ( sztBufSize, szValue ) vm::CAny<sztBufSize>( szValue ).toULong()
#define vCAnyToLLong  ( sztBufSize, szValue ) vm::CAny<sztBufSize>( szValue ).toLLong()
#define vCAnyToULLong ( sztBufSize, szValue ) vm::CAny<sztBufSize>( szValue ).toULLong()
#define vCAnyToDouble ( sztBufSize, szValue ) vm::CAny<sztBufSize>( szValue ).toDouble()
#define vCAnyToLDouble( sztBufSize, szValue ) vm::CAny<sztBufSize>( szValue ).toLDouble()

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CAny : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template<size_t sztBufSize>
class CAny
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
public:
    // 数据类型
    typedef enum  emType
    {
        emBool      = 0,

        emChar      = 1,
        emUChar     = 2,

        emWChar     = 3,

        emShort     = 4,
        emUShort    = 5,

        emInt       = 6,
        emUInt      = 7,

        emLong      = 8,
        emULong     = 9,

        emLLong     = 10,
        emULLong    = 11,

        emFloat     = 12,
        emDouble    = 13,
        emLDouble   = 14,

        emStr       = 99
    } *PEMT;

    // 数据存储类型
    typedef union unValue
    {
        bool                bValue;
    
        char                cValue;
        unsigned char       ucValue;

        wchar_t             wcValue;

        short               sValue;
        unsigned short      usValue;

        int                 iValue;
        unsigned int        uiValue;

        long                lValue;
        unsigned long       ulValue;

        long long           llValue;
        unsigned long long  ullValue;

        float               fValue;
        double              dValue;
        long double         ldValue;

    } UNVALUE, *PUNVALUE;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CAny(const bool               cVal ) :memType(emType::emBool)   { munValue.bValue   = cVal; vMemZero(mszBuf); };
    explicit CAny(const char               cVal ) :memType(emType::emChar)   { munValue.cValue   = cVal; vMemZero(mszBuf); };
    explicit CAny(const unsigned char      cVal ) :memType(emType::emUChar)  { munValue.ucValue  = cVal; vMemZero(mszBuf); };
    explicit CAny(const wchar_t            cVal ) :memType(emType::emWChar)  { munValue.wcValue  = cVal; vMemZero(mszBuf); };
    explicit CAny(const short              cVal ) :memType(emType::emShort)  { munValue.sValue   = cVal; vMemZero(mszBuf); };
    explicit CAny(const unsigned short     cVal ) :memType(emType::emUShort) { munValue.usValue  = cVal; vMemZero(mszBuf); };
    explicit CAny(const int                cVal ) :memType(emType::emInt)    { munValue.iValue   = cVal; vMemZero(mszBuf); };
    explicit CAny(const unsigned int       cVal ) :memType(emType::emUInt)   { munValue.uiValue  = cVal; vMemZero(mszBuf); };
    explicit CAny(const long               cVal ) :memType(emType::emLong)   { munValue.lValue   = cVal; vMemZero(mszBuf); };
    explicit CAny(const unsigned long      cVal ) :memType(emType::emULong)  { munValue.ulValue  = cVal; vMemZero(mszBuf); };
    explicit CAny(const long long          cVal ) :memType(emType::emLLong)  { munValue.llValue  = cVal; vMemZero(mszBuf); };
    explicit CAny(const unsigned long long cVal ) :memType(emType::emULLong) { munValue.ullValue = cVal; vMemZero(mszBuf); };
    explicit CAny(const float              cVal ) :memType(emType::emFloat)  { munValue.fValue   = cVal; vMemZero(mszBuf); };
    explicit CAny(const double             cVal ) :memType(emType::emDouble) { munValue.dValue   = cVal; vMemZero(mszBuf); };
    explicit CAny(const long double        cVal ) :memType(emType::emLDouble){ munValue.ldValue  = cVal; vMemZero(mszBuf); };

    explicit CAny(const tchar* const      cpValue) :memType(emType::emStr) { vMemZero(mszBuf); v_memcpy(mszBuf, sizeof(mszBuf), cpValue, vStrlen(cpValue)); };
    // Destruct define
    virtual ~CAny() {};
    
private:
    // No Copy
    CAny(const CAny& obj){};
    // No Assignment
    CAny& operator = ( const CAny& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    // 需要被转换的数据
    unValue         munValue;
    // 数据类型
    emType          memType;
    // 转义后字符串缓存
    tchar           mszBuf[sztBufSize];

    // 错误代码
    unsigned long   mulErrCode;

public:
    bool HasError(){ return mulErrCode==0?true:false; };
    unsigned long toErrCode(){ return mulErrCode; };

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 基础数据类型长度
    static size_t size_bool()   { return sizeof(bool);          };
    static size_t size_uchar()  { return sizeof(unsigned char); };
    static size_t size_char()   { return sizeof(char);          };
    static size_t size_wchar()  { return sizeof(wchar_t);       };
    static size_t size_short()  { return sizeof(short);         };
    static size_t size_ushort() { return sizeof(unsigned short);};
    static size_t size_int()    { return sizeof(int);           };
    static size_t size_uint()   { return sizeof(unsigned int);  };
    static size_t size_long()   { return sizeof(long);          };
    static size_t size_ulong()  { return sizeof(unsigned long); };
    static size_t size_llong()  { return sizeof(long long);     };
    static size_t size_ullong() { return sizeof(unsigned long long); };
    static size_t size_float()  { return sizeof(float);         };
    static size_t size_double() { return sizeof(double);        };
    static size_t size_ldouble(){ return sizeof(long double);   };

    // 将字符串数据转换到相应的类型
    static int                toInt    ( const tchar* const cpValue );
    static float              toFloat  ( const tchar* const cpValue );
    static long               toLong   ( const tchar* const cpValue );
    static unsigned long      toULong  ( const tchar* const cpValue );
    static long long          toLLong  ( const tchar* const cpValue );
    static unsigned long long toULLong ( const tchar* const cpValue );
    static double             toDouble ( const tchar* const cpValue );
    static long double        toLDouble( const tchar* const cpValue );

public:
    // 转译后字符串的长度
    inline size_t len()     { return strlen(mszBuf); };
    // 返回缓存区大小
    inline size_t size()    { return sizeof(mszBuf); };
    // 获取当前字符串
    inline tchar*  str()     { return mszBuf;         };
    // 返回数据类型
    inline emType anyType() { return memType;        };

    // 判读数据类型
    inline bool isBool()   { memType==emType::emBool    ? true:false; };
    inline bool isChar()   { memType==emType::emChar    ? true:false; };
    inline bool isUChar()  { memType==emType::emUChar   ? true:false; };
    inline bool isShort()  { memType==emType::emShort   ? true:false; };
    inline bool isUShort() { memType==emType::emUShort  ? true:false; };
    inline bool isInt()    { memType==emType::emInt     ? true:false; };
    inline bool isUInt()   { memType==emType::emUInt    ? true:false; };
    inline bool isLong()   { memType==emType::emLong    ? true:false; };
    inline bool isULong()  { memType==emType::emULong   ? true:false; };
    inline bool isLLong()  { memType==emType::emLLong   ? true:false; };
    inline bool isULLong() { memType==emType::emULLong  ? true:false; };
    inline bool isFloat()  { memType==emType::emFloat   ? true:false; };
    inline bool isDouble() { memType==emType::emDouble  ? true:false; };
    inline bool isLDouble(){ memType==emType::emLDouble ? true:false; };

public:
    // 字符串输出数据
    inline tchar* s_bool()   { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%s"),  munValue.bValue==true?"true":"false");   return mszBuf; };
    inline tchar* s_char( const tchar* const cpPrototype=nullptr)   { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%hhd"),  munValue.cValue);   return mszBuf; };
    inline tchar* s_uchar()  { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%hhu"),  munValue.ucValue);  return mszBuf; };
    inline tchar* s_short()  { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%hi"), munValue.sValue);   return mszBuf; };
    inline tchar* s_ushort() { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%hu"), munValue.usValue);  return mszBuf; };
    inline tchar* s_int()    { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%li"), munValue.iValue);   return mszBuf; };
    inline tchar* s_uint()   { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%lu"), munValue.uiValue);  return mszBuf; };
    inline tchar* s_long()   { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%li"), munValue.lValue);   return mszBuf; };
    inline tchar* s_ulong()  { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%lu"), munValue.ulValue);  return mszBuf; };
    inline tchar* s_llong()  { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%Li"), munValue.llValue);  return mszBuf; };
    inline tchar* s_ullong() { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%Lu"), munValue.ullValue); return mszBuf; };
    inline tchar* s_float()  { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%hf"), munValue.fValue);   return mszBuf; };
    inline tchar* s_double() { vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%lf"), munValue.dValue);   return mszBuf; };
    inline tchar* s_ldouble(){ vMemZero(mszBuf); v_sprintf(mszBuf, sztBufSize, vT("%Lf"), munValue.dValue);   return mszBuf; };

public:
    inline bool               toBool()   { return munValue.bValue;   };
    inline bool               toSBool()  { return v_strcmp_equl(mszBuf,"true");};
    inline int                toInt()    { return toInt(mszBuf);     };
    inline long               toLong()   { return toLong(mszBuf);    };
    inline unsigned long      toULong()  { return toULong(mszBuf);   };
    inline long long          toLLong()  { return toLLong(mszBuf);   };
    inline unsigned long long toULLong() { return toULLong(mszBuf);  };
    inline float              toFloat()  { return toFloat(mszBuf);   };
    inline double             toDouble() { return toDouble(mszBuf);  };
    inline long double        toLDouble(){ return toLDouble(mszBuf); };

}; // End of class CAny
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toFloat(...)
// Brief     :
// Return    : float
template<size_t sztBufSize>
int CAny<sztBufSize>::toInt(const tchar* const cpValue)
{
    tchar* lpEnd = 0;
    return vStol(cpValue, lpEnd, 10);
}
// End of function toFloat(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toFloat(...)
// Brief     :
// Return    : float
template<size_t sztBufSize>
float CAny<sztBufSize>::toFloat(const tchar* const cpValue)
{
    tchar* lpEnd = 0;
    float lfRet = vStof(cpValue, &lpEnd);
    // #  TODO : Add condition brife here ##
    if ( errno == 0 )
        return lfRet;

    mulErrCode = errno;
    return vMaxFloat;
}
// End of function toFloat(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toLong(...)
// Brief     :
// Return    : long
template<size_t sztBufSize>
long CAny<sztBufSize>::toLong(const tchar* const cpValue)
{
    tchar* lpEnd = 0;
    long llRet = vStol(cpValue, &lpEnd, 0);
    if (errno == 0)
        return llRet;

    mulErrCode = errno;
    return vMaxsLong;
}
// End of function toLong(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toULong(...)
// Brief     :
// Return    : unsigned long
template<size_t sztBufSize>
unsigned long CAny<sztBufSize>::toULong(const tchar* const cpValue)
{
    tchar* lpEnd = 0;
    unsigned long lulRet = vStoul(cpValue, &lpEnd, 0);
    if (errno == 0)
        return lulRet;

    mulErrCode = errno;
    return vMaxuLong;
}
// End of function toULong(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toLLong(...)
// Brief     :
// Return    : long long
template<size_t sztBufSize>
long long CAny<sztBufSize>::toLLong(const tchar* const cpValue)
{
    tchar* lpEnd = 0;
    long long lllRet = vStoll(cpValue, &lpEnd, 0);
    if (errno == 0)
        return lllRet;

    mulErrCode = errno;
    return vMaxsLLong;
}
// End of function toLLong(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toULLong(...)
// Brief     :
// Return    : unsigned long long
template<size_t sztBufSize>
unsigned long long CAny<sztBufSize>::toULLong(const tchar* const cpValue)
{
    tchar* lpEnd = 0;
    unsigned long long lullRet = vStoull(cpValue, &lpEnd, 0);
    if (errno == 0)
        return lullRet;

    mulErrCode = errno;
    return vMaxuLLong;
}
// End of function toULLong(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toDouble(...)
// Brief     :
// Return    : double
template<size_t sztBufSize>
double CAny<sztBufSize>::toDouble(const tchar* const cpValue)
{
    tchar* lpEnd = 0;
    double ldRet = vStod(cpValue, &lpEnd);
    if (errno == 0)
        return ldRet;

    mulErrCode = errno;
    return vMaxDouble;
}
// End of function toDouble(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toLDouble(...)
// Brief     :
// Return    : long double
template<size_t sztBufSize>
long double CAny<sztBufSize>::toLDouble(const tchar* const cpValue)
{
    tchar* lpEnd = 0;
    long double lldRet = vStold(cpValue, &lpEnd);
    if (errno == 0)
        return lldRet;

    mulErrCode = errno;
    return vMaxDouble;
}
// End of function toLDouble(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CANY_HPP__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CAny.hpp
/////////////////////////////////////////////////////////////////////////////////////////