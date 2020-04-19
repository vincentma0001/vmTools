/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CBit64.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/06 00:51:45
// Modify time 	: 2020/01/06 00:51:45
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

#ifndef __CBIT64_H__
#define __CBIT64_H__

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
typedef struct stBit64
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

    unsigned int  bit32 : 1;
    unsigned int  bit33 : 1;
    unsigned int  bit34 : 1;
    unsigned int  bit35 : 1;
    unsigned int  bit36 : 1;
    unsigned int  bit37 : 1;
    unsigned int  bit38 : 1;
    unsigned int  bit39 : 1;

    unsigned int  bit40 : 1;
    unsigned int  bit41 : 1;
    unsigned int  bit42 : 1;
    unsigned int  bit43 : 1;
    unsigned int  bit44 : 1;
    unsigned int  bit45 : 1;
    unsigned int  bit46 : 1;
    unsigned int  bit47 : 1;

    unsigned int  bit48 : 1;
    unsigned int  bit49 : 1;
    unsigned int  bit50 : 1;
    unsigned int  bit51 : 1;
    unsigned int  bit52 : 1;
    unsigned int  bit53 : 1;
    unsigned int  bit54 : 1;
    unsigned int  bit55 : 1;

    unsigned int  bit56 : 1;
    unsigned int  bit57 : 1;
    unsigned int  bit58 : 1;
    unsigned int  bit59 : 1;
    unsigned int  bit60 : 1;
    unsigned int  bit61 : 1;
    unsigned int  bit62 : 1;
    unsigned int  bit63 : 1;

} STBIT64, *PSTBIT64;

/////////////////////////////////////////////////////////////////////////////////////////
// Macros define :

#define _V_CBIT64_POS_00_  0x0000000000000000

#define _V_CBIT64_POS_01_  0x0000000000000001
#define _V_CBIT64_POS_02_  0x0000000000000002
#define _V_CBIT64_POS_03_  0x0000000000000004
#define _V_CBIT64_POS_04_  0x0000000000000008
#define _V_CBIT64_POS_05_  0x0000000000000010
#define _V_CBIT64_POS_06_  0x0000000000000020
#define _V_CBIT64_POS_07_  0x0000000000000040
#define _V_CBIT64_POS_08_  0x0000000000000080

#define _V_CBIT64_POS_09_  0x0000000000000100
#define _V_CBIT64_POS_10_  0x0000000000000200
#define _V_CBIT64_POS_11_  0x0000000000000400
#define _V_CBIT64_POS_12_  0x0000000000000800
#define _V_CBIT64_POS_13_  0x0000000000001000
#define _V_CBIT64_POS_14_  0x0000000000002000
#define _V_CBIT64_POS_15_  0x0000000000004000
#define _V_CBIT64_POS_16_  0x0000000000008000

#define _V_CBIT64_POS_17_  0x0000000000010000
#define _V_CBIT64_POS_18_  0x0000000000020000
#define _V_CBIT64_POS_19_  0x0000000000040000
#define _V_CBIT64_POS_20_  0x0000000000080000
#define _V_CBIT64_POS_21_  0x0000000000100000
#define _V_CBIT64_POS_22_  0x0000000000200000
#define _V_CBIT64_POS_23_  0x0000000000400000
#define _V_CBIT64_POS_24_  0x0000000000800000

#define _V_CBIT64_POS_25_  0x0000000001000000
#define _V_CBIT64_POS_26_  0x0000000002000000
#define _V_CBIT64_POS_27_  0x0000000004000000
#define _V_CBIT64_POS_28_  0x0000000008000000
#define _V_CBIT64_POS_29_  0x0000000010000000
#define _V_CBIT64_POS_30_  0x0000000020000000
#define _V_CBIT64_POS_31_  0x0000000040000000
#define _V_CBIT64_POS_32_  0x0000000080000000

#define _V_CBIT64_POS_33_  0x0000000100000000
#define _V_CBIT64_POS_34_  0x0000000200000000
#define _V_CBIT64_POS_35_  0x0000000400000000
#define _V_CBIT64_POS_36_  0x0000000800000000
#define _V_CBIT64_POS_37_  0x0000001000000000
#define _V_CBIT64_POS_38_  0x0000002000000000
#define _V_CBIT64_POS_39_  0x0000004000000000
#define _V_CBIT64_POS_40_  0x0000008000000000

