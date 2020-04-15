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
#	include <vmCfg.h>
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
// Name      : CExp(...)
// Brief     :
// Return    : 
CExp::CExp() : mExpLevel(emExp), mpExpNext(nullptr)
{

}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CExp(...)
// Brief     :
// Return    : 
CExp::~CExp()
{
    if (mpExpNext != nullptr)
        delete mpExpNext;

    mpExpNext = nullptr;
}
// End of function ~CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const tchar * const cpFile
// Parameter : const unsigned int cuiLine
CExp::CExp(const tchar* const   cpFile,
    const unsigned long culLine,
    const tchar* const   cpTimeFmt) :mExpLevel(emExp), mpExpNext(nullptr)
{
    vCStrPtr(mszFile) = vm::CFileBase(cpFile).cs_FileName();
    muiLine = culLine;
    vCStrPtr(mszDateTime) = vm::CDateTime<_V_CDATETIME_MAX_BUF_>::GetCurrTime().Fmt(cpTimeFmt);
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const CExp & oExp
// Parameter : const tchar * const cpFile
// Parameter : const unsigned int cuiLine
CExp::CExp(const CExp&               oExp,
    const tchar* const      cpFile,
    const unsigned long    culLine,
    const tchar* const   cpTimeFmt)
    :mExpLevel(emExp), mpExpNext(nullptr)
{
    mpExpNext = new CExp();
    *mpExpNext = oExp;

    vm::CFileBase::GetFileName(cpFile, vStrlen(cpFile), mszFile, sizeof(mszFile));
    muiLine = culLine;
    vCStrPtr(mszDateTime) = vm::CDateTime<_V_CDATETIME_MAX_BUF_>::GetCurrTime().Fmt(cpTimeFmt);
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const CExp & obj
CExp::CExp(const CExp& obj)
{
    *this = obj;
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=(...)
// Brief     :
// Return    : vm::CExp&
// Parameter : const CExp & obj
vm::CExp& CExp::operator=(const CExp& obj)
{
    // ����CExp�е�����
    vCStrPtr(mszFunc) = obj.mszFunc;
    vCStrPtr(mszFile) = obj.mszFile;
    muiLine = obj.muiLine;
    vCStrPtr(mszDateTime) = obj.mszDateTime;
    vCStrPtr(mszMsg) = obj.mszMsg;

    // ѭ��������һ���쳣��Ϣ
    if (obj.mpExpNext == nullptr)
        return *this;

    if (mpExpNext != nullptr)
        delete[] mpExpNext;

    mpExpNext = new CExp();
    *mpExpNext = *obj.mpExpNext;

    return *this;
}
// End of function operator=(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator()(...)
// Brief     :
// Return    : void
// Parameter : const tchar * const cpFunc
// Parameter : const tchar * const cpFmt
// Parameter : ...
CExp& CExp::operator()(const tchar* const cpFunc, const tchar* const cpFmt, ...)
{
    vCStrPtr(mszFunc) = cpFunc;

    va_list vList;
    va_start(vList, cpFmt);
    vCMemPtr(mszMsg).Fmt(cpFmt, vList);
    va_end(vList);

    return *this;
}
// End of function operator()(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator()(...)
// Brief     :
// Return    : void
// Parameter : const tchar * const cpFunc
// Parameter : const tchar * const cpFmt
// Parameter : va_list vList
CExp& CExp::operator()(const tchar* const cpFunc, const tchar* const cpFmt, va_list vList)
{
    vCStrPtr(mszFunc) = cpFunc;
    vCStrPtr(mszMsg).Fmt(cpFmt, vList);

    return *this;
}
// End of function operator()(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Fmt(...)
// Brief     :
// Return    : int
// Parameter : const tchar * const cpFmt
tchar* CExp::Fmt(const tchar* const cpFmt)
{
    // ��֤��ʽ�����Ƿ���ȷ
    _VERIFY_(cpFmt);

    // ��ʼ������������
    vm::CParser::CPattern loPatternExpFunc(vT("%M"), mszFunc);
    vm::CParser::CPattern loPatternExpFile(vT("%F"), mszFile);
    vm::CParser::CPattern loPatternExpLine(vT("%L"), vm::CAny<128>(muiLine).s_ulong());
    vm::CParser::CPattern loPatternExpTime(vT("%T"), mszDateTime);
    vm::CParser::CPattern loPatternExpMsgs(vT("%N"), mszMsg);

    vm::CParser loParser(vT('%'), cpFmt);
    loParser.Regist(loPatternExpFunc);
    loParser.Regist(loPatternExpFile);
    loParser.Regist(loPatternExpLine);
    loParser.Regist(loPatternExpTime);
    loParser.Regist(loPatternExpMsgs);

    vMemZero(mszBuf);
    loParser.Parse(mszBuf, sizeof(mszBuf));

    return mszBuf;
}
// End of function Fmt(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Next(...)
// Brief     :
// Return    : vm::CExp*
vm::CExp* CExp::Next()
{
    return mpExpNext;
}
// End of function Next(...)
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