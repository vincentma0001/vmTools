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
// Types define :
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
} STBIT32, *PSTBIT32;

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :

#define _V_CBIT32_POS_00_  0x00000000

#define _V_CBIT32_POS_01_  0x00000001
#define _V_CBIT32_POS_02_  0x00000002
#define _V_CBIT32_POS_03_  0x00000004
#define _V_CBIT32_POS_04_  0x00000008
#define _V_CBIT32_POS_05_  0x00000010
#define _V_CBIT32_POS_06_  0x00000020
#define _V_CBIT32_POS_07_  0x00000040
#define _V_CBIT32_POS_08_  0x00000080

#define _V_CBIT32_POS_09_  0x00000100
#define _V_CBIT32_POS_10_  0x00000200
#define _V_CBIT32_POS_11_  0x00000400
#define _V_CBIT32_POS_12_  0x00000800
#define _V_CBIT32_POS_13_  0x00001000
#define _V_CBIT32_POS_14_  0x00002000
#define _V_CBIT32_POS_15_  0x00004000
#define _V_CBIT32_POS_16_  0x00008000

#define _V_CBIT32_POS_17_  0x00010000
#define _V_CBIT32_POS_18_  0x00020000
#define _V_CBIT32_POS_19_  0x00040000
#define _V_CBIT32_POS_20_  0x00080000
#define _V_CBIT32_POS_21_  0x00100000
#define _V_CBIT32_POS_22_  0x00200000
#define _V_CBIT32_POS_23_  0x00400000
#define _V_CBIT32_POS_24_  0x00800000

#define _V_CBIT32_POS_25_  0x01000000
#define _V_CBIT32_POS_26_  0x02000000
#define _V_CBIT32_POS_27_  0x04000000
#define _V_CBIT32_POS_28_  0x08000000
#define _V_CBIT32_POS_29_  0x10000000
#define _V_CBIT32_POS_30_  0x20000000
#define _V_CBIT32_POS_31_  0x40000000
#define _V_CBIT32_POS_32_  0x80000000

#define _V_CBIT32_POS_FF_  0xFFFFFFFF