#define _V_CBIT64_POS_41_  0x0000010000000000
#define _V_CBIT64_POS_42_  0x0000020000000000
#define _V_CBIT64_POS_43_  0x0000040000000000
#define _V_CBIT64_POS_44_  0x0000080000000000
#define _V_CBIT64_POS_45_  0x0000100000000000
#define _V_CBIT64_POS_46_  0x0000200000000000
#define _V_CBIT64_POS_47_  0x0000400000000000
#define _V_CBIT64_POS_48_  0x0000800000000000

#define _V_CBIT64_POS_49_  0x0001000000000000
#define _V_CBIT64_POS_50_  0x0002000000000000
#define _V_CBIT64_POS_51_  0x0004000000000000
#define _V_CBIT64_POS_52_  0x0008000000000000
#define _V_CBIT64_POS_53_  0x0010000000000000
#define _V_CBIT64_POS_54_  0x0020000000000000
#define _V_CBIT64_POS_55_  0x0040000000000000
#define _V_CBIT64_POS_56_  0x0080000000000000

#define _V_CBIT64_POS_57_  0x0100000000000000
#define _V_CBIT64_POS_58_  0x0200000000000000
#define _V_CBIT64_POS_59_  0x0400000000000000
#define _V_CBIT64_POS_60_  0x0800000000000000
#define _V_CBIT64_POS_61_  0x1000000000000000
#define _V_CBIT64_POS_62_  0x2000000000000000
#define _V_CBIT64_POS_63_  0x4000000000000000
#define _V_CBIT64_POS_64_  0x8000000000000000

#define _V_CBIT64_POS_FF_  0xFFFFFFFFFFFFFFFF

#define _V_CBIT64_MAX_BUF_ 65
/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBit64 : 此类封装了64位Bit字节操作
//
/////////////////////////////////////////////////////////////////////////////////////////
class CBit64
{
/////////////////////////////////////////////////////////////////////////////////////////
// Types define :
public:
    typedef struct stBit64
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

        unsigned int  bit32 : 1;
        unsigned int  bit33 : 1;
        unsigned int  bit34 : 1;
        unsigned int  bit35 : 1;
        unsigned int  bit36 : 1;
        unsigned int  bit37 : 1;
        unsigned int  bit38 : 1;
        unsigned int  bit39 : 1;

        unsigned int  bit40 : 1;
        unsigned int  bit41 : 1;
        unsigned int  bit42 : 1;
        unsigned int  bit43 : 1;
        unsigned int  bit44 : 1;
        unsigned int  bit45 : 1;
        unsigned int  bit46 : 1;
        unsigned int  bit47 : 1;

        unsigned int  bit48 : 1;
        unsigned int  bit49 : 1;
        unsigned int  bit50 : 1;
        unsigned int  bit51 : 1;
        unsigned int  bit52 : 1;
        unsigned int  bit53 : 1;
        unsigned int  bit54 : 1;
        unsigned int  bit55 : 1;

