/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CLogImp.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/05 15:33:40
// Modify time  : 2020/01/05 15:33:40
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

#ifndef __CLOGIMP_H__
#define __CLOGIMP_H__

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
// class CLogImp : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CLogImp
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CLogImp():mpImpNext(nullptr){};
    // Destruct define
    virtual ~CLogImp()
    {
        if ( mpImpNext==nullptr )
            delete [] mpImpNext;
    };
    
private:
    // No Copy
    CLogImp(const CLogImp& obj){};
    // No Assignment
    CLogImp& operator = ( const CLogImp& obj ){};

public:
    virtual tChar* WriteLine( const tChar* const cpFmt, va_list vList ) = 0;
    virtual bool  WriteNext( const tChar* const cpFmt, va_list vList )
    {
        CLogImp* lpLogNext = mpImpNext;
        while ( lpLogNext != nullptr )
        {
            lpLogNext->WriteLine(cpFmt, vList);
            lpLogNext = lpLogNext->mpImpNext;
        }
    }

    void AddImp( CLogImp& oLogImp )
    {
        CLogImp* lpImpNow = GetLastImp();
        lpImpNow->mpImpNext = &oLogImp;
    }

    CLogImp* GetLastImp()
    {
        CLogImp* lpImpNow = this;
        CLogImp* lpImpNext = this->mpImpNext;

        while (lpImpNext!=nullptr)
        {
            lpImpNow = lpImpNext;
            lpImpNext = lpImpNow->mpImpNext;
        }

        return lpImpNow;
    }
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    CLogImp* mpImpNext;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:

}; // End of class CLogImp
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CLOGIMP_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CLogImp.h
/////////////////////////////////////////////////////////////////////////////////////////