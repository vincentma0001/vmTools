/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CExp.cpp
// Version      : 0.0.0.0
// Author       : v.m.
// Brief        : 
// Create time  : 2020/01/02 20:51:18
// Modify time  : 2020/01/02 20:51:18
// Note         :
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Disable warnings :
// Example : #pragma warning(disable:4996)

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <exception>
#include <time.h>

// Config files included
#include <vmCfg.h>

// platform files included
#if defined ( _V_PLATFORM_ ) && ( _V_PLATFORM_ == _V_PF_WIN_ )
#include <windows.h>
#endif // #if defined(...)

// Used files included
#include <vmLibBase/vmUtil.h>
#include <vmLibErr.h>

#include <vmLibBase/CMemPtr.h>
#include <vmLibBase/CStrPtr.h>
#include <vmLibBase/CDateTime.hpp>

#include <vmLibFile.h>

// Declare file included
#include "CExp.h"
#include "vmVerify.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
CExp::CExp(): mExpLevel(emExp),mpExpNext(nullptr)
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
    if ( mpExpNext != nullptr )
        delete [] mpExpNext;
    
    mpExpNext = nullptr;
}
// End of function ~CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const char * const cpFile
// Parameter : const unsigned int cuiLine
CExp::CExp( const char* const   cpFile, 
            const unsigned long culLine,
            const char* const   cpTimeFmt ):mExpLevel(emExp),mpExpNext(nullptr)
{
    vCStrPtr(mszFile)     = vm::CFile(cpFile).cs_Name();
    muiLine               = culLine;
    vCStrPtr(mszDateTime) = vm::CDateTime<_V_CDATETIME_MAX_BUF_>::GetCurrTime().Fmt(cpTimeFmt);
}
// End of function CExp(...)
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CExp(...)
// Brief     :
// Return    : 
// Parameter : const CExp & oExp
// Parameter : const char * const cpFile
// Parameter : const unsigned int cuiLine
CExp::CExp( const CExp&         oExp, 
            const char* const   cpFile , 
            const unsigned long culLine,
            const char* const   cpTimeFmt):mExpLevel(emExp), mpExpNext(nullptr)
{
    mpExpNext       = new CExp();
    *mpExpNext      = oExp;

    vCStrPtr(mszFile)         = vm::CFile(cpFile).cs_Name();
    muiLine                   = culLine;
    vCStrPtr(mszDateTime)     = vm::CDateTime<_V_CDATETIME_MAX_BUF_>::GetCurrTime().Fmt(cpTimeFmt);
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
    vCStrPtr(mszFunc)        = obj.mszFunc;
    vCStrPtr(mszFile)        = obj.mszFile;
    muiLine                  = obj.muiLine;
    vCStrPtr(mszDateTime)    = obj.mszDateTime;
    vCStrPtr(mszMsg)         = obj.mszMsg;

    // ѭ��������һ���쳣��Ϣ
    if ( obj.mpExpNext == nullptr )
        return *this;

    if ( mpExpNext != nullptr )
        delete [] mpExpNext;

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
// Parameter : const char * const cpFunc
// Parameter : const char * const cpFmt
// Parameter : ...
CExp& CExp::operator()(const char* const cpFunc, const char* const cpFmt, ...)
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
// Parameter : const char * const cpFunc
// Parameter : const char * const cpFmt
// Parameter : va_list vList
CExp& CExp::operator()(const char* const cpFunc, const char* const cpFmt, va_list vList)
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
// Parameter : const char * const cpFmt
// Parameter : ...
char* CExp::Fmt(const char* const cpFmt, ...)
{
    // ��֤��ʽ�����Ƿ���ȷ
    _VERIFY_(cpFmt);

    // ��ʼ����ʽ���ַ�������
    size_t lsztFmtStrLen = strlen(cpFmt);
    size_t lsztFmtStrOffset = 0;
    vm::CStrPtr loFmtStr(const_cast<char*>(cpFmt), lsztFmtStrLen);
    char*  lpFmtStrOffset = (char*)cpFmt;

    // ��ʼ������������
    size_t lsztBufOffset = 0;
    vm::CMemPtr loBuf(mszBuf,sizeof(mszBuf));
    loBuf.Set(0x00);

    // ��������Ĳ�����ʽ��������Ϣ
    char* lpFmtFlagPos = loFmtStr.Find('%');
    while (lpFmtFlagPos != nullptr)
    {
        // ��ȡ��ʽ���ַ�����%��ʶ��֮���������Ϣ���������ƫ����
        size_t loFmtStrDataLen = lpFmtFlagPos - lpFmtStrOffset;
        lsztFmtStrOffset += (loFmtStrDataLen);

        // ����ʽ���е����ݿ������������У�����ӻ�����ƫ����
        size_t loCopyedLen = loBuf.CopyFm(lsztBufOffset, lpFmtStrOffset, loFmtStrDataLen);
        lsztBufOffset += loCopyedLen;

        // ���ݱ�ʶ�����쳣��Ϣ��ӵ���������
        // �������ں�������Ϣ
        if (loFmtStr.Cmp("%Fn", 3, lsztBufOffset) == true)
        {
            // ���������ת��Ϊ�ַ�������ӵ���������
            size_t lsztOffset = loBuf.CopyFm(lsztBufOffset, mszFunc, strlen(mszFunc));
            // ������ƫ�ƴ��������ת�����ַ�������
            lsztBufOffset += lsztOffset;
            // ��ʽ���ַ���ƫ�������ַ���%Fn��
            lsztFmtStrOffset += 3;
        }
        // ���������ļ�����Ϣ
        else if (loFmtStr.Cmp("%Fi", 3, lsztBufOffset) == true)
        {
            // ������������Ĵ�����Ϣ��ӵ���������
            size_t lsztOffset = loBuf.CopyFm(lsztBufOffset, mszFile, strlen(mszFile));
            // ������ƫ�ƴ�����Ϣ�ĳ���
            lsztBufOffset += lsztOffset;
            // ��ʽ���ַ���ƫ�������ַ���%Fi��
            lsztFmtStrOffset += 3;
        }
        // ����ʱ����Ϣ
        else if (loFmtStr.Cmp("%L", 2, lsztBufOffset) == true)
        {
            // ������������Ĵ�����Ϣ��ӵ���������
            size_t lsztOffset = loBuf.Fmt2(lsztBufOffset, "%04d", muiLine);;
            // ������ƫ�ƴ�����Ϣ�ĳ���
            lsztBufOffset += lsztOffset;
            // ��ʽ���ַ���ƫ�������ַ���%L��
            lsztFmtStrOffset += 2;
        }
        // ����ʱ����Ϣ
        else if (loFmtStr.Cmp("%T", 2, lsztBufOffset) == true)
        {
            // ������������Ĵ�����Ϣ��ӵ���������
            size_t lsztOffset = loBuf.CopyFm(lsztBufOffset, mszDateTime, strlen(mszDateTime));
            // ������ƫ�ƴ�����Ϣ�ĳ���
            lsztBufOffset += lsztOffset;
            // ��ʽ���ַ���ƫ�������ַ���%T��
            lsztFmtStrOffset += 2;
        }
        // �����쳣��Ϣ
        else if (loFmtStr.Cmp("%M", 2, lsztBufOffset) == true)
        {
            // ������������Ĵ�����Ϣ��ӵ���������
            size_t lsztOffset = loBuf.CopyFm(lsztBufOffset, mszFile, strlen(mszFile));
            // ������ƫ�ƴ�����Ϣ�ĳ���
            lsztBufOffset += lsztOffset;
            // ��ʽ���ַ���ƫ�������ַ���%M��
            lsztFmtStrOffset += 2;
        }

        // ����ʣ��ĸ�ʽ���ַ������ȣ���ʣ����С��0��������ѭ��
        size_t lszFmtStrLeft = lsztFmtStrLen - lsztFmtStrOffset;
        if (lszFmtStrLeft < 0)
            break;

        // ���¶�λ��һ����ʽ���ַ����б�ʶ����λ��
        lpFmtFlagPos = loFmtStr.Find(lsztFmtStrOffset, '%');
    }

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
// End of file CExp.cpp
/////////////////////////////////////////////////////////////////////////////////////////
