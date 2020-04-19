/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CBit32.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/06 00:51:24
// Modify time 	: 2020/01/06 00:51:24
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

#ifndef __CBIT32_H__
#define __CBIT32_H__

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
// class CBit32 : 此类封装了32位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit32
{
/////////////////////////////////////////////////////////////////////////////////////////
// Types define :
public:
    typedef struct stBit32
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

        unsigned int  bit16 : 1;
        unsigned int  bit17 : 1;
        unsigned int  bit18 : 1;
        unsigned int  bit19 : 1;
        unsigned int  bit20 : 1;
        unsigned int  bit21 : 1;
        unsigned int  bit22 : 1;
        unsigned int  bit23 : 1;

        unsigned int  bit24 : 1;
        unsigned int  bit25 : 1;
        unsigned int  bit26 : 1;
        unsigned int  bit27 : 1;
        unsigned int  bit28 : 1;
        unsigned int  bit29 : 1;
        unsigned int  bit30 : 1;
        unsigned int  bit31 : 1;

    };

    typedef enum emBitPos
    {
        PosFF = 0xFFFFFFFF,
        Pos00 = 0x00000000,

        Pos01 = 0x00000001,
        Pos02 = 0x00000002,
        Pos03 = 0x00000004,
        Pos04 = 0x00000008,
        Pos05 = 0x00000010,
        Pos06 = 0x00000020,
        Pos07 = 0x00000040,
        Pos08 = 0x00000080,

        Pos09 = 0x00000100,
        Pos10 = 0x00000200,
        Pos11 = 0x00000400,
        Pos12 = 0x00000800,
        Pos13 = 0x00001000,
        Pos14 = 0x00002000,
        Pos15 = 0x00004000,
        Pos16 = 0x00008000,

        Pos17 = 0x00010000,
        Pos18 = 0x00020000,
        Pos19 = 0x00040000,
        Pos20 = 0x00080000,
        Pos21 = 0x00100000,
        Pos22 = 0x00200000,
        Pos23 = 0x00400000,
        Pos24 = 0x00800000,

        Pos25 = 0x01000000,
        Pos26 = 0x02000000,
        Pos27 = 0x04000000,
        Pos28 = 0x08000000,
        Pos29 = 0x10000000,
        Pos30 = 0x20000000,
        Pos31 = 0x40000000,
        Pos32 = 0x80000000
    };

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline CBit32(long&          cVal) :mBit(*((unsigned long*)&cVal)) {};
    inline CBit32(unsigned long& cVal) :mBit(cVal) {};
    // Destruct define
    inline virtual ~CBit32() {};

