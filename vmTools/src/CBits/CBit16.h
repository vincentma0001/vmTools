/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CBit16.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/06 00:51:35
// Modify time 	: 2020/01/06 00:51:35
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

#ifndef __CBIT16_H__
#define __CBIT16_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>
#endif // __VM_CFG_H__

// Platform files included

// Used files included
#ifndef   __VM_UTIL_H__
#	error this file need #include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{


/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit16 : 此类封装了16位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit16
{
/////////////////////////////////////////////////////////////////////////////////////////
// Types define :
public:
    typedef struct stBit16
    {
        unsigned int  bit00 : 1;
        unsigned int  bit01 : 1;
        unsigned int  bit02 : 1;
        unsigned int  bit03 : 1;
        unsigned int  bit04 : 1;
        unsigned int  bit05 : 1;
        unsigned int  bit06 : 1;
        unsigned int  bit07 : 1;

        unsigned int  bit08 : 1;
        unsigned int  bit09 : 1;
        unsigned int  bit10 : 1;
        unsigned int  bit11 : 1;
        unsigned int  bit12 : 1;
        unsigned int  bit13 : 1;
        unsigned int  bit14 : 1;
        unsigned int  bit15 : 1;
    };

    typedef enum emBitPos
    {
        PosFF = 0xFFFF,
        Pos00 = 0x0000,

        Pos01 = 0x0001,
        Pos02 = 0x0002,
        Pos03 = 0x0004,
        Pos04 = 0x0008,
        Pos05 = 0x0010,
        Pos06 = 0x0020,
        Pos07 = 0x0040,
        Pos08 = 0x0080,

        Pos09 = 0x0100,
        Pos10 = 0x0200,
        Pos11 = 0x0400,
        Pos12 = 0x0800,
        Pos13 = 0x1000,
        Pos14 = 0x2000,
        Pos15 = 0x4000,
        Pos16 = 0x8000
    };

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline CBit16(short&          cVal) :mBit(*((unsigned short*)&cVal)) {};
    inline CBit16(unsigned short& cVal) :mBit(cVal) {};
    // Destruct define
    inline virtual ~CBit16() {};

public:
    // Copy construct define
    inline CBit16(const CBit16& obj) :mBit(obj.mBit) {};
    // Assignment define
    inline CBit16& operator = (const CBit16& obj) { mBit = obj.mBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit16& operator&(const CBit16& obj) { mBit = mBit & obj.mBit; return *this; };
    inline CBit16& operator&(const short  cVal) { mBit = mBit & cVal;     return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit16& operator|(const CBit16& obj) { mBit = mBit | obj.mBit; return *this; };
    inline CBit16& operator|(const short  cVal) { mBit = mBit | cVal;     return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit16& operator^(const CBit16& obj) { mBit = mBit ^ obj.mBit; return *this; };
    inline CBit16& operator^(const short  cVal) { mBit = mBit ^ cVal;     return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit16& operator~() { mBit = ~mBit; return *this; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members
private:
    unsigned short&  mBit;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前Bit类内存大小
    inline unsigned int   size()     { return sizeof(mBit); };
    // 重置Bit数值
    inline void           reset()    { mBit = 0; };

    // 返回当前值
    inline short          toShort()  { return mBit; };
    inline unsigned short toUShort() { return mBit; };

    // 设置bit值
    inline void Set(const short          cVal) { mBit = cVal; };
    inline void Set(const unsigned short cVal) { mBit = cVal; };

    inline void Set01() { ((stBit16*)&mBit)->bit00 = 1; };
    inline void Set02() { ((stBit16*)&mBit)->bit01 = 1; };
    inline void Set03() { ((stBit16*)&mBit)->bit02 = 1; };
    inline void Set04() { ((stBit16*)&mBit)->bit03 = 1; };
    inline void Set05() { ((stBit16*)&mBit)->bit04 = 1; };
    inline void Set06() { ((stBit16*)&mBit)->bit05 = 1; };
    inline void Set07() { ((stBit16*)&mBit)->bit06 = 1; };
    inline void Set08() { ((stBit16*)&mBit)->bit07 = 1; };
    inline void Set09() { ((stBit16*)&mBit)->bit08 = 1; };
    inline void Set10() { ((stBit16*)&mBit)->bit09 = 1; };
    inline void Set11() { ((stBit16*)&mBit)->bit10 = 1; };
    inline void Set12() { ((stBit16*)&mBit)->bit11 = 1; };
    inline void Set13() { ((stBit16*)&mBit)->bit12 = 1; };
    inline void Set14() { ((stBit16*)&mBit)->bit13 = 1; };
    inline void Set15() { ((stBit16*)&mBit)->bit14 = 1; };
    inline void Set16() { ((stBit16*)&mBit)->bit15 = 1; };

    // 取消bit值设置
    inline void unSet(const short          cVal) { mBit = cVal; };
    inline void unSet(const unsigned short cVal) { mBit = cVal; };

    inline void unSet01() { ((stBit16*)&mBit)->bit00 = 0; };
    inline void unSet02() { ((stBit16*)&mBit)->bit01 = 0; };
    inline void unSet03() { ((stBit16*)&mBit)->bit02 = 0; };
    inline void unSet04() { ((stBit16*)&mBit)->bit03 = 0; };
    inline void unSet05() { ((stBit16*)&mBit)->bit04 = 0; };
    inline void unSet06() { ((stBit16*)&mBit)->bit05 = 0; };
    inline void unSet07() { ((stBit16*)&mBit)->bit06 = 0; };
    inline void unSet08() { ((stBit16*)&mBit)->bit07 = 0; };
    inline void unSet08() { ((stBit16*)&mBit)->bit08 = 0; };
    inline void unSet09() { ((stBit16*)&mBit)->bit09 = 0; };
    inline void unSet10() { ((stBit16*)&mBit)->bit10 = 0; };
    inline void unSet11() { ((stBit16*)&mBit)->bit11 = 0; };
    inline void unSet12() { ((stBit16*)&mBit)->bit12 = 0; };
    inline void unSet13() { ((stBit16*)&mBit)->bit13 = 0; };
    inline void unSet14() { ((stBit16*)&mBit)->bit14 = 0; };
    inline void unSet15() { ((stBit16*)&mBit)->bit15 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const short cVal) { mBit&cVal ? true : false; };

    inline bool isSet01() { return (((stBit16*)&mBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((stBit16*)&mBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((stBit16*)&mBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((stBit16*)&mBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((stBit16*)&mBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((stBit16*)&mBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((stBit16*)&mBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((stBit16*)&mBit)->bit07 & 1) ? true : false; };
    inline bool isSet09() { return (((stBit16*)&mBit)->bit08 & 1) ? true : false; };
    inline bool isSet10() { return (((stBit16*)&mBit)->bit09 & 1) ? true : false; };
    inline bool isSet11() { return (((stBit16*)&mBit)->bit10 & 1) ? true : false; };
    inline bool isSet12() { return (((stBit16*)&mBit)->bit11 & 1) ? true : false; };
    inline bool isSet13() { return (((stBit16*)&mBit)->bit12 & 1) ? true : false; };
    inline bool isSet14() { return (((stBit16*)&mBit)->bit13 & 1) ? true : false; };
    inline bool isSet15() { return (((stBit16*)&mBit)->bit14 & 1) ? true : false; };
    inline bool isSet16() { return (((stBit16*)&mBit)->bit15 & 1) ? true : false; };

/////////////////////////////////////////////////////////////////////////////////////////
// Friends define: 
friend class CBitStr;

}; // End of class CBit16
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CBIT16_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit16.h
/////////////////////////////////////////////////////////////////////////////////////////