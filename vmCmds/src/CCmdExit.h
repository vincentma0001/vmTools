/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CCmdExit.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/04/20 09:05:19
// Modify time  : 2020/04/20 09:05:19
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

#ifndef __CCMDEXIT_H__
#define __CCMDEXIT_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included

// Platform files included

// Used files included
#include <CCmd.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :
#ifndef     _V_CMDEXIT_MAX_NAME
#    define _V_CMDEXIT_MAX_NAME 256
#endif   // _V_CMDEXIT_MAX_NAME

#ifndef     _V_CMDEXIT_MAX_NOTE
#    define _V_CMDEXIT_MAX_NOTE 1024
#endif   // _V_CMD_EXIT_MAX_NOTE

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CCmdExit : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CCmdExit : public CCmd<_V_CMDEXIT_MAX_NAME, _V_CMDEXIT_MAX_NOTE>
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CCmdExit(){};
    // Destruct define
    virtual ~CCmdExit(){};
    
private:
    // No Copy
    CCmdExit(const CCmdExit& obj){};
    // No Assignment
    CCmdExit& operator = ( const CCmdExit& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    virtual void OnAction( void* pFrame, const unsigned int argc, tchar** argv );

}; // End of class CCmdExit
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CCMDEXIT_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CCmdExit.h
/////////////////////////////////////////////////////////////////////////////////////////