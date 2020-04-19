/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CBitStr.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/04/16 10:27:37
// Modify time  : 2020/04/16 10:27:37
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

#ifndef __CBITSTR_H__
#define __CBITSTR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CBitStr : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template<typename CBitType>
class CBitStr
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :
#ifndef     _V_CBIT_STR_MAX_BUF_
#    define _V_CBIT_STR_MAX_BUF_ 128
#endif   // _V_CBIT_STR_MAX_BUF_

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CBitStr(CBitType& oBit):mBit(oBit){};
    // Destruct define
    virtual ~CBitStr(){};
    
private:
    // No Copy
    CBitStr(const CBitStr& obj){};
    // No Assignment
    CBitStr& operator = ( const CBitStr& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    CBitType&   mBitType;
    tchar       mszBuf[ _V_CBIT_STR_MAX_BUF_ ];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // 以二进制方式返回bit值字符串
    inline tchar* toBin()
    {
        vMemZero(mszBuf);
        tchar* lpPos = mszBuf;
        for (int i = mBitType.size()-1; i >= 0; i--)
        {
            (*lpPos) = ((mBit >> i) & 1) ? '1' : '0';;
            lpPos++;
        }
        return mszBuf;
    };
    // 以八进制方式返回bit值字符串
    tchar* toOct04()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%04o"), mBitType.mBit);
        return mszBuf;
    }
    tchar* toOct08()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%08o"), mBitType.mBit);
        return mszBuf;
    }
    // 以十进制方式返回bit值字符串
    tchar* toDec04()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%04d"), mBitType.mBit);
        return mszBuf;
    }
    tchar* toDec08()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%08d"), mBitType.mBit);
        return mszBuf;
    }
    // 以十六进制方式返回bit值字符串
    tchar* toHex02()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%02x"), mBitType.mBit);
        return mszBuf;
    }
    tchar* toHex04()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%04x"), mBitType.mBit);
        return mszBuf;
    }
    tchar* toHex08()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%08x"), mBitType.mBit);
        return mszBuf;
    }
    tchar* toHeX02()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%02X"), mBitType.mBit);
        return mszBuf;
    }
    tchar* toHeX04()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%04X"), mBitType.mBit);
        return mszBuf;
    }
    tchar* toHeX08()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%08X"), mBitType.mBit);
        return mszBuf;
    }

    // 以十六进制方式返回bit值以0x开头小写字符串,
    tchar* to0xHex02()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%0x02x"), mBitType.mBit);
        return mszBuf;
    }
    tchar* to0xHex04()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%0x04x"), mBitType.mBit);
        return mszBuf;
    }
    tchar* to0xHex08()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%0x08x"), mBitType.mBit);
        return mszBuf;
    }

    // 以十六进制方式返回bit值以0x开头大写字符串,
    tchar* to0xHeX02()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%0x02X"), mBitType.mBit);
        return mszBuf;
    }
    tchar* to0xHeX04()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%0x04X"), mBitType.mBit);
        return mszBuf;
    }
    tchar* to0xHeX08()
    {
        vMemZero(mszBuf);
        int liRet = v_sprintf(mszBuf, sizeof(mszBuf), vT("%0x08X"), mBitType.mBit);
        return mszBuf;
    }


}; // End of class CBitStr
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CBITSTR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CBitStr.h
/////////////////////////////////////////////////////////////////////////////////////////