        unsigned int  bit56 : 1;
        unsigned int  bit57 : 1;
        unsigned int  bit58 : 1;
        unsigned int  bit59 : 1;
        unsigned int  bit60 : 1;
        unsigned int  bit61 : 1;
        unsigned int  bit62 : 1;
        unsigned int  bit63 : 1;

    };

    typedef enum emBitPos
    {
        PosFF = 0xFFFFFFFFFFFFFFFF,
        Pos00 = 0x0000000000000000,

        Pos01 = 0x0000000000000001,
        Pos02 = 0x0000000000000002,
        Pos03 = 0x0000000000000004,
        Pos04 = 0x0000000000000008,
        Pos05 = 0x0000000000000010,
        Pos06 = 0x0000000000000020,
        Pos07 = 0x0000000000000040,
        Pos08 = 0x0000000000000080,

        Pos09 = 0x0000000000000100,
        Pos10 = 0x0000000000000200,
        Pos11 = 0x0000000000000400,
        Pos12 = 0x0000000000000800,
        Pos13 = 0x0000000000001000,
        Pos14 = 0x0000000000002000,
        Pos15 = 0x0000000000004000,
        Pos16 = 0x0000000000008000,

        Pos17 = 0x0000000000010000,
        Pos18 = 0x0000000000020000,
        Pos19 = 0x0000000000040000,
        Pos20 = 0x0000000000080000,
        Pos21 = 0x0000000000100000,
        Pos22 = 0x0000000000200000,
        Pos23 = 0x0000000000300000,
        Pos24 = 0x0000000000800000,

        Pos25 = 0x0000000001000000,
        Pos26 = 0x0000000002000000,
        Pos27 = 0x0000000004000000,
        Pos28 = 0x0000000008000000,
        Pos29 = 0x0000000010000000,
        Pos30 = 0x0000000020000000,
        Pos31 = 0x0000000040000000,
        Pos32 = 0x0000000080000000,

        Pos33 = 0x0000000100000000,
        Pos34 = 0x0000000200000000,
        Pos35 = 0x0000000400000000,
        Pos36 = 0x0000000800000000,
        Pos37 = 0x0000001000000000,
        Pos38 = 0x0000002000000000,
        Pos39 = 0x0000004000000000,
        Pos40 = 0x0000008000000000,

        Pos41 = 0x0000010000000000,
        Pos42 = 0x0000020000000000,
        Pos43 = 0x0000040000000000,
        Pos44 = 0x0000080000000000,
        Pos45 = 0x0000100000000000,
        Pos46 = 0x0000200000000000,
        Pos47 = 0x0000400000000000,
        Pos48 = 0x0000800000000000,

        Pos49 = 0x0001000000000000,
        Pos50 = 0x0002000000000000,
        Pos51 = 0x0004000000000000,
        Pos52 = 0x0008000000000000,
        Pos53 = 0x0010000000000000,
        Pos54 = 0x0020000000000000,
        Pos55 = 0x0040000000000000,
        Pos56 = 0x0080000000000000,

        Pos57 = 0x0100000000000000,
        Pos58 = 0x0200000000000000,
        Pos59 = 0x0400000000000000,
        Pos60 = 0x0800000000000000,
        Pos61 = 0x1000000000000000,
        Pos62 = 0x2000000000000000,
        Pos63 = 0x4000000000000000,
        Pos64 = 0x8000000000000000
    };

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    inline CBit64(long long&          cVal) :mBit(*((unsigned long long*)&cVal)) {};
    inline CBit64(unsigned long long& cVal) :mBit(cVal) {};
    // Destruct define
    inline virtual ~CBit64() {};

public:
    // Copy construct define
    inline CBit64(const CBit64& obj) :mBit(obj.mBit) {};
    // Assignment define
    inline CBit64& operator = (const CBit64& obj) { mBit = obj.mBit; return *this; };

public:
    // 位与运算符(&) [00000011 & 00000101 = 00000001]
    inline CBit64& operator&(const CBit64& obj) { mBit = mBit & obj.mBit; return *this; };
    inline CBit64& operator&(const long long  cVal) { mBit = mBit & cVal;     return *this; };
    // 位或运算符(|) [00000011 | 00000101 = 00000111]
    inline CBit64& operator|(const CBit64& obj) { mBit = mBit | obj.mBit; return *this; };
    inline CBit64& operator|(const long long  cVal) { mBit = mBit | cVal;     return *this; };
    // 位异或运算符(^) [00000011 | 00000101 = 00000110]
    inline CBit64& operator^(const CBit64& obj) { mBit = mBit ^ obj.mBit; return *this; };
    inline CBit64& operator^(const long long  cVal) { mBit = mBit ^ cVal;     return *this; };
    // 位取反运算符(~) [~00000101 = 11111010]
    inline CBit64& operator~() { mBit = ~mBit; return *this; };

