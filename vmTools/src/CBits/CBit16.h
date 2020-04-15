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
} STBIT16, *PSTBIT16;

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :

#define _V_CBIT16_POS_00_  0x0000

#define _V_CBIT16_POS_01_  0x0001
#define _V_CBIT16_POS_02_  0x0002
#define _V_CBIT16_POS_03_  0x0004
#define _V_CBIT16_POS_04_  0x0008
#define _V_CBIT16_POS_05_  0x0010
#define _V_CBIT16_POS_06_  0x0020
#define _V_CBIT16_POS_07_  0x0040
#define _V_CBIT16_POS_08_  0x0080

#define _V_CBIT16_POS_09_  0x0100
#define _V_CBIT16_POS_10_  0x0200
#define _V_CBIT16_POS_11_  0x0400
#define _V_CBIT16_POS_12_  0x0800
#define _V_CBIT16_POS_13_  0x1000
#define _V_CBIT16_POS_14_  0x2000
#define _V_CBIT16_POS_15_  0x4000
#define _V_CBIT16_POS_16_  0x8000

#define _V_CBIT16_POS_FF_  0xFFFF

#define _V_CBIT16_MAX_BUF_ 17

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit16 : 此类封装了16位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit16
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CBit16(short          cVal) :mBit(cVal) {};
    inline explicit CBit16(unsigned short cVal) :mBit(cVal) {};
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
    unsigned short  mBit;
    tchar            mszBuf[_V_CBIT16_MAX_BUF_];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前值
    inline short          toShort()  { return mBit; };
    inline unsigned short toUShort() { return mBit; };

    inline void clear() { mBit = 0; vMemZero(mszBuf); };

    // 设置bit值
    inline void Set(const short          cVal) { mBit = cVal; };
    inline void Set(const unsigned short cVal) { mBit = cVal; };

    inline void Set01() { ((PSTBIT16)&mBit)->bit00 = 1; };
    inline void Set02() { ((PSTBIT16)&mBit)->bit01 = 1; };
    inline void Set03() { ((PSTBIT16)&mBit)->bit02 = 1; };
    inline void Set04() { ((PSTBIT16)&mBit)->bit03 = 1; };
    inline void Set05() { ((PSTBIT16)&mBit)->bit04 = 1; };
    inline void Set06() { ((PSTBIT16)&mBit)->bit05 = 1; };
    inline void Set07() { ((PSTBIT16)&mBit)->bit06 = 1; };
    inline void Set08() { ((PSTBIT16)&mBit)->bit07 = 1; };
    inline void Set09() { ((PSTBIT16)&mBit)->bit08 = 1; };
    inline void Set10() { ((PSTBIT16)&mBit)->bit09 = 1; };
    inline void Set11() { ((PSTBIT16)&mBit)->bit10 = 1; };
    inline void Set12() { ((PSTBIT16)&mBit)->bit11 = 1; };
    inline void Set13() { ((PSTBIT16)&mBit)->bit12 = 1; };
    inline void Set14() { ((PSTBIT16)&mBit)->bit13 = 1; };
    inline void Set15() { ((PSTBIT16)&mBit)->bit14 = 1; };
    inline void Set16() { ((PSTBIT16)&mBit)->bit15 = 1; };

    // 取消bit值设置
    inline void unSet(const short          cVal) { mBit = cVal; };
    inline void unSet(const unsigned short cVal) { mBit = cVal; };

    inline void unSet01() { ((PSTBIT16)&mBit)->bit00 = 0; };
    inline void unSet02() { ((PSTBIT16)&mBit)->bit01 = 0; };
    inline void unSet03() { ((PSTBIT16)&mBit)->bit02 = 0; };
    inline void unSet04() { ((PSTBIT16)&mBit)->bit03 = 0; };
    inline void unSet05() { ((PSTBIT16)&mBit)->bit04 = 0; };
    inline void unSet06() { ((PSTBIT16)&mBit)->bit05 = 0; };
    inline void unSet07() { ((PSTBIT16)&mBit)->bit06 = 0; };
    inline void unSet08() { ((PSTBIT16)&mBit)->bit07 = 0; };
    inline void unSet08() { ((PSTBIT16)&mBit)->bit08 = 0; };
    inline void unSet09() { ((PSTBIT16)&mBit)->bit09 = 0; };
    inline void unSet10() { ((PSTBIT16)&mBit)->bit10 = 0; };
    inline void unSet11() { ((PSTBIT16)&mBit)->bit11 = 0; };
    inline void unSet12() { ((PSTBIT16)&mBit)->bit12 = 0; };
    inline void unSet13() { ((PSTBIT16)&mBit)->bit13 = 0; };
    inline void unSet14() { ((PSTBIT16)&mBit)->bit14 = 0; };
    inline void unSet15() { ((PSTBIT16)&mBit)->bit15 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const short cVal) { mBit&cVal ? true : false; };

    inline bool isSet01() { return (((PSTBIT16)&mBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((PSTBIT16)&mBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((PSTBIT16)&mBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((PSTBIT16)&mBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((PSTBIT16)&mBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((PSTBIT16)&mBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((PSTBIT16)&mBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((PSTBIT16)&mBit)->bit07 & 1) ? true : false; };
    inline bool isSet09() { return (((PSTBIT16)&mBit)->bit08 & 1) ? true : false; };
    inline bool isSet10() { return (((PSTBIT16)&mBit)->bit09 & 1) ? true : false; };
    inline bool isSet11() { return (((PSTBIT16)&mBit)->bit10 & 1) ? true : false; };
    inline bool isSet12() { return (((PSTBIT16)&mBit)->bit11 & 1) ? true : false; };
    inline bool isSet13() { return (((PSTBIT16)&mBit)->bit12 & 1) ? true : false; };
    inline bool isSet14() { return (((PSTBIT16)&mBit)->bit13 & 1) ? true : false; };
    inline bool isSet15() { return (((PSTBIT16)&mBit)->bit14 & 1) ? true : false; };
    inline bool isSet16() { return (((PSTBIT16)&mBit)->bit15 & 1) ? true : false; };

    // 以二进制方式返回bit值字符串
    inline tchar* toBin()
    {
        vMemZero(mszBuf);
        tchar* lpPos = mszBuf;
        for (int i = 15; i >= 0; i--)
        {
            (*lpPos) = ((mBit >> i) & 1) ? '1' : '0';;
            lpPos++;
        }
        return mszBuf;
    };
    // 以八进制方式返回bit值字符串
    inline tchar* toOct()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%08o", mBit);
        return mszBuf;
    };
    // 以十进制方式返回bit值字符串
    inline tchar* toDec()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%08d", mBit);
        return mszBuf;
    };
    // 以十六进制方式返回bit值字符串
    inline tchar* toHex()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%04X", mBit);
        return mszBuf;
    };

}; // End of class CBit16
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit16Ptr : 此类封装了16位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit16Ptr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CBit16Ptr(short* const          cpVal) :mpBit((unsigned short*)cpVal) {};
    inline explicit CBit16Ptr(unsigned short* const cpVal) :mpBit(cpVal) {};
    inline explicit CBit16Ptr(short&                 cVal) :mpBit((unsigned short*)&cVal) {};
    inline explicit CBit16Ptr(unsigned short&        cVal) :mpBit(&cVal) {};
    // Destruct define
    inline virtual ~CBit16Ptr() {};

public:
    // Copy construct define
    inline CBit16Ptr(const CBit16Ptr& obj) :mpBit(obj.mpBit) {};
    // Assignment define
    inline CBit16Ptr& operator = (const CBit16Ptr& obj) { *mpBit = *obj.mpBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit16Ptr& operator&(const CBit16Ptr& obj) { *mpBit = *mpBit & *obj.mpBit; return *this; };
    inline CBit16Ptr& operator&(const short     cVal) { *mpBit = *mpBit & cVal;       return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit16Ptr& operator|(const CBit16Ptr& obj) { *mpBit = *mpBit | *obj.mpBit; return *this; };
    inline CBit16Ptr& operator|(const short     cVal) { *mpBit = *mpBit | cVal;       return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit16Ptr& operator^(const CBit16Ptr& obj) { *mpBit = *mpBit ^ *obj.mpBit; return *this; };
    inline CBit16Ptr& operator^(const short     cVal) { *mpBit = *mpBit ^ cVal;       return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit16Ptr& operator~() { *mpBit = ~*mpBit; return *this; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    unsigned short*  mpBit;
    tchar             mszBuf[_V_CBIT16_MAX_BUF_];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前值
    inline short          toShort()  { return *mpBit; };
    inline unsigned short toUShort() { return *mpBit; };

    inline void clear() { *mpBit = 0; vMemZero(mszBuf); };

    // 设置bit值
    inline void Set(const short          cVal) { *mpBit = cVal; };
    inline void Set(const unsigned short cVal) { *mpBit = cVal; };

    inline void Set01() { ((PSTBIT16)mpBit)->bit00 = 1; };
    inline void Set02() { ((PSTBIT16)mpBit)->bit01 = 1; };
    inline void Set03() { ((PSTBIT16)mpBit)->bit02 = 1; };
    inline void Set04() { ((PSTBIT16)mpBit)->bit03 = 1; };
    inline void Set05() { ((PSTBIT16)mpBit)->bit04 = 1; };
    inline void Set06() { ((PSTBIT16)mpBit)->bit05 = 1; };
    inline void Set07() { ((PSTBIT16)mpBit)->bit06 = 1; };
    inline void Set08() { ((PSTBIT16)mpBit)->bit07 = 1; };
    inline void Set09() { ((PSTBIT16)mpBit)->bit08 = 1; };
    inline void Set10() { ((PSTBIT16)mpBit)->bit09 = 1; };
    inline void Set11() { ((PSTBIT16)mpBit)->bit10 = 1; };
    inline void Set12() { ((PSTBIT16)mpBit)->bit11 = 1; };
    inline void Set13() { ((PSTBIT16)mpBit)->bit12 = 1; };
    inline void Set14() { ((PSTBIT16)mpBit)->bit13 = 1; };
    inline void Set15() { ((PSTBIT16)mpBit)->bit14 = 1; };
    inline void Set16() { ((PSTBIT16)mpBit)->bit15 = 1; };

    // 取消bit值设置
    inline void unSet(const short          cVal) { *mpBit = cVal; };
    inline void unSet(const unsigned short cVal) { *mpBit = cVal; };

    inline void unSet01() { ((PSTBIT16)mpBit)->bit00 = 0; };
    inline void unSet02() { ((PSTBIT16)mpBit)->bit01 = 0; };
    inline void unSet03() { ((PSTBIT16)mpBit)->bit02 = 0; };
    inline void unSet04() { ((PSTBIT16)mpBit)->bit03 = 0; };
    inline void unSet05() { ((PSTBIT16)mpBit)->bit04 = 0; };
    inline void unSet06() { ((PSTBIT16)mpBit)->bit05 = 0; };
    inline void unSet07() { ((PSTBIT16)mpBit)->bit06 = 0; };
    inline void unSet08() { ((PSTBIT16)mpBit)->bit07 = 0; };
    inline void unSet09() { ((PSTBIT16)mpBit)->bit08 = 0; };
    inline void unSet10() { ((PSTBIT16)mpBit)->bit09 = 0; };
    inline void unSet11() { ((PSTBIT16)mpBit)->bit10 = 0; };
    inline void unSet12() { ((PSTBIT16)mpBit)->bit11 = 0; };
    inline void unSet13() { ((PSTBIT16)mpBit)->bit12 = 0; };
    inline void unSet14() { ((PSTBIT16)mpBit)->bit13 = 0; };
    inline void unSet15() { ((PSTBIT16)mpBit)->bit14 = 0; };
    inline void unSet16() { ((PSTBIT16)mpBit)->bit15 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const short sVal) { (*mpBit)&sVal ? true : false; };

    inline bool isSet01() { return (((PSTBIT16)mpBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((PSTBIT16)mpBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((PSTBIT16)mpBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((PSTBIT16)mpBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((PSTBIT16)mpBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((PSTBIT16)mpBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((PSTBIT16)mpBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((PSTBIT16)mpBit)->bit07 & 1) ? true : false; };
    inline bool isSet09() { return (((PSTBIT16)mpBit)->bit08 & 1) ? true : false; };
    inline bool isSet10() { return (((PSTBIT16)mpBit)->bit09 & 1) ? true : false; };
    inline bool isSet11() { return (((PSTBIT16)mpBit)->bit10 & 1) ? true : false; };
    inline bool isSet12() { return (((PSTBIT16)mpBit)->bit11 & 1) ? true : false; };
    inline bool isSet13() { return (((PSTBIT16)mpBit)->bit12 & 1) ? true : false; };
    inline bool isSet14() { return (((PSTBIT16)mpBit)->bit13 & 1) ? true : false; };
    inline bool isSet15() { return (((PSTBIT16)mpBit)->bit14 & 1) ? true : false; };
    inline bool isSet16() { return (((PSTBIT16)mpBit)->bit15 & 1) ? true : false; };

    // 以二进制方式返回bit值字符串
    inline tchar* toBin()
    {
        vMemZero(mszBuf);
        tchar* lpPos = mszBuf;
        for (int i = 15; i >= 0; i--)
        {
            (*lpPos) = ((*mpBit >> i) & 1) ? '1' : '0';;
            lpPos++;
        }
        return mszBuf;
    };
    // 以八进制方式返回bit值字符串
    inline tchar* toOct()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%08o", *mpBit);
        return mszBuf;
    };
    // 以十进制方式返回bit值字符串
    inline tchar* toDec()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%08d", *mpBit);
        return mszBuf;
    };
    // 以十六进制方式返回bit值字符串
    inline tchar* toHex()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), "%04X", *mpBit);
        return mszBuf;
    };

}; // End of class CBit16Ptr
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