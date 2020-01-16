/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWrn.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/07 08:59:07
// Modify time  : 2020/01/07 08:59:07
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

#ifndef __CWRN_H__
#define __CWRN_H__

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
// class CWrn : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWrn : public CLog
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWrn(){};
    // Destruct define
    virtual ~CWrn(){};
    
private:
    // No Copy
    CWrn(const CWrn& obj){};
    // No Assignment
    CWrn& operator = ( const CWrn& obj ){};

public:
    void operator()(const char* const cpFmt, ...)
    {
        va_list vList;
        va_start(vList, cpFmt);
        WriteLine( cpFmt, vList );
        va_end(vList);
    };
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:

}; // End of class CWrn
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWRN_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWrn.h
/////////////////////////////////////////////////////////////////////////////////////////