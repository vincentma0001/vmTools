/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CException.cpp
// Version 		: 0.0.1.0
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 9/1/2016 20:26:06
// Modify time 	: 9/1/2016 20:26:06
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <windows.h>
#include <stdarg.h>
#include <string.h>

#include "CException.h"
#include "VerifyDef.h"
#include "CFile.h"
#include "CValue.h"

/////////////////////////////////////////////////////////////////////////////////////////
// macro define
#define EX_MAX_BUF 2048

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

namespace vm {

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CException
// Full name : CException::CException
// Access    : public 
// Brief     : ���캯��
// Parameter :  const char* szFormat,                                       -- �쳣��Ϣ��ʽ
//              const char* szFunc,                                         -- �쳣�����ĺ�����
//              const unsigned long culExpType /*= MAKEUSEREXP(ET_USER)*/,  -- �쳣����
//              const unsigned long culExpCode /*= MAKEUSEREXP(ET_USER)*/,  -- �쳣����
//              const unsigned long culLine /*= __LINE__*/,                 -- �쳣�����ĺ�������
//              const char* szFile /*= __FILE__*/,                          -- �쳣�������ļ���
//              const char* szTime /*= NULL*/,                              -- �쳣������ʱ��
//              ...
// Return    : 
// Notes     : 
CException::CException( const char* szFormat, 
                        const char* szFunc, 
                        const unsigned long culLine, 
                        const char* szFile, 
                        const unsigned long culExpType /*= MAKEUSEREXP(ET_USER)*/, 
                        const unsigned long culExpCode /*= MAKEUSEREXP(ET_USER)*/, 
                        const char* szTime /*= NULL*/, 
                        ...)
{
    // ��֤����
    _VERIFY_3_(szFormat, szFunc, szFile);

    // ��ȡ�쳣��Ϣ
    char szBuf[EX_MAX_BUF] = { 0 };
    va_list vp;
    va_start(vp, szTime);
#if defined (_MSC_VER) && (_MSC_VER<=1300)
    vsprintf(szBuf, szFormat, vp);
#else
    vsprintf_s(szBuf, EX_MAX_BUF, szFormat, vp);
#endif
    va_end(vp);
    mstrMsg = szBuf;

    // �����쳣����
    mulExpType = culExpType;

    // �����쳣����
    mulExpCode = culExpCode;

    // �����쳣λ��
    mulLine = culLine;
    mstrFunc = szFunc;
    mstrFile = vm::CFile::GetFileBase( szFile );

    // �����쳣ʱ��
    if ( szTime != NULL )
    {
        mstrTime = szTime;
    }
    

} // End of function CException(...
/////////////////////////////////////////////////////////////////////////////////////////

#if defined (_MSC_VER) && (_MSC_VER<=1300)
CException::CException( 
           const char* szFunc,
           const unsigned long culLine,
           const char* szFile )
{
    // ��֤����
    _VERIFY_2_(szFunc, szFile);
    
 /*   ,
        const unsigned long culExpType = MAKEUSEREXP(ET_UNKNOWN),
        const unsigned long culExpCode = MAKEUSEREXP(ET_UNKNOWN),
           const char* szTime = NULL
    // �����쳣����
    mulExpType = culExpType;
    
    // �����쳣����
    mulExpCode = culExpCode;
   */ 
    // �����쳣λ��
    mulLine = culLine;
    mstrFunc = szFunc;
    vm::CFile loFile(szFile);
    mstrFile = loFile.mstrFileBase.c_str();
    
//     // �����쳣ʱ��
//     if ( szTime != NULL )
//     {
//         mstrTime = szTime;
//     }
}

CException& CException::operator()( const char* szFormat, ... ) 
{
    // ��ȡ�쳣��Ϣ
    char szBuf[EX_MAX_BUF] = { 0 };
    va_list vp;
    va_start(vp, szFormat);
    vsprintf(szBuf, szFormat, vp);
    va_end(vp);
    mstrMsg = szBuf;

    return *this;
}
#endif

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CException
// Full name : CException::CException
// Access    : public 
// Brief     : 
// Parameter : const CException& ex, const char* szFunc/*= "func"*/, const unsigned long culLine /*= __LINE__*/, const char* szFile /*= __FILE__*/, const char* szTime /*= NULL */
// Return    : 
// Notes     : 
CException::CException(const vm::CException& ex, 
                       const char* szFunc,
                       const unsigned long culLine /*= __LINE__*/, 
                       const char* szFile /*= __FILE__*/, 
                       const char* szTime /*= NULL */)
{
    mstrMsg = ex.mstrMsg;

    // �����쳣����
    mulExpType = ex.mulExpType;

    // �����쳣����
    mulExpCode = ex.mulExpCode;

    // �����쳣λ��
    mulLine = culLine;
    mstrFunc = szFunc;
    mstrFile = vm::CFile::GetFileBase( szFile );

    // �����쳣ʱ��
    if ( szTime != NULL )
    {
        mstrTime = szTime;
    }

} // End of function CException(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CException
// Full name : CException::CException
// Access    : public 
// Brief     : 
// Parameter : const CException& ex
// Return    : 
// Notes     : 
CException::CException(const vm::CException& ex)
{
    mulExpType  = ex.mulExpType;             // �쳣����: ����쳣���Ͷ���

    mulExpCode  = ex.mulExpCode;             // �쳣����

    mulLine     = ex.mulLine;                // �쳣�������ļ�����
    mstrFile    = ex.mstrFile;               // �쳣�������ļ���
    mstrFunc    = ex.mstrFunc;               // �쳣�����ĺ�����

    mstrTime    = ex.mstrTime;               // �쳣������ʱ��
    mstrMsg     = ex.mstrMsg;                // �쳣��Ϣ
    mstrBuf     = ex.mstrBuf;                // �쳣��Ϣ

} // End of function CException(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CException::ToString
// Access    : virtual public 
// Brief     : ��ʽ������쳣��Ϣ
// Parameter : const char* szFormat                                 -- �쳣��ʽ
// Return    : const char*                                          -- �쳣��Ϣ
// Notes     : �쳣��ʽ  
//             %M                -- �쳣�����ĺ�����
//             %L                -- �쳣����������
//             %F                -- �쳣�������ļ���
//             %T                -- �쳣����
//             %C                -- �쳣����
//             %I                -- �쳣��Ϣ
//             %D                -- �쳣������ʱ��
const char* CException::Format(const char* szFormat)
{
    _VERIFY_( szFormat );

    char szBuf[EX_MAX_BUF] = { 0 };

    size_t lstLenForTmp = strlen( szFormat );
    size_t lstMinLen = _MIN_( EX_MAX_BUF, lstLenForTmp );

    char* lpBuf = szBuf;
    char* lpFormat = const_cast<char*>(szFormat);

    size_t lstCopied = 0;
    char *p = NULL;
    do 
    {
#if defined (_MSC_VER) && (_MSC_VER<=1300)
        p = (char*)memccpy( lpBuf, lpFormat, '%', lstMinLen );
#else
        p = (char*)_memccpy( lpBuf, lpFormat, '%', lstMinLen );
#endif
        
        if ( p==NULL )
        {
            break;
        }

        unsigned int luiLeft = p-lpBuf;
        lpBuf       += luiLeft-1;
        lpFormat    += luiLeft;
        char cFlag = *(lpFormat);
        switch( cFlag )
        {
        case 'M':
            {
                memcpy(lpBuf,mstrFunc.c_str(), mstrFunc.size());
                lpBuf+=mstrFunc.size();
                lpFormat+=1;
            }
            break;
        case 'L':
            {
                CValue lValue(mulLine);
                memcpy( lpBuf, lValue.ToString(), lValue.Size() );
                lpBuf+=lValue.Size();
                lpFormat+=1;
            }
            break;
        case 'T':
            {
                CValue lValue(mulExpType);
                memcpy( lpBuf, lValue.ToHexStr(), lValue.Size() );
                lpBuf+=lValue.Size();
                lpFormat+=1;
            }
            break;
        case 'C':
            {
                CValue lValue(mulExpCode);
                memcpy( lpBuf, lValue.ToHexStr(), lValue.Size() );
                lpBuf+=lValue.Size();
                lpFormat+=1;
            }
            break;
        case 'F':
            {
                memcpy(lpBuf,mstrFile.c_str(), mstrFile.size());
                lpBuf+=mstrFile.size();
                lpFormat+=1;
            }
            break;
        case 'I':
            {
                memcpy(lpBuf,mstrMsg.c_str(), mstrMsg.size());
                lpBuf+=mstrMsg.size();
                lpFormat+=1;
            }
            break;
        case 'D':
            {
                memcpy(lpBuf,mstrTime.c_str(), mstrTime.size());
                lpBuf+=mstrTime.size();
                lpFormat+=1;
            }
        case '%':
            {
                memcpy(lpBuf,lpFormat, sizeof(char));
                lpBuf+=sizeof(char);
                lpFormat+=1;
            }
            break;
        }

        lstCopied = lpBuf-szBuf;
    } while ((lstCopied<1024) && (p!=NULL));

    mstrBuf = szBuf;
    return mstrBuf.c_str();
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : operator=
// Full name : CException::operator=
// Access    : public 
// Brief     : ��ֵ����
// Parameter : const CException& ex
// Return    : CException&
// Notes     : 
CException& CException::operator=(const CException& ex)
{
    mulExpType = ex.mulExpType;
    mulExpCode = ex.mulExpCode;
    mulLine = ex.mulLine;
    mstrFile = ex.mstrFile;
    mstrFunc = ex.mstrFunc;
    mstrTime = ex.mstrTime;
    mstrMsg = ex.mstrMsg;
    mstrBuf = ex.mstrBuf;

    return *this;
} // End of function operator=(...
/////////////////////////////////////////////////////////////////////////////////////////

} // End of namespace JL

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CException.cpp...
/////////////////////////////////////////////////////////////////////////////////////////