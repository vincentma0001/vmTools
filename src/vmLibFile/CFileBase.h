/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CFileBase.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2019/12/30 15:18:11
// Modify time  : 2019/12/30 15:18:11
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

#ifndef __CFILEBASE_H__
#define __CFILEBASE_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#ifndef   __VM_CFG_H__
#	error this file need #include <vmCfg.h>
#endif // __VM_CFG_H__

// Platform files included

// Used files included
#include <vmLibBase/vmUtil.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
// Macro define :

#define _V_DIR_SPLITE_ vT('\\')
#define _V_EXT_SPLITE_ vT('.')
#define _V_DRV_SPLITE_ vT(':')

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CFileBase : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CFileBase
{

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CFileBase();
    explicit CFileBase( const tChar* cpFName );
    // Destruct define
    virtual ~CFileBase();
    
public:
    // Copy construct define
    explicit CFileBase(const CFileBase& obj);
    // Assignment define
    CFileBase& operator = ( const CFileBase& obj );
    
/////////////////////////////////////////////////////////////////////////////////////////
// members
protected:
    // File's path
    tChar mszFilePath [  _V_FILE_MAX_PATH_ ];
    // File's direct
    tChar mszFileDir  [  _V_FILE_MAX_DIR_  ];
    // File's base name
    tChar mszFileBase [ _V_FILE_MAX_FNAME_ ];
    // File's name
    tChar mszFileName [ _V_FILE_MAX_FNAME_ ];
    // File's ext name
    tChar mszFileExt  [  _V_FILE_MAX_EXT_  ];

protected:
    // Error code
    unsigned long mulErrCode;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // Check has error lautch
    bool          HasError() { return (mulErrCode == 0) ? true : false; }
    // Get error code
    unsigned long toErrCode() { return mulErrCode; };

public:
    // Get file's path
    inline const tChar* cs_Path() const      { return mszFilePath;  };
    // Get file's direct
    inline const tChar* cs_Dir() const       { return mszFileDir;   };
    // Get file's base name
    inline const tChar* cs_FileBase() const  { return mszFileBase; };
    // Get file's name
    inline const tChar* cs_FileName() const  { return mszFileName; };
    // Get file's ext name
    inline const tChar* cs_Ext() const       { return mszFileExt;   };

public:
    // Check the string has direct or not
    static bool HasDir( _vIn_ const tChar* const cpPath );
    // Check the string has ext or not
    static bool HasExt(_vIn_ const tChar* const cpPath);

    // Get file's direct
    static size_t GetFileDir ( _vIn_ const tChar* const cpPath, _vIn_ const size_t    csztPathLen,
                               _vOt_ tChar* const      pDirBuf, _vIn_ const size_t csztDirBufSize );
    // Get file's name, include ext name
    static size_t GetFileName( _vIn_ const tChar* const cpPath, _vIn_ const size_t    csztPathLen,
                               _vOt_ tChar* const      pDirBuf, _vIn_ const size_t csztDirBufSize );
    // Get file's base name, don't include ext name
    static size_t GetFileBase( _vIn_ const tChar* const cpPath, _vIn_ const size_t    csztPathLen,
                               _vOt_ tChar* const      pDirBuf, _vIn_ const size_t csztDirBufSize );
    // Get file's ext name
    static size_t GetFileExt ( _vIn_ const tChar* const cpPath, _vIn_ const size_t    csztPathLen,
                               _vOt_ tChar* const      pDirBuf, _vIn_ const size_t csztDirBufSize );

    // Get current execute file's direction
    static size_t GetExecDir (_vOt_ tChar* const pOutputBuf, _vIn_ const size_t csztBufSize);
    // Get current execute file's name
    static size_t GetExecName(_vOt_ tChar* const pOutputBuf, _vIn_ const size_t csztBufSize);


/////////////////////////////////////////////////////////////////////////////////////////
// Static functions :
public:

/////////////////////////////////////////////////////////////////////////////////////////    
}; // End of class CFileBase
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CFILEBASE_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CFileBase.h
/////////////////////////////////////////////////////////////////////////////////////////