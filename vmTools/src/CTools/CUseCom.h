/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CUseCom.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/05 07:42:05
// Modify time  : 2020/01/05 07:42:05
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

#ifndef __CUSECOM_H__
#define __CUSECOM_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CUseCom : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CUseCom
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CUseCom();
    // Destruct define
    virtual ~CUseCom();

}; // End of class CUseCom
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CUseCom(...)
// Brief     :
// Return    : 
CUseCom::CUseCom()
{
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
    ::CoInitialize(NULL);
#endif // #if defined (_V_PLATFORM)...
}
// End of function CUseCom(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CUseCom(...)
// Brief     :
// Return    : 
CUseCom::~CUseCom()
{
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
    ::CoUninitialize();
#endif // #if defined (_V_PLATFORM)...
}
// End of function ~CUseCom(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CUSECOM_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CUseCom.h
/////////////////////////////////////////////////////////////////////////////////////////