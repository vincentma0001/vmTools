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
// 1 ������CPattern��������ͬ��Flag����Flag�Ƚϳ���CPattern��Ҫ������ӵ�CParser�С�
//
// ���� �� 
//          CPatter loP1( vT("%M1"),vStrlen("%M1"), vT("XXX"), vStrlen("XXXX") );
//          CPatter loP2( vT("%M"), vStrlen("%M"),  vT("XXX"), vStrlen("XXXX") );
//          CParser loParser;
//          loParser.Regist(loP1);
//          loParser.Regist(loP2);
//          loParser.Parser();
//
// --------------------------------------------------------------------------------------
// 2 ��֪���ø�ʽ
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
    // ׼����������
    vm::CStringPtr loFmt(mpFmt, msztFmtLen);
    size_t lsztFmtOffSet = 0;
    tchar* lpFmtEnd = mpFmt + msztFmtLen;

    vm::CStringPtr loOutBuf(pOutBuf, csztOutBufLen);
    size_t lsztOutBufOffset = 0;

    // ���ҵ�һ����ʶ���������Ҳ����򷵻ء�
    tchar* lpPos = loFmt.Find(mszSpecifier);
    if (lpPos == nullptr) 
        return nullptr;

    // ����ʶ����Դ���ݿ�ʼλ�õ����ݸ��Ƶ�Ŀ��������
    size_t lsztCount        = (lpPos - mpFmt);
    size_t lsztFirstCopied  = loOutBuf.CopyFm(mpFmt, lsztCount, 0);
    lsztOutBufOffset       += lsztFirstCopied;
    lsztFmtOffSet          += lsztFirstCopied;

    // ѭ����ÿһ��Pattern���жԱ�
    while (lpPos != nullptr)
    {
        // ���μ��Pattern��ʶ
        CPattern* lpPattern = mpPatterns;
        while (lpPattern != nullptr)
        {
            // ����ǰPattern���ʶ������ͬ����ת����һ��Pattern���м��
            if (!loFmt.Cmp(lpPattern->mpFlg, lpPattern->msztFlgLen, lsztFmtOffSet))
            {
                lpPattern = lpPattern->mpPattern;
                continue;
            }

            // ��Pattern������ַ��������滻 
            size_t lsztCopied = loOutBuf.CopyFm(lpPattern->mpRpl, lpPattern->msztRplLen, lsztOutBufOffset);
            lsztFmtOffSet += lpPattern->msztFlgLen;
            lsztOutBufOffset += lsztCopied;
            lpPattern = lpPattern->mpPattern;
            break;
        }

        // ������һ����ʶ�����ڵ�λ��
        tchar* lpNextPos = loFmt.Find(lsztFmtOffSet, mszSpecifier);
        if (lpNextPos != lpPos)
        {
            // ����ǰ��ʶ������һ����ʶ���е����ݸ��Ƶ�Ŀ��������
            size_t lsztCount = 0;
            if (lpNextPos == nullptr)
            {
                // ��ǰ��ʶ�����Բ����ڱ�ʶ��������ǰ��ʶ����Դ�ַ�����β�����ݸ��Ƶ�Ŀ���ַ����С�
                lsztCount = lpFmtEnd - (mpFmt + lsztFmtOffSet);
            }
            else
            {
                // ����ǰ��ʶ������һ����ʶ���е����ݸ��Ƶ�Ŀ��������
                lsztCount = lpNextPos - (mpFmt + lsztFmtOffSet);
            }
            size_t lsztCopied = loOutBuf.CopyFm(loFmt[ lsztFmtOffSet ], lsztCount, lsztOutBufOffset);
            lsztOutBufOffset += lsztCopied;
            lsztFmtOffSet += lsztCount;
            lpPos = lpNextPos;
        }
        else
        {
            // ��ǰ��ʶ���ĺ��治���ڿɽ���������
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