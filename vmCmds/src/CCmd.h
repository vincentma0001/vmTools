/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CCmd.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/04/20 09:07:15
// Modify time  : 2020/04/20 09:07:15
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

#ifndef __CCMD_H__
#define __CCMD_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included
#include <vmTools.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CCmdBase : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CCmdBase
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CCmdBase( tchar* const pCmdName, const unsigned int cuiNameSize, 
                       tchar* const pCmdNote, const unsigned int cuiNoteSize )
                     : mpCmdName(pCmdName), muiNameSize(cuiNameSize),
                       mpCmdNote(pCmdNote), muiNoteSize(cuiNoteSize)
    {};
    // Destruct define
    virtual ~CCmdBase(){};
    
private:
    // No Copy
    CCmdBase(const CCmdBase& obj){};
    // No Assignment
    CCmdBase& operator = ( const CCmdBase& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tchar*          mpCmdName;
    unsigned int    muiNameSize;
    tchar*          mpCmdNote;
    unsigned int    muiNoteSize;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:

    virtual void OnAction( void* pFrame, unsigned int argc, tchar** argv ) = 0;

}; // End of class CCmdBase
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CCmd : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
template<size_t stNameSize, size_t stNoteSize>
class DLL_API CCmd : public CCmdBase
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CCmd():CCmdBase(mszCmdName, stNameSize, mszCmdNote, stNoteSize){};
    // Destruct define
    virtual ~CCmd(){};
    
private:
    // No Copy
    CCmd(const CCmd& obj){};
    // No Assignment
    CCmd& operator = ( const CCmd& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tchar   mszCmdName[stNameSize];
    tchar   mszCmdNote[stNoteSize];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:

}; // End of class CCmd
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CCMD_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CCmd.h
/////////////////////////////////////////////////////////////////////////////////////////