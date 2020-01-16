/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CStdPars.h
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time 	: 2020/01/08 12:12:28
// Modify time 	: 2020/01/08 12:12:28
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

#ifndef __CSTDPARS_H__
#define __CSTDPARS_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <string>

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{
namespace vStd{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CStdPars : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CStdPars
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
public:
    class CPattern
    {
    friend CStdPars;
    public:
         explicit CPattern( vString strFlg, vString strRpl)
                 :mstrFlg(strFlg),mulFlgLen(strFlg.length()),mstrRpl(strRpl),mpPattern(nullptr){};
         virtual ~CPattern(){ mpPattern = nullptr; };
    public:
        unsigned long   mulFlgLen;
        vString         mstrFlg;
        vString         mstrRpl;

    private:
        CPattern*          mpPattern;

    private:
        CPattern*& GetLastFlag()
        {
            if (mpPattern == nullptr) 
                return mpPattern;
            
            return mpPattern->GetLastFlag();
        }
    };

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    CStdPars( vString strFmt, tChar cFlag ):mstrFmt(strFmt), mszSpecifier(cFlag),mpPatterns(nullptr){};
    // Destruct define
    virtual ~CStdPars(){if (mpPatterns!=nullptr) mpPatterns=nullptr; }
    
private:
    // No Copy
    CStdPars(const CStdPars& obj):mszSpecifier(obj.mszSpecifier),mstrFmt(obj.mstrFmt),mpPatterns(nullptr){};
    // No Assignment
    CStdPars& operator = ( const CStdPars& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tChar       mszSpecifier;
    vString     mstrFmt;
    CPattern*   mpPatterns;

public:
    void Regist(CPattern& oFlag )
    {
        if ( mpPatterns==nullptr )
        {mpPatterns = &oFlag;return;};

        CPattern*& lpFlag = mpPatterns->GetLastFlag();
        lpFlag            = &oFlag;
    }

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    bool Parse(vString& strOutput)
    {
        size_t lsztPos = mstrFmt.find_first_of(mszSpecifier);
        if(lsztPos==vString::npos) return false;

        strOutput = mstrFmt.substr(0,lsztPos);
        while ( lsztPos!=vString::npos )
        {
            CPattern* lpPattern = mpPatterns;
            while (lpPattern !=nullptr)
            {
                if (mstrFmt.compare(lsztPos, lpPattern->mulFlgLen, lpPattern->mstrFlg) != 0)
                {
                    lpPattern = lpPattern->mpPattern;
                    continue;
                }

                lsztPos     += lpPattern->mulFlgLen;
                strOutput   += lpPattern->mstrRpl;

                lpPattern   = lpPattern->mpPattern;
                break; 
            }
           
            size_t lsztNextPos = mstrFmt.find_first_of(mszSpecifier, lsztPos );
            if ( lsztNextPos != lsztPos )
            {
                size_t lszCount    = lsztNextPos-lsztPos;
                strOutput += mstrFmt.substr(lsztPos,lszCount);
                lsztPos = lsztNextPos;
            }
            else
            {
                strOutput += mszSpecifier;
                lsztPos++;
                if ( lsztPos >= mstrFmt.length() )
                    break;
            }
        }
        
        return true;
    }

}; // End of class CStdPars
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vStd
/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CSTDPARS_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CStdPars.h
/////////////////////////////////////////////////////////////////////////////////////////