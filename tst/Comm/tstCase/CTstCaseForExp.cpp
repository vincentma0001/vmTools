/////////////////////////////////////////////////////////////////////////////////////////
//
// File name    : CTstCaseForExp.cpp
// Version      : 1.0.0.0
// Brief        : 
// Author       : v.m.
// Create time  : 16/2/2016 14:20:28
// Modify time  : 16/2/2016 14:20:28
// Note         : 
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by Julong Co. LTD
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include <iostream>

#include <CommInc.h>

#include "CTstCaseForExp.h"



void func1( void )
{
    try{
        int i = 0;
        int j = 10;
        int k = j/i;
    } // End of try
    catch( CWinSeh& ex )
    {
        CWinSehExp exp( ex, __FUNCTION__, __LINE__, __FILEBASE__, NULL );
        //EXP_TRACK_ADD( exp );
        throw exp;
    }
    catch( std::exception& ex )
    {
        CCppExp exp( ex, __FUNCTION__, __LINE__, __FILEBASE__, NULL );
        //EXP_TRACK_ADD( exp );
        throw exp;
    }
    catch( CException& ex )
    {
        CException exp( ex, __FUNCTION__, __LINE__, __FILEBASE__, NULL );
        //EXP_TRACK_ADD( exp );
        throw exp;
    }
    catch(...){
        CException exp( "Get an unknown exception!" );
        //EXP_TRACK_ADD( exp );
        throw exp;
    } // End of catch( ... )
}

/////////////////////////////////////////////////////////////////////////////////////////
// Name      : OnExcute
// Full name : CTstCaseForExp::OnExcute
// Access    : virtual public 
// Brief     : 
// Parameter : const stCmd& stuCmd
// Return    : void
// Notes     : 
void CTstCaseForExp::OnExcute(const stCmd& stuCmd)
{
    std::cout << "CTstCaseForExp running..." << std::endl;
     
    func1();

} // End of function OnExcute(...
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// End of file CTstCaseForExp.cpp
/////////////////////////////////////////////////////////////////////////////////////////
