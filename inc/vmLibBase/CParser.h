/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CParser.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/09 08:43:50
// Modify time  : 2020/01/09 08:43:50
// Note         :
// --------------------------------------------------------------------------------------
// 1 若两个CPattern都存在相同的Flag，则Flag比较长的CPattern需要有限添加到CParser中。
//
// 例如 ： 
//          CPatter loP1( vT("%M1"),vStrlen("%M1"), vT("XXX"), vStrlen("XXXX") );
//          CPatter loP2( vT("%M"), vStrlen("%M"),  vT("XXX"), vStrlen("XXXX") );
//          CParser loParser;
//          loParser.Regist(loP1);
//          loParser.Regist(loP2);
//          loParser.Parser();
//
// --------------------------------------------------------------------------------------
// 2 已知可用格式
//    1 - ""
//    2 - "%"
//    3 - "%%"
//    4 - "this is a test%"
//    5 - "%this is a test%"
//    6 - "this is a test [%F:%L] -  %M"
//    7 - "this is a test [%F%L] -  %M"
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

#ifndef __CPARSER_H__
#define __CPARSER_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :

#ifndef   __CSTRINGPTR_H__
#   include <vmLibBase/CStringPtr.h>
#endif // __CSTRINGPTR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CParser : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CParser
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
public:
    /////////////////////////////////////////////////////////////////////////////////////
    // class CPattern
    class CPattern
    {
        friend CParser;
    public:
        explicit CPattern( const tchar* const cpFlg, const size_t csztFlgLen,
                           const tchar* const cpRpl, const size_t csztRplLen );
        explicit CPattern( const tchar* const cpFlg, const tchar* const cpRpl );
        virtual ~CPattern();
    public:
        const tchar*    mpFlg;
        size_t          msztFlgLen;
        const tchar*    mpRpl;
        size_t          msztRplLen;

    private:
        CPattern*       mpPattern;

    private:
        CPattern*&      GetLastPattern();

    }; // End of class CPattern

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    CParser( const tchar cszSpecifier, const tchar* const cpFmt, const size_t csztFmtLen);
    CParser( const tchar cszSpecifier, const tchar* const cpFmt);

    // Destruct define
    virtual ~CParser();
private:
    // No Copy
    CParser(const CParser& obj){};
    // No Assignment
    CParser& operator = ( const CParser& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tchar           mszSpecifier;
    tchar*          mpFmt;
    size_t          msztFmtLen;
    CPattern*       mpPatterns;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    void   Regist( CPattern& oFlag );
    tchar* Parse ( tchar* const pOutBuf, const size_t csztOutBufLen );

}; // End of class CParser
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CPattern(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
CParser::CPattern::CPattern(const tchar* const cpFlg, const size_t csztFlgLen,
                            const tchar* const cpRpl, const size_t csztRplLen)
                           :mpFlg(cpFlg), msztFlgLen(csztFlgLen),
                            mpRpl(cpRpl), msztRplLen(csztRplLen),
                            mpPattern(nullptr) 
{

};
// End of function CPattern(...)
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CPattern(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
CParser::CPattern::CPattern(const tchar* const cpFlg, const tchar* const cpRpl)
                           :mpFlg(cpFlg), msztFlgLen(vStrlen(cpFlg)),
                            mpRpl(cpRpl), msztRplLen(vStrlen(cpRpl)),
                            mpPattern(nullptr) 
{

};
// End of function CPattern(...)
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ~CPattern(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
CParser::CPattern::~CPattern()
{
    mpFlg       = nullptr;
    mpRpl       = nullptr;
    mpPattern   = nullptr;
};
// End of function ~CPattern(...)
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
// Method    : GetLastPattern(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
CParser::CPattern*& CParser::CPattern::GetLastPattern()
{
    if (mpPattern == nullptr)
        return mpPattern;

    return mpPattern->GetLastPattern();
}
// End of function GetLastPattern(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CParser(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
CParser::CParser( const tchar cszSpecifier, const tchar* const cpFmt, const size_t csztFmtLen )
                 :mszSpecifier(cszSpecifier), mpPatterns(nullptr),
                  mpFmt(const_cast<tchar*>(mpFmt)), msztFmtLen(csztFmtLen) 
{

};
// End of function CParser(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : CParser(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
CParser::CParser( const tchar cszSpecifier, const tchar* const cpFmt )
                 :mszSpecifier(cszSpecifier), mpPatterns(nullptr),
                  mpFmt(const_cast<tchar*>(cpFmt)), msztFmtLen(vStrlen(cpFmt)) 
{

};
// End of function CParser(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : ~CParser(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
// Destruct define
CParser::~CParser()
{
    mpPatterns = nullptr;
}
// End of function ~CParser(...)
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Regist(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
void CParser::Regist(CPattern& oFlag)
{
    if (mpPatterns == nullptr)
    {
        mpPatterns = &oFlag; 
        return;
    };

    CPattern*& lpFlag = mpPatterns->GetLastPattern();
    lpFlag = &oFlag;
}
// End of function Regist(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Parse(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
tchar* CParser::Parse(tchar* const pOutBuf, const size_t csztOutBufLen)
{
    // 准备解析数据
    vm::CStringPtr loFmt(mpFmt, msztFmtLen);
    size_t lsztFmtOffSet = 0;
    tchar* lpFmtEnd = mpFmt + msztFmtLen;

    vm::CStringPtr loOutBuf(pOutBuf, csztOutBufLen);
    size_t lsztOutBufOffset = 0;

    // 查找第一个标识符，若查找不到则返回。
    tchar* lpPos = loFmt.Find(mszSpecifier);
    if (lpPos == nullptr) 
        return nullptr;

    // 将标识符到源数据开始位置的数据复制到目标数据中
    size_t lsztCount        = (lpPos - mpFmt);
    size_t lsztFirstCopied  = loOutBuf.CopyFm(mpFmt, lsztCount, 0);
    lsztOutBufOffset       += lsztFirstCopied;
    lsztFmtOffSet          += lsztFirstCopied;

    // 循环对每一个Pattern进行对比
    while (lpPos != nullptr)
    {
        // 依次检测Pattern标识
        CPattern* lpPattern = mpPatterns;
        while (lpPattern != nullptr)
        {
            // 若当前Pattern与标识符不相同，将转到下一个Pattern进行检测
            if (!loFmt.Cmp(lpPattern->mpFlg, lpPattern->msztFlgLen, lsztFmtOffSet))
            {
                lpPattern = lpPattern->mpPattern;
                continue;
            }

            // 对Pattern代表的字符串进行替换 
            size_t lsztCopied = loOutBuf.CopyFm(lpPattern->mpRpl, lpPattern->msztRplLen, lsztOutBufOffset);
            lsztFmtOffSet += lpPattern->msztFlgLen;
            lsztOutBufOffset += lsztCopied;
            lpPattern = lpPattern->mpPattern;
            break;
        }

        // 查找下一个标识符所在的位置
        tchar* lpNextPos = loFmt.Find(lsztFmtOffSet, mszSpecifier);
        if (lpNextPos != lpPos)
        {
            // 将当前标识符与下一个标识符中的数据复制到目标数据中
            size_t lsztCount = 0;
            if (lpNextPos == nullptr)
            {
                // 当前标识符后以不存在标识符，将当前标识符到源字符串结尾的数据复制到目标字符串中。
                lsztCount = lpFmtEnd - (mpFmt + lsztFmtOffSet);
            }
            else
            {
                // 将当前标识符与下一个标识符中的数据复制到目标数据中
                lsztCount = lpNextPos - (mpFmt + lsztFmtOffSet);
            }
            size_t lsztCopied = loOutBuf.CopyFm(loFmt[ lsztFmtOffSet ], lsztCount, lsztOutBufOffset);
            lsztOutBufOffset += lsztCopied;
            lsztFmtOffSet += lsztCount;
            lpPos = lpNextPos;
        }
        else
        {
            // 当前标识符的后面不存在可解析的数据
            size_t lsztCopied = loOutBuf.CopyFm(loFmt[ lsztFmtOffSet ], sizeof(mszSpecifier), lsztOutBufOffset);
            lsztFmtOffSet += lsztCopied;
            lsztOutBufOffset += lsztCopied;
            //lpNextPos         = loFmt.Find(lsztFmtOffSet, mszSpecifier);
            lpPos = lpNextPos;
        }
    }

    return pOutBuf;
}
// End of function Parse(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CPARSER_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CParser.h
/////////////////////////////////////////////////////////////////////////////////////////