public:
    // Copy construct define
    inline CBit32(const CBit32& obj) :mBit(obj.mBit) {};
    // Assignment define
    inline CBit32& operator = (const CBit32& obj) { mBit = obj.mBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit32& operator&(const CBit32& obj) { mBit = mBit & obj.mBit; return *this; };
    inline CBit32& operator&(const long  cVal) { mBit = mBit & cVal;     return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit32& operator|(const CBit32& obj) { mBit = mBit | obj.mBit; return *this; };
    inline CBit32& operator|(const long  cVal) { mBit = mBit | cVal;     return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit32& operator^(const CBit32& obj) { mBit = mBit ^ obj.mBit; return *this; };
    inline CBit32& operator^(const long  cVal) { mBit = mBit ^ cVal;     return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit32& operator~() { mBit = ~mBit; return *this; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    unsigned long&  mBit;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前Bit类内存大小
    inline unsigned int  size()    { return sizeof(mBit); };
    // 重置Bit数值
    inline void          reset()   { mBit = 0; };

    // 返回当前值
    inline long          toLong()  { return mBit; };
    inline unsigned long toULong() { return mBit; };

    // 设置bit值
    inline void Set(const long          cVal) { mBit = cVal; };
    inline void Set(const unsigned long cVal) { mBit = cVal; };

    inline void Set01() { ((stBit32*)&mBit)->bit00 = 1; };
    inline void Set02() { ((stBit32*)&mBit)->bit01 = 1; };
    inline void Set03() { ((stBit32*)&mBit)->bit02 = 1; };
    inline void Set04() { ((stBit32*)&mBit)->bit03 = 1; };
    inline void Set05() { ((stBit32*)&mBit)->bit04 = 1; };
    inline void Set06() { ((stBit32*)&mBit)->bit05 = 1; };
    inline void Set07() { ((stBit32*)&mBit)->bit06 = 1; };
    inline void Set08() { ((stBit32*)&mBit)->bit07 = 1; };

    inline void Set09() { ((stBit32*)&mBit)->bit08 = 1; };
    inline void Set10() { ((stBit32*)&mBit)->bit09 = 1; };
    inline void Set11() { ((stBit32*)&mBit)->bit10 = 1; };
    inline void Set12() { ((stBit32*)&mBit)->bit11 = 1; };
    inline void Set13() { ((stBit32*)&mBit)->bit12 = 1; };
    inline void Set14() { ((stBit32*)&mBit)->bit13 = 1; };
    inline void Set15() { ((stBit32*)&mBit)->bit14 = 1; };
    inline void Set16() { ((stBit32*)&mBit)->bit15 = 1; };

    inline void Set17() { ((stBit32*)&mBit)->bit16 = 1; };
    inline void Set18() { ((stBit32*)&mBit)->bit17 = 1; };
    inline void Set19() { ((stBit32*)&mBit)->bit18 = 1; };
    inline void Set20() { ((stBit32*)&mBit)->bit19 = 1; };
    inline void Set21() { ((stBit32*)&mBit)->bit20 = 1; };
    inline void Set22() { ((stBit32*)&mBit)->bit21 = 1; };
    inline void Set23() { ((stBit32*)&mBit)->bit22 = 1; };
    inline void Set24() { ((stBit32*)&mBit)->bit23 = 1; };

    inline void Set25() { ((stBit32*)&mBit)->bit24 = 1; };
    inline void Set26() { ((stBit32*)&mBit)->bit25 = 1; };
    inline void Set27() { ((stBit32*)&mBit)->bit26 = 1; };
    inline void Set28() { ((stBit32*)&mBit)->bit27 = 1; };
    inline void Set29() { ((stBit32*)&mBit)->bit28 = 1; };
    inline void Set30() { ((stBit32*)&mBit)->bit29 = 1; };
    inline void Set31() { ((stBit32*)&mBit)->bit30 = 1; };
    inline void Set32() { ((stBit32*)&mBit)->bit31 = 1; };

    // 取消bit值设置
    inline void unSet(const long          cVal) { mBit = cVal; };
    inline void unSet(const unsigned long cVal) { mBit = cVal; };

    inline void unSet01() { ((stBit32*)&mBit)->bit00 = 0; };
    inline void unSet02() { ((stBit32*)&mBit)->bit01 = 0; };
    inline void unSet03() { ((stBit32*)&mBit)->bit02 = 0; };
    inline void unSet04() { ((stBit32*)&mBit)->bit03 = 0; };
    inline void unSet05() { ((stBit32*)&mBit)->bit04 = 0; };
    inline void unSet06() { ((stBit32*)&mBit)->bit05 = 0; };
    inline void unSet07() { ((stBit32*)&mBit)->bit06 = 0; };
    inline void unSet08() { ((stBit32*)&mBit)->bit07 = 0; };

    inline void unSet09() { ((stBit32*)&mBit)->bit08 = 0; };
    inline void unSet10() { ((stBit32*)&mBit)->bit09 = 0; };
    inline void unSet11() { ((stBit32*)&mBit)->bit10 = 0; };
    inline void unSet12() { ((stBit32*)&mBit)->bit11 = 0; };
    inline void unSet13() { ((stBit32*)&mBit)->bit12 = 0; };
    inline void unSet14() { ((stBit32*)&mBit)->bit13 = 0; };
    inline void unSet15() { ((stBit32*)&mBit)->bit14 = 0; };
    inline void unSet16() { ((stBit32*)&mBit)->bit15 = 0; };

    inline void unSet17() { ((stBit32*)&mBit)->bit16 = 0; };
    inline void unSet18() { ((stBit32*)&mBit)->bit17 = 0; };
    inline void unSet19() { ((stBit32*)&mBit)->bit18 = 0; };
    inline void unSet20() { ((stBit32*)&mBit)->bit19 = 0; };
    inline void unSet21() { ((stBit32*)&mBit)->bit20 = 0; };
    inline void unSet22() { ((stBit32*)&mBit)->bit21 = 0; };
    inline void unSet23() { ((stBit32*)&mBit)->bit22 = 0; };
    inline void unSet24() { ((stBit32*)&mBit)->bit23 = 0; };

    inline void unSet25() { ((stBit32*)&mBit)->bit24 = 0; };
    inline void unSet26() { ((stBit32*)&mBit)->bit25 = 0; };
    inline void unSet27() { ((stBit32*)&mBit)->bit26 = 0; };
    inline void unSet28() { ((stBit32*)&mBit)->bit27 = 0; };
    inline void unSet29() { ((stBit32*)&mBit)->bit28 = 0; };
    inline void unSet30() { ((stBit32*)&mBit)->bit29 = 0; };
    inline void unSet31() { ((stBit32*)&mBit)->bit30 = 0; };
    inline void unSet32() { ((stBit32*)&mBit)->bit31 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const long cVal) { mBit&cVal ? true : false; };

    inline bool isSet01() { return (((stBit32*)&mBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((stBit32*)&mBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((stBit32*)&mBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((stBit32*)&mBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((stBit32*)&mBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((stBit32*)&mBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((stBit32*)&mBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((stBit32*)&mBit)->bit07 & 1) ? true : false; };

    inline bool isSet09() { return (((stBit32*)&mBit)->bit08 & 1) ? true : false; };
    inline bool isSet10() { return (((stBit32*)&mBit)->bit09 & 1) ? true : false; };
    inline bool isSet11() { return (((stBit32*)&mBit)->bit10 & 1) ? true : false; };
    inline bool isSet12() { return (((stBit32*)&mBit)->bit11 & 1) ? true : false; };
    inline bool isSet13() { return (((stBit32*)&mBit)->bit12 & 1) ? true : false; };
    inline bool isSet14() { return (((stBit32*)&mBit)->bit13 & 1) ? true : false; };
    inline bool isSet15() { return (((stBit32*)&mBit)->bit14 & 1) ? true : false; };
    inline bool isSet16() { return (((stBit32*)&mBit)->bit15 & 1) ? true : false; };

    inline bool isSet17() { return (((stBit32*)&mBit)->bit16 & 1) ? true : false; };
    inline bool isSet18() { return (((stBit32*)&mBit)->bit17 & 1) ? true : false; };
    inline bool isSet19() { return (((stBit32*)&mBit)->bit18 & 1) ? true : false; };
    inline bool isSet20() { return (((stBit32*)&mBit)->bit19 & 1) ? true : false; };
    inline bool isSet21() { return (((stBit32*)&mBit)->bit20 & 1) ? true : false; };
    inline bool isSet22() { return (((stBit32*)&mBit)->bit21 & 1) ? true : false; };
    inline bool isSet23() { return (((stBit32*)&mBit)->bit22 & 1) ? true : false; };
    inline bool isSet24() { return (((stBit32*)&mBit)->bit23 & 1) ? true : false; };

    inline bool isSet25() { return (((stBit32*)&mBit)->bit24 & 1) ? true : false; };
    inline bool isSet26() { return (((stBit32*)&mBit)->bit25 & 1) ? true : false; };
    inline bool isSet27() { return (((stBit32*)&mBit)->bit26 & 1) ? true : false; };
    inline bool isSet28() { return (((stBit32*)&mBit)->bit27 & 1) ? true : false; };
    inline bool isSet29() { return (((stBit32*)&mBit)->bit28 & 1) ? true : false; };
    inline bool isSet30() { return (((stBit32*)&mBit)->bit29 & 1) ? true : false; };
    inline bool isSet31() { return (((stBit32*)&mBit)->bit30 & 1) ? true : false; };
    inline bool isSet32() { return (((stBit32*)&mBit)->bit31 & 1) ? true : false; };

/////////////////////////////////////////////////////////////////////////////////////////
// Friends define: 
friend class CBitStr;

}; // End of class CBit32
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CBIT32_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit32.h
/////////////////////////////////////////////////////////////////////////////////////////
