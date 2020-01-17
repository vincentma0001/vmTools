/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CExp.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2019/12/30 21:55:32
// Modify time  : 2019/12/30 21:55:32
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

#ifndef __CEXP_H__
#define __CEXP_H__

/////////////////////////////////////////////////////////////////////////////////////////
// include file

#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>_
#endif // __VM_CFG_H__

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define

#ifndef     _VM_CEXP_TIMEFMT_
#   define  _VM_CEXP_TIMEFMT_ "%Y/%m/%d %H:%M:%S.%Mill"
#endif // ! _VM_CEXP_TIMEFMT_

/////////////////////////////////////////////////////////////////////////////////////////
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
//---------------------------------------------------------------------------------------

#   define _V_CEXP_MAX_FUNC_ _MAX_FNAME
#   define _V_CEXP_MAX_FILE_ _MAX_FNAME
#   define _V_CEXP_MAX_MSG_  1024
#   define _V_CEXP_MAX_BUF_  2048
#   define _V_CEXP_TIME_BUF_ 128

//---------------------------------------------------------------------------------------
#else // ! #if defined (_V_PLATFORM)...
//---------------------------------------------------------------------------------------

#   define _V_CEXP_MAX_FUNC_ 256
#   define _V_CEXP_MAX_FILE_ 256
#   define _V_CEXP_MAX_MSG_  1024
#   define _V_CEXP_MAX_BUF_  2048
#   define _V_CEXP_TIME_BUF_ 128

//---------------------------------------------------------------------------------------
#endif // #if defined (_V_PLATFORM)...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CExp : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CExp
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedef :
typedef enum emExpLevel
{
    emExp = 1,
    emWrn = 2
} EMEXPLEVEL;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CExp();
    explicit CExp( const tchar* const      cpFile,
                   const unsigned long    culLine,
                   const tchar* const   cpTimeFmt);
    explicit CExp( const CExp&               oExp,
                   const tchar* const      cpFile, 
                   const unsigned long    culLine,
                   const tchar* const   cpTimeFmt);
    // Destruct define
    virtual ~CExp();
    
public:
    // Copy construct define
    CExp(const CExp& obj);
    // Assignment define
    CExp& operator = ( const CExp& obj );

public:
    // ()����
    CExp& operator()(const tchar* const cpFunc,
                     const tchar* const cpFmt , ...);
    CExp& operator()(const tchar* const cpFunc,
                     const tchar* const cpFmt , va_list vList);
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
protected:
    // where
    // �쳣����ʱ���ڵĺ�����
    tchar   mszFunc[_V_CEXP_MAX_FUNC_];
    // �쳣����ʱ���ڵ��ļ���
    tchar   mszFile[_V_CEXP_MAX_FILE_];
    // �쳣����ʱ˵զ���ļ�����
    unsigned int    muiLine;

    // when
    // �쳣������ʱ��
    tchar   mszDateTime[_V_CEXP_TIME_BUF_];
    
    // what
    // �쳣��Ϣ
    tchar   mszMsg[_V_CEXP_MAX_MSG_];

    // format msg buffer
    // ��ʽ������
    tchar   mszBuf[_V_CEXP_MAX_BUF_];

private:
    // �쳣�ȼ�
    emExpLevel                   mExpLevel;
    // ��һ���쳣��Ϣ
    CExp*                        mpExpNext;
    
/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // ��ʽ������쳣��Ϣ
    // FMT : %M(Method)                      - ������
    //       %F(File)                        - �ļ���
    //       %L(Line)                        - �ļ�����
    //       %N(Notification)                - �쳣��Ϣ
    //       %T(Time)                        - �쳣������ʱ��
    tchar* Fmt( const tchar* const cpFmt );

public:
    // ��ȡ����һ���쳣��Ϣ
    CExp* Next();

}; // End of class CExp
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CEXP_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CExp.h
/////////////////////////////////////////////////////////////////////////////////////////