/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CWinSockErr.h
// Version 		: 1.0.0.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 27/6/2016 8:29:55
// Modify time 	: 27/6/2016 8:29:55
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co.LTD
//
/////////////////////////////////////////////////////////////////////////////////////////
// compile macro definition
#if defined (_MSC_VER) && (_MSC_VER >= 1300)
#pragma once
#endif

#ifndef __CWINSOCKERR_H__
#define __CWINSOCKERR_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file

#ifndef _WINSOCK2API_
#   error this file need #include <WINSOCK2.H>
#endif

#include "CError.h"

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CWinSockErr
//        Notes : ## add class brief here #
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinSockErr : public CError
{
/////////////////////////////////////////////////////////////////////////////////////
// functions :
public:
    CWinSockErr( const DWORD cdwError=WSAGetLastError() )
        : CError(cdwError){};			                        // Construct define
    ~CWinSockErr(){};			                                    // Destruct define
public:
    virtual const char* ToString();;                             // ��ȡ��������

    /////////////////////////////////////////////////////////////////////////////////////////
    // static functions:
public:
    DWORD GetErrorCode();                                // ��ȡ�������
    const char* GetErrorInfo( void );                    // ��ȡ��������

}; // End of class CWinSockErr
///////////////////////////////////////////////////////////////////////////////////////// 


/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINSOCKERR_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinSockErr.h
/////////////////////////////////////////////////////////////////////////////////////////