#define _V_CBIT32_MAX_BUF_ 33

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit32 : 此类封装了32位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit32
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CBit32(long          cVal) :mBit(cVal) {};
    inline explicit CBit32(unsigned long cVal) :mBit(cVal) {};
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
    unsigned long  mBit;
    tChar           mszBuf[_V_CBIT32_MAX_BUF_];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前值
    inline long          toShort() { return mBit; };
    inline unsigned long toUShort() { return mBit; };

    inline void clear() { mBit = 0; vMemZero(mszBuf); };

    // 设置bit值
    inline void Set(const long          cVal) { mBit = cVal; };
    inline void Set(const unsigned long cVal) { mBit = cVal; };

    inline void Set01() { ((PSTBIT32)&mBit)->bit00 = 1; };
    inline void Set02() { ((PSTBIT32)&mBit)->bit01 = 1; };
    inline void Set03() { ((PSTBIT32)&mBit)->bit02 = 1; };
    inline void Set04() { ((PSTBIT32)&mBit)->bit03 = 1; };
    inline void Set05() { ((PSTBIT32)&mBit)->bit04 = 1; };
    inline void Set06() { ((PSTBIT32)&mBit)->bit05 = 1; };
    inline void Set07() { ((PSTBIT32)&mBit)->bit06 = 1; };
    inline void Set08() { ((PSTBIT32)&mBit)->bit07 = 1; };

    inline void Set09() { ((PSTBIT32)&mBit)->bit08 = 1; };
    inline void Set10() { ((PSTBIT32)&mBit)->bit09 = 1; };
    inline void Set11() { ((PSTBIT32)&mBit)->bit10 = 1; };
    inline void Set12() { ((PSTBIT32)&mBit)->bit11 = 1; };
    inline void Set13() { ((PSTBIT32)&mBit)->bit12 = 1; };
    inline void Set14() { ((PSTBIT32)&mBit)->bit13 = 1; };
    inline void Set15() { ((PSTBIT32)&mBit)->bit14 = 1; };
    inline void Set16() { ((PSTBIT32)&mBit)->bit15 = 1; };

    inline void Set17() { ((PSTBIT32)&mBit)->bit16 = 1; };
    inline void Set18() { ((PSTBIT32)&mBit)->bit17 = 1; };
    inline void Set19() { ((PSTBIT32)&mBit)->bit18 = 1; };
    inline void Set20() { ((PSTBIT32)&mBit)->bit19 = 1; };
    inline void Set21() { ((PSTBIT32)&mBit)->bit20 = 1; };
    inline void Set22() { ((PSTBIT32)&mBit)->bit21 = 1; };
    inline void Set23() { ((PSTBIT32)&mBit)->bit22 = 1; };
    inline void Set24() { ((PSTBIT32)&mBit)->bit23 = 1; };

    inline void Set25() { ((PSTBIT32)&mBit)->bit24 = 1; };
    inline void Set26() { ((PSTBIT32)&mBit)->bit25 = 1; };
    inline void Set27() { ((PSTBIT32)&mBit)->bit26 = 1; };
    inline void Set28() { ((PSTBIT32)&mBit)->bit27 = 1; };
    inline void Set29() { ((PSTBIT32)&mBit)->bit28 = 1; };
    inline void Set30() { ((PSTBIT32)&mBit)->bit29 = 1; };
    inline void Set31() { ((PSTBIT32)&mBit)->bit30 = 1; };
    inline void Set32() { ((PSTBIT32)&mBit)->bit31 = 1; };

    // 取消bit值设置
    inline void unSet(const long          cVal) { mBit = cVal; };
    inline void unSet(const unsigned long cVal) { mBit = cVal; };

    inline void unSet01() { ((PSTBIT32)&mBit)->bit00 = 0; };
    inline void unSet02() { ((PSTBIT32)&mBit)->bit01 = 0; };
    inline void unSet03() { ((PSTBIT32)&mBit)->bit02 = 0; };
    inline void unSet04() { ((PSTBIT32)&mBit)->bit03 = 0; };
    inline void unSet05() { ((PSTBIT32)&mBit)->bit04 = 0; };
    inline void unSet06() { ((PSTBIT32)&mBit)->bit05 = 0; };
    inline void unSet07() { ((PSTBIT32)&mBit)->bit06 = 0; };
    inline void unSet08() { ((PSTBIT32)&mBit)->bit07 = 0; };

    inline void unSet09() { ((PSTBIT32)&mBit)->bit08 = 0; };
    inline void unSet10() { ((PSTBIT32)&mBit)->bit09 = 0; };
    inline void unSet11() { ((PSTBIT32)&mBit)->bit10 = 0; };
    inline void unSet12() { ((PSTBIT32)&mBit)->bit11 = 0; };
    inline void unSet13() { ((PSTBIT32)&mBit)->bit12 = 0; };
    inline void unSet14() { ((PSTBIT32)&mBit)->bit13 = 0; };
    inline void unSet15() { ((PSTBIT32)&mBit)->bit14 = 0; };
    inline void unSet16() { ((PSTBIT32)&mBit)->bit15 = 0; };

    inline void unSet17() { ((PSTBIT32)&mBit)->bit16 = 0; };
    inline void unSet18() { ((PSTBIT32)&mBit)->bit17 = 0; };
    inline void unSet19() { ((PSTBIT32)&mBit)->bit18 = 0; };
    inline void unSet20() { ((PSTBIT32)&mBit)->bit19 = 0; };
    inline void unSet21() { ((PSTBIT32)&mBit)->bit20 = 0; };
    inline void unSet22() { ((PSTBIT32)&mBit)->bit21 = 0; };
    inline void unSet23() { ((PSTBIT32)&mBit)->bit22 = 0; };
    inline void unSet24() { ((PSTBIT32)&mBit)->bit23 = 0; };

    inline void unSet25() { ((PSTBIT32)&mBit)->bit24 = 0; };
    inline void unSet26() { ((PSTBIT32)&mBit)->bit25 = 0; };
    inline void unSet27() { ((PSTBIT32)&mBit)->bit26 = 0; };
    inline void unSet28() { ((PSTBIT32)&mBit)->bit27 = 0; };
    inline void unSet29() { ((PSTBIT32)&mBit)->bit28 = 0; };
    inline void unSet30() { ((PSTBIT32)&mBit)->bit29 = 0; };
    inline void unSet31() { ((PSTBIT32)&mBit)->bit30 = 0; };
    inline void unSet32() { ((PSTBIT32)&mBit)->bit31 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const long cVal) { mBit&cVal ? true : false; };

    inline bool isSet01() { return (((PSTBIT32)&mBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((PSTBIT32)&mBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((PSTBIT32)&mBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((PSTBIT32)&mBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((PSTBIT32)&mBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((PSTBIT32)&mBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((PSTBIT32)&mBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((PSTBIT32)&mBit)->bit07 & 1) ? true : false; };

    inline bool isSet09() { return (((PSTBIT32)&mBit)->bit08 & 1) ? true : false; };
    inline bool isSet10() { return (((PSTBIT32)&mBit)->bit09 & 1) ? true : false; };
    inline bool isSet11() { return (((PSTBIT32)&mBit)->bit10 & 1) ? true : false; };
    inline bool isSet12() { return (((PSTBIT32)&mBit)->bit11 & 1) ? true : false; };
    inline bool isSet13() { return (((PSTBIT32)&mBit)->bit12 & 1) ? true : false; };
    inline bool isSet14() { return (((PSTBIT32)&mBit)->bit13 & 1) ? true : false; };
    inline bool isSet15() { return (((PSTBIT32)&mBit)->bit14 & 1) ? true : false; };
    inline bool isSet16() { return (((PSTBIT32)&mBit)->bit15 & 1) ? true : false; };

    inline bool isSet17() { return (((PSTBIT32)&mBit)->bit16 & 1) ? true : false; };
    inline bool isSet18() { return (((PSTBIT32)&mBit)->bit17 & 1) ? true : false; };
    inline bool isSet19() { return (((PSTBIT32)&mBit)->bit18 & 1) ? true : false; };
    inline bool isSet20() { return (((PSTBIT32)&mBit)->bit19 & 1) ? true : false; };
    inline bool isSet21() { return (((PSTBIT32)&mBit)->bit20 & 1) ? true : false; };
    inline bool isSet22() { return (((PSTBIT32)&mBit)->bit21 & 1) ? true : false; };
    inline bool isSet23() { return (((PSTBIT32)&mBit)->bit22 & 1) ? true : false; };
    inline bool isSet24() { return (((PSTBIT32)&mBit)->bit23 & 1) ? true : false; };

    inline bool isSet25() { return (((PSTBIT32)&mBit)->bit24 & 1) ? true : false; };
    inline bool isSet26() { return (((PSTBIT32)&mBit)->bit25 & 1) ? true : false; };
    inline bool isSet27() { return (((PSTBIT32)&mBit)->bit26 & 1) ? true : false; };
    inline bool isSet28() { return (((PSTBIT32)&mBit)->bit27 & 1) ? true : false; };
    inline bool isSet29() { return (((PSTBIT32)&mBit)->bit28 & 1) ? true : false; };
    inline bool isSet30() { return (((PSTBIT32)&mBit)->bit29 & 1) ? true : false; };
    inline bool isSet31() { return (((PSTBIT32)&mBit)->bit30 & 1) ? true : false; };
    inline bool isSet32() { return (((PSTBIT32)&mBit)->bit31 & 1) ? true : false; };

    // 以二进制方式返回bit值字符串
    inline tChar* toBin()
    {
        vMemZero(mszBuf);
        tChar* lpPos = mszBuf;
        for (int i = 31; i >= 0; i--)
        {
            (*lpPos) = ((mBit >> i) & 1) ? '1' : '0';;
            lpPos++;
        }
        return mszBuf;
    };
    // 以八进制方式返回bit值字符串
    inline tChar* toOct()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%08o", mBit);
        return mszBuf;
    };
    // 以十进制方式返回bit值字符串
    inline tChar* toDec()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%08d", mBit);
        return mszBuf;
    };
    // 以十六进制方式返回bit值字符串
    inline tChar* toHex()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%04X", mBit);
        return mszBuf;
    };

}; // End of class CBit32
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit32Ptr : 此类封装了32位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit32Ptr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CBit32Ptr(long* const          cpVal) :mpBit((unsigned long*)cpVal) {};
    inline explicit CBit32Ptr(unsigned long* const cpVal) :mpBit(cpVal) {};
    inline explicit CBit32Ptr(long&                 cVal) :mpBit((unsigned long*)&cVal) {};
    inline explicit CBit32Ptr(unsigned long&        cVal) :mpBit(&cVal) {};
    // Destruct define
    inline virtual ~CBit32Ptr() {};

public:
    // Copy construct define
    inline CBit32Ptr(const CBit32Ptr& obj) :mpBit(obj.mpBit) {};
    // Assignment define
    inline CBit32Ptr& operator = (const CBit32Ptr& obj) { *mpBit = *obj.mpBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit32Ptr& operator&(const CBit32Ptr& obj) { *mpBit = *mpBit & *obj.mpBit; return *this; };
    inline CBit32Ptr& operator&(const long     cVal) { *mpBit = *mpBit & cVal;       return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit32Ptr& operator|(const CBit32Ptr& obj) { *mpBit = *mpBit | *obj.mpBit; return *this; };
    inline CBit32Ptr& operator|(const long     cVal) { *mpBit = *mpBit | cVal;       return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit32Ptr& operator^(const CBit32Ptr& obj) { *mpBit = *mpBit ^ *obj.mpBit; return *this; };
    inline CBit32Ptr& operator^(const long     cVal) { *mpBit = *mpBit ^ cVal;       return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit32Ptr& operator~() { *mpBit = ~*mpBit; return *this; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    unsigned long*  mpBit;
    tChar            mszBuf[_V_CBIT32_MAX_BUF_];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前值
    inline long          toShort() { return *mpBit; };
    inline unsigned long toUShort() { return *mpBit; };

    inline void clear() { *mpBit = 0; vMemZero(mszBuf); };

    // 设置bit值
    inline void Set(const long          cVal) { *mpBit = cVal; };
    inline void Set(const unsigned long cVal) { *mpBit = cVal; };

    inline void Set01() { ((PSTBIT32)mpBit)->bit00 = 1; };
    inline void Set02() { ((PSTBIT32)mpBit)->bit01 = 1; };
    inline void Set03() { ((PSTBIT32)mpBit)->bit02 = 1; };
    inline void Set04() { ((PSTBIT32)mpBit)->bit03 = 1; };
    inline void Set05() { ((PSTBIT32)mpBit)->bit04 = 1; };
    inline void Set06() { ((PSTBIT32)mpBit)->bit05 = 1; };
    inline void Set07() { ((PSTBIT32)mpBit)->bit06 = 1; };
    inline void Set08() { ((PSTBIT32)mpBit)->bit07 = 1; };

    inline void Set09() { ((PSTBIT32)mpBit)->bit08 = 1; };
    inline void Set10() { ((PSTBIT32)mpBit)->bit09 = 1; };
    inline void Set11() { ((PSTBIT32)mpBit)->bit10 = 1; };
    inline void Set12() { ((PSTBIT32)mpBit)->bit11 = 1; };
    inline void Set13() { ((PSTBIT32)mpBit)->bit12 = 1; };
    inline void Set14() { ((PSTBIT32)mpBit)->bit13 = 1; };
    inline void Set15() { ((PSTBIT32)mpBit)->bit14 = 1; };
    inline void Set16() { ((PSTBIT32)mpBit)->bit15 = 1; };

    inline void Set17() { ((PSTBIT32)mpBit)->bit16 = 1; };
    inline void Set18() { ((PSTBIT32)mpBit)->bit17 = 1; };
    inline void Set19() { ((PSTBIT32)mpBit)->bit18 = 1; };
    inline void Set20() { ((PSTBIT32)mpBit)->bit19 = 1; };
    inline void Set21() { ((PSTBIT32)mpBit)->bit20 = 1; };
    inline void Set22() { ((PSTBIT32)mpBit)->bit21 = 1; };
    inline void Set23() { ((PSTBIT32)mpBit)->bit22 = 1; };
    inline void Set24() { ((PSTBIT32)mpBit)->bit23 = 1; };

    inline void Set25() { ((PSTBIT32)mpBit)->bit24 = 1; };
    inline void Set26() { ((PSTBIT32)mpBit)->bit25 = 1; };
    inline void Set27() { ((PSTBIT32)mpBit)->bit26 = 1; };
    inline void Set28() { ((PSTBIT32)mpBit)->bit27 = 1; };
    inline void Set29() { ((PSTBIT32)mpBit)->bit28 = 1; };
    inline void Set30() { ((PSTBIT32)mpBit)->bit29 = 1; };
    inline void Set31() { ((PSTBIT32)mpBit)->bit30 = 1; };
    inline void Set32() { ((PSTBIT32)mpBit)->bit31 = 1; };

    // 取消bit值设置
    inline void unSet(const long          cVal) { *mpBit = cVal; };
    inline void unSet(const unsigned long cVal) { *mpBit = cVal; };

    inline void unSet01() { ((PSTBIT32)mpBit)->bit00 = 0; };
    inline void unSet02() { ((PSTBIT32)mpBit)->bit01 = 0; };
    inline void unSet03() { ((PSTBIT32)mpBit)->bit02 = 0; };
    inline void unSet04() { ((PSTBIT32)mpBit)->bit03 = 0; };
    inline void unSet05() { ((PSTBIT32)mpBit)->bit04 = 0; };
    inline void unSet06() { ((PSTBIT32)mpBit)->bit05 = 0; };
    inline void unSet07() { ((PSTBIT32)mpBit)->bit06 = 0; };
    inline void unSet08() { ((PSTBIT32)mpBit)->bit07 = 0; };

    inline void unSet09() { ((PSTBIT32)mpBit)->bit08 = 0; };
    inline void unSet10() { ((PSTBIT32)mpBit)->bit09 = 0; };
    inline void unSet11() { ((PSTBIT32)mpBit)->bit10 = 0; };
    inline void unSet12() { ((PSTBIT32)mpBit)->bit11 = 0; };
    inline void unSet13() { ((PSTBIT32)mpBit)->bit12 = 0; };
    inline void unSet14() { ((PSTBIT32)mpBit)->bit13 = 0; };
    inline void unSet15() { ((PSTBIT32)mpBit)->bit14 = 0; };
    inline void unSet16() { ((PSTBIT32)mpBit)->bit15 = 0; };

    inline void unSet17() { ((PSTBIT32)mpBit)->bit16 = 0; };
    inline void unSet18() { ((PSTBIT32)mpBit)->bit17 = 0; };
    inline void unSet19() { ((PSTBIT32)mpBit)->bit18 = 0; };
    inline void unSet20() { ((PSTBIT32)mpBit)->bit19 = 0; };
    inline void unSet21() { ((PSTBIT32)mpBit)->bit20 = 0; };
    inline void unSet22() { ((PSTBIT32)mpBit)->bit21 = 0; };
    inline void unSet23() { ((PSTBIT32)mpBit)->bit22 = 0; };
    inline void unSet24() { ((PSTBIT32)mpBit)->bit23 = 0; };

    inline void unSet25() { ((PSTBIT32)mpBit)->bit24 = 0; };
    inline void unSet26() { ((PSTBIT32)mpBit)->bit25 = 0; };
    inline void unSet27() { ((PSTBIT32)mpBit)->bit26 = 0; };
    inline void unSet28() { ((PSTBIT32)mpBit)->bit27 = 0; };
    inline void unSet29() { ((PSTBIT32)mpBit)->bit28 = 0; };
    inline void unSet30() { ((PSTBIT32)mpBit)->bit29 = 0; };
    inline void unSet31() { ((PSTBIT32)mpBit)->bit30 = 0; };
    inline void unSet32() { ((PSTBIT32)mpBit)->bit31 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const long sVal) { (*mpBit)&sVal ? true : false; };

    inline bool isSet01() { return (((PSTBIT32)mpBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((PSTBIT32)mpBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((PSTBIT32)mpBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((PSTBIT32)mpBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((PSTBIT32)mpBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((PSTBIT32)mpBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((PSTBIT32)mpBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((PSTBIT32)mpBit)->bit07 & 1) ? true : false; };

    inline bool isSet09() { return (((PSTBIT32)mpBit)->bit08 & 1) ? true : false; };
    inline bool isSet10() { return (((PSTBIT32)mpBit)->bit09 & 1) ? true : false; };
    inline bool isSet11() { return (((PSTBIT32)mpBit)->bit10 & 1) ? true : false; };
    inline bool isSet12() { return (((PSTBIT32)mpBit)->bit11 & 1) ? true : false; };
    inline bool isSet13() { return (((PSTBIT32)mpBit)->bit12 & 1) ? true : false; };
    inline bool isSet14() { return (((PSTBIT32)mpBit)->bit13 & 1) ? true : false; };
    inline bool isSet15() { return (((PSTBIT32)mpBit)->bit14 & 1) ? true : false; };
    inline bool isSet16() { return (((PSTBIT32)mpBit)->bit15 & 1) ? true : false; };

    inline bool isSet17() { return (((PSTBIT32)mpBit)->bit16 & 1) ? true : false; };
    inline bool isSet18() { return (((PSTBIT32)mpBit)->bit17 & 1) ? true : false; };
    inline bool isSet19() { return (((PSTBIT32)mpBit)->bit18 & 1) ? true : false; };
    inline bool isSet20() { return (((PSTBIT32)mpBit)->bit19 & 1) ? true : false; };
    inline bool isSet21() { return (((PSTBIT32)mpBit)->bit20 & 1) ? true : false; };
    inline bool isSet22() { return (((PSTBIT32)mpBit)->bit21 & 1) ? true : false; };
    inline bool isSet23() { return (((PSTBIT32)mpBit)->bit22 & 1) ? true : false; };
    inline bool isSet24() { return (((PSTBIT32)mpBit)->bit23 & 1) ? true : false; };

    inline bool isSet25() { return (((PSTBIT32)mpBit)->bit24 & 1) ? true : false; };
    inline bool isSet26() { return (((PSTBIT32)mpBit)->bit25 & 1) ? true : false; };
    inline bool isSet27() { return (((PSTBIT32)mpBit)->bit26 & 1) ? true : false; };
    inline bool isSet28() { return (((PSTBIT32)mpBit)->bit27 & 1) ? true : false; };
    inline bool isSet29() { return (((PSTBIT32)mpBit)->bit28 & 1) ? true : false; };
    inline bool isSet30() { return (((PSTBIT32)mpBit)->bit29 & 1) ? true : false; };
    inline bool isSet31() { return (((PSTBIT32)mpBit)->bit30 & 1) ? true : false; };
    inline bool isSet32() { return (((PSTBIT32)mpBit)->bit21 & 1) ? true : false; };

    // 以二进制方式返回bit值字符串
    inline tChar* toBin()
    {
        vMemZero(mszBuf);
        tChar* lpPos = mszBuf;
        for (int i = 31; i >= 0; i--)
        {
            (*lpPos) = ((*mpBit >> i) & 1) ? '1' : '0';
            lpPos++;
        }
        return mszBuf;
    };
    // 以八进制方式返回bit值字符串
    inline tChar* toOct()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%08o", *mpBit);
        return mszBuf;
    };
    // 以十进制方式返回bit值字符串
    inline tChar* toDec()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%08d", *mpBit);
        return mszBuf;
    };
    // 以十六进制方式返回bit值字符串
    inline tChar* toHex()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%04X", *mpBit);
        return mszBuf;
    };

}; // End of class CBit32Ptr
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
