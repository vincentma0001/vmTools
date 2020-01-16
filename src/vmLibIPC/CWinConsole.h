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
public:
typedef enum emColor
{
    // 前景颜色
    vfDarkBule      = 0x01,       // 暗蓝色
    vfDarkGreen     = 0x02,       // 暗绿色
    vfDarkCyan      = 0x03,       // 暗青色
    vfDarkRed       = 0x04,       // 暗红色
    vfDarkPink      = 0x05,       // 暗粉红色
    vfDarkYellow    = 0x06,       // 暗黄色
    vfDarkWhite     = 0x07,       // 暗白色
    vfGray          = 0x08,       // 灰色
    vfLightBule     = 0x09,       // 亮蓝色
    vfLightGreen    = 0x0A,       // 亮绿色
    vfLightCyan     = 0x0B,       // 亮青色
    vfLightRed      = 0x0C,       // 亮红色
    vfLightPink     = 0x0D,       // 亮粉红色
    vfLightYellow   = 0x0E,       // 亮粉红色
    vfLightWhite    = 0x0F,       // 亮白色

    // 背景颜色
    vbDarkBule      = 0x10,       // 暗蓝色
    vbDarkGreen     = 0x20,       // 暗绿色
    vbDarkCyan      = 0x30,       // 暗青色
    vbDarkRed       = 0x40,       // 暗红色
    vbDarkPink      = 0x50,       // 暗粉红色
    vbDarkYellow    = 0x60,       // 暗黄色
    vbDarkWhite     = 0x70,       // 暗白色
    vbGray          = 0x80,       // 灰色
    vbLightBule     = 0x90,       // 亮蓝色
    vbLightGreen    = 0xA0,       // 亮绿色
    vbLightCyan     = 0xB0,       // 亮青色
    vbLightRed      = 0xC0,       // 亮红色
    vbLightPink     = 0xD0,       // 亮粉红色
    vbLightYellow   = 0xE0,       // 亮粉红色
    vbLightWhite    = 0xF0,       // 亮白色

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
    virtual ~CWinConsole()
    {
        mhHandle = NULL;
    };
    
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
    int Write(const short csAttribute, const tChar* const cpFmt, va_list& vList)
    {
        bool lbRet = SetTextAttribute(csAttribute);
        if (lbRet == false)
            return emRet::vError;

        int liRetForPrintf = vprintf_s(cpFmt, vList);

        bool lbRet2 = SetTextAttribute();
        if (lbRet2 == false)
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