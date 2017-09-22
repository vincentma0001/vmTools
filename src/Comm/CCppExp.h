/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CCppExp.h
// Version 		: 0.0.1.0
// Brief 		: 
// Author 		: v.m.
// Create time 	: 23/1/2016 11:09:34
// Modify time 	: 23/1/2016 11:09:34
// Note 		:
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

#ifndef __CCPPEXP_H__
#define __CCPPEXP_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <exception>
#include "CException.h"

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#ifndef __FUNCTION__
#   define __FUNCTION__ "func"
#endif

// �쳣������
#define CEXP_CPP( ex )                                                      CCppExp( ex, __FUNCTION__, __LINE__,__FILE__, NULL )
#define CEXP_CPP_F( ex, szFunc )                                            CCppExp( ex, szFunc, __LINE__,__FILE__, NULL )
#define CEXP_CPP_T( ex, szTime )                                            CCppExp( ex, __FUNCTION__, __LINE__,__FILE__, szTime )
#define CEXP_CPP_FT( ex, szFunc, szTime )                                   CCppExp( ex, szFunc, __LINE__,__FILE__, szTime )

/////////////////////////////////////////////////////////////////////////////////////////
//
// class define : CCppExp
//        Notes : ���ཫC++�쳣ת��Ϊ�Զ����쳣
//
/////////////////////////////////////////////////////////////////////////////////////////
class CCppExp : public JL::CException
{
/////////////////////////////////////////////////////////////////////////////////////////
// Construct & Destruct :
public:
    CCppExp( std::exception& ex,                            // C++�쳣��Ϣ
        const char* szFunc = "func",                        // �쳣�����ĺ���
        const unsigned long culLine = __LINE__,             // �쳣����������
        const char* szFile = __FILE__,                      // �쳣�������ļ�
        const char* szTime = NULL                           // �쳣������ʱ��
        );                                                  // Construct define
    virtual ~CCppExp(){};                                   // Destruct define

}; // End of class CCppExp
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CCPPEXP_H__
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CCppExp.h
/////////////////////////////////////////////////////////////////////////////////////////
