/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CBit08.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/04/16 10:09:29
// Modify time  : 2020/04/16 10:09:29
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

#ifndef __CBIT08_H__
#define __CBIT08_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit08 : 此类封装了8位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit08
{
/////////////////////////////////////////////////////////////////////////////////////////
// Types define :
public:
    typedef struct stBit08
    {
        unsigned int  bit00 : 1;
        unsigned int  bit01 : 1;
        unsigned int  bit02 : 1;
        unsigned int  bit03 : 1;
        unsigned int  bit04 : 1;
        unsigned int  bit05 : 1;
        unsigned int  bit06 : 1;
        unsigned int  bit07 : 1;
    };

    typedef enum emBitPos
    {
        PosFF = 0xFF,
        Pos00 = 0x00,

        Pos01 = 0x01,
        Pos02 = 0x02,
        Pos03 = 0x04,
        Pos04 = 0x08,
        Pos05 = 0x10,
        Pos06 = 0x20,
        Pos07 = 0x40,
        Pos08 = 0x80
    };

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline CBit08(char&          cVal) :mBit(*((unsigned char*)&cVal)) {};
    inline CBit08(unsigned char& cValue):mBit(cValue){};

    // Destruct define
    virtual ~CBit08() {};

public:
    // Copy construct define
    inline CBit08(const CBit08& obj) :mBit(obj.mBit){};
    // Assignment define
    inline CBit08& operator = (const CBit08& obj) { mBit = obj.mBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit08& operator&(const CBit08&  obj) { mBit = mBit & obj.mBit; return *this; };
    inline CBit08& operator&(const tchar   cVal) { mBit = mBit & cVal;     return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit08& operator|(const CBit08&  obj) { mBit = mBit | obj.mBit; return *this; };
    inline CBit08& operator|(const tchar   cVal) { mBit = mBit | cVal;     return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit08& operator^(const CBit08&  obj) { mBit = mBit ^ obj.mBit; return *this; };
    inline CBit08& operator^(const tchar   cVal) { mBit = mBit ^ cVal;     return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit08& operator~()                   { mBit = ~mBit;           return *this; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
protected:
    unsigned char&  mBit;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前Bit类内存大小
    inline unsigned int  size ()   { return sizeof(mBit); };
    // 重置Bit数值
    inline void          reset()   { mBit = 0;            };

    // 返回当前值
    inline char          toChar()  { return (char)mBit; };
    inline unsigned char toUChar() { return       mBit; };

    // 设置bit值
    inline void Set(const char          cVal) { mBit = cVal; };
    inline void Set(const unsigned char cVal) { mBit = cVal; };

    inline void Set01() { ((stBit08*)&mBit)->bit00 = 1; };
    inline void Set02() { ((stBit08*)&mBit)->bit01 = 1; };
    inline void Set03() { ((stBit08*)&mBit)->bit02 = 1; };
    inline void Set04() { ((stBit08*)&mBit)->bit03 = 1; };
    inline void Set05() { ((stBit08*)&mBit)->bit04 = 1; };
    inline void Set06() { ((stBit08*)&mBit)->bit05 = 1; };
    inline void Set07() { ((stBit08*)&mBit)->bit06 = 1; };
    inline void Set08() { ((stBit08*)&mBit)->bit07 = 1; };

    // 取消bit值设置
    inline void unSet(const char          cVal) { mBit = cVal; };
    inline void unSet(const unsigned char cVal) { mBit = cVal; };

    inline void unSet01() { ((stBit08*)&mBit)->bit00 = 0; };
    inline void unSet02() { ((stBit08*)&mBit)->bit01 = 0; };
    inline void unSet03() { ((stBit08*)&mBit)->bit02 = 0; };
    inline void unSet04() { ((stBit08*)&mBit)->bit03 = 0; };
    inline void unSet05() { ((stBit08*)&mBit)->bit04 = 0; };
    inline void unSet06() { ((stBit08*)&mBit)->bit05 = 0; };
    inline void unSet07() { ((stBit08*)&mBit)->bit06 = 0; };
    inline void unSet08() { ((stBit08*)&mBit)->bit07 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const char cVal) { (mBit)&cVal ? true : false; };

    inline bool isSet01() { return (((stBit08*)&mBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((stBit08*)&mBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((stBit08*)&mBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((stBit08*)&mBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((stBit08*)&mBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((stBit08*)&mBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((stBit08*)&mBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((stBit08*)&mBit)->bit07 & 1) ? true : false; };

/////////////////////////////////////////////////////////////////////////////////////////
// Friends define: 
friend class CBitStr;

}; // End of class CBit08
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CBIT08_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit08.h
/////////////////////////////////////////////////////////////////////////////////////////