/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    unsigned long long&  mBit;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 返回当前Bit类内存大小
    inline unsigned int       size()     { return sizeof(mBit); };
    // 重置Bit数值
    inline void               reset()    { mBit = 0; };

    // 返回当前值
    inline long long          toLLong()  { return mBit; };
    inline unsigned long long toULLong() { return mBit; };

    // 设置bit值
    inline void Set(const long long          cVal) { mBit = cVal; };
    inline void Set(const unsigned long long cVal) { mBit = cVal; };

    inline void Set01() { ((stBit64*)&mBit)->bit00 = 1; };
    inline void Set02() { ((stBit64*)&mBit)->bit01 = 1; };
    inline void Set03() { ((stBit64*)&mBit)->bit02 = 1; };
    inline void Set04() { ((stBit64*)&mBit)->bit03 = 1; };
    inline void Set05() { ((stBit64*)&mBit)->bit04 = 1; };
    inline void Set06() { ((stBit64*)&mBit)->bit05 = 1; };
    inline void Set07() { ((stBit64*)&mBit)->bit06 = 1; };
    inline void Set08() { ((stBit64*)&mBit)->bit07 = 1; };

    inline void Set09() { ((stBit64*)&mBit)->bit08 = 1; };
    inline void Set10() { ((stBit64*)&mBit)->bit09 = 1; };
    inline void Set11() { ((stBit64*)&mBit)->bit10 = 1; };
    inline void Set12() { ((stBit64*)&mBit)->bit11 = 1; };
    inline void Set13() { ((stBit64*)&mBit)->bit12 = 1; };
    inline void Set14() { ((stBit64*)&mBit)->bit13 = 1; };
    inline void Set15() { ((stBit64*)&mBit)->bit14 = 1; };
    inline void Set16() { ((stBit64*)&mBit)->bit15 = 1; };

    inline void Set17() { ((stBit64*)&mBit)->bit16 = 1; };
    inline void Set18() { ((stBit64*)&mBit)->bit17 = 1; };
    inline void Set19() { ((stBit64*)&mBit)->bit18 = 1; };
    inline void Set20() { ((stBit64*)&mBit)->bit19 = 1; };
    inline void Set21() { ((stBit64*)&mBit)->bit20 = 1; };
    inline void Set22() { ((stBit64*)&mBit)->bit21 = 1; };
    inline void Set23() { ((stBit64*)&mBit)->bit22 = 1; };
    inline void Set24() { ((stBit64*)&mBit)->bit23 = 1; };

    inline void Set25() { ((stBit64*)&mBit)->bit24 = 1; };
    inline void Set26() { ((stBit64*)&mBit)->bit25 = 1; };
    inline void Set27() { ((stBit64*)&mBit)->bit26 = 1; };
    inline void Set28() { ((stBit64*)&mBit)->bit27 = 1; };
    inline void Set29() { ((stBit64*)&mBit)->bit28 = 1; };
    inline void Set30() { ((stBit64*)&mBit)->bit29 = 1; };
    inline void Set31() { ((stBit64*)&mBit)->bit30 = 1; };

    inline void Set32() { ((stBit64*)&mBit)->bit31 = 1; };
    inline void Set33() { ((stBit64*)&mBit)->bit32 = 1; };
    inline void Set34() { ((stBit64*)&mBit)->bit33 = 1; };
    inline void Set35() { ((stBit64*)&mBit)->bit34 = 1; };
    inline void Set36() { ((stBit64*)&mBit)->bit35 = 1; };
    inline void Set37() { ((stBit64*)&mBit)->bit36 = 1; };
    inline void Set38() { ((stBit64*)&mBit)->bit37 = 1; };
    inline void Set39() { ((stBit64*)&mBit)->bit38 = 1; };

    inline void Set40() { ((stBit64*)&mBit)->bit39 = 1; };
    inline void Set41() { ((stBit64*)&mBit)->bit40 = 1; };
    inline void Set42() { ((stBit64*)&mBit)->bit41 = 1; };
    inline void Set43() { ((stBit64*)&mBit)->bit42 = 1; };
    inline void Set44() { ((stBit64*)&mBit)->bit43 = 1; };
    inline void Set45() { ((stBit64*)&mBit)->bit44 = 1; };
    inline void Set46() { ((stBit64*)&mBit)->bit45 = 1; };
    inline void Set47() { ((stBit64*)&mBit)->bit46 = 1; };

    inline void Set48() { ((stBit64*)&mBit)->bit47 = 1; };
    inline void Set49() { ((stBit64*)&mBit)->bit48 = 1; };
    inline void Set50() { ((stBit64*)&mBit)->bit49 = 1; };
    inline void Set51() { ((stBit64*)&mBit)->bit50 = 1; };
    inline void Set52() { ((stBit64*)&mBit)->bit51 = 1; };
    inline void Set53() { ((stBit64*)&mBit)->bit52 = 1; };
    inline void Set54() { ((stBit64*)&mBit)->bit53 = 1; };
    inline void Set55() { ((stBit64*)&mBit)->bit54 = 1; };

    inline void Set56() { ((stBit64*)&mBit)->bit55 = 1; };
    inline void Set57() { ((stBit64*)&mBit)->bit56 = 1; };
    inline void Set58() { ((stBit64*)&mBit)->bit57 = 1; };
    inline void Set59() { ((stBit64*)&mBit)->bit58 = 1; };
    inline void Set60() { ((stBit64*)&mBit)->bit59 = 1; };
    inline void Set61() { ((stBit64*)&mBit)->bit60 = 1; };
    inline void Set62() { ((stBit64*)&mBit)->bit61 = 1; };
    inline void Set63() { ((stBit64*)&mBit)->bit62 = 1; };
    inline void Set64() { ((stBit64*)&mBit)->bit63 = 1; };

    // 取消bit值设置
    inline void unSet(const long long          cVal) { mBit = cVal; };
    inline void unSet(const unsigned long long cVal) { mBit = cVal; };

    inline void unSet01() { ((stBit64*)&mBit)->bit00 = 0; };
    inline void unSet02() { ((stBit64*)&mBit)->bit01 = 0; };
    inline void unSet03() { ((stBit64*)&mBit)->bit02 = 0; };
    inline void unSet04() { ((stBit64*)&mBit)->bit03 = 0; };
    inline void unSet05() { ((stBit64*)&mBit)->bit04 = 0; };
    inline void unSet06() { ((stBit64*)&mBit)->bit05 = 0; };
    inline void unSet07() { ((stBit64*)&mBit)->bit06 = 0; };
    inline void unSet08() { ((stBit64*)&mBit)->bit07 = 0; };

    inline void unSet09() { ((stBit64*)&mBit)->bit08 = 0; };
    inline void unSet10() { ((stBit64*)&mBit)->bit09 = 0; };
    inline void unSet11() { ((stBit64*)&mBit)->bit10 = 0; };
    inline void unSet12() { ((stBit64*)&mBit)->bit11 = 0; };
    inline void unSet13() { ((stBit64*)&mBit)->bit12 = 0; };
    inline void unSet14() { ((stBit64*)&mBit)->bit13 = 0; };
    inline void unSet15() { ((stBit64*)&mBit)->bit14 = 0; };
    inline void unSet16() { ((stBit64*)&mBit)->bit15 = 0; };

    inline void unSet17() { ((stBit64*)&mBit)->bit16 = 0; };
    inline void unSet18() { ((stBit64*)&mBit)->bit17 = 0; };
    inline void unSet19() { ((stBit64*)&mBit)->bit18 = 0; };
    inline void unSet20() { ((stBit64*)&mBit)->bit19 = 0; };
    inline void unSet21() { ((stBit64*)&mBit)->bit20 = 0; };
    inline void unSet22() { ((stBit64*)&mBit)->bit21 = 0; };
    inline void unSet23() { ((stBit64*)&mBit)->bit22 = 0; };
    inline void unSet24() { ((stBit64*)&mBit)->bit23 = 0; };

    inline void unSet25() { ((stBit64*)&mBit)->bit24 = 0; };
    inline void unSet26() { ((stBit64*)&mBit)->bit25 = 0; };
    inline void unSet27() { ((stBit64*)&mBit)->bit26 = 0; };
    inline void unSet28() { ((stBit64*)&mBit)->bit27 = 0; };
    inline void unSet29() { ((stBit64*)&mBit)->bit28 = 0; };
    inline void unSet30() { ((stBit64*)&mBit)->bit29 = 0; };
    inline void unSet31() { ((stBit64*)&mBit)->bit30 = 0; };
    inline void unSet32() { ((stBit64*)&mBit)->bit31 = 0; };

    inline void unSet33() { ((stBit64*)&mBit)->bit32 = 0; };
    inline void unSet34() { ((stBit64*)&mBit)->bit33 = 0; };
    inline void unSet35() { ((stBit64*)&mBit)->bit34 = 0; };
    inline void unSet36() { ((stBit64*)&mBit)->bit35 = 0; };
    inline void unSet37() { ((stBit64*)&mBit)->bit36 = 0; };
    inline void unSet38() { ((stBit64*)&mBit)->bit37 = 0; };
    inline void unSet39() { ((stBit64*)&mBit)->bit38 = 0; };
    inline void unSet40() { ((stBit64*)&mBit)->bit39 = 0; };

    inline void unSet41() { ((stBit64*)&mBit)->bit40 = 0; };
    inline void unSet42() { ((stBit64*)&mBit)->bit41 = 0; };
    inline void unSet43() { ((stBit64*)&mBit)->bit42 = 0; };
    inline void unSet44() { ((stBit64*)&mBit)->bit43 = 0; };
    inline void unSet45() { ((stBit64*)&mBit)->bit44 = 0; };
    inline void unSet46() { ((stBit64*)&mBit)->bit45 = 0; };
    inline void unSet47() { ((stBit64*)&mBit)->bit46 = 0; };
    inline void unSet48() { ((stBit64*)&mBit)->bit47 = 0; };

    inline void unSet49() { ((stBit64*)&mBit)->bit48 = 0; };
    inline void unSet50() { ((stBit64*)&mBit)->bit49 = 0; };
    inline void unSet51() { ((stBit64*)&mBit)->bit50 = 0; };
    inline void unSet52() { ((stBit64*)&mBit)->bit51 = 0; };
    inline void unSet53() { ((stBit64*)&mBit)->bit52 = 0; };
    inline void unSet54() { ((stBit64*)&mBit)->bit53 = 0; };
    inline void unSet55() { ((stBit64*)&mBit)->bit54 = 0; };
    inline void unSet56() { ((stBit64*)&mBit)->bit55 = 0; };

    inline void unSet57() { ((stBit64*)&mBit)->bit56 = 0; };
    inline void unSet58() { ((stBit64*)&mBit)->bit57 = 0; };
    inline void unSet59() { ((stBit64*)&mBit)->bit58 = 0; };
    inline void unSet60() { ((stBit64*)&mBit)->bit59 = 0; };
    inline void unSet61() { ((stBit64*)&mBit)->bit60 = 0; };
    inline void unSet62() { ((stBit64*)&mBit)->bit61 = 0; };
    inline void unSet63() { ((stBit64*)&mBit)->bit62 = 0; };
    inline void unSet64() { ((stBit64*)&mBit)->bit63 = 0; };

    // 判断Bit位是非被设置
    inline bool isSet(const long long cVal) { mBit&cVal ? true : false; };

    inline bool isSet01() { return (((stBit64*)&mBit)->bit00 & 1) ? true : false; };
    inline bool isSet02() { return (((stBit64*)&mBit)->bit01 & 1) ? true : false; };
    inline bool isSet03() { return (((stBit64*)&mBit)->bit02 & 1) ? true : false; };
    inline bool isSet04() { return (((stBit64*)&mBit)->bit03 & 1) ? true : false; };
    inline bool isSet05() { return (((stBit64*)&mBit)->bit04 & 1) ? true : false; };
    inline bool isSet06() { return (((stBit64*)&mBit)->bit05 & 1) ? true : false; };
    inline bool isSet07() { return (((stBit64*)&mBit)->bit06 & 1) ? true : false; };
    inline bool isSet08() { return (((stBit64*)&mBit)->bit07 & 1) ? true : false; };

    inline bool isSet09() { return (((stBit64*)&mBit)->bit08 & 1) ? true : false; };
    inline bool isSet10() { return (((stBit64*)&mBit)->bit09 & 1) ? true : false; };
    inline bool isSet11() { return (((stBit64*)&mBit)->bit10 & 1) ? true : false; };
    inline bool isSet12() { return (((stBit64*)&mBit)->bit11 & 1) ? true : false; };
    inline bool isSet13() { return (((stBit64*)&mBit)->bit12 & 1) ? true : false; };
    inline bool isSet14() { return (((stBit64*)&mBit)->bit13 & 1) ? true : false; };
    inline bool isSet15() { return (((stBit64*)&mBit)->bit14 & 1) ? true : false; };
    inline bool isSet16() { return (((stBit64*)&mBit)->bit15 & 1) ? true : false; };

    inline bool isSet17() { return (((stBit64*)&mBit)->bit16 & 1) ? true : false; };
    inline bool isSet18() { return (((stBit64*)&mBit)->bit17 & 1) ? true : false; };
    inline bool isSet19() { return (((stBit64*)&mBit)->bit18 & 1) ? true : false; };
    inline bool isSet20() { return (((stBit64*)&mBit)->bit19 & 1) ? true : false; };
    inline bool isSet21() { return (((stBit64*)&mBit)->bit20 & 1) ? true : false; };
    inline bool isSet22() { return (((stBit64*)&mBit)->bit21 & 1) ? true : false; };
    inline bool isSet23() { return (((stBit64*)&mBit)->bit22 & 1) ? true : false; };
    inline bool isSet24() { return (((stBit64*)&mBit)->bit23 & 1) ? true : false; };

    inline bool isSet25() { return (((stBit64*)&mBit)->bit24 & 1) ? true : false; };
    inline bool isSet26() { return (((stBit64*)&mBit)->bit25 & 1) ? true : false; };
    inline bool isSet27() { return (((stBit64*)&mBit)->bit26 & 1) ? true : false; };
    inline bool isSet28() { return (((stBit64*)&mBit)->bit27 & 1) ? true : false; };
    inline bool isSet29() { return (((stBit64*)&mBit)->bit28 & 1) ? true : false; };
    inline bool isSet30() { return (((stBit64*)&mBit)->bit29 & 1) ? true : false; };
    inline bool isSet31() { return (((stBit64*)&mBit)->bit30 & 1) ? true : false; };
    inline bool isSet32() { return (((stBit64*)&mBit)->bit31 & 1) ? true : false; };

    inline bool isSet33() { return (((stBit64*)&mBit)->bit32 & 1) ? true : false; };
    inline bool isSet34() { return (((stBit64*)&mBit)->bit33 & 1) ? true : false; };
    inline bool isSet35() { return (((stBit64*)&mBit)->bit34 & 1) ? true : false; };
    inline bool isSet36() { return (((stBit64*)&mBit)->bit35 & 1) ? true : false; };
    inline bool isSet37() { return (((stBit64*)&mBit)->bit36 & 1) ? true : false; };
    inline bool isSet38() { return (((stBit64*)&mBit)->bit37 & 1) ? true : false; };
    inline bool isSet39() { return (((stBit64*)&mBit)->bit38 & 1) ? true : false; };
    inline bool isSet40() { return (((stBit64*)&mBit)->bit39 & 1) ? true : false; };

    inline bool isSet41() { return (((stBit64*)&mBit)->bit40 & 1) ? true : false; };
    inline bool isSet42() { return (((stBit64*)&mBit)->bit41 & 1) ? true : false; };
    inline bool isSet43() { return (((stBit64*)&mBit)->bit42 & 1) ? true : false; };
    inline bool isSet44() { return (((stBit64*)&mBit)->bit43 & 1) ? true : false; };
    inline bool isSet45() { return (((stBit64*)&mBit)->bit44 & 1) ? true : false; };
    inline bool isSet46() { return (((stBit64*)&mBit)->bit45 & 1) ? true : false; };
    inline bool isSet47() { return (((stBit64*)&mBit)->bit46 & 1) ? true : false; };
    inline bool isSet48() { return (((stBit64*)&mBit)->bit47 & 1) ? true : false; };

    inline bool isSet49() { return (((stBit64*)&mBit)->bit48 & 1) ? true : false; };
    inline bool isSet50() { return (((stBit64*)&mBit)->bit49 & 1) ? true : false; };
    inline bool isSet51() { return (((stBit64*)&mBit)->bit50 & 1) ? true : false; };
    inline bool isSet52() { return (((stBit64*)&mBit)->bit51 & 1) ? true : false; };
    inline bool isSet53() { return (((stBit64*)&mBit)->bit52 & 1) ? true : false; };
    inline bool isSet54() { return (((stBit64*)&mBit)->bit53 & 1) ? true : false; };
    inline bool isSet55() { return (((stBit64*)&mBit)->bit54 & 1) ? true : false; };
    inline bool isSet56() { return (((stBit64*)&mBit)->bit55 & 1) ? true : false; };

    inline bool isSet57() { return (((stBit64*)&mBit)->bit56 & 1) ? true : false; };
    inline bool isSet58() { return (((stBit64*)&mBit)->bit57 & 1) ? true : false; };
    inline bool isSet59() { return (((stBit64*)&mBit)->bit58 & 1) ? true : false; };
    inline bool isSet60() { return (((stBit64*)&mBit)->bit59 & 1) ? true : false; };
    inline bool isSet61() { return (((stBit64*)&mBit)->bit60 & 1) ? true : false; };
    inline bool isSet62() { return (((stBit64*)&mBit)->bit61 & 1) ? true : false; };
    inline bool isSet63() { return (((stBit64*)&mBit)->bit62 & 1) ? true : false; };
    inline bool isSet64() { return (((stBit64*)&mBit)->bit63 & 1) ? true : false; };

/////////////////////////////////////////////////////////////////////////////////////////
// Friends define: 
friend class CBitStr;

}; // End of class CBit64
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CBIT64_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBit64.h
/////////////////////////////////////////////////////////////////////////////////////////