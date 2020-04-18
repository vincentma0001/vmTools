/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CBit08Ptr.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/21 09:12:00
// Modify time  : 2020/01/21 09:12:00
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

#ifndef __CBIT08PTR_H__
#define __CBIT08PTR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#ifndef    __VM_CFG_H__
#   include<vmCfg.h>
#endif  // __VM_CFG_H__

// Used files included
#ifndef   __VM_UTIL_H__
#    include <vmUtil.h>
#endif // __VM_UTIL_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit08Ptr : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit08Ptr
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
} STBIT08, *PSTBIT08;

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
} EMBITPOS, *PEMBITPOS;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CBit08Ptr(char& cValue, tchar*& const cpBuf, const size_t csztBufSize)
                      :mBit(*((unsigned char*)&cValue)),mpBuf(cpBuf),msztBufSize(csztBufSize){};
    explicit CBit08Ptr(unsigned char& cValue, tchar*& const cpBuf, const size_t csztBufSize)
                      :mBit(cValue), mpBuf(cpBuf), msztBufSize(csztBufSize) {};

    // Destruct define
    virtual ~CBit08Ptr(){};
    
public:
    // Copy construct define
    CBit08Ptr(const CBit08Ptr& obj):mBit(obj.mBit),mpBuf(obj.mpBuf),msztBufSize(obj.msztBufSize){};
    // Assignment define
    CBit08Ptr& operator = ( const CBit08Ptr& obj ){ mBit = obj.mBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit08Ptr& operator&(const CBit08Ptr& obj) { mBit = mBit & obj.mBit; return *this; };
    inline CBit08Ptr& operator&(const tchar     cVal) { mBit = mBit & cVal;     return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit08Ptr& operator|(const CBit08Ptr& obj) { mBit = mBit | obj.mBit; return *this; };
    inline CBit08Ptr& operator|(const tchar     cVal) { mBit = mBit | cVal;     return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit08Ptr& operator^(const CBit08Ptr& obj) { mBit = mBit ^ obj.mBit; return *this; };
    inline CBit08Ptr& operator^(const tchar     cVal) { mBit = mBit ^ cVal;     return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit08Ptr& operator~()                     { mBit = ~mBit;           return *this; };

    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
protected:
    unsigned char&  mBit;
    tchar*&         mpBuf;
    const size_t    msztBufSize;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前Bit类内存大小
    inline unsigned int  size() { return sizeof(mBit); }

    // 返回当前值
    inline char          toChar () { return (char)mBit; };
    inline unsigned char toUChar() { return       mBit; };

    inline void clear() { mBit = 0; vMemset(mpBuf,0x00, msztBufSize); };

    // 设置bit值
    inline void Set(const char          cVal) { mBit = cVal; };
    inline void Set(const unsigned char cVal) { mBit = cVal; };

    inline void Set01() { ((PSTBIT08)&mBit)->bit00 = 1; };
    inline void Set02() { ((PSTBIT08)&mBit)->bit01 = 1; };
    inline void Set03() { ((PSTBIT08)&mBit)->bit02 = 1; };
    inline void Set04() { ((PSTBIT08)&mBit)->bit03 = 1; };
    inline void Set05() { ((PSTBIT08)&mBit)->bit04 = 1; };
    inline void Set06() { ((PSTBIT08)&mBit)->bit05 = 1; };
    inline void Set07() { ((PSTBIT08)&mBit)->bit06 = 1; };
    inline void Set08() { ((PSTBIT08)&mBit)->bit07 = 1; };

    // 取消bit值设置
    inline void unSet(const char          cVal) { mBit = cVal; };
    inline void unSet(const unsigned char cVal) { mBit = cVal; };

    inline void unSet01() { ((PSTBIT08)mBit)->bit00 = 0; };
    inline void unSet02() { ((PSTBIT08)mBit)->bit01 = 0; };
    inline void unSet03() { ((PSTBIT08)mBit)->bit02 = 0; };
    inline void unSet04() { ((PSTBIT08)mBit)->bit03 = 0; };
    inline void unSet05() { ((PSTBIT08)mBit)->bit04 = 0; };
    inline void unSet06() { ((PSTBIT08)mBit)->bit05 = 0; };
    inline void unSet07() { ((PSTBIT08)mBit)->bit06 = 0; };
    inline void unSet08() { ((PSTBIT08)mBit)->bit07 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const char cVal) { (mBit)&cVal ? true : false; };

    inline bool isSet01() { return (((PSTBIT08)mBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((PSTBIT08)mBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((PSTBIT08)mBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((PSTBIT08)mBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((PSTBIT08)mBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((PSTBIT08)mBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((PSTBIT08)mBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((PSTBIT08)mBit)->bit07 & 1) ? true : false; };



}; // End of class CBit08Ptr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toBin08(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::toBin08()
{

}
// End of function toBin08(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toOct04(...)
// Brief     :
// Return    : tchar*
tchar* CBit08Ptr::toOct04()
{
}
// End of function toOct04(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toOct08(...)
// Brief     :
// Return    : tchar*
tchar* CBit08Ptr::toOct08()
{
}
// End of function toOct08(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toDec04(...)
// Brief     :
// Return    : tchar*
tchar* CBit08Ptr::toDec04()
{
}
// End of function toDec04(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toDec08(...)
// Brief     :
// Return    : tchar*
tchar* CBit08Ptr::toDec08()
{
}
// End of function toDec08(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toHex02(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::toHex02()
{
}
// End of function toHex02(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toHex04(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::toHex04()
{
}
// End of function toHex04(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toHex08(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::toHex08()
{
}
// End of function toHex08(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : to0xHex02(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::to0xHex02()
{
    vMemset(mpBuf, 0x00, msztBufSize);
    int liRet = v_sprintf(mpBuf, msztBufSize, vT("0x%02x"), mBit);
    return mpBuf;
}
// End of function to0xHex02(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : to0xHex04(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::to0xHex04()
{
    vMemset(mpBuf, 0x00, msztBufSize);
    int liRet = v_sprintf(mpBuf, msztBufSize, vT("0x%04x"), mBit);
    return mpBuf;
}
// End of function to0xHex04(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : to0xHex08(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::to0xHex08()
{
    vMemset(mpBuf, 0x00, msztBufSize);
    int liRet = v_sprintf(mpBuf, msztBufSize, vT("0x%08x"), mBit);
    return mpBuf;
}
// End of function to0xHex08(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toHeX02(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::toHeX02()
{
}
// End of function toHeX02(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toHeX04(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::toHeX04()
{
    vMemset(mpBuf, 0x00, msztBufSize);
    int liRet = v_sprintf(mpBuf, msztBufSize, vT("%04X"), mBit);
    return mpBuf;
}
// End of function toHeX04(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : toHeX08(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::toHeX08()
{
    vMemset(mpBuf, 0x00, msztBufSize);
    int liRet = v_sprintf(mpBuf, msztBufSize, vT("%08X"), mBit);
    return mpBuf;
}
// End of function toHeX08(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : to0xHeX02(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::to0xHeX02()
{
    vMemset(mpBuf, 0x00, msztBufSize);
    int liRet = v_sprintf(mpBuf, msztBufSize, vT("0x%02X"), mBit);
    return mpBuf;
}
// End of function to0xHeX02(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : to0xHeX04(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::to0xHeX04()
{
    vMemset(mpBuf, 0x00, msztBufSize);
    int liRet = v_sprintf(mpBuf, msztBufSize, vT("0x%04X"), mBit);
    return mpBuf;
}
// End of function to0xHeX04(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : to0xHeX08(...)
// Brief     :
// Return    : tchar*
inline tchar* CBit08Ptr::to0xHeX08()
{
    vMemset(mpBuf, 0x00, msztBufSize);
    int liRet = v_sprintf(mpBuf, msztBufSize, vT("0x%08X"), mBit);
    return mpBuf;
}
// End of function to0xHeX08(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CBIT08PTR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit08Ptr.h
/////////////////////////////////////////////////////////////////////////////////////////