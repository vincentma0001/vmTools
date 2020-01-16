/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CWinConsole.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/01/13 07:15:03
// Modify time  : 2020/01/13 07:15:03
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

#ifndef __CWINCONSOLE_H__
#define __CWINCONSOLE_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included
#include <stdio.h>

// Config files included
#include <vmCfg.h>

// Platform files included
#include <windows.h>

// Used files included
#include <vmLibBase/vmUtil.h>
#include <vmLibBase/CWinApis.h>
#include <vmLibIPC/CWinKernal.h>

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CConsole : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CWinConsole : public CWinKernal
{
/////////////////////////////////////////////////////////////////////////////////////////
// Typedefs :
typedef enum emColor
{
    // 前景颜色
    vfBule      = FOREGROUND_BLUE,      // 蓝色
    vfGreen     = FOREGROUND_GREEN,     // 绿色
    vfReg       = FOREGROUND_RED,       // 红色
    vfIntensity = FOREGROUND_INTENSITY, // 加强

    // 背景颜色
    vbBlue      = BACKGROUND_BLUE,       // 蓝色背景
    vbGreen     = BACKGROUND_GREEN,      // 绿色背景
    vbReg       = BACKGROUND_RED,        // 红色背景
    vbIntensity = BACKGROUND_INTENSITY,  // 背景色加强
    
    vReverseVideo = COMMON_LVB_REVERSE_VIDEO  // 反色
}*PEMCOLOR;

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CWinConsole()
    {
        mhHandle =::GetStdHandle(STD_OUTPUT_HANDLE);
        long llRet= CheckHandle();
    };
    // Destruct define
    virtual ~CWinConsole(){};
    
private:
    // No Copy
    CWinConsole(const CWinConsole& obj){};
    // No Assignment
    CWinConsole& operator = ( const CWinConsole& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    tChar       mszBuf[_V_FILE_MAX_PATH_];
    CONSOLE_SCREEN_BUFFER_INFO mstBufInfo;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    
    int Write( const short csAttribute, const tChar* const cpFmt, ... )
    {
        bool lbRet = SetTextAttribute( csAttribute );
        if ( lbRet == false )
            return emRet::vError;
       
        va_list vList; 
        va_start( vList, cpFmt );
        int liRetForPrintf = vprintf_s( cpFmt, vList );
        va_end( vList );

        bool lbRet2 = SetTextAttribute();
        if ( lbRet2 == false )
            return emRet::vError;

        return liRetForPrintf;
    }

    bool SetTextAttribute( const short csAttribute = 0x0f )
    {
        BOOL lbRet = ::SetConsoleTextAttribute( mhHandle,csAttribute );
        if ( lbRet == TRUE )
            return true;

        mulErrCode = ::GetLastError();
        return false;
    }
    
    bool SetWinCentrePos( const short csWidg, const short csHigh )
    {
        int liSceenWigt = vm::vWin::GetSysMetricsWide();
        int liSceenHigh = vm::vWin::GetSysMetricsHigh();
        int liCentreX = liSceenWigt/2;
        int liCentreY = liSceenHigh/2;

        short lsHalfOfX = csWidg/2;
        short lsHalfOfY = csHigh/2;
        
        return SetWinPos( liCentreX-lsHalfOfX, liCentreY-lsHalfOfY, csWidg, csHigh );
    }

    bool SetWinPos( const short csX, const short csY, const short csWidg, const short csHigh )
    {
        return SetWinSize( csY, csY+csHigh, csX, csX+csWidg );
    }

    bool SetWinSize( const short csTop, const short csBottom, const short csLeft, const short csRight, const bool cbAbsolute = true )
    {
        SMALL_RECT loRect;
        loRect.Top      = csTop;
        loRect.Bottom   = csBottom;
        loRect.Left     = csLeft;
        loRect.Right    = csRight;
        
        BOOL lbRet = ::SetConsoleWindowInfo(mhHandle, cbAbsolute, &loRect );
        if ( lbRet == TRUE )
            return true;

        mulErrCode = ::GetLastError();
        return false;
    }
    char* GetTitile(  )
    {
        vMemZero(mszBuf);
        DWORD ldwRet = ::GetConsoleTitle(mszBuf, sizeof(mszBuf));
        return mszBuf;
    }
    bool SetTitile( const tChar* const cpTitile )
    {
        BOOL lbRet = ::SetConsoleTitle( cpTitile );
        if ( lbRet == TRUE )
            return true;

        mulErrCode = GetLastError();
        return false; 
    }

}; // End of class CConsole
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CWINCONSOLE_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CWinConsole.h
/////////////////////////////////////////////////////////////////////////////////////////