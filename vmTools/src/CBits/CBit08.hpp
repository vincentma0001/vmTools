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

////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

#ifndef   __CBIT08PTR_H__
#    include <CBits/CBit08Ptr.h>
#endif // __CBIT08PTR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

#ifndef    _V_CBIT08_MAX_BUF_
#   define _V_CBIT08_MAX_BUF_ 16
#endif  // _V_CBIT08_MAX_BUF_

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit8 : 此类封装了8位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
template< size_t sztBufSize >
class CBit08 : public CBit08Ptr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline explicit CBit08(char          cVal) : CBit08Ptr( cVal, mszBuf, sztBufSize ) {};
    inline explicit CBit08(unsigned char cVal) : CBit08Ptr( cVal, mszBuf, sztBufSize ) {};
    inline explicit CBit08(char&         cVal) : CBit08Ptr( cVal, mszBuf, sztBufSize ) {};
    inline explicit CBit08(unsigned char&cVal) : CBit08Ptr( cVal, mszBuf, sztBufSize ) {};

    // Destruct define
    inline virtual ~CBit08(){};
    
public:
    // Copy construct define
    inline CBit08(const CBit08& obj):mBit(obj.mBit){};
    // Assignment define
    inline CBit08& operator = ( const CBit08& obj ){ mBit = obj.mBit; return *this; };

//public:
//     位与运算符(&) [00000011 & 00000101 = 00000001]
//    inline CBit08& operator&(const CBit08& obj) { mBit = mBit&obj.mBit; return *this; };
//    inline CBit08& operator&(const char  cVal) { mBit = mBit&cVal;     return *this; };
//     位或运算符(|) [00000011 | 00000101 = 00000111]
//    inline CBit08& operator|(const CBit08& obj) { mBit = mBit|obj.mBit; return *this; };
//    inline CBit08& operator|(const char  cVal) { mBit = mBit|cVal;     return *this; };
//     位异或运算符(^) [00000011 | 00000101 = 00000110]
//    inline CBit08& operator^(const CBit08& obj) { mBit = mBit^obj.mBit; return *this; };
//    inline CBit08& operator^(const char  cVal) { mBit = mBit^cVal;     return *this; };
//     位取反运算符(~) [~00000101 = 11111010]
//    inline CBit08& operator~() { mBit = ~mBit; return *this; };
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members
private:
    tchar          mszBuf[ sztBufSize ];

}; // End of class CBit8
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