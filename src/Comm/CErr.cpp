/////////////////////////////////////////////////////////////////////////////////////////
//
// File name 	: CError.cpp
// Version 		: 0.0.0.1
// Brief 		: 
// Auther 		: v.m.
// Create time 	: 20/12/2015 12:53:12
// Modify time 	: 20/12/2015 12:53:12
// Note 		:
//
/////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright : this file is copyright by v.m.'s tools lib
//
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// include file
#include "CErr.h"

/////////////////////////////////////////////////////////////////////////////////////////
const char* gpDefaultFormat = "Err(%d) ��%s";

/////////////////////////////////////////////////////////////////////////////////////////
// Function implementation

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CError
// Full name : CError::CError
// Access    : public 
// Brief     : 
// Parameter : unsigned long dwErrorCode
// Return    : 
// Notes     : 
CErr::CErr( unsigned long dwErrCode ) 
    : mdwErrCode(dwErrCode)
{

} // End of function CError(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : CError
// Full name : CError::CError
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CErr::CErr()
{

} // End of function CError(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ~CError
// Full name : CError::~CError
// Access    : public 
// Brief     : 
// Parameter : 
// Return    : 
// Notes     : 
CErr::~CErr()
{

} // End of function ~CError(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CError::ToString
// Access    : virtual public 
// Brief     : 
// Parameter : 
// Return    : std::string&
// Notes     : 
std::string CErr::ToString(const std::string& cstrFormat)
{
    try{
        char    lcBuf[ _CERR_MAX_FMT_DES_ ]={0};
        sprintf_s( lcBuf, _CERR_MAX_FMT_DES_, cstrFormat.c_str(), mdwErrCode,mstrErrDes.c_str()  );
        return lcBuf;
    }
    catch( ... )
    {
        return "";
    }
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Name      : ToString
// Full name : CError::ToString
// Access    : virtual public 
// Brief     : 
// Parameter : void
// Return    : std::string
// Notes     : 
std::string CErr::ToString(void)
{
    return ToString( gpDefaultFormat );
} // End of function ToString(...
/////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////
// End of file CError.cpp...
/////////////////////////////////////////////////////////////////////////////////////////
