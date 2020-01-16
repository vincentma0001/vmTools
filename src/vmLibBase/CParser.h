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
// Config files included
#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>
#endif // __VM_CFG_H__

// Used files included
#ifndef   __VM_UTIL_H__
#	error this file need #include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

#ifndef   __CSTRPTR_H__
#	error this file need #include <vmLibBase/CStrPtr.h>
#endif // __CSTRPTR_H__

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
    class CPattern
    {
        friend CParser;
    public:
        explicit CPattern( const tChar* const cpFlg, const tSize csztFlgLen,
                           const tChar* const cpRpl, const tSize csztRplLen )
                          :mpFlg(const_cast<tChar*>(cpFlg)), msztFlgLen(csztFlgLen), 
                           mpRpl(const_cast<tChar*>(cpRpl)), msztRplLen(csztRplLen),
                           mpPattern(nullptr) {};
        explicit CPattern( const tChar* const cpFlg, const tChar* const cpRpl )
                          :mpFlg(const_cast<tChar*>(cpFlg)), msztFlgLen(vStrLen(cpFlg)), 
                           mpRpl(const_cast<tChar*>(cpRpl)), msztRplLen(vStrLen(cpRpl)),
                           mpPattern(nullptr) {};
        virtual ~CPattern() 
        { 
            mpFlg     = nullptr; 
            mpRpl     = nullptr; 
            mpPattern = nullptr; 
        };
    public:
        tChar*  mpFlg;
        tSize   msztFlgLen;
        tChar*  mpRpl;
        tSize   msztRplLen;

    private:
        CPattern*  mpPattern;

    private:
        CPattern*& GetLastPattern()
        {
            if (mpPattern == nullptr)
                return mpPattern;

            return mpPattern->GetLastPattern();
        }
    }; // End of class CPattern

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    CParser( const tChar cszSpecifier, const tChar* const cpFmt, const tSize csztFmtLen) 
            :mszSpecifier(cszSpecifier),      mpPatterns(nullptr), 
             mpFmt(const_cast<char*>(mpFmt)), msztFmtLen(csztFmtLen){}; 
   CParser( const tChar cszSpecifier, const tChar* const cpFmt) 
            :mszSpecifier(cszSpecifier),      mpPatterns(nullptr), 
             mpFmt(const_cast<char*>(cpFmt)), msztFmtLen(vStrLen(cpFmt)){};

    // Destruct define
    virtual ~CParser() 
    { 
        mpPatterns = nullptr; 
    }

private:
    // No Copy
    CParser(const CParser& obj){};
    // No Assignment
    CParser& operator = ( const CParser& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tChar           mszSpecifier;
    tChar*          mpFmt;
    tSize           msztFmtLen;
    CPattern*       mpPatterns;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    void Regist(CPattern& oFlag)
    {
        if (mpPatterns == nullptr)
        {
            mpPatterns = &oFlag; return;
        };

        CPattern*& lpFlag = mpPatterns->GetLastPattern();
        lpFlag = &oFlag;
    }

    char* Parse( tChar* const pOutBuf, const tSize csztOutBufLen )
    {
        // 准备解析数据
        vm::CStrPtr loFmt(mpFmt,msztFmtLen);
        tSize lsztFmtOffSet = 0;
        char* lpFmtEnd      = mpFmt + msztFmtLen;
        vm::CStrPtr loOutBuf(pOutBuf, csztOutBufLen);
        tSize lsztOutBufOffset = 0;

        // 查找第一个标识符，若查找不到则返回。
        char* lpPos = loFmt.Find(mszSpecifier);
        if ( lpPos == nullptr ) return nullptr;

        // 将标识符到源数据开始位置的数据复制到目标数据中
        tSize lsztCount        = (lpPos-mpFmt);
        tSize lsztFirstCopied  = loOutBuf.CopyFm( mpFmt,lsztCount );
        lsztOutBufOffset      += lsztFirstCopied;
        lsztFmtOffSet         += lsztFirstCopied;

        // 循环对每一个Pattern进行对比
        while ( lpPos != nullptr )
        {
            // 依次检测Pattern标识
            CPattern* lpPattern = mpPatterns;
            while (lpPattern != nullptr)
            {
                // 若当前Pattern与标识符不相同，将转到下一个Pattern进行检测
                if ( ! loFmt.Cmp(lpPattern->mpFlg, lpPattern->msztFlgLen, lsztFmtOffSet ) )
                {
                    lpPattern = lpPattern->mpPattern;
                    continue;
                }
                
                // 对Pattern代表的字符串进行替换 
                tSize lsztCopied  = loOutBuf.CopyFm( lsztOutBufOffset,lpPattern->mpRpl, lpPattern->msztRplLen );
                lsztFmtOffSet    += lpPattern->msztFlgLen;
                lsztOutBufOffset += lsztCopied;
                lpPattern         = lpPattern->mpPattern;
                break;
            }

            // 查找下一个标识符所在的位置
            char* lpNextPos = loFmt.Find(lsztFmtOffSet, mszSpecifier);
            if (  lpNextPos != lpPos )
            {
                // 将当前标识符与下一个标识符中的数据复制到目标数据中
                tSize lsztCount = 0;
                if ( lpNextPos == nullptr )
                { 
                    // 当前标识符后以不存在标识符，将当前标识符到源字符串结尾的数据复制到目标字符串中。
                    lsztCount = lpFmtEnd-(mpFmt+lsztFmtOffSet);
                }else
                {
                    // 将当前标识符与下一个标识符中的数据复制到目标数据中
                    lsztCount = lpNextPos-(mpFmt+lsztFmtOffSet);
                }
                tSize lsztCopied    = loOutBuf.CopyFm( lsztOutBufOffset, loFmt[lsztFmtOffSet], lsztCount );
                lsztOutBufOffset   += lsztCopied;
                lsztFmtOffSet      += lsztCount;
                lpPos               = lpNextPos;
            }
            else
            {
                // 当前标识符的后面不存在可解析的数据
                tSize lszCopied = loOutBuf.CopyFm(lsztOutBufOffset, loFmt[lsztFmtOffSet], sizeof(mszSpecifier));
                lpPos++;
                if ( lpPos >= lpFmtEnd )
                break;
            }
        }

        return pOutBuf;
    }


}; // End of class CParser
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