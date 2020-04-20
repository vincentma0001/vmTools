/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CCmdFrame.h
// Version      : 0.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 2020/04/20 08:51:37
// Modify time  : 2020/04/20 08:51:37
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

#ifndef __CCMDFRAME_H__
#define __CCMDFRAME_H__

/////////////////////////////////////////////////////////////////////////////////////////
// Include libs  :

/////////////////////////////////////////////////////////////////////////////////////////
// Include files :
// Standard c/c++ files included

// Config files included
#include <vmCfg.h>

// Platform files included

// Used files included
#include <vmTools.h>

// Declare file included
#include "CCmd.h"
#include "CCmdExit.h"
#include "CCmdHelp.h"

/////////////////////////////////////////////////////////////////////////////////////////
// using namespace
namespace vm{

/////////////////////////////////////////////////////////////////////////////////////////
//
// class CCmdFrame : ## add class brief here ##
//
/////////////////////////////////////////////////////////////////////////////////////////
class DLL_API CCmdFrame
{
/////////////////////////////////////////////////////////////////////////////////////////
// Macro defines :
#ifndef     _V_CMDFRAME_MAX_INPUT
#    define _V_CMDFRAME_MAX_INPUT 1024
#endif   // _V_CMDFRAME_MAX_INPUT
/////////////////////////////////////////////////////////////////////////////////////////
// Type defines :

/////////////////////////////////////////////////////////////////////////////////////////
// Construct && Destruct
public:
    // Construct define
    explicit CCmdFrame(){};
    // Destruct define
    virtual ~CCmdFrame(){};
    
private:
    // No Copy
    CCmdFrame(const CCmdFrame& obj){};
    // No Assignment
    CCmdFrame& operator = ( const CCmdFrame& obj ){};
    
/////////////////////////////////////////////////////////////////////////////////////////
// Members :
private:
    CList mCmds;

    bool  mbExitFlag;

    CCmdExit     mCmdExit;
    CCmdHelp     mCmdHelp;

/////////////////////////////////////////////////////////////////////////////////////////
// Functions :
public:
    // main loop
    void Run()
    {
        // regist exit & help cmd
        RegCmd( &mCmdExit );
        RegCmd( &mCmdHelp );

        // frame main loop
        while (mbExitFlag)
        {
            // Show Cmd inform
            Output( vT("%s"), vT("CMD > ") );

            // get input string
            tchar lszInput[_V_CMDFRAME_MAX_INPUT] = {0x00};
            std::getline(lszInput);
            
            // Splite input string
            vm::CArgs<1024>     lArgs;
            lArgs.Splite( lszInput, vT(" ") );
            
            // Get cmd obj by input name
            CCmdBase* lpCmd = GetCmd( lArgs[0] );

            // process follow when don't fine cmd from cmd list.
            if (lpCmd==nullptr)
            { 	
                mCmdHelp.OnAction( this, lArgs.Argc(), lArgs.Argv() );
                continue;  
            } 

            // process cmd action
            lpCmd->OnAction( this, lArgs.Argc(), lArgs.Argv() );

        }

    }

    // regist cmd obj
    void RegCmd( CCmdBase* pCmdBase )
    {
        mCmds.Add( pCmdBase );
    }

    // get cmd by name
    CCmdBase* GetCmd( const tchar* const szCmdName )
    {
    }

    // 
    void Output( const tchar* const szFmt, ... )
    {
        va_list lvList;
        va_start( szFmt, lvList );
        Output( szFmt, lvList );
        va_end( lvList );
    }
    void Output( const tchar* const szFmt, va_list vList )
    {}

}; // End of class CCmdFrame
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} // End of namespace vm
/////////////////////////////////////////////////////////////////////////////////////////
#endif // __CCMDFRAME_H__
/////////////////////////////////////////////////////////////////////////////////////////
// usage :
/*

//*/
/////////////////////////////////////////////////////////////////////////////////////////
// End of file CCmdFrame.h
/////////////////////////////////////////////////////////////////////////////////////////