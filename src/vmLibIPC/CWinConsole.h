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
    // ǰ����ɫ
    vfDarkBule      = 0x01,       // ����ɫ
    vfDarkGreen     = 0x02,       // ����ɫ
    vfDarkCyan      = 0x03,       // ����ɫ
    vfDarkRed       = 0x04,       // ����ɫ
    vfDarkPink      = 0x05,       // ���ۺ�ɫ
    vfDarkYellow    = 0x06,       // ����ɫ
    vfDarkWhite     = 0x07,       // ����ɫ
    vfGray          = 0x08,       // ��ɫ
    vfLightBule     = 0x09,       // ����ɫ
    vfLightGreen    = 0x0A,       // ����ɫ
    vfLightCyan     = 0x0B,       // ����ɫ
    vfLightRed      = 0x0C,       // ����ɫ
    vfLightPink     = 0x0D,       // ���ۺ�ɫ
    vfLightYellow   = 0x0E,       // ���ۺ�ɫ
    vfLightWhite    = 0x0F,       // ����ɫ

    // ������ɫ
    vbDarkBule      = 0x10,       // ����ɫ
    vbDarkGreen     = 0x20,       // ����ɫ
    vbDarkCyan      = 0x30,       // ����ɫ
    vbDarkRed       = 0x40,       // ����ɫ
    vbDarkPink      = 0x50,       // ���ۺ�ɫ
    vbDarkYellow    = 0x60,       // ����ɫ
    vbDarkWhite     = 0x70,       // ����ɫ
    vbGray          = 0x80,       // ��ɫ
    vbLightBule     = 0x90,       // ����ɫ
    vbLightGreen    = 0xA0,       // ����ɫ
    vbLightCyan     = 0xB0,       // ����ɫ
    vbLightRed      = 0xC0,       // ����ɫ
    vbLightPink     = 0xD0,       // ���ۺ�ɫ
    vbLightYellow   = 0xE0,       // ���ۺ�ɫ
    vbLightWhite    = 0xF0,       // ����ɫ

    vReverseVideo = COMMON_LVB_REVERSE_VIDEO  // ��ɫ
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