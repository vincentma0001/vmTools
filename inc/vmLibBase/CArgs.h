/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CArgs.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/11 11:45:26
// Modify time  : 2020/01/11 11:45:26
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

#ifndef __CARGS_H__
#define __CARGS_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included

// Platform files included

// Used files included
#include <vmUtil.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CArgs : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CArgs
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :
#define _V_CARGS_MAX_NUM_ 1024

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CArgs():mulArgc(0),mpArgv{0}{};
    // Destruct define
    virtual ~CArgs(){};
    
public:
    // Copy construct define
    CArgs(const CArgs& obj){};
    // Assignment define
    CArgs& operator = ( const CArgs& obj )
    {
        mulArgc = obj.mulArgc;
        v_memcpy( mpArgv, sizeof(mpArgv), obj.mpArgv, sizeof(mpArgv));
    };

public:
    CArgs& operator+(void*pArgv){ Add(pArgv); return *this; }
    void* operator*(){ return mpArgv; };
    void*  operator [] ( unsigned long ulPos ){  if(ulPos>=_V_CARGS_MAX_NUM_) return nullptr; return mpArgv[ulPos]; }
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    unsigned long mulArgc;
    void*         mpArgv [_V_CARGS_MAX_NUM_];

public:
    unsigned long toCount(){ return mulArgc; };

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    bool Add( void* pArgv )
    {
        if ( mulArgc+1 >= _V_CARGS_MAX_NUM_ )
            return false;

        mpArgv[mulArgc] = pArgv;
        mulArgc++;
    }

}; // End of class CArgs
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CARGS_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CArgs.h
/////////////////////////////////////////////////////////////////////////////////////////