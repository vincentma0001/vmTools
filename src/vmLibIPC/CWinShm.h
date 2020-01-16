/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinShm.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/12 15:11:47
// Modify time  : 2020/01/12 15:11:47
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

#ifndef __CWINSHM_H__
#define __CWINSHM_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

// Platform files included
#include <windows.h>

// Used files included
#include <vmLibBase/vmUtil.h>
#include <vmLibIPC/CWinKernal.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CWinShm : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class CWinShm : public CWinKernal
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
public:
typedef enum  emProtect
{
    vAll    = FILE_MAP_ALL_ACCESS,
    vWrite  = FILE_MAP_WRITE,
    vRead   = FILE_MAP_READ,
    vCopy   = FILE_MAP_COPY
}*PEMPROTECT;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinShm(){};
    // Destruct define
    virtual ~CWinShm()
    {
       UnMapFileView();
    };
    
private:
    // No Copy
    CWinShm(const CWinShm& obj){};
    // No Assignment
    CWinShm& operator = ( const CWinShm& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    void* mpFileView;
    size_t msztSize;

public:
    size_t size(){ return msztSize; }

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    size_t Write( const void* const cpSrc, const size_t csztDataLen, const size_t csztOffset=0 )
    {
        size_t lsztBufLeft = msztSize-csztOffset;
        void* lpPos = (tChar*)mpFileView+csztOffset;
        return v_memcpy( lpPos, lsztBufLeft, cpSrc, csztDataLen );
    }
    size_t Read( void* const pBuf, const size_t csztBufSize, const size_t csztDataLen, const size_t csztOffset=0 )
    {
        void* lpPos = (tChar*)mpFileView+csztOffset;
        return v_memcpy( pBuf, csztBufSize, lpPos, csztDataLen );        
    }
    long Initialize( const tChar* const cpName, const size_t csztSize )
    {
        msztSize = csztSize;

        long lRetForCreate = Create( cpName, emProtect::vAll, 0, msztSize ) ;
        if ( lRetForCreate != emRet::vSucceed )
            return lRetForCreate;

        long llRetForMapping = MapFileView( emProtect::vAll );
        return llRetForMapping;
    }
    
    long Create( const tChar* const  cpName,         const unsigned long cdwProtect, 
                 const unsigned long cdwMaxSizeHigh, const unsigned long cdwMaxSizeLow  )
    {
        mhHandle = ::CreateFileMapping( 
                                        INVALID_HANDLE_VALUE,       // handle to file
                                        &mstSecurityAttributes,     // security
                                        cdwProtect,                 // protection
                                        cdwMaxSizeHigh,             // high-order DWORD of size
                                        cdwMaxSizeLow,              // low-order DWORD of size 
                                        cpName                      // object name
                                       );
        return CheckHandle();
    }

    long Open(const tChar* const cpName, const unsigned long cdwDesiredAccess, const bool cbInheritHandle = false)
    {
        mhHandle = ::OpenFileMapping(
                                      cdwDesiredAccess,
                                      cbInheritHandle,
                                      cpName
                                    );
        return CheckHandle();
    }

    long MapFileView( const unsigned long cdwDesiredAccess,     const unsigned long cdwFileOffsetHigh   = 0, 
                      const unsigned long cdwFileOffsetLow = 0, const size_t        csztNumOfBytesToMap = 0 )
    {
        mpFileView = ::MapViewOfFile( 
                                       mhHandle, 
                                       cdwDesiredAccess, 
                                       cdwFileOffsetHigh, 
                                       cdwFileOffsetLow,  
                                       csztNumOfBytesToMap 
                                    );
        if ( mpFileView !=nullptr )
            return emRet::vSucceed;

        mulErrCode = GetLastError();
        return emRet::vlError;
    }

    bool UnMapFileView()
    {
        if ( mpFileView == NULL )
            return false;

        BOOL lbRet = ::UnmapViewOfFile( mpFileView );
        if ( lbRet = TRUE  )
            return true;

        mulErrCode = GetLastError();
        return false;
    }
    
}; // End of class CWinShm
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINSHM_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinShm.h
/////////////////////////////////////////////////////////////////////////////////////////