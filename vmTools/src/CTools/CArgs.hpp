/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CArgs.hpp
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/03/09 10:10:51
// Modify time  : 2020/03/09 10:10:51
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

#ifndef __CARGS_HPP__
#define __CARGS_HPP__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

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
template<unsigned int uiMaxArgv>
class CArgs
{
////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CArgs():muiArgc(0),mpArgv{0x00}{};
    // Destruct define
    virtual ~CArgs(){};
    
private:
    // No Copy
    CArgs(const CArgs& obj){};
    // No Assignment
    CArgs& operator = ( const CArgs& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    unsigned int muiArgc;
    tchar*       mpArgv[uiMaxArgv];

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // Get argv value by pos
    tchar*        operator [](unsigned int uiPos);
    // Get argv address
    tchar**       operator*();
    // Add a string to args
    CArgs&       operator+=(const char* const cpArgv);

    // Get argc value
    unsigned int  Argc();
    // Get argv address
    tchar**       Argv();
    
    // Splite string to args 
    unsigned int Splite(tchar* pszString, const tchar* const cpszDelimiters);
    // Free memory space that malloc by Splite function
    void Clear();

}; // End of class CArgs
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator*(...)
// Brief     :
// Return    : template<unsigned int uiMaxArgv>
template<unsigned int uiMaxArgv>
tchar** CArgs<uiMaxArgv>::operator*()
{
    return mpArgv;
}
// End of function operator*(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Method    : Method(...)
// Brief     : # add method brief here #
// Return    : return                                    -     # add return value notes #
// Parameter : Param1                                    - [O] # add param1 value notes #
//           : Param2                                    - [I] # add param2 value notes #
template<unsigned int uiMaxArgv>
tchar*  CArgs<uiMaxArgv>::operator[](unsigned int uiPos)
{
    if (uiPos > muiArgc || uiPos >= uiMaxArgv)
    {
        return nullptr;
    }


    return mpArgv[ uiPos ];
}
// End of function Method(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator+(...)
// Brief     :
// Return    : template<unsigned int uiMaxArgv>
// Parameter : const char * const cpArgv
template<unsigned int uiMaxArgv>
CArgs<uiMaxArgv>& CArgs<uiMaxArgv>::operator+=(const tchar* const cpArgv)
{
    // #  TODO : Add condition brief here ##
    if (muiArgc < uiMaxArgv)
    {
        unsigned int luiArgvLen = (unsigned int)vStrlen(cpArgv);
        mpArgv[ muiArgc ] = (tchar*)malloc((luiArgvLen + 1) * sizeof(tchar));
        v_strcpy(mpArgv[ muiArgc ], luiArgvLen + 1, cpArgv);
        muiArgc++;
    }
    // End of if (muiArgc<uiMaxArgv) ...

    return *this;
}
// End of function operator+(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Argc(...)
// Brief     :
// Return    : 
template<unsigned int uiMaxArgv>
unsigned int CArgs<uiMaxArgv>::Argc()
{
    return muiArgc;
}
// End of function Argc(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Argv(...)
// Brief     :
// Return    : 
template<unsigned int uiMaxArgv>
tchar** vm::CArgs<uiMaxArgv>::Argv()
{
    return mpArgv;
}
// End of function Argv(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Splite(...)
// Brief     :
// Return    : 
// Parameter : char * pszString
// Parameter : const char * const cpszDelimiters
template<unsigned int uiMaxArgv>
unsigned int vm::CArgs<uiMaxArgv>::Splite(char* pszString, const char* const cpszDelimiters)
{
    tchar* lpch = nullptr;
    tchar* lpNext = nullptr;
    lpch = vStrtok_s(pszString, cpszDelimiters, &lpNext);
    while (lpch != nullptr&&muiArgc < uiMaxArgv)
    {
        *this += lpch;
        lpch = vStrtok_s(NULL, cpszDelimiters, &lpNext);
    }
    return muiArgc;
}
// End of function Splite(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Clear(...)
// Brief     :
// Return    : 
template<unsigned int uiMaxArgv>
void vm::CArgs<uiMaxArgv>::Clear()
{
    for (unsigned int i = 0; i < muiArgc; i++)
    {
        if (mpArgv[ i ] != nullptr)
        {
            free(mpArgv[ i ]);
            mpArgv[ i ] = nullptr;
        }
    }

    muiArgc = 0;
}
// End of function Clear(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CARGS_HPP__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CArgs.hpp
/////////////////////////////////////////////////////////////////////////////////////////