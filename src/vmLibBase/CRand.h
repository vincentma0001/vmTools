/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CRand.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/04 20:18:56
// Modify time  : 2020/01/04 20:18:56
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

#ifndef __CRAND_H__
#define __CRAND_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
#ifndef   _INC_TIME
#   include <time.h>
#endif // _INC_TIME

#ifndef   _INC_STDLIB
#   include <stdlib.h>
#endif // _INC_STDLIB

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CRand : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CRand
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CRand()
    {
        srand((unsigned int)time(0));
    };
    // Destruct define
    virtual ~CRand(){};
    
private:
    // No Copy
    CRand(const CRand& obj){};
    // No Assignment
    CRand& operator = ( const CRand& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
private:

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    long Random( const long clMin, const long clMax )
    {
        long llDiff = clMax - clMin;
        long llRet = rand() % llDiff + clMin;
        return llRet;
    }
    long Random( const long clMax )
    {
        long liRet = rand() % clMax;
        return liRet;
    }

}; // End of class CRand
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CRAND_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CRand.h
/////////////////////////////////////////////////////////////////////////////////////////