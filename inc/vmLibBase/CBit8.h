/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CBit8.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2019/12/30 11:28:44
// Modify time  : 2019/12/30 11:28:44
// Note 		:
//
//          位操作总结
//                  1. 位与运算符(&)
//                      例：00000011 & 00000101 = 00000001
//                  2. 位或运算符(|)
//                      例：00000011 | 00000101 = 00000111
//                  3. 位异或运算符(^)
//                      例：00000011 | 00000101 = 00000110
//                  4. 位取反运算符(~)
//                      例：~00000101 = 11111010
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

#ifndef __CBIT8_H__
#define __CBIT8_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :

#ifndef   __VM_UTIL_H__
#	error this file need #include <vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Types define :
typedef struct stBit8
{
    unsigned int  bit00 : 1;
    unsigned int  bit01 : 1;
    unsigned int  bit02 : 1;
    unsigned int  bit03 : 1;
    unsigned int  bit04 : 1;
    unsigned int  bit05 : 1;
    unsigned int  bit06 : 1;
    unsigned int  bit07 : 1;
} STBIT8, *PSTBIT8;

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :

#define _V_CBIT8_POS_00_  0x00
#define _V_CBIT8_POS_01_  0x01
#define _V_CBIT8_POS_02_  0x02
#define _V_CBIT8_POS_03_  0x04
#define _V_CBIT8_POS_04_  0x08
#define _V_CBIT8_POS_05_  0x10
#define _V_CBIT8_POS_06_  0x20
#define _V_CBIT8_POS_07_  0x40
#define _V_CBIT8_POS_08_  0x80
#define _V_CBIT8_POS_FF_  0xFF

#define _V_CBIT8_MAX_BUF_ 9

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit8 : 此类封装了8位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit8
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CBit8(char          cVal) :mBit(cVal) {};
    inline explicit CBit8(unsigned char cVal) :mBit(cVal) {};
    // Destruct define
    inline virtual ~CBit8(){};
    
public:
    // Copy construct define
    inline CBit8(const CBit8& obj):mBit(obj.mBit){};
    // Assignment define
    inline CBit8& operator = ( const CBit8& obj ){ mBit = obj.mBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit8& operator&(const CBit8& obj) { mBit = mBit&obj.mBit; return *this; };
    inline CBit8& operator&(const char  cVal) { mBit = mBit&cVal;      return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit8& operator|(const CBit8& obj) { mBit = mBit|obj.mBit; return *this; };
    inline CBit8& operator|(const char  cVal) { mBit = mBit|cVal;      return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit8& operator^(const CBit8& obj) { mBit = mBit^obj.mBit; return *this; };
    inline CBit8& operator^(const char  cVal) { mBit = mBit^cVal;      return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit8& operator~() { mBit = ~mBit; return *this; };
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members
private:
    unsigned char  mBit;
    char           mszBuf[_V_CBIT8_MAX_BUF_];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前值
    inline char          toChar () { return mBit; };
    inline unsigned char toUChar() { return mBit; };
    
    inline void clear(){ mBit=0;vMemZero(mszBuf); };

    // 设置bit值
    inline void Set(const char          cVal) {mBit=cVal;};
    inline void Set(const unsigned char cVal) {mBit=cVal;};

    inline void Set01() { ((PSTBIT8)&mBit)->bit00 = 1; };
    inline void Set02() { ((PSTBIT8)&mBit)->bit01 = 1; };
    inline void Set03() { ((PSTBIT8)&mBit)->bit02 = 1; };
    inline void Set04() { ((PSTBIT8)&mBit)->bit03 = 1; };
    inline void Set05() { ((PSTBIT8)&mBit)->bit04 = 1; };
    inline void Set06() { ((PSTBIT8)&mBit)->bit05 = 1; };
    inline void Set07() { ((PSTBIT8)&mBit)->bit06 = 1; };
    inline void Set08() { ((PSTBIT8)&mBit)->bit07 = 1; };

    // 取消bit值设置
    inline void unSet(const char          cVal) { mBit = cVal; };
    inline void unSet(const unsigned char cVal) { mBit = cVal; };

    inline void unSet01() { ((PSTBIT8)&mBit)->bit00 = 0; };
    inline void unSet02() { ((PSTBIT8)&mBit)->bit01 = 0; };
    inline void unSet03() { ((PSTBIT8)&mBit)->bit02 = 0; };
    inline void unSet04() { ((PSTBIT8)&mBit)->bit03 = 0; };
    inline void unSet05() { ((PSTBIT8)&mBit)->bit04 = 0; };
    inline void unSet06() { ((PSTBIT8)&mBit)->bit05 = 0; };
    inline void unSet07() { ((PSTBIT8)&mBit)->bit06 = 0; };
    inline void unSet08() { ((PSTBIT8)&mBit)->bit07 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const char cVal)   { mBit&cVal?true:false; };

    inline bool isSet01() { return (((PSTBIT8)&mBit)->bit00&1)?true:false; };
    inline bool isSet02() { return (((PSTBIT8)&mBit)->bit01&1)?true:false; };
    inline bool isSet03() { return (((PSTBIT8)&mBit)->bit02&1)?true:false; };
    inline bool isSet04() { return (((PSTBIT8)&mBit)->bit03&1)?true:false; };
    inline bool isSet05() { return (((PSTBIT8)&mBit)->bit04&1)?true:false; };
    inline bool isSet06() { return (((PSTBIT8)&mBit)->bit05&1)?true:false; };
    inline bool isSet07() { return (((PSTBIT8)&mBit)->bit06&1)?true:false; };
    inline bool isSet08() { return (((PSTBIT8)&mBit)->bit07&1)?true:false; };

    // 以二进制方式返回bit值字符串
    inline char* toBin( )
    {
        vMemZero(mszBuf);
        char* lpPos = mszBuf;
        for (int i = 7; i >= 0; i--)
        {
            (*lpPos) = ((mBit >> i) & 1) ? '1' : '0';;
            lpPos++;
        }
        return mszBuf;
    };
    // 以八进制方式返回bit值字符串
    inline char* toOct( )
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf( mszBuf, sizeof(mszBuf), "%04o", mBit);
        return mszBuf;
    };
    // 以十进制方式返回bit值字符串
    inline char* toDec( )
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%04d", (char)mBit);
        return mszBuf;
    };
    inline char* toUDec()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%04u", mBit);
        return mszBuf;
    };
    // 以十六进制方式返回bit值字符串
    inline char* toHex( )
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%02X", mBit);
        return mszBuf;
    };

}; // End of class CBit8
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit8Ptr : 此类封装了8位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit8Ptr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CBit8Ptr(char* const cpVal) :mpBit((unsigned char*)cpVal) {};
    inline explicit CBit8Ptr(unsigned char* const cpVal) :mpBit(cpVal) {};
    inline explicit CBit8Ptr(char& cVal) :mpBit((unsigned char*)&cVal) {};
    inline explicit CBit8Ptr(unsigned char& cVal) :mpBit(&cVal) {};
    // Destruct define
    inline virtual ~CBit8Ptr() {};

public:
    // Copy construct define
    inline CBit8Ptr(const CBit8Ptr& obj) :mpBit(obj.mpBit) {};
    // Assignment define
    inline CBit8Ptr& operator = (const CBit8Ptr& obj) { *mpBit = *obj.mpBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit8Ptr& operator&(const CBit8Ptr& obj) { *mpBit = *mpBit & *obj.mpBit; return *this; };
    inline CBit8Ptr& operator&(const char  cVal)    { *mpBit = *mpBit & cVal;       return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit8Ptr& operator|(const CBit8Ptr& obj) { *mpBit = *mpBit | *obj.mpBit; return *this; };
    inline CBit8Ptr& operator|(const char  cVal)    { *mpBit = *mpBit | cVal;       return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit8Ptr& operator^(const CBit8Ptr& obj) { *mpBit = *mpBit ^ *obj.mpBit; return *this; };
    inline CBit8Ptr& operator^(const char  cVal)    { *mpBit = *mpBit ^ cVal;       return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit8Ptr& operator~()                    { *mpBit = ~*mpBit; return *this; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members
private:
    unsigned char*  mpBit;
    char            mszBuf[_V_CBIT8_MAX_BUF_];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前值
    inline char          toChar()  { return *mpBit; };
    inline unsigned char toUChar() { return *mpBit; };

    inline void clear() { *mpBit = 0; vMemZero(mszBuf); };

    // 设置bit值
    inline void Set(const char          cVal) { *mpBit = cVal; };
    inline void Set(const unsigned char cVal) { *mpBit = cVal; };

    inline void Set01() { ((PSTBIT8)mpBit)->bit00 = 1; };
    inline void Set02() { ((PSTBIT8)mpBit)->bit01 = 1; };
    inline void Set03() { ((PSTBIT8)mpBit)->bit02 = 1; };
    inline void Set04() { ((PSTBIT8)mpBit)->bit03 = 1; };
    inline void Set05() { ((PSTBIT8)mpBit)->bit04 = 1; };
    inline void Set06() { ((PSTBIT8)mpBit)->bit05 = 1; };
    inline void Set07() { ((PSTBIT8)mpBit)->bit06 = 1; };
    inline void Set08() { ((PSTBIT8)mpBit)->bit07 = 1; };

    // 取消bit值设置
    inline void unSet(const char          cVal) { *mpBit = cVal; };
    inline void unSet(const unsigned char cVal) { *mpBit = cVal; };

    inline void unSet01() { ((PSTBIT8)mpBit)->bit00 = 0; };
    inline void unSet02() { ((PSTBIT8)mpBit)->bit01 = 0; };
    inline void unSet03() { ((PSTBIT8)mpBit)->bit02 = 0; };
    inline void unSet04() { ((PSTBIT8)mpBit)->bit03 = 0; };
    inline void unSet05() { ((PSTBIT8)mpBit)->bit04 = 0; };
    inline void unSet06() { ((PSTBIT8)mpBit)->bit05 = 0; };
    inline void unSet07() { ((PSTBIT8)mpBit)->bit06 = 0; };
    inline void unSet08() { ((PSTBIT8)mpBit)->bit07 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const char cVal) { (*mpBit)&cVal ? true : false; };

    inline bool isSet01() { return (((PSTBIT8)mpBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((PSTBIT8)mpBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((PSTBIT8)mpBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((PSTBIT8)mpBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((PSTBIT8)mpBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((PSTBIT8)mpBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((PSTBIT8)mpBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((PSTBIT8)mpBit)->bit07 & 1) ? true : false; };

    // 以二进制方式返回bit值字符串
    inline char* toBin()
    {
        vMemZero(mszBuf);
        char* lpPos = mszBuf;
        for (int i = 7; i >= 0; i--)
        {
            (*lpPos) = ((*mpBit >> i) & 1) ? '1' : '0';;
            lpPos++;
        }
        return mszBuf;
    };
    // 以八进制方式返回bit值字符串
    inline char* toOct()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%04o", *mpBit);
        return mszBuf;
    };
    // 以十进制方式返回bit值字符串
    inline char* toDec()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%04d", *mpBit);
        return mszBuf;
    };
    // 以十六进制方式返回bit值字符串
    inline char* toHex()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%02X", *mpBit);
        return mszBuf;
    };

}; // End of class CBit8Ptr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CBIT8_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit8.h
/////////////////////////////////////////////////////////////////////////////////////////