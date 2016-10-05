/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CDLoader.cpp
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 22/2/2016 9:35:27
// Modify time  : 22/2/2016 9:35:27
// Note         : 
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <Comm/VerifyDef.h>
#include <Comm/CException.h>
#include <Comm/CWinError.h>
#include "CModuleLoader.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : CDLoader
// Full name : CDLoader::CDLoader
// Access    : public 
// Brief     : 
// Parameter : const char* cszDLLName
// Return    : 
// Notes     : 
CModuleLoader::CModuleLoader(const char* cszDLLName) :mHandle(NULL),mdwErrCode(0),mstrErrDes("")
{
    try{
        // ����ģ��
        Load( cszDLLName );
    } // End of try
    catch( CException& lEx )
    {
        CWinError       lWinErr;
        mdwErrCode      = lWinErr.GetErrorCode();
        mstrErrDes      = lWinErr.GetErrorInfo();

        throw lEx;
    } // End of catch( CException& lEx )
    catch(...){
        CWinError       lWinErr;
        mdwErrCode      = lWinErr.GetErrorCode();
        mstrErrDes      = lWinErr.GetErrorInfo();

        throw CEXP( "Get an unknown exception!" );
    } // End of catch( ... )
} // End of function CDLoader(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetAddr
// Full name : CDLoader::GetAddr
// Access    : public 
// Brief     : 
// Parameter : const char* cszName
// Return    : void*
// Notes     : 
void* CModuleLoader::GetAddr(const char* cszName)
{
    try{
        // ��֤����
        _VERIFY_2_( cszName, mHandle );  

        // ��ȡ��ַ
        void* h = ::GetProcAddress( mHandle, cszName );
        _ASSERT_( h==NULL );

        return h;
    } // End of try
    catch( CException& lEx )
    {
        CWinError       lWinErr;
        mdwErrCode      = lWinErr.GetErrorCode();
        mstrErrDes      = lWinErr.GetErrorInfo();

        throw lEx;
    } // End of catch( CException& lEx )
    catch(...)
    {
        CWinError       lWinErr;
        mdwErrCode      = lWinErr.GetErrorCode();
        mstrErrDes      = lWinErr.GetErrorInfo();

        throw CEXP( "Get an unknown exception!" );
    } // End of catch( ... )
} // End of function GetAddr(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Load
// Full name : CDLoader::Load
// Access    : public 
// Brief     : 
// Parameter : const char* cszDllName
// Return    : bool
// Notes     : 
void CModuleLoader::Load(const char* cszDllName)
{
    try{
        // ��֤����
        _VERIFY_( cszDllName );

        // ������ԭ��ģ�飬����ж��
        if ( mHandle != NULL )
        {
            Free( );
            mHandle = NULL;
        }

        // ����ģ��
        HMODULE lhModule = ::LoadLibrary( cszDllName );
        _ASSERT_( lhModule == NULL );

    } // End of try
    catch( CException& lEx )
    {
        CWinError       lWinErr;
        mdwErrCode      = lWinErr.GetErrorCode();
        mstrErrDes      = lWinErr.GetErrorInfo();

        throw lEx;
    } // End of catch( CException& lEx )
    catch(...)
    {
        CWinError       lWinErr;
        mdwErrCode      = lWinErr.GetErrorCode();
        mstrErrDes      = lWinErr.GetErrorInfo();

        throw CEXP( "Get an unknown exception!" );
    } // End of catch( ... )
} // End of function Load(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : Free
// Full name : CDLoader::Free
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : bool
// Notes     : 
void CModuleLoader::Free(void)
{
    try{
        if ( mHandle != NULL )
        {
            bool lbRet = ::FreeLibrary( mHandle )==TRUE?true:false;
            _ASSERT_( lbRet == false );
        }

    } // End of try
    catch( CException& lEx )
    {
        CWinError       lWinErr;
        mdwErrCode      = lWinErr.GetErrorCode();
        mstrErrDes      = lWinErr.GetErrorInfo();

        throw lEx;
    } // End of catch( CException& lEx )
    catch(...){
        CWinError       lWinErr;
        mdwErrCode      = lWinErr.GetErrorCode();
        mstrErrDes      = lWinErr.GetErrorInfo();

        throw CEXP( "Get an unknown exception!" );
    } // End of catch( ... )
} // End of function Free(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CDLoader
// Full name : CDLoader::~CDLoader
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CModuleLoader::~CModuleLoader()
{
    Free();
} // End of function ~CDLoader(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrDes
// Full name : CDLoader::GetErrDes
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : const char*
// Notes     : 
const char* CModuleLoader::GetErrDes(void) // ��ȡ��������
{
    return mstrErrDes.c_str();
} // End of function GetErrDes(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : GetErrCode
// Full name : CDLoader::GetErrCode
// Access    : public 
// Brief     : 
// Parameter : void
// Return    : unsigned long
// Notes     : 
unsigned long CModuleLoader::GetErrCode(void) // ��ȡ�������
{
    return mdwErrCode;
} // End of function GetErrCode(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CDLoader.cpp
/////////////////////////////////////////////////////////////////////////////////////////
