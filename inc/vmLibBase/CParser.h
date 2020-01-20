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
// Config files included
#ifndef   __VM_CFG_H__
#   include <vmCfg.h>
#endif // __VM_CFG_H__

// Used files included
#ifndef   __VM_UTIL_H__
#   include <vmLibBase/vmUtil.h>
#endif // __VM_UTIL_H__

#ifndef   __CSTRPTR_H__
#   include <vmLibBase/CStrPtr.h>
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
        explicit CPattern( const tchar* const cpFlg, const size_t csztFlgLen,
                           const tchar* const cpRpl, const size_t csztRplLen )
                          :mpFlg(const_cast<tchar*>(cpFlg)), msztFlgLen(csztFlgLen), 
                           mpRpl(const_cast<tchar*>(cpRpl)), msztRplLen(csztRplLen),
                           mpPattern(nullptr) {};
        explicit CPattern( const tchar* const cpFlg, const tchar* const cpRpl )
                          :mpFlg(const_cast<tchar*>(cpFlg)), msztFlgLen(vStrlen(cpFlg)),
                           mpRpl(const_cast<tchar*>(cpRpl)), msztRplLen(vStrlen(cpRpl)),
                           mpPattern(nullptr) {};
        virtual ~CPattern() 
        { 
            mpFlg     = nullptr; 
            mpRpl     = nullptr; 
            mpPattern = nullptr; 
        };
    public:
        tchar*   mpFlg;
        size_t   msztFlgLen;
        tchar*   mpRpl;
        size_t   msztRplLen;

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
    CParser( const tchar cszSpecifier, const tchar* const cpFmt, const size_t csztFmtLen)
            :mszSpecifier(cszSpecifier),      mpPatterns(nullptr), 
             mpFmt(const_cast<tchar*>(mpFmt)), msztFmtLen(csztFmtLen){}; 
   CParser( const tchar cszSpecifier, const tchar* const cpFmt) 
            :mszSpecifier(cszSpecifier),      mpPatterns(nullptr), 
             mpFmt(const_cast<tchar*>(cpFmt)), msztFmtLen(vStrlen(cpFmt)){};

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
    tchar           mszSpecifier;
    tchar*          mpFmt;
    size_t          msztFmtLen;
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

    tchar* Parse( tchar* const pOutBuf, const size_t csztOutBufLen )
    {
        // ׼����������
        vm::CStrPtr loFmt(mpFmt,msztFmtLen);
        size_t lsztFmtOffSet = 0;
        tchar* lpFmtEnd      = mpFmt + msztFmtLen;
        vm::CStrPtr loOutBuf(pOutBuf, csztOutBufLen);
        size_t lsztOutBufOffset = 0;

        // ���ҵ�һ����ʶ���������Ҳ����򷵻ء�
        tchar* lpPos = loFmt.Find(mszSpecifier);
        if ( lpPos == nullptr ) return nullptr;

        // ����ʶ����Դ���ݿ�ʼλ�õ����ݸ��Ƶ�Ŀ��������
        size_t lsztCount        = (lpPos-mpFmt);
        size_t lsztFirstCopied  = loOutBuf.CopyFm( mpFmt,lsztCount );
        lsztOutBufOffset      += lsztFirstCopied;
        lsztFmtOffSet         += lsztFirstCopied;

        // ѭ����ÿһ��Pattern���жԱ�
        while ( lpPos != nullptr )
        {
            // ���μ��Pattern��ʶ
            CPattern* lpPattern = mpPatterns;
            while (lpPattern != nullptr)
            {
                // ����ǰPattern���ʶ������ͬ����ת����һ��Pattern���м��
                if ( ! loFmt.Cmp(lpPattern->mpFlg, lpPattern->msztFlgLen, lsztFmtOffSet ) )
                {
                    lpPattern = lpPattern->mpPattern;
                    continue;
                }
                
                // ��Pattern������ַ��������滻 
                size_t lsztCopied  = loOutBuf.CopyFm( lsztOutBufOffset,lpPattern->mpRpl, lpPattern->msztRplLen );
                lsztFmtOffSet    += lpPattern->msztFlgLen;
                lsztOutBufOffset += lsztCopied;
                lpPattern         = lpPattern->mpPattern;
                break;
            }

            // ������һ����ʶ�����ڵ�λ��
            tchar* lpNextPos = loFmt.Find(lsztFmtOffSet, mszSpecifier);
            //do{
                if (  lpNextPos != lpPos )
                {
                    // ����ǰ��ʶ������һ����ʶ���е����ݸ��Ƶ�Ŀ��������
                    size_t lsztCount = 0;
                    if ( lpNextPos == nullptr )
                    { 
                        // ��ǰ��ʶ�����Բ����ڱ�ʶ��������ǰ��ʶ����Դ�ַ�����β�����ݸ��Ƶ�Ŀ���ַ����С�
                        lsztCount = lpFmtEnd-(mpFmt+lsztFmtOffSet);
                    }else
                    {
                        // ����ǰ��ʶ������һ����ʶ���е����ݸ��Ƶ�Ŀ��������
                        lsztCount = lpNextPos-(mpFmt+lsztFmtOffSet);
                    }
                    size_t lsztCopied    = loOutBuf.CopyFm( lsztOutBufOffset, loFmt[lsztFmtOffSet], lsztCount );
                    lsztOutBufOffset   += lsztCopied;
                    lsztFmtOffSet      += lsztCount;
                    lpPos               = lpNextPos;
                }
                else
                {
                    // ��ǰ��ʶ���ĺ��治���ڿɽ���������
                    size_t lsztCopied   = loOutBuf.CopyFm(lsztOutBufOffset, loFmt[lsztFmtOffSet], sizeof(mszSpecifier));
                    lsztFmtOffSet    += lsztCopied;
                    lsztOutBufOffset += lsztCopied;
                    //lpNextPos         = loFmt.Find(lsztFmtOffSet, mszSpecifier);
                    lpPos             = lpNextPos;                   
                }
            //}while(lpPos!=nullptr